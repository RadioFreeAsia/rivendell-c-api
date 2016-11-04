/* rd_addcart.h
 *
 * Header for the AddtCart  Rivendell Access Library
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

#ifndef RD_ADDCUT_H
#define RD_ADDCUT_H

#include <rivendell/rd_cut.h>
#include <rivendell/rd_common.h>

_MYRIVLIB_INIT_DECL


int RD_AddCut(struct rd_cut *cut[],
			const char hostname[],
			const char username[],
			const char passwd[],
			const unsigned cartnumber,
			unsigned *numrecs);

_MYRIVLIB_FINI_DECL

#endif  // RD_ADDCUT_H
