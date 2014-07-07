
extern zend_class_entry *pdm_query_quoter_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_Quoter);

PHP_METHOD(Pdm_Query_Quoter, __construct);
PHP_METHOD(Pdm_Query_Quoter, getQuoteNamePrefix);
PHP_METHOD(Pdm_Query_Quoter, getQuoteNameSuffix);
PHP_METHOD(Pdm_Query_Quoter, quoteName);
PHP_METHOD(Pdm_Query_Quoter, quoteNameWithSeparator);
PHP_METHOD(Pdm_Query_Quoter, quoteNamesIn);
PHP_METHOD(Pdm_Query_Quoter, getListForQuoteNamesIn);
PHP_METHOD(Pdm_Query_Quoter, quoteNamesInLoop);
PHP_METHOD(Pdm_Query_Quoter, replaceNamesAndAliasIn);
PHP_METHOD(Pdm_Query_Quoter, replaceName);
PHP_METHOD(Pdm_Query_Quoter, replaceNamesIn);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_quotename, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_quotenamewithseparator, 0, 0, 3)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, sep)
	ZEND_ARG_INFO(0, pos)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_quotenamesin, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_getlistforquotenamesin, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_quotenamesinloop, 0, 0, 2)
	ZEND_ARG_INFO(0, val)
	ZEND_ARG_INFO(0, isLast)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_replacenamesandaliasin, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_replacename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_quoter_replacenamesin, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_quoter_method_entry) {
	PHP_ME(Pdm_Query_Quoter, __construct, arginfo_pdm_query_quoter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Query_Quoter, getQuoteNamePrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Quoter, getQuoteNameSuffix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Quoter, quoteName, arginfo_pdm_query_quoter_quotename, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Quoter, quoteNameWithSeparator, arginfo_pdm_query_quoter_quotenamewithseparator, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Quoter, quoteNamesIn, arginfo_pdm_query_quoter_quotenamesin, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Quoter, getListForQuoteNamesIn, arginfo_pdm_query_quoter_getlistforquotenamesin, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Quoter, quoteNamesInLoop, arginfo_pdm_query_quoter_quotenamesinloop, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Quoter, replaceNamesAndAliasIn, arginfo_pdm_query_quoter_replacenamesandaliasin, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Quoter, replaceName, arginfo_pdm_query_quoter_replacename, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Quoter, replaceNamesIn, arginfo_pdm_query_quoter_replacenamesin, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
