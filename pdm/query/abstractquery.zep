
/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Query;

use Pdm\Query\Common\LimitInterface;
use Pdm\Query\Common\LimitOffsetInterface;

/**
 * Abstract query object.
 *
 * @package \Pdm\Query
 */
abstract class AbstractQuery
{
    /**
     * Data to be bound to the query.
     *
     * @var array
     */
    protected bindValues = [];

    /**
     * The list of WHERE conditions.
     *
     * @var array
     */
    protected where = [];

    /**
     * Bind these values to the WHERE conditions.
     *
     * @var array
     */
    protected bindWhere = [];

    /**
     * ORDER BY these columns.
     *
     * @var array
     */
    protected orderBy = [];

    /**
     * The number of rows to select
     *
     * @var int
     */
    protected limit = 0 { get };

    /**
     * Return rows after this offset.
     *
     * @var int
     */
    protected offset = 0 { get };

    /**
     * The list of flags.
     *
     * @var array
     */
    protected flags = [];

    /**
     * Returns this query object as a string.
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->build();
    }

    /**
     *
     * Gets the values to bind to placeholders.
     *
     * @return array
     *
     */
    public function getBindValuesx() -> array
    {
        return this->bindValues;
    }

    /**
     * Binds multiple values to placeholders; merges with existing values.
     *
     * @param array $bindValues Values to bind to placeholders.
     * @return QueryInterface
     */
    public function bindValues(var bindValues) -> <\Pdm\Query\QueryInterface>
    {
        var key, val;

        if typeof bindValues != "array" {
            throw new \InvalidArgumentException("bindValues must be array.");
        }

        // array_merge() renumbers integer keys, which is bad for question-mark placeholders
        for key, val in bindValues {
            this->bindValue(key, val);
        }
        return this;
    }

    /**
     * Binds a single value to the query.
     *
     * @param string $name The placeholder name or number.
     * @param mixed $value The value to bind to the placeholder.
     * @return QueryInterface
     */
    public function bindValue(string! name, var value) -> <\Pdm\Query\QueryInterface>
    {
        let this->bindValues[name] = value;
        return this;
    }

    /**
     * Builds this query object into a string.
     *
     * @return string
     */
    abstract protected function build() -> string;

    /**
     * Returns an array as an indented comma-separated values string.
     *
     * @param array $list The values to convert.
     * @return string
     */
    protected function indentCsv(var list) -> string
    {
        if typeof list != "array" {
            throw new \InvalidArgumentException("list must be array.");
        }
        return PHP_EOL . "    " . implode("," . PHP_EOL . "    ", list);
    }

    /**
     * Returns an array as an indented string.
     *
     * @param array $list The values to convert.
     * @return string
     */
    protected function indent(var list) -> string
    {
        if typeof list != "array" {
            throw new \InvalidArgumentException("list must be array.");
        }
        return PHP_EOL . "    " . implode(PHP_EOL . "    ", list);
    }

    /**
     * Sets or unsets specified flag.
     *
     * @param string $flag Flag to set or unset
     * @param bool $enable Flag status - enabled or not (default true)
     * @return QueryInterface
     */
    protected function setFlag(string! flag, boolean enable = true) -> <\Pdm\Query\QueryInterface>
    {
        if enable {
            let this->flags[flag] = true;
        } else {
            unset this->flags[flag];
        }
        return this;
    }

    /**
     * Reset all query flags.
     *
     * @return QueryInterface
     */
    protected function resetFlags() -> <\Pdm\Query\QueryInterface>
    {
        let this->flags = [];
        return this;
    }

    /**
     * Adds a WHERE condition to the query by AND or OR. If the condition has
     * ?-placeholders, additional arguments to the method will be bound to
     * those placeholders sequentially.
     *
     * @param string $andor Add the condition using this operator, typically
     * 'AND' or 'OR'.
     * @param string $cond, condition
     * @param array $binds Arguments for adding the condition.
     * @return QueryInterface
     */
    protected function addWhere(string! andor, string! cond, var binds = []) -> <\Pdm\Query\QueryInterface>
    {
        if typeof binds != "array" {
            throw new \InvalidArgumentException("binds must be array.");
        }
        return this->addClauseCondWithBind("where", andor, [cond, binds]);
    }

    /**
     * Adds conditions and binds values to a clause.
     *
     * @param string $clause The clause to work with, typically 'where' or 'having'.
     * @param string $andor Add the condition using this operator, typically 'AND' or 'OR'.
     * @param array $args Arguments for adding the condition. $args = [$cond, $binds]
     * @return QueryInterface
     */
    protected function addClauseCondWithBind(string! clause, string! andor, var args) -> <\Pdm\Query\QueryInterface>
    {
        var cond, binds, bindName, value, clauses;

        if typeof args != "array" {
            throw new \InvalidArgumentException("args must be array.");
        }

        // remove the condition from the args
        let cond = (string) array_shift(args);

        // remaining args are bind values; e.g., this->bindWhere, this->bindHaving
        let bindName = "bind" . ucwords(clause);
        if property_exists(this, bindName) {
            let binds = this->{bindName};

            if unlikely typeof binds != "array" {
                throw new \RuntimeException(bindName . " must be an array.");
            }

            for value in args {
                let binds[] = value;
            }

            let this->{bindName} = binds;
        } else {
            echo bindName . " is not a property 1\n";
        }

        // add condition to clause; this->where, this->having
        if property_exists(this, clause) {
            let clauses = this->{clause};
            if typeof clauses != "array" {
                let clauses = [clauses];
            }

            if !empty clauses {
                let clauses[] = andor . " " . cond;
            } else {
                let clauses[] = cond;
            }
            let this->{clause} = clauses;
        } else {
            echo clause . " is not a property 2\n";
        }

        return this;
    }

    /**
     * Adds a column order to the query.
     *
     * @param array $spec The columns and direction to order by.
     * @return QueryInterface
     */
    protected function addOrderBy(var spec) -> <\Pdm\Query\QueryInterface>
    {
        var col;

        if typeof spec != "array" {
            throw new \InvalidArgumentException("spec must be array.");
        }

        for col in spec {
            let this->orderBy[] = col;
        }
        return this;
    }

    /**
     * Builds the flags as a space-separated string.
     *
     * @return string
     */
    protected function buildFlags() -> string
    {
        if empty this->flags {
            return "";
        }
        return " " . implode(" ", array_keys(this->flags));
    }

    /**
     * Builds the `WHERE` clause of the statement.
     *
     * @return string
     */
    protected function buildWhere() -> string
    {
        if unlikely empty this->where {
            return "";
        }

        return PHP_EOL . "WHERE" . this->indent(this->where);
    }

    /**
     * Builds the `ORDER BY ...` clause of the statement.
     *
     * @return string
     */
    protected function buildOrderBy() -> string
    {
        if empty this->orderBy {
            return "";
        }

        return PHP_EOL . "ORDER BY" . this->indentCsv(this->orderBy);
    }

    /**
     * Builds the `LIMIT ... OFFSET` clause of the statement.
     *
     * @return string
     */
    protected function buildLimit() -> string
    {
        var hasLimit, hasOffset, clause;

        let hasLimit = this instanceof LimitInterface;
        let hasOffset = this instanceof LimitOffsetInterface;

        if hasOffset && this->limit {
            let clause = PHP_EOL . "LIMIT " . this->limit;
            if this->offset {
                let clause .= " OFFSET " . this->offset;
            }
            return clause;
        } else {
            if hasLimit && this->limit {
                return PHP_EOL . "LIMIT " . this->limit;
            }
        }

        // not applicable
        return "";
    }
}
