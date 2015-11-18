/* listlogs_test.c
 *
 * Test the listlog library.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rivendell/listlogs.h>

int main(int argc,char *argv[])
{
  int i;
  struct rd_log *logs=0;
  char buf[BUFSIZ];
  char *p;
  char svcname[11];
  long int trackable=0;
  unsigned numrecs;
  char *host;
  char *user;
  char *passwd;

  /*      Get the Rivendell Host, User and Password if set in env */
  if (getenv("RIVHOST")!=NULL) {
    host = getenv("RIVHOST");
  }
  else {
    host="localhost";
  }

  if (getenv("RIVUSER")!=NULL) {
    user = getenv("RIVUSER");
  }
  else {
    user="USER";
  }

  if (getenv("RIVPASS")!=NULL) {
    passwd = getenv("RIVPASS");
  }
  else {
    passwd = "";
  } 

  printf("Please enter the Service Name (default is All) ==> ");
  if(fgets(buf,sizeof(buf),stdin) != NULL)
  {
    strncpy(svcname,buf,10);
  } 
  fflush(stdin);
  printf("Please enter 1 if you want trackable logs ==>");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    trackable = strtol(buf,&p,10);
    if ( (buf[0] != '\n') &&
         ((*p != '\n') && (*p != '\0')))
    {
        fprintf(stderr," Illegal Characters detected! Exiting.\n");
        exit(0);
    }
  }

  //
  //
  //
  // Call the function
  //
  int result= RD_ListLogs(&logs,
		host,
		user,
		passwd,
		&svcname[0],
		(int)trackable,
		&numrecs); 

  if(result<0) {
    fprintf(stderr,"Error: Web function Failure!\n");
    exit(256);
  }

  //
  // List the results
  //

  for(i=0;i<numrecs;i++) {
    printf("                   Log Name: %s\n",logs[i].log_name);
    printf("                Log Service: %s\n",logs[i].log_service);
    printf("            Log Description: %s\n",logs[i].log_description);
    printf("       Log Origin User Name: %s\n",logs[i].log_origin_username);
    printf("        Log Origin DateTime: %s\n",logs[i].log_origin_datetime);
    printf("          Log Link DateTime: %s\n",logs[i].log_link_datetime);
    printf("      Log Modified DateTime: %s\n",logs[i].log_modified_datetime);
    printf("            Log AutoRefresh: %d\n",logs[i].log_autorefresh);
    printf("             Log Start Date: %s\n",logs[i].log_startdate);
    printf("               Log End Date: %s\n",logs[i].log_enddate);
    printf("       Log Scheduled Tracks: %d\n",logs[i].log_scheduled_tracks);
    printf("       Log Completed Tracks: %d\n",logs[i].log_completed_tracks);
    printf("            Log Music Links: %d\n",logs[i].log_music_links);
    printf("           Log Music Linked: %d\n",logs[i].log_music_linked);
    printf("          Log Traffic Links: %d\n",logs[i].log_traffic_links);
    printf("         Log Traffic Linked: %d\n",logs[i].log_traffic_linked);
    printf("\n");
  }

  //
  // Free the Log list when finished with it
  //
  free(logs);

  exit(0);
}
