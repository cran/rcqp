### ===========================================================================
### File: "configure.ac"
###                        Created: 2010-06-24 08:46:27
###              Last modification: 2012-05-11 10:42:07
### Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
###          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
### This is part of the R package 'rcqp'.
### ===========================================================================
###
### Process this file with autoconf to produce a configure script.
###

AC_PREREQ(2.60)

AC_INIT([rcqp],[1.0])

# Check for pkg-config
AC_PATH_PROGS(PKG_CONFIG, pkg-config) 

if test -n "${PKG_CONFIG}"; then
	if (${PKG_CONFIG} --exists libpcre); then
		RCQP_PCRE_CFLAGS=`pkg-config --cflags libpcre`
		RCQP_PCRE_LFLAGS=`pkg-config --libs libpcre`
    else
         echo "ERROR: 'pcre' library not found by pkg-config. Please install it."
         exit 1
    fi
	
	if (${PKG_CONFIG} --exists glib-2.0); then
		RCQP_GLIB_CFLAGS=`pkg-config --cflags glib-2.0`
		RCQP_GLIB_LFLAGS=`pkg-config --libs glib-2.0`
    else
         echo "ERROR: 'glib-2.0' library not found by pkg-config. Please install it."
         exit 1
    fi	
	
else
    echo "ERROR: can't find pkg-config. Please install it."
    exit 1
fi

AC_SUBST(RCQP_PCRE_CFLAGS)
AC_SUBST(RCQP_PCRE_LFLAGS)
AC_SUBST(RCQP_GLIB_CFLAGS)
AC_SUBST(RCQP_GLIB_LFLAGS)


# C support
# ---------
AC_PROG_CC()
AC_PROG_LEX()
AC_PROG_YACC()

# Support the MacPorts location
LDFLAGS="$LDFLAGS -L/opt/local/lib"




# Process the .in files
# ---------------------
AC_CONFIG_FILES(
[ src/Makevars
])

AC_OUTPUT

