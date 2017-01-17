/* rd_listlog.c
 *
 * Implementation of the ListLog Rivendell Access Library
 *
 * (C) Copyright 2015 Todd Baker  <bakert@rfa.org>             
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public
 *   License along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>
#include <expat.h>

#include "rd_common.h"
#include "rd_listlog.h"

struct xml_data {
  unsigned logline_quan;
  char elem_name[256];
  char attribute[256];
  char attribute_value[256];
  char strbuf[1024];
  struct rd_logline *logline;
};


static void XMLCALL __ListLogElementStart(void *data, const char *el, 
					     const char **attr)
{
  struct xml_data *xml_data=(struct xml_data *)data;
  if(strcasecmp(el,"logLine")==0) {    // Allocate a new logline entry
    xml_data->logline=realloc(xml_data->logline, 
            (xml_data->logline_quan+1)*sizeof(struct rd_logline));
    (xml_data->logline_quan)++;
  }

  if (attr[0]) {
    strcpy(xml_data->attribute,attr[0]);
    strcpy(xml_data->attribute_value,attr[1]);
  }
  strncpy(xml_data->elem_name,el,256);
  memset(xml_data->strbuf,0,1024);
}


static void XMLCALL __ListLogElementData(void *data,const XML_Char *s,
					    int len)
{
  struct xml_data *xml_data=(struct xml_data *)data;

  memcpy(xml_data->strbuf+strlen(xml_data->strbuf),s,len);
}


static void XMLCALL __ListLogElementEnd(void *data, const char *el)
{
  struct xml_data *xml_data=(struct xml_data *)data;
  struct rd_logline *logline=xml_data->logline+(xml_data->logline_quan-1);

  if(strcasecmp(el,"line")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_line);
  }
  if(strcasecmp(el,"id")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_id);
  }
  if(strcasecmp(el,"type")==0) {
    printf("logline: %p  ",logline);
    if(strcasecmp(xml_data->strbuf,"Audio")==0) {
      logline->logline_type=0;
      printf("Audio");
    }
    if(strcasecmp(xml_data->strbuf,"Marker")==0) {
      logline->logline_type=1;
      printf("Marker");
    }
    if(strcasecmp(xml_data->strbuf,"Macro")==0) {
      logline->logline_type=2;
      printf("Macro");
    }
    if(strcasecmp(xml_data->strbuf,"OpenBracket")==0) {
      logline->logline_type=3;
      printf("OpenBracket");
    }
    if(strcasecmp(xml_data->strbuf,"CloseBracket")==0) {
      logline->logline_type=4;
      printf("CloseBracket");
    }
    if(strcasecmp(xml_data->strbuf,"Chain")==0) {
      logline->logline_type=5;
      printf("Chain");
    }
    if(strcasecmp(xml_data->strbuf,"Track")==0) {
      logline->logline_type=6;
      printf("Track");
    }
    if(strcasecmp(xml_data->strbuf,"MusicLink")==0) {
      logline->logline_type=7;
      printf("MusicLink");
    }
    if(strcasecmp(xml_data->strbuf,"TrafficLink")==0) {
      logline->logline_type=8;
      printf("TrafficLink");
    }
    if(strcasecmp(xml_data->strbuf,"UnknownType")==0) {
      logline->logline_type=9;
      printf("UnknownType");
    }
    printf("[%d]\n",logline->logline_type);
  }
  if(strcasecmp(el,"cartType")==0) {
    if(strcasecmp(xml_data->strbuf,"Audio")==0) {
      logline->logline_cart_type=1;
    }
    else {
      if(strcasecmp(xml_data->strbuf,"Macro")==0) {
        logline->logline_cart_type=2;
      }
      else
      {
        /*  This is ALL type */
        logline->logline_cart_type=0;
      }
    }
  }
  if(strcasecmp(el,"cartNumber")==0){
    sscanf(xml_data->strbuf,"%u",&logline->logline_cart_number);
  }
  if(strcasecmp(el,"cutNumber")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_cut_number);
  }
  if(strcasecmp(el,"groupName")==0) {
    strncpy(logline->logline_group_name,xml_data->strbuf,10);
  }
  if(strcasecmp(el,"groupColor")==0) {
    sscanf(xml_data->strbuf,"%s",(char *)&logline->logline_group_color);
  }
  if(strcasecmp(el,"title")==0) {
    strncpy(logline->logline_title,xml_data->strbuf,256);
  }
  if(strcasecmp(el,"artist")==0) {
    strncpy(logline->logline_artist,xml_data->strbuf,256);
  }
  if(strcasecmp(el,"publisher")==0) {
    strncpy(logline->logline_publisher,xml_data->strbuf,65);
  }
  if(strcasecmp(el,"composer")==0) {
    strncpy(logline->logline_composer,xml_data->strbuf,65);
  }
  if(strcasecmp(el,"album")==0) {
    strncpy(logline->logline_album,xml_data->strbuf,256);
  }
  if(strcasecmp(el,"label")==0) {
    strncpy(logline->logline_label,xml_data->strbuf,65);
  }
  if(strcasecmp(el,"year")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_year);
  }
  if(strcasecmp(el,"client")==0) {
    strncpy(logline->logline_client,xml_data->strbuf,65);
  }
  if(strcasecmp(el,"agency")==0) {
    strncpy(logline->logline_agency,xml_data->strbuf,65);
  }
  if(strcasecmp(el,"userDefined")==0) {
    strncpy(logline->logline_user_defined,xml_data->strbuf,256);
  }
  if(strcasecmp(el,"usageCode")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_usage_code);
  }
  if(strcasecmp(el,"enforceLength")==0) {
    logline->logline_enforce_length=RD_ReadBool(xml_data->strbuf);
  }
  if(strcasecmp(el,"forcedLength")==0) {
    strncpy(logline->logline_forced_length,xml_data->strbuf,9);
  }
  if(strcasecmp(el,"evergreen")==0) {
    logline->logline_evergreen=RD_ReadBool(xml_data->strbuf);
  }
  if(strcasecmp(el,"source")==0) {
    if(strcasecmp(xml_data->strbuf,"Manual")==0) {
      logline->logline_source=0;
    }
    if(strcasecmp(xml_data->strbuf,"Traffic")==0) {
      logline->logline_source=1;
    }
    if(strcasecmp(xml_data->strbuf,"Music")==0) {
      logline->logline_source=2;
    }
    if(strcasecmp(xml_data->strbuf,"Template")==0) {
      logline->logline_source=3;
    }
    if(strcasecmp(xml_data->strbuf,"Tracker")==0) {
      logline->logline_source=4;
    }
  }
  if(strcasecmp(el,"timeType")==0) {
    if(strcasecmp(xml_data->strbuf,"Relative")==0) {
      logline->logline_time_type=0;
    }
    if(strcasecmp(xml_data->strbuf,"Hard")==0) {
      logline->logline_time_type=1;
    }
    if(strcasecmp(xml_data->strbuf,"NoTime")==0) {
      logline->logline_time_type=255;
    }
  }
  if(strcasecmp(el,"startTime")==0) {
    strncpy(logline->logline_starttime,xml_data->strbuf,12);
  }
  if(strcasecmp(el,"transitionType")==0) {
    if(strcasecmp(xml_data->strbuf,"PLAY")==0) {
      logline->logline_transition_type=0;
    }
    else {
      if(strcasecmp(xml_data->strbuf,"SEGUE")==0) {
        logline->logline_transition_type=1;
      }
      else {
        if(strcasecmp(xml_data->strbuf,"STOP")==0) {
          logline->logline_transition_type=2;
        }
        else {
          logline->logline_transition_type=255;
        }
      }
    }
  }
  if(strcasecmp(el,"cutQuantity")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_cut_quantity);
  }
  if(strcasecmp(el,"lastCutPlayed")==0) {
    sscanf(xml_data->strbuf,"%d",&logline->logline_last_cut_played);
  }
  if(strcasecmp(el,"markerComment")==0) {
    strncpy(logline->logline_marker_comment,xml_data->strbuf,256);
  }
  if(strcasecmp(el,"markerLabel")==0) {
    strncpy(logline->logline_marker_label,xml_data->strbuf,65);
  }
  if(strcasecmp(el,"originUser")==0) {
    sscanf(xml_data->strbuf,"%s",(char *)&logline->logline_origin_user);
  }
  if(strcasecmp(el,"originDateTime")==0) {
    strncpy(logline->logline_origin_datetime,xml_data->strbuf,26);
  }
  if(strcasecmp(el,"startPoint")==0) {
    if(strcasecmp(xml_data->attribute,"src")==0) {
      if(strcasecmp(xml_data->attribute_value,"cart")==0) {
	sscanf(xml_data->strbuf,"%d",&logline->logline_start_point_cart);
      } 
      else {
	if(strcasecmp(xml_data->attribute_value,"log")==0) {
	  sscanf(xml_data->strbuf,"%d",&logline->logline_start_point_log);
 	}
      }
    }
  }
  if(strcasecmp(el,"endPoint")==0) {
    if(strcasecmp(xml_data->attribute,"src")==0) {
      if(strcasecmp(xml_data->attribute_value,"cart")==0) {
	sscanf(xml_data->strbuf,"%d",&logline->logline_end_point_cart);
      } 
      else {
	if(strcasecmp(xml_data->attribute_value,"log")==0) {
	  sscanf(xml_data->strbuf,"%d",&logline->logline_end_point_log);
 	}
      }
    }
  }
  if(strcasecmp(el,"segueStartPoint")==0) {
    if(strcasecmp(xml_data->attribute,"src")==0) {
      if(strcasecmp(xml_data->attribute_value,"cart")==0) {
	sscanf(xml_data->strbuf,"%d",&logline->logline_segue_start_point_cart);
      } 
      else {
	if(strcasecmp(xml_data->attribute_value,"log")==0) {
	  sscanf(xml_data->strbuf,"%d",&logline->logline_segue_start_point_log);
 	}
      }
    }
  }
  if(strcasecmp(el,"segueEndPoint")==0) {
    if(strcasecmp(xml_data->attribute,"src")==0) {
      if(strcasecmp(xml_data->attribute_value,"cart")==0) {
	sscanf(xml_data->strbuf,"%d",&logline->logline_segue_end_point_cart);
      } 
      else {
	if(strcasecmp(xml_data->attribute_value,"log")==0) {
	  sscanf(xml_data->strbuf,"%d",&logline->logline_segue_end_point_log);
 	}
      }
    }
  }
  if(strcasecmp(el,"segueGain")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_segue_gain);
  }
  if(strcasecmp(el,"fadeupPoint")==0) {
    if(strcasecmp(xml_data->attribute,"src")==0) {
      if(strcasecmp(xml_data->attribute_value,"cart")==0) {
	sscanf(xml_data->strbuf,"%d",&logline->logline_fadeup_point_cart);
      } 
      else {
	if(strcasecmp(xml_data->attribute_value,"log")==0) {
	  sscanf(xml_data->strbuf,"%d",&logline->logline_fadeup_point_log);
 	}
      }
    }
  }
  if(strcasecmp(el,"fadeupGain")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_fadeup_gain);
  }
  if(strcasecmp(el,"fadedownPoint")==0) {
    if(strcasecmp(xml_data->attribute,"src")==0) {
      if(strcasecmp(xml_data->attribute_value,"cart")==0) {
	sscanf(xml_data->strbuf,"%d",&logline->logline_fadedown_point_cart);
      } 
      else {
	if(strcasecmp(xml_data->attribute_value,"log")==0) {
	  sscanf(xml_data->strbuf,"%d",&logline->logline_fadedown_point_log);
 	}
      }
    }
  }
  if(strcasecmp(el,"duckUpGain")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_duckup_gain);
  }
  if(strcasecmp(el,"duckDownGain")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_duckdown_gain);
  }
  if(strcasecmp(el,"talkStartPoint")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_talk_start_point);
  }
  if(strcasecmp(el,"talkEndPoint")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_talk_end_point);
  }
  if(strcasecmp(el,"hookMode")==0) {
    logline->logline_hook_mode=RD_ReadBool(xml_data->strbuf);
  }
  if(strcasecmp(el,"hookStartPoint")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_hook_start_point);
  }
  if(strcasecmp(el,"hookEndPoint")==0) {
      sscanf(xml_data->strbuf,"%d",&logline->logline_hook_end_point);
  }
}


size_t __ListLogCallback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
  XML_Parser p=(XML_Parser)userdata;

  XML_Parse(p,ptr,size*nmemb,0);
  
  return size*nmemb;
}


int RD_ListLog(struct rd_logline *logline[],
		  	const char hostname[],
			const char username[],
			const char passwd[],
                  	const char logname[],
			unsigned *numrecs)
{
  char post[1500];
  char url[1500];
  CURL *curl=NULL;
  XML_Parser parser;
  struct xml_data xml_data;
  char real_logname[64];
  char *real_index = &real_logname[0];
  long response_code;
  int i;
  char errbuf[CURL_ERROR_SIZE];
  CURLcode res;

  /*  Set number of recs so if fail already set */
  *numrecs = 0;
  
  if (strlen(logname)==0)  {
    return 400;        /* Log Name Missing */
  }
  /* make the actual log name */
  if (strlen(logname)>60)  {
    return 404;        /* Log Name Incorrect */
  }
  memset(real_logname,'\0',sizeof(real_logname));
  for (i = 0; i<strlen(logname);i++)  {
    if (logname[i]>32) {
      strncpy(real_index,&logname[i],1);
      real_index++;
    }
  }

   /*
   * Setup the CURL call
   */
  memset(&xml_data,0,sizeof(xml_data));
  parser=XML_ParserCreate(NULL);
  XML_SetUserData(parser,&xml_data);
  XML_SetElementHandler(parser,__ListLogElementStart,
			__ListLogElementEnd);
  XML_SetCharacterDataHandler(parser,__ListLogElementData);
  snprintf(url,1500,"http://%s/rd-bin/rdxport.cgi",hostname);
  snprintf(post,1500,"COMMAND=22&LOGIN_NAME=%s&PASSWORD=%s&NAME=%s",
	   username,passwd,real_logname);
  if((curl=curl_easy_init())==NULL) {
    return -1;
  }
  curl_easy_setopt(curl,CURLOPT_WRITEDATA,parser);
  curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,__ListLogCallback);
  curl_easy_setopt(curl,CURLOPT_URL,url);
  curl_easy_setopt(curl,CURLOPT_POST,1);
  curl_easy_setopt(curl,CURLOPT_POSTFIELDS,post);
  curl_easy_setopt(curl,CURLOPT_NOPROGRESS,1);
  curl_easy_setopt(curl,CURLOPT_ERRORBUFFER,errbuf);
  //  curl_easy_setopt(curl,CURLOPT_VERBOSE,1);
  res = curl_easy_perform(curl);
  if(res != CURLE_OK) {
    size_t len = strlen(errbuf);
    fprintf(stderr, "\nlibcurl error: (%d)", res);
    if (len)
        fprintf(stderr, "%s%s", errbuf,
            ((errbuf[len-1] != '\n') ? "\n" : ""));
    else
        fprintf(stderr, "%s\n", curl_easy_strerror(res));
    curl_easy_cleanup(curl);
    return -1;
  }

/* The response OK - so figure out if we got what we wanted.. */

  curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE,&response_code);
  curl_easy_cleanup(curl);
  
  if (response_code > 199 && response_code < 300) {
    *logline=xml_data.logline;
    *numrecs = xml_data.logline_quan;
    return 0;
  }
  else {
    fprintf(stderr," Call Returned Error: %s\n",xml_data.strbuf);
    return (int)response_code;
  }
}
