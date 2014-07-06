
extern zend_class_entry *pdm_db_connectionlocator_ce;

ZEPHIR_INIT_CLASS(Pdm_Db_ConnectionLocator);

PHP_METHOD(Pdm_Db_ConnectionLocator, __construct);
PHP_METHOD(Pdm_Db_ConnectionLocator, setDefault);
PHP_METHOD(Pdm_Db_ConnectionLocator, getDefault);
PHP_METHOD(Pdm_Db_ConnectionLocator, setRead);
PHP_METHOD(Pdm_Db_ConnectionLocator, getRead);
PHP_METHOD(Pdm_Db_ConnectionLocator, setWrite);
PHP_METHOD(Pdm_Db_ConnectionLocator, getWrite);
PHP_METHOD(Pdm_Db_ConnectionLocator, getConnection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultCallback)
	ZEND_ARG_INFO(0, read)
	ZEND_ARG_INFO(0, write)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator_setread, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator_getread, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator_setwrite, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator_getwrite, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_db_connectionlocator_getconnection, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_db_connectionlocator_method_entry) {
	PHP_ME(Pdm_Db_ConnectionLocator, __construct, arginfo_pdm_db_connectionlocator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Db_ConnectionLocator, setDefault, arginfo_pdm_db_connectionlocator_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_ConnectionLocator, getDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_ConnectionLocator, setRead, arginfo_pdm_db_connectionlocator_setread, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_ConnectionLocator, getRead, arginfo_pdm_db_connectionlocator_getread, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_ConnectionLocator, setWrite, arginfo_pdm_db_connectionlocator_setwrite, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_ConnectionLocator, getWrite, arginfo_pdm_db_connectionlocator_getwrite, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Db_ConnectionLocator, getConnection, arginfo_pdm_db_connectionlocator_getconnection, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
