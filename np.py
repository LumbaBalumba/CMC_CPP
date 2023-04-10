#!/bin/python3

import sys
import os

sample_code = "#include <iostream>\n\nint main() {\n    std::cout << \"Hello world\" << std::endl;\n}"


def main():
    dir_num = int(sys.argv[1])
    tasks_num = int(sys.argv[2])
    config = open("CMakeLists.txt", "at")
    print("\n", file=config)
    for i in range(tasks_num):
        print(f"add_executable({dir_num}-{i + 1} {dir_num}/{i + 1}.cpp)", file=config)
    config.close()
    os.mkdir(str(dir_num))
    for i in range(tasks_num):
        f = open(f"{dir_num}/{i + 1}.cpp", "wt")
        print(sample_code, file=f)
        f.close()


if __name__ == "__main__":
    main()
