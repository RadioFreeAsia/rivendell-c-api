/* rd_listlogs.h
 *
 * Header for the ListLogs  Rivendell Access Library
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

#ifndef RD_LISTLOGS_H
#define RD_LISTLOGS_H

struct rd_log {
  char  log_name[11];
  char  log_service[11];
  char  log_description[65];
  char  log_origin_username[256];
  char  log_origin_datetime[26];
  char  log_link_datetime[26];
  char  log_modified_datetime[26];
  int   log_autorefresh;
  char  log_startdate[26];
  char  log_enddate[26];
  int   log_scheduled_tracks;
  int   log_completed_tracks;
  int   log_music_links;
  int   log_music_linked;
  int   log_traffic_links;
  int   log_traffic_linked;
};

int RD_ListLogs(struct rd_log *logs[],
		  	const char hostname[],
			const char username[],
			const char passwd[],
			const char servicename[],
                        const int  trackable,
			unsigned *numrecs);


#endif  // RD_LISTLOGS_H
