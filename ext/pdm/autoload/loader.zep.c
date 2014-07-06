
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/require.h"

ZEPHIR_INIT_CLASS(Pdm_Autoload_Loader) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Autoload, Loader, pdm, autoload_loader, pdm_autoload_loader_method_entry, 0);

	/**
	 * A map of explicit class names to their file paths.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_autoload_loader_ce, SL("classFiles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Debug information populated by loadClass().
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_autoload_loader_ce, SL("debug"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Classes, interfaces, and traits loaded by the autoloader; the key is
	 * the class name and the value is the file name.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_autoload_loader_ce, SL("loadedClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * A map of namespace prefixes to base directories.
	 *
	 * @var array
	 */
	zend_declare_property_null(pdm_autoload_loader_ce, SL("prefixes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Registers this autoloader with SPL.
 *
 * @param bool $prepend True to prepend to the autoload stack.
 * @return void
 */
PHP_METHOD(Pdm_Autoload_Loader, register) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *prepend_param = NULL, *_1;
	zend_bool prepend;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prepend_param);

	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadClass", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_register", NULL, _0, ZEPHIR_GLOBAL(global_true), (prepend ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Unregisters this autoloader from SPL.
 *
 * @return void
 */
PHP_METHOD(Pdm_Autoload_Loader, unregister) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "loadClass", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "spl_autoload_unregister", NULL, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the debugging information array from the last loadClass()
 * attempt.
 *
 * @return array
 */
PHP_METHOD(Pdm_Autoload_Loader, getDebug) {


	RETURN_MEMBER(this_ptr, "debug");

}

/**
 * Adds a base directory for a namespace prefix.
 *
 * @param string prefix The namespace prefix.
 * @param string|array baseDirs One or more base directories for the
 * namespace prefix.
 * @param bool $prepend If true, prepend the base directories to the
 * prefix instead of appending them; this causes them to be searched
 * first rather than last.
 * @return Loader
 */
PHP_METHOD(Pdm_Autoload_Loader, addPrefix) {

	HashTable *_6;
	HashPosition _5;
	zend_bool prepend;
	zval *prefix_param = NULL, *baseDirs = NULL, *prepend_param = NULL, *key = NULL, *baseDir = NULL, *_0, _1, *_2, *_3, *_4 = NULL, **_7, _8 = zval_used_for_init, *_9 = NULL, *_10, *_11;
	zval *prefix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &prefix_param, &baseDirs, &prepend_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		prefix = prefix_param;
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}
	ZEPHIR_SEPARATE_PARAM(prefix);
	ZEPHIR_SEPARATE_PARAM(baseDirs);
	if (!prepend_param) {
		prepend = 0;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\", 0);
	zephir_fast_trim(_0, prefix, &_1, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "\\");
	zephir_get_strval(prefix, _2);
	if (Z_TYPE_P(baseDirs) != IS_ARRAY) {
		if (unlikely(Z_TYPE_P(baseDirs) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "baseDirs must be string or array", "pdm/autoload/loader.zep", 100);
			return;
		}
		ZEPHIR_INIT_NVAR(baseDirs);
		array_init_size(baseDirs, 2);
		zephir_array_fast_append(baseDirs, baseDirs);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_3, prefix))) {
		ZEPHIR_INIT_VAR(_4);
		array_init(_4);
		zephir_update_property_array(this_ptr, SL("prefixes"), prefix, _4 TSRMLS_CC);
	}
	zephir_is_iterable(baseDirs, &_6, &_5, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(key, _6, _5);
		ZEPHIR_GET_HVALUE(baseDir, _7);
		ZEPHIR_INIT_NVAR(_4);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_trim(_4, baseDir, &_8, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_9);
		ZEPHIR_CONCAT_VS(_9, _4, "/");
		zephir_array_update_zval(&baseDirs, key, &_9, PH_COPY | PH_SEPARATE);
	}
	if (prepend) {
		ZEPHIR_INIT_NVAR(_4);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
		zephir_array_fetch(&_11, _10, prefix, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_fast_array_merge(_4, &(baseDirs), &(_11) TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("prefixes"), prefix, _4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_4);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
		zephir_array_fetch(&_11, _10, prefix, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_fast_array_merge(_4, &(_11), &(baseDirs) TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("prefixes"), prefix, _4 TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Sets all namespace prefixes and their base directories. This overwrites
 * the existing prefixes.
 *
 * @param array prefixes An associative array of namespace prefixes and
 * their base directories.
 * @return Loader
 */
PHP_METHOD(Pdm_Autoload_Loader, setPrefixes) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *prefixes_param = NULL, *key = NULL, *val = NULL, *_0, **_3;
	zval *prefixes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefixes_param);

	zephir_get_arrval(prefixes, prefixes_param);


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("prefixes"), _0 TSRMLS_CC);
	zephir_is_iterable(prefixes, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(val, _3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addprefix", &_4, key, val);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Returns the list of all class name prefixes and their base directories.
 *
 * @return array
 */
PHP_METHOD(Pdm_Autoload_Loader, getPrefixes) {


	RETURN_MEMBER(this_ptr, "prefixes");

}

/**
 * Sets the explicit file path for an explicit class name.
 *
 * @param string className The explicit class name.
 * @param string file The file path to that class.
 * @return Loader
 */
PHP_METHOD(Pdm_Autoload_Loader, setClassFile) {

	zval *className_param = NULL, *file_param = NULL;
	zval *className = NULL, *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &file_param);

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
	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(file_param) == IS_STRING)) {
		file = file_param;
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}


	zephir_update_property_array(this_ptr, SL("classFiles"), className, file TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets all file paths for all class names; this overwrites all previous
 * explicit mappings.
 *
 * @param array $classFiles An array of class-to-file mappings where the
 * key is the class name and the value is the file path.
 * @return Loader
 */
PHP_METHOD(Pdm_Autoload_Loader, setClassFiles) {

	zval *classFiles_param = NULL;
	zval *classFiles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classFiles_param);

	zephir_get_arrval(classFiles, classFiles_param);


	zephir_update_property_this(this_ptr, SL("classFiles"), classFiles TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Adds file paths for class names to the existing explicit mappings.
 *
 * @param array $classFiles An array of class-to-file mappings where the
 * key is the class name and the value is the file path.
 * @return Loader
 */
PHP_METHOD(Pdm_Autoload_Loader, addClassFiles) {

	zval *classFiles_param = NULL, *_0, *_1;
	zval *classFiles = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classFiles_param);

	zephir_get_arrval(classFiles, classFiles_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("classFiles"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(classFiles) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("classFiles"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the list of explicit class names and their file paths.
 *
 * @return array
 */
PHP_METHOD(Pdm_Autoload_Loader, getClassFiles) {


	RETURN_MEMBER(this_ptr, "classFiles");

}

/**
 * Returns the list of classes, interfaces, and traits loaded by the
 * autoloader.
 *
 * @return array An array of key-value pairs where the key is the class
 * or interface name and the value is the file name.
 */
PHP_METHOD(Pdm_Autoload_Loader, getLoadedClasses) {


	RETURN_MEMBER(this_ptr, "loadedClasses");

}

/**
 * Loads the class file for a given class name.
 *
 * @param string $className The fully-qualified class name.
 * @return mixed The mapped file name on success, or boolean false on
 * failure.
 */
PHP_METHOD(Pdm_Autoload_Loader, loadClass) {

	zephir_fcall_cache_entry *_9 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *className_param = NULL, *file = NULL, *found = NULL, *prefix = NULL, *pos = NULL, *relativeClass = NULL, *_1 = NULL, *_2, *_3, *_4, _5 = zval_used_for_init, _7 = zval_used_for_init;
	zval *className = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

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


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "Loading $class", 1);
	zephir_array_fast_append(_0, _1);
	zephir_update_property_this(this_ptr, SL("debug"), _0 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("classFiles"), PH_NOISY_CC);
	if (zephir_array_isset(_2, className)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("classFiles"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(file);
		zephir_array_fetch(&file, _3, className, PH_NOISY TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&found, this_ptr, "requirefile", NULL, file);
		zephir_check_call_status();
		if (zephir_is_true(found)) {
			ZEPHIR_INIT_ZVAL_NREF(_4);
			ZVAL_STRING(_4, "Loaded from explicit: file", 1);
			zephir_update_property_array_append(this_ptr, SL("debug"), _4 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("loadedClasses"), className, file TSRMLS_CC);
			RETURN_CCTOR(file);
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_STRING(_3, "No explicit class file", 1);
	zephir_update_property_array_append(this_ptr, SL("debug"), _3 TSRMLS_CC);
	ZEPHIR_CPY_WRT(prefix, className);
	while (1) {
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "\\", 0);
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_6, prefix, &_5);
		zephir_check_call_status();
		if (!(zephir_is_true(pos))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, (zephir_get_numberval(pos) + 1));
		ZEPHIR_CALL_FUNCTION(&prefix, "substr", &_8, className, &_5, &_7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, (zephir_get_numberval(pos) + 1));
		ZEPHIR_CALL_FUNCTION(&relativeClass, "substr", &_8, className, &_5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&file, this_ptr, "loadfile", &_9, prefix, relativeClass);
		zephir_check_call_status();
		if (zephir_is_true(file)) {
			ZEPHIR_INIT_ZVAL_NREF(_3);
			ZVAL_STRING(_3, "Loaded from prefix: file", 1);
			zephir_update_property_array_append(this_ptr, SL("debug"), _3 TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("loadedClasses"), className, file TSRMLS_CC);
			RETURN_CCTOR(file);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_STRING(&_5, "\\", 0);
		zephir_fast_trim(_1, prefix, &_5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_CPY_WRT(prefix, _1);
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_VS(_10, className, " not loaded");
	zephir_update_property_array_append(this_ptr, SL("debug"), _10 TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

/**
 * Load the mapped file for a namespace prefix and relative class.
 *
 * @param string prefix The namespace prefix.
 * @param string relativeClass The relative class name.
 * @return mixed Boolean false if no mapped file can be loaded, or the
 * name of the mapped file that was loaded.
 */
PHP_METHOD(Pdm_Autoload_Loader, loadFile) {

	zephir_fcall_cache_entry *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_4;
	HashPosition _3;
	zval *prefix_param = NULL, *relativeClass_param = NULL, *baseDir = NULL, *file = NULL, *_0, *_1, *_2, **_5, *_6 = NULL, _7 = zval_used_for_init, _8 = zval_used_for_init, *_9 = NULL, *_11;
	zval *prefix = NULL, *relativeClass = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &relativeClass_param);

	if (unlikely(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(prefix_param) == IS_STRING)) {
		prefix = prefix_param;
	} else {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}
	if (unlikely(Z_TYPE_P(relativeClass_param) != IS_STRING && Z_TYPE_P(relativeClass_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'relativeClass' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(relativeClass_param) == IS_STRING)) {
		relativeClass = relativeClass_param;
	} else {
		ZEPHIR_INIT_VAR(relativeClass);
		ZVAL_EMPTY_STRING(relativeClass);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, prefix))) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_STRING(_1, "prefix: no base dirs", 1);
		zephir_update_property_array_append(this_ptr, SL("debug"), _1 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefixes"), PH_NOISY_CC);
	zephir_array_fetch(&_2, _1, prefix, PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_is_iterable(_2, &_4, &_3, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(baseDir, _5);
		ZEPHIR_INIT_NVAR(_6);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_STRING(&_7, "\\", 0);
		ZEPHIR_SINIT_NVAR(_8);
		ZVAL_STRING(&_8, "/", 0);
		zephir_fast_str_replace(_6, &_7, &_8, relativeClass);
		ZEPHIR_INIT_NVAR(file);
		ZEPHIR_CONCAT_VVS(file, baseDir, _6, ".php");
		ZEPHIR_CALL_METHOD(&_9, this_ptr, "requirefile", &_10, file);
		zephir_check_call_status();
		if (zephir_is_true(_9)) {
			RETURN_CCTOR(file);
		}
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZVAL_STRING(_11, "prefix: file not found", 1);
		zephir_update_property_array_append(this_ptr, SL("debug"), _11 TSRMLS_CC);
	}
	RETURN_MM_BOOL(0);

}

/**
 * If a file exists, require it from the file system.
 *
 * @param string file The file to require.
 * @return bool True if the file exists, false if not.
 */
PHP_METHOD(Pdm_Autoload_Loader, requireFile) {

	zval *file_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(file_param) == IS_STRING)) {
		file = file_param;
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}


	if ((zephir_file_exists(file TSRMLS_CC) == SUCCESS)) {
		if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Pdm_Autoload_Loader, __construct) {

	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("classFiles"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("debug"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("loadedClasses"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("prefixes"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

