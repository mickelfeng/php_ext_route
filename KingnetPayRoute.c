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

#include "php_KingnetPayRoute.h"


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
	char *name;
	uint name_len;
	zval *route_map,**pdata;
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name,&name_len) == FAILURE) {
		RETURN_NULL();
	}

	if (!name_len) {
		RETURN_FALSE;
	}

	route_map = zend_read_property(KingnetPayRoute_ce, getThis(), ZEND_STRL("route_map"), 1 TSRMLS_CC);

	if (zend_hash_find(Z_ARRVAL_P(route_map),name,name_len+1,(void **)&pdata) == SUCCESS) {
		RETURN_ZVAL(*pdata,1,0);
	}

	RETURN_NULL();
}
PHP_METHOD(KingnetPayRoute,addRoute) {

	char *name;
	uint name_len;
	zval *route_map,*info;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sz", &name, &name_len, &info) == FAILURE) {
		RETURN_NULL();
	}

	if (!name_len) {
		RETURN_FALSE;
	}

	// 1 is no notice messages
	route_map = zend_read_property(KingnetPayRoute_ce, getThis(), ZEND_STRL("route_map"), 1 TSRMLS_CC);

	// I dont know why add this line
	Z_ADDREF_P(info);
	zend_hash_update(Z_ARRVAL_P(route_map), name, name_len + 1, (void **)&info, sizeof(zval *), NULL);

	RETURN_ZVAL(getThis(), 1, 0);
}

PHP_METHOD(KingnetPayRoute,getRouteMap) {
	zval *route_map;

	route_map = zend_read_property(KingnetPayRoute_ce, getThis(), ZEND_STRL("route_map"), 1 TSRMLS_CC);

	RETURN_ZVAL(route_map,1,0);
}
/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
