
/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Query\Common;

//use Pdm\Query\QueryInterface;

/**
 * An interface for SELECT queries.
 *
 * @package \Pdm\Query
 */
interface SelectInterface //extends QueryInterface, OrderByInterface, LimitOffsetInterface, WhereInterface
{
    /**
     * Sets the number of rows per page.
     *
     * @param int $paging The number of rows to page at.
     * @return SelectInterface
     */
    public function setPaging(int paging) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Gets the number of rows per page.
     *
     * @return int The number of rows per page.
     */
    public function getPaging() -> int;

    /**
     * Makes the select FOR UPDATE (or not).
     *
     * @param bool $enable Whether or not the SELECT is FOR UPDATE (default true).
     * @return SelectInterface
     */
    public function forUpdate(boolean enable = true) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Makes the select DISTINCT (or not).
     *
     * @param bool $enable Whether or not the SELECT is DISTINCT (default true).
     * @return SelectInterface
     */
    public function distinct(boolean enable = true) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Adds columns to the query.
     *
     * Multiple calls to select() will append to the list of columns, not
     * overwrite the previous columns.
     *
     * @param array $select The column(s) to add to the query.
     * @return SelectInterface
     */
    public function select(var select) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Adds a FROM table and columns to the query.
     *
     * @param string $spec The table specification; "foo" or "foo AS bar".
     * @return SelectInterface
     */
    public function from(string! spec) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Adds an aliased sub-select to the query.
     *
     * @param string|Select $spec If a Select object, use as the sub-select; if a string, the sub-select string.
     * @param string $name The alias name for the sub-select.
     * @return SelectInterface
     */
    public function fromSubSelect(var spec, string! name) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Adds a JOIN table and columns to the query.
     *
     * @param string $join The join type: inner, left, natural, etc.
     * @param string $spec The table specification; "foo" or "foo AS bar".
     * @param string $cond Join on this condition.
     * @return SelectInterface
     */
    public function join(string! join, string! spec, string! cond = null) -> <\Pdm\Query\Common\SelectInterface>;

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
    public function joinSubSelect(string! join, string! spec, string! name, string! cond = null) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Adds grouping to the query.
     *
     * @param array $spec The column(s) to group by.
     * @return SelectInterface
     */
    public function groupBy(var spec) -> <\Pdm\Query\Common\SelectInterface>;

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
    public function having(string! cond, var binds = []) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Adds a HAVING condition to the query by AND; otherwise identical to
     * `having()`.
     *
     * @param string $cond The HAVING condition.
     * @param array $binds
     * @return SelectInterface
     * @see having()
     */
    public function orHaving(string! cond, var binds = []) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Sets the limit and count by page number.
     *
     * @param int $page Limit results to this page number.
     * @return SelectInterface
     */
    public function page(int page) -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Takes the current select properties and retains them, then sets
     * UNION for the next set of properties.
     *
     * @return SelectInterface
     */
    public function union() -> <\Pdm\Query\Common\SelectInterface>;

    /**
     * Takes the current select properties and retains them, then sets
     * UNION ALL for the next set of properties.
     *
     * @return SelectInterface
     */
    public function unionAll() -> <\Pdm\Query\Common\SelectInterface>;
}
