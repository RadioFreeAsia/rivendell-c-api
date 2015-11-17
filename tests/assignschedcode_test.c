/* assignschedcodes.c
 *
 * Test the assignschedcode library.
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

#include <assignschedcode.h>

int main(int argc,char *argv[])
{
  int i;
  char buf[BUFSIZ];
  char code[BUFSIZ];
  char *p;
  long int cart=0;
  char *codeptr;


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

  codeptr = &code[0];
  printf("Please enter the Scheduler Code assign to cart# %ld ==>",cart);
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    for (i = 0; i < strlen(buf) ; i++) {
      if (buf[i]>32) {
	strncpy(codeptr,&buf[i],1);
        codeptr++;
      }
    }
  }
  strcat(code,"\0");
 
  // Call the function
  //
  int result= RD_AssignSchedCode("localhost",
			"user",
			"",
			(unsigned)cart,	
                        code);
  if(result<0) {
    fprintf(stderr,"Error: Web function Failure!\n");
    exit(256);
  }

  if ((result< 200 || result > 299) &&
       (result != 0))
  {
    switch(result) {
      case 400:
        fprintf(stderr,"ERROR:  Missing Cart/Code Number! \n");
        break;
      case 404:
        fprintf(stderr,"ERROR:  No Such Cart/Code Exists! \n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }
  //
  // List the results
  //
    printf(" Scheduler Code %s was successfully added to Cart %ld !\n",code,cart);
    printf("\n");

  exit(0);
}
