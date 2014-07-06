
extern zend_class_entry *pdm_entity_entityinterface_ce;

ZEPHIR_INIT_CLASS(Pdm_Entity_EntityInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pdm_entity_entityinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, di)
	ZEND_ARG_INFO(0, entityManager)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pdm_entity_entityinterface_method_entry) {
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, __construct, arginfo_pdm_entity_entityinterface___construct)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, getSchema, NULL)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, getTable, NULL)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, getSequence, NULL)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, getEntityManager, NULL)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, metaData, NULL)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, toArray, NULL)
	PHP_ABSTRACT_ME(Pdm_Entity_EntityInterface, toString, NULL)
  PHP_FE_END
};
