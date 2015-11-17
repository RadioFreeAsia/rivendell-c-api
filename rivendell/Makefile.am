## automake.am
##
## (C) Copyright 2015 Fred Gleason <fredg@paravelsystems.com>
##
##   This program is free software; you can redistribute it and/or modify
##   it under the terms of the GNU General Public License version 2 as
##   published by the Free Software Foundation.
##
##   This program is distributed in the hope that it will be useful,
##   but WITHOUT ANY WARRANTY; without even the implied warranty of
##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##   GNU General Public License for more details.
##
##   You should have received a copy of the GNU General Public
##   License along with this program; if not, write to the Free Software
##   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
##
##
## Use automake to process this into a Makefile.in

AM_CFLAGS = -I$(top_srcdir)
lib_LTLIBRARIES = librivwebcapi.la 
dist_librivwebcapi_la_SOURCES = listgroups.c listgroups.h \
				listgroup.c listgroup.h \
				listcarts.c listcarts.h \
				listcart.c listcart.h \
				listcuts.c listcuts.h \
				listcut.c listcut.h \
				listservices.c listservices.h \
				listschedcodes.c listschedcodes.h\
				listcartschedcodes.c listcartschedcodes.h\
				assignschedcode.c assignschedcode.h\
				unassignschedcode.c unassignschedcode.h\
				addcart.c addcart.h \
				addcut.c addcut.h \
				removecart.c removecart.h \
				removecut.c removecut.h \
				deleteaudio.c deleteaudio.h \
				copyaudio.c copyaudio.h \
				audioinfo.c audioinfo.h \
				trimaudio.c trimaudio.h \
				audiostore.c audiostore.h \
				listlogs.c listlogs.h \
				listlog.c listlog.h \
				editcart.c editcart.h \
				editcut.c editcut.h \
				import.c import.h \
				export.c export.h \
				exportpeaks.c exportpeaks.h

includedir = $(prefix)/include/rivendell
include_HEADERS = addcart.h\
                  addcut.h\
                  assignschedcode.h\
                  audioinfo.h\
                  audiostore.h\
                  copyaudio.h\
                  deleteaudio.h\
                  editcart.h\
                  editcut.h\
                  export.h\
                  exportpeaks.h\
                  import.h\
                  listcart.h\
                  listcartschedcodes.h\
                  listcarts.h\
                  listcut.h\
                  listcuts.h\
                  listgroup.h\
                  listgroups.h\
                  listlog.h\
                  listlogs.h\
                  listschedcodes.h\
                  listservices.h\
                  rdcart.h\
                  rdcut.h\
                  rdgroup.h\
                  rdschedcodes.h\
                  removecart.h\
                  removecut.h\
                  trimaudio.h\
                  unassignschedcode.h

CLEANFILES = *~\
             moc_*\
             *.lib\
             *.obj\
             *.qm

DISTCLEANFILES = rdpaths.h

MAINTAINERCLEANFILES = *~\
                       *.tar.gz\
                       aclocal.m4\
                       configure\
                       Makefile.in\
                       moc_*
