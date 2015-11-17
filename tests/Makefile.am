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

AM_CPPFLAGS = -Wall -I$(top_srcdir)/lib
LIBS = -L$(top_srcdir)/lib
noinst_PROGRAMS = listgroups_test \
		listgroup_test \
		listcarts_test \
		listcart_test \
		listcuts_test \
		listcut_test \
		listschedcodes_test \
		listcartschedcodes_test \
		assignschedcode_test \
		unassignschedcode_test \
		addcart_test \
		addcut_test \
		removecart_test \
		removecut_test \
		audioinfo_test \
		audiostore_test \
		trimaudio_test \
                listlogs_test \
                listservices_test \
                listlog_test \
		editcart_test \
		editcut_test \
		importcart_test \
		exportcart_test \
		exportpeaks_test \
		deleteaudio_test \
		copyaudio_test

dist_listgroups_test_SOURCES = listgroups_test.c 
dist_listgroup_test_SOURCES = listgroup_test.c 
dist_listcarts_test_SOURCES = listcarts_test.c 
dist_listcart_test_SOURCES = listcart_test.c 
dist_listcuts_test_SOURCES = listcuts_test.c 
dist_listcut_test_SOURCES = listcut_test.c 
dist_listschedcodes_test_SOURCES = listschedcodes_test.c 
dist_assignschedcode_test_SOURCES = assignschedcode_test.c 
dist_unassignschedcode_test_SOURCES = unassignschedcode_test.c 
dist_addcart_test_SOURCES = addcart_test.c 
dist_addcut_test_SOURCES = addcut_test.c 
dist_removecart_test_SOURCES = removecart_test.c 
dist_removecut_test_SOURCES = removecut_test.c 
dist_audioinfo_test_SOURCES = audioinfo_test.c 
dist_audiostore_test_SOURCES = audiostore_test.c 
dist_trimaudio_test_SOURCES = trimaudio_test.c 
dist_listlog_test_SOURCES = listlog_test.c 
dist_listlogs_test_SOURCES = listlogs_test.c 
dist_listservices_test_SOURCES = listservices_test.c 
dist_editcart_test_SOURCES = editcart_test.c 
dist_editcut_test_SOURCES = editcut_test.c 
dist_importcart_test_SOURCES = importcart_test.c 
dist_exportcart_test_SOURCES = exportcart_test.c 
dist_exportpeaks_test_SOURCES = exportpeaks_test.c 
dist_deleteaudio_test_SOURCES = deleteaudio_test.c 
dist_copyaudio_test_SOURCES = copyaudio_test.c 

listgroups_test_LDADD = -lcurl -lrivwebcapi -lexpat
listgroup_test_LDADD = -lcurl -lrivwebcapi -lexpat
listcarts_test_LDADD = -lcurl -lrivwebcapi -lexpat
listcart_test_LDADD = -lcurl -lrivwebcapi -lexpat
listcuts_test_LDADD = -lcurl -lrivwebcapi -lexpat
listcut_test_LDADD = -lcurl -lrivwebcapi -lexpat
listschedcodes_test_LDADD = -lcurl -lrivwebcapi -lexpat
assignschedcode_test_LDADD = -lcurl -lrivwebcapi -lexpat
listcartschedcodes_test_LDADD = -lcurl -lrivwebcapi -lexpat
unassignschedcode_test_LDADD = -lcurl -lrivwebcapi -lexpat
addcart_test_LDADD  = -lcurl -lrivwebcapi -lexpat
addcut_test_LDADD  = -lcurl -lrivwebcapi -lexpat
removecart_test_LDADD  = -lcurl -lrivwebcapi -lexpat
removecut_test_LDADD  = -lcurl -lrivwebcapi -lexpat
audioinfo_test_LDADD  = -lcurl -lrivwebcapi -lexpat
audiostore_test_LDADD  = -lcurl -lrivwebcapi -lexpat
trimaudio_test_LDADD  = -lcurl -lrivwebcapi -lexpat
listlog_test_LDADD  = -lcurl -lrivwebcapi -lexpat
listlogs_test_LDADD  = -lcurl -lrivwebcapi -lexpat
listservices_test_LDADD  = -lcurl -lrivwebcapi -lexpat
editcart_test_LDADD  = -lcurl -lrivwebcapi -lexpat
editcut_test_LDADD  = -lcurl -lrivwebcapi -lexpat
importcart_test_LDADD  = -lcurl -lrivwebcapi -lexpat
exportcart_test_LDADD  = -lcurl -lrivwebcapi -lexpat
exportpeaks_test_LDADD  = -lcurl -lrivwebcapi -lexpat
deleteaudio_test_LDADD  = -lcurl -lrivwebcapi -lexpat
copyaudio_test_LDADD  = -lcurl -lrivwebcapi -lexpat

CLEANFILES = *~\
             moc_*

MAINTAINERCLEANFILES = *~\
                       *.tar.gz\
                       aclocal.m4\
                       configure\
                       Makefile.in\
                       moc_*
