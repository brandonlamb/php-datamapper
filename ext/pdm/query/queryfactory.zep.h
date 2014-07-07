
extern zend_class_entry *pdm_query_queryfactory_ce;

ZEPHIR_INIT_CLASS(Pdm_Query_QueryFactory);

PHP_METHOD(Pdm_Query_QueryFactory, __construct);
PHP_METHOD(Pdm_Query_QueryFactory, setLastInsertIdNames);
PHP_METHOD(Pdm_Query_QueryFactory, newSelect);
PHP_METHOD(Pdm_Query_QueryFactory, newInsert);
PHP_METHOD(Pdm_Query_QueryFactory, newUpdate);
PHP_METHOD(Pdm_Query_QueryFactory, newDelete);
PHP_METHOD(Pdm_Query_QueryFactory, newInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_queryfactory___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, db)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_queryfactory_setlastinsertidnames, 0, 0, 1)
	ZEND_ARG_INFO(0, lastInsertIdNames)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_query_queryfactory_newinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_query_queryfactory_method_entry) {
	PHP_ME(Pdm_Query_QueryFactory, __construct, arginfo_pdm_query_queryfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Query_QueryFactory, setLastInsertIdNames, arginfo_pdm_query_queryfactory_setlastinsertidnames, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_QueryFactory, newSelect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_QueryFactory, newInsert, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_QueryFactory, newUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_QueryFactory, newDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Query_QueryFactory, newInstance, arginfo_pdm_query_queryfactory_newinstance, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
