
/**
 * DB2 PDO Adapter
 *
 * Specific functions for the DB2 database system
 *
 * <code>
 *   $connection = new \Pdm\Db\Adapter\Pdo\Db2($pdo);
 * </code>
 *
 * @package \Pdm\Db\Adapter\Pdo
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db\Adapter\Pdo;

use Pdm\Db\Adapter\AbstractPdo;
use Pdm\Db\AdapterInterface;

class Db2 extends AbstractPdo implements AdapterInterface
{
	/**
	 * @var string
	 */
	protected type = "db2" { get };

	/**
	 * @var string
	 */
	protected dialectType = "db2" { get };

    /**
     * {@inheritdoc}
     */
    public function lastInsertId(string! sequence = null)
    {
    	var statement;
    	var row;
    	var pdo;

    	let pdo = <\PDO> this->pdo;

        // If a sequence was passed then pass it through to the PDO method
        if typeof sequence != "null" {
            // Get previous value from sequence
            let statement = <\PDOStatement> this->pdo->query("VALUES PREVIOUS VALUE FOR " . sequence);
        } else {
            // Get last insert id from the identity_val_local() function
            let statement = <\PDOStatement> this->pdo->query("VALUES IDENTITY_VAL_LOCAL()");
        }

        let row = statement->$fetch(\PDO::FETCH_NUM);

        if isset row[0] {
        	return row[0];
    	} else {
    		return 0;
    	}
    }

    /**
     * {@inheritDoc}
     */
    public function supportSequences() -> boolean
    {
        return true;
    }
}
