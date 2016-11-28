/* listservices_test.c
 *
 * Test the listservices library.
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <rivendell/rd_listservices.h>

int main(int argc,char *argv[])
{
  int i;
  long int trackable=0;
  char buf[BUFSIZ];
  char *p;
  struct rd_service *services=0;
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
  // Call the function
  //
  int result= RD_ListServices(&services,
			host,
			user,
			passwd,
			(int)trackable,
			&numrecs);
  if(result<0) {
    fprintf(stderr,"Error: Web function Failure!\n");
    exit(256);
  }

  if ((result< 200 || result > 299) &&
       (result != 0))
  {
    fprintf(stderr, "Unknown Error occurred ==> %d",result);
    exit(256);
  }
  //
  // List the results
  //
  for(i=0;i<numrecs;i++) {
    printf("            Service Name: %s\n",services[i].service_name);
    printf("     Service Description: %s\n",services[i].service_description);
    printf("\n");
  }

  //
  // Free the services list when finished with it
  //
  free(services);

  exit(0);
}
