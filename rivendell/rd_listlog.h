/* rd_listlog.h
 *
 * Header for the ListCarts  Rivendell Access Library
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

#ifndef RD_LISTLOG_H
#define RD_LISTLOG_H

struct rd_logline {
  int  logline_line;
  int  logline_id;
  int  logline_type;
  int  logline_cart_type;
  unsigned logline_cart_number;
  int logline_cut_number;
  char logline_group_name[11];
  char logline_group_color[10];
  char logline_title[256];
  char logline_artist[256];
  char logline_album[256];
  int  logline_year;
  char logline_label[65];
  char logline_client[65];
  char logline_agency[65];
  char logline_publisher[65];
  char logline_composer[65];
  char logline_user_defined[256];
  int  logline_usage_code;
  int  logline_enforce_length;
  char logline_forced_length[10];
  int  logline_evergreen;
  int  logline_source;
  int  logline_time_type;
  char logline_starttime[13];
  int  logline_transition_type;
  int  logline_cut_quantity;
  int  logline_last_cut_played;
  char logline_marker_comment[256];
  char logline_marker_label[65];
  char logline_origin_user[256];
  char logline_origin_datetime[26];
  int  logline_start_point_cart;
  int  logline_start_point_log;
  int  logline_end_point_cart;
  int  logline_end_point_log;
  int  logline_segue_start_point_cart;
  int  logline_segue_start_point_log;
  int  logline_segue_end_point_cart;
  int  logline_segue_end_point_log;
  int  logline_segue_gain;
  int  logline_fadeup_point_cart;
  int  logline_fadeup_point_log;
  int  logline_fadeup_gain;
  int  logline_fadedown_point_cart;
  int  logline_fadedown_point_log;
  int  logline_duckup_gain;
  int  logline_duckdown_gain;
  int  logline_talk_start_point;
  int  logline_talk_end_point;
  int  logline_hook_mode;
  int  logline_hook_start_point;
  int  logline_hook_end_point;
};

int RD_ListLog(struct rd_logline *logline[],
		  	const char hostname[],
			const char username[],
			const char passwd[],
			const char logname[],
			unsigned *numrecs);


#endif  // RD_LISTLOG_H
