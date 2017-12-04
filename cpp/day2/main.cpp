#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> splitLine(std::string line, char delimiter) {
    std::vector<int> results;
    size_t pos = 0;
    std::string value;

    while ((pos = line.find(delimiter)) != std::string::npos) {
        value = line.substr(0, pos);
        results.push_back(std::stoi(value));
        line.erase(0, pos + 1);
    }

    //get the last of the line
    results.push_back(std::stoi(line));

    return results;
}

int main (int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "There should be one argument" << std::endl;

        return 1;
    }

    std::string line;
    std::ifstream file(argv[1]);
    int sum = 0;

    // check to see if the file opening succeeded
    if (!file.is_open()) {
        std::cout << "Ain't no file here boss" << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::vector<int> currentRowValues = splitLine(line, '\t');
        auto max = *std::max_element(currentRowValues.begin(), currentRowValues.end());
        auto min = *std::min_element(currentRowValues.begin(), currentRowValues.end());

        sum += (max - min);
    }

    std::cout << sum << std::endl;

    return 0;
}
