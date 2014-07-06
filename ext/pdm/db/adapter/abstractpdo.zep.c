
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
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"

#include <ext/pdo/php_pdo_driver.h>



/**
 * Pdm\Db\Adapter\Pdo
 *
 * Pdm\Db\Adapter\Pdo is the Pdm\Db that internally uses Pdo to connect to a database
 *
 *<code>
 *	$connection = new \Pdm\Db\Adapter\Pdo\Mysql(array(
 *		'host' => '192.168.0.11',
 *		'username' => 'sigma',
 *		'password' => 'secret',
 *		'dbname' => 'blog',
 *		'port' => '3306'
 *	));
 *</code>
 */
ZEPHIR_INIT_CLASS(Pdm_Db_Adapter_AbstractPdo) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Db\\Adapter, AbstractPdo, pdm, db_adapter_abstractpdo, pdm_db_abstractadapter_ce, pdm_db_adapter_abstractpdo_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Pdo Handler
	 * @var \Pdo
	 */
	zend_declare_property_null(pdm_db_adapter_abstractpdo_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Last affected rows
	 * @var int
	 */
	zend_declare_property_null(pdm_db_adapter_abstractpdo_ce, SL("affectedRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Last affected rows
 * @var int
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, getAffectedRows) {


	RETURN_MEMBER(this_ptr, "affectedRows");

}

/**
 * Pdm\Db\Adapter constructor
 *
 * @param \PDO pdo
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *pdo, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pdo);



	if (!(zephir_instance_of_ev(pdo, php_pdo_get_dbh_ce() TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'pdo' must be an instance of 'PDO'", "", 0);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, pdm_db_adapter_abstractpdo_ce, this_ptr, "__construct", &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(pdo) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_adapter_exception_ce, "A resource of PDO must be passed", "pdm/db/adapter/abstractpdo.zep", 51);
		return;
	}
	zephir_update_property_this(this_ptr, SL("pdo"), pdo TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("affectedRows"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a PDO prepared statement to be executed with 'executePrepared'
 *
 * <code>
 *   $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 *   $result = $connection->executePrepared($statement, ['name' => 'Voltron']);
 * </code>
 *
 * @param string statement
 * @return \PDOStatement
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, prepare) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement_param = NULL, *_0;
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "prepare", NULL, statement);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Executes a prepared statement binding. This function uses integer indexes starting from zero
 *
 * <code>
 *   $statement = $db->prepare('SELECT * FROM robots WHERE name = :name');
 *   $result = $connection->executePrepared($statement, array('name' => 'Voltron'));
 * </code>
 *
 * @param \PDOStatement statement
 * @param array bindParams
 * @param array bindTypes
 * @return \PDOStatement
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, executePrepared) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *statement, *bindParams = NULL, *bindTypes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement, &bindParams, &bindTypes);

	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	} else {
		ZEPHIR_SEPARATE_PARAM(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	}


	if (!(zephir_instance_of_ev(statement, zephir_get_internal_ce(SS("pdostatement") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'statement' must be an instance of 'PDOStatement'", "", 0);
		return;
	}
	if (Z_TYPE_P(bindParams) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(bindParams);
		array_init(bindParams);
	}
	ZEPHIR_CALL_METHOD(NULL, statement, "execute", NULL, bindParams);
	zephir_check_call_status();
	RETURN_CCTOR(statement);

}

PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, bindStatmentParameters) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zend_bool hasBindParams, hasBindTypes, _3;
	zval *statement, *bindParams = NULL, *bindTypes = NULL, *wildcard = NULL, *value = NULL, *parameter = NULL, *type = NULL, *castValue = NULL, **_2, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &statement, &bindParams, &bindTypes);

	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	} else {
		ZEPHIR_SEPARATE_PARAM(bindTypes);
	}


	if (!(zephir_instance_of_ev(statement, zephir_get_internal_ce(SS("pdostatement") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'statement' must be an instance of 'PDOStatement'", "", 0);
		return;
	}
	if (Z_TYPE_P(bindTypes) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(bindTypes);
		array_init(bindTypes);
	}
	if (zephir_fast_count_int(bindParams TSRMLS_CC) > 0) {
		hasBindParams = 1;
	} else {
		hasBindParams = 0;
	}
	if (zephir_fast_count_int(bindTypes TSRMLS_CC) > 0) {
		hasBindTypes = 1;
	} else {
		hasBindTypes = 0;
	}
	zephir_is_iterable(bindParams, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(wildcard, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(wildcard) == IS_LONG) {
			ZEPHIR_INIT_NVAR(parameter);
			ZVAL_LONG(parameter, (zephir_get_numberval(wildcard) + 1));
		} else {
			if (Z_TYPE_P(wildcard) == IS_STRING) {
				ZEPHIR_CPY_WRT(parameter, wildcard);
			} else {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_adapter_exception_ce, "Invalid bind parameter (1)", "pdm/db/adapter/abstractpdo.zep", 126);
				return;
			}
		}
		_3 = hasBindParams;
		if (_3) {
			_3 = hasBindTypes;
		}
		if (_3) {
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_fetch(&type, bindTypes, wildcard, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(type);
				ZVAL_LONG(type, 2);
			}
			if (ZEPHIR_IS_LONG(type, 32)) {
				ZEPHIR_INIT_NVAR(castValue);
				ZVAL_DOUBLE(castValue, zephir_get_doubleval(value));
				ZEPHIR_INIT_NVAR(type);
				ZVAL_LONG(type, 1024);
			} else {
				ZEPHIR_CPY_WRT(castValue, value);
			}
			if (ZEPHIR_IS_LONG(type, 1024)) {
				Z_SET_ISREF_P(castValue);
				ZEPHIR_CALL_METHOD(NULL, statement, "bindparam", &_4, parameter, castValue);
				zephir_check_call_status();
				Z_UNSET_ISREF_P(castValue);
			} else {
				Z_SET_ISREF_P(castValue);
				ZEPHIR_CALL_METHOD(NULL, statement, "bindparam", &_5, parameter, castValue, type);
				zephir_check_call_status();
				Z_UNSET_ISREF_P(castValue);
			}
		} else {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 2);
			Z_SET_ISREF_P(value);
			ZEPHIR_CALL_METHOD(NULL, statement, "bindparam", &_7, parameter, value, _6);
			zephir_check_call_status();
			Z_UNSET_ISREF_P(value);
		}
	}
	RETURN_CCTOR(statement);

}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server is returning rows
 *
 * <code>
 *   //Querying data
 *   $resultset = $connection->query("SELECT * FROM robots WHERE type = 'mechanical'");
 *   $resultset = $connection->query("SELECT * FROM robots WHERE type = ?", ["mechanical"]);
 * </code>
 *
 * @param string sqlStatement
 * @param array bindParams
 * @param array bindTypes
 * @return Pdm\Db\ResultInterface|\PDO|bool
 * <\Pdm\Db\ResultInterface> | <\PDOStatement> | boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *statement = NULL, *result, *affectedRows = NULL, *_1, *_2 = NULL;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams, &bindTypes);

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
	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	}


	_0 = Z_TYPE_P(bindParams) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(bindParams TSRMLS_CC) > 0;
	}
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&statement, _1, "prepare", NULL, sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "executeprepared", NULL, statement, bindParams, bindTypes);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(statement, _2);
		}
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&statement, _1, "query", NULL, sqlStatement);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(statement) == IS_OBJECT) {
		if (zephir_instance_of_ev(statement, zephir_get_internal_ce(SS("pdostatement") TSRMLS_CC) TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&affectedRows, statement, "rowcount",  NULL);
			zephir_check_call_status();
			if (Z_TYPE_P(affectedRows) == IS_LONG) {
				zephir_update_property_this(this_ptr, SL("affectedRows"), affectedRows TSRMLS_CC);
			}
			ZEPHIR_INIT_VAR(result);
			object_init_ex(result, pdm_db_result_pdo_ce);
			ZEPHIR_CALL_METHOD(NULL, result, "__construct", NULL, this_ptr, statement, sqlStatement, bindParams, bindTypes);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		}
	}
	RETURN_CCTOR(statement);

}

/**
 * Sends SQL statements to the database server returning the success state.
 * Use this method only when the SQL statement sent to the server doesn't return any row
 *
 *<code>
 *	//Inserting data
 *	$success = $connection->execute("INSERT INTO robots VALUES (1, 'Astro Boy')");
 *	$success = $connection->execute("INSERT INTO robots VALUES (?, ?)", array(1, 'Astro Boy'));
 *</code>
 *
 * @param string sqlStatement
 * @param array bindParams
 * @param array bindTypes
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, execute) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlStatement_param = NULL, *bindParams = NULL, *bindTypes = NULL, *affectedRows = NULL, *newStatement = NULL, *statement = NULL, *_0;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &sqlStatement_param, &bindParams, &bindTypes);

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
	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	}


	ZEPHIR_INIT_VAR(affectedRows);
	ZVAL_LONG(affectedRows, 0);
	if (Z_TYPE_P(bindParams) == IS_ARRAY) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&statement, _0, "prepare", NULL, sqlStatement);
		zephir_check_call_status();
		if (Z_TYPE_P(statement) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&newStatement, this_ptr, "executeprepared", NULL, statement, bindParams, bindTypes);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&affectedRows, newStatement, "rowcount",  NULL);
			zephir_check_call_status();
		}
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&affectedRows, _0, "exec", NULL, sqlStatement);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(affectedRows) == IS_LONG) {
		zephir_update_property_this(this_ptr, SL("affectedRows"), affectedRows TSRMLS_CC);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the number of affected rows by the lastest INSERT/UPDATE/DELETE executed in the database system
 *
 *<code>
 *	$connection->execute("DELETE FROM robots");
 *	echo $connection->affectedRows(), ' were deleted';
 *</code>
 *
 * @return int
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, affectedRows) {


	RETURN_MEMBER(this_ptr, "affectedRows");

}

/**
 * Closes the active connection returning success. Pdm automatically closes and destroys
 * active connections when the request ends
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, close) {

	zval *pdo = NULL, *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(pdo, _0);
	if (Z_TYPE_P(pdo) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("pdo"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Escapes a column/table/schema name
 *
 *<code>
 *	$escapedTable = $connection->escapeIdentifier('robots');
 *	$escapedTable = $connection->escapeIdentifier(array('store', 'robots'));
 *</code>
 *
 * @param string identifier
 * @return string
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, escapeIdentifier) {

	zval *identifier, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		zephir_array_fetch_long(&_0, identifier, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&_1, identifier, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVS(return_value, "\"", _0, "\".\"", _1, "\"");
		return;
	}
	ZEPHIR_CONCAT_SVS(return_value, "\"", identifier, "\"");
	return;

}

/**
 * Escapes a value to avoid SQL injections according to the active charset in the connection
 *
 *<code>
 *	$escapedStr = $connection->escapeString('some dangerous value');
 *</code>
 *
 * @param string str
 * @return string
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, escapeString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(str_param) == IS_STRING)) {
		str = str_param;
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "quote", NULL, str);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the insert id for the auto_increment/serial column inserted in the lastest executed SQL statement
 *
 *<code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Getting the generated id
 * $id = $connection->lastInsertId();
 *</code>
 *
 * @param string sequenceName
 * @return int|boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, lastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequenceName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sequenceName);

	if (!sequenceName) {
		sequenceName = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "lastinsertid", NULL, sequenceName);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Starts a transaction in the connection
 *
 * @param boolean nesting
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, begin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, *transactionLevel = NULL, *savepointName = NULL, *_0, *_1 = NULL;
	zend_bool nesting;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);

	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("transactionLevel") TSRMLS_CC));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("transactionLevel"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transactionLevel, _0);
	if (ZEPHIR_IS_LONG(transactionLevel, 1)) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0, "begintransaction", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		if (zephir_is_true(transactionLevel)) {
			if (nesting) {
				ZEPHIR_CALL_METHOD(&_1, this_ptr, "isnestedtransactionswithsavepoints",  NULL);
				zephir_check_call_status();
				if (zephir_is_true(_1)) {
					ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname",  NULL);
					zephir_check_call_status();
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createsavepoint", NULL, savepointName);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Rollbacks the active transaction in the connection
 *
 * @param boolean nesting
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, rollback) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, *transactionLevel = NULL, *savepointName = NULL, *_0, *_1 = NULL;
	zend_bool nesting;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);

	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("transactionLevel"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transactionLevel, _0);
	if (!(zephir_is_true(transactionLevel))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_adapter_exception_ce, "There is no active transaction", "pdm/db/adapter/abstractpdo.zep", 416);
		return;
	}
	if (ZEPHIR_IS_LONG(transactionLevel, 1)) {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel") TSRMLS_CC));
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0, "rollback", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		if (zephir_is_true(transactionLevel)) {
			if (nesting) {
				ZEPHIR_CALL_METHOD(&_1, this_ptr, "isnestedtransactionswithsavepoints",  NULL);
				zephir_check_call_status();
				if (zephir_is_true(_1)) {
					ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname",  NULL);
					zephir_check_call_status();
					RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel") TSRMLS_CC));
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rollbacksavepoint", NULL, savepointName);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
	}
	if (ZEPHIR_GT_LONG(transactionLevel, 0)) {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel") TSRMLS_CC));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Commits the active transaction in the connection
 *
 * @param boolean nesting
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, commit) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *nesting_param = NULL, *transactionLevel = NULL, *savepointName = NULL, *_0, *_1 = NULL;
	zend_bool nesting;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &nesting_param);

	if (!nesting_param) {
		nesting = 1;
	} else {
		nesting = zephir_get_boolval(nesting_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("transactionLevel"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transactionLevel, _0);
	if (!(zephir_is_true(transactionLevel))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_adapter_exception_ce, "There is no active transaction", "pdm/db/adapter/abstractpdo.zep", 473);
		return;
	}
	if (ZEPHIR_IS_LONG(transactionLevel, 1)) {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel") TSRMLS_CC));
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_0, "commit", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		if (zephir_is_true(transactionLevel)) {
			if (nesting) {
				ZEPHIR_CALL_METHOD(&_1, this_ptr, "isnestedtransactionswithsavepoints",  NULL);
				zephir_check_call_status();
				if (zephir_is_true(_1)) {
					ZEPHIR_CALL_METHOD(&savepointName, this_ptr, "getnestedtransactionsavepointname",  NULL);
					zephir_check_call_status();
					RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel") TSRMLS_CC));
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "releasesavepoint", NULL, savepointName);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
	}
	if (ZEPHIR_GT_LONG(transactionLevel, 0)) {
		RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("transactionLevel") TSRMLS_CC));
	}
	RETURN_MM_BOOL(0);

}

/**
 * Checks whether the connection is under a transaction
 *
 *<code>
 *	$connection->begin();
 *	var_dump($connection->isUnderTransaction()); //true
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, isUnderTransaction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "intransaction", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return internal PDO handler
 *
 * @return \Pdo
 */
PHP_METHOD(Pdm_Db_Adapter_AbstractPdo, getInternalHandler) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("pdo"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_OBJECT) {
		RETURN_MM_MEMBER(this_ptr, "pdo");
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid PDO", "pdm/db/adapter/abstractpdo.zep", 542);
	return;

}

