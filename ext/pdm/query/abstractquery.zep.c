
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"

ZEPHIR_INIT_CLASS(Pdm_Query_AbstractQuery) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Query, AbstractQuery, pdm, query_abstractquery, pdm_query_abstractquery_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Data to be bound to the query.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_abstractquery_ce, SL("bindValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The list of WHERE conditions.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_abstractquery_ce, SL("where"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Bind these values to the WHERE conditions.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_abstractquery_ce, SL("bindWhere"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ORDER BY these columns.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_abstractquery_ce, SL("orderBy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The number of rows to select
	 *
	 * @var int
	 */
	zend_declare_property_long(pdm_query_abstractquery_ce, SL("limit"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Return rows after this offset.
	 *
	 * @var int
	 */
	zend_declare_property_long(pdm_query_abstractquery_ce, SL("offset"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The list of flags.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_abstractquery_ce, SL("flags"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * The number of rows to select
 *
 * @var int
 */
PHP_METHOD(Pdm_Query_AbstractQuery, getLimit) {


	RETURN_MEMBER(this_ptr, "limit");

}

/**
 * Return rows after this offset.
 *
 * @var int
 */
PHP_METHOD(Pdm_Query_AbstractQuery, getOffset) {


	RETURN_MEMBER(this_ptr, "offset");

}

/**
 * Returns this query object as a string.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "build", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Gets the values to bind to placeholders.
 *
 * @return array
 *
 */
PHP_METHOD(Pdm_Query_AbstractQuery, getBindValuesx) {


	RETURN_MEMBER(this_ptr, "bindValues");

}

/**
 * Binds multiple values to placeholders; merges with existing values.
 *
 * @param array $bindValues Values to bind to placeholders.
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, bindValues) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *bindValues, *key = NULL, *val = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bindValues);



	if (Z_TYPE_P(bindValues) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "bindValues must be array.", "pdm/query/abstractquery.zep", 102);
		return;
	}
	zephir_is_iterable(bindValues, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bindvalue", &_3, key, val);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Binds a single value to the query.
 *
 * @param string $name The placeholder name or number.
 * @param mixed $value The value to bind to the placeholder.
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, bindValue) {

	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

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


	zephir_update_property_array(this_ptr, SL("bindValues"), name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Builds this query object into a string.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, build) {

}

/**
 * Returns an array as an indented comma-separated values string.
 *
 * @param array $list The values to convert.
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, indentCsv) {

	zval *list, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &list);



	if (Z_TYPE_P(list) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "list must be array.", "pdm/query/abstractquery.zep", 141);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, ",", _2, "    ");
	zephir_fast_join(_1, _3, list TSRMLS_CC);
	ZEPHIR_CONCAT_VSV(return_value, _0, "    ", _1);
	RETURN_MM();

}

/**
 * Returns an array as an indented string.
 *
 * @param array $list The values to convert.
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, indent) {

	zval *list, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &list);



	if (Z_TYPE_P(list) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "list must be array.", "pdm/query/abstractquery.zep", 155);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, "    ");
	zephir_fast_join(_1, _3, list TSRMLS_CC);
	ZEPHIR_CONCAT_VSV(return_value, _0, "    ", _1);
	RETURN_MM();

}

/**
 * Sets or unsets specified flag.
 *
 * @param string $flag Flag to set or unset
 * @param bool $enable Flag status - enabled or not (default true)
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, setFlag) {

	zend_bool enable;
	zval *flag_param = NULL, *enable_param = NULL, *_0;
	zval *flag = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &flag_param, &enable_param);

	if (unlikely(Z_TYPE_P(flag_param) != IS_STRING && Z_TYPE_P(flag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'flag' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(flag_param) == IS_STRING)) {
		flag = flag_param;
	} else {
		ZEPHIR_INIT_VAR(flag);
		ZVAL_EMPTY_STRING(flag);
	}
	if (!enable_param) {
		enable = 1;
	} else {
		enable = zephir_get_boolval(enable_param);
	}


	if (enable) {
		zephir_update_property_array(this_ptr, SL("flags"), flag, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("flags"), PH_NOISY_CC);
		zephir_array_unset(&_0, flag, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * Reset all query flags.
 *
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, resetFlags) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("flags"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds a WHERE condition to the query by AND or OR. If the condition has
 * ?-placeholders, additional arguments to the method will be bound to
 * those placeholders sequentially.
 *
 * @param string $andor Add the condition using this operator, typically
 * 'AND' or 'OR'.
 * @param string $cond, condition
 * @param array $binds Arguments for adding the condition.
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, addWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *andor_param = NULL, *cond_param = NULL, *binds = NULL, *_1;
	zval *andor = NULL, *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &andor_param, &cond_param, &binds);

	if (unlikely(Z_TYPE_P(andor_param) != IS_STRING && Z_TYPE_P(andor_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'andor' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(andor_param) == IS_STRING)) {
		andor = andor_param;
	} else {
		ZEPHIR_INIT_VAR(andor);
		ZVAL_EMPTY_STRING(andor);
	}
	if (unlikely(Z_TYPE_P(cond_param) != IS_STRING && Z_TYPE_P(cond_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cond' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(cond_param) == IS_STRING)) {
		cond = cond_param;
	} else {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	}
	if (!binds) {
		ZEPHIR_INIT_VAR(binds);
		array_init(binds);
	}


	if (Z_TYPE_P(binds) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "binds must be array.", "pdm/query/abstractquery.zep", 202);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, cond);
	zephir_array_fast_append(_0, binds);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "where", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addclausecondwithbind", NULL, _1, andor, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds conditions and binds values to a clause.
 *
 * @param string $clause The clause to work with, typically 'where' or 'having'.
 * @param string $andor Add the condition using this operator, typically 'AND' or 'OR'.
 * @param array $args Arguments for adding the condition. $args = [$cond, $binds]
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, addClauseCondWithBind) {

	HashTable *_10;
	HashPosition _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_6 = NULL;
	zval *clause_param = NULL, *andor_param = NULL, *args, *cond = NULL, *binds, *bindName, *value = NULL, *clauses = NULL, *_0 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8, **_11, *_12 = NULL;
	zval *clause = NULL, *andor = NULL, *_2 = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &clause_param, &andor_param, &args);

	if (unlikely(Z_TYPE_P(clause_param) != IS_STRING && Z_TYPE_P(clause_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'clause' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(clause_param) == IS_STRING)) {
		clause = clause_param;
	} else {
		ZEPHIR_INIT_VAR(clause);
		ZVAL_EMPTY_STRING(clause);
	}
	if (unlikely(Z_TYPE_P(andor_param) != IS_STRING && Z_TYPE_P(andor_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'andor' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(andor_param) == IS_STRING)) {
		andor = andor_param;
	} else {
		ZEPHIR_INIT_VAR(andor);
		ZVAL_EMPTY_STRING(andor);
	}


	if (Z_TYPE_P(args) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "args must be array.", "pdm/query/abstractquery.zep", 220);
		return;
	}
	Z_SET_ISREF_P(args);
	ZEPHIR_CALL_FUNCTION(&_0, "array_shift", &_1, args);
	Z_UNSET_ISREF_P(args);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(cond, _2);
	ZEPHIR_CALL_FUNCTION(&_3, "ucwords", &_4, clause);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindName);
	ZEPHIR_CONCAT_SV(bindName, "bind", _3);
	ZEPHIR_CALL_FUNCTION(&_5, "property_exists", &_6, this_ptr, bindName);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_OBS_VAR(binds);
		zephir_read_property_zval(&binds, this_ptr, bindName, PH_NOISY_CC);
		if (unlikely(Z_TYPE_P(binds) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(_7);
			object_init_ex(_7, spl_ce_RuntimeException);
			ZEPHIR_INIT_VAR(_8);
			ZEPHIR_CONCAT_VS(_8, bindName, " must be an array.");
			ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, _8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7, "pdm/query/abstractquery.zep", 232 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_is_iterable(args, &_10, &_9, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HVALUE(value, _11);
			zephir_array_append(&binds, value, PH_SEPARATE);
		}
		zephir_update_property_zval_zval(this_ptr, bindName, binds TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_VS(_7, bindName, " is not a property 1\n");
		zend_print_zval(_7, 0);
	}
	ZEPHIR_CALL_FUNCTION(&_12, "property_exists", &_6, this_ptr, clause);
	zephir_check_call_status();
	if (zephir_is_true(_12)) {
		ZEPHIR_OBS_VAR(clauses);
		zephir_read_property_zval(&clauses, this_ptr, clause, PH_NOISY_CC);
		if (Z_TYPE_P(clauses) != IS_ARRAY) {
			ZEPHIR_INIT_NVAR(clauses);
			array_init_size(clauses, 2);
			zephir_array_fast_append(clauses, clauses);
		}
		if (!(ZEPHIR_IS_EMPTY(clauses))) {
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_VSV(_7, andor, " ", cond);
			zephir_array_append(&clauses, _7, PH_SEPARATE);
		} else {
			zephir_array_append(&clauses, cond, PH_SEPARATE);
		}
		zephir_update_property_zval_zval(this_ptr, clause, clauses TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_13);
		ZEPHIR_CONCAT_VS(_13, clause, " is not a property 2\n");
		zend_print_zval(_13, 0);
	}
	RETURN_THIS();

}

/**
 * Adds a column order to the query.
 *
 * @param array $spec The columns and direction to order by.
 * @return QueryInterface
 */
PHP_METHOD(Pdm_Query_AbstractQuery, addOrderBy) {

	HashTable *_1;
	HashPosition _0;
	zval *spec, *col = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &spec);



	if (Z_TYPE_P(spec) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "spec must be array.", "pdm/query/abstractquery.zep", 275);
		return;
	}
	zephir_is_iterable(spec, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(col, _2);
		zephir_update_property_array_append(this_ptr, SL("orderBy"), col TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Builds the flags as a space-separated string.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, buildFlags) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("flags"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("flags"), PH_NOISY_CC);
	zephir_array_keys(_2, _3 TSRMLS_CC);
	zephir_fast_join_str(_1, SL(" "), _2 TSRMLS_CC);
	ZEPHIR_CONCAT_SV(return_value, " ", _1);
	RETURN_MM();

}

/**
 * Builds the `WHERE` clause of the statement.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, buildWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	if (unlikely(ZEPHIR_IS_EMPTY(_0))) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("where"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indent", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _1, "WHERE", _2);
	RETURN_MM();

}

/**
 * Builds the `ORDER BY ...` clause of the statement.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, buildOrderBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("orderBy"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indentcsv", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _1, "ORDER BY", _2);
	RETURN_MM();

}

/**
 * Builds the `LIMIT ... OFFSET` clause of the statement.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_AbstractQuery, buildLimit) {

	zval *clause, *_1, *_2 = NULL, *_3, *_4, *_5, *_6;
	zend_bool hasLimit, hasOffset, _0, _7;

	ZEPHIR_MM_GROW();

	hasLimit = zephir_instance_of_ev(this_ptr, pdm_query_common_limitinterface_ce TSRMLS_CC);
	hasOffset = zephir_instance_of_ev(this_ptr, pdm_query_common_limitoffsetinterface_ce TSRMLS_CC);
	_0 = hasOffset;
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
		_0 = zephir_is_true(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(clause);
		ZEPHIR_CONCAT_VSV(clause, _2, "LIMIT ", _3);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("offset"), PH_NOISY_CC);
		if (zephir_is_true(_4)) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("offset"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_SV(_6, " OFFSET ", _5);
			zephir_concat_self(&clause, _6 TSRMLS_CC);
		}
		RETURN_CCTOR(clause);
	} else {
		_7 = hasLimit;
		if (_7) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
			_7 = zephir_is_true(_3);
		}
		if (_7) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("limit"), PH_NOISY_CC);
			ZEPHIR_CONCAT_VSV(return_value, _2, "LIMIT ", _4);
			RETURN_MM();
		}
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Pdm_Query_AbstractQuery, __construct) {

	zval *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("bindValues"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("where"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("bindWhere"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("orderBy"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("flags"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

