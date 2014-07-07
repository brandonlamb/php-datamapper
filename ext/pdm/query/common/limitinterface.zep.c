
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
 * An interface for LIMIT clauses.
 *
 * @package \Pdm\Query
 *
 */
ZEPHIR_INIT_CLASS(Pdm_Query_Common_LimitInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Query\\Common, LimitInterface, pdm, query_common_limitinterface, pdm_query_common_limitinterface_method_entry);

	return SUCCESS;

}

/**
 *
 * Sets a limit count on the query.
 *
 * @param int $limit The number of rows to select.
 *
 * @return LimitInterface
 *
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_LimitInterface, limit);

