/* include/config.h.  Generated from config.h.in by configure.  */
/************************************************************************
 *
 * NDBXT Includes
 * Copyright (c) 2005-2007 Ethan Galstad
 * Last Modified: 10-19-2007
 *
 ************************************************************************/

#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include <stdlib.h>

#define STDC_HEADERS 1
#define HAVE_STRDUP 1
#define HAVE_STRSTR 1
#define HAVE_STRTOUL 1
#define HAVE_INITGROUPS 1
#define HAVE_STRTOF 1

#define SIZEOF_INT 4
#define SIZEOF_SHORT 2
#define SIZEOF_LONG 8

/* stupid stuff for u_int32_t */
/* #undef U_INT32_T_IS_USHORT */
/* #undef U_INT32_T_IS_UINT */
/* #undef U_INT32_T_IS_ULONG */
/* #undef U_INT32_T_IS_UINT32_T */

#ifdef U_INT32_T_IS_USHORT
typedef unsigned short u_int32_t;
#endif
#ifdef U_INT32_T_IS_ULONG
typedef unsigned long u_int32_t;
#endif
#ifdef U_INT32_T_IS_UINT
typedef unsigned int u_int32_t;
#endif
#ifdef U_INT32_T_IS_UINT32_t
typedef uint32_t u_int32_t;
#endif

/* stupid stuff for int32_t */
/* #undef INT32_T_IS_SHORT */
/* #undef INT32_T_IS_INT */
/* #undef INT32_T_IS_LONG */

#ifdef INT32_T_IS_USHORT
typedef short int32_t;
#endif
#ifdef INT32_T_IS_ULONG
typedef long int32_t;
#endif
#ifdef INT32_T_IS_UINT
typedef int int32_t;
#endif


#define SOCKET_SIZE_TYPE size_t
#define GETGROUPS_T gid_t
#define RETSIGTYPE void

#define HAVE_GETOPT_H 1
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#define HAVE_STRINGS_H 1
#define HAVE_STRING_H 1
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#define HAVE_UNISTD_H 1
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#define HAVE_STDARG_H 1
#ifdef HAVE_STDARG_H
#include <stdarg.h>
#endif

#define HAVE_SIGNAL_H 1
#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

#define HAVE_SYSLOG_H 1
#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

#define HAVE_SYS_STAT_H 1
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#define HAVE_FCNTL_H 1
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#define HAVE_SYS_SENDFILE_H 1
#ifdef HAVE_SYS_SENDFILE_H
#include <sys/sendfile.h>
#endif

#define HAVE_SYS_TYPES_H 1
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#define HAVE_SYS_WAIT_H 1
#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#ifndef WEXITSTATUS
# define WEXITSTATUS(stat_val) ((unsigned)(stat_val) >> 8)
#endif
#ifndef WIFEXITED
# define WIFEXITED(stat_val) (((stat_val) & 255) == 0)
#endif

#define HAVE_ERRNO_H 1
#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#define HAVE_SYS_MMAN_H 1
#ifdef HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif

/* needed for the time_t structures we use later... */
#define TIME_WITH_SYS_TIME 1
#define HAVE_SYS_TIME_H 1
#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif


#define HAVE_SYS_UN_H 1
#ifdef HAVE_SYS_UN_H
#include <sys/un.h>
#endif

#define HAVE_SYS_SOCKET_H 1
#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

/* Define to 'int' if <sys/socket.h> does not define */
/* #undef socklen_t */

/* #undef HAVE_SOCKET_H */
#ifdef HAVE_SOCKET_H
#include <socket.h>
#endif

/* Solaris 8 doesn't have SUN_LEN */
#define HAVE_SUN_LEN 1
#ifndef HAVE_SUN_LEN
#define SUN_LEN(sunp) ((size_t)((struct sockaddr_un *)0)->sun_path + strlen((sunp)->sun_path))
#endif

/* #undef HAVE_TCPD_H */
#ifdef HAVE_TCPD_H
#include <tcpd.h>
#endif

#define HAVE_NETINET_IN_H 1
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#define HAVE_ARPA_INET_H 1
#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#define HAVE_NETDB_H 1
#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#define HAVE_CTYPE_H 1
#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

#define HAVE_PWD_H 1
#ifdef HAVE_PWD_H
#include <pwd.h>
#endif
 
#define HAVE_GRP_H 1
#ifdef HAVE_GRP_H
#include <grp.h>
#endif

#define HAVE_DIRENT_H 1
#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#else
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#endif

#define HAVE_MATH_H 1
#ifdef HAVE_MATH_H
#include <math.h>
#endif

#define HAVE_FLOAT_H 1
#ifdef HAVE_FLAT_H
#include <flat.h>
#endif

#define HAVE_LIMITS_H 1
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#define HAVE_UNISTD_H 1
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#define HAVE_VALUES_H 1
#ifdef HAVE_VALUES_H
#include <values.h>
#endif


#define USE_MYSQL 1
/* #undef HAVE_MYSQL */
#ifdef USE_MYSQL
#define HAVE_MYSQL 1
#include <mysql/mysql.h>
#include <mysql/errmsg.h>
#endif

/* #undef USE_PGSQL */
/* #undef HAVE_PGSQL */
#ifdef USE_PGSQL
#define HAVE_PGSQL 1
#include <libpq-fe.h>
#endif

/* #undef HAVE_SSL */
#ifdef HAVE_SSL
#include <rsa.h>
#include <crypto.h>
#include <dh.h>
#include <pem.h>
#include <ssl.h>
#include <err.h>
#include <rand.h>
#endif

#define USE_NANOSLEEP 1

#endif

/* add by roy@rootk.com */
#include "cJSON.h"
#include <amqp.h>
#include <amqp_tcp_socket.h>
#include <amqp_ssl_socket.h>
#include <amqp_framing.h>
#include <mongo.h>
#include <pcre.h>
