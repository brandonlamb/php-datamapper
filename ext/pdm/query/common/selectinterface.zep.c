
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
/**
 * An interface for SELECT queries.
 *
 * @package \Pdm\Query
 */
ZEPHIR_INIT_CLASS(Pdm_Query_Common_SelectInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pdm\\Query\\Common, SelectInterface, pdm, query_common_selectinterface, pdm_query_common_selectinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the number of rows per page.
 *
 * @param int $paging The number of rows to page at.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, setPaging);

/**
 * Gets the number of rows per page.
 *
 * @return int The number of rows per page.
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, getPaging);

/**
 * Makes the select FOR UPDATE (or not).
 *
 * @param bool $enable Whether or not the SELECT is FOR UPDATE (default true).
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, forUpdate);

/**
 * Makes the select DISTINCT (or not).
 *
 * @param bool $enable Whether or not the SELECT is DISTINCT (default true).
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, distinct);

/**
 * Adds columns to the query.
 *
 * Multiple calls to select() will append to the list of columns, not
 * overwrite the previous columns.
 *
 * @param array $select The column(s) to add to the query.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, select);

/**
 * Adds a FROM table and columns to the query.
 *
 * @param string $spec The table specification; "foo" or "foo AS bar".
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, from);

/**
 * Adds an aliased sub-select to the query.
 *
 * @param string|Select $spec If a Select object, use as the sub-select; if a string, the sub-select string.
 * @param string $name The alias name for the sub-select.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, fromSubSelect);

/**
 * Adds a JOIN table and columns to the query.
 *
 * @param string $join The join type: inner, left, natural, etc.
 * @param string $spec The table specification; "foo" or "foo AS bar".
 * @param string $cond Join on this condition.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, join);

/**
 * Adds a JOIN to an aliased subselect and columns to the query.
 *
 * @param string $join The join type: inner, left, natural, etc.
 * @param string|Select $spec If a Select
 * object, use as the sub-select; if a string, the sub-select
 * command string.
 * @param string $name The alias name for the sub-select.
 * @param string $cond Join on this condition.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, joinSubSelect);

/**
 * Adds grouping to the query.
 *
 * @param array $spec The column(s) to group by.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, groupBy);

/**
 * Adds a HAVING condition to the query by AND; if a value is passed as
 * the second param, it will be quoted and replaced into the condition
 * wherever a question-mark appears.
 *
 * Array values are quoted and comma-separated.
 *
 * {{code: php
 *     // simplest but non-secure
 *     $select->having("COUNT(id) = $count");
 *
 *     // secure
 *     $select->having('COUNT(id) = ?', $count);
 *
 *     // equivalent security with named binding
 *     $select->having('COUNT(id) = :count');
 *     $select->bind('count', $count);
 * }}
 *
 * @param string $cond The HAVING condition.
 * @param array $binds
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, having);

/**
 * Adds a HAVING condition to the query by AND; otherwise identical to
 * `having()`.
 *
 * @param string $cond The HAVING condition.
 * @param array $binds
 * @return SelectInterface
 * @see having()
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, orHaving);

/**
 * Sets the limit and count by page number.
 *
 * @param int $page Limit results to this page number.
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, page);

/**
 * Takes the current select properties and retains them, then sets
 * UNION for the next set of properties.
 *
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, union);

/**
 * Takes the current select properties and retains them, then sets
 * UNION ALL for the next set of properties.
 *
 * @return SelectInterface
 */
ZEPHIR_DOC_METHOD(Pdm_Query_Common_SelectInterface, unionAll);

