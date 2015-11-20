/* rd_editcart.h
 *
 * Header for the Edit Cart  Rivendell Access Library
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

#ifndef RD_EDITCART_H
#define RD_EDITCART_H

#include <rivendell/rd_cart.h>

struct edit_cart_values {
  char cart_grp_name[11];
  int use_cart_grp_name;
  char cart_title[256];
  int use_cart_title;
  char cart_artist[256];
  int use_cart_artist;
  char cart_album[256];
  int use_cart_album;
  int cart_year;
  int use_cart_year;
  char cart_label[65];
  int use_cart_label;
  char cart_client[65];
  int use_cart_client;
  char cart_agency[65];
  int use_cart_agency;
  char cart_publisher[65];
  int use_cart_publisher;
  char cart_composer[65];
  int use_cart_composer;
  char cart_user_defined[256];
  int use_cart_user_defined;
  int  cart_usage_code;
  int use_cart_usage_code;
  int  cart_forced_length;
  int use_cart_forced_length;
  int cart_enforce_length;
  int use_cart_enforce_length;
  int cart_asyncronous;
  int use_cart_asyncronous;
  char cart_owner[65];  
  int use_cart_owner;
  char cart_notes[1024];
  int use_cart_notes;
  char cart_metadata_datetime [26];
  int use_cart_metadata_datetime;
};                      

int RD_EditCart(struct rd_cart *cart[],
			struct edit_cart_values edit_cart_values,
			const char hostname[],
			const char username[],
			const char passwd[],
                	const unsigned cartnum,
			unsigned *numrecs);


void Build_Post_Cart_Fields(char *post, const struct edit_cart_values edit_cart_values);

#endif  // RD_EDITCART_H
