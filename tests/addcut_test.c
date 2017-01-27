/* addcut.c
 *
 * Test the addcut library.
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

#include <rivendell/rd_addcut.h>

int main(int argc,char *argv[])
{
  struct rd_cut *cut=0;

  char buf[BUFSIZ];
  char *p;
  long int cartnum=0;
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

  printf("Please enter the Cart Number that you want to Add a CUT to==> ");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    cartnum = strtol(buf, &p,10);

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
  int result=RD_AddCut(&cut,
		host,
		user,
		passwd,
		(unsigned)cartnum,
		&numrecs);

  if(result<0) {
    fprintf(stderr,"Something went wrong!\n");
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
      case 500:
        fprintf(stderr, "ERROR:  Unable to Create Cart! \n");
        break;
      case  401:
        fprintf(stderr, "ERROR:  Unauthorized ! \n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }

  //
  // List the Results
  //
    printf("                 Cut Name: %s\n",cut->cut_name);
    printf("          Cut Cart Number: %u\n",cut->cut_cart_number);
    printf("               Cut Number: %u\n",cut->cut_cut_number);
    printf("                Evergreen: %d\n",cut->cut_evergreen);
    printf("          Cut Description: %s\n",cut->cut_description);
    printf("               Cut Outcue: %s\n",cut->cut_outcue);
    printf("                 Cut ISRC: %s\n",cut->cut_isrc);
    printf("                 Cut ISCI: %s\n",cut->cut_isci);
    printf("               Cut Length: %u\n",cut->cut_length);
    printf("     Cut Origin Date Time\n");
    printf("Cut Origin year value    : %d\n",cut->cut_origin_datetime.tm_year);
    printf("Cut Origin month value   : %d\n",cut->cut_origin_datetime.tm_mon);
    printf("Cut Origin day value     : %d\n",cut->cut_origin_datetime.tm_mday);
    printf("Cut Origin wday value    : %d\n",cut->cut_origin_datetime.tm_wday);
    printf("Cut Origin hour value    : %d\n",cut->cut_origin_datetime.tm_hour);
    printf("Cut Origin min value     : %d\n",cut->cut_origin_datetime.tm_min);
    printf("Cut Origin sec value     : %d\n",cut->cut_origin_datetime.tm_sec);
    printf("Cut Origin isdst value   : %d\n",cut->cut_origin_datetime.tm_isdst);
    printf("      Cut Start Date Time\n");
    printf("Cut Start year value     : %d\n",cut->cut_start_datetime.tm_year);
    printf("Cut Start month value    : %d\n",cut->cut_start_datetime.tm_mon);
    printf("Cut Start day value      : %d\n",cut->cut_start_datetime.tm_mday);
    printf("Cut Start wday value     : %d\n",cut->cut_start_datetime.tm_wday);
    printf("Cut Start hour value     : %d\n",cut->cut_start_datetime.tm_hour);
    printf("Cut Start min value      : %d\n",cut->cut_start_datetime.tm_min);
    printf("Cut Start sec value      : %d\n",cut->cut_start_datetime.tm_sec);
    printf("Cut Start isdst value    : %d\n",cut->cut_start_datetime.tm_isdst);
    printf("        Cut End Date Time\n");
    printf("Cut End year value       : %d\n",cut->cut_end_datetime.tm_year);
    printf("Cut End month value      : %d\n",cut->cut_end_datetime.tm_mon);
    printf("Cut End day value        : %d\n",cut->cut_end_datetime.tm_mday);
    printf("Cut End wday value       : %d\n",cut->cut_end_datetime.tm_wday);
    printf("Cut End hour value       : %d\n",cut->cut_end_datetime.tm_hour);
    printf("Cut End min value        : %d\n",cut->cut_end_datetime.tm_min);
    printf("Cut End sec value        : %d\n",cut->cut_end_datetime.tm_sec);
    printf("Cut End isdst value      : %d\n",cut->cut_end_datetime.tm_isdst);
    printf("                  Cut Sun: %d\n",cut->cut_sun);
    printf("                  Cut Mon: %d\n",cut->cut_mon);
    printf("                  Cut Tue: %d\n",cut->cut_tue);
    printf("                  Cut Wed: %d\n",cut->cut_wed);
    printf("                  Cut Thu: %d\n",cut->cut_thu);
    printf("                  Cut Fri: %d\n",cut->cut_fri);
    printf("                  Cut Sat: %d\n",cut->cut_sat);
    printf("        Cut Start Daypart: %s\n",cut->cut_start_daypart);
    printf("          Cut End Daypart: %s\n",cut->cut_end_daypart);
    printf("          Cut Origin Name: %s\n",cut->cut_origin_name);
    printf("               Cut Weight: %u\n",cut->cut_weight);
    printf("  Cut Last Play Date Time\n");
    printf("Cut LastPlay year value  : %d\n",cut->cut_last_play_datetime.tm_year);
    printf("Cut LastPlay month value : %d\n",cut->cut_last_play_datetime.tm_mon);
    printf("Cut LastPlay day value   : %d\n",cut->cut_last_play_datetime.tm_mday);
    printf("Cut LastPlay wday value  : %d\n",cut->cut_last_play_datetime.tm_wday);
    printf("Cut LastPlay hour value  : %d\n",cut->cut_last_play_datetime.tm_hour);
    printf("Cut LastPlay min value   : %d\n",cut->cut_last_play_datetime.tm_min);
    printf("Cut LastPlay sec value   : %d\n",cut->cut_last_play_datetime.tm_sec);
    printf("Cut LastPlay isdst value : %d\n",cut->cut_last_play_datetime.tm_isdst);
    printf("         Cut Play Counter: %u\n",cut->cut_play_counter);
    printf("        Cut Local Counter: %u\n",cut->cut_local_counter);
    printf("             Cut Validity: %u\n",cut->cut_validity);
    printf("        Cut Coding Format: %u\n",cut->cut_coding_format);
    printf("          Cut Sample Rate: %u\n",cut->cut_sample_rate);
    printf("             Cut Bit Rate: %u\n",cut->cut_bit_rate);
    printf("             Cut Channels: %u\n",cut->cut_channels);
    printf("            Cut Play Gain: %d\n",cut->cut_play_gain);
    printf("          Cut Start Point: %d\n",cut->cut_start_point);
    printf("            Cut End Point: %d\n",cut->cut_end_point);
    printf("        Cut Fade Up Point: %d\n",cut->cut_fadeup_point);
    printf("      Cut Fade Down Point: %d\n",cut->cut_fadedown_point);
    printf("    Cut Segue Start Point: %d\n",cut->cut_segue_start_point);
    printf("      Cut Segue End Point: %d\n",cut->cut_segue_end_point);
    printf("           Cut Segue Gain: %d\n",cut->cut_segue_gain);
    printf("     Cut Hook Start Point: %d\n",cut->cut_hook_start_point);
    printf("       Cut Hook End Point: %d\n",cut->cut_hook_end_point);
    printf("     Cut Talk Start Point: %d\n",cut->cut_talk_start_point);
    printf("       Cut Talk End Point: %d\n",cut->cut_talk_end_point);
    printf("\n");

  free(cut);
  exit(0);
}
