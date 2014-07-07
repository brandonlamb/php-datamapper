
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 *
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 *
 */
/**
 *
 * An interface for ORDER BY clauses.
 *
 * @package \Pdm\Query
 *
 */
ZEPHIR_INIT_CLASS(Pdm_Query_Common_OrderByInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Query\\Common, OrderByInterface, pdm, query_common_orderbyinterface, pdm_query_common_orderbyinterface_method_entry);

	return SUCCESS;

}

/**
 *
 * Adds a column order to the query.
 *
 * @param array $spec The columns and direction to order by.
 *
 * @return OrderByInterface
 *
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_OrderByInterface, orderBy);

