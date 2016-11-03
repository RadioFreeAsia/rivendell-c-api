/* rd_audioinfo.h
 *
 * Header for the ListCuts  Rivendell Access Library
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

#ifndef RD_AUDIOINFO_H
#define RD_AUDIOINFO_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplug

struct rd_audioinfo {
  unsigned cart_number;
  unsigned cut_number;
  int format;
  int channels;
  int samplerate;
  unsigned frames;
  unsigned length;
};

int RD_AudioInfo(struct rd_audioinfo *audioinfo[],
		  	const char hostname[],
			const char username[],
			const char passwd[],
			const unsigned cartnumber,
                        const unsigned cutnumber,
			unsigned *numrecs);

#ifdef __cplusplus
}
#endif  // _cplusplus

#endif  // RD_AUDIOINFO_H
