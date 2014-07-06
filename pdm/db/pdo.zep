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
 * This extended decorator for PDO provides lazy connection, array quoting, a
 * new `perform()` method, and new `fetch*()` methods.
 */
class Pdo extends \PDO implements PdoInterface
{
    /**
     * The instance of PDO being decorated.
     *
     * @var PDO
     */
    protected pdo;

    /**
     * The attributes for a lazy connection.
     *
     * @var array
     */
    protected attributes;

    /**
     * The DSN for a lazy connection.
     *
     * @var string
     */
    protected dsn;

    /**
     * PDO options for a lazy connection.
     *
     * @var array
     */
    protected options;

    /**
     *
     * The password for a lazy connection.
     *
     * @var string
     *
     */
    protected password;

    /**
     *
     * The current profile information.
     *
     * @var array
     *
     */
    protected profile;

    /**
     *
     * A query profiler.
     *
     * @var ProfilerInterface
     *
     */
    protected profiler;

    /**
     *
     * The username for a lazy connection.
     *
     * @var string
     *
     */
    protected username;

    /**
     *
     * This constructor is pseudo-polymorphic. You may pass a normal set of PDO
     * constructor parameters, and ExtendedPdo will use them for a lazy
     * connection. Alternatively, if the `$dsn` parameter is an existing PDO
     * instance, that instance will be decorated by ExtendedPdo; the remaining
     * parameters will be ignored.
     *
     * @param PDO|string $dsn The data source name for a lazy PDO connection,
     * or an existing instance of PDO. If the latter, the remaining params are
     * ignored.
     * @param string $username The username for a lazy connection.
     * @param string $password The password for a lazy connection.
     * @param array $options Driver-specific options for a lazy connection.
     * @param array $attributes Attributes to set after a lazy connection.
     * @see http://php.net/manual/en/pdo.construct.php
     *
     */
    public function __construct(var dsn, string! username = null, string! password = null, var options = [], var attributes = [])
    {
        let this->attributes = [];
        let this->attributes[\PDO::ATTR_ERRMODE] = \PDO::ERRMODE_EXCEPTION;
        let this->attributes[\PDO::ATTR_EMULATE_PREPARES] = true;
        let this->attributes[\PDO::ATTR_CASE] = \PDO::CASE_LOWER;

        let this->dsn = "";
        let this->profile = [];
        let this->username = username;
        let this->password = password;
        let this->options = options;
        let this->attributes = array_replace(this->attributes, attributes);

        if typeof dsn == "string" {
            let this->dsn = dsn;
        } else {
            if dsn instanceof \PDO {
                let this->pdo = <\PDO> dsn;
            } else {
                throw new \InvalidArgumentException("$dsn must be string or PDO");
            }
        }
    }

    /**
     * Begins a transaction and turns off autocommit mode.
     *
     * @return bool True on success, false on failure.
     * @see http://php.net/manual/en/pdo.begintransaction.php
     */
    public function beginTransaction() -> boolean
    {
        var result;

        //this->connect();
        this->beginProfile(__FUNCTION__);
        //let result = this->pdo->beginTransaction();
        let result = this->getPdo()->beginTransaction();
        this->endProfile();
        return result;
    }

    /**
     * Commits the existing transaction and restores autocommit mode.
     *
     * @return bool True on success, false on failure.
     * @see http://php.net/manual/en/pdo.commit.php
     */
    public function commit() -> boolean
    {
        var result;

        //this->connect();
        this->beginProfile(__FUNCTION__);
        //let result = this->pdo->commit();
        let result = this->getPdo()->commit();
        this->endProfile();
        return result;
    }

    /**
     * Connects to the database and sets PDO attributes.
     *
     * @return null
     * @throws PDOException if the connection fails.
     */
    public function connect() -> void
    {
        var attribute, value;

        // don't connect twice
        if typeof this->pdo != "null" {
            return;
        }

        // connect to the database
        this->beginProfile(__FUNCTION__);
        let this->pdo = new \PDO(
            this->dsn,
            this->username,
            this->password,
            this->options
        );
        this->endProfile();

        // set attributes
        for attribute, value in this->attributes {
            this->setAttribute(attribute, value);
        }
    }

    /**
     * Gets the most recent error code.
     *
     * @return mixed
     */
    public function errorCode()
    {
        //this->connect();
        //return this->pdo->errorCode();
        return this->getPdo()->errorCode();
    }

    /**
     * Gets the most recent error info.
     *
     * @return array
     */
    public function errorInfo() -> array
    {
        //this->connect();
        //return this->pdo->errorInfo();
        return this->getPdo()->errorInfo();
    }

    /**
     * Executes an SQL statement and returns the number of affected rows.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @return int The number of affected rows.
     * @see http://php.net/manual/en/pdo.exec.php
     */
    public function exec(string! statement) -> int | boolean
    {
        var affectedRows;

        //this->connect();
        this->beginProfile(__FUNCTION__);
        //let affectedRows = this->pdo->exec(statement);
        let affectedRows = this->getPdo()->exec(statement);
        this->endProfile(statement);

        return affectedRows;
    }

    /**
     * Performs a statement and returns the number of affected rows.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return int
     */
    public function fetchAffected(string! statement, var values = []) -> int
    {
        var sth;
        let sth = this->perform(statement, values);
        return sth->rowCount();
    }

    /**
     * Fetches a sequential array of rows from the database; the rows
     * are returned as associative arrays.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @return array
     */
    public function fetchAll(string! statement, var values = [], var callback = null) -> array
    {
        return this->fetchAllWithCallable(\PDO::FETCH_ASSOC, statement, values, callback);
    }

    /**
     * Fetch array using a callable
     * @param int $fetchType
     * @param string $statement
     * @param array $values
     * @param callable $callback
     * @return array
     */
    protected function fetchAllWithCallable(var fetchType, string! statement, var values = [], var callback = null) -> array
    {
        var sth, data;

        let sth = this->perform(statement, values);

        if typeof fetchType != "integer" {
            let fetchType = (int) fetchType;
        }

        if fetchType == \PDO::FETCH_COLUMN {
            let data = sth->fetchAll(fetchType, 0);
        } else {
            let data = sth->fetchAll(fetchType);
        }

        return this->applyCallableToFetchAll(callback, data);
    }

    protected function applyCallableToFetchAll(var callback, var data) -> array
    {
        var key, row;

        if typeof callback == "object" {
            for key, row in data {
                let data[key] = call_user_func(callback, row);
            }
        }

        return data;
    }

    /**
     * Fetches an associative array of rows from the database; the rows
     * are returned as associative arrays, and the array of rows is keyed
     * on the first column of each row.
     *
     * N.b.: If multiple rows have the same first column value, the last
     * row with that value will override earlier rows.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @return array
     */
    public function fetchAssoc(string! statement, var values = [], var callback = null) -> array
    {
        var sth, data, row, key;

        let sth = this->perform(statement, values);
        let data = [];


        loop {
            let row = sth->$fetch(\PDO::FETCH_ASSOC);
            if !row {
                break;
            }

            let key = current(row);
            if typeof callback == "null" {
                let data[key] = row;
            } else {
                if typeof callback != "null" {
                    let data[key] = call_user_func(callback, row);
                } else {
                    let data[key] = row;
                }
            }

        }

        return data;
    }

    /**
     * Fetches the first column of rows as a sequential array.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @param callable $callback A callable to be applied to each of the rows
     * to be returned.
     * @return array
     */
    public function fetchCol(string! statement, var values = [], var callback = null) -> array
    {
        return this->fetchAllWithCallable(\PDO::FETCH_COLUMN, statement, values, callback);
    }

    /**
     * Fetches one row from the database as an object where the column values
     * are mapped to object properties.
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
    public function fetchObject(string! statement, var values = [], string! className = "StdClass", var ctor_args = [])
    {
        var sth;
        let sth = this->perform(statement, values);
        return sth->fetchObject(className, ctor_args);
    }

    /**
     * Fetches a sequential array of rows from the database; the rows
     * are returned as objects where the column values are mapped to
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
     * @param string $className The name of the class to create from each
     * row.
     * @param array $ctor_args Arguments to pass to each object constructor.
     * @return array
     */
    public function fetchObjects(string! statement, var values = [], string! className = "StdClass", var ctor_args = []) -> array
    {
        var sth;
        let sth = this->perform(statement, values);
        return sth->fetchAll(\PDO::FETCH_CLASS, className, ctor_args);
    }

    /**
     * Fetches one row from the database as an associative array.
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return array
     */
    public function fetchOne(statement, var values = []) -> array
    {
        var sth;
        let sth = this->perform(statement, values);
        return sth->$fetch(\PDO::FETCH_ASSOC);
    }

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
    public function fetchPairs(string! statement, var values = [], var callback = null) -> array
    {
        var sth, data, row;

        let sth = this->perform(statement, values);

        if typeof callback != "null" {
            let data = [];
            loop {
                let row = sth->$fetch(\PDO::FETCH_NUM);
                if !row {
                    break;
                }

                // apply the callback first so the key can be modified
                if typeof callback != "null" {
                    let row = call_user_func(callback, row);
                }

                // now retain the data
                let data[row[0]] = row[1];
            }
        } else {
            let data = sth->fetchAll(\PDO::FETCH_KEY_PAIR);
        }

        return data;
    }

    /**
     * Fetches the very first value (i.e., first column of the first row).
     *
     * @param string $statement The SQL statement to prepare and execute.
     * @param array $values Values to bind to the query.
     * @return mixed
     */
    public function fetchValue(string! statement, var values = [])
    {
        var sth;
        let sth = this->perform(statement, values);
        return sth->fetchColumn(0);
    }

    /**
     * Gets a PDO attribute value.
     *
     * @param mixed $attribute The PDO::ATTR_* constant.
     * @return mixed The value for the attribute.
     */
    public function getAttribute(var attribute)
    {
        //this->connect();
        //return this->pdo->getAttribute(attribute);
        return this->getPdo()->getAttribute(attribute);
    }

    /**
     * Returns the DSN for a lazy connection; if the underlying PDO instance
     * was injected at construction time, this will be null.
     *
     * @return string|null
     */
    public function getDsn() -> string|null
    {
        return this->dsn;
    }

    /**
     * Returns the underlying PDO connection object.
     *
     * @return PDO
     */
    public function getPdo() -> <\PDO>
    {
        this->connect();
        if this->pdo {
            return this->pdo;
        }
        throw new \Pdm\Db\Exception("Invalid PDO");
    }

    /**
     * Returns the profiler object.
     *
     * @return ProfilerInterface
     */
    public function getProfiler() -> <\Pdm\Db\ProfilerInterface>
    {
        return this->profiler;
    }

    /**
     * Is a transaction currently active?
     *
     * @return bool
     * @see http://php.net/manual/en/pdo.intransaction.php
     */
    public function inTransaction() -> boolean
    {
        var result;

        //this->connect();
        this->beginProfile(__FUNCTION__);
        //let result = this->pdo->inTransaction();
        let result = this->getPdo()->inTransaction();
        this->endProfile();

        return result;
    }

    /**
     * Is this instance connected to a database?
     *
     * @return bool
     */
    public function isConnected() -> boolean
    {
        return typeof this->pdo == "object";
    }

    /**
     * Returns the last inserted autoincrement sequence value.
     *
     * @param string $name The name of the sequence to check; typically needed
     * only for PostgreSQL, where it takes the form of `<table>_<column>_seq`.
     * @return int
     * @see http://php.net/manual/en/pdo.lastinsertid.php
     */
    public function lastInsertId(string! name = null) -> int
    {
        var result;

        //this->connect();
        this->beginProfile(__FUNCTION__);
        //let result = this->pdo->lastInsertId(name);
        let result = this->getPdo()->lastInsertId(name);
        this->endProfile();

        return result;
    }

    /**
     * Performs a query with bound values and returns the resulting
     * PDOStatement; array values will be passed through `quote()` and their
     * respective placeholders will be replaced in the query string.
     *
     * @param string $statement The SQL statement to perform.
     * @param array $values Values to bind to the query
     * @return PDOStatement
     * @see quote()
     */
    public function perform(string! statement, var values = [])
    {
        var sth;

        let sth = this->prepareWithValues(statement, values);
        this->beginProfile(__FUNCTION__);
        sth->execute();
        this->endProfile(statement, values);
        return sth;
    }

    /**
     * Prepares an SQL statement for execution.
     *
     * @param string $statement The SQL statement to prepare for execution.
     * @param array $options Set these attributes on the returned
     * PDOStatement.
     * @return PDOStatement
     * @see http://php.net/manual/en/pdo.prepare.php
     */
    public function prepare(string! statement, var options = null) -> boolean
    {
        if typeof options != "array" {
            let options = [];
        }

        //this->connect();
        //return this->pdo->prepare(statement, options);
        return this->getPdo()->prepare(statement, options);
    }

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
     * @return PDOStatement
     * @see http://php.net/manual/en/pdo.query.php
     */
    public function query(string! statement, var fetch_mode = null, var fetch_arg1 = null, var fetch_arg2 = null) -> <\PDOStatement>
    {
        var sth;
        var pdo;

        if typeof statement != "string" {
            throw new \InvalidArgumentException("$statement must be a string");
        }

        let pdo = this->getPdo();
        //this->connect();
        this->beginProfile(__FUNCTION__);

        let sth = call_user_func_array(
            [pdo, "query"],
            func_get_args()
        );
        this->endProfile(sth->queryString);

        return sth;
    }

    /**
     * Quotes a value for use in an SQL statement.
     *
     * This differs from `PDO::quote()` in that it will convert an array into
     * a string of comma-separated quoted values.
     *
     * @param mixed $value The value to quote.
     * @param int $parameterType A data type hint for the database driver.
     * @return mixed The quoted value.
     * @see http://php.net/manual/en/pdo.quote.php
     */
    public function quote(var value, var parameterType = \PDO::PARAM_STR)
    {
        var k, v;
        var pdo;

        let pdo = this->getPdo();
        let parameterType = (int) parameterType;
        //this->connect();

        // non-array quoting
        if typeof value != "array" {
            //return this->pdo->quote(value, parameterType);
            return pdo->quote(value, parameterType);
        }

        // quote array values, not keys, then combine with commas
        for k, v in value {
            //let value[k] = this->pdo->quote(v, parameterType);
            let value[k] = pdo->quote(v, parameterType);
        }

        return implode(", ", value);
    }

    /**
     * Rolls back the current transaction, and restores autocommit mode.
     *
     * @return bool True on success, false on failure.
     * @see http://php.net/manual/en/pdo.rollback.php
     */
    public function rollBack() -> boolean
    {
        var result;

        //this->connect();
        this->beginProfile(__FUNCTION__);
        //let result = this->pdo->rollBack();
        let result = this->getPdo()->rollBack();
        this->endProfile();

        return result;
    }

    /**
     * Sets a PDO attribute value.
     *
     * @param mixed $attribute The PDO::ATTR_* constant.
     * @param mixed $value The value for the attribute.
     * @return bool True on success, false on failure. Note that if PDO has not
     * not connected, all calls will be treated as successful.
     */
    public function setAttribute(var attribute, var value) -> boolean
    {
        if this->pdo {
            return this->pdo->setAttribute(attribute, value);
        }

        let this->attributes[attribute] = value;
        return true;
    }

    /**
     * Sets the profiler object.
     *
     * @param ProfilerInterface $profiler
     * @return void
     */
    public function setProfiler(<\Pdm\Db\ProfilerInterface> profiler) -> void
    {
        let this->profiler = profiler;
    }

    /**
     * Begins a profile entry.
     *
     * @param string $functionName The function starting the profile entry.
     * @return void
     */
    protected function beginProfile(string! functionName) -> void
    {
        // if there's no profiler, can't profile
        if !this->profiler {
            return;
        }

        // retain starting profile info
        let this->profile["time"] = microtime(true);
        let this->profile["function"] = functionName;
    }

    /**
     * Ends and records a profile entry.
     *
     * @param string $statement The statement being profiled, if any.
     * @param array values
     * @return void
     */
    protected function endProfile(string! statement = "", var values = []) -> void
    {
        // is there a profiler in place?
        if this->profiler {
            // add an entry to the profiler
            this->profiler->addProfile(
                microtime(true) - this->profile["time"],
                this->profile["function"],
                statement,
                values
            );
        }

        // clear the starting profile info
        let this->profile = [];
    }

    /**
     * Prepares an SQL statement with bound values.
     *
     * This method only binds values that have placeholders in the
     * statement, thereby avoiding errors from PDO regarding too many bound
     * values. It also binds all sequential (question-mark) placeholders.
     *
     * If a placeholder value is an array, the array is converted to a string
     * of comma-separated quoted values; e.g., for an `IN (...)` condition.
     * The quoted string is replaced directly into the statement instead of
     * using `PDOStatement::bindValue()` proper.
     *
     * @param string $statement The SQL statement to prepare for execution.
     * @return PDOStatement
     * @see http://php.net/manual/en/pdo.prepare.php
     */
    public function prepareWithValues(string! statement, var values = []) -> <\PDOStatement>
    {
        var rebuild, key, value, sth;

        if typeof statement != "string" {
            throw new \InvalidArgumentException("$statment must be a string");
        }

        if typeof values != "array" {
            throw new \InvalidArgumentException("$values must be array");
        }

        // if there are no values to bind, use the normal preparation
        if empty values {
            return this->prepare(statement);
        }

        // rebuild the statement and values
        let rebuild = this->rebuild(statement, values);

        // prepare the statement
        let sth = this->prepare(rebuild[0]);

        // for the placeholders we found, bind the corresponding data values
        for key, value in rebuild[1] {
            sth->bindValue(key, value);
        }

        return sth;
    }

    /**
     * Returns a new anonymous object to track bind values.
     *
     * @param array $values The values to bind and/or replace into a statement.
     * @return mixed
     */
    protected function newBindTracker(var values) -> <\Pdm\Db\BindTracker>
    {
        if typeof values != "array" {
            let values = [];
        }

        // anonymous object to track preparation info
        return new BindTracker(values);
    }

    /**
     * Rebuilds a statement with array values replaced into placeholders.
     *
     * @param string $statement The statement to rebuild.
     * @param array $values The values to bind and/or replace into a statement.
     * @return array An array where element 0 is the rebuilt statement and
     * element 1 is the rebuilt array of values.
     */
    protected function rebuild(string! statement, var values) -> array
    {
        var bind;

        if typeof values != "array" {
            let values = [];
        }

        let bind = <\Pdm\Db\BindTracker> this->newBindTracker(values);
        let statement = this->rebuildStatement(statement, bind);
        return [statement, bind->finalValues];
    }

    protected function rebuildStatement(string! statement, <\Pdm\Db\BindTracker> bind) -> array
    {
        var apos, quot, regex, parts;

        // find all parts not inside quotes or backslashed-quotes
        let apos = "'";
        let quot = "\"";
        let regex = "/((" . apos . "+|" . quot . "+|\\" . apos . "+|\\" . quot . "+).*?)\\2/m";

        let parts = preg_split(
            regex,
            statement,
            -1,
            PREG_SPLIT_DELIM_CAPTURE
        );

        return this->rebuildParts(parts, bind);
    }

    protected function rebuildParts(var parts, <\Pdm\Db\BindTracker> bind) -> array
    {
        var k, i;

        // loop through the non-quoted parts (0, 3, 6, 9, etc.)
        let k = count(parts);
        let i = 0;

        while i <= k {
            let parts[i] = this->rebuildPart(parts[i], bind);
            let i += 3;
        }

        return implode("", parts);
    }

    protected function rebuildPart(var part, <\Pdm\Db\BindTracker> bind) -> array
    {
        var subs, regex;

        let regex = "/(:[a-zA-Z_][a-zA-Z0-9_]*)|(\?)/m";

        // split into subparts by ":name" and "?"
        let subs = preg_split(
            regex,
            part,
            -1,
            PREG_SPLIT_DELIM_CAPTURE
        );

        // check subparts to convert bound arrays to quoted CSV strings
        let subs = this->prepareValuePlaceholders(subs, bind);

        // reassemble
        return implode("", subs);
    }

    /**
     * Prepares the sub-parts of a query with placeholders.
     *
     * @param array $subs The query subparts.
     * @param BindTracker $bind The preparation info object.
     * @return array The prepared subparts.
     */
    protected function prepareValuePlaceholders(var subs, <\Pdm\Db\BindTracker> bind) -> array
    {
        var character, i, sub;

        for i, sub in subs {
            let character = substr(sub, 0, 1);

            if character == "?" {
                let subs[i] = this->prepareNumberedPlaceholder(sub, bind);
            }

            if character == ":" {
                let subs[i] = this->prepareNamedPlaceholder(sub, bind);
            }
        }

        return subs;
    }

    /**
     * Bind or quote a numbered placeholder in a query subpart.
     *
     * @param string $sub The query subpart.
     * @param BindTracker $bind The preparation info object.
     * @return string The prepared query subpart.
     */
    protected function prepareNumberedPlaceholder(var sub, <\Pdm\Db\BindTracker> bind) -> string
    {
        var bindArray, values, finalValues;

        if typeof sub != "string" {
            throw new \InvalidArgumentException("$sub must be a string");
        }

        // What numbered placeholder is this in the original statement?
        bind->setNum(bind->num + 1);

        // If index 0 is set, prepend a 0 to the beginning
        if isset bind->values[0] {
            let values = bind->values;
            array_unshift(values, 0);
            unset values[0];
            bind->setValues(values);
        }

        // is the corresponding data element an array?
        if isset bind->values[bind->num] {
            if typeof bind->values[bind->num] == "array" {
                let bindArray = true;
            } else {
                let bindArray = false;
            }
        } else {
            let bindArray = false;
        }

        if bindArray {
            // PDO won't bind an array; quote and replace directly
            let sub = this->quote(bind->values[bind->num]);
        } else {
            // increase the count of numbered placeholders to be bound
            bind->setCount(bind->count + 1);
            let finalValues = bind->finalValues;
            let finalValues[bind->count] = bind->values[bind->num];
            bind->setFinalValues(finalValues);
        }

        return sub;
    }

    /**
     * Bind or quote a named placeholder in a query subpart.
     *
     * @param string $sub The query subpart.
     * @param BindTracker $bind The preparation info object.
     * @return string The prepared query subpart.
     */
    protected function prepareNamedPlaceholder(var sub, <\Pdm\Db\BindTracker> bind) -> string
    {
        var name, bindArray, finalValues;

        if typeof sub != "string" {
            throw new \InvalidArgumentException("$sub must be a string");
        }

        let name = substr(sub, 1);

        // is the corresponding data element an array?
        if isset bind->values[name] {
            if typeof bind->values[name] == "array" {
                let bindArray = true;
            }
        } else {
            let bindArray = false;
        }

        if bindArray {
            // PDO won't bind an array; quote and replace directly
            let sub = this->quote(bind->values[name]);
        } else {
            // not an array, retain the placeholder for later
            let finalValues = bind->finalValues;
            let finalValues[name] = bind->values[name];
            bind->setFinalValues(finalValues);
        }

        return sub;
    }
}
