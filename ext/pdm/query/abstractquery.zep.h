
extern zend_class_entry *pdm_query_abstractquery_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_AbstractQuery);

PHP_METHOD(Pdm_Query_AbstractQuery, getLimit);
PHP_METHOD(Pdm_Query_AbstractQuery, getOffset);
PHP_METHOD(Pdm_Query_AbstractQuery, __toString);
PHP_METHOD(Pdm_Query_AbstractQuery, getBindValuesx);
PHP_METHOD(Pdm_Query_AbstractQuery, bindValues);
PHP_METHOD(Pdm_Query_AbstractQuery, bindValue);
PHP_METHOD(Pdm_Query_AbstractQuery, build);
PHP_METHOD(Pdm_Query_AbstractQuery, indentCsv);
PHP_METHOD(Pdm_Query_AbstractQuery, indent);
PHP_METHOD(Pdm_Query_AbstractQuery, setFlag);
PHP_METHOD(Pdm_Query_AbstractQuery, resetFlags);
PHP_METHOD(Pdm_Query_AbstractQuery, addWhere);
PHP_METHOD(Pdm_Query_AbstractQuery, addClauseCondWithBind);
PHP_METHOD(Pdm_Query_AbstractQuery, addOrderBy);
PHP_METHOD(Pdm_Query_AbstractQuery, buildFlags);
PHP_METHOD(Pdm_Query_AbstractQuery, buildWhere);
PHP_METHOD(Pdm_Query_AbstractQuery, buildOrderBy);
PHP_METHOD(Pdm_Query_AbstractQuery, buildLimit);
PHP_METHOD(Pdm_Query_AbstractQuery, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_bindvalues, 0, 0, 1)
	ZEND_ARG_INFO(0, bindValues)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_bindvalue, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_indentcsv, 0, 0, 1)
	ZEND_ARG_INFO(0, list)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_indent, 0, 0, 1)
	ZEND_ARG_INFO(0, list)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_setflag, 0, 0, 1)
	ZEND_ARG_INFO(0, flag)
	ZEND_ARG_INFO(0, enable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_addwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, andor)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_addclausecondwithbind, 0, 0, 3)
	ZEND_ARG_INFO(0, clause)
	ZEND_ARG_INFO(0, andor)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_abstractquery_addorderby, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_abstractquery_method_entry) {
	PHP_ME(Pdm_Query_AbstractQuery, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_AbstractQuery, getOffset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_AbstractQuery, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_AbstractQuery, getBindValuesx, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_AbstractQuery, bindValues, arginfo_pdm_query_abstractquery_bindvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_AbstractQuery, bindValue, arginfo_pdm_query_abstractquery_bindvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_AbstractQuery, build, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, indentCsv, arginfo_pdm_query_abstractquery_indentcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, indent, arginfo_pdm_query_abstractquery_indent, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, setFlag, arginfo_pdm_query_abstractquery_setflag, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, resetFlags, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, addWhere, arginfo_pdm_query_abstractquery_addwhere, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, addClauseCondWithBind, arginfo_pdm_query_abstractquery_addclausecondwithbind, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, addOrderBy, arginfo_pdm_query_abstractquery_addorderby, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, buildFlags, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, buildWhere, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, buildOrderBy, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, buildLimit, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_AbstractQuery, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
