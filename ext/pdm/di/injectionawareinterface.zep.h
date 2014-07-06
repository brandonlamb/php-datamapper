
extern zend_class_entry *pdm_di_injectionawareinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Di_InjectionAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_injectionawareinterface_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, di)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_di_injectionawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Di_InjectionAwareInterface, setDi, arginfo_pdm_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(Pdm_Di_InjectionAwareInterface, getDi, NULL)
  PHP_FE_END
};
