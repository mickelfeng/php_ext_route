/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2010 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 297205 2010-03-30 21:09:07Z johannes $ */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"

#ifndef PHP_KINGNETPAYROUTE_H
#define PHP_KINGNETPAYROUTE_H

extern zend_module_entry KingnetPayRoute_module_entry;
#define phpext_KingnetPayRoute_ptr &KingnetPayRoute_module_entry

#ifdef PHP_WIN32
#	define PHP_KINGNETPAYROUTE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_KINGNETPAYROUTE_API __attribute__ ((visibility("default")))
#else
#	define PHP_KINGNETPAYROUTE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(KingnetPayRoute);
PHP_MSHUTDOWN_FUNCTION(KingnetPayRoute);
PHP_RINIT_FUNCTION(KingnetPayRoute);
PHP_RSHUTDOWN_FUNCTION(KingnetPayRoute);
PHP_MINFO_FUNCTION(KingnetPayRoute);

PHP_FUNCTION(confirm_KingnetPayRoute_compiled);	/* For testing, remove later. */
PHP_METHOD(KingnetPayRoute,__construct);
PHP_METHOD(KingnetPayRoute,__destruct);
PHP_METHOD(KingnetPayRoute,getRoute);
PHP_METHOD(KingnetPayRoute,addRoute);
PHP_METHOD(KingnetPayRoute,getRouteMap);

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(KingnetPayRoute)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(KingnetPayRoute)
*/

/* In every utility function you add that needs to use variables
   in php_KingnetPayRoute_globals, call TSRMLS_FETCH(); after declaring other
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as KINGNETPAYROUTE_G(variable).  You are
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define KINGNETPAYROUTE_G(v) TSRMG(KingnetPayRoute_globals_id, zend_KingnetPayRoute_globals *, v)
#else
#define KINGNETPAYROUTE_G(v) (KingnetPayRoute_globals.v)
#endif

#endif	/* PHP_KINGNETPAYROUTE_H */

/* If you declare any globals in php_KingnetPayRoute.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(KingnetPayRoute)
*/

/* True global resources - no need for thread safety here */
static int le_KingnetPayRoute;
 /* 类方法的参数 */
ZEND_BEGIN_ARG_INFO(routeName_args, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()
/* {{{ KingnetPayRoute_functions[]
 *
 * Every user visible function must have an entry in KingnetPayRoute_functions[].
 */
const zend_function_entry KingnetPayRoute_functions[] = {
	{NULL, NULL, NULL}	/* Must be the last line in KingnetPayRoute_functions[] */
};
const zend_function_entry route_functions[] = {
	PHP_ME(KingnetPayRoute, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(KingnetPayRoute, __destruct,  NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(KingnetPayRoute, getRoute,  routeName_args, ZEND_ACC_PUBLIC)// get route info
	PHP_ME(KingnetPayRoute, addRoute,  routeName_args, ZEND_ACC_PUBLIC)// add route info
	PHP_ME(KingnetPayRoute, getRouteMap,  NULL, ZEND_ACC_PUBLIC)// get route map = get all route info
	{NULL, NULL, NULL}	/* Must be the last line in KingnetPayRoute_functions[] */
};
/* }}} */

/* {{{ KingnetPayRoute_module_entry
 */
zend_module_entry KingnetPayRoute_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"KingnetPayRoute",
	KingnetPayRoute_functions,
	PHP_MINIT(KingnetPayRoute),
	PHP_MSHUTDOWN(KingnetPayRoute),
	PHP_RINIT(KingnetPayRoute),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(KingnetPayRoute),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(KingnetPayRoute),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_KINGNETPAYROUTE
ZEND_GET_MODULE(KingnetPayRoute)
#endif


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
