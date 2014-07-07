
/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Query\Common;

use Pdm\Query\AbstractQuery;
use Pdm\Query\Exception;
use Pdm\Query\QueryInterface;

/**
 * An object for SELECT queries.
 *
 * @package \Pdm\QUery
 */
class Select
    extends AbstractQuery
    implements SelectInterface, QueryInterface, OrderByInterface, LimitOffsetInterface //, WhereInterface
{
    /**
     * An array of union SELECT statements.
     *
     * @var array
     */
    protected union = [];

    /**
     *
     * Is this a SELECT FOR UPDATE?
     *
     * @var
     *
     */
    protected forUpdate = false;

    /**
     *
     * The columns to be selected.
     *
     * @var array
     *
     */
    protected select = [];

    /**
     *
     * Select from these tables; includes JOIN clauses.
     *
     * @var array
     *
     */
    protected from = [];

    /**
     *
     * The current key in the `$from` array.
     *
     * @var int
     *
     */
    protected fromKey = -1;

    /**
     *
     * GROUP BY these columns.
     *
     * @var array
     *
     */
    protected groupBy = [];

    /**
     *
     * The list of HAVING conditions.
     *
     * @var array
     *
     */
    protected having = [];

    /**
     *
     * Bind values in the HAVING clause.
     *
     * @var array
     *
     */
    protected bindHaving = [];

    /**
     *
     * The number of rows per page.
     *
     * @var int
     *
     */
    protected paging = 10;

    /**
     *
     * Returns this object as an SQL statement string.
     *
     * @return string An SQL statement string.
     *
     */
    public function __toString() -> string
    {
        if unlikely !empty this->union {
            return implode(PHP_EOL, this->union) . PHP_EOL . this->build();
        }
        return this->build();
    }

    /**
     *
     * Sets the number of rows per page.
     *
     * @param int $paging The number of rows to page at.
     *
     * @return SelectInterface
     *
     */
    public function setPaging(int paging) -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->paging = paging;
        return this;
    }

    /**
     *
     * Gets the number of rows per page.
     *
     * @return int The number of rows per page.
     *
     */
    public function getPaging() -> int
    {
        return this->paging;
    }

    /**
     *
     * Gets the values to bind to placeholders.
     *
     * @return array
     *
     */
    public function getBindValues() -> array
    {
        var bindValues, i, val;

        let bindValues = this->bindValues;
        let i = 1;

        for val in this->bindWhere {
            let bindValues[i] = val;
            let i++;
        }

        for val in this->bindHaving {
            let bindValues[i] = val;
            let i++;
        }

        return bindValues;
    }

    /**
     *
     * Makes the select FOR UPDATE (or not).
     *
     * @param bool $enable Whether or not the SELECT is FOR UPDATE (default
     * true).
     *
     * @return SelectInterface
     *
     */
    public function forUpdate(boolean! enable = true) -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->forUpdate = enable;
        return this;
    }

    /**
     *
     * Makes the select DISTINCT (or not).
     *
     * @param bool $enable Whether or not the SELECT is DISTINCT (default
     * true).
     *
     * @return SelectInterface
     *
     */
    public function distinct(boolean! enable = true) -> <\Pdm\Query\Common\SelectInterface>
    {
        return this->setFlag("DISTINCT", enable);
    }

    /**
     *
     * Adds columns to the query.
     *
     * Multiple calls to select() will append to the list of columns, not
     * overwrite the previous columns.
     *
     * @param array $select The column(s) to add to the query. The elements can be
     * any mix of these: `array("col", "col AS alias", "col" => "alias")`
     *
     * @return SelectInterface
     *
     */
    public function select(var select) -> <\Pdm\Query\Common\SelectInterface>
    {
        var key, val;
        for key, val in select {
            this->addCol(key, val);
        }
        return this;
    }

    /**
     *
     * Adds a FROM table and columns to the query.
     *
     * @param string $spec The table specification; "foo" or "foo AS bar".
     *
     * @return SelectInterface
     *
     */
    public function from(string! spec) -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->from[] = [spec];
        let this->fromKey++;
        return this;
    }

    /**
     *
     * Adds an aliased sub-select to the query.
     *
     * @param string|Select $spec If a Select object, use as the sub-select;
     * if a string, the sub-select string.
     *
     * @param string $name The alias name for the sub-select.
     *
     * @return SelectInterface
     *
     */
    public function fromSubSelect(var spec, string! name) -> <\Pdm\Query\Common\SelectInterface>
    {
        let spec = ltrim(preg_replace("/^/m", "        ", (string) spec));
        let this->from[] = [
            "(" . PHP_EOL . "        " . spec . PHP_EOL . "    ) AS " . name
        ];
        let this->fromKey++;
        return this;
    }

    /**
     *
     * Adds a JOIN table and columns to the query.
     *
     * @param string $type The join type: inner, left, natural, etc.
     *
     * @param string $spec The table specification; "foo" or "foo AS bar".
     *
     * @param string $cond Join on this condition.
     *
     * @return SelectInterface
     *
     * @throws Exception
     *
     */
    public function join(string! type, string! spec, var cond = null) -> <\Pdm\Query\Common\SelectInterface>
    {
        var join, sql, key;

        if unlikely empty this->from {
            throw new Exception("Cannot join() without from() first.");
        }

        let join = strtoupper(trim(type)) . " JOIN ";
        let cond = this->fixJoinCondition(cond);
        let sql = trim(join . spec . " " . cond);

        if fetch key, this->from[this->fromKey] {
            let key[] = sql;
        } else {
            let key = [sql];
        }

        let this->from[this->fromKey] = key;

        return this;
    }

    /**
     *
     * Adds a INNER JOIN table and columns to the query.
     *
     * @param string $spec The table specification; "foo" or "foo AS bar".
     *
     * @param string $cond Join on this condition.
     *
     * @return SelectInterface
     *
     * @throws Exception
     *
     */
    public function innerJoin(string! spec, string! cond = null) -> <\Pdm\Query\Common\SelectInterface>
    {
        return this->join("INNER", spec, cond);
    }

    /**
     *
     * Adds a LEFT JOIN table and columns to the query.
     *
     * @param string $spec The table specification; "foo" or "foo AS bar".
     *
     * @param string $cond Join on this condition.
     *
     * @return SelectInterface
     *
     * @throws Exception
     *
     */
    public function leftJoin(string! spec, string! cond = null) -> <\Pdm\Query\Common\SelectInterface>
    {
        return this->join("LEFT", spec, cond);
    }

    /**
     *
     * Adds a JOIN to an aliased subselect and columns to the query.
     *
     * @param string $type The join type: inner, left, natural, etc.
     *
     * @param string|Select $spec If a Select
     * object, use as the sub-select; if a string, the sub-select
     * command string.
     *
     * @param string $name The alias name for the sub-select.
     *
     * @param string $cond Join on this condition.
     *
     * @return SelectInterface
     *
     * @throws Exception
     *
     */
    public function joinSubSelect(string! type, var spec, string! name, var cond = null) -> <\Pdm\Query\Common\SelectInterface>
    {
        var join, sql, key;

        if unlikely empty this->from {
            throw new Exception("Cannot join() without from() first.");
        }

        let join = strtoupper(ltrim(type)) . " JOIN";
        let spec = PHP_EOL . "    " . ltrim(preg_replace("/^/m", "    ", (string) spec)) . PHP_EOL;
        let cond = this->fixJoinCondition(cond);
        let sql = rtrim(join . " (" . spec . ") AS " . name . " " . cond);

        if fetch key, this->from[this->fromKey] {
            let key[] = sql;
        } else {
            let key = [sql];
        }

        let this->from[this->fromKey] = key;

        return this;
    }

    /**
     *
     * Adds grouping to the query.
     *
     * @param array $spec The column(s) to group by.
     *
     * @return SelectInterface
     *
     */
    public function groupBy(var spec) -> <\Pdm\Query\Common\SelectInterface>
    {
        var col;

        if typeof spec != "array" {
            throw new \InvalidArgumentException("spec must be array.");
        }

        for col in spec {
            let this->groupBy[] = col;
        }
        return this;
    }

    /**
     *
     * Adds a HAVING condition to the query by AND. If the condition has
     * ?-placeholders, additional arguments to the method will be bound to
     * those placeholders sequentially.
     *
     * @param string $cond The HAVING condition.
     * @param array $binds
     *
     * @return SelectInterface
     *
     */
    public function having(string! cond, var binds = []) -> <\Pdm\Query\Common\SelectInterface>
    {
        if typeof binds != "array" {
            throw new \InvalidArgumentException("binds must be array.");
        }
        return this->addClauseCondWithBind("having", "AND", binds);
    }

    /**
     *
     * Adds a HAVING condition to the query by AND. If the condition has
     * ?-placeholders, additional arguments to the method will be bound to
     * those placeholders sequentially.
     *
     * @param string $cond The HAVING condition.
     *
     * @return SelectInterface
     *
     * @see having()
     *
     */
    public function orHaving(string! cond, var binds = []) -> <\Pdm\Query\Common\SelectInterface>
    {
        if typeof binds != "array" {
            throw new \InvalidArgumentException("binds must be array.");
        }
        return this->addClauseCondWithBind("having", "OR", binds);
    }

    /**
     *
     * Sets the limit and count by page number.
     *
     * @param int $page Limit results to this page number.
     *
     * @return SelectInterface
     *
     */
    public function page(int page) -> <\Pdm\Query\Common\SelectInterface>
    {
        // reset the count and offset
        let this->limit  = 0;
        let this->offset = 0;

        // determine the count and offset from the page number
        let page = (int) page;
        if page > 0 {
            let this->limit  = this->paging;
            let this->offset = this->paging * (page - 1);
        }

        // done
        return this;
    }

    /**
     *
     * Takes the current select properties and retains them, then sets
     * UNION for the next set of properties.
     *
     * @return SelectInterface
     *
     */
    public function union() -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->union[] = this->build() . PHP_EOL . "UNION";
        return this->reset();
    }

    /**
     *
     * Takes the current select properties and retains them, then sets
     * UNION ALL for the next set of properties.
     *
     * @return SelectInterface
     *
     */
    public function unionAll() -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->union[] = this->build() . PHP_EOL . "UNION ALL";
        return this->reset();
    }

    /**
     *
     * Adds a WHERE condition to the query by AND. If the condition has
     * ?-placeholders, additional arguments to the method will be bound to
     * those placeholders sequentially.
     *
     * @param string $cond The WHERE condition.
     * @param array $binds arguments to bind to placeholders
     *
     * @return SelectInterface
     *
     */
    public function where(string! cond, var binds = []) -> <\Pdm\Query\Common\SelectInterface>
    {
        if typeof binds != "array" {
            throw new \InvalidArgumentException("binds must be array.");
        }
        return this->addWhere("AND", cond, binds);
    }

    /**
     *
     * Adds a WHERE condition to the query by OR. If the condition has
     * ?-placeholders, additional arguments to the method will be bound to
     * those placeholders sequentially.
     *
     * @param string $cond The WHERE condition.
     * @param array $binds arguments to bind to placeholders
     *
     * @return SelectInterface
     *
     * @see where()
     *
     */
    public function orWhere(string! cond, var binds = [])
    {
        if typeof binds != "array" {
            throw new \InvalidArgumentException("binds must be array.");
        }
        return this->addWhere("OR", cond, binds);
    }

    /**
     *
     * Sets a limit count on the query.
     *
     * @param int $limit The number of rows to select.
     *
     * @return SelectInterface
     *
     */
    public function limit(int limit) -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->limit = (int) limit;
        return this;
    }

    /**
     *
     * Sets a limit offset on the query.
     *
     * @param int $offset Start returning after this many rows.
     *
     * @return SelectInterface
     *
     */
    public function offset(int offset) -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->offset = (int) offset;
        return this;
    }

    /**
     *
     * Adds a column order to the query.
     *
     * @param array $spec The columns and direction to order by.
     *
     * @return SelectInterface
     *
     */
    public function orderBy(var spec) -> <\Pdm\Query\Common\SelectInterface>
    {
        if typeof spec != "array" {
            throw new \InvalidArgumentException("spec must be array.");
        }

        return this->addOrderBy(spec);
    }

    /**
     *
     * Adds a column and alias to the columsn to be selected.
     *
     * @param mixed $key If an integer, ignored. Otherwise, the column to be
     * added.
     *
     * @param mixed $val If $key was an integer, the column to be added;
     * otherwise, the column alias.
     *
     * @return SelectInterface
     *
     */
    protected function addCol(var key, var val) -> <\Pdm\Query\Common\SelectInterface>
    {
        if typeof key == "integer" {
            let this->select[] = val;
        } else {
            let this->select[] = key . " AS " . val;
        }
        return this;
    }

    /**
     *
     * Fixes a JOIN condition to quote names in the condition and prefix it
     * with a condition type ('ON' is the default and 'USING' is recognized).
     *
     * @param string $cond Join on this condition.
     *
     * @return string
     *
     */
    protected function fixJoinCondition(string! cond) -> string
    {
        var cond2;

        if unlikely cond == "" {
            return "";
        }

        let cond2 = strtoupper(ltrim(cond));

        if substr(cond2, 0, 3) == "ON " {
            return cond;
        }

        if substr(cond2, 0, 6) == "USING " {
            return cond;
        }

        return "ON " . cond;
    }

    /**
     *
     * Clears the current select properties; generally used after adding a
     * union.
     *
     * @return SelectInterface
     *
     */
    protected function reset() -> <\Pdm\Query\Common\SelectInterface>
    {
        let this->select       = [];
        let this->from       = [];
        let this->fromKey    = -1;
        let this->where      = [];
        let this->groupBy    = [];
        let this->having     = [];
        let this->orderBy    = [];
        let this->limit      = 0;
        let this->offset     = 0;
        let this->forUpdate  = false;

        return this->resetFlags();
    }

    /**
     *
     * Builds this query object into a string.
     *
     * @return string
     *
     */
    protected function build() -> string
    {
        return "SELECT"
            . this->buildFlags()
            . this->buildSelect()
            . this->buildFrom() // includes JOIN
            . this->buildWhere()
            . this->buildGroupBy()
            . this->buildHaving()
            . this->buildOrderBy()
            . this->buildLimit()
            . this->buildForUpdate();
    }

    /**
     *
     * Builds the columns clause.
     *
     * @return string
     *
     * @throws Exception when there are no columns in the SELECT.
     *
     */
    protected function buildSelect() -> string
    {
        if unlikely empty this->select {
            throw new Exception("No columns in the SELECT.");
        }

        return this->indentCsv(this->select);
    }

    /**
     *
     * Builds the FROM clause.
     *
     * @return string
     *
     */
    protected function buildFrom() -> string
    {
        var refs, from;

        if empty this->from {
            // not applicable
            return "";
        }

        let refs = [];
        for from in this->from {
            let refs[] = implode(PHP_EOL, from);
        }
        return PHP_EOL . "FROM" . this->indentCsv(refs);
    }

    /**
     *
     * Builds the GROUP BY clause.
     *
     * @return string
     *
     */
    protected function buildGroupBy() -> string
    {
        if empty this->groupBy {
            // not applicable
            return "";
        }

        return PHP_EOL . "GROUP BY" . this->indentCsv(this->groupBy);
    }

    /**
     *
     * Builds the HAVING clause.
     *
     * @return string
     *
     */
    protected function buildHaving() -> string
    {
        if empty this->having {
            // not applicable
            return "";
        }

        return PHP_EOL . "HAVING" . this->indent(this->having);
    }

    /**
     *
     * Builds the FOR UPDATE clause.
     *
     * @return string
     *
     */
    protected function buildForUpdate() -> string
    {
        if empty this->forUpdate {
            // not applicable
            return "";
        }

        return PHP_EOL . "FOR UPDATE";
    }
}
