/* listcuts_test.c
 *
 * Test the listcuts library.
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

#include <rivendell/rd_listcuts.h>

int main(int argc,char *argv[])
{
  int i;
  struct rd_cut *cuts=0;

  char buf[BUFSIZ];
  char *p;
  long int cart=0;
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

  printf("Please enter the Cart Number that you want to List CUTS ==> ");
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
  //
  // Call the function
  //
  int result=RD_ListCuts(&cuts,
		host,
		user,
		passwd,
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
         fprintf(stderr," ERROR: Missing Cart Number");
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
  // List the Results
  //
  for(i=0;i<numrecs;i++) {
    printf("              Cut Name %s:\n",cuts[i].cut_name);
    printf("       Cut Cart Number %u:\n",cuts[i].cut_cart_number);
    printf("            Cut Number %u:\n",cuts[i].cut_cut_number);
    printf("                Evergreen: %d\n",cuts[i].cut_evergreen);
    printf("          Cut Description: %s\n",cuts[i].cut_description);
    printf("            Cut Outcue %s:\n",cuts[i].cut_outcue);
    printf("                 Cut ISRC: %s\n",cuts[i].cut_isrc);
    printf("                 Cut ISCI: %s\n",cuts[i].cut_isci);
    printf("               Cut Length: %u\n",cuts[i].cut_length);
    printf("     Cut Origin Date Time: %s\n",cuts[i].cut_origin_datetime);
    printf("      Cut Start Date Time: %s\n",cuts[i].cut_start_datetime);
    printf("        Cut End Date Time: %s\n",cuts[i].cut_end_datetime);
    printf("                  Cut Sun: %d\n",cuts[i].cut_sun);
    printf("                  Cut Mon: %d\n",cuts[i].cut_mon);
    printf("                  Cut Tue: %d\n",cuts[i].cut_tue);
    printf("                  Cut Wed: %d\n",cuts[i].cut_wed);
    printf("                  Cut Thu: %d\n",cuts[i].cut_thu);
    printf("                  Cut Fri: %d\n",cuts[i].cut_fri);
    printf("                  Cut Sat: %d\n",cuts[i].cut_sat);
    printf("        Cut Start Daypart: %s\n",cuts[i].cut_start_daypart);
    printf("          Cut End Daypart: %s\n",cuts[i].cut_end_daypart);
    printf("          Cut Origin Name: %s\n",cuts[i].cut_origin_name);
    printf("               Cut Weight: %u\n",cuts[i].cut_weight);
    printf("  Cut Last Play Date Time: %s\n",cuts[i].cut_last_play_datetime);
    printf("         Cut Play Counter: %u\n",cuts[i].cut_play_counter);
    printf("        Cut Local Counter: %u\n",cuts[i].cut_local_counter);
    printf("             Cut Validity: %u\n",cuts[i].cut_validity);
    printf("        Cut Coding Format: %u\n",cuts[i].cut_coding_format);
    printf("          Cut Sample Rate: %u\n",cuts[i].cut_sample_rate);
    printf("             Cut Bit Rate: %u\n",cuts[i].cut_bit_rate);
    printf("             Cut Channels: %u\n",cuts[i].cut_channels);
    printf("            Cut Play Gain: %d\n",cuts[i].cut_play_gain);
    printf("          Cut Start Point: %d\n",cuts[i].cut_start_point);
    printf("            Cut End Point: %d\n",cuts[i].cut_end_point);
    printf("        Cut Fade Up Point: %d\n",cuts[i].cut_fadeup_point);
    printf("      Cut Fade Down Point: %d\n",cuts[i].cut_fadedown_point);
    printf("    Cut Segue Start Point: %d\n",cuts[i].cut_segue_start_point);
    printf("      Cut Segue End Point: %d\n",cuts[i].cut_segue_end_point);
    printf("           Cut Segue Gain: %d\n",cuts[i].cut_segue_gain);
    printf("     Cut Hook Start Point: %d\n",cuts[i].cut_hook_start_point);
    printf("       Cut Hook End Point: %d\n",cuts[i].cut_hook_end_point);
    printf("     Cut Talk Start Point: %d\n",cuts[i].cut_talk_start_point);
    printf("       Cut Talk End Point: %d\n",cuts[i].cut_talk_end_point);
    printf("\n");

  }

  //
  // Free the cut list when finished with it
  //
  free(cuts);

  exit(0);
}
