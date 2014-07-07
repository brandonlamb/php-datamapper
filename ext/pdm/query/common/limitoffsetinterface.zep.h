
extern zend_class_entry *pdm_query_common_limitoffsetinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_Common_LimitOffsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_common_limitoffsetinterface_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_common_limitoffsetinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Query_Common_LimitOffsetInterface, offset, arginfo_pdm_query_common_limitoffsetinterface_offset)
  PHP_FE_END
};
