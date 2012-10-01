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
#include "php_KingnetPayRoute.h"

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
	PHP_ME(KingnetPayRoute, getRoute,  routeName_args, ZEND_ACC_PUBLIC)
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

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("KingnetPayRoute.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_KingnetPayRoute_globals, KingnetPayRoute_globals)
    STD_PHP_INI_ENTRY("KingnetPayRoute.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_KingnetPayRoute_globals, KingnetPayRoute_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_KingnetPayRoute_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_KingnetPayRoute_init_globals(zend_KingnetPayRoute_globals *KingnetPayRoute_globals)
{
	KingnetPayRoute_globals->global_value = 0;
	KingnetPayRoute_globals->global_string = NULL;
}
*/
/* }}} */

zend_class_entry *KingnetPayRoute_ce;

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(KingnetPayRoute)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	zend_class_entry KingnetPayRoute;
	INIT_CLASS_ENTRY(KingnetPayRoute, "KingnetPayRoute", route_functions);

	KingnetPayRoute_ce = zend_register_internal_class_ex(&KingnetPayRoute, NULL, NULL TSRMLS_CC);
	zend_declare_property_null(KingnetPayRoute_ce, ZEND_STRL("route_map"), ZEND_ACC_PRIVATE TSRMLS_CC);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(KingnetPayRoute)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(KingnetPayRoute)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(KingnetPayRoute)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(KingnetPayRoute)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "KingnetPayRoute support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

PHP_METHOD(KingnetPayRoute,__construct) {
	zval *self;
	zval *val;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &val) == FAILURE) {
		RETURN_NULL();
	}
	self = getThis();
	zend_update_property(Z_OBJCE_P(self), self, ZEND_STRL("route_map"), val TSRMLS_CC);
	RETURN_TRUE;
}
PHP_METHOD(KingnetPayRoute,__destruct) {
}
PHP_METHOD(KingnetPayRoute,getRoute) {
	char *route_info;
	zval *self,*route_map,**pdata,*name;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_NULL();
	}

	self = getThis();
	route_map = zend_read_property(Z_OBJCE_P(self), self, ZEND_STRL("route_map"), 0 TSRMLS_CC);
	if (zend_hash_find(Z_ARRVAL_P(route_map),Z_STRVAL_P(name),Z_STRLEN_P(name)+1,(void **)&pdata) != FAILURE) {
		route_info = Z_STRVAL_PP(pdata);
		RETURN_STRING(route_info,1);
	} else {
		RETURN_ZVAL(route_map,1,0);
	}
	RETURN_TRUE;
}
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
