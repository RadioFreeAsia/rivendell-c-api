/* listgroup_test.c
 *
 * Test the listgroups library.
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

#include <listgroup.h>

int main(int argc,char *argv[])
{
  struct rd_group *grp=0;
  unsigned numrecs;
  char grp_name[BUFSIZ];
  char *grpptr;
  int i;
  char buf[BUFSIZ];

  grpptr = &grp_name[0];
  printf("Please enter the Group Name you want to list ==>");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    for (i = 0; i < strlen(buf) ; i++) {
      if (buf[i]>32) {
	strncpy(grpptr,&buf[i],1);
        grpptr++;
      }
    }
  }
  strcat(grp_name,"\0");
 

  //
  // Call the function
  //
  int result= RD_ListGroup(&grp,"localhost","user","",grp_name,&numrecs);
  if(result<0) {
    fprintf(stderr,"Error: Web function Failure!\n");
    exit(256);
  }

  if ((result< 200 || result > 299) &&
       (result != 0))
  {
    switch(result) {
      case 404:
        fprintf(stderr,"ERROR:  No Such Group Exists! \n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }
 
  if (numrecs==1) { 
      //
      // List the results
      //
      printf("        Group Name : %s\n",grp[0].grp_name);
      printf("        Description: %s\n",grp[0].grp_desc);
      printf("  Default cart type: %u\n",grp[0].grp_default_cart_type);
      printf("           Low Cart: %06u\n",grp[0].grp_lo_limit);
      printf("          High Cart: %06u\n",grp[0].grp_hi_limit);
      printf("         Shelf Life: %d\n",grp[0].grp_shelf_life);
      printf("      Default Title: %s\n",grp[0].grp_default_title);
      printf(" Enforce Cart Range: %u\n",grp[0].grp_enforce_range);
      printf("   Incl. in Traffic: %u\n",grp[0].grp_report_tfc);
      printf("     Incl. in Music: %u\n",grp[0].grp_report_mus);
      printf("    Send Now & Next: %u\n",grp[0].grp_now_next);
      printf("              Color: %s\n",grp[0].grp_color);
      printf("\n");
  }

  //
  // Free the group list when finished with it
  //
  free(grp);
  exit(0);
}
