
/**
 * This file is part of Pdm for PHP.
 *
 * @package Pdm\Autoload
 * @license http://opensource.org/licenses/bsd-license.php BSD
 */
namespace Pdm\Autoload;

/**
 * An SPL autoloader adhering to PSR-4.
 *
 * @package Pdm\Autoload
 */
class Loader
{
    /**
     * A map of explicit class names to their file paths.
     *
     * @var array
     */
    protected classFiles = [];

    /**
     * Debug information populated by loadClass().
     *
     * @var array
     */
    protected debug = [];

    /**
     * Classes, interfaces, and traits loaded by the autoloader; the key is
     * the class name and the value is the file name.
     *
     * @var array
     */
    protected loadedClasses = [];

    /**
     * A map of namespace prefixes to base directories.
     *
     * @var array
     */
    protected prefixes = [];

    /**
     * Registers this autoloader with SPL.
     *
     * @param bool $prepend True to prepend to the autoload stack.
     * @return void
     */
    public function register(boolean prepend = false) -> <\Pdm\Autoload\Loader>
    {
        spl_autoload_register([this, "loadClass"], true, prepend);
        return this;
    }

    /**
     * Unregisters this autoloader from SPL.
     *
     * @return void
     */
    public function unregister() -> <\Pdm\Autoload\Loader>
    {
        spl_autoload_unregister([this, "loadClass"]);
        return this;
    }

    /**
     * Returns the debugging information array from the last loadClass()
     * attempt.
     *
     * @return array
     */
    public function getDebug() -> array
    {
        return this->debug;
    }

    /**
     * Adds a base directory for a namespace prefix.
     *
     * @param string prefix The namespace prefix.
     * @param string|array baseDirs One or more base directories for the
     * namespace prefix.
     * @param bool $prepend If true, prepend the base directories to the
     * prefix instead of appending them; this causes them to be searched
     * first rather than last.
     * @return Loader
     */
    public function addPrefix(string! prefix, var baseDirs, boolean prepend = false) -> <\Pdm\Autoload\Loader>
    {
        var key, baseDir;

        // normalize the namespace prefix
        let prefix = trim(prefix, "\\") . "\\";

        if typeof baseDirs != "array" {
            if unlikely typeof baseDirs != "string" {
                throw new \InvalidArgumentException("baseDirs must be string or array");
            }
            let baseDirs = [baseDirs];
        }

        // initialize the namespace prefix array if needed
        if !isset this->prefixes[prefix] {
            let this->prefixes[prefix] = [];
        }

        // normalize each base dir with a trailing separator
        for key, baseDir in baseDirs {
            let baseDirs[key] = rtrim(baseDir, DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
        }

        // prepend or append?
        if prepend {
            let this->prefixes[prefix] = array_merge(baseDirs, this->prefixes[prefix]);
        } else {
            let this->prefixes[prefix] = array_merge(this->prefixes[prefix], baseDirs);
        }

        return this;
    }

    /**
     * Sets all namespace prefixes and their base directories. This overwrites
     * the existing prefixes.
     *
     * @param array prefixes An associative array of namespace prefixes and
     * their base directories.
     * @return Loader
     */
    public function setPrefixes(array prefixes) -> <\Pdm\Autoload\Loader>
    {
        var key, val;

        let this->prefixes = [];
        for key, val in prefixes {
            this->addPrefix(key, val);
        }

        return this;
    }

    /**
     * Returns the list of all class name prefixes and their base directories.
     *
     * @return array
     */
    public function getPrefixes() -> array
    {
        return this->prefixes;
    }

    /**
     * Sets the explicit file path for an explicit class name.
     *
     * @param string className The explicit class name.
     * @param string file The file path to that class.
     * @return Loader
     */
    public function setClassFile(string! className, string! file) -> <\Pdm\Autoload\Loader>
    {
        let this->classFiles[className] = file;
        return this;
    }

    /**
     * Sets all file paths for all class names; this overwrites all previous
     * explicit mappings.
     *
     * @param array $classFiles An array of class-to-file mappings where the
     * key is the class name and the value is the file path.
     * @return Loader
     */
    public function setClassFiles(array classFiles) -> <\Pdm\Autoload\Loader>
    {
        let this->classFiles = classFiles;
        return this;
    }

    /**
     * Adds file paths for class names to the existing explicit mappings.
     *
     * @param array $classFiles An array of class-to-file mappings where the
     * key is the class name and the value is the file path.
     * @return Loader
     */
    public function addClassFiles(array classFiles) -> <\Pdm\Autoload\Loader>
    {
        let this->classFiles = array_merge(this->classFiles, classFiles);
        return this;
    }

    /**
     * Returns the list of explicit class names and their file paths.
     *
     * @return array
     */
    public function getClassFiles() -> array
    {
        return this->classFiles;
    }

    /**
     * Returns the list of classes, interfaces, and traits loaded by the
     * autoloader.
     *
     * @return array An array of key-value pairs where the key is the class
     * or interface name and the value is the file name.
     */
    public function getLoadedClasses() -> array
    {
        return this->loadedClasses;
    }

    /**
     * Loads the class file for a given class name.
     *
     * @param string $className The fully-qualified class name.
     * @return mixed The mapped file name on success, or boolean false on
     * failure.
     */
    public function loadClass(string! className)
    {
        var file, found, prefix, pos, relativeClass;

        // reset debug info
        let this->debug = ["Loading $class"];

        // is an explicit class file noted?
        if isset this->classFiles[className] {
            let file = this->classFiles[className];
            let found = this->requireFile(file);

            if found {
                let this->debug[] = "Loaded from explicit: file";
                let this->loadedClasses[className] = file;
                return file;
            }
        }

        // no explicit class file
        let this->debug[] = "No explicit class file";

        // the current namespace prefix
        let prefix = className;

        // work backwards through the namespace names of the fully-qualified
        // class name to find a mapped file name
        loop {
            let pos = strrpos(prefix, "\\");

            // Break out of loop if we never find a match (false or 0)
            if !pos {
                break;
            }

            // retain the trailing namespace separator in the prefix
            let prefix = substr(className, 0, pos + 1);

            // the rest is the relative class name
            let relativeClass = substr(className, pos + 1);

            // try to load a mapped file for the prefix and relative class
            let file = this->loadFile(prefix, relativeClass);
            if file {
                let this->debug[] = "Loaded from prefix: file";
                let this->loadedClasses[className] = file;
                return file;
            }

            // remove the trailing namespace separator for the next iteration
            // of strrpos()
            let prefix = rtrim(prefix, "\\");
        }

        // did not find a file for the class
        let this->debug[] = className . " not loaded";

        return false;
    }

    /**
     * Load the mapped file for a namespace prefix and relative class.
     *
     * @param string prefix The namespace prefix.
     * @param string relativeClass The relative class name.
     * @return mixed Boolean false if no mapped file can be loaded, or the
     * name of the mapped file that was loaded.
     */
    protected function loadFile(string! prefix, string! relativeClass)
    {
        var baseDir, file;

        // are there any base directories for this namespace prefix?
        if !isset this->prefixes[prefix] {
            let this->debug[] = "prefix: no base dirs";
            return false;
        }

        // look through base directories for this namespace prefix
        for baseDir in this->prefixes[prefix] {
            // replace the namespace prefix with the base directory,
            // replace namespace separators with directory separators
            // in the relative class name, append with .php
            let file = baseDir . str_replace("\\", DIRECTORY_SEPARATOR, relativeClass) . ".php";

            // if the mapped file exists, require it
            if this->requireFile(file) {
                // yes, we're done
                return file;
            }

            // not in the base directory
            let this->debug[] = "prefix: file not found";
        }

        // never found it
        return false;
    }

    /**
     * If a file exists, require it from the file system.
     *
     * @param string file The file to require.
     * @return bool True if the file exists, false if not.
     */
    protected function requireFile(string! file)
    {
        if file_exists(file) {
            require file;
            return true;
        }
        return false;
    }
}
