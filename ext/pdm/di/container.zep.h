
extern zend_class_entry *pdm_di_container_ce;

ZEPHIR_INIT_CLASS(Pdm_Di_Container);

PHP_METHOD(Pdm_Di_Container, __construct);
PHP_METHOD(Pdm_Di_Container, __get);
PHP_METHOD(Pdm_Di_Container, __set);
PHP_METHOD(Pdm_Di_Container, set);
PHP_METHOD(Pdm_Di_Container, setParam);
PHP_METHOD(Pdm_Di_Container, get);
PHP_METHOD(Pdm_Di_Container, getShared);
PHP_METHOD(Pdm_Di_Container, getParam);
PHP_METHOD(Pdm_Di_Container, remove);
PHP_METHOD(Pdm_Di_Container, setDefault);
PHP_METHOD(Pdm_Di_Container, getDefault);
PHP_METHOD(Pdm_Di_Container, has);
PHP_METHOD(Pdm_Di_Container, hasShared);
PHP_METHOD(Pdm_Di_Container, hasParam);
PHP_METHOD(Pdm_Di_Container, getSharedServices);
PHP_METHOD(Pdm_Di_Container, getServices);
PHP_METHOD(Pdm_Di_Container, getParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_INFO(0, sharedContainer)
	ZEND_ARG_INFO(0, paramContainer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container___get, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container___set, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_set, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_get, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, di)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_has, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_hasshared, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_di_container_hasparam, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_di_container_method_entry) {
	PHP_ME(Pdm_Di_Container, __construct, arginfo_pdm_di_container___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Di_Container, __get, arginfo_pdm_di_container___get, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, __set, arginfo_pdm_di_container___set, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, set, arginfo_pdm_di_container_set, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, setParam, arginfo_pdm_di_container_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, get, arginfo_pdm_di_container_get, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, getShared, arginfo_pdm_di_container_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, getParam, arginfo_pdm_di_container_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, remove, arginfo_pdm_di_container_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, setDefault, arginfo_pdm_di_container_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pdm_Di_Container, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Pdm_Di_Container, has, arginfo_pdm_di_container_has, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, hasShared, arginfo_pdm_di_container_hasshared, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, hasParam, arginfo_pdm_di_container_hasparam, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, getSharedServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, getServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Di_Container, getParams, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
