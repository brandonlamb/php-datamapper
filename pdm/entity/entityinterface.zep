
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
interface EntityInterface
{
    /**
     * Constructor
     *
     * @param Pdm\Di\ContainerInterface di
     * @param Pdm\Entity\ManagerInterface entityManager
     */
    public function __construct(
        <\Pdm\Di\ContainerInterface> di = null,
        <\Pdm\Entity\ManagerInterface> entityManager = null
    );

    /**
     * Returns schema name where table mapped is located
     *
     * @return string
     */
    public function getSchema() -> string;

    /**
     * Returns table name mapped in the model
     *
     * @return string
     */
    public function getTable() -> string;

    /**
     * Returns sequence name
     *
     * @return string
     */
    public function getSequence() -> string;

    /**
     * Returns entity manager
     *
     * @return \Pdm\Entity\ManagerInterface
     */
    public function getEntityManager();// -> <\Pdm\Entity\ManagerInterface>;

    /**
     * Returns the entity meta data definition
     *
     * @return array
     */
    public function metaData() -> array;

    /**
     * Returns the instance as an array representation
     *
     *<code>
     * print_r($entity->toArray());
     *</code>
     *
     * @return array
     */
    public function toArray() -> array;

    /**
     * Returns the class name of the entity
     *
     * @return string
     */
    public function toString() -> string;
}
