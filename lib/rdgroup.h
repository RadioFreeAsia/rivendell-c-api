/* rdgroup.h
 *
 * Header for the RDGROUP Structure Rivendell Access Library
 *
 * (C) Copyright 2015 Fred Gleason <fredg@paravelsystems.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
                                                                    */
#ifndef RDGROUP_H
#define RDGROUP_H
struct rd_group {
  char grp_name[11];
  char grp_desc[255];
  unsigned grp_default_cart_type;
  unsigned grp_lo_limit;
  unsigned grp_hi_limit;
  int grp_shelf_life;
  char grp_default_title[255];
  int grp_enforce_range;
  int grp_report_tfc;
  int grp_report_mus;
  int grp_now_next;
  char grp_color[8];
  char grp_reserved[457];
};

#endif   //END  RDGROUP_H
