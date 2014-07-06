
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


/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Entity
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Meta Data
 *
 * @package Pdm\Entity
 */
ZEPHIR_INIT_CLASS(Pdm_Entity_MetaData) {

	ZEPHIR_REGISTER_CLASS(Pdm\\Entity, MetaData, pdm, entity_metadata, NULL, 0);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("ATTRIBUTES"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("PRIMARY_KEY"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("NON_PRIMARY_KEY"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("NOT_NULL"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("DATA_TYPES"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("DATA_TYPES_NUMERIC"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("DATA_TYPES_BIND"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("IDENTITY_COLUMN"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("IGNORE_INSERT"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(pdm_entity_metadata_ce, SL("IGNORE_UPDATE"), 10 TSRMLS_CC);

	return SUCCESS;

}

