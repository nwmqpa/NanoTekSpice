"""Main file for the looping application."""
import sys
import os


class Application(object):
    """Class defining the looping application."""

    def __init__(self, title):
        """Initialize the application."""
        self.title = title

    def exit_on_error(self, error):
        """Exit the application on error."""
        sys.stderr.write("{0}: {1}".format(self.title, str(error)))
        sys.exit(84)

    def parse_file(self, filename):
        """Parse the nts file."""
        with open(filename, "r") as fR:
            file = fR.read()
        lines = [line.strip() for line in file.split("\n")]
        lines = list(filter(lambda x: len(x) and x[0] != '#', lines))
        return lines

    def check_file(self, lines):
        """Check lines."""
        if ".chipsets:" not in lines:
            self.exit_on_error("No chipsets in file\n")
        if ".links:" not in lines:
            self.exit_on_error("No links in file\n")

    def generate_makefile(self, folder, component):
        """Generate makefile."""
        with open(sys.argv[0] + "/Makefile", 'r') as mR:
            makefile = mR.read()
        makefile = makefile.format(
            component,
            "$(SRC_DIR)/Component" + component.capitalize() + ".cpp"
        )
        with open(folder + "/Makefile", "w") as mW:
            mW.write(makefile)

    def generate_folders(self, folder):
        """Generate folders."""
        try:
            os.makedirs(folder + "/includes")
        except:
            pass
        try:
            os.makedirs(folder + "/sources")
        except:
            pass

    def compute_linking(self, lines):
        """Compute the linking of any component."""
        pass
    
    def generate_files(self, folder, component, linking):
        """Generate files."""
        with open(sys.argv[0] + "/entrypoint.cpp", 'r') as mR:
            entrypoint = mR.read()
        entrypoint = entrypoint.format(
            component.capitalize(),
            component
        )
        with open(folder + "/sources/entrypoint.cpp", "w") as mW:
            mW.write(entrypoint)

        with open(sys.argv[0] + "/Component.cpp", 'r') as mR:
            component_cpp = mR.read()
        component_cpp = component_cpp.format(
            component.capitalize(),
            linking
        )
        with open(folder + "/sources/Component" + component.capitalize() + ".cpp", "w") as mW:
            mW.write(component_cpp)

        with open(sys.argv[0] + "/Component.hpp", 'r') as mR:
            component_hpp = mR.read()
        component_hpp = component_hpp.format(
            component.capitalize(),
            component.upper()
        )
        with open(folder + "/includes/Component" + component.capitalize() + ".hpp", "w") as mW:
            mW.write(component_hpp)

    def run(self):
        """Run the application."""
        folder = '/'.join(sys.argv[1].split("/")[:-1])
        component = sys.argv[1].split("/")[-1].split(".")[0]
        lines = self.parse_file(sys.argv[1])
        self.check_file(lines)
        self.generate_makefile(folder, component)
        self.generate_folders(folder)
        linking = self.compute_linking(lines)
        self.generate_files(folder, component, linking)


if __name__ == "__main__":
    app = Application("looping")
    app.run()
