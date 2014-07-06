
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Manages PDO connection objects for default, read, and write connections.
 *
 * @package Pdm\Db
 */
ZEPHIR_INIT_CLASS(Pdm_Db_ConnectionLocator) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, ConnectionLocator, pdm, db_connectionlocator, pdm_db_connectionlocator_method_entry, 0);

	/**
	 * A registry of PDO connection entries.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_connectionlocator_ce, SL("registry"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether or not registry entries have been converted to objects.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_connectionlocator_ce, SL("converted"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_connectionlocator_ce TSRMLS_CC, 1, pdm_db_connectionlocatorinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param callable $defaultCallback A callable to create a default connection.
 * @param array $read An array of callables to create read connections.
 * @param array $write An array of callables to create write connections.
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, __construct) {

	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	HashTable *_4, *_8;
	HashPosition _3, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *read = NULL, *write = NULL, *_0, *_2;
	zval *defaultCallback = NULL, *read_param = NULL, *write_param = NULL, *name = NULL, *callback = NULL, *_1, **_5, **_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &defaultCallback, &read_param, &write_param);

	if (!defaultCallback) {
		defaultCallback = ZEPHIR_GLOBAL(global_null);
	}
	if (!read_param) {
		ZEPHIR_INIT_VAR(read);
		array_init(read);
	} else {
		zephir_get_arrval(read, read_param);
	}
	if (!write_param) {
		ZEPHIR_INIT_VAR(write);
		array_init(write);
	} else {
		zephir_get_arrval(write, write_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 5);
	zephir_array_update_string(&_0, SL("default"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("read"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("write"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("registry"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 5);
	zephir_array_update_string(&_2, SL("default"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_2, SL("read"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_2, SL("write"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("converted"), _2 TSRMLS_CC);
	if (Z_TYPE_P(defaultCallback) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefault", NULL, defaultCallback);
		zephir_check_call_status();
	}
	zephir_is_iterable(read, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(name, _4, _3);
		ZEPHIR_GET_HVALUE(callback, _5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setread", &_6, name, callback);
		zephir_check_call_status();
	}
	zephir_is_iterable(write, &_8, &_7, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(name, _8, _7);
		ZEPHIR_GET_HVALUE(callback, _9);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwrite", &_10, name, callback);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default connection registry entry.
 *
 * @param callable $callback The registry entry.
 * @return ConnnectionLocatorInterface
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, setDefault) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_3;
	zval *callback, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (Z_TYPE_P(callback) == IS_OBJECT) {
		if (zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "default", 1);
			zephir_update_property_array(this_ptr, SL("registry"), _0, callback TSRMLS_CC);
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "default", 1);
			zephir_update_property_array(this_ptr, SL("converted"), _1, ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			RETURN_THIS();
		}
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zend_exception_get_default(TSRMLS_C));
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SS(_3, "Must pass a callable to ", "setDefault");
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_2, "pdm/db/connectionlocator.zep", 83 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns the default connection object.
 *
 * @return PdoInterface
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, getDefault) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *callback, *_0, *_1, *_2, *_3 = NULL, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("converted"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("default"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (!(zephir_is_true(_1))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(callback);
		zephir_array_fetch_string(&callback, _2, SL("default"), PH_NOISY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "call_user_func", &_4, callback);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5);
		ZVAL_STRING(_5, "default", 1);
		zephir_update_property_array(this_ptr, SL("registry"), _5, _3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "default", 1);
		zephir_update_property_array(this_ptr, SL("converted"), _6, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
	zephir_array_fetch_string(&_7, _2, SL("default"), PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_7);

}

/**
 * Sets a read connection registry entry by name.
 *
 * @param string $name The name of the registry entry.
 * @param callable $callback The registry entry.
 * @return ConnnectionLocatorInterface
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, setRead) {

	zval *name_param = NULL, *callback, *registry = NULL, *converted = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callback);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	if (Z_TYPE_P(callback) == IS_OBJECT) {
		if (zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC)) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
			zephir_array_fetch_string(&_1, _0, SL("read"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CPY_WRT(registry, _1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("converted"), PH_NOISY_CC);
			zephir_array_fetch_string(&_1, _2, SL("read"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CPY_WRT(converted, _1);
			zephir_array_update_zval(&registry, name, &callback, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&converted, name, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "read", 1);
			zephir_update_property_array(this_ptr, SL("registry"), _3, registry TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "read", 1);
			zephir_update_property_array(this_ptr, SL("converted"), _4, converted TSRMLS_CC);
			RETURN_THIS();
		}
	}
	RETURN_THIS();

}

/**
 * Returns a read connection by name; if no name is given, picks a
 * random connection; if no read connections are present, returns the
 * default connection.
 *
 * @param string $name The read connection name to return.
 * @return PdoInterface
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, getRead) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "read", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", NULL, _0, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a write connection registry entry by name.
 *
 * @param string $name The name of the registry entry.
 * @param callable $callback The registry entry.
 * @return ConnnectionLocatorInterface
 *
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, setWrite) {

	zval *name_param = NULL, *callback, *registry = NULL, *converted = NULL, *_0, *_1, *_2, *_3, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callback);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	if (Z_TYPE_P(callback) == IS_OBJECT) {
		if (zephir_instance_of_ev(callback, zend_ce_closure TSRMLS_CC)) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
			zephir_array_fetch_string(&_1, _0, SL("write"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CPY_WRT(registry, _1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("converted"), PH_NOISY_CC);
			zephir_array_fetch_string(&_1, _2, SL("write"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CPY_WRT(converted, _1);
			zephir_array_update_zval(&registry, name, &callback, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&converted, name, &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "write", 1);
			zephir_update_property_array(this_ptr, SL("registry"), _3, registry TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "write", 1);
			zephir_update_property_array(this_ptr, SL("converted"), _4, converted TSRMLS_CC);
			RETURN_THIS();
		}
	}
	RETURN_THIS();

}

/**
 * Returns a write connection by name; if no name is given, picks a
 * random connection; if no write connections are present, returns the
 * default connection.
 *
 * @param string $name The write connection name to return.
 * @return PdoInterface
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, getWrite) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	} else {
	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(name_param) == IS_STRING)) {
		name = name_param;
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "write", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", NULL, _0, name);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a connection by name.
 *
 * @param string $type The connection type ("read" or "write").
 * @param string $name The name of the connection.
 * @return PdoInterface
 * @throws Exception\ConnectionNotFound
 */
PHP_METHOD(Pdm_Db_ConnectionLocator, getConnection) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *name = NULL, *callback, *_0, *_1, *_2, *_3, *_5, *_6, *_7, *_8, *_9, *_10 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &name);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(type_param) == IS_STRING)) {
		type = type_param;
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	ZEPHIR_SEPARATE_PARAM(name);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, type, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (!(zephir_is_true(_1))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdefault", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(name, "")) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
		zephir_array_fetch(&_3, _2, type, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&name, "array_rand", &_4, _3);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, type, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (!(zephir_array_isset(_3, name))) {
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, pdm_db_exception_connectionnotfound_ce);
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_VSV(_6, type, ":", name);
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "pdm/db/connectionlocator.zep", 210 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("converted"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, type, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch(&_7, _3, name, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (!(zephir_is_true(_7))) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
		zephir_array_fetch(&_9, _8, type, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_OBS_VAR(callback);
		zephir_array_fetch(&callback, _9, name, PH_NOISY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_10, "call_user_func", &_11, callback);
		zephir_check_call_status();
		zephir_update_property_array_multi(this_ptr, SL("registry"), &_10 TSRMLS_CC, SL("zz"), 2, type, name);
		zephir_update_property_array_multi(this_ptr, SL("converted"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC, SL("zz"), 2, type, name);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("registry"), PH_NOISY_CC);
	zephir_array_fetch(&_3, _2, type, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch(&_9, _3, name, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_9);

}

