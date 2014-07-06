
extern zend_class_entry *pdm_entity_abstractentity_ce;

ZEPHIR_INIT_CLASS(Pdm_Entity_AbstractEntity);

PHP_METHOD(Pdm_Entity_AbstractEntity, __construct);
PHP_METHOD(Pdm_Entity_AbstractEntity, getSchema);
PHP_METHOD(Pdm_Entity_AbstractEntity, getTable);
PHP_METHOD(Pdm_Entity_AbstractEntity, getSequence);
PHP_METHOD(Pdm_Entity_AbstractEntity, getEntityManager);
PHP_METHOD(Pdm_Entity_AbstractEntity, metaData);
PHP_METHOD(Pdm_Entity_AbstractEntity, toArray);
PHP_METHOD(Pdm_Entity_AbstractEntity, toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_entity_abstractentity___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, di)
	ZEND_ARG_INFO(0, entityManager)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_entity_abstractentity_method_entry) {
	PHP_ME(Pdm_Entity_AbstractEntity, __construct, arginfo_pdm_entity_abstractentity___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pdm_Entity_AbstractEntity, getSchema, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Entity_AbstractEntity, getTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Entity_AbstractEntity, getSequence, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Entity_AbstractEntity, getEntityManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Entity_AbstractEntity, metaData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Entity_AbstractEntity, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pdm_Entity_AbstractEntity, toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
