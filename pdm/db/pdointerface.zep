%{
#include <ext/pdo/php_pdo_driver.h>
}%

/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Db
 *
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Db;

/**
 * An interface to the native PDO object, with additional extended methods.
 *
 * @package Pdm\Db
 */
interface PdoInterface
{
    /**
     * Begins a transaction and turns off autocommit mode.
     *
     * @return bool True on success, false on failure.
     * @see http://php.net/manual/en/pdo.begintransaction.php
     */
    public function beginTransaction() -> boolean;

    /**
     * Commits the existing transaction and restores autocommit mode.
     *
     * @return bool True on success, false on failure.
     * @see http://php.net/manual/en/pdo.commit.php
     */
    public function commit() -> boolean;

    /**
     * Gets the most recent error code.
     *
     * @return mixed
     * @see http://php.net/manual/en/pdo.errorcode.php
     */
    public function errorCode();

    /**
     * Gets the most recent error info.
     *
     * @return array
     * @see http://php.net/manual/en/pdo.errorinfo.php
     */
    public function errorInfo() -> array;

    /**
     * Executes an SQL statement and returns the number of affected rows.
     *
     * @param string $statement The SQL statement to execute.
     * @return int The number of rows affected.
     * @see http://php.net/manual/en/pdo.exec.php
     */
    public function exec(string! statement) -> int | boolean;

    /**
     * Gets a PDO attribute value.
     *
     * @param mixed $attribute The PDO::ATTR_* constant.
     * @return mixed The value for the attribute.
     * @see http://php.net/manual/en/pdo.getattribute.php
     */
    public function getAttribute(var attribute);

    /**
     * Is a transaction currently active?
     *
     * @return bool
     * @see http://php.net/manual/en/pdo.intransaction.php
     */
    public function inTransaction() -> boolean;

    /**
     * Returns the last inserted autoincrement sequence value.
     *
     * @param string $name The name of the sequence to check; typically needed
     * only for PostgreSQL, where it takes the form of `<table>_<column>_seq`.
     * @return int
     * @see http://php.net/manual/en/pdo.lastinsertid.php
     */
    public function lastInsertId(string! name = null) -> int;

    /**
     * Prepares an SQL statement for execution.
     *
     * @param string $statement The SQL statement to prepare for execution.
     * @param array $options Set these attributes on the returned
     * PDOStatement.
     * @return \PDOStatement
     * @see http://php.net/manual/en/pdo.prepare.php
     */
    public function prepare(string! statement, var options = []) -> <\PDOStatement>;

    /**
     * Queries the database and returns a PDOStatement.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param int $fetch_mode The `PDO::FETCH_*` type to set on the returned
     * `PDOStatement::setFetchMode()`.
     * @param mixed $fetch_arg1 The first additional argument to send to
     * `PDOStatement::setFetchMode()`.
     * @param mixed $fetch_arg2 The second additional argument to send to
     * `PDOStatement::setFetchMode()`.
     * @return \PDOStatement
     * @see http://php.net/manual/en/pdo.query.php
     */
    public function query(string! statement, var fetch_mode = null, var fetch_arg1 = null, var fetch_arg2 = null) -> <\PDOStatement>;

    /**
     * Quotes a value for use in an SQL statement.
     *
     * @param mixed $value The value to quote.
     * @param int $parameter_type A data type hint for the database driver.
     * @return mixed The quoted value.
     * @see http://php.net/manual/en/pdo.quote.php
     */
    public function quote(var value, var parameter_type = \PDO::PARAM_STR);

    /**
     * Rolls back the current transaction and restores autocommit mode.
     *
     * @return bool True on success, false on failure.
     * @see http://php.net/manual/en/pdo.rollback.php
     */
    public function rollBack() -> boolean;

    /**
     * Sets a PDO attribute value.
     *
     * @param mixed $attribute The PDO::ATTR_* constant.
     * @param mixed $value The value for the attribute.
     * @return bool
     * @see http://php.net/manual/en/pdo.setattribute.php
     */
    public function setAttribute(var attribute, var value) -> boolean;

    /**
     * Returns all currently available PDO drivers.
     *
     * @return array
     * @see http://php.net/manual/en/pdo.getavailabledrivers.php
     */
    public static function getAvailableDrivers() -> array;

    /**
     * Connects to the database and sets PDO attributes.
     *
     * @return null
     * @throws \PDOException if the connection fails.
     */
    public function connect() -> void;

    /**
     * Performs a statement and returns the number of affected rows.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return array
     */
    public function fetchAffected(string! statement, var values = []) -> array;

    /**
     * Fetches a sequential array of rows from the database; the rows
     * are represented as associative arrays.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @return array
     */
    public function fetchAll(string! statement, var values = [], var callback = null) -> array;

    /**
     * Fetches an associative array of rows from the database; the rows
     * are represented as associative arrays. The array of rows is keyed
     * on the first column of each row.
     *
     * N.b.: if multiple rows have the same first column value, the last
     * row with that value will override earlier rows.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @return array
     */
    public function fetchAssoc(string! statement, var values = [], var callback = null) -> array;

    /**
     * Fetches the first column of rows as a sequential array.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @return array
     */
    public function fetchCol(string! statement, var values = [], var callback = null) -> array;

    /**
     * Fetches one row from the database as an object, mapping column values
     * to object properties.
     *
     * Warning: PDO "injects property-values BEFORE invoking the constructor -
     * in other words, if your class initializes property-values to defaults
     * in the constructor, you will be overwriting the values injected by
     * fetchObject() !"
     * <http://www.php.net/manual/en/pdostatement.fetchobject.php#111744>
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param string $className The name of the class to create.
     * @param array $ctor_args Arguments to pass to the object constructor.
     * @return object
     */
    public function fetchObject(string! statement, var values = [], string! className = "StdClass", var $ctor_args = []);

    /**
     * Fetches a sequential array of rows from the database; the rows
     * are represented as objects, where the column values are mapped to
     * object properties.
     *
     * Warning: PDO "injects property-values BEFORE invoking the constructor -
     * in other words, if your class initializes property-values to defaults
     * in the constructor, you will be overwriting the values injected by
     * fetchObject() !"
     * <http://www.php.net/manual/en/pdostatement.fetchobject.php#111744>
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param string $class_name The name of the class to create from each
     * row.
     * @param array $ctor_args Arguments to pass to each object constructor.
     * @return array
     */
    public function fetchObjects(string! statement, var values = [], string! className = "StdClass", var $ctor_args = []) -> array;

    /**
     * Fetches one row from the database as an associative array.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return array
     */
    public function fetchOne(string! statement, var values = []) -> array;

    /**
     * Fetches an associative array of rows as key-value pairs (first
     * column is the key, second column is the value).
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @param array $values Values to bind to the query.
     * @return array
     */
    public function fetchPairs(string! statement, var values = [], var callback = null) -> array;

    /**
     * Fetches the very first value (i.e., first column of the first row).
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return mixed
     */
    public function fetchValue(string! statement, var values = []);

    /**
     * Returns the DSN for a lazy connection; if the underlying PDO instance
     * was injected at construction time, this will be null.
     *
     * @return string|null
     */
    public function getDsn() -> string|null;

    /**
     * Returns the underlying PDO connection object.
     *
     * @return PDO
     */
    public function getPdo() -> <\PDO>;

    /**
     * Returns the profiler object.
     *
     * @return ProfilerInterface
     */
    public function getProfiler() -> <\Pdm\Db\ProfilerInterface>;

    /**
     * Is the instance connected to a database?
     *
     * @return bool
     */
    public function isConnected() -> boolean;

    /**
     * Performs a query after preparing the statement with bound values, then
     * returns the result as a PDOStatement.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return \PDOStatement
     */
    public function perform(string! statement, var values = []) -> <\PDOStatement>;

    /**
     * Sets the profiler object.
     *
     * @param ProfilerInterface $profiler
     * @return void
     */
    public function setProfiler(<\Pdm\Db\ProfilerInterface> $profiler) -> void;
}
