/* deletelog_test.c
 *
 * Test the deletelog library.
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

#include <rivendell/rd_deletelog.h>

#include "common.h"

int main(int argc,char *argv[])
{
  char logname[BUFSIZ]={0};
  char *host;
  char *user;
  char *passwd;
  char ticket[41]="";
  char user_agent[25]="Riv-C-API test Suite 1.0";

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

  PromptForString("Please enter the Name of the Log that you want to Delete ==> ",
		  logname,BUFSIZ);

  //
  // Call the function
  //
  int result=RD_DeleteLog(host,
			  user,
			  passwd,
			  ticket,
			  logname,
                          user_agent);

  if(result<0) {
    fprintf(stderr,"Something went wrong!\n");
    exit(256);
  }

  if ((result< 200 || result > 299) && 
       (result != 0))
  {
    switch(result) {
      case 400:
         fprintf(stderr," ERROR: Invalid Parameter for LOG_NAME! \n");
        break;
      case 500:
        fprintf(stderr, "ERROR:  Unable to Delete Log! \n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }

  //
  // List the Results
  //
  printf(" Success\n");

  exit(0);
}
