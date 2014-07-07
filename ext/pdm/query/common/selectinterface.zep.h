
extern zend_class_entry *pdm_query_common_selectinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_Common_SelectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_setpaging, 0, 0, 1)
	ZEND_ARG_INFO(0, paging)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, enable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_distinct, 0, 0, 0)
	ZEND_ARG_INFO(0, enable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_select, 0, 0, 1)
	ZEND_ARG_INFO(0, select)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_from, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_fromsubselect, 0, 0, 2)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_join, 0, 0, 2)
	ZEND_ARG_INFO(0, join)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_joinsubselect, 0, 0, 3)
	ZEND_ARG_INFO(0, join)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_having, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_orhaving, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_selectinterface_page, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_common_selectinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, setPaging, arginfo_pdm_query_common_selectinterface_setpaging)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, getPaging, NULL)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, forUpdate, arginfo_pdm_query_common_selectinterface_forupdate)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, distinct, arginfo_pdm_query_common_selectinterface_distinct)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, select, arginfo_pdm_query_common_selectinterface_select)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, from, arginfo_pdm_query_common_selectinterface_from)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, fromSubSelect, arginfo_pdm_query_common_selectinterface_fromsubselect)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, join, arginfo_pdm_query_common_selectinterface_join)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, joinSubSelect, arginfo_pdm_query_common_selectinterface_joinsubselect)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, groupBy, arginfo_pdm_query_common_selectinterface_groupby)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, having, arginfo_pdm_query_common_selectinterface_having)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, orHaving, arginfo_pdm_query_common_selectinterface_orhaving)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, page, arginfo_pdm_query_common_selectinterface_page)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, union, NULL)
	PHP_ABSTRACT_ME(Pdm_Query_Common_SelectInterface, unionAll, NULL)
  PHP_FE_END
};
