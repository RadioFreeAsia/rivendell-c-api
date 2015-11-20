/* rd_trimaudio.c
 *
 * Implementation of the TrimAudio Rivendell Access Library
 *
 * (C) Copyright 2015 Fred Gleason <fredg@paravelsystems.com>
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

#include "rd_trimaudio.h"

struct xml_data {
  char elem_name[256];
  char strbuf[1024];
  struct rd_trimaudio *trimaudio;
};


static void XMLCALL __TrimAudioElementStart(void *data, const char *el, 
					     const char **attr)
{
  unsigned i;
  struct xml_data *xml_data=(struct xml_data *)data;
  if(strcasecmp(el,"trimPoint")==0) {    // Allocate a new trimaudio entry
    xml_data->trimaudio=realloc(xml_data->trimaudio,
			   sizeof(struct rd_trimaudio));
  }
  strncpy(xml_data->elem_name,el,256);
  memset(xml_data->strbuf,0,1024);
}


static void XMLCALL __TrimAudioElementData(void *data,const XML_Char *s,
					    int len)
{
  struct xml_data *xml_data=(struct xml_data *)data;

  memcpy(xml_data->strbuf+strlen(xml_data->strbuf),s,len);
}


static void XMLCALL __TrimAudioElementEnd(void *data, const char *el)
{
  struct xml_data *xml_data=(struct xml_data *)data;
  struct rd_trimaudio *trimaudio=xml_data->trimaudio;

  if(strcasecmp(el,"cartNumber")==0) {
    sscanf(xml_data->strbuf,"%u",&trimaudio->cart_number);
  }
  if(strcasecmp(el,"cutNumber")==0){
    sscanf(xml_data->strbuf,"%u",&trimaudio->cut_number);
  }
  if(strcasecmp(el,"trimLevel")==0) {
    sscanf(xml_data->strbuf,"%d",&trimaudio->trimlevel);
  }
  if(strcasecmp(el,"startTrimPoint")==0){
    sscanf(xml_data->strbuf,"%d",&trimaudio->starttrimpoint);
  }
  if(strcasecmp(el,"endTrimPoint")==0){
    sscanf(xml_data->strbuf,"%d",&trimaudio->endtrimpoint);
  }
}


size_t __TrimAudioCallback(void *ptr, size_t size, size_t nmemb, void *userdata)
{
  XML_Parser p=(XML_Parser)userdata;

  XML_Parse(p,ptr,size*nmemb,0);
  
  return size*nmemb;
}


int RD_TrimAudio(struct rd_trimaudio *trimaudio[],
		  	const char hostname[],
                  	const char username[],
                  	const char passwd[],
                  	const unsigned cartnumber,
			const unsigned cutnumber,
			const int trimlevel,
                  	unsigned *numrecs)
{
  char post[1500];
  char url[1500];
  CURL *curl=NULL;
  XML_Parser parser;
  struct xml_data xml_data;
  long response_code;

   /* Set number of recs so if fail already set */
  *numrecs = 0;

  /*
   * Setup the CURL call
   */
  memset(&xml_data,0,sizeof(xml_data));
  parser=XML_ParserCreate(NULL);
  XML_SetUserData(parser,&xml_data);
  XML_SetElementHandler(parser,__TrimAudioElementStart,
			__TrimAudioElementEnd);
  XML_SetCharacterDataHandler(parser,__TrimAudioElementData);
  snprintf(url,1500,"http://%s/rd-bin/rdxport.cgi",hostname);
  snprintf(post,1500,"COMMAND=17&LOGIN_NAME=%s&PASSWORD=%s&CART_NUMBER=%u&CUT_NUMBER=%u&TRIM_LEVEL=%d",
	   username,passwd,cartnumber,cutnumber,trimlevel);
  if((curl=curl_easy_init())==NULL) {
    return -1;
  }
  curl_easy_setopt(curl,CURLOPT_WRITEDATA,parser);
  curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,__TrimAudioCallback);
  curl_easy_setopt(curl,CURLOPT_URL,url);
  curl_easy_setopt(curl,CURLOPT_POST,1);
  curl_easy_setopt(curl,CURLOPT_POSTFIELDS,post);
  curl_easy_setopt(curl,CURLOPT_NOPROGRESS,1);
  //  curl_easy_setopt(curl,CURLOPT_VERBOSE,1);
  if(curl_easy_perform(curl)!=CURLE_OK) {
    return -1;
  }

/* The response OK - so figure out if we got what we wanted.. */

  curl_easy_getinfo(curl,CURLINFO_RESPONSE_CODE,&response_code);
  curl_easy_cleanup(curl);
  
  if (response_code > 199 && response_code < 300) { 
    *trimaudio=xml_data.trimaudio;
    *numrecs = 1;
    return 0;
  }
  else {
    fprintf(stderr," Call Returned Error: %s\n",xml_data.strbuf);
    return (int)response_code;
  }
}
