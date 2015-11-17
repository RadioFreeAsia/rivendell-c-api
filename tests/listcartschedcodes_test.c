/* listcartschedulcodes.c
 *
 * Test the listcartschedulcodes library.
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

#include <rivendell/listcartschedcodes.h>

int main(int argc,char *argv[])
{
  int i;
  struct rd_schedcodes *schedcodes=0;
  char buf[BUFSIZ];
  char *p;
  long int cart=0;
  unsigned numrecs;


  printf("Please enter the Cart Number ==> ");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    cart = strtol(buf, &p,10);

    if ( (buf[0] != '\n') &&
         ((*p != '\n') && (*p != '\0')))
    {
        fprintf(stderr," Illegal Characters detected! Exiting.\n");
	exit(0);
    }
  } 
  // Call the function
  //
  int result= RD_ListCartSchedCodes(&schedcodes,
			"localhost",
			"user",
			"",
			(unsigned)cart,	
			&numrecs);
  if(result<0) {
    fprintf(stderr,"Error: Web function Failure!\n");
    exit(256);
  }

  if ((result< 200 || result > 299) &&
       (result != 0))
  {
    switch(result) {
      case 400:
        fprintf(stderr,"ERROR:  Missing Cart Number! \n");
        break;
      case 404:
        fprintf(stderr,"ERROR:  No Such Cart Exists! \n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }
  //
  // List the results
  //
  printf("     Cart Number:  %ld\n", cart);
  for(i=0;i<numrecs;i++) {
    printf("            Code: %s\n",schedcodes[i].code);
    printf("           Description: %s\n",schedcodes[i].description);
    printf("\n");
  }

  //
  // Free the services list when finished with it
  //
  free(schedcodes);

  exit(0);
}
