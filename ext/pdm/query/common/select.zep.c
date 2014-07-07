
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Pdm_Query_Common_Select) {

	ZEPHIR_REGISTER_CLASS_EX(Pdm\\Query\\Common, Select, pdm, query_common_select, pdm_query_abstractquery_ce, pdm_query_common_select_method_entry, 0);

	/**
	 * An array of union SELECT statements.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_query_common_select_ce, SL("union"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * Is this a SELECT FOR UPDATE?
	 *
	 * @var
	 *
	 */
	zend_declare_property_bool(pdm_query_common_select_ce, SL("forUpdate"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The columns to be selected.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(pdm_query_common_select_ce, SL("select"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * Select from these tables; includes JOIN clauses.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(pdm_query_common_select_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The current key in the `$from` array.
	 *
	 * @var int
	 *
	 */
	zend_declare_property_long(pdm_query_common_select_ce, SL("fromKey"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * GROUP BY these columns.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(pdm_query_common_select_ce, SL("groupBy"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The list of HAVING conditions.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(pdm_query_common_select_ce, SL("having"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * Bind values in the HAVING clause.
	 *
	 * @var array
	 *
	 */
	zend_declare_property_null(pdm_query_common_select_ce, SL("bindHaving"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The number of rows per page.
	 *
	 * @var int
	 *
	 */
	zend_declare_property_long(pdm_query_common_select_ce, SL("paging"), 10, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_query_common_select_ce TSRMLS_CC, 1, pdm_query_common_selectinterface_ce);
	zend_class_implements(pdm_query_common_select_ce TSRMLS_CC, 1, pdm_query_queryinterface_ce);
	zend_class_implements(pdm_query_common_select_ce TSRMLS_CC, 1, pdm_query_common_orderbyinterface_ce);
	zend_class_implements(pdm_query_common_select_ce TSRMLS_CC, 1, pdm_query_common_limitoffsetinterface_ce);
	return SUCCESS;

}

/**
 *
 * Returns this object as an SQL statement string.
 *
 * @return string An SQL statement string.
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, __toString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("union"), PH_NOISY_CC);
	if (unlikely(!ZEPHIR_IS_EMPTY(_0))) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_GET_CONSTANT(_2, "PHP_EOL");
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("union"), PH_NOISY_CC);
		zephir_fast_join(_1, _2, _3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_GET_CONSTANT(_4, "PHP_EOL");
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "build",  NULL);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVV(return_value, _1, _4, _5);
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "build", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Sets the number of rows per page.
 *
 * @param int $paging The number of rows to page at.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, setPaging) {

	zval *paging_param = NULL, *_0;
	int paging;

	zephir_fetch_params(0, 1, 0, &paging_param);

	paging = zephir_get_intval(paging_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, paging);
	zephir_update_property_this(this_ptr, SL("paging"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 *
 * Gets the number of rows per page.
 *
 * @return int The number of rows per page.
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, getPaging) {


	RETURN_MEMBER(this_ptr, "paging");

}

/**
 *
 * Gets the values to bind to placeholders.
 *
 * @return array
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, getBindValues) {

	HashTable *_2, *_6;
	HashPosition _1, _5;
	int i;
	zval *bindValues = NULL, *val = NULL, *_0, **_3, *_4, **_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("bindValues"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(bindValues, _0);
	i = 1;
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("bindWhere"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(val, _3);
		zephir_array_update_long(&bindValues, i, &val, PH_COPY | PH_SEPARATE, "pdm/query/common/select.zep", 159);
		i++;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("bindHaving"), PH_NOISY_CC);
	zephir_is_iterable(_4, &_6, &_5, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(val, _7);
		zephir_array_update_long(&bindValues, i, &val, PH_COPY | PH_SEPARATE, "pdm/query/common/select.zep", 164);
		i++;
	}
	RETURN_CCTOR(bindValues);

}

/**
 *
 * Makes the select FOR UPDATE (or not).
 *
 * @param bool $enable Whether or not the SELECT is FOR UPDATE (default
 * true).
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, forUpdate) {

	zval *enable_param = NULL;
	zend_bool enable;

	zephir_fetch_params(0, 0, 1, &enable_param);

	if (!enable_param) {
		enable = 1;
	} else {
	if (unlikely(Z_TYPE_P(enable_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'enable' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}

	enable = Z_BVAL_P(enable_param);
	}


	zephir_update_property_this(this_ptr, SL("forUpdate"), enable ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 *
 * Makes the select DISTINCT (or not).
 *
 * @param bool $enable Whether or not the SELECT is DISTINCT (default
 * true).
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, distinct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *enable_param = NULL, *_0;
	zend_bool enable;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &enable_param);

	if (!enable_param) {
		enable = 1;
	} else {
	if (unlikely(Z_TYPE_P(enable_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'enable' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	enable = Z_BVAL_P(enable_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DISTINCT", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setflag", NULL, _0, (enable ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds columns to the query.
 *
 * Multiple calls to select() will append to the list of columns, not
 * overwrite the previous columns.
 *
 * @param array $select The column(s) to add to the query. The elements can be
 * any mix of these: `array("col", "col AS alias", "col" => "alias")`
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, select) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *select, *key = NULL, *val = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &select);



	zephir_is_iterable(select, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addcol", &_3, key, val);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 *
 * Adds a FROM table and columns to the query.
 *
 * @param string $spec The table specification; "foo" or "foo AS bar".
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, from) {

	zval *_0;
	zval *spec_param = NULL;
	zval *spec = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &spec_param);

	if (unlikely(Z_TYPE_P(spec_param) != IS_STRING && Z_TYPE_P(spec_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'spec' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(spec_param) == IS_STRING)) {
		spec = spec_param;
	} else {
		ZEPHIR_INIT_VAR(spec);
		ZVAL_EMPTY_STRING(spec);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	zephir_array_fast_append(_0, spec);
	zephir_update_property_array_append(this_ptr, SL("from"), _0 TSRMLS_CC);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("fromKey") TSRMLS_CC));
	RETURN_THIS();

}

/**
 *
 * Adds an aliased sub-select to the query.
 *
 * @param string|Select $spec If a Select object, use as the sub-select;
 * if a string, the sub-select string.
 *
 * @param string $name The alias name for the sub-select.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, fromSubSelect) {

	zval *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *name = NULL, *_0 = NULL;
	zval *spec, *name_param = NULL, _1, _2, *_3 = NULL, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &spec, &name_param);

	ZEPHIR_SEPARATE_PARAM(spec);
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


	ZEPHIR_INIT_BNVAR(spec);
	zephir_get_strval(_0, spec);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/^/m", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "        ", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", &_4, &_1, &_2, _0);
	zephir_check_call_status();
	zephir_fast_trim(spec, _3, NULL , ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 2);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_GET_CONSTANT(_7, "PHP_EOL");
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVSVVSV(_8, "(", _6, "        ", spec, _7, "    ) AS ", name);
	zephir_array_fast_append(_5, _8);
	zephir_update_property_array_append(this_ptr, SL("from"), _5 TSRMLS_CC);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("fromKey") TSRMLS_CC));
	RETURN_THIS();

}

/**
 *
 * Adds a JOIN table and columns to the query.
 *
 * @param string $type The join type: inner, left, natural, etc.
 *
 * @param string $spec The table specification; "foo" or "foo AS bar".
 *
 * @param string $cond Join on this condition.
 *
 * @return SelectInterface
 *
 * @throws Exception
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, join) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *spec_param = NULL, *cond = NULL, *join, *sql, *key, *_0, *_1, *_2, *_3 = NULL, *_4, *_5, *_6, *_7;
	zval *type = NULL, *spec = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type_param, &spec_param, &cond);

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
	if (unlikely(Z_TYPE_P(spec_param) != IS_STRING && Z_TYPE_P(spec_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'spec' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(spec_param) == IS_STRING)) {
		spec = spec_param;
	} else {
		ZEPHIR_INIT_VAR(spec);
		ZVAL_EMPTY_STRING(spec);
	}
	if (!cond) {
		ZEPHIR_CPY_WRT(cond, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(cond);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (unlikely(ZEPHIR_IS_EMPTY(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_query_exception_ce, "Cannot join() without from() first.", "pdm/query/common/select.zep", 282);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_trim(_2, type, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fast_strtoupper(_1, _2);
	ZEPHIR_INIT_VAR(join);
	ZEPHIR_CONCAT_VS(join, _1, " JOIN ");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "fixjoincondition", NULL, cond);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(cond, _3);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VVSV(_4, join, spec, " ", cond);
	zephir_fast_trim(sql, _4, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_OBS_VAR(key);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("fromKey"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&key, _5, _6, 0 TSRMLS_CC)) {
		zephir_array_append(&key, sql, PH_SEPARATE);
	} else {
		ZEPHIR_INIT_BNVAR(key);
		array_init_size(key, 2);
		zephir_array_fast_append(key, sql);
	}
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_this(&_7, this_ptr, SL("fromKey"), PH_NOISY_CC);
	zephir_update_property_array(this_ptr, SL("from"), _7, key TSRMLS_CC);
	RETURN_THIS();

}

/**
 *
 * Adds a INNER JOIN table and columns to the query.
 *
 * @param string $spec The table specification; "foo" or "foo AS bar".
 *
 * @param string $cond Join on this condition.
 *
 * @return SelectInterface
 *
 * @throws Exception
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, innerJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *spec_param = NULL, *cond_param = NULL, *_0;
	zval *spec = NULL, *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &spec_param, &cond_param);

	if (unlikely(Z_TYPE_P(spec_param) != IS_STRING && Z_TYPE_P(spec_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'spec' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(spec_param) == IS_STRING)) {
		spec = spec_param;
	} else {
		ZEPHIR_INIT_VAR(spec);
		ZVAL_EMPTY_STRING(spec);
	}
	if (!cond_param) {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	} else {
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
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "INNER", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, _0, spec, cond);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds a LEFT JOIN table and columns to the query.
 *
 * @param string $spec The table specification; "foo" or "foo AS bar".
 *
 * @param string $cond Join on this condition.
 *
 * @return SelectInterface
 *
 * @throws Exception
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, leftJoin) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *spec_param = NULL, *cond_param = NULL, *_0;
	zval *spec = NULL, *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &spec_param, &cond_param);

	if (unlikely(Z_TYPE_P(spec_param) != IS_STRING && Z_TYPE_P(spec_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'spec' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(spec_param) == IS_STRING)) {
		spec = spec_param;
	} else {
		ZEPHIR_INIT_VAR(spec);
		ZVAL_EMPTY_STRING(spec);
	}
	if (!cond_param) {
		ZEPHIR_INIT_VAR(cond);
		ZVAL_EMPTY_STRING(cond);
	} else {
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
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "LEFT", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, _0, spec, cond);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds a JOIN to an aliased subselect and columns to the query.
 *
 * @param string $type The join type: inner, left, natural, etc.
 *
 * @param string|Select $spec If a Select
 * object, use as the sub-select; if a string, the sub-select
 * command string.
 *
 * @param string $name The alias name for the sub-select.
 *
 * @param string $cond Join on this condition.
 *
 * @return SelectInterface
 *
 * @throws Exception
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, joinSubSelect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL;
	zval *type_param = NULL, *spec, *name_param = NULL, *cond = NULL, *join, *sql, *key, *_0, *_1, *_2, *_3, *_4, _6, _7, *_8 = NULL, *_10, *_11 = NULL, *_12, *_13, *_14, *_15;
	zval *type = NULL, *name = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &type_param, &spec, &name_param, &cond);

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
	ZEPHIR_SEPARATE_PARAM(spec);
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
	if (!cond) {
		ZEPHIR_CPY_WRT(cond, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(cond);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (unlikely(ZEPHIR_IS_EMPTY(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_query_exception_ce, "Cannot join() without from() first.", "pdm/query/common/select.zep", 360);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_trim(_2, type, NULL , ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_fast_strtoupper(_1, _2);
	ZEPHIR_INIT_VAR(join);
	ZEPHIR_CONCAT_VS(join, _1, " JOIN");
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "PHP_EOL");
	ZEPHIR_INIT_VAR(_4);
	zephir_get_strval(_5, spec);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "/^/m", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "    ", 0);
	ZEPHIR_CALL_FUNCTION(&_8, "preg_replace", &_9, &_6, &_7, _5);
	zephir_check_call_status();
	zephir_fast_trim(_4, _8, NULL , ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_GET_CONSTANT(_10, "PHP_EOL");
	ZEPHIR_INIT_BNVAR(spec);
	ZEPHIR_CONCAT_VSVV(spec, _3, "    ", _4, _10);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "fixjoincondition", NULL, cond);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(cond, _11);
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_VSVSVSV(_12, join, " (", spec, ") AS ", name, " ", cond);
	zephir_fast_trim(sql, _12, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_OBS_VAR(key);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("fromKey"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&key, _13, _14, 0 TSRMLS_CC)) {
		zephir_array_append(&key, sql, PH_SEPARATE);
	} else {
		ZEPHIR_INIT_BNVAR(key);
		array_init_size(key, 2);
		zephir_array_fast_append(key, sql);
	}
	ZEPHIR_OBS_VAR(_15);
	zephir_read_property_this(&_15, this_ptr, SL("fromKey"), PH_NOISY_CC);
	zephir_update_property_array(this_ptr, SL("from"), _15, key TSRMLS_CC);
	RETURN_THIS();

}

/**
 *
 * Adds grouping to the query.
 *
 * @param array $spec The column(s) to group by.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, groupBy) {

	HashTable *_1;
	HashPosition _0;
	zval *spec, *col = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &spec);



	if (Z_TYPE_P(spec) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "spec must be array.", "pdm/query/common/select.zep", 393);
		return;
	}
	zephir_is_iterable(spec, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(col, _2);
		zephir_update_property_array_append(this_ptr, SL("groupBy"), col TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 *
 * Adds a HAVING condition to the query by AND. If the condition has
 * ?-placeholders, additional arguments to the method will be bound to
 * those placeholders sequentially.
 *
 * @param string $cond The HAVING condition.
 * @param array $binds
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, having) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cond_param = NULL, *binds = NULL, *_0, *_1;
	zval *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &cond_param, &binds);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "binds must be array.", "pdm/query/common/select.zep", 417);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "having", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "AND", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addclausecondwithbind", NULL, _0, _1, binds);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds a HAVING condition to the query by AND. If the condition has
 * ?-placeholders, additional arguments to the method will be bound to
 * those placeholders sequentially.
 *
 * @param string $cond The HAVING condition.
 *
 * @return SelectInterface
 *
 * @see having()
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, orHaving) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cond_param = NULL, *binds = NULL, *_0, *_1;
	zval *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &cond_param, &binds);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "binds must be array.", "pdm/query/common/select.zep", 438);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "having", 0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "OR", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addclausecondwithbind", NULL, _0, _1, binds);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Sets the limit and count by page number.
 *
 * @param int $page Limit results to this page number.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, page) {

	zval *page_param = NULL, *_0, *_1, *_2;
	int page;

	zephir_fetch_params(0, 1, 0, &page_param);

	page = zephir_get_intval(page_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("limit"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("offset"), _0 TSRMLS_CC);
	page = page;
	if (page > 0) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("paging"), PH_NOISY_CC);
		zephir_update_property_this(this_ptr, SL("limit"), _0 TSRMLS_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("paging"), PH_NOISY_CC);
		ZEPHIR_INIT_ZVAL_NREF(_2);
		ZVAL_LONG(_2, (zephir_get_numberval(_1) * ((page - 1))));
		zephir_update_property_this(this_ptr, SL("offset"), _2 TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 *
 * Takes the current select properties and retains them, then sets
 * UNION for the next set of properties.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, union) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "build",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VVS(_2, _0, _1, "UNION");
	zephir_update_property_array_append(this_ptr, SL("union"), _2 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "reset", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Takes the current select properties and retains them, then sets
 * UNION ALL for the next set of properties.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, unionAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "build",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VVS(_2, _0, _1, "UNION ALL");
	zephir_update_property_array_append(this_ptr, SL("union"), _2 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "reset", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds a WHERE condition to the query by AND. If the condition has
 * ?-placeholders, additional arguments to the method will be bound to
 * those placeholders sequentially.
 *
 * @param string $cond The WHERE condition.
 * @param array $binds arguments to bind to placeholders
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, where) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cond_param = NULL, *binds = NULL, *_0;
	zval *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &cond_param, &binds);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "binds must be array.", "pdm/query/common/select.zep", 512);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AND", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addwhere", NULL, _0, cond, binds);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds a WHERE condition to the query by OR. If the condition has
 * ?-placeholders, additional arguments to the method will be bound to
 * those placeholders sequentially.
 *
 * @param string $cond The WHERE condition.
 * @param array $binds arguments to bind to placeholders
 *
 * @return SelectInterface
 *
 * @see where()
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, orWhere) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cond_param = NULL, *binds = NULL, *_0;
	zval *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &cond_param, &binds);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "binds must be array.", "pdm/query/common/select.zep", 534);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "OR", 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addwhere", NULL, _0, cond, binds);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Sets a limit count on the query.
 *
 * @param int $limit The number of rows to select.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, limit) {

	zval *limit_param = NULL, *_0;
	int limit;

	zephir_fetch_params(0, 1, 0, &limit_param);

	limit = zephir_get_intval(limit_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, limit);
	zephir_update_property_this(this_ptr, SL("limit"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 *
 * Sets a limit offset on the query.
 *
 * @param int $offset Start returning after this many rows.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, offset) {

	zval *offset_param = NULL, *_0;
	int offset;

	zephir_fetch_params(0, 1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, offset);
	zephir_update_property_this(this_ptr, SL("offset"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 *
 * Adds a column order to the query.
 *
 * @param array $spec The columns and direction to order by.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, orderBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *spec;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &spec);



	if (Z_TYPE_P(spec) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "spec must be array.", "pdm/query/common/select.zep", 581);
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addorderby", NULL, spec);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Adds a column and alias to the columsn to be selected.
 *
 * @param mixed $key If an integer, ignored. Otherwise, the column to be
 * added.
 *
 * @param mixed $val If $key was an integer, the column to be added;
 * otherwise, the column alias.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, addCol) {

	zval *key, *val, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key, &val);



	if (Z_TYPE_P(key) == IS_LONG) {
		zephir_update_property_array_append(this_ptr, SL("select"), val TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, key, " AS ", val);
		zephir_update_property_array_append(this_ptr, SL("select"), _0 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 *
 * Fixes a JOIN condition to quote names in the condition and prefix it
 * with a condition type ('ON' is the default and 'USING' is recognized).
 *
 * @param string $cond Join on this condition.
 *
 * @return string
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, fixJoinCondition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *cond_param = NULL, *cond2, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL;
	zval *cond = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cond_param);

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


	if (unlikely(ZEPHIR_IS_STRING(cond, ""))) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(cond2);
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, cond, NULL , ZEPHIR_TRIM_LEFT TSRMLS_CC);
	zephir_fast_strtoupper(cond2, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_FUNCTION(&_3, "substr", &_4, cond2, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_3, "ON ")) {
		RETURN_CTOR(cond);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 6);
	ZEPHIR_CALL_FUNCTION(&_5, "substr", &_4, cond2, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(_5, "USING ")) {
		RETURN_CTOR(cond);
	}
	ZEPHIR_CONCAT_SV(return_value, "ON ", cond);
	RETURN_MM();

}

/**
 *
 * Clears the current select properties; generally used after adding a
 * union.
 *
 * @return SelectInterface
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, reset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("select"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("from"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, -1);
	zephir_update_property_this(this_ptr, SL("fromKey"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("where"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("groupBy"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("having"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("orderBy"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, 0);
	zephir_update_property_this(this_ptr, SL("limit"), _2 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, 0);
	zephir_update_property_this(this_ptr, SL("offset"), _2 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("forUpdate"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "resetflags", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Builds this query object into a string.
 *
 * @return string
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, build) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "buildflags",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "buildselect",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "buildfrom",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "buildwhere",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "buildgroupby",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "buildhaving",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "buildorderby",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "buildlimit",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "buildforupdate",  NULL);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVVVVVVVVV(return_value, "SELECT", _0, _1, _2, _3, _4, _5, _6, _7, _8);
	RETURN_MM();

}

/**
 *
 * Builds the columns clause.
 *
 * @return string
 *
 * @throws Exception when there are no columns in the SELECT.
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, buildSelect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("select"), PH_NOISY_CC);
	if (unlikely(ZEPHIR_IS_EMPTY(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pdm_query_exception_ce, "No columns in the SELECT.", "pdm/query/common/select.zep", 698);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("select"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "indentcsv", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * Builds the FROM clause.
 *
 * @return string
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, buildFrom) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zval *refs, *from = NULL, *_0, *_1, **_4, *_5 = NULL, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(refs);
	array_init(refs);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(from, _4);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
		zephir_fast_join(_5, _6, from TSRMLS_CC);
		zephir_array_append(&refs, _5, PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "PHP_EOL");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "indentcsv", NULL, refs);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _5, "FROM", _7);
	RETURN_MM();

}

/**
 *
 * Builds the GROUP BY clause.
 *
 * @return string
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, buildGroupBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("groupBy"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("groupBy"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indentcsv", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _1, "GROUP BY", _2);
	RETURN_MM();

}

/**
 *
 * Builds the HAVING clause.
 *
 * @return string
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, buildHaving) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("having"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("having"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indent", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, _1, "HAVING", _2);
	RETURN_MM();

}

/**
 *
 * Builds the FOR UPDATE clause.
 *
 * @return string
 *
 */
PHP_METHOD(Pdm_Query_Common_Select, buildForUpdate) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("forUpdate"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "PHP_EOL");
	ZEPHIR_CONCAT_VS(return_value, _1, "FOR UPDATE");
	RETURN_MM();

}

PHP_METHOD(Pdm_Query_Common_Select, __construct) {

	zval *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10;

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
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("union"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("select"), _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	array_init(_7);
	zephir_update_property_this(this_ptr, SL("from"), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	array_init(_8);
	zephir_update_property_this(this_ptr, SL("groupBy"), _8 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	array_init(_9);
	zephir_update_property_this(this_ptr, SL("having"), _9 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	array_init(_10);
	zephir_update_property_this(this_ptr, SL("bindHaving"), _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

