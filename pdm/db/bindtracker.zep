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
class BindTracker
{
    /**
     * How many numbered placeholders in the original statement
     *
     * @var int
     */
    public num { get };

    /*
     * how many numbered placeholders to actually be bound; this may
     * differ from 'num' in that some numbered placeholders may get
     * replaced with quoted CSV strings
     *
     * @var int
     */
    public count { get };

    /**
     * Initial values to be bound
     *
     * @var array
     */
    public values { get };

    /**
     * Named and numbered placeholders to bind at the end
     *
     * @var array
     */
    public finalValues { get };

    /**
     * Constructor
     *
     * @param array $values
     */
    public function __construct(array values = [])
    {
        let this->num = 0;
        let this->count = 0;
        let this->values = values;
        let this->finalValues = [];
    }

    /**
     * Magic setter
     *
     * @param string key
     * @param mixed value
     * @return void
     */
    public function __set(string! key, var value) -> void
    {
        switch (key) {
            case "num":
                this->setNum(value);
                break;

            case "count":
                this->setCount(value);
                break;

            case "values":
                this->setValues(value);
                break;

            case "finalValues":
                this->setFinalValues(value);
                break;
        }
    }

    /**
     * Set the num
     *
     * @param int value
     * @return void
     */
    public function setNum(int value)
    {
        let this->num = value;
    }

    /**
     * Set the count
     *
     * @param int value
     * @return void
     */
    public function setCount(int value)
    {
        let this->count = value;
    }

    /**
     * Set the values
     *
     * @param array value
     * @return void
     */
    public function setValues(array value)
    {
        let this->values = value;
    }

    /**
     * Set the final values
     *
     * @param array value
     * @return void
     */
    public function setFinalValues(array value)
    {
        let this->finalValues = value;
    }
}
