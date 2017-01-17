/* import_test.c
 *
 * Test the Impourt Cart/Cut API Library
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

#include <rivendell/rd_import.h>

int main(int argc,char *argv[])
{

  int i;
  char buf[BUFSIZ];
  char *p;
  long int cartnum=0;
  long int cutnum=0;
  int create_flag=0;
  char filename[BUFSIZ];
  char group_name[BUFSIZ]="";
  char *host;
  char *user;
  char *passwd;
  struct rd_cart *carts=0;
  unsigned numrecs;

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

  printf("Please enter the Cart Number that you want to Import To  ==> ");
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
  printf("Please enter the Cut Number that you want to import To ==> ");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    cutnum = strtol(buf, &p,10);

    if ( (buf[0] != '\n') &&
         ((*p != '\n') && (*p != '\0')))
    {
        fprintf(stderr," Illegal Characters detected! Exiting.\n");
	exit(0);
    }
  } 
  printf("Please enter the File Name that you want to Import ==> ");
  if (fgets(filename,sizeof(filename),stdin) != NULL)
  {
  } 
  
  printf("Do you want to Create Cart If Doesn't Exist - (Yes or No) ==> ");
  if (fgets(buf,sizeof(buf),stdin) != NULL)
  {
    if (( buf[0] != '\n') && (buf[0] =='Y'))
    {
      create_flag = 1;
      printf("Please enter the Group Name ==> ");
      if (fgets(group_name,sizeof(group_name),stdin) != NULL)
      {
      }
    }
  }
  //
  // Call the function
  //
fprintf(stderr," Create flag = %d\n",create_flag);
fprintf(stderr," Group Name= %s\n",group_name);
  
  int result= RD_ImportCart(&carts,
                host,
		user,
		passwd,
		(unsigned)cartnum,
		(unsigned)cutnum,
		(unsigned)2,
		0,
		0,
		0,
		create_flag,
		group_name,
                filename,
		&numrecs);

  if(result<0) {
    fprintf(stderr,"Something went wrong! Result Code = %d\n",result);
    exit(256);
  }

  if ((result< 200 || result > 299) && 
       (result != 0))
  {
    switch(result) {
      case 404:
        fprintf(stderr,"ERROR:  No Such Cart/Cut Exists! \n");
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
    //printf(" Cart: %d  -  Cut: %ld  - Filename: %s was successfully imported!\n",cartnum,cutnum,filename);
    printf(" Cart: %d  -  Cut: %ld  - Filename: %s was successfully imported!\n",carts[i].cart_number,
                                (cartnum != 0) ? cutnum : 1,
                                filename);
    printf("\n");
  }

  //
  // Free the cart list when finished with it
  //
  free(carts);

  exit(0);
}
