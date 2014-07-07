
extern zend_class_entry *pdm_query_common_select_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_Common_Select);

PHP_METHOD(Pdm_Query_Common_Select, __toString);
PHP_METHOD(Pdm_Query_Common_Select, setPaging);
PHP_METHOD(Pdm_Query_Common_Select, getPaging);
PHP_METHOD(Pdm_Query_Common_Select, getBindValues);
PHP_METHOD(Pdm_Query_Common_Select, forUpdate);
PHP_METHOD(Pdm_Query_Common_Select, distinct);
PHP_METHOD(Pdm_Query_Common_Select, select);
PHP_METHOD(Pdm_Query_Common_Select, from);
PHP_METHOD(Pdm_Query_Common_Select, fromSubSelect);
PHP_METHOD(Pdm_Query_Common_Select, join);
PHP_METHOD(Pdm_Query_Common_Select, innerJoin);
PHP_METHOD(Pdm_Query_Common_Select, leftJoin);
PHP_METHOD(Pdm_Query_Common_Select, joinSubSelect);
PHP_METHOD(Pdm_Query_Common_Select, groupBy);
PHP_METHOD(Pdm_Query_Common_Select, having);
PHP_METHOD(Pdm_Query_Common_Select, orHaving);
PHP_METHOD(Pdm_Query_Common_Select, page);
PHP_METHOD(Pdm_Query_Common_Select, union);
PHP_METHOD(Pdm_Query_Common_Select, unionAll);
PHP_METHOD(Pdm_Query_Common_Select, where);
PHP_METHOD(Pdm_Query_Common_Select, orWhere);
PHP_METHOD(Pdm_Query_Common_Select, limit);
PHP_METHOD(Pdm_Query_Common_Select, offset);
PHP_METHOD(Pdm_Query_Common_Select, orderBy);
PHP_METHOD(Pdm_Query_Common_Select, addCol);
PHP_METHOD(Pdm_Query_Common_Select, fixJoinCondition);
PHP_METHOD(Pdm_Query_Common_Select, reset);
PHP_METHOD(Pdm_Query_Common_Select, build);
PHP_METHOD(Pdm_Query_Common_Select, buildSelect);
PHP_METHOD(Pdm_Query_Common_Select, buildFrom);
PHP_METHOD(Pdm_Query_Common_Select, buildGroupBy);
PHP_METHOD(Pdm_Query_Common_Select, buildHaving);
PHP_METHOD(Pdm_Query_Common_Select, buildForUpdate);
PHP_METHOD(Pdm_Query_Common_Select, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_setpaging, 0, 0, 1)
	ZEND_ARG_INFO(0, paging)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, enable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_distinct, 0, 0, 0)
	ZEND_ARG_INFO(0, enable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_select, 0, 0, 1)
	ZEND_ARG_INFO(0, select)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_from, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_fromsubselect, 0, 0, 2)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_join, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_joinsubselect, 0, 0, 3)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, spec)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_having, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_orhaving, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_page, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_where, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
	ZEND_ARG_INFO(0, binds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_addcol, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_select_fixjoincondition, 0, 0, 1)
	ZEND_ARG_INFO(0, cond)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_common_select_method_entry) {
	PHP_ME(Pdm_Query_Common_Select, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, setPaging, arginfo_pdm_query_common_select_setpaging, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, getPaging, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, getBindValues, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, forUpdate, arginfo_pdm_query_common_select_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, distinct, arginfo_pdm_query_common_select_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, select, arginfo_pdm_query_common_select_select, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, from, arginfo_pdm_query_common_select_from, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, fromSubSelect, arginfo_pdm_query_common_select_fromsubselect, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, join, arginfo_pdm_query_common_select_join, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, innerJoin, arginfo_pdm_query_common_select_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, leftJoin, arginfo_pdm_query_common_select_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, joinSubSelect, arginfo_pdm_query_common_select_joinsubselect, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, groupBy, arginfo_pdm_query_common_select_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, having, arginfo_pdm_query_common_select_having, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, orHaving, arginfo_pdm_query_common_select_orhaving, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, page, arginfo_pdm_query_common_select_page, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, union, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, unionAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, where, arginfo_pdm_query_common_select_where, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, orWhere, arginfo_pdm_query_common_select_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, limit, arginfo_pdm_query_common_select_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, offset, arginfo_pdm_query_common_select_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, orderBy, arginfo_pdm_query_common_select_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_Common_Select, addCol, arginfo_pdm_query_common_select_addcol, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, fixJoinCondition, arginfo_pdm_query_common_select_fixjoincondition, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, reset, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, build, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, buildSelect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, buildFrom, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, buildGroupBy, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, buildHaving, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, buildForUpdate, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Pdm_Query_Common_Select, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
