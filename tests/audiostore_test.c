/*audiostore_test.c
 *
 * Test the audiostore WEB library.
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

#include <rivendell/audiostore.h>

int main(int argc,char *argv[])
{
  int i;
  struct rd_audiostore *audiostore=0;

  unsigned numrecs;

  //
  // Call the function
  //

  int result=RD_AudioStore(&audiostore,
		"localhost",
		"user",
		"",
		&numrecs);

  if (result<0) {
    fprintf(stderr,"Error: Web function Failure!\n");
    exit(256);
  }

  if ((result< 200 || result > 299) &&
       (result != 0))
  {
    switch(result) {
      case 400:
         fprintf(stderr," ERROR: Internal Error - Exiting!\n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }
  //
  // List the Results
  //
  for(i=0;i<numrecs;i++) {
    printf("              Free Bytes: %lu\n",audiostore[i].freebytes);
    printf("             Total Bytes: %lu\n",audiostore[i].totalbytes);
    printf("\n");

  }

  //
  // Free the audio store list when finished with it
  //
  free(audiostore);
  exit(0);
}
