
extern zend_class_entry *pdm_di_containerinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Di_ContainerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerinterface_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_containerinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_di_containerinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, set, arginfo_pdm_di_containerinterface_set)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, remove, arginfo_pdm_di_containerinterface_remove)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, get, arginfo_pdm_di_containerinterface_get)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, getShared, arginfo_pdm_di_containerinterface_getshared)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, has, arginfo_pdm_di_containerinterface_has)
	ZEND_FENTRY(setDefault, NULL, arginfo_pdm_di_containerinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDefault, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, getSharedServices, NULL)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, getServices, NULL)
	PHP_ABSTRACT_ME(Pdm_Di_ContainerInterface, getParams, NULL)
  PHP_FE_END
};
