
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * A quoting mechanism for identifier names (not values).
 *
 * @package \Pdm\Query
 */
ZEPHIR_INIT_CLASS(Pdm_Query_Quoter) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Query, Quoter, pdm, query_quoter, pdm_query_quoter_method_entry, 0);

	/**
	 * The prefix to use when quoting identifier names.
	 *
	 * @var string
	 */
	zend_declare_property_string(pdm_query_quoter_ce, SL("quoteNamePrefix"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 *
	 * The suffix to use when quoting identifier names.
	 *
	 * @var string
	 *
	 */
	zend_declare_property_string(pdm_query_quoter_ce, SL("quoteNameSuffix"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param string prefix The prefix to use when quoting identifier names.
 * @param string suffix The suffix to use when quoting identifier names.
 */
PHP_METHOD(Pdm_Query_Quoter, __construct) {

	zval *prefix_param = NULL, *suffix_param = NULL;
	zval *prefix = NULL, *suffix = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &prefix_param, &suffix_param);

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
	if (unlikely(Z_TYPE_P(suffix_param) != IS_STRING && Z_TYPE_P(suffix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'suffix' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(suffix_param) == IS_STRING)) {
		suffix = suffix_param;
	} else {
		ZEPHIR_INIT_VAR(suffix);
		ZVAL_EMPTY_STRING(suffix);
	}


	zephir_update_property_this(this_ptr, SL("quoteNamePrefix"), prefix TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("quoteNameSuffix"), suffix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the prefix to use when quoting identifier names.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_Quoter, getQuoteNamePrefix) {


	RETURN_MEMBER(this_ptr, "quoteNamePrefix");

}

/**
 * Returns the suffix to use when quoting identifier names.
 *
 * @return string
 */
PHP_METHOD(Pdm_Query_Quoter, getQuoteNameSuffix) {


	RETURN_MEMBER(this_ptr, "quoteNameSuffix");

}

/**
 * Quotes a single identifier name (table, table alias, table column,
 * index, sequence).
 *
 * If the name contains `' AS '`, this method will separately quote the
 * parts before and after the `' AS '`.
 *
 * If the name contains a space, this method will separately quote the
 * parts before and after the space.
 *
 * If the name contains a dot, this method will separately quote the
 * parts before and after the dot.
 *
 * @param string $spec The identifier name to quote.
 * @return string|array The quoted identifier name.
 * @see replaceName()
 * @see quoteNameWithSeparator()
 */
PHP_METHOD(Pdm_Query_Quoter, quoteName) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	zval *spec_param = NULL, *sep = NULL, *seps, *pos = NULL, *_0, *_1, **_4;
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
	ZEPHIR_SEPARATE_PARAM(spec);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, spec, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(spec, _0);
	ZEPHIR_INIT_VAR(seps);
	array_init_size(seps, 5);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, " AS ", 1);
	zephir_array_fast_append(seps, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, " ", 1);
	zephir_array_fast_append(seps, _1);
	ZEPHIR_INIT_BNVAR(_1);
	ZVAL_STRING(_1, ".", 1);
	zephir_array_fast_append(seps, _1);
	zephir_is_iterable(seps, &_3, &_2, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(sep, _4);
		ZEPHIR_CALL_FUNCTION(&pos, "strripos", &_5, spec, sep);
		zephir_check_call_status();
		if (zephir_is_true(pos)) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "quotenamewithseparator", &_6, spec, sep, pos);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replacename", NULL, spec);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Quotes an identifier that has a separator.
 *
 * @param string $spec The identifier name to quote.
 * @param string $sep The separator, typically a dot or space.
 * @param int $pos The position of the separator.
 * @return string The quoted identifier name.
 */
PHP_METHOD(Pdm_Query_Quoter, quoteNameWithSeparator) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int pos, ZEPHIR_LAST_CALL_STATUS;
	zval *spec_param = NULL, *sep_param = NULL, *pos_param = NULL, *len, *part1 = NULL, *part2 = NULL, _0 = zval_used_for_init, _1, *_2 = NULL, *_4 = NULL;
	zval *spec = NULL, *sep = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &spec_param, &sep_param, &pos_param);

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
	if (unlikely(Z_TYPE_P(sep_param) != IS_STRING && Z_TYPE_P(sep_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sep' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(sep_param) == IS_STRING)) {
		sep = sep_param;
	} else {
		ZEPHIR_INIT_VAR(sep);
		ZVAL_EMPTY_STRING(sep);
	}
	pos = zephir_get_intval(pos_param);


	ZEPHIR_INIT_VAR(len);
	ZVAL_LONG(len, zephir_fast_strlen_ev(sep));
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, pos);
	ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, spec, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&part1, this_ptr, "quotename", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (pos + zephir_get_numberval(len)));
	ZEPHIR_CALL_FUNCTION(&_4, "substr", &_3, spec, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&part2, this_ptr, "replacename", NULL, _4);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, part1, sep, part2);
	RETURN_MM();

}

/**
 * Quotes all fully-qualified identifier names ("table.col") in a string,
 * typically an SQL snippet for a SELECT clause.
 *
 * Does not quote identifier names that are string literals (i.e., inside
 * single or double quotes).
 *
 * Looks for a trailing ' AS alias' and quotes the alias as well.
 *
 * @param string $text The string in which to quote fully-qualified
 * identifier names to quote.
 * @return string|array The string with names quoted in it.
 */
PHP_METHOD(Pdm_Query_Quoter, quoteNamesIn) {

	zval *text_param = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}


	RETURN_CTOR(text);

}

/**
 * Returns a list of candidate elements for quoting.
 *
 * @param string $text The text to split into quoting candidates.
 * @return array
 */
PHP_METHOD(Pdm_Query_Quoter, getListForQuoteNamesIn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *text_param = NULL, *apos, *quot, *_0, _1, _2;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}


	ZEPHIR_INIT_VAR(apos);
	ZVAL_STRING(apos, "'", 1);
	ZEPHIR_INIT_VAR(quot);
	ZVAL_STRING(quot, "\"", 1);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVSVSVSVS(_0, "/((", apos, "+|", quot, "+|\\", apos, "+|\\", quot, "+).*?\\2)/");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, -1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_split", &_3, _0, text, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The in-loop functionality for quoting identifier names.
 *
 * @param string $val The name to be quoted.
 * @param bool $isLast Is this the last loop?
 * @return string The quoted name.
 */
PHP_METHOD(Pdm_Query_Quoter, quoteNamesInLoop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool isLast;
	zval *val_param = NULL, *isLast_param = NULL;
	zval *val = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &val_param, &isLast_param);

	if (unlikely(Z_TYPE_P(val_param) != IS_STRING && Z_TYPE_P(val_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'val' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(val_param) == IS_STRING)) {
		val = val_param;
	} else {
		ZEPHIR_INIT_VAR(val);
		ZVAL_EMPTY_STRING(val);
	}
	if (unlikely(Z_TYPE_P(isLast_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'isLast' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	isLast = Z_BVAL_P(isLast_param);


	if (isLast) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replacenamesandaliasin", NULL, val);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "replacenamesin", NULL, val);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Replaces the names and alias in a string.
 *
 * @param string $val The name to be quoted.
 * @return string The quoted name.
 */
PHP_METHOD(Pdm_Query_Quoter, replaceNamesAndAliasIn) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *val_param = NULL, *quoted = NULL, *pos = NULL, *alias = NULL, _0 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_5;
	zval *val = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val_param);

	if (unlikely(Z_TYPE_P(val_param) != IS_STRING && Z_TYPE_P(val_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'val' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(val_param) == IS_STRING)) {
		val = val_param;
	} else {
		ZEPHIR_INIT_VAR(val);
		ZVAL_EMPTY_STRING(val);
	}


	ZEPHIR_CALL_METHOD(&quoted, this_ptr, "replacenamesin", NULL, val);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, " AS ", 0);
	ZEPHIR_CALL_FUNCTION(&pos, "strripos", &_1, quoted, &_0);
	zephir_check_call_status();
	if (zephir_is_true(pos)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, (zephir_get_numberval(pos) + 4));
		ZEPHIR_CALL_FUNCTION(&_2, "substr", &_3, quoted, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&alias, this_ptr, "replacename", NULL, _2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_3, quoted, &_0, pos);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_VSV(_5, _4, " AS ", alias);
		ZEPHIR_CPY_WRT(quoted, _5);
	}
	RETURN_CCTOR(quoted);

}

/**
 * Quotes an identifier name (table, index, etc); ignores empty values and
 * values of '*'.
 *
 * @param string $name The identifier name to quote.
 * @return string The quoted identifier name.
 */
PHP_METHOD(Pdm_Query_Quoter, replaceName) {

	zval *name_param = NULL, *_0, *_1, *_2;
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
	ZEPHIR_SEPARATE_PARAM(name);


	ZEPHIR_INIT_VAR(_0);
	zephir_fast_trim(_0, name, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_get_strval(name, _0);
	if (ZEPHIR_IS_STRING(name, "*")) {
		RETURN_CTOR(name);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("quoteNamePrefix"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("quoteNameSuffix"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VVV(return_value, _1, name, _2);
	RETURN_MM();

}

/**
 * Quotes all fully-qualified identifier names ("table.col") in a string.
 *
 * @param string $text The string in which to quote fully-qualified
 * identifier names to quote.
 * @return string|array The string with names quoted in it.
 * @see quoteNamesIn()
 */
PHP_METHOD(Pdm_Query_Quoter, replaceNamesIn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL;
	zend_bool isStringLiteral, _2;
	zval *text_param = NULL, *word, *find, *repl, _0, *_1, _3, *_4, *_5, *_6, *_7, *_8, *_9 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	ZEPHIR_SEPARATE_PARAM(text);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "'", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, text, &_0, 0 );
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(_1);
	if (!(_2)) {
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "\"", 0);
		ZEPHIR_INIT_VAR(_4);
		zephir_fast_strpos(_4, text, &_3, 0 );
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(_4);
	}
	isStringLiteral = _2;
	if (isStringLiteral) {
		RETURN_CTOR(text);
	}
	ZEPHIR_INIT_VAR(word);
	ZVAL_STRING(word, "[a-z_][a-z0-9_]+", 1);
	ZEPHIR_INIT_VAR(find);
	ZEPHIR_CONCAT_SVSVS(find, "/(\\b)(", word, ")\\.(", word, ")(\\b)/i");
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("quoteNamePrefix"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("quoteNameSuffix"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("quoteNamePrefix"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("quoteNameSuffix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(repl);
	ZEPHIR_CONCAT_SVSVSVSVS(repl, "$1", _5, "$2", _6, ".", _7, "$3", _8, "$4");
	ZEPHIR_CALL_FUNCTION(&_9, "preg_replace", &_10, find, repl, text);
	zephir_check_call_status();
	zephir_get_strval(text, _9);
	RETURN_CTOR(text);

}

