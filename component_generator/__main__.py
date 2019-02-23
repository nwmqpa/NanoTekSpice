"""Main file for the looping application."""
import sys
import os
import re


def capitalize(value: str):
    """Capitalize vaues."""
    return "".join(list(map(lambda x: x.capitalize(), value.split("_"))))


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

    def check_lines(self, lines):
        """Check the different lines."""
        state = 0
        chipsets = []
        links = []
        for i in lines:
            if i == ".chipsets:":
                state = 1
            elif i == ".links:":
                state = 2
            elif state == 1:
                c = re.search(
                    "^([a-zA-Z0-9_]+)[ \t]+([a-zA-Z0-9_]+)\(?([\w.]*)\)?$",
                    i
                )
                chipsets.append({
                    'type': c.group(1),
                    'name': c.group(2),
                    'value': c.group(3)
                })
            elif state == 2:
                c = re.search(
                    "^([a-zA-Z0-9_]+):([0-9]+)[ \t]+([a-zA-Z0-9_]+):([0-9]+)$",
                    i
                )
                links.append({
                    "c1": c.group(1),
                    "p1": int(c.group(2)),
                    "c2": c.group(3),
                    "p2": int(c.group(4))
                })
        return chipsets, links

    def generate_makefile(self, folder, component):
        """Generate makefile."""
        with open(sys.argv[0] + "/Makefile", 'r') as mR:
            makefile = mR.read()
        makefile = makefile.format(
            component,
            "$(SRC_DIR)/Component" + capitalize(component) + ".cpp"
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

    def compute_gates(self, lines):
        """Compute the gates used."""
        max_pin = 0
        gates = []
        updates = []
        for gate in lines:
            if gate['type'] not in ["input", "output"]:
                gates.append(
                    "    auto {} = factory->createComponent(\"{}\", \"{}\");".format(
                        gate['name'],
                        gate['type'],
                        gate['value']
                    )
                )
                updates.append(
                    "    component.get()->gatesToUpdate.push_back(std::move({}));".format(gate['name'])
                )
            else:
                if max_pin < int(gate['name']):
                    max_pin = int(gate['name'])
        gates.insert(0, "    component.get()->pins.resize({});".format(max_pin + 1))
        return gates, updates

    def compute_linking(self, lines):
        """Compute the linking of any component."""
        links = []
        for line in lines:
            links.append(
                "    (*{}).setLink({}, *{}, {});".format(
                    "component" if line["c1"].isdigit() and line["p1"] == 1 else line["c1"],
                    line["c1"] if line["c1"].isdigit() and line["p1"] == 1 else line["p1"],
                    "component" if line["c2"].isdigit() and line["p2"] == 1 else line["c2"],
                    line["c2"] if line["c2"].isdigit() and line["p2"] == 1 else line["p2"]
                )
            )
        return links
    
    def generate_files(self, folder, component, linking):
        """Generate files."""
        with open(sys.argv[0] + "/entrypoint.cpp", 'r') as mR:
            entrypoint = mR.read()
        entrypoint = entrypoint.format(
            capitalize(component),
            component.lower()
        )
        with open(folder + "/sources/entrypoint.cpp", "w") as mW:
            mW.write(entrypoint)

        with open(sys.argv[0] + "/Component.cpp", 'r') as mR:
            component_cpp = mR.read()
        component_cpp = component_cpp.format(
            capitalize(component),
            "\n".join(linking),
            component.lower()
        )
        with open(folder + "/sources/Component" + capitalize(component) + ".cpp", "w") as mW:
            mW.write(component_cpp)

        with open(sys.argv[0] + "/Component.hpp", 'r') as mR:
            component_hpp = mR.read()
        component_hpp = component_hpp.format(
            capitalize(component),
            component.upper()
        )
        with open(folder + "/includes/Component" + capitalize(component) + ".hpp", "w") as mW:
            mW.write(component_hpp)

    def process_file(self, file_to_process):
        """File to process."""
        folder = ".".join(file_to_process.split(".")[:-1])
        component = file_to_process.split("/")[-1].split(".")[0]
        lines = self.parse_file(file_to_process)
        self.check_file(lines)
        try:
            chipsets, links = self.check_lines(lines)
        except:
            self.exit_on_error("Error on parsing\n")
        self.generate_folders(folder)
        self.generate_makefile(folder, component)
        gates, updates = self.compute_gates(chipsets)
        gates += self.compute_linking(links)
        gates += updates
        self.generate_files(folder, component, gates)

    def run(self):
        """Run the application."""
        files = os.listdir("components")
        try:
            if sys.argv[1] == "fclean":
                for file in files:
                    if file.find(".nts") != -1 and os.path.exists("components/" + file.split(".")[0]):
                        os.system("rm -rf components/" + file.split(".")[0])
        except:
            for file in files:
                if file.find(".nts") != -1 and not os.path.exists("components/" + file.split(".")[0]):
                    self.process_file("components/" + file)


if __name__ == "__main__":
    app = Application("looping")
    app.run()
