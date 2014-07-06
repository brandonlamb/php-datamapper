
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * This extended decorator for PDO provides lazy connection, array quoting, a
 * new `perform()` method, and new `fetch*()` methods.
 */
ZEPHIR_INIT_CLASS(Pdm_Db_BindTracker) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, BindTracker, pdm, db_bindtracker, pdm_db_bindtracker_method_entry, 0);

	/**
	 * How many numbered placeholders in the original statement
	 *
	 * @var int
	 */
	zend_declare_property_null(pdm_db_bindtracker_ce, SL("num"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/*
	 * how many numbered placeholders to actually be bound; this may
	 * differ from 'num' in that some numbered placeholders may get
	 * replaced with quoted CSV strings
	 *
	 * @var int
	 */
	zend_declare_property_null(pdm_db_bindtracker_ce, SL("count"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Initial values to be bound
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_bindtracker_ce, SL("values"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * Named and numbered placeholders to bind at the end
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_bindtracker_ce, SL("finalValues"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * How many numbered placeholders in the original statement
 *
 * @var int
 */
PHP_METHOD(Pdm_Db_BindTracker, getNum) {


	RETURN_MEMBER(this_ptr, "num");

}

/*
 * how many numbered placeholders to actually be bound; this may
 * differ from 'num' in that some numbered placeholders may get
 * replaced with quoted CSV strings
 *
 * @var int
 */
PHP_METHOD(Pdm_Db_BindTracker, getCount) {


	RETURN_MEMBER(this_ptr, "count");

}

/**
 * Initial values to be bound
 *
 * @var array
 */
PHP_METHOD(Pdm_Db_BindTracker, getValues) {


	RETURN_MEMBER(this_ptr, "values");

}

/**
 * Named and numbered placeholders to bind at the end
 *
 * @var array
 */
PHP_METHOD(Pdm_Db_BindTracker, getFinalValues) {


	RETURN_MEMBER(this_ptr, "finalValues");

}

/**
 * Constructor
 *
 * @param array $values
 */
PHP_METHOD(Pdm_Db_BindTracker, __construct) {

	zval *values_param = NULL, *_0, *_1;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &values_param);

	if (!values_param) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	} else {
		zephir_get_arrval(values, values_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("num"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("count"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("values"), values TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("finalValues"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Magic setter
 *
 * @param string key
 * @param mixed value
 * @return void
 */
PHP_METHOD(Pdm_Db_BindTracker, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(key_param) == IS_STRING)) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	do {
		if (ZEPHIR_IS_STRING(key, "num")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setnum", NULL, value);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(key, "count")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcount", NULL, value);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(key, "values")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalues", NULL, value);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(key, "finalValues")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfinalvalues", NULL, value);
			zephir_check_call_status();
			break;
		}
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Set the num
 *
 * @param int value
 * @return void
 */
PHP_METHOD(Pdm_Db_BindTracker, setNum) {

	zval *value_param = NULL, *_0;
	int value;

	zephir_fetch_params(0, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, value);
	zephir_update_property_this(this_ptr, SL("num"), _0 TSRMLS_CC);

}

/**
 * Set the count
 *
 * @param int value
 * @return void
 */
PHP_METHOD(Pdm_Db_BindTracker, setCount) {

	zval *value_param = NULL, *_0;
	int value;

	zephir_fetch_params(0, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, value);
	zephir_update_property_this(this_ptr, SL("count"), _0 TSRMLS_CC);

}

/**
 * Set the values
 *
 * @param array value
 * @return void
 */
PHP_METHOD(Pdm_Db_BindTracker, setValues) {

	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_arrval(value, value_param);


	zephir_update_property_this(this_ptr, SL("values"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the final values
 *
 * @param array value
 * @return void
 */
PHP_METHOD(Pdm_Db_BindTracker, setFinalValues) {

	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_arrval(value, value_param);


	zephir_update_property_this(this_ptr, SL("finalValues"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

