/* addcart_test.c
 *
 * Test the addcart library.
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

#include <rivendell/addcart.h>

int main(int argc,char *argv[])
{
  struct rd_cart *cart=0;

  char buf[BUFSIZ];
  char *p;
  long int cartnum=0;
  unsigned numrecs;

  printf("Please enter the Cart Number that you want to Add ==> ");
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
  int result=RD_AddCart(&cart,
		"localhost",
		"user",
		"",
		"TEST",
		"audio",
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
         fprintf(stderr," ERROR: Invalid Parameter for GROUP or TYPE");
        break;
      case 403:
        fprintf(stderr,"ERROR:  That Cart Already Exists!\n");
        break;
      case 404:
        fprintf(stderr,"ERROR:  No Such Group Exists! \n");
        break;
      case 500:
        fprintf(stderr, "ERROR:  Unable to Create Cart! \n");
        break;
      case  401:
        fprintf(stderr, "ERROR:  Unauthorized Or Cart out of Range! \n");
        break;
      default:
        fprintf(stderr, "Unknown Error occurred ==> %d",result);
    }
    exit(256);
  }

  //
  // List the Results
  //
    printf("              Cart Number: %d\n",cart->cart_number);
    printf("                Cart Type: %d\n",cart->cart_type);
    printf("               Group Name: %s\n",cart->cart_grp_name);
    printf("               Cart Title: %s\n",cart->cart_title);
    printf("              Cart Artist: %s\n",cart->cart_artist);
    printf("               Cart Album: %s\n",cart->cart_album);
    printf("                Cart Year: %d\n",cart->cart_year);
    printf("               Cart Label: %s\n",cart->cart_label);
    printf("              Cart Client: %s\n",cart->cart_client);
    printf("              Cart Agency: %s\n",cart->cart_agency);
    printf("           Cart Publisher: %s\n",cart->cart_publisher);
    printf("            Cart Composer: %s\n",cart->cart_composer);
    printf("        Cart User Defined: %s\n",cart->cart_user_defined);
    printf("          Cart Usage Code: %d\n",cart->cart_usage_code);
    printf("       Cart Forced Length: %d\n",cart->cart_forced_length);
    printf("      Cart Average Length: %d\n",cart->cart_average_length);
    printf("    Cart Length Deviation: %d\n",cart->cart_length_deviation);
    printf("Cart Average Segue Length: %d\n",cart->cart_average_segue_length);
    printf(" Cart Average Hook Length: %d\n",cart->cart_average_hook_length);
    printf("        Cart Cut Quantity: %u\n",cart->cart_cut_quantity);
    printf("     Cart Last Cut Played: %03u\n",cart->cart_last_cut_played);
    printf("            Cart Validity: %u\n",cart->cart_validity);
    printf("      Cart Enforce Length: %d\n",cart->cart_enforce_length);
    printf("         Cart Asyncronous: %d\n",cart->cart_asyncronous);
    printf("               Cart Owner: %s\n",cart->cart_owner);
    printf("   Cart Metadata Datetime: %s\n",cart->cart_metadata_datetime);
    printf("\n");

  free(cart);
  exit(0);
}
