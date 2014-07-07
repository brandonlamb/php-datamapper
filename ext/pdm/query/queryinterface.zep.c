
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * Interface for query objects.
 *
 * @package \Pdm\Query
 */
ZEPHIR_INIT_CLASS(Pdm_Query_QueryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Query, QueryInterface, pdm, query_queryinterface, pdm_query_queryinterface_method_entry);

	return SUCCESS;

}

/**
 * Builds this query object into a string.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Pdm_Query_QueryInterface, __toString);

/**
 * Adds values to bind into the query; merges with existing values.
 *
 * @param array bindValues Values to bind to the query.
 * @return QueryInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_QueryInterface, bindValues);

/**
 * Binds a single value to the query.
 *
 * @param string $name The placeholder name or number.
 * @param mixed $value The value to bind to the placeholder.
 * @return QueryInterface
 *
 */
ZEPHIR_DOC_METHOD(Pdm_Query_QueryInterface, bindValue);

/**
 * Gets the values to bind into the query.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Pdm_Query_QueryInterface, getBindValues);

