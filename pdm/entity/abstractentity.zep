
/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Entity
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Entity;

/**
 * Entity Interface
 *
 * @package Pdm\Entity
 */
abstract class AbstractEntity implements EntityInterface
{
    /**
     * Constructor
     *
     * @param Pdm\Di\ContainerInterface di
     * @param Pdm\Entity\ManagerInterface entityManager
     */
    public function __construct(<\Pdm\Di\ContainerInterface> di = null, <\Pdm\Entity\ManagerInterface> entityManager = null)
    {

    }

    /**
     * Returns schema name where table mapped is located
     *
     * @return string
     */
    public function getSchema() -> string
    {
        return "";
    }

    /**
     * Returns table name mapped in the model
     *
     * @return string
     */
    public function getTable() -> string
    {
        return "";
    }

    /**
     * Returns sequence name
     *
     * @return string
     */
    public function getSequence() -> string
    {
        return "";
    }

    /**
     * Returns entity manager
     *
     * @return \Pdm\Entity\ManagerInterface
     */
    public function getEntityManager()// -> <\Pdm\Entity\ManagerInterface>
    {
        return "";
    }

    /**
     * Returns the entity meta data definition
     *
     * @return array
     */
    public function metaData() -> array
    {
        return [];
    }

    /**
     * Returns the instance as an array representation
     *
     *<code>
     * print_r($entity->toArray());
     *</code>
     *
     * @return array
     */
    public function toArray() -> array
    {
        return [];
    }

    /**
     * Returns the class name of the entity
     *
     * @return string
     */
    public function toString() -> string
    {
        return "";
    }
}
