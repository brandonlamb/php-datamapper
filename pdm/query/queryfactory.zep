
/**
 * This file is part of Aura for PHP.
 *
 * @package \Pdm\Query
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Query;

/**
 * Creates query statement objects.
 *
 * @package Pdm\Query
 */
class QueryFactory
{
    /**
     * What database are we building for?
     *
     * @param string
     */
    protected db;

    /**
     * A map of `table.col` names to last-insert-id names.
     *
     * @var array
     */
    protected lastInsertIdNames = [];

    /**
     * Constructor.
     *
     * @param string $db The database type.
     * @param string $common Pass the constant self::COMMON to force common
     * query objects instead of db-specific ones.
     * @param array $lastInsertIdNames A map of `table.col` names to
     * last-insert-id names.
     */
    public function __construct(string! db)
    {
        let this->db = ucfirst(strtolower(db));
    }

    /**
     * Sets the last-insert-id names to be used for Insert queries..
     *
     * @param array $lastInsertIdNames A map of `table.col` names to
     * last-insert-id names.
     *
     * @return void
     */
    public function setLastInsertIdNames(var lastInsertIdNames) -> void
    {
        if typeof lastInsertIdNames != "array" {
            throw new \InvalidArgumentException("lastInsertIdNames must be array.");
        }
        let this->lastInsertIdNames = lastInsertIdNames;
    }

    /**
     * Returns a new SELECT object.
     *
     * @return Common\SelectInterface
     */
    public function newSelect() -> <\Pdm\Query\Common\SelectInterface>
    {
        return this->newInstance("Select");
    }

    /**
     * Returns a new INSERT object.
     *
     * @return Common\InsertInterface
     */
    public function newInsert() -> <\Pdm\Query\Common\InsertInterface>
    {
        var insert;
        let insert = this->newInstance("Insert");
        insert->setLastInsertIdNames(this->lastInsertIdNames);
        return insert;
    }

    /**
     * Returns a new UPDATE object.
     *
     * @return Common\UpdateInterface
     */
    public function newUpdate() -> <\Pdm\Query\Common\UpdateInterface>
    {
        return this->newInstance("Update");
    }

    /**
     * Returns a new DELETE object.
     *
     * @return Common\DeleteInterface
     */
    public function newDelete() -> <\Pdm\Query\Common\DeleteInterface>
    {
        return this->newInstance("Delete");
    }

    /**
     * Returns a new query object.
     *
     * @param string $query The query object type.
     * @return AbstractQuery
     */
    protected function newInstance(string! query) -> <\Pdm\Query\QueryInterface>
    {
        string className;
        let className = "\\Pdm\\Query\\" . this->db . "\\" . query;
        return new {className}();
    }
}
