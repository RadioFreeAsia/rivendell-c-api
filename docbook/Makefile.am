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

EXTRA_DIST = addcart.html\
             addcart.pdf\
             addcart.xml\
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

CLEANFILES = *~
MAINTAINERCLEANFILES = *~\
                       *.7\
                       *.html\
                       *.pdf\
                       aclocal.m4\
                       configure\
                       Makefile.in
