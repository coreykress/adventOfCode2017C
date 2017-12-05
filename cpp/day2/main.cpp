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
    int part2Sum = 0;

    // check to see if the file opening succeeded
    if (!file.is_open()) {
        std::cout << "Ain't no file here boss" << std::endl;
        return 1;
    }

    while (std::getline(file, line)) {
        std::vector<int> currentRowValues = splitLine(line, '\t');
        //part 1
        auto max = *std::max_element(currentRowValues.begin(), currentRowValues.end());
        auto min = *std::min_element(currentRowValues.begin(), currentRowValues.end());

        sum += (max - min);

        //part 2
        while (currentRowValues.size()) {
            bool done = false;
            int rowValue = currentRowValues.at(0);
            currentRowValues.erase(currentRowValues.begin() + 0);
            for (int n: currentRowValues) {
                if (rowValue % n == 0) {
                    part2Sum += (rowValue / n);
                    done = true;
                    break;
                } else if (n % rowValue == 0) {
                    part2Sum += (n / rowValue);
                    done = true;
                    break;
                }
            }
            if (done) {
                break;
            }
        }
    }

    std::cout << sum << std::endl;
    std::cout << part2Sum << std::endl;

    return 0;
}
