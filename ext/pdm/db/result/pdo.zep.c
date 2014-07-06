
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"

#include <ext/pdo/php_pdo_driver.h>



/**
 * Pdm\Db\Result\Pdo
 *
 * Encapsulates the resultset internals
 *
 * <code>
 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(PDO::FETCH_NUM);
 *	while ($robot = $result->fetchArray()) {
 *		print_r($robot);
 *	}
 * </code>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Result_Pdo) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db\\Result, Pdo, pdm, db_result_pdo, pdm_db_result_pdo_method_entry, 0);

	/**
	 * @var \Pdm\Db\AdapterInterface
	 */
	zend_declare_property_null(pdm_db_result_pdo_ce, SL("adapter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active fetch mode
	 * @var int
	 */
	zend_declare_property_null(pdm_db_result_pdo_ce, SL("fetchMode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Internal resultset
	 *
	 * @var \PDOStatement
	 */
	zend_declare_property_null(pdm_db_result_pdo_ce, SL("pdoStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * SQL statement
	 * @var string
	 */
	zend_declare_property_null(pdm_db_result_pdo_ce, SL("sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Bound parameters array
	 * @var array
	 */
	zend_declare_property_null(pdm_db_result_pdo_ce, SL("bindParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(pdm_db_result_pdo_ce, SL("bindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(pdm_db_result_pdo_ce, SL("rowCount"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_result_pdo_ce TSRMLS_CC, 1, pdm_db_resultinterface_ce);
	return SUCCESS;

}

/**
 * Active fetch mode
 * @var int
 */
PHP_METHOD(Pdm_Db_Result_Pdo, getFetchMode) {


	RETURN_MEMBER(this_ptr, "fetchMode");

}

/**
 * SQL statement
 * @var string
 */
PHP_METHOD(Pdm_Db_Result_Pdo, getSqlStatement) {


	RETURN_MEMBER(this_ptr, "sqlStatement");

}

/**
 * Pdm\Db\Result\Pdo constructor
 *
 * @param Pdm\Db\AdapterInterface adapter
 * @param \PDOStatement pdoStatement
 * @param string sqlStatement
 * @param array bindParams
 * @param array bindTypes
 */
PHP_METHOD(Pdm_Db_Result_Pdo, __construct) {

	zval *sqlStatement = NULL;
	zval *adapter, *pdoStatement, *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &adapter, &pdoStatement, &sqlStatement_param, &bindParams, &bindTypes);

	if (!sqlStatement_param) {
		ZEPHIR_INIT_VAR(sqlStatement);
		ZVAL_EMPTY_STRING(sqlStatement);
	} else {
	if (unlikely(Z_TYPE_P(sqlStatement_param) != IS_STRING && Z_TYPE_P(sqlStatement_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlStatement' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sqlStatement_param) == IS_STRING)) {
		sqlStatement = sqlStatement_param;
	} else {
		ZEPHIR_INIT_VAR(sqlStatement);
		ZVAL_EMPTY_STRING(sqlStatement);
	}
	}
	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	}


	if (!(zephir_instance_of_ev(adapter, pdm_db_adapterinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'adapter' must be an instance of 'Pdm\\Db\\AdapterInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(pdoStatement, zephir_get_internal_ce(SS("pdostatement") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'pdoStatement' must be an instance of 'PDOStatement'", "", 0);
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 4);
	zephir_update_property_this(this_ptr, SL("fetchMode"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("rowCount"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("adapter"), adapter TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("pdoStatement"), pdoStatement TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_gettype(_1, sqlStatement TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "null")) {
		zephir_update_property_this(this_ptr, SL("sqlStatement"), sqlStatement TSRMLS_CC);
	}
	if (Z_TYPE_P(bindParams) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("bindParams"), bindParams TSRMLS_CC);
	}
	if (Z_TYPE_P(bindTypes) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("bindTypes"), bindTypes TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Allows to execute the statement again. Some database systems don't support scrollable cursors,
 * So, as cursors are forward only, we need to execute the cursor again to fetch rows from the begining
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Result_Pdo, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinternalresult",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "execute", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fetches an array/object of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(PDO::FETCH_OBJ);
 *	while ($robot = $result->fetch()) {
 *		echo robot->name;
 *	}
 *</code>
 *
 * @return mixed
 */
PHP_METHOD(Pdm_Db_Result_Pdo, fetch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinternalresult",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetch", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an array of strings that corresponds to the fetched row, or FALSE if there are no more rows.
 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
 *	$result->setFetchMode(PDO::FETCH_NUM);
 *	while ($robot = result->fetchArray()) {
 *		print_r($robot);
 *	}
 *</code>
 *
 * @return array | bool
 */
PHP_METHOD(Pdm_Db_Result_Pdo, fetchArray) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinternalresult",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetch", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns an array of arrays containing all the records in the result
 * This method is affected by the active fetch flag set using Pdm\Db\Result\Pdo::setFetchMode
 *
 *<code>
 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
 *	$robots = $result->fetchAll();
 *</code>
 *
 * @return array
 */
PHP_METHOD(Pdm_Db_Result_Pdo, fetchAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getinternalresult",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetchall", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets number of rows returned by a resulset
 *
 *<code>
 *	$result = $adapter->query("SELECT * FROM robots ORDER BY name");
 *	echo 'There are ', $result->numRows(), ' rows in the resulset';
 *</code>
 *
 * @return int
 */
PHP_METHOD(Pdm_Db_Result_Pdo, numRows) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement = NULL, *rowCount = NULL, *adapter = NULL, *type = NULL, *pdoStatement = NULL, *matches, *result = NULL, *row = NULL, *_0, *_2, *_3 = NULL, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rowCount"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(rowCount, _0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(rowCount)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("adapter"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(adapter, _0);
		ZEPHIR_CALL_METHOD(&type, adapter, "gettype",  NULL);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_STRING(type, "pgsql");
		if (!(_1)) {
			_1 = ZEPHIR_IS_STRING(type, "mysql");
		}
		if (_1) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdoStatement"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(pdoStatement, _0);
			ZEPHIR_CALL_METHOD(&rowCount, pdoStatement, "rowcount",  NULL);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(rowCount)) {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("sqlStatement"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(sqlStatement, _0);
			if (!(zephir_start_with_str(sqlStatement, SL("SELECT COUNT(*) ")))) {
				ZEPHIR_INIT_VAR(matches);
				ZVAL_NULL(matches);
				ZEPHIR_INIT_VAR(_2);
				ZVAL_STRING(_2, "/^SELECT\\s+(.*)/i", 0);
				Z_SET_ISREF_P(matches);
				ZEPHIR_CALL_FUNCTION(&_3, "preg_match", &_4, _2, sqlStatement, matches);
				zephir_check_temp_parameter(_2);
				Z_UNSET_ISREF_P(matches);
				zephir_check_call_status();
				if (zephir_is_true(_3)) {
					zephir_array_fetch_long(&_5, matches, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
					ZEPHIR_INIT_VAR(_6);
					ZEPHIR_CONCAT_SVS(_6, "SELECT COUNT(*) \"numrows\" FROM (SELECT ", _5, ")");
					_0 = zephir_fetch_nproperty_this(this_ptr, SL("bindParams"), PH_NOISY_CC);
					_7 = zephir_fetch_nproperty_this(this_ptr, SL("bindTypes"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(&result, adapter, "query", NULL, _6, _0, _7);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&row, result, "fetch",  NULL);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(rowCount);
					zephir_array_fetch_string(&rowCount, row, SL("numrows"), PH_NOISY TSRMLS_CC);
				}
			} else {
				ZEPHIR_INIT_NVAR(rowCount);
				ZVAL_LONG(rowCount, 1);
			}
		}
		zephir_update_property_this(this_ptr, SL("rowCount"), rowCount TSRMLS_CC);
	}
	RETURN_CCTOR(rowCount);

}

/**
 * Changes the fetching mode affecting Pdm\Db\Result\Pdo::fetch()
 *
 *<code>
 *	//Return array with integer indexes
 *	$result->setFetchMode(PDO::FETCH_NUM);
 *
 *	//Return associative array without integer indexes
 *	$result->setFetchMode(PDO::FETCH_ASSOC);
 *
 *	//Return associative array together with integer indexes
 *	$result->setFetchMode(PDO::FETCH_BOTH);
 *
 *	//Return an object
 *	$result->setFetchMode(PDO::FETCH_OBJ);
 *</code>
 *
 * @param int fetchMode
 */
PHP_METHOD(Pdm_Db_Result_Pdo, setFetchMode) {

	zval *_1 = NULL;
	int _0, ZEPHIR_LAST_CALL_STATUS;
	zval *fetchMode = NULL, *_2, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fetchMode);

	ZEPHIR_SEPARATE_PARAM(fetchMode);


	if (Z_TYPE_P(fetchMode) != IS_LONG) {
		_0 = zephir_get_intval(fetchMode);
		ZEPHIR_INIT_NVAR(fetchMode);
		ZVAL_LONG(fetchMode, _0);
	}
	do {
		if (ZEPHIR_IS_LONG(fetchMode, 4)) {
			break;
		}
		if (ZEPHIR_IS_LONG(fetchMode, 2)) {
			break;
		}
		if (ZEPHIR_IS_LONG(fetchMode, 3)) {
			break;
		}
		if (ZEPHIR_IS_LONG(fetchMode, 5)) {
			break;
		}
		zephir_get_strval(_1, fetchMode);
		ZEPHIR_CPY_WRT(fetchMode, _1);
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, pdm_db_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "Unsupported fetch mode '", fetchMode, "'");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "pdm/db/result/pdo.zep", 246 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	zephir_update_property_this(this_ptr, SL("fetchMode"), fetchMode TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getinternalresult",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "setfetchmode", NULL, fetchMode);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the internal PDO result object
 *
 * @return \PDOStatement
 */
PHP_METHOD(Pdm_Db_Result_Pdo, getInternalResult) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("pdoStatement"), PH_NOISY_CC);
	if (unlikely(!zephir_instance_of_ev(_0, zephir_get_internal_ce(SS("pdostatement") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid PDOStatement", "pdm/db/result/pdo.zep", 261);
		return;
	}
	RETURN_MM_MEMBER(this_ptr, "pdoStatement");

}

