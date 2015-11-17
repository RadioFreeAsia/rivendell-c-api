## automake.am
##
## docbook/automake.am for Rivendell C API
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
## Use automake to process this into a Makefile.in

##
## Build Dependencies
##
%.html:	%.xml
	xsltproc -o $@ $(DOCBOOK_STYLESHEETS)/xhtml/docbook.xsl $<

%.pdf:	%.xml
	xsltproc $(DOCBOOK_STYLESHEETS)/fo/docbook.xsl $< | fop - -pdf $@

%.7:	%.xml
	xsltproc $(DOCBOOK_STYLESHEETS)/manpages/docbook.xsl $<

all-local:	addcart.html\
                addcart.pdf\
                addcart.xml\
                addcut.html\
                addcut.pdf\
                addcut.xml\
                assignschedcode.html\
                assignschedcode.pdf\
                assignschedcode.xml\
                audioinfo.html\
                audioinfo.pdf\
                audioinfo.xml\
                audiostore.html\
                audiostore.pdf\
                audiostore.xml\
                clibsummary.xml\
                clibsummary.html\
                clibsummary.pdf\
                copyaudio.html\
                copyaudio.pdf\
                copyaudio.xml\
                deleteaudio.html\
                deleteaudio.pdf\
                deleteaudio.xml\
                editcart.html\
                editcart.pdf\
                editcart.xml\
                editcut.html\
                editcut.pdf\
                editcut.xml\
                exportpeaks.html\
                exportpeaks.pdf\
                exportpeaks.xml\
                export.html\
                export.pdf\
                export.xml\
                import.html\
                import.pdf\
                import.xml\
                listcartschedcodes.html\
                listcartschedcodes.pdf\
                listcartschedcodes.xml\
                listcarts.html\
                listcarts.pdf\
                listcarts.xml\
                listcart.html\
                listcart.pdf\
                listcart.xml\
                listcuts.html\
                listcuts.pdf\
                listcuts.xml\
                listcut.html\
                listcut.pdf\
                listcut.xml\
                listgroups.html\
                listgroups.pdf\
                listgroups.xml\
                listgroup.html\
                listgroup.pdf\
                listgroup.xml\
                listlogs.html\
                listlogs.pdf\
                listlogs.xml\
                listlog.html\
                listlog.pdf\
                listlog.xml\
                listschedcodes.html\
                listschedcodes.pdf\
                listschedcodes.xml\
                listservices.html\
                listservices.pdf\
                listservices.xml\
                removecart.html\
                removecart.pdf\
                removecart.xml\
                removecut.html\
                removecut.pdf\
                removecut.xml\
                trimaudio.html\
                trimaudio.pdf\
                trimaudio.xml\
                unassignschedcode.html\
                unassignschedcode.pdf\
                unassignschedcode.xml

man_MANS = addcart.7\
           addcut.7\
           assignschedcode.7\
           audioinfo.7\
           audiostore.7\
           copyaudio.7\
           deleteaudio.7\
           editcart.7\
           editcut.7\
           exportpeaks.7\
           export.7\
           import.7\
           listcartschedcodes.7\
           listcarts.7\
           listcart.7\
           listcuts.7\
           listcut.7\
           listgroups.7\
           listgroup.7\
           listlogs.7\
           listlog.7\
           listschedcodes.7\
           listservices.7\
           removecart.7\
           removecut.7\
           trimaudio.7\
           unassignschedcode.7

EXTRA_DIST = addcart.7\
             addcart.html\
             addcart.pdf\
             addcart.xml\
             addcut.7\
             addcut.html\
             addcut.pdf\
             addcut.xml\
             assignschedcode.7\
             assignschedcode.html\
             assignschedcode.pdf\
             assignschedcode.xml\
             audioinfo.7\
             audioinfo.html\
             audioinfo.pdf\
             audioinfo.xml\
             audiostore.7\
             audiostore.html\
             audiostore.pdf\
             audiostore.xml\
             clibsummary.xml\
             clibsummary.html\
             clibsummary.pdf\
             copyaudio.7\
             copyaudio.html\
             copyaudio.pdf\
             copyaudio.xml\
             deleteaudio.7\
             deleteaudio.html\
             deleteaudio.pdf\
             deleteaudio.xml\
             editcart.7\
             editcart.html\
             editcart.pdf\
             editcart.xml\
             editcut.7\
             editcut.html\
             editcut.pdf\
             editcut.xml\
             exportpeaks.7\
             exportpeaks.html\
             exportpeaks.pdf\
             exportpeaks.xml\
             export.7\
             export.html\
             export.pdf\
             export.xml\
             import.7\
             import.html\
             import.pdf\
             import.xml\
             listcartschedcodes.7\
             listcartschedcodes.html\
             listcartschedcodes.pdf\
             listcartschedcodes.xml\
             listcarts.7\
             listcarts.html\
             listcarts.pdf\
             listcarts.xml\
             listcart.7\
             listcart.html\
             listcart.pdf\
             listcart.xml\
             listcuts.7\
             listcuts.html\
             listcuts.pdf\
             listcuts.xml\
             listcut.7\
             listcut.html\
             listcut.pdf\
             listcut.xml\
             listgroups.7\
             listgroups.html\
             listgroups.pdf\
             listgroups.xml\
             listgroup.7\
             listgroup.html\
             listgroup.pdf\
             listgroup.xml\
             listlogs.7\
             listlogs.html\
             listlogs.pdf\
             listlogs.xml\
             listlog.7\
             listlog.html\
             listlog.pdf\
             listlog.xml\
             listschedcodes.7\
             listschedcodes.html\
             listschedcodes.pdf\
             listschedcodes.xml\
             listservices.7\
             listservices.html\
             listservices.pdf\
             listservices.xml\
             removecart.7\
             removecart.html\
             removecart.pdf\
             removecart.xml\
             removecut.7\
             removecut.html\
             removecut.pdf\
             removecut.xml\
             trimaudio.7\
             trimaudio.html\
             trimaudio.pdf\
             trimaudio.xml\
             unassignschedcode.7\
             unassignschedcode.html\
             unassignschedcode.pdf\
             unassignschedcode.xml

CLEANFILES = *~
MAINTAINERCLEANFILES = *~\
                       *.7\
                       *.html\
                       *.pdf\
                       aclocal.m4\
                       configure\
                       Makefile.in
