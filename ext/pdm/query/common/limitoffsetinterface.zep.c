
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
 * An interface for LIMIT...OFFSET clauses.
 *
 * @package \Pdm\Query
 *
 */
ZEPHIR_INIT_CLASS(Pdm_Query_Common_LimitOffsetInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(Pdm\\Query\\Common, LimitOffsetInterface, pdm, query_common_limitoffsetinterface, pdm_query_common_limitinterface_ce, pdm_query_common_limitoffsetinterface_method_entry);

	return SUCCESS;

}

/**
 *
 * Sets a limit offset on the query.
 *
 * @param int $offset Start returning after this many rows.
 *
 * @return LimitOffsetInterface
 *
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_LimitOffsetInterface, offset);

