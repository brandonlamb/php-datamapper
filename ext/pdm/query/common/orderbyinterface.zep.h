
extern zend_class_entry *pdm_query_common_orderbyinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_Common_OrderByInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_orderbyinterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, spec)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_common_orderbyinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Query_Common_OrderByInterface, orderBy, arginfo_pdm_query_common_orderbyinterface_orderby)
  PHP_FE_END
};
