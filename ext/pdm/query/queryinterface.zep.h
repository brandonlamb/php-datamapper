
extern zend_class_entry *pdm_query_queryinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_QueryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_queryinterface_bindvalues, 0, 0, 1)
	ZEND_ARG_INFO(0, bindValues)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_queryinterface_bindvalue, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_queryinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Query_QueryInterface, __toString, NULL)
	PHP_ABSTRACT_ME(Pdm_Query_QueryInterface, bindValues, arginfo_pdm_query_queryinterface_bindvalues)
	PHP_ABSTRACT_ME(Pdm_Query_QueryInterface, bindValue, arginfo_pdm_query_queryinterface_bindvalue)
	PHP_ABSTRACT_ME(Pdm_Query_QueryInterface, getBindValues, NULL)
  PHP_FE_END
};
