/* rd_common.c
 *
 * Common Utility Functions for the Rivendell Access Library
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

#include "rd_common.h"

unsigned RD_ReadBool(const char *val)
{
  if((strcasecmp(val,"true")==0)||(strcasecmp(val,"yes")==0)||
     (strcasecmp(val,"on")==0)) {
    return 1;
  }
  else {
    return 0;
  }
}

/****************************************************************
 *   RD_DateTimeConvert
 *     Take a DateTime String and converts to a tm struct.
 *     Assumes a Z means Zulu (GMT) Always returns localtime
 *     in tm struct pointer. Returns null tm on invalid date
*****************************************************************/

struct tm RD_DateTimeConvert( const char *datein)
{
    struct tm datetimetm = {0};
    struct tm *tmptr;
    time_t rawtime;
    time_t newrawtime;
    char theyear[5];
    char themonth[3];
    char theday[3];
    char thehr[3];
    char themin[3];
    char thesec[3];
    char plusminusz[2];
    char offsethr[3];
    char offsetmin[3];
    int offhr = 0;
    int offmin = 0;
    int val;

    tmptr = &datetimetm;

    if ((strlen(datein) < 19)  ||   // INVALID DATE
        (strlen(datein) > 26) )  
        return datetimetm;

    strlcpy(theyear,datein,4);
    strlcpy(themonth,datein+5,2);
    strlcpy(theday,datein+8,2);
    strlcpy(thehr,datein+11,2);
    strlcpy(themin,datein+14,2);
    strlcpy(thesec,datein+17,2);
    if (strlen(datein) > 19)  
    {
        strlcpy(plusminusz,datein+19,1);
        if ( (( strcmp(plusminusz,"+"))==0) ||
             (( strcmp(plusminusz,"-"))==0)  )
        {
    	    strlcpy(offsethr,datein+20,2);
    	    strlcpy(offsetmin,datein+23,2);
        }
    }
    val = atoi(theyear) - 1900;
    tmptr->tm_year = val;
    val = atoi(themonth) - 1;
    tmptr->tm_mon  = val;
    tmptr->tm_mday = atoi(theday);
    tmptr->tm_hour = atoi(thehr);
    tmptr->tm_min  = atoi(themin);
    tmptr->tm_sec  = atoi(thesec);
    rawtime = mktime (tmptr);  
    newrawtime = rawtime; 
    if ((strcmp(plusminusz,"Z")) != 0)
    {
        if (strlen(datein)==25)
        {
            offhr = atoi(offsethr);
            offmin = atoi(offsetmin);
        }
        if ((strcmp(plusminusz,"-"))== 0)
        {
            newrawtime = rawtime + ((offhr * 3600) +
                (offmin * 60));
        }
        else 
        {
            newrawtime = rawtime - ((offhr * 3600) -
                (offmin * 60));
        }
    }
//    Get the local offset from UTC
    time_t currtime;
    struct tm * timeinfo;
    time( &currtime );
    timeinfo = gmtime (&currtime);
    time_t utc = mktime (timeinfo);
    timeinfo = localtime(&currtime);
    time_t local = mktime(timeinfo);
    double offsetfromutc = difftime(local,utc);
    if (timeinfo->tm_isdst)
        offsetfromutc += 3600;
    newrawtime += offsetfromutc;
    localtime_r(&newrawtime,tmptr);
    return datetimetm;
}
    
/****************************************************************
 *   strlcpy
 *     Copies a strng buffer into a string buffer with size bufsiz
 *     Returns size_t length copied. Null Terminates Automatically
*****************************************************************/
size_t strlcpy(char * dest, const char* src, size_t bufsize)
{
    size_t srclen = strlen(src);
    size_t len;
    if (bufsize == 0)
        return bufsize;
    len = (bufsize < srclen) ? bufsize : srclen;
    memcpy(dest,src,len);
    dest[len]='\0';
    return len;
}

