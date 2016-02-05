/* rd_common.h
 *
 * Common Utility Functions for the Rivendell Access Library
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

#include <string.h>

#ifndef RD_COMMON_H
#define RD_COMMON_H
#if ((defined(_WINDLL)) || (defined(_WIN32)))
#define strcpy_s strcpy
#define strncpy_s strncpy
#define strcat_s strcat
#define snprintf _snprintf
#define strcasecmp _stricmp
#define sscanf_s sscanf
#endif

#if defined(__cplusplus)
#define _MYRIVLIB_INIT_DECL extern "C" {
#define _MYRIVLIB_FINI_DECL }
#else
#define _MYRIVLIB_INIT_DECL
#define _MYRIVLIB_FINI_DECL
#endif

extern unsigned RD_ReadBool(const char *val);

#endif  // RD_COMMON_H
