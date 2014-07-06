
extern zend_class_entry *pdm_di_containerbuilder_ce;

ZEPHIR_INIT_CLASS(Pdm_Di_ContainerBuilder);

PHP_METHOD(Pdm_Di_ContainerBuilder, newInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerbuilder_newinstance, 0, 0, 0)
	ZEND_ARG_INFO(0, services)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_di_containerbuilder_method_entry) {
	PHP_ME(Pdm_Di_ContainerBuilder, newInstance, arginfo_pdm_di_containerbuilder_newinstance, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
