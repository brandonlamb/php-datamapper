
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Pdm_Db_Profiler) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Db, Profiler, pdm, db_profiler, pdm_db_profiler_method_entry, 0);

	/**
	 * Is the profiler active?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(pdm_db_profiler_ce, SL("active"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Retained profiles.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_db_profiler_ce, SL("profiles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(pdm_db_profiler_ce TSRMLS_CC, 1, pdm_db_profilerinterface_ce);
	return SUCCESS;

}

/**
 * Turns the profiler on and off.
 *
 * @param bool $active True to turn on, false to turn off.
 * @return ProfilerInterface
 */
PHP_METHOD(Pdm_Db_Profiler, setActive) {

	zval *active_param = NULL;
	zend_bool active;

	zephir_fetch_params(0, 1, 0, &active_param);

	if (unlikely(Z_TYPE_P(active_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'active' must be a bool") TSRMLS_CC);
		RETURN_NULL();
	}

	active = Z_BVAL_P(active_param);


	zephir_update_property_this(this_ptr, SL("active"), active ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Is the profiler active?
 *
 * @return bool
 */
PHP_METHOD(Pdm_Db_Profiler, isActive) {


	RETURN_MEMBER(this_ptr, "active");

}

/**
 * Adds a profile entry.
 *
 * @param float $duration The query duration.
 * @param string $functionName The PDO method that made the entry.
 * @param string $statement The SQL query statement.
 * @param array $bind_values The values bound to the statement.
 * @return ProfilerInterface
 */
PHP_METHOD(Pdm_Db_Profiler, addProfile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *bindValues = NULL, *_1;
	zval *functionName = NULL, *statement = NULL;
	zval *duration, *functionName_param = NULL, *statement_param = NULL, *bindValues_param = NULL, *e, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &duration, &functionName_param, &statement_param, &bindValues_param);

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
	if (!bindValues_param) {
		ZEPHIR_INIT_VAR(bindValues);
		array_init(bindValues);
	} else {
		zephir_get_arrval(bindValues, bindValues_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isactive",  NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(e);
	object_init_ex(e, zend_exception_get_default(TSRMLS_C));
	ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 7);
	zephir_array_update_string(&_1, SL("duration"), &duration, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("function"), &functionName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("statement"), &statement, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("bindValues"), &bindValues, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, e, "gettraceasstring",  NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("trace"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("profiles"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns all the profile entries.
 *
 * @return array
 */
PHP_METHOD(Pdm_Db_Profiler, getProfiles) {


	RETURN_MEMBER(this_ptr, "profiles");

}

PHP_METHOD(Pdm_Db_Profiler, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("profiles"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

