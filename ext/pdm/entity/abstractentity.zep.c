
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"


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
ZEPHIR_INIT_CLASS(Pdm_Entity_AbstractEntity) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Entity, AbstractEntity, pdm, entity_abstractentity, pdm_entity_abstractentity_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(pdm_entity_abstractentity_ce TSRMLS_CC, 1, pdm_entity_entityinterface_ce);
	return SUCCESS;

}

/**
 * Constructor
 *
 * @param Pdm\Di\ContainerInterface di
 * @param Pdm\Entity\ManagerInterface entityManager
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, __construct) {

	zend_bool _0, _1;
	zval *di = NULL, *entityManager = NULL;

	zephir_fetch_params(0, 0, 2, &di, &entityManager);

	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}
	if (!entityManager) {
		entityManager = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(di) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(di, pdm_di_containerinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'di' must be an instance of 'Pdm\\Di\\ContainerInterface'", "", 0);
		return;
	}
	_1 = Z_TYPE_P(entityManager) != IS_NULL;
	if (_1) {
		_1 = !zephir_is_instance_of(entityManager, SL("Pdm\\Entity\\ManagerInterface") TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'entityManager' must be an instance of 'Pdm\\Entity\\ManagerInterface'", "", 0);
		return;
	}

}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, getSchema) {


	RETURN_STRING("", 1);

}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, getTable) {


	RETURN_STRING("", 1);

}

/**
 * Returns sequence name
 *
 * @return string
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, getSequence) {


	RETURN_STRING("", 1);

}

/**
 * Returns entity manager
 *
 * @return \Pdm\Entity\ManagerInterface
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, getEntityManager) {


	RETURN_STRING("", 1);

}

/**
 * Returns the entity meta data definition
 *
 * @return array
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, metaData) {


	array_init(return_value);
	return;

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($entity->toArray());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, toArray) {


	array_init(return_value);
	return;

}

/**
 * Returns the class name of the entity
 *
 * @return string
 */
PHP_METHOD(Pdm_Entity_AbstractEntity, toString) {


	RETURN_STRING("", 1);

}

