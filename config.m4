dnl $Id$
dnl config.m4 for extension KingnetPayRoute

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(KingnetPayRoute, for KingnetPayRoute support,
dnl Make sure that the comment is aligned:
dnl [  --with-KingnetPayRoute             Include KingnetPayRoute support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(KingnetPayRoute, whether to enable KingnetPayRoute support,
dnl Make sure that the comment is aligned:
[  --enable-KingnetPayRoute           Enable KingnetPayRoute support])

if test "$PHP_KINGNETPAYROUTE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-KingnetPayRoute -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/KingnetPayRoute.h"  # you most likely want to change this
  dnl if test -r $PHP_KINGNETPAYROUTE/$SEARCH_FOR; then # path given as parameter
  dnl   KINGNETPAYROUTE_DIR=$PHP_KINGNETPAYROUTE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for KingnetPayRoute files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       KINGNETPAYROUTE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$KINGNETPAYROUTE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the KingnetPayRoute distribution])
  dnl fi

  dnl # --with-KingnetPayRoute -> add include path
  dnl PHP_ADD_INCLUDE($KINGNETPAYROUTE_DIR/include)

  dnl # --with-KingnetPayRoute -> check for lib and symbol presence
  dnl LIBNAME=KingnetPayRoute # you may want to change this
  dnl LIBSYMBOL=KingnetPayRoute # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $KINGNETPAYROUTE_DIR/lib, KINGNETPAYROUTE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_KINGNETPAYROUTELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong KingnetPayRoute lib version or lib not found])
  dnl ],[
  dnl   -L$KINGNETPAYROUTE_DIR/lib -lm
  dnl ])
  dnl
  PHP_SUBST(KINGNETPAYROUTE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(KingnetPayRoute, KingnetPayRoute.c, $ext_shared)
fi
