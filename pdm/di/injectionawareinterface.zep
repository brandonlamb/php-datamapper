
/**
 * Pdm\Di\InjectionAwareInterface
 *
 * This interface must be implemented in those classes that uses internally the Pdm\Di that creates them
 */

namespace Pdm\Di;

interface InjectionAwareInterface
{
    /**
     * Sets the dependency injector
     *
     * @param Pdm\Di\ContainerInterface di
     */
    public function setDi(<\Pdm\Di\ContainerInterface> di);

    /**
     * Returns the internal dependency injector
     *
     * @return Pdm\Di\ContainerInterface
     */
    public function getDi() -> <\Pdm\Di\ContainerInterface>;
}
