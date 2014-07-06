
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"

#include <ext/pdo/php_pdo_driver.h>



/**
 * Pdm\Db\Adapter
 *
 * Base class for Pdm\Db adapters
 */
ZEPHIR_INIT_CLASS(Pdm_Db_AbstractAdapter) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, AbstractAdapter, pdm, db_abstractadapter, pdm_db_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Event Manager
	 *
	 * @var Pdm\Events\Manager
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Type of database system the adapter is used for
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Name of the dialect used
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("dialectType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Dialect instance
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("dialect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active connection ID
	 *
	 * @var long
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("connectionId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Statement
	 *
	 * @var string
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL bound parameter variables
	 *
	 * @var string
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active SQL Bind Types
	 *
	 * @var string
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("transactionLevel"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(pdm_db_abstractadapter_ce, SL("transactionsWithSavepoints"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Connection ID
	 */
	zend_declare_property_long(pdm_db_abstractadapter_ce, SL("_connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Type of database system the adapter is used for
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getType) {


	RETURN_MEMBER(this_ptr, "type");

}

/**
 * Name of the dialect used
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getDialectType) {


	RETURN_MEMBER(this_ptr, "dialectType");

}

/**
 * Active connection ID
 *
 * @var long
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getConnectionId) {


	RETURN_MEMBER(this_ptr, "connectionId");

}

/**
 * Active SQL Statement
 *
 * @var string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getSqlStatement) {


	RETURN_MEMBER(this_ptr, "sqlStatement");

}

/**
 * Active SQL bound parameter variables
 *
 * @var string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getSqlVariables) {


	RETURN_MEMBER(this_ptr, "sqlVariables");

}

/**
 * @var int
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getTransactionLevel) {


	RETURN_MEMBER(this_ptr, "transactionLevel");

}

/**
 * @var bool
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getTransactionsWithSavepoints) {


	RETURN_MEMBER(this_ptr, "transactionsWithSavepoints");

}

/**
 * Pdm\Db\Adapter constructor
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, __construct) {

	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dialectClass, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdialecttype",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(dialectClass);
	ZEPHIR_CONCAT_SV(dialectClass, "\\Pdm\\Db\\Dialect\\", _0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("connectionId"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("transactionLevel"), _1 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("transactionsWithSavepoints"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	_3 = zend_fetch_class(Z_STRVAL_P(dialectClass), Z_STRLEN_P(dialectClass), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_2, _3);
	if (zephir_has_constructor(_2 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("dialect"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the event manager
 *
 * @param Pdm\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	if (!(zephir_is_instance_of(eventsManager, SL("Pdm\\Events\\ManagerInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Pdm\\Events\\ManagerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Pdm\Events\ManagerInterface
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getEventsManager) {


	RETURN_MEMBER(this_ptr, "eventsManager");

}

/**
 * Sets the dialect used to produce the SQL
 *
 * @param Pdm\Db\DialectInterface
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, setDialect) {

	zval *dialect;

	zephir_fetch_params(0, 1, 0, &dialect);



	if (!(zephir_instance_of_ev(dialect, pdm_db_dialectinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dialect' must be an instance of 'Pdm\\Db\\DialectInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("dialect"), dialect TSRMLS_CC);

}

/**
 * Returns internal dialect instance
 *
 * @return Pdm\Db\DialectInterface
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getDialect) {


	RETURN_MEMBER(this_ptr, "dialect");

}

/**
 * Returns the first row in a SQL query result
 *
 *<code>
 *	//Getting first robot
 *	$robot = $connection->fecthOne("SELECT * FROM robots");
 *	print_r($robot);
 *
 *	//Getting first robot with associative indexes only
 *	$robot = $connection->fecthOne("SELECT * FROM robots", PDO::FETCH_ASSOC);
 *	print_r($robot);
 *</code>
 *
 * @param string sqlStatement
 * @param int fetchType
 * @param array bindParams
 * @param array bindTypes
 * @return mixed
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, fetchOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	zval *sqlStatement_param = NULL, *fetchType = NULL, *bindParams = NULL, *bindTypes = NULL, *result = NULL, *_1;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlStatement_param, &fetchType, &bindParams, &bindTypes);

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
	if (!fetchType) {
		ZEPHIR_INIT_VAR(fetchType);
		ZVAL_LONG(fetchType, 2);
	}
	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "query", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_2, _0, sqlStatement, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(result) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, fetchType);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(result, "fetch", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Dumps the complete result of a query into an array
 *
 *<code>
 *	//Getting all robots with associative indexes only
 *	$robots = $connection->fetchAll("SELECT * FROM robots", PDO::FETCH_ASSOC);
 *	foreach ($robots as $robot) {
 *		print_r($robot);
 *	}
 *
 *  //Getting all robots that contains word "robot" withing the name
 *  $robots = $connection->fetchAll("SELECT * FROM robots WHERE name LIKE :name",
 *		PDO::FETCH_ASSOC,
 *		array('name' => '%robot%')
 *  );
 *	foreach($robots as $robot){
 *		print_r($robot);
 *	}
 *</code>
 *
 * @param string sqlStatement
 * @param int fetchType
 * @param array bindParams
 * @param array bindTypes
 * @return array
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, fetchAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	zval *sqlStatement_param = NULL, *fetchType = NULL, *bindParams = NULL, *bindTypes = NULL, *results, *result = NULL, *row = NULL, *_1;
	zval *sqlStatement = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &sqlStatement_param, &fetchType, &bindParams, &bindTypes);

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
	if (!fetchType) {
		ZEPHIR_INIT_VAR(fetchType);
		ZVAL_LONG(fetchType, 2);
	}
	if (!bindParams) {
		ZEPHIR_INIT_VAR(bindParams);
		array_init(bindParams);
	}
	if (!bindTypes) {
		ZEPHIR_INIT_VAR(bindTypes);
		array_init(bindTypes);
	}


	ZEPHIR_INIT_VAR(results);
	array_init(results);
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "query", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&result, "call_user_func", &_2, _0, sqlStatement, bindParams, bindTypes);
	zephir_check_call_status();
	if (Z_TYPE_P(result) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, fetchType);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&row, result, "fetch",  NULL);
			zephir_check_call_status();
			if (!(zephir_is_true(row))) {
				break;
			}
			zephir_array_append(&results, row, PH_SEPARATE);
		}
	}
	RETURN_CCTOR(results);

}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * <code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * </code>
 *
 * @param string|array table
 * @param array values
 * @param array fields
 * @param array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, insert) {

	zval *_5 = NULL;
	HashTable *_3, *_8;
	HashPosition _2, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, *values, *fields = NULL, *dataTypes = NULL, *placeholders, *insertValues, *bindDataTypes = NULL, *bindType = NULL, *position = NULL, *value = NULL, *escapedTable = NULL, *joinedValues, *escapedFields = NULL, *field = NULL, *insertSql, *_0, *_1, **_4, *_6 = NULL, **_9, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &table, &values, &fields, &dataTypes);

	if (!fields) {
		fields = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(values) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "The second parameter for insert isn't an Array", "pdm/db/abstractadapter.zep", 243);
		return;
	}
	if (!(zephir_fast_count_int(values TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, pdm_db_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Unable to insert into ", table, " without data");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "pdm/db/abstractadapter.zep", 248 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(placeholders);
	array_init(placeholders);
	ZEPHIR_INIT_VAR(insertValues);
	array_init(insertValues);
	if (Z_TYPE_P(dataTypes) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(bindDataTypes);
		array_init(bindDataTypes);
	} else {
		ZEPHIR_CPY_WRT(bindDataTypes, dataTypes);
	}
	zephir_is_iterable(values, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(position, _3, _2);
		ZEPHIR_GET_HVALUE(value, _4);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			zephir_get_strval(_5, value);
			zephir_array_append(&placeholders, _5, PH_SEPARATE);
		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "null", 1);
				zephir_array_append(&placeholders, _6, PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "?", 1);
				zephir_array_append(&placeholders, _6, PH_SEPARATE);
				zephir_array_append(&insertValues, value, PH_SEPARATE);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, dataTypes, position, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Incomplete number of bind types", "pdm/db/abstractadapter.zep", 272);
						return;
					}
					zephir_array_append(&bindDataTypes, bindType, PH_SEPARATE);
				}
			}
		}
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(escapedTable, table);
	}
	ZEPHIR_INIT_VAR(joinedValues);
	zephir_fast_join_str(joinedValues, SL(", "), placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(insertSql);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_INIT_VAR(escapedFields);
			array_init(escapedFields);
			zephir_is_iterable(fields, &_8, &_7, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
			  ; zephir_hash_move_forward_ex(_8, &_7)
			) {
				ZEPHIR_GET_HVALUE(field, _9);
				ZEPHIR_CALL_METHOD(&_10, this_ptr, "escapeidentifier", NULL, field);
				zephir_check_call_status();
				zephir_array_append(&escapedFields, _10, PH_SEPARATE);
			}
		} else {
			ZEPHIR_CPY_WRT(escapedFields, fields);
		}
		ZEPHIR_INIT_NVAR(_6);
		zephir_fast_join_str(_6, SL(", "), escapedFields TSRMLS_CC);
		ZEPHIR_CONCAT_SVSVSVS(insertSql, "INSERT INTO ", escapedTable, " (", _6, ") VALUES (", joinedValues, ")");
	} else {
		ZEPHIR_CONCAT_SVSVS(insertSql, "INSERT INTO ", escapedTable, " VALUES (", joinedValues, ")");
	}
	if (!(zephir_fast_count_int(bindDataTypes TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, insertSql, insertValues);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, insertSql, insertValues, bindDataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * <code>
 * //Updating existing robot
 * $success = $connection->update(
 *     "robots",
 *     array("name"),
 *     array("New Astro Boy"),
 *     "id = 101"
 * );
 *
 * //Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 * </code>
 *
 * @param string|array table
 * @param array fields
 * @param array values
 * @param string whereCondition
 * @param array dataTypes
 * @return 	boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, update) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *table, *fields, *values, *whereCondition = NULL, *dataTypes = NULL, *placeholders, *updateValues, *position = NULL, *value = NULL, *field = NULL, *bindDataTypes = NULL, *escapedField = NULL, *bindType = NULL, *escapedTable = NULL, *setClause, *updateSql, *conditions, *whereBind, *whereTypes, **_2, *_3 = NULL, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &table, &fields, &values, &whereCondition, &dataTypes);

	if (!whereCondition) {
		whereCondition = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(placeholders);
	array_init(placeholders);
	ZEPHIR_INIT_VAR(updateValues);
	array_init(updateValues);
	if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(bindDataTypes);
		array_init(bindDataTypes);
	} else {
		ZEPHIR_CPY_WRT(bindDataTypes, dataTypes);
	}
	zephir_is_iterable(values, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(position, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		ZEPHIR_OBS_NVAR(field);
		if (!(zephir_array_isset_fetch(&field, fields, position, 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "The number of values in the update is not the same as fields", "pdm/db/abstractadapter.zep", 353);
			return;
		}
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_CALL_METHOD(&escapedField, this_ptr, "escapeidentifier", NULL, field);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(escapedField, field);
		}
		if (Z_TYPE_P(value) == IS_OBJECT) {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_VSV(_3, escapedField, " = ", value);
			zephir_array_append(&placeholders, _3, PH_SEPARATE);
		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_VS(_3, escapedField, " = null");
				zephir_array_append(&placeholders, _3, PH_SEPARATE);
			} else {
				zephir_array_append(&updateValues, value, PH_SEPARATE);
				if (Z_TYPE_P(dataTypes) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, dataTypes, position, 0 TSRMLS_CC))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Incomplete number of bind types", "pdm/db/abstractadapter.zep", 371);
						return;
					}
					zephir_array_append(&bindDataTypes, bindType, PH_SEPARATE);
				}
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VS(_4, escapedField, " = ?");
				zephir_array_append(&placeholders, _4, PH_SEPARATE);
			}
		}
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(escapedTable, table);
	}
	ZEPHIR_INIT_VAR(setClause);
	zephir_fast_join_str(setClause, SL(", "), placeholders TSRMLS_CC);
	ZEPHIR_INIT_VAR(updateSql);
	if (Z_TYPE_P(whereCondition) != IS_NULL) {
		ZEPHIR_CONCAT_SVSVS(updateSql, "UPDATE ", escapedTable, " SET ", setClause, " WHERE ");
		if (Z_TYPE_P(whereCondition) == IS_STRING) {
			zephir_concat_self(&updateSql, whereCondition TSRMLS_CC);
		} else {
			if (Z_TYPE_P(whereCondition) != IS_ARRAY) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid WHERE clause conditions", "pdm/db/abstractadapter.zep", 397);
				return;
			}
			ZEPHIR_OBS_VAR(conditions);
			if (zephir_array_isset_string_fetch(&conditions, whereCondition, SS("conditions"), 0 TSRMLS_CC)) {
				zephir_concat_self(&updateSql, conditions TSRMLS_CC);
			}
			ZEPHIR_OBS_VAR(whereBind);
			if (zephir_array_isset_string_fetch(&whereBind, whereCondition, SS("bind"), 0 TSRMLS_CC)) {
				zephir_merge_append(updateValues, whereBind);
			}
			ZEPHIR_OBS_VAR(whereTypes);
			if (zephir_array_isset_string_fetch(&whereTypes, whereCondition, SS("bindTypes"), 0 TSRMLS_CC)) {
				zephir_merge_append(bindDataTypes, whereTypes);
			}
		}
	} else {
		ZEPHIR_CONCAT_SVSV(updateSql, "UPDATE ", escapedTable, " SET ", setClause);
	}
	if (!(zephir_fast_count_int(bindDataTypes TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, updateSql, updateValues);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, updateSql, updateValues, bindDataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * <code>
 * //Deleting existing robot
 * $success = $connection->delete(
 *     "robots",
 *     "id = 101"
 * );
 *
 * //Next SQL sentence is generated
 * DELETE FROM `robots` WHERE `id` = 101
 * </code>
 *
 * @param string table
 * @param string whereCondition
 * @param array placeholders
 * @param array dataTypes
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *whereCondition = NULL, *placeholders = NULL, *dataTypes = NULL, *sql, *escapedTable = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &table_param, &whereCondition, &placeholders, &dataTypes);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!whereCondition) {
		whereCondition = ZEPHIR_GLOBAL(global_null);
	}
	if (!placeholders) {
		placeholders = ZEPHIR_GLOBAL(global_null);
	}
	if (!dataTypes) {
		dataTypes = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CALL_METHOD(&escapedTable, this_ptr, "escapeidentifier", NULL, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(escapedTable, table);
	}
	ZEPHIR_INIT_VAR(sql);
	if (!(ZEPHIR_IS_EMPTY(whereCondition))) {
		ZEPHIR_CONCAT_SVSV(sql, "DELETE FROM ", escapedTable, " WHERE ", whereCondition);
	} else {
		ZEPHIR_CONCAT_SV(sql, "DELETE FROM ", escapedTable);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, sql, placeholders, dataTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a list of columns
 *
 * @param array columnList
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getColumnList) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *columnList, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcolumnlist", NULL, columnList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string sqlQuery
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, forUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *_0;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		sqlQuery = sqlQuery_param;
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "forupdate", NULL, sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string sqlQuery
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, sharedLock) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sqlQuery_param = NULL, *_0;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		sqlQuery = sqlQuery_param;
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "sharedlock", NULL, sqlQuery);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the SQL column definition from a column
 *
 * @param Pdm\Db\ColumnInterface column
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getColumnDefinition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if (!(zephir_instance_of_ev(column, pdm_db_columninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Pdm\\Db\\ColumnInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcolumndefinition", NULL, column);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Creates a new savepoint
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, createSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dialect = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dialect, _0);
	ZEPHIR_CALL_METHOD(&_1, dialect, "supportssavepoints",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Savepoints are not supported by this database adapter.", "pdm/db/abstractadapter.zep", 524);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, dialect, "createsavepoint", NULL, name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Releases given savepoint
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, releaseSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dialect = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dialect, _0);
	ZEPHIR_CALL_METHOD(&_1, dialect, "supportssavepoints",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Savepoints are not supported by this database adapter", "pdm/db/abstractadapter.zep", 543);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, dialect, "supportsreleasesavepoints",  NULL);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_3, dialect, "releasesavepoint", NULL, name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rollbacks given savepoint
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, rollbackSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dialect = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dialect, _0);
	ZEPHIR_CALL_METHOD(&_1, dialect, "supportssavepoints",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Savepoints are not supported by this database adapter", "pdm/db/abstractadapter.zep", 566);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, dialect, "rollbacksavepoint", NULL, name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, _2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set if nested transactions should use savepoints
 *
 * @param boolean nestedTransactionsWithSavepoints
 * @return Pdm\Db\AdapterInterface
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, setNestedTransactionsWithSavepoints) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *nestedTransactionsWithSavepoints_param = NULL, *_0, *_1, *_2 = NULL;
	zend_bool nestedTransactionsWithSavepoints;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nestedTransactionsWithSavepoints_param);

	nestedTransactionsWithSavepoints = zephir_get_boolval(nestedTransactionsWithSavepoints_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("transactionLevel"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Nested transaction with savepoints behavior cannot be changed while a transaction is open", "pdm/db/abstractadapter.zep", 581);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "supportssavepoints",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Savepoints are not supported by this database adapter", "pdm/db/abstractadapter.zep", 585);
		return;
	}
	zephir_update_property_this(this_ptr, SL("transactionsWithSavepoints"), nestedTransactionsWithSavepoints ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns if nested transactions should use savepoints
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, isNestedTransactionsWithSavepoints) {


	RETURN_MEMBER(this_ptr, "transactionsWithSavepoints");

}

/**
 * Returns the savepoint name to use for nested transactions
 *
 * @return string
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getNestedTransactionSavepointName) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("transactionLevel"), PH_NOISY_CC);
	ZEPHIR_CONCAT_SV(return_value, "Pdm_SAVEPOINT_", _0);
	return;

}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
 * //Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     array($connection->getDefaultIdValue(), "Astro Boy", 1952),
 *     array("id", "name", "year")
 * );
 *</code>
 *
 * @return Pdm\Db\RawValue
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, getDefaultIdValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rawValue, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(rawValue);
	object_init_ex(rawValue, pdm_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "null", 0);
	ZEPHIR_CALL_METHOD(NULL, rawValue, "__construct", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_CCTOR(rawValue);

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, supportSequences) {


	RETURN_BOOL(0);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
PHP_METHOD(Pdm_Db_AbstractAdapter, useExplicitIdValue) {


	RETURN_BOOL(0);

}

