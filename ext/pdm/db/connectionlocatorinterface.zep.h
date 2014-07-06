
extern zend_class_entry *pdm_db_connectionlocatorinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_ConnectionLocatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocatorinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocatorinterface_setread, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocatorinterface_getread, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocatorinterface_setwrite, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocatorinterface_getwrite, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_connectionlocatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Db_ConnectionLocatorInterface, setDefault, arginfo_pdm_db_connectionlocatorinterface_setdefault)
	PHP_ABSTRACT_ME(Pdm_Db_ConnectionLocatorInterface, getDefault, NULL)
	PHP_ABSTRACT_ME(Pdm_Db_ConnectionLocatorInterface, setRead, arginfo_pdm_db_connectionlocatorinterface_setread)
	PHP_ABSTRACT_ME(Pdm_Db_ConnectionLocatorInterface, getRead, arginfo_pdm_db_connectionlocatorinterface_getread)
	PHP_ABSTRACT_ME(Pdm_Db_ConnectionLocatorInterface, setWrite, arginfo_pdm_db_connectionlocatorinterface_setwrite)
	PHP_ABSTRACT_ME(Pdm_Db_ConnectionLocatorInterface, getWrite, arginfo_pdm_db_connectionlocatorinterface_getwrite)
  PHP_FE_END
};
