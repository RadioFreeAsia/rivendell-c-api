/* rd_export.h
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

#ifndef RD_EXPORT_H
#define RD_EXPORT_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplug

int RD_ExportCart( const char hostname[],
		 	const char         username[],
                        const char           passwd[],
			const unsigned        cartnum,
                        const unsigned         cutnum,
                        const int              format,
			const int	  channels,
                        const int         sample_rate,
                        const int            bit_rate,
                        const int             quality,
                        const int         start_point,
                        const int           end_point,
                        const int normalization_level,
                        const int     enable_metadata,
                        const char         filename[]);


#ifdef __cplusplus
}
#endif  // _cplusplus

#endif  // RD_EXPORT_H
