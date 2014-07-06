
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
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"

#include <ext/pdo/php_pdo_driver.h>



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
ZEPHIR_INIT_CLASS(Pdm_Db_Pdo) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db, Pdo, pdm, db_pdo, php_pdo_get_dbh_ce(), pdm_db_pdo_method_entry, 0);

	/**
	 * The instance of PDO being decorated.
	 *
	 * @var PDO
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The attributes for a lazy connection.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The DSN for a lazy connection.
	 *
	 * @var string
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("dsn"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * PDO options for a lazy connection.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The password for a lazy connection.
	 *
	 * @var string
	 *
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("password"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The current profile information.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("profile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * A query profiler.
	 *
	 * @var ProfilerInterface
	 *
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("profiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The username for a lazy connection.
	 *
	 * @var string
	 *
	 */
	zend_declare_property_null(pdm_db_pdo_ce, SL("username"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_pdo_ce TSRMLS_CC, 1, pdm_db_pdointerface_ce);
	return SUCCESS;

}

/**
 *
 * This constructor is pseudo-polymorphic. You may pass a normal set of PDO
 * constructor parameters, and ExtendedPdo will use them for a lazy
 * connection. Alternatively, if the `$dsn` parameter is an existing PDO
 * instance, that instance will be decorated by ExtendedPdo; the remaining
 * parameters will be ignored.
 *
 * @param PDO|string $dsn The data source name for a lazy PDO connection,
 * or an existing instance of PDO. If the latter, the remaining params are
 * ignored.
 * @param string $username The username for a lazy connection.
 * @param string $password The password for a lazy connection.
 * @param array $options Driver-specific options for a lazy connection.
 * @param array $attributes Attributes to set after a lazy connection.
 * @see http://php.net/manual/en/pdo.construct.php
 *
 */
PHP_METHOD(Pdm_Db_Pdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zval *username = NULL, *password = NULL;
	zval *dsn, *username_param = NULL, *password_param = NULL, *options = NULL, *attributes = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &dsn, &username_param, &password_param, &options, &attributes);

	if (!username_param) {
		ZEPHIR_INIT_VAR(username);
		ZVAL_EMPTY_STRING(username);
	} else {
	if (unlikely(Z_TYPE_P(username_param) != IS_STRING && Z_TYPE_P(username_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'username' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(username_param) == IS_STRING)) {
		username = username_param;
	} else {
		ZEPHIR_INIT_VAR(username);
		ZVAL_EMPTY_STRING(username);
	}
	}
	if (!password_param) {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	} else {
	if (unlikely(Z_TYPE_P(password_param) != IS_STRING && Z_TYPE_P(password_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'password' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(password_param) == IS_STRING)) {
		password = password_param;
	} else {
		ZEPHIR_INIT_VAR(password);
		ZVAL_EMPTY_STRING(password);
	}
	}
	if (!options) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}
	if (!attributes) {
		ZEPHIR_INIT_VAR(attributes);
		array_init(attributes);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("attributes"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 3);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2);
	zephir_update_property_array(this_ptr, SL("attributes"), _1, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 20);
	zephir_update_property_array(this_ptr, SL("attributes"), _3, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 8);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 2);
	zephir_update_property_array(this_ptr, SL("attributes"), _4, _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_STRING(_6, "", 1);
	zephir_update_property_this(this_ptr, SL("dsn"), _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	array_init(_7);
	zephir_update_property_this(this_ptr, SL("profile"), _7 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("username"), username TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("password"), password TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("attributes"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_8, "array_replace", &_9, _6, attributes);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("attributes"), _8 TSRMLS_CC);
	if (Z_TYPE_P(dsn) == IS_STRING) {
		zephir_update_property_this(this_ptr, SL("dsn"), dsn TSRMLS_CC);
	} else {
		if (zephir_instance_of_ev(dsn, php_pdo_get_dbh_ce() TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("pdo"), dsn TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "$dsn must be string or PDO", "pdm/db/pdo.zep", 121);
			return;
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Begins a transaction and turns off autocommit mode.
 *
 * @return bool True on success, false on failure.
 * @see http://php.net/manual/en/pdo.begintransaction.php
 */
PHP_METHOD(Pdm_Db_Pdo, beginTransaction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "beginTransaction", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _1, "begintransaction",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Commits the existing transaction and restores autocommit mode.
 *
 * @return bool True on success, false on failure.
 * @see http://php.net/manual/en/pdo.commit.php
 */
PHP_METHOD(Pdm_Db_Pdo, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "commit", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _1, "commit",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Connects to the database and sets PDO attributes.
 *
 * @return null
 * @throws PDOException if the connection fails.
 */
PHP_METHOD(Pdm_Db_Pdo, connect) {

	zephir_fcall_cache_entry *_11 = NULL;
	HashTable *_9;
	HashPosition _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *attribute = NULL, *value = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, **_10;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) != IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "connect", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, php_pdo_get_dbh_ce());
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("dsn"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("username"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("password"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3, _4, _5, _6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pdo"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("attributes"), PH_NOISY_CC);
	zephir_is_iterable(_7, &_9, &_8, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HMKEY(attribute, _9, _8);
		ZEPHIR_GET_HVALUE(value, _10);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setattribute", &_11, attribute, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the most recent error code.
 *
 * @return mixed
 */
PHP_METHOD(Pdm_Db_Pdo, errorCode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "errorcode", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the most recent error info.
 *
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, errorInfo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "errorinfo", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes an SQL statement and returns the number of affected rows.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @return int The number of affected rows.
 * @see http://php.net/manual/en/pdo.exec.php
 */
PHP_METHOD(Pdm_Db_Pdo, exec) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *affectedRows = NULL, *_0, *_1 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &statement_param);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "exec", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&affectedRows, _1, "exec", NULL, statement);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL, statement);
	zephir_check_call_status();
	RETURN_CCTOR(affectedRows);

}

/**
 * Performs a statement and returns the number of affected rows.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @return int
 */
PHP_METHOD(Pdm_Db_Pdo, fetchAffected) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *sth = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(sth, "rowcount", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetches a sequential array of rows from the database; the rows
 * are returned as associative arrays.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @param callable $callback A callable to be applied to each of the rows
 * to be returned.
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *callback = NULL, *_0;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement_param, &values, &callback);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchallwithcallable", NULL, _0, statement, values, callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetch array using a callable
 * @param int $fetchType
 * @param string $statement
 * @param array $values
 * @param callable $callback
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchAllWithCallable) {

	int ZEPHIR_LAST_CALL_STATUS, _0;
	zval *statement = NULL;
	zval *fetchType = NULL, *statement_param = NULL, *values = NULL, *callback = NULL, *sth = NULL, *data = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &fetchType, &statement_param, &values, &callback);

	ZEPHIR_SEPARATE_PARAM(fetchType);
	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	if (Z_TYPE_P(fetchType) != IS_LONG) {
		_0 = zephir_get_intval(fetchType);
		ZEPHIR_INIT_NVAR(fetchType);
		ZVAL_LONG(fetchType, _0);
	}
	if (ZEPHIR_IS_LONG(fetchType, 7)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, 0);
		ZEPHIR_CALL_METHOD(&data, sth, "fetchall", NULL, fetchType, _1);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&data, sth, "fetchall", NULL, fetchType);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "applycallabletofetchall", NULL, callback, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pdm_Db_Pdo, applyCallableToFetchAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *callback, *data, *key = NULL, *row = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &callback, &data);

	ZEPHIR_SEPARATE_PARAM(data);


	if (Z_TYPE_P(callback) == IS_OBJECT) {
		zephir_is_iterable(data, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(row, _2);
			ZEPHIR_CALL_FUNCTION(&_3, "call_user_func", &_4, callback, row);
			zephir_check_call_status();
			zephir_array_update_zval(&data, key, &_3, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

/**
 * Fetches an associative array of rows from the database; the rows
 * are returned as associative arrays, and the array of rows is keyed
 * on the first column of each row.
 *
 * N.b.: If multiple rows have the same first column value, the last
 * row with that value will override earlier rows.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @param callable $callback A callable to be applied to each of the rows
 * to be returned.
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchAssoc) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *callback = NULL, *sth = NULL, *data, *row = NULL, *key = NULL, *_0 = NULL, *_2 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement_param, &values, &callback);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	while (1) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 2);
		ZEPHIR_CALL_METHOD(&row, sth, "fetch", NULL, _0);
		zephir_check_call_status();
		if (!(zephir_is_true(row))) {
			break;
		}
		Z_SET_ISREF_P(row);
		ZEPHIR_CALL_FUNCTION(&key, "current", &_1, row);
		Z_UNSET_ISREF_P(row);
		zephir_check_call_status();
		if (Z_TYPE_P(callback) == IS_NULL) {
			zephir_array_update_zval(&data, key, &row, PH_COPY | PH_SEPARATE);
		} else {
			if (Z_TYPE_P(callback) != IS_NULL) {
				ZEPHIR_CALL_FUNCTION(&_2, "call_user_func", &_3, callback, row);
				zephir_check_call_status();
				zephir_array_update_zval(&data, key, &_2, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&data, key, &row, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(data);

}

/**
 * Fetches the first column of rows as a sequential array.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @param callable $callback A callable to be applied to each of the rows
 * to be returned.
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchCol) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *callback = NULL, *_0;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement_param, &values, &callback);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 7);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "fetchallwithcallable", NULL, _0, statement, values, callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetches one row from the database as an object where the column values
 * are mapped to object properties.
 *
 * Warning: PDO "injects property-values BEFORE invoking the constructor -
 * in other words, if your class initializes property-values to defaults
 * in the constructor, you will be overwriting the values injected by
 * fetchObject() !"
 * <http://www.php.net/manual/en/pdostatement.fetchobject.php#111744>
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @param string $className The name of the class to create.
 * @param array $ctor_args Arguments to pass to the object constructor.
 * @return object
 */
PHP_METHOD(Pdm_Db_Pdo, fetchObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *className_param = NULL, *ctor_args = NULL, *sth = NULL;
	zval *statement = NULL, *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &statement_param, &values, &className_param, &ctor_args);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!className_param) {
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "StdClass", 1);
	} else {
	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(className_param) == IS_STRING)) {
		className = className_param;
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}
	}
	if (!ctor_args) {
		ZEPHIR_INIT_VAR(ctor_args);
		array_init(ctor_args);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(sth, "fetchobject", NULL, className, ctor_args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetches a sequential array of rows from the database; the rows
 * are returned as objects where the column values are mapped to
 * object properties.
 *
 * Warning: PDO "injects property-values BEFORE invoking the constructor -
 * in other words, if your class initializes property-values to defaults
 * in the constructor, you will be overwriting the values injected by
 * fetchObject() !"
 * <http://www.php.net/manual/en/pdostatement.fetchobject.php#111744>
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @param string $className The name of the class to create from each
 * row.
 * @param array $ctor_args Arguments to pass to each object constructor.
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchObjects) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *className_param = NULL, *ctor_args = NULL, *sth = NULL, *_0;
	zval *statement = NULL, *className = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &statement_param, &values, &className_param, &ctor_args);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!className_param) {
		ZEPHIR_INIT_VAR(className);
		ZVAL_STRING(className, "StdClass", 1);
	} else {
	if (unlikely(Z_TYPE_P(className_param) != IS_STRING && Z_TYPE_P(className_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'className' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(className_param) == IS_STRING)) {
		className = className_param;
	} else {
		ZEPHIR_INIT_VAR(className);
		ZVAL_EMPTY_STRING(className);
	}
	}
	if (!ctor_args) {
		ZEPHIR_INIT_VAR(ctor_args);
		array_init(ctor_args);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 8);
	ZEPHIR_RETURN_CALL_METHOD(sth, "fetchall", NULL, _0, className, ctor_args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetches one row from the database as an associative array.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *values = NULL, *sth = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement, &values);

	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 2);
	ZEPHIR_RETURN_CALL_METHOD(sth, "fetch", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetches an associative array of rows as key-value pairs (first
 * column is the key, second column is the value).
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param callable $callback A callable to be applied to each of the rows
 * to be returned.
 * @param array $values Values to bind to the query.
 * @return array
 */
PHP_METHOD(Pdm_Db_Pdo, fetchPairs) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *callback = NULL, *sth = NULL, *data = NULL, *row = NULL, *_0 = NULL, *_1 = NULL, *_3, *_4 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement_param, &values, &callback);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}
	if (!callback) {
		callback = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	if (Z_TYPE_P(callback) != IS_NULL) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
		while (1) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_LONG(_0, 3);
			ZEPHIR_CALL_METHOD(&row, sth, "fetch", NULL, _0);
			zephir_check_call_status();
			if (!(zephir_is_true(row))) {
				break;
			}
			if (Z_TYPE_P(callback) != IS_NULL) {
				ZEPHIR_CALL_FUNCTION(&_1, "call_user_func", &_2, callback, row);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(row, _1);
			}
			zephir_array_fetch_long(&_3, row, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_OBS_NVAR(_4);
			zephir_array_fetch_long(&_4, row, 0, PH_NOISY TSRMLS_CC);
			zephir_array_update_zval(&data, _4, &_3, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 12);
		ZEPHIR_CALL_METHOD(&data, sth, "fetchall", NULL, _0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(data);

}

/**
 * Fetches the very first value (i.e., first column of the first row).
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param array $values Values to bind to the query.
 * @return mixed
 */
PHP_METHOD(Pdm_Db_Pdo, fetchValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *sth = NULL, *_0;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "perform", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(sth, "fetchcolumn", NULL, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a PDO attribute value.
 *
 * @param mixed $attribute The PDO::ATTR_* constant.
 * @return mixed The value for the attribute.
 */
PHP_METHOD(Pdm_Db_Pdo, getAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attribute, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "getattribute", NULL, attribute);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DSN for a lazy connection; if the underlying PDO instance
 * was injected at construction time, this will be null.
 *
 * @return string|null
 */
PHP_METHOD(Pdm_Db_Pdo, getDsn) {


	RETURN_MEMBER(this_ptr, "dsn");

}

/**
 * Returns the underlying PDO connection object.
 *
 * @return PDO
 */
PHP_METHOD(Pdm_Db_Pdo, getPdo) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "connect", NULL);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MM_MEMBER(this_ptr, "pdo");
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid PDO", "pdm/db/pdo.zep", 514);
	return;

}

/**
 * Returns the profiler object.
 *
 * @return ProfilerInterface
 */
PHP_METHOD(Pdm_Db_Pdo, getProfiler) {


	RETURN_MEMBER(this_ptr, "profiler");

}

/**
 * Is a transaction currently active?
 *
 * @return bool
 * @see http://php.net/manual/en/pdo.intransaction.php
 */
PHP_METHOD(Pdm_Db_Pdo, inTransaction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "inTransaction", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _1, "intransaction",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Is this instance connected to a database?
 *
 * @return bool
 */
PHP_METHOD(Pdm_Db_Pdo, isConnected) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("pdo"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_OBJECT);

}

/**
 * Returns the last inserted autoincrement sequence value.
 *
 * @param string $name The name of the sequence to check; typically needed
 * only for PostgreSQL, where it takes the form of `<table>_<column>_seq`.
 * @return int
 * @see http://php.net/manual/en/pdo.lastinsertid.php
 */
PHP_METHOD(Pdm_Db_Pdo, lastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *result = NULL, *_0, *_1 = NULL;
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
	ZVAL_STRING(_0, "lastInsertId", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _1, "lastinsertid", NULL, name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Performs a query with bound values and returns the resulting
 * PDOStatement; array values will be passed through `quote()` and their
 * respective placeholders will be replaced in the query string.
 *
 * @param string $statement The SQL statement to perform.
 * @param array $values Values to bind to the query
 * @return PDOStatement
 * @see quote()
 */
PHP_METHOD(Pdm_Db_Pdo, perform) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *sth = NULL, *_0;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}


	ZEPHIR_CALL_METHOD(&sth, this_ptr, "preparewithvalues", NULL, statement, values);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "perform", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, sth, "execute", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL, statement, values);
	zephir_check_call_status();
	RETURN_CCTOR(sth);

}

/**
 * Prepares an SQL statement for execution.
 *
 * @param string $statement The SQL statement to prepare for execution.
 * @param array $options Set these attributes on the returned
 * PDOStatement.
 * @return PDOStatement
 * @see http://php.net/manual/en/pdo.prepare.php
 */
PHP_METHOD(Pdm_Db_Pdo, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *options = NULL, *_0 = NULL;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &options);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "prepare", NULL, statement, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Queries the database and returns a PDOStatement.
 *
 * @param string $statement The SQL statement to prepare and execute.
 * @param int $fetch_mode The `PDO::FETCH_*` type to set on the returned
 * `PDOStatement::setFetchMode()`.
 * @param mixed $fetch_arg1 The first additional argument to send to
 * `PDOStatement::setFetchMode()`.
 * @param mixed $fetch_arg2 The second additional argument to send to
 * `PDOStatement::setFetchMode()`.
 * @return PDOStatement
 * @see http://php.net/manual/en/pdo.query.php
 */
PHP_METHOD(Pdm_Db_Pdo, query) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *fetch_mode = NULL, *fetch_arg1 = NULL, *fetch_arg2 = NULL, *sth, *pdo = NULL, *_0, *_1, *_3 = NULL, *_5;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &statement_param, &fetch_mode, &fetch_arg1, &fetch_arg2);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!fetch_mode) {
		fetch_mode = ZEPHIR_GLOBAL(global_null);
	}
	if (!fetch_arg1) {
		fetch_arg1 = ZEPHIR_GLOBAL(global_null);
	}
	if (!fetch_arg2) {
		fetch_arg2 = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, statement TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_0, "string")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "$statement must be a string", "pdm/db/pdo.zep", 637);
		return;
	}
	ZEPHIR_CALL_METHOD(&pdo, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "query", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sth);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 3);
	zephir_array_fast_append(_2, pdo);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, "query", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(&_3, "func_get_args", &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(sth, _2, _3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, sth, SL("queryString"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL, _5);
	zephir_check_call_status();
	RETURN_CCTOR(sth);

}

/**
 * Quotes a value for use in an SQL statement.
 *
 * This differs from `PDO::quote()` in that it will convert an array into
 * a string of comma-separated quoted values.
 *
 * @param mixed $value The value to quote.
 * @param int $parameterType A data type hint for the database driver.
 * @return mixed The quoted value.
 * @see http://php.net/manual/en/pdo.quote.php
 */
PHP_METHOD(Pdm_Db_Pdo, quote) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS, _0;
	zval *value, *parameterType = NULL, *k = NULL, *v = NULL, *pdo = NULL, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &parameterType);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!parameterType) {
		ZEPHIR_INIT_VAR(parameterType);
		ZVAL_LONG(parameterType, 2);
	} else {
		ZEPHIR_SEPARATE_PARAM(parameterType);
	}


	ZEPHIR_CALL_METHOD(&pdo, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	_0 = zephir_get_intval(parameterType);
	ZEPHIR_INIT_BNVAR(parameterType);
	ZVAL_LONG(parameterType, _0);
	if (Z_TYPE_P(value) != IS_ARRAY) {
		ZEPHIR_RETURN_CALL_METHOD(pdo, "quote", NULL, value, parameterType);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_is_iterable(value, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_CALL_METHOD(&_4, pdo, "quote", &_5, v, parameterType);
		zephir_check_call_status();
		zephir_array_update_zval(&value, k, &_4, PH_COPY | PH_SEPARATE);
	}
	zephir_fast_join_str(return_value, SL(", "), value TSRMLS_CC);
	RETURN_MM();

}

/**
 * Rolls back the current transaction, and restores autocommit mode.
 *
 * @return bool True on success, false on failure.
 * @see http://php.net/manual/en/pdo.rollback.php
 */
PHP_METHOD(Pdm_Db_Pdo, rollBack) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "rollBack", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "beginprofile", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getpdo",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _1, "rollback",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "endprofile", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(result);

}

/**
 * Sets a PDO attribute value.
 *
 * @param mixed $attribute The PDO::ATTR_* constant.
 * @param mixed $value The value for the attribute.
 * @return bool True on success, false on failure. Note that if PDO has not
 * not connected, all calls will be treated as successful.
 */
PHP_METHOD(Pdm_Db_Pdo, setAttribute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attribute, *value, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_1, "setattribute", NULL, attribute, value);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_update_property_array(this_ptr, SL("attributes"), attribute, value TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * Sets the profiler object.
 *
 * @param ProfilerInterface $profiler
 * @return void
 */
PHP_METHOD(Pdm_Db_Pdo, setProfiler) {

	zval *profiler;

	zephir_fetch_params(0, 1, 0, &profiler);



	if (!(zephir_instance_of_ev(profiler, pdm_db_profilerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'profiler' must be an instance of 'Pdm\\Db\\ProfilerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("profiler"), profiler TSRMLS_CC);

}

/**
 * Begins a profile entry.
 *
 * @param string $functionName The function starting the profile entry.
 * @return void
 */
PHP_METHOD(Pdm_Db_Pdo, beginProfile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *functionName_param = NULL, *_0, *_1 = NULL, *_3, *_4;
	zval *functionName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &functionName_param);

	if (unlikely(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(functionName_param) == IS_STRING)) {
		functionName = functionName_param;
	} else {
		ZEPHIR_INIT_VAR(functionName);
		ZVAL_EMPTY_STRING(functionName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("profiler"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "microtime", &_2, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "time", 1);
	zephir_update_property_array(this_ptr, SL("profile"), _3, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "function", 1);
	zephir_update_property_array(this_ptr, SL("profile"), _4, functionName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Ends and records a profile entry.
 *
 * @param string $statement The statement being profiled, if any.
 * @param array values
 * @return void
 */
PHP_METHOD(Pdm_Db_Pdo, endProfile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *statement_param = NULL, *values = NULL, *_0, *_1, *_2 = NULL, *_4, *_5, *_6, *_7, *_8;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &statement_param, &values);

	if (!statement_param) {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_STRING(statement, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("profiler"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("profiler"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_2, "microtime", &_3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("profile"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _4, SL("time"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6);
		zephir_sub_function(_6, _2, _5 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("profile"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _7, SL("function"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "addprofile", NULL, _6, _5, statement, values);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_8);
	array_init(_8);
	zephir_update_property_this(this_ptr, SL("profile"), _8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Prepares an SQL statement with bound values.
 *
 * This method only binds values that have placeholders in the
 * statement, thereby avoiding errors from PDO regarding too many bound
 * values. It also binds all sequential (question-mark) placeholders.
 *
 * If a placeholder value is an array, the array is converted to a string
 * of comma-separated quoted values; e.g., for an `IN (...)` condition.
 * The quoted string is replaced directly into the statement instead of
 * using `PDOStatement::bindValue()` proper.
 *
 * @param string $statement The SQL statement to prepare for execution.
 * @return PDOStatement
 * @see http://php.net/manual/en/pdo.prepare.php
 */
PHP_METHOD(Pdm_Db_Pdo, prepareWithValues) {

	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *rebuild = NULL, *key = NULL, *value = NULL, *sth = NULL, *_0, *_1, *_2, **_5;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &statement_param, &values);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	if (!values) {
		ZEPHIR_INIT_VAR(values);
		array_init(values);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_gettype(_0, statement TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_0, "string")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "$statment must be a string", "pdm/db/pdo.zep", 799);
		return;
	}
	if (Z_TYPE_P(values) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "$values must be array", "pdm/db/pdo.zep", 803);
		return;
	}
	if (ZEPHIR_IS_EMPTY(values)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "prepare", NULL, statement);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&rebuild, this_ptr, "rebuild", NULL, statement, values);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, rebuild, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&sth, this_ptr, "prepare", NULL, _1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, rebuild, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HMKEY(key, _4, _3);
		ZEPHIR_GET_HVALUE(value, _5);
		ZEPHIR_CALL_METHOD(NULL, sth, "bindvalue", NULL, key, value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(sth);

}

/**
 * Returns a new anonymous object to track bind values.
 *
 * @param array $values The values to bind and/or replace into a statement.
 * @return mixed
 */
PHP_METHOD(Pdm_Db_Pdo, newBindTracker) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values);

	ZEPHIR_SEPARATE_PARAM(values);


	if (Z_TYPE_P(values) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(values);
		array_init(values);
	}
	object_init_ex(return_value, pdm_db_bindtracker_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, values);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rebuilds a statement with array values replaced into placeholders.
 *
 * @param string $statement The statement to rebuild.
 * @param array $values The values to bind and/or replace into a statement.
 * @return array An array where element 0 is the rebuilt statement and
 * element 1 is the rebuilt array of values.
 */
PHP_METHOD(Pdm_Db_Pdo, rebuild) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *values = NULL, *bind = NULL, *_0 = NULL, *_1;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &values);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}
	ZEPHIR_SEPARATE_PARAM(statement);
	ZEPHIR_SEPARATE_PARAM(values);


	if (Z_TYPE_P(values) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(values);
		array_init(values);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "newbindtracker", NULL, values);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(bind, _0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "rebuildstatement", NULL, statement, bind);
	zephir_check_call_status();
	zephir_get_strval(statement, _0);
	array_init_size(return_value, 3);
	zephir_array_fast_append(return_value, statement);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, bind, SL("finalValues"), PH_NOISY_CC);
	zephir_array_fast_append(return_value, _1);
	RETURN_MM();

}

PHP_METHOD(Pdm_Db_Pdo, rebuildStatement) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *statement_param = NULL, *bind, *apos, *quot, *regex, *parts = NULL, _0, _1;
	zval *statement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &statement_param, &bind);

	if (unlikely(Z_TYPE_P(statement_param) != IS_STRING && Z_TYPE_P(statement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'statement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(statement_param) == IS_STRING)) {
		statement = statement_param;
	} else {
		ZEPHIR_INIT_VAR(statement);
		ZVAL_EMPTY_STRING(statement);
	}


	if (!(zephir_instance_of_ev(bind, pdm_db_bindtracker_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bind' must be an instance of 'Pdm\\Db\\BindTracker'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(apos);
	ZVAL_STRING(apos, "'", 1);
	ZEPHIR_INIT_VAR(quot);
	ZVAL_STRING(quot, "\"", 1);
	ZEPHIR_INIT_VAR(regex);
	ZEPHIR_CONCAT_SVSVSVSVS(regex, "/((", apos, "+|", quot, "+|\\", apos, "+|\\", quot, "+).*?)\\2/m");
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -1);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", &_2, regex, statement, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rebuildparts", NULL, parts, bind);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pdm_Db_Pdo, rebuildParts) {

	zephir_fcall_cache_entry *_2 = NULL;
	int i, ZEPHIR_LAST_CALL_STATUS;
	zval *parts, *bind, *k, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &parts, &bind);

	ZEPHIR_SEPARATE_PARAM(parts);


	if (!(zephir_instance_of_ev(bind, pdm_db_bindtracker_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bind' must be an instance of 'Pdm\\Db\\BindTracker'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(k);
	ZVAL_LONG(k, zephir_fast_count_int(parts TSRMLS_CC));
	i = 0;
	while (1) {
		if (!(ZEPHIR_GE_LONG(k, i))) {
			break;
		}
		zephir_array_fetch_long(&_1, parts, i, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "rebuildpart", &_2, _1, bind);
		zephir_check_call_status();
		zephir_array_update_long(&parts, i, &_0, PH_COPY | PH_SEPARATE, "pdm/db/pdo.zep", 890);
		i += 3;
	}
	zephir_fast_join_str(return_value, SL(""), parts TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Pdm_Db_Pdo, rebuildPart) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *part, *bind, *subs = NULL, *regex, _0, _1, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &part, &bind);



	if (!(zephir_instance_of_ev(bind, pdm_db_bindtracker_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bind' must be an instance of 'Pdm\\Db\\BindTracker'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(regex);
	ZVAL_STRING(regex, "/(:[a-zA-Z_][a-zA-Z0-9_]*)|(\?)/m", 1);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, -1);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&subs, "preg_split", &_2, regex, part, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparevalueplaceholders", NULL, subs, bind);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(subs, _3);
	zephir_fast_join_str(return_value, SL(""), subs TSRMLS_CC);
	RETURN_MM();

}

/**
 * Prepares the sub-parts of a query with placeholders.
 *
 * @param array $subs The query subparts.
 * @param BindTracker $bind The preparation info object.
 * @return array The prepared subparts.
 */
PHP_METHOD(Pdm_Db_Pdo, prepareValuePlaceholders) {

	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *subs, *bind, *character = NULL, *i = NULL, *sub = NULL, **_2, _3 = zval_used_for_init, _4 = zval_used_for_init, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &subs, &bind);

	ZEPHIR_SEPARATE_PARAM(subs);


	if (!(zephir_instance_of_ev(bind, pdm_db_bindtracker_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bind' must be an instance of 'Pdm\\Db\\BindTracker'", "", 0);
		return;
	}
	zephir_is_iterable(subs, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(i, _1, _0);
		ZEPHIR_GET_HVALUE(sub, _2);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 0);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 1);
		ZEPHIR_CALL_FUNCTION(&character, "substr", &_5, sub, &_3, &_4);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(character, "?")) {
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "preparenumberedplaceholder", &_7, sub, bind);
			zephir_check_call_status();
			zephir_array_update_zval(&subs, i, &_6, PH_COPY | PH_SEPARATE);
		}
		if (ZEPHIR_IS_STRING(character, ":")) {
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "preparenamedplaceholder", &_8, sub, bind);
			zephir_check_call_status();
			zephir_array_update_zval(&subs, i, &_6, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(subs);

}

/**
 * Bind or quote a numbered placeholder in a query subpart.
 *
 * @param string $sub The query subpart.
 * @param BindTracker $bind The preparation info object.
 * @return string The prepared query subpart.
 */
PHP_METHOD(Pdm_Db_Pdo, prepareNumberedPlaceholder) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool bindArray;
	zval *sub = NULL, *bind, *values = NULL, *finalValues = NULL, *_0, *_1, *_2, *_3 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sub, &bind);

	ZEPHIR_SEPARATE_PARAM(sub);


	if (!(zephir_instance_of_ev(bind, pdm_db_bindtracker_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bind' must be an instance of 'Pdm\\Db\\BindTracker'", "", 0);
		return;
	}
	if (Z_TYPE_P(sub) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "$sub must be a string", "pdm/db/pdo.zep", 956);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, bind, SL("num"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, (zephir_get_numberval(_0) + 1));
	ZEPHIR_CALL_METHOD(NULL, bind, "setnum", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, bind, SL("values"), PH_NOISY_CC);
	if (zephir_array_isset_long(_2, 0)) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, bind, SL("values"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(values, _3);
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_LONG(_1, 0);
		Z_SET_ISREF_P(values);
		ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", &_4, values, _1);
		Z_UNSET_ISREF_P(values);
		zephir_check_call_status();
		zephir_array_unset_long(&values, 0, PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, bind, "setvalues", NULL, values);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(_3);
	zephir_read_property(&_3, bind, SL("values"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, bind, SL("num"), PH_NOISY_CC);
	if (zephir_array_isset(_3, _5)) {
		ZEPHIR_OBS_VAR(_6);
		zephir_read_property(&_6, bind, SL("values"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_7);
		ZEPHIR_OBS_VAR(_8);
		zephir_read_property(&_8, bind, SL("num"), PH_NOISY_CC);
		zephir_array_fetch(&_7, _6, _8, PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(_7) == IS_ARRAY) {
			bindArray = 1;
		} else {
			bindArray = 0;
		}
	} else {
		bindArray = 0;
	}
	if (bindArray) {
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, bind, SL("values"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, bind, SL("num"), PH_NOISY_CC);
		zephir_array_fetch(&_9, _3, _6, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&sub, this_ptr, "quote", NULL, _9);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, bind, SL("count"), PH_NOISY_CC);
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_LONG(_1, (zephir_get_numberval(_3) + 1));
		ZEPHIR_CALL_METHOD(NULL, bind, "setcount", NULL, _1);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, bind, SL("finalValues"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(finalValues, _6);
		ZEPHIR_OBS_NVAR(_6);
		zephir_read_property(&_6, bind, SL("values"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_7);
		zephir_read_property(&_7, bind, SL("num"), PH_NOISY_CC);
		zephir_array_fetch(&_9, _6, _7, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_8);
		zephir_read_property(&_8, bind, SL("count"), PH_NOISY_CC);
		zephir_array_update_zval(&finalValues, _8, &_9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, bind, "setfinalvalues", NULL, finalValues);
		zephir_check_call_status();
	}
	RETURN_CCTOR(sub);

}

/**
 * Bind or quote a named placeholder in a query subpart.
 *
 * @param string $sub The query subpart.
 * @param BindTracker $bind The preparation info object.
 * @return string The prepared query subpart.
 */
PHP_METHOD(Pdm_Db_Pdo, prepareNamedPlaceholder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zend_bool bindArray;
	zval *sub = NULL, *bind, *name = NULL, *finalValues = NULL, _0, *_2, *_3 = NULL, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sub, &bind);

	ZEPHIR_SEPARATE_PARAM(sub);


	if (!(zephir_instance_of_ev(bind, pdm_db_bindtracker_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bind' must be an instance of 'Pdm\\Db\\BindTracker'", "", 0);
		return;
	}
	if (Z_TYPE_P(sub) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "$sub must be a string", "pdm/db/pdo.zep", 1007);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&name, "substr", &_1, sub, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, bind, SL("values"), PH_NOISY_CC);
	if (zephir_array_isset(_2, name)) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, bind, SL("values"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_4);
		zephir_array_fetch(&_4, _3, name, PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(_4) == IS_ARRAY) {
			bindArray = 1;
		}
	} else {
		bindArray = 0;
	}
	if (bindArray) {
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, bind, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_5, _3, name, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&sub, this_ptr, "quote", NULL, _5);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, bind, SL("finalValues"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(finalValues, _3);
		ZEPHIR_OBS_NVAR(_3);
		zephir_read_property(&_3, bind, SL("values"), PH_NOISY_CC);
		zephir_array_fetch(&_5, _3, name, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_update_zval(&finalValues, name, &_5, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, bind, "setfinalvalues", NULL, finalValues);
		zephir_check_call_status();
	}
	RETURN_CCTOR(sub);

}

