
extern zend_class_entry *pdm_query_common_limitinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_Common_LimitInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_limitinterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_common_limitinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Query_Common_LimitInterface, limit, arginfo_pdm_query_common_limitinterface_limit)
  PHP_FE_END
};
