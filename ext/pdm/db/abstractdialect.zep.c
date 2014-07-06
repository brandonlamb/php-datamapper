
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * Pdm\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBM related syntax
 */
ZEPHIR_INIT_CLASS(Pdm_Db_AbstractDialect) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, AbstractDialect, pdm, db_abstractdialect, pdm_db_abstractdialect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_null(pdm_db_abstractdialect_ce, SL("escapeChar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @var string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, getEscapeChar) {


	RETURN_MEMBER(this_ptr, "escapeChar");

}

/**
 * Generates the SQL for LIMIT clause
 *
 *<code>
 * $sql = $dialect->limit('SELECT * FROM robots', 10);
 * echo $sql; // SELECT * FROM robots LIMIT 10
 *</code>
 *
 * @param string sqlQuery
 * @param int number
 * @return string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, limit) {

	int number;
	zval *sqlQuery_param = NULL, *number_param = NULL, _0, _1;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

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
	number = zephir_get_intval(number_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, number);
	if (zephir_is_numeric(&_0)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, number);
		ZEPHIR_CONCAT_VSV(return_value, sqlQuery, " LIMIT ", &_1);
		RETURN_MM();
	}
	RETURN_CTOR(sqlQuery);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_AbstractDialect, offset) {

	int number;
	zval *sqlQuery_param = NULL, *number_param = NULL, _0, _1;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number_param);

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
	number = zephir_get_intval(number_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, number);
	if (zephir_is_numeric(&_0)) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, number);
		ZEPHIR_CONCAT_VSV(return_value, sqlQuery, " OFFSET ", &_1);
		RETURN_MM();
	}
	RETURN_CTOR(sqlQuery);

}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 *<code>
 * $sql = $dialect->forUpdate('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots FOR UPDATE
 *</code>
 *
 * @param	string sqlQuery
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, forUpdate) {

	zval *sqlQuery_param = NULL;
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


	ZEPHIR_CONCAT_VS(return_value, sqlQuery, " FOR UPDATE");
	RETURN_MM();

}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 *<code>
 * $sql = $dialect->sharedLock('SELECT * FROM robots');
 * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
 *</code>
 *
 * @param	string sqlQuery
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, sharedLock) {

	zval *sqlQuery_param = NULL;
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


	ZEPHIR_CONCAT_VS(return_value, sqlQuery, " LOCK IN SHARE MODE");
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_AbstractDialect, supportsSavepoints) {


	RETURN_BOOL(1);

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_AbstractDialect, supportsReleaseSavepoints) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "supportssavepoints", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_AbstractDialect, createSavepoint) {

	zval *name_param = NULL;
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


	ZEPHIR_CONCAT_SV(return_value, "SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_AbstractDialect, releaseSavepoint) {

	zval *name_param = NULL;
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


	ZEPHIR_CONCAT_SV(return_value, "RELEASE SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * {@inheritDoc}
 */
PHP_METHOD(Pdm_Db_AbstractDialect, rollbackSavepoint) {

	zval *name_param = NULL;
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


	ZEPHIR_CONCAT_SV(return_value, "ROLLBACK TO SAVEPOINT ", name);
	RETURN_MM();

}

/**
 * Gets a list of columns with escaped identifiers
 *
 *<code>
 * echo $dialect->getColumnList(array('column1', 'column'));
 *</code>
 *
 * @param	array columnList
 * @return	string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, getColumnList) {

	HashTable *_2;
	HashPosition _1;
	zval *columnList, *strList, *escapeChar = NULL, *column = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &columnList);



	ZEPHIR_INIT_VAR(strList);
	array_init(strList);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("escapeChar"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(escapeChar, _0);
	zephir_is_iterable(columnList, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(column, _3);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VVV(_4, escapeChar, column, escapeChar);
		zephir_array_append(&strList, _4, PH_SEPARATE);
	}
	zephir_fast_join_str(return_value, SL(", "), strList TSRMLS_CC);
	RETURN_MM();

}

/**
 * Transforms an intermediate representation for a expression into a database system valid expression
 *
 * @param array expression
 * @param string escapeChar
 * @return string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, getSqlExpression) {

	zephir_fcall_cache_entry *_10 = NULL;
	HashTable *_7, *_13;
	HashPosition _6, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *escapeChar = NULL, *_1 = NULL;
	zval *expression, *escapeChar_param = NULL, *type, *domain, *operator, *left = NULL, *right = NULL, *name = NULL, *sqlItems, *escapedName = NULL, *sqlArguments, *arguments, *argument = NULL, *item = NULL, *_0, *_2, *_3, *_4, *_5 = NULL, **_8, *_9 = NULL, *_11 = NULL, **_14, *_15, *_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &expression, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		if (ZEPHIR_IS_STRING_IDENTICAL(escapeChar, "")) {
			ZEPHIR_OBS_VAR(_0);
			zephir_read_property_this(&_0, this_ptr, SL("escapeChar"), PH_NOISY_CC);
			zephir_get_strval(_1, _0);
			ZEPHIR_CPY_WRT(escapeChar, _1);
		}
	}
	if (Z_TYPE_P(expression) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid SQL expression", "pdm/db/abstractdialect.zep", 176);
		return;
	}
	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, expression, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid SQL expression", "pdm/db/abstractdialect.zep", 180);
		return;
	}
	if (ZEPHIR_IS_STRING(type, "qualified")) {
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_string(&name, expression, SL("name"), PH_NOISY TSRMLS_CC);
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_INIT_VAR(escapedName);
			ZEPHIR_CONCAT_VVV(escapedName, escapeChar, name, escapeChar);
		} else {
			ZEPHIR_CPY_WRT(escapedName, name);
		}
		ZEPHIR_OBS_VAR(domain);
		if (zephir_array_isset_string_fetch(&domain, expression, SS("domain"), 0 TSRMLS_CC)) {
			if (ZEPHIR_GLOBAL(db).escape_identifiers) {
				ZEPHIR_CONCAT_VVVSV(return_value, escapeChar, domain, escapeChar, ".", escapedName);
				RETURN_MM();
			} else {
				ZEPHIR_CONCAT_VSV(return_value, domain, ".", escapedName);
				RETURN_MM();
			}
		}
		RETURN_CCTOR(escapedName);
	}
	if (ZEPHIR_IS_STRING(type, "literal")) {
		zephir_array_fetch_string(&_2, expression, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	if (ZEPHIR_IS_STRING(type, "binary-op")) {
		zephir_array_fetch_string(&_2, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", NULL, _2, escapeChar);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3, expression, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", NULL, _3, escapeChar);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4, expression, SL("op"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CONCAT_VSVSV(return_value, left, " ", _4, " ", right);
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "unary-op")) {
		ZEPHIR_OBS_VAR(operator);
		zephir_array_fetch_string(&operator, expression, SL("op"), PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(left);
		if (zephir_array_isset_string_fetch(&left, expression, SS("left"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpression", NULL, left, escapeChar);
			zephir_check_call_status();
			ZEPHIR_CONCAT_VV(return_value, _5, operator);
			RETURN_MM();
		}
		ZEPHIR_OBS_NVAR(right);
		if (zephir_array_isset_string_fetch(&right, expression, SS("right"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpression", NULL, right, escapeChar);
			zephir_check_call_status();
			ZEPHIR_CONCAT_VV(return_value, _5, operator);
			RETURN_MM();
		}
	}
	if (ZEPHIR_IS_STRING(type, "placeholder")) {
		zephir_array_fetch_string(&_2, expression, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	if (ZEPHIR_IS_STRING(type, "parentheses")) {
		zephir_array_fetch_string(&_2, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpression", NULL, _2, escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "(", _5, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "functionCall")) {
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_string(&name, expression, SL("name"), PH_NOISY TSRMLS_CC);
		ZEPHIR_INIT_VAR(sqlArguments);
		array_init(sqlArguments);
		ZEPHIR_OBS_VAR(arguments);
		if (zephir_array_isset_string_fetch(&arguments, expression, SS("arguments"), 0 TSRMLS_CC)) {
			zephir_is_iterable(arguments, &_7, &_6, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_7, &_6)
			) {
				ZEPHIR_GET_HVALUE(argument, _8);
				ZEPHIR_CALL_METHOD(&_9, this_ptr, "getsqlexpression", &_10, argument, escapeChar);
				zephir_check_call_status();
				zephir_array_append(&sqlArguments, _9, PH_SEPARATE);
			}
			ZEPHIR_INIT_VAR(_11);
			zephir_fast_join_str(_11, SL(", "), sqlArguments TSRMLS_CC);
			ZEPHIR_CONCAT_VSVS(return_value, name, "(", _11, ")");
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_VS(return_value, name, "()");
			RETURN_MM();
		}
	}
	if (ZEPHIR_IS_STRING(type, "list")) {
		ZEPHIR_INIT_VAR(sqlItems);
		array_init(sqlItems);
		zephir_array_fetch_long(&_2, expression, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_is_iterable(_2, &_13, &_12, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(item, _14);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getsqlexpression", &_10, item, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&sqlItems, _5, PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(_11);
		zephir_fast_join_str(_11, SL(", "), sqlItems TSRMLS_CC);
		ZEPHIR_CONCAT_SVS(return_value, "(", _11, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "all")) {
		RETURN_MM_STRING("*", 1);
	}
	if (ZEPHIR_IS_STRING(type, "cast")) {
		zephir_array_fetch_string(&_2, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_10, _2, escapeChar);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3, expression, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_10, _3, escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "CAST(", left, " AS ", right, ")");
		RETURN_MM();
	}
	if (ZEPHIR_IS_STRING(type, "convert")) {
		zephir_array_fetch_string(&_2, expression, SL("left"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&left, this_ptr, "getsqlexpression", &_10, _2, escapeChar);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3, expression, SL("right"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&right, this_ptr, "getsqlexpression", &_10, _3, escapeChar);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "CONVERT(", left, " USING ", right, ")");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_15);
	object_init_ex(_15, pdm_db_exception_ce);
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_SVS(_16, "Invalid SQL expression type '", type, "'");
	ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _16);
	zephir_check_call_status();
	zephir_throw_exception_debug(_15, "pdm/db/abstractdialect.zep", 287 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Transform an intermediate representation for a schema/table into a database system valid expression
 *
 * @param array table
 * @param string escapeChar
 * @return string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, getSqlTable) {

	zval *escapeChar = NULL, *_1 = NULL;
	zval *table, *escapeChar_param = NULL, *sqlTable = NULL, *sqlSchema = NULL, *aliasName, *sqlTableAlias = NULL, *schemaName, *tableName, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &escapeChar_param);

	if (!escapeChar_param) {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_EMPTY_STRING(escapeChar);
	} else {
		zephir_get_strval(escapeChar, escapeChar_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(escapeChar, "")) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("escapeChar"), PH_NOISY_CC);
		zephir_get_strval(_1, _0);
		ZEPHIR_CPY_WRT(escapeChar, _1);
	}
	if (Z_TYPE_P(table) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(tableName);
		zephir_array_fetch_long(&tableName, table, 0, PH_NOISY TSRMLS_CC);
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_INIT_VAR(sqlTable);
			ZEPHIR_CONCAT_VVV(sqlTable, escapeChar, tableName, escapeChar);
		} else {
			ZEPHIR_CPY_WRT(sqlTable, tableName);
		}
		ZEPHIR_OBS_VAR(schemaName);
		zephir_array_fetch_long(&schemaName, table, 1, PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(schemaName) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(sqlSchema);
			if (ZEPHIR_GLOBAL(db).escape_identifiers) {
				ZEPHIR_CONCAT_VVVSV(sqlSchema, escapeChar, schemaName, escapeChar, ".", sqlTable);
			} else {
				ZEPHIR_CONCAT_VSV(sqlSchema, schemaName, ".", sqlTable);
			}
		} else {
			ZEPHIR_CPY_WRT(sqlSchema, sqlTable);
		}
		ZEPHIR_OBS_VAR(aliasName);
		if (zephir_array_isset_long_fetch(&aliasName, table, 2, 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(sqlTableAlias);
			if (ZEPHIR_GLOBAL(db).escape_identifiers) {
				ZEPHIR_CONCAT_VSVVV(sqlTableAlias, sqlSchema, " AS ", escapeChar, aliasName, escapeChar);
			} else {
				ZEPHIR_CONCAT_VSV(sqlTableAlias, sqlSchema, " AS ", aliasName);
			}
		} else {
			ZEPHIR_CPY_WRT(sqlTableAlias, sqlSchema);
		}
		RETURN_CCTOR(sqlTableAlias);
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CONCAT_VVV(return_value, escapeChar, table, escapeChar);
		RETURN_MM();
	}
	RETURN_CCTOR(table);

}

/**
 * Builds a SELECT statement
 *
 * @param array definition
 * @return string
 */
PHP_METHOD(Pdm_Db_AbstractDialect, select) {

	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_6, *_11, *_16, *_22, *_26;
	HashPosition _1, _5, _10, _15, _21, _25;
	zval *definition, *tables, *columns = NULL, *escapeChar = NULL, *columnItem = NULL, *column = NULL, *selectedColumns, *columnSql = NULL, *columnDomainSql = NULL, *columnAlias = NULL, *selectedTables, *sqlJoin = NULL, *joinExpressions = NULL, *joinCondition = NULL, *joinConditionsArray = NULL, *tablesSql = NULL, *columnDomain = NULL, *columnAliasSql = NULL, *columnsSql = NULL, *table = NULL, *sql, *joins, *join = NULL, *sqlTable = NULL, *whereConditions, *groupFields, *groupField = NULL, *groupItems, *havingConditions, *orderFields, *orderItem = NULL, *orderItems, *orderSqlItem = NULL, *sqlOrderType = NULL, *orderSqlItemType = NULL, *limitValue, *number, *offset, *_0, **_3, **_7, *_8 = NULL, **_12, *_13, *_14, **_17, *_18 = NULL, *_19 = NULL, *_20 = NULL, **_23, *_24 = NULL, **_27, *_28, *_29;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition);



	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "Invalid SELECT definition", "pdm/db/abstractdialect.zep", 375);
		return;
	}
	ZEPHIR_OBS_VAR(tables);
	if (!(zephir_array_isset_string_fetch(&tables, definition, SS("tables"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "The index 'tables' is required in the definition array", "pdm/db/abstractdialect.zep", 379);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_db_exception_ce, "The index 'columns' is required in the definition array", "pdm/db/abstractdialect.zep", 383);
		return;
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("escapeChar"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(escapeChar, _0);
	} else {
		ZEPHIR_INIT_VAR(escapeChar);
		ZVAL_NULL(escapeChar);
	}
	ZEPHIR_OBS_NVAR(columns);
	zephir_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(columns) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(selectedColumns);
		array_init(selectedColumns);
		zephir_is_iterable(columns, &_2, &_1, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(column, _3);
			ZEPHIR_OBS_NVAR(columnItem);
			zephir_array_fetch_long(&columnItem, column, 0, PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(columnItem) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(&columnSql, this_ptr, "getsqlexpression", &_4, columnItem, escapeChar);
				zephir_check_call_status();
			} else {
				if (ZEPHIR_IS_STRING(columnItem, "*")) {
					ZEPHIR_CPY_WRT(columnSql, columnItem);
				} else {
					if (ZEPHIR_GLOBAL(db).escape_identifiers) {
						ZEPHIR_INIT_NVAR(columnSql);
						ZEPHIR_CONCAT_VVV(columnSql, escapeChar, columnItem, escapeChar);
					} else {
						ZEPHIR_CPY_WRT(columnSql, columnItem);
					}
				}
			}
			ZEPHIR_OBS_NVAR(columnDomain);
			if (zephir_array_isset_long_fetch(&columnDomain, column, 1, 0 TSRMLS_CC)) {
				if (zephir_is_true(columnDomain)) {
					ZEPHIR_INIT_NVAR(columnDomainSql);
					if (ZEPHIR_GLOBAL(db).escape_identifiers) {
						ZEPHIR_CONCAT_VVVSV(columnDomainSql, escapeChar, columnDomain, escapeChar, ".", columnSql);
					} else {
						ZEPHIR_CONCAT_VSV(columnDomainSql, columnDomain, ".", columnSql);
					}
				} else {
					ZEPHIR_CPY_WRT(columnDomainSql, columnSql);
				}
			} else {
				ZEPHIR_CPY_WRT(columnDomainSql, columnSql);
			}
			ZEPHIR_OBS_NVAR(columnAlias);
			if (zephir_array_isset_long_fetch(&columnAlias, column, 2, 0 TSRMLS_CC)) {
				if (zephir_is_true(columnAlias)) {
					ZEPHIR_INIT_NVAR(columnAliasSql);
					if (ZEPHIR_GLOBAL(db).escape_identifiers) {
						ZEPHIR_CONCAT_VSVVV(columnAliasSql, columnDomainSql, " AS ", escapeChar, columnAlias, escapeChar);
					} else {
						ZEPHIR_CONCAT_VSV(columnAliasSql, columnDomainSql, " AS ", columnAlias);
					}
				} else {
					ZEPHIR_CPY_WRT(columnAliasSql, columnDomainSql);
				}
			} else {
				ZEPHIR_CPY_WRT(columnAliasSql, columnDomainSql);
			}
			zephir_array_append(&selectedColumns, columnAliasSql, PH_SEPARATE);
		}
		ZEPHIR_INIT_VAR(columnsSql);
		zephir_fast_join_str(columnsSql, SL(", "), selectedColumns TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(columnsSql, columns);
	}
	if (Z_TYPE_P(tables) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(selectedTables);
		array_init(selectedTables);
		zephir_is_iterable(tables, &_6, &_5, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(table, _7);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqltable", &_9, table, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&selectedTables, _8, PH_SEPARATE);
		}
		ZEPHIR_INIT_VAR(tablesSql);
		zephir_fast_join_str(tablesSql, SL(", "), selectedTables TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(tablesSql, tables);
	}
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSV(sql, "SELECT ", columnsSql, " FROM ", tablesSql);
	ZEPHIR_OBS_VAR(joins);
	if (zephir_array_isset_string_fetch(&joins, definition, SS("joins"), 0 TSRMLS_CC)) {
		zephir_is_iterable(joins, &_11, &_10, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(join, _12);
			zephir_array_fetch_string(&_13, join, SL("source"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&sqlTable, this_ptr, "getsqltable", &_9, _13, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&selectedTables, sqlTable, PH_SEPARATE);
			zephir_array_fetch_string(&_14, join, SL("type"), PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_INIT_NVAR(sqlJoin);
			ZEPHIR_CONCAT_SVSV(sqlJoin, " ", _14, " JOIN ", sqlTable);
			ZEPHIR_OBS_NVAR(joinConditionsArray);
			if (zephir_array_isset_string_fetch(&joinConditionsArray, join, SS("conditions"), 0 TSRMLS_CC)) {
				if (zephir_fast_count_int(joinConditionsArray TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(joinExpressions);
					array_init(joinExpressions);
					zephir_is_iterable(joinConditionsArray, &_16, &_15, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
					  ; zephir_hash_move_forward_ex(_16, &_15)
					) {
						ZEPHIR_GET_HVALUE(joinCondition, _17);
						ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_4, joinCondition, escapeChar);
						zephir_check_call_status();
						zephir_array_append(&joinExpressions, _8, PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_18);
					zephir_fast_join_str(_18, SL(" AND "), joinExpressions TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_19);
					ZEPHIR_CONCAT_SVS(_19, " ON ", _18, " ");
					zephir_concat_self(&sqlJoin, _19 TSRMLS_CC);
				}
			}
			zephir_concat_self(&sql, sqlJoin TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, definition, SS("where"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(whereConditions) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_4, whereConditions, escapeChar);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_19);
			ZEPHIR_CONCAT_SV(_19, " WHERE ", _8);
			zephir_concat_self(&sql, _19 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_20);
			ZEPHIR_CONCAT_SV(_20, " WHERE ", whereConditions);
			zephir_concat_self(&sql, _20 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(groupFields);
	if (zephir_array_isset_string_fetch(&groupFields, definition, SS("group"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(groupItems);
		array_init(groupItems);
		zephir_is_iterable(groupFields, &_22, &_21, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_22, (void**) &_23, &_21) == SUCCESS
		  ; zephir_hash_move_forward_ex(_22, &_21)
		) {
			ZEPHIR_GET_HVALUE(groupField, _23);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_4, groupField, escapeChar);
			zephir_check_call_status();
			zephir_array_append(&groupItems, _8, PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(_18);
		zephir_fast_join_str(_18, SL(", "), groupItems TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_20);
		ZEPHIR_CONCAT_SV(_20, " GROUP BY ", _18);
		zephir_concat_self(&sql, _20 TSRMLS_CC);
		ZEPHIR_OBS_VAR(havingConditions);
		if (zephir_array_isset_string_fetch(&havingConditions, definition, SS("having"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "getsqlexpression", &_4, havingConditions, escapeChar);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_24);
			ZEPHIR_CONCAT_SV(_24, " HAVING ", _8);
			zephir_concat_self(&sql, _24 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(orderFields);
	if (zephir_array_isset_string_fetch(&orderFields, definition, SS("order"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(orderItems);
		array_init(orderItems);
		zephir_is_iterable(orderFields, &_26, &_25, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_26, (void**) &_27, &_25) == SUCCESS
		  ; zephir_hash_move_forward_ex(_26, &_25)
		) {
			ZEPHIR_GET_HVALUE(orderItem, _27);
			zephir_array_fetch_long(&_13, orderItem, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&orderSqlItem, this_ptr, "getsqlexpression", &_4, _13, escapeChar);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(sqlOrderType);
			if (zephir_array_isset_long_fetch(&sqlOrderType, orderItem, 1, 0 TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(orderSqlItemType);
				ZEPHIR_CONCAT_VSV(orderSqlItemType, orderSqlItem, " ", sqlOrderType);
			} else {
				ZEPHIR_CPY_WRT(orderSqlItemType, orderSqlItem);
			}
			zephir_array_append(&orderItems, orderSqlItemType, PH_SEPARATE);
		}
		ZEPHIR_INIT_VAR(_28);
		zephir_fast_join_str(_28, SL(", "), orderItems TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_20);
		ZEPHIR_CONCAT_SV(_20, " ORDER BY ", _28);
		zephir_concat_self(&sql, _20 TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&limitValue, definition, SS("limit"), 1 TSRMLS_CC)) {
		if (Z_TYPE_P(limitValue) == IS_ARRAY) {
			zephir_array_fetch_string(&_13, limitValue, SL("number"), PH_NOISY | PH_READONLY TSRMLS_CC);
			zephir_array_fetch_string(&number, _13, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
			if (zephir_array_isset_string_fetch(&offset, limitValue, SS("offset"), 1 TSRMLS_CC)) {
				zephir_array_fetch_string(&_14, offset, SL("value"), PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_24);
				ZEPHIR_CONCAT_SVSV(_24, " LIMIT ", number, " OFFSET ", _14);
				zephir_concat_self(&sql, _24 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_29);
				ZEPHIR_CONCAT_SV(_29, " LIMIT ", number);
				zephir_concat_self(&sql, _29 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_SV(_20, " LIMIT ", limitValue);
			zephir_concat_self(&sql, _20 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

