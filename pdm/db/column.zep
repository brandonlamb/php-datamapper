
/**
 * Pdm\Db\Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *<code>
 *	use Pdm\Db\Column as Column;
 *
 * //column definition
 * $column = new Column("id", [
 *   "type" => Column::TYPE_INTEGER,
 *   "size" => 10,
 *   "unsigned" => true,
 *   "numeric" => true,
 *   "notNull" => true,
 *   "identity" => true,
 *   "primary" => true,
 *   "first" => true,
 *   "default" => 1,
 * ]);
 *
 * //add column to existing table
 * $connection->addColumn("robots", null, $column);
 *</code>
 */

namespace Pdm\Db;

use Pdm\Db\ColumnInterface;

class Column implements ColumnInterface
{
	/**
	 * @var int, Integer abstract type
	 */
	const TYPE_INTEGER = 0;

	/**
	 * @var int, Date abstract type
	 */
	const TYPE_DATE = 1;

	/**
	 * @var int, Varchar abstract type
	 */
	const TYPE_VARCHAR = 2;

	/**
	 * @var int, Decimal abstract type
	 */
	const TYPE_DECIMAL = 3;

	/**
	 * @var int, Datetime abstract type
	 */
	const TYPE_DATETIME = 4;

	/**
	 * @var int, Char abstract type
	 */
	const TYPE_CHAR = 5;

	/**
	 * @var int, Text abstract data type
	 */
	const TYPE_TEXT = 6;

	/**
	 * @var int, Float abstract data type
	 */
	const TYPE_FLOAT = 7;

	/**
	 * @var int, Boolean abstract data type
	 */
	const TYPE_BOOLEAN = 8;

	/**
	 * @var int, Time abstract type
	 */
	const TYPE_TIME = 9;

	/**
	 * @var int, Bind Type Null
	 */
	const BIND_PARAM_NULL = 0;

	/**
	 * @var int, Bind Type Integer
	 */
	const BIND_PARAM_INT = 1;

	/**
	 * @var int, Bind Type String
	 */
	const BIND_PARAM_STR = 2;

	/**
	 * @var int, Bind Type Bool
	 */
	const BIND_PARAM_BOOL = 5;

	/**
	 * @var int, Bind Type Decimal
	 */
	const BIND_PARAM_DECIMAL = 32;

	/**
	 * @var int, Skip binding by type
	 */
	const BIND_SKIP = 1024;

	/**
	 * @var string, Column's name
	 */
	protected name { get };

	/**
	 * @var string, Column's alias
	 */
	protected alias { get };

	/**
	 * @var int, Column data type
	 */
	protected type = 2 { get };

	/**
	 * @var int, Bind Type
	 */
	protected bindType = 2 { get };

	/**
	 * @var string, Column Position
	 */
	protected afterPosition { get };

	/**
	 * @var int, Integer column size
	 */
	protected size = 0 { get };

	/**
	 * @var int, Integer column number scale
	 */
	protected scale = 0 { get };

	/**
	 * @var mixed, Default value for column
	 */
	protected defaultValue { get };

	/**
	 * @var boolean, The column have some numeric type?
	 */
	protected isNumeric = false;

	/**
	 * @var boolean, Integer column unsigned?
	 */
	protected isUnsigned = false;

	/**
	 * @var boolean, Column not nullable?
	 */
	protected isNotNull = false;

	/**
	 * @var boolean, Column is part of the primary key?
	 */
	protected isPrimary = false;

	/**
	 * @var boolean, Column is identity?
	 */
	protected isIdentity = false;

	/**
	 * @var boolean, Column is sequence?
	 */
	protected isSequence = false;

	/**
	 * @var boolean, Position is first
	 */
	protected isFirst = false;

	/**
	 * Pdm\Db\Column constructor
	 *
	 * @param string name
	 * @param array definition
	 */
	public function __construct(string! name, array definition)
	{
		var type, alias, bindType, size, scale, afterPosition, defaultValue, isNotNull,
		isPrimary, isUnsigned, isFirst, isNumeric, isIdentity, isSequence;

		let this->name = name;

		// Get the column type, one of the TYPE_* constants
		if fetch type, definition["type"] {
			let this->type = (int) type;
		} else {
			throw new Exception("Column type is required");
		}

		// Check if the field has an alias
		if fetch alias, definition["alias"] {
			let this->alias = trim(alias);
		}

		// The bind type to cast the field when passing it to PDO
		if fetch bindType, definition["bindType"] {
			let this->bindType = (int) bindType;
		}

		// Check if the field has a size defined
		if fetch size, definition["size"] {
			let this->size = (int) size;
		}

		// Check if the column has a decimal scale
		if fetch scale, definition["scale"] {
			if unlikely type != self::TYPE_INTEGER && type != self::TYPE_FLOAT && type != self::TYPE_DECIMAL {
				throw new Exception("Column type does not support scale parameter");
			}
			let this->scale = (int) scale;
		}

		// Name of the column which is placed before the current field
		if fetch afterPosition, definition["after"] {
			let this->afterPosition = afterPosition;
		}

		// The default value to set the field to
		if fetch defaultValue, definition["default"] {
			let this->defaultValue = defaultValue;
		}

		// Check if the field is nullable
		if fetch isNotNull, definition["notNull"] {
			let this->isNotNull = (boolean) isNotNull;
		}

		// Check if the field is primary key
		if fetch isPrimary, definition["primary"] {
			let this->isPrimary = (boolean) isPrimary;
		}

		// Check if the field is unsigned (only MySQL)
		if fetch isUnsigned, definition["unsigned"] {
			let this->isUnsigned = (boolean) isUnsigned;
		}

		// Check if the field is numeric
		if fetch isNumeric, definition["isNumeric"] {
			let this->isNumeric = (boolean) isNumeric;
		}

		// Check if the field is auto-increment/serial
		if fetch isIdentity, definition["identity"] {
			if unlikely type != self::TYPE_INTEGER {
				throw new Exception("Column type cannot be auto-increment");
			}
			let this->isIdentity = (boolean) isIdentity;
		}

		// Check if the field is auto-increment/serial
		if fetch isSequence, definition["sequence"] {
			if unlikely type != self::TYPE_INTEGER {
				throw new Exception("Column type cannot be sequence");
			}
			let this->isSequence = (boolean) isSequence;
		}

		// Check if the field is placed at the first position of the table
		if fetch isFirst, definition["first"] {
			let this->isFirst = (boolean) isFirst;
		}
	}

	/**
	 * Check whether column have an numeric type
	 *
	 * @return boolean
	 */
	public function isNumeric() -> boolean
	{
		return this->isNumeric;
	}

	/**
	 * Returns true if number column is unsigned
	 *
	 * @return boolean
	 */
	public function isUnsigned() -> boolean
	{
		return this->isUnsigned;
	}

	/**
	 * Not null
	 *
	 * @return boolean
	 */
	public function isNotNull() -> boolean
	{
		return this->isNotNull;
	}

	/**
	 * Column is part of the primary key?
	 *
	 * @return boolean
	 */
	public function isPrimary() -> boolean
	{
		return this->isPrimary;
	}

	/**
	 * Auto-Increment
	 *
	 * @return boolean
	 */
	public function isIdentity() -> boolean
	{
		return this->isIdentity;
	}

	/**
	 * Sequence
	 *
	 * @return boolean
	 */
	public function isSequence() -> boolean
	{
		return this->isSequence;
	}

	/**
	 * Check whether column have first position in table
	 *
	 * @return boolean
	 */
	public function isFirst() -> boolean
	{
		return this->isFirst;
	}

	/**
	 * Restores the internal state of a Pdm\Db\Column object
	 *
	 * @param array data
	 * @return \Pdm\Db\Column
	 */
	public static function __set_state(var data) -> <\Pdm\Db\ColumnInterface>
	{
		var definition, alias, columnType, bindType, size, afterPosition, isNotNull,
		isUnsigned, isNumeric, isFirst, isPrimary, isIdentity, isSequence;

		if typeof data != "array" {
			throw new Exception("Column state must be an array");
		}

		if !isset data["name"] {
			throw new Exception("Column name is required");
		}

		let definition = [];

		if fetch columnType, data["type"] {
			let definition["type"] = columnType;
		}

		if fetch alias, data["alias"] {
			let definition["alias"] = alias;
		}

		if fetch bindType, data["bindType"] {
			let definition["bindType"] = bindType;
		}

		if fetch size, data["size"] {
			let definition["size"] = size;
		}

		if fetch afterPosition, data["after"] {
			let definition["after"] = afterPosition;
		}

		if fetch isNumeric, data["isNumeric"] {
			let definition["isNumeric"] = isNumeric;
		}

		if fetch isUnsigned, data["unsigned"] {
			let definition["unsigned"] = isUnsigned;
		}

		if fetch isNotNull, data["notNull"] {
			let definition["notNull"] = isNotNull;
		}

		if fetch isPrimary, data["primary"] {
			let definition["primary"] = isPrimary;
		}

		if fetch isIdentity, data["identity"] {
			let definition["identity"] = isIdentity;
		}

		if fetch isSequence, data["sequence"] {
			let definition["sequence"] = isSequence;
		}

		if fetch isFirst, data["first"] {
			let definition["first"] = isFirst;
		}

		return new self(data["name"], definition);
	}
}
