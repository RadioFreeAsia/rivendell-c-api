/*audioinfo_test.c
 *
 * Test the audioinfo WEB library.
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

#include <trimaudio.h>

int main(int argc,char *argv[])
{
  int i;
  struct rd_trimaudio *trimaudio=0;

  char buf[BUFSIZ];
  char *p;
  long int cart=0;
  long int cut=0;
  long int trimlevel=0;
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

  printf("Please enter the Cut Number for the Cart used above ==> ");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    cut = strtol(buf, &p,10);

    if ( (buf[0] != '\n') &&
         ((*p != '\n') && (*p != '\0')))
    {
        fprintf(stderr," Illegal Characters detected! Exiting.\n");
	exit(0);
    }
  } 

  printf("Please enter the Trim Level: ");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    trimlevel = strtol(buf, &p,10);

    if ( (buf[0] != '\n') &&
         ((*p != '\n') && (*p != '\0')))
    {
        fprintf(stderr," Illegal Characters detected! Exiting.\n");
	exit(0);
    }
  } 
  //
  //
  // Call the function
  //

  int result=RD_TrimAudio(&trimaudio,
		"localhost",
		"user",
		"",
		(unsigned)cart,
		(unsigned)cut,
		(int)trimlevel,
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
         fprintf(stderr," ERROR: Missing Cart/Cut Number or \n   Unknown Trim Level or \n   No Peak Data Available\n");
        break;
      case 404:
        fprintf(stderr,"ERROR:  No Such Cart/Audio Exists! \n");
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
    printf("              Cart Number: %u\n",trimaudio[i].cart_number);
    printf("               Cut Number: %d\n",trimaudio[i].cut_number);
    printf("               Trim Level: %d\n",trimaudio[i].trimlevel);
    printf("         Start Trim Point: %d\n",trimaudio[i].starttrimpoint);
    printf("           End Trim Point: %d\n",trimaudio[i].endtrimpoint);
    printf("\n");

  }

  //
  // Free the trimaudio list when finished with it
  //
  free(trimaudio);
  exit(0);
}
