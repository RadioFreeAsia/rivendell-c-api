dnl configure.ac
dnl
dnl Autoconf configuration.
dnl Use autoconf to process this into a configure script
dnl
dnl   (C) Copyright 2015 Fred Gleason <fredg@paravelsystems.com>
dnl
dnl   This program is free software; you can redistribute it and/or modify
dnl   it under the terms of the GNU General Public License version 2 as
dnl   published by the Free Software Foundation.
dnl
dnl   This program is distributed in the hope that it will be useful,
dnl   but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl   GNU General Public License for more details.
dnl
dnl   You should have received a copy of the GNU General Public
dnl   License along with this program; if not, write to the Free Software
dnl   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
dnl

AC_INIT([rivwebcapi],m4_esyscmd(cat PACKAGE_VERSION))
AM_INIT_AUTOMAKE
AC_SUBST(RPM_RELEASE,1)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])
AC_CONFIG_MACRO_DIR([m4])

#
# Some Fully Resolved Install Paths
# (for the packaging system and friends)
#
if test ${prefix} = "NONE" ; then
  PREFIX=/usr/local
  AC_SUBST(LOCAL_PREFIX,/usr/local)
else
  PREFIX=${prefix}
  AC_SUBST(LOCAL_PREFIX,${prefix})
fi

#
# Basic Compiler Checks
#
AC_PROG_CC
AC_PROG_LIBTOOL

# to avoid rpath usage :
# http://wiki.debian.net/index.cgi?RpathIssue
case ${host} in
  *-pc-linux-gnu)
    AC_MSG_RESULT([Fixing libtool for -rpath problems.])
    sed < libtool > libtool-2 \
    's/^hardcode_libdir_flag_spec.*$/hardcode_libdir_flag_spec=" -D__LIBTOOL_IS_A_FOOL__ "/'
    mv libtool-2 libtool
    chmod 755 libtool
  ;;
esac

#
# Option Switches
#
AC_ARG_ENABLE(docbook,[  --disable-docbook       disable building of documentation],[DOCBOOK_DISABLED=yes],[])

#
# Determine Library API Versioning
#
# From http://www.gnu.org/software/libtool/manual.html#Updating-version-info
#
#   1. Start with version information of 0:0:0 for each libtool library.
#   2. Update the version information only immediately before a public
#      release of your software. More frequent updates are unnecessary,
#      and only guarantee that the current interface number gets larger
#      faster.
#   3. If the library source code has changed at all since the last update,
#      then increment 'REVISION' (c:r:a becomes c:r+1:a).
#   4. If any interfaces have been added, removed, or changed since the last
#      update, increment 'CURRENT', and set 'REVISION' to 0.
#   5. If any interfaces have been added since the last public release, then
#      increment 'AGE'.
#   6. If any interfaces have been removed since the last public release,
#      then set 'AGE' to 0.
CURRENT=0
REVISION=0
AGE=0
POINT=$(($CURRENT - $AGE))

#
# Calculate the Library Version Values
#
AC_SUBST(INTERFACE_CURRENT,$CURRENT)
AC_SUBST(INTERFACE_REVISION,$REVISION)
AC_SUBST(INTERFACE_AGE,$AGE)
AC_SUBST(INTERFACE_MAJOR,$POINT)
AC_SUBST(INTERFACE_MINOR,$AGE)
AC_SUBST(INTERFACE_POINT,$REVISION)

#
# Determine the target architecture
#
AR_GCC_TARGET()
AC_SUBST(VENDOR,$ar_gcc_distro)
AC_SUBST(ARCH,$ar_gcc_arch)
if test $ar_gcc_arch = x86_64 ; then
  LIB_PATH=$PREFIX/lib64
  AC_SUBST(RD_LIB_PATH,lib64)
else
  LIB_PATH=$PREFIX/lib
  AC_SUBST(RD_LIB_PATH,lib)
fi

#
# Determine Distro
#
AR_GET_DISTRO()
AC_SUBST(DISTRO,$ar_gcc_distro)

#
# Check for LibCurl
#
AC_CHECK_HEADER(curl/curl.h,[],[AC_MSG_ERROR([*** LibCurl not found ***])])

#
# Check for Expat
#
AC_CHECK_HEADER(expat.h,[],[AC_MSG_ERROR([*** Expat not found ***])])

#
# Check for DocBook Toolchain
#
AC_CHECK_PROG(XSLTPROC_FOUND,xsltproc,[yes])
AC_CHECK_PROG(FOP_FOUND,fop,[yes])
if test $XSLTPROC_FOUND ; then
   if test $FOP_FOUND ; then
      if test $DOCBOOK_STYLESHEETS ; then
        if test -z $DOCBOOK_DISABLED ; then
          USING_DOCBOOK=yes
	fi
      fi
   fi
fi
AM_CONDITIONAL([DOCBOOK_AM], [test "$USING_DOCBOOK" = yes])

#
# Configure RPM Build
#
AC_CHECK_PROG(RPMBUILD_FOUND,rpmbuild,[yes],[])
if test -z $RPMBUILD_FOUND ; then
  AC_SUBST(RPMBUILD,rpm)
else
  AC_SUBST(RPMBUILD,rpmbuild)
fi
if test -d /usr/src/redhat ; then
  AC_SUBST(RPM_ROOT,/usr/src/redhat)
  AC_SUBST(VENDOR,redhat)
else
  AC_SUBST(RPM_ROOT,/usr/src/packages)
  AC_SUBST(VENDOR,suse)
fi 

AC_CONFIG_FILES([ \
    docbook/Makefile \
    rivendell/Makefile \
    tests/Makefile \
    Makefile \
    rivendell.pc \
    rivwebcapi.spec \
    ])
AC_OUTPUT()

AC_MSG_NOTICE()
AC_MSG_NOTICE(Now enter 'make' to build the software.)
AC_MSG_NOTICE()
