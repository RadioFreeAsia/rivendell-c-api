/* listcarts_test.c
 *
 * Test the listcarts library.
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

#include <rivendell/listcarts.h>

int main(int argc,char *argv[])
{
  int i;
  struct rd_cart *carts=0;
  unsigned numrecs;

  //
  // Call the function
  //
  int result= RD_ListCarts(&carts,"localhost","user","","","7777","Audio",&numrecs);
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
  //
  // List the results
  //
  for(i=0;i<numrecs;i++) {
    printf("              Cart Number: %d\n",carts[i].cart_number);
    printf("                Cart Type: %d\n",carts[i].cart_type);
    printf("               Group Name: %s\n",carts[i].cart_grp_name);
    printf("               Cart Title: %s\n",carts[i].cart_title);
    printf("              Cart Artist: %s\n",carts[i].cart_artist);
    printf("               Cart Album: %s\n",carts[i].cart_album);
    printf("                Cart Year: %d\n",carts[i].cart_year);
    printf("               Cart Label: %s\n",carts[i].cart_label);
    printf("              Cart Client: %s\n",carts[i].cart_client);
    printf("              Cart Agency: %s\n",carts[i].cart_agency);
    printf("           Cart Publisher: %s\n",carts[i].cart_publisher);
    printf("            Cart Composer: %s\n",carts[i].cart_composer);
    printf("        Cart User Defined: %s\n",carts[i].cart_user_defined);
    printf("          Cart Usage Code: %d\n",carts[i].cart_usage_code);
    printf("       Cart Forced Length: %d\n",carts[i].cart_forced_length);
    printf("      Cart Average Length: %d\n",carts[i].cart_average_length);
    printf("    Cart Length Deviation: %d\n",carts[i].cart_length_deviation);
    printf("Cart Average Segue Length: %d\n",carts[i].cart_average_segue_length);
    printf(" Cart Average Hook Length: %d\n",carts[i].cart_average_hook_length);
    printf("        Cart Cut Quantity: %u\n",carts[i].cart_cut_quantity);
    printf("     Cart Last Cut Played: %03u\n",carts[i].cart_last_cut_played);
    printf("            Cart Validity: %u\n",carts[i].cart_validity);
    printf("      Cart Enforce Length: %d\n",carts[i].cart_enforce_length);
    printf("         Cart Asyncronous: %d\n",carts[i].cart_asyncronous);
    printf("               Cart Owner: %s\n",carts[i].cart_owner);
    printf("   Cart Metadata Datetime: %s\n",carts[i].cart_metadata_datetime);
    printf("\n");
  }

  //
  // Free the cart list when finished with it
  //
  free(carts);

  exit(0);
}
