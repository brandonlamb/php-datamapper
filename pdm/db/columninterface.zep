
/**
 * Interface for Db Column
 *
 * @package \Pdm\Db
 * @author Brandon Lamb <brandon@brandonlamb.com>
 */

namespace Pdm\Db;

/**
 * Pdm\Db\ColumnInterface
 *
 * Interface for Pdm\Db\Column
 */
interface ColumnInterface
{
	/**
	 * Pdm\Db\ColumnInterface constructor
	 *
	 * @param string columnName
	 * @param array definition
	 */
	public function __construct(string! columnName, array definition);

	/**
	 * Returns column name
	 *
	 * @return string
	 */
	public function getName() -> string;

	/**
	 * Returns column type
	 *
	 * @return int
	 */
	public function getType() -> int;

	/**
	 * Returns column size
	 *
	 * @return int
	 */
	public function getSize() -> int;

	/**
	 * Returns column scale
	 *
	 * @return int
	 */
	public function getScale() -> int;

	/**
	 * Check whether field absolute to position in table
	 *
	 * @return string
	 */
	public function getAfterPosition() -> string;

	/**
	 * Returns the type of bind handling
	 *
	 * @return int
	 */
	public function getBindType() -> int;

	/**
	 * Check whether column have an numeric type
	 *
	 * @return boolean
	 */
	public function isNumeric() -> boolean;

	/**
	 * Returns true if number column is unsigned
	 *
	 * @return boolean
	 */
	public function isUnsigned() -> boolean;

	/**
	 * Not null
	 *
	 * @return boolean
	 */
	public function isNotNull() -> boolean;

	/**
	 * Column is part of the primary key?
	 *
	 * @return boolean
	 */
	public function isPrimary() -> boolean;

	/**
	 * Identity/Auto-Increment
	 *
	 * @return boolean
	 */
	public function isIdentity() -> boolean;

	/**
	 * Sequence
	 *
	 * @return boolean
	 */
	public function isSequence() -> boolean;

	/**
	 * Check whether column have first position in table
	 *
	 * @return boolean
	 */
	public function isFirst() -> boolean;

	/**
	 * Restores the internal state of a Pdm\Db\Column object
	 *
	 * @param array data
	 * @return \Pdm\Db\ColumnInterface
	 */
	public static function __set_state(var data) -> <\Pdm\Db\ColumnInterface>;
}
