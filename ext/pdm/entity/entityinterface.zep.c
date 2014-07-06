
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Entity
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Entity Interface
 *
 * @package Pdm\Entity
 */
ZEPHIR_INIT_CLASS(Pdm_Entity_EntityInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Entity, EntityInterface, pdm, entity_entityinterface, pdm_entity_entityinterface_method_entry);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param Pdm\Di\ContainerInterface di
 * @param Pdm\Entity\ManagerInterface entityManager
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, __construct);

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, getSchema);

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, getTable);

/**
 * Returns sequence name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, getSequence);

/**
 * Returns entity manager
 *
 * @return \Pdm\Entity\ManagerInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, getEntityManager);

/**
 * Returns the entity meta data definition
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, metaData);

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($entity->toArray());
 *</code>
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, toArray);

/**
 * Returns the class name of the entity
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Entity_EntityInterface, toString);

