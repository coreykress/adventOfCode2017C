#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main (int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "There should be one argument" << std::endl;

        return 1;
    }

    std::ifstream file(argv[1]);
    // check to see if the file opening succeeded
    if (!file.is_open()) {
        std::cout << "Ain't no file here boss" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream buffer(line);
        std::cout << &buffer << std::endl;
    }

    return 0;
}
