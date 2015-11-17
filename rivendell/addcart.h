/* addcart.h
 *
 * Header for the AddCart  Rivendell Access Library
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

#ifndef ADD_CART_H
#define ADD_CART_H

#include <rivendell/rdcart.h>

int RD_AddCart(struct rd_cart *cart[],
			const char hostname[],
			const char username[],
			const char passwd[],
			const char group[],
			const char type[],
			const unsigned cartnumber,
			unsigned *numrecs);

#endif  // ADD_CART_H
