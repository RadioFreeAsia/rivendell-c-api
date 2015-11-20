## automake.am
##
## Top level automake.am for Rivendell
##
## Use automake to process this into a Makefile.in
##
##   (C) Copyright 2002-2015 Fred Gleason <fredg@paravelsystems.com>
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

if DOCBOOK_AM
  DOCBOOK_AM_OPT = docbook
endif

SUBDIRS = $(DOCBOOK_AM_OPT) rivendell\
          tests

ACLOCAL_AMFLAGS = -I m4

maintainer-clean-local:	
	rm -rf m4

rpm:	dist
	cp rivwebcapi-$(VERSION).tar.gz $(HOME)/rpmbuild/SOURCES/
	$(RPMBUILD) -ba --target $(ARCH)-$(VENDOR)-linux rivwebcapi.spec
	mv $(HOME)/rpmbuild/RPMS/$(ARCH)/rivwebcapi-*.rpm $(top_srcdir)/
	mv $(HOME)/rpmbuild/SRPMS/rivwebcapi-*.src.rpm $(top_srcdir)/
	rm $(HOME)/rpmbuild/SOURCES/rivwebcapi-$(VERSION).tar.gz
	rm -rf $(HOME)/rpmbuild/BUILD/rivwebcapi-$(VERSION)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = rivendell.pc

EXTRA_DIST = autogen.sh\
             get_distro.sh\
             get_target.sh\
             PACKAGE_VERSION\
             rivendell.pc.in\
             rivwebcapi.spec.in

CLEANFILES = *~\
             *.mo\
             *.rpm\
             *.tar.gz\
             *.tgz\
             *.zip

DISTCLEANFILES = config.guess\
                 config.sub\
                 ltmain.sh\
                 make_slack\
                 rivendell.pc

MAINTAINERCLEANFILES = *~\
                       *.tar.gz\
                       aclocal.m4\
                       Makefile.in\
                       config.guess\
                       config.status\
                       config.sub\
                       configure\
                       depcomp\
                       install-sh\
                       libtool\
                       ltmain.sh\
                       missing\
                       mkinstalldirs
