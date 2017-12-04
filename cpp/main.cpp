#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int calcValue (std::string str, int step) {
    int sum = 0;
    std::vector<int> summable;

    for (int i = 0; i <= str.size(); i++) {
        int currentValue = str[i] - '0';
        int nextIndex = i + step;
        if (nextIndex >= str.size()) {
            nextIndex -= str.size();
        }

        int nextValue = str[nextIndex];

        std::cout << str[i];
//        std::cout << nextValue << std::endl;

        if (currentValue != nextValue) {
            //add the sum of summable to the total sum
            int vecSum = 0;
            for (int& n : summable) {
                vecSum += n;
            }
            sum += vecSum;

            // clear out summable
            summable.clear();
            continue;
        }
        // add next value to summable
        summable.push_back(nextValue);
    }

    //add the sum of summable to the total sum
    int vecSum = 0;
    for (int& n : summable) {
        vecSum += n;
    }
    sum += vecSum;

    return sum;
}

int main( int argc, char *argv[] ) {
    if (argc != 2) {
        std::cout << "There should be only one argument" << std::endl;
        return 1;
    }

    // argv[1] should be the file
    std::ifstream file(argv[1]);
    // check to see if the file opening succeeded
    if (!file.is_open()) {
        std::cout << "Ain't no file here boss" << std::endl;
        return 1;
    }

    std::stringstream buffer;

    buffer << file.rdbuf();
    std::string str = buffer.str();

    std::cout<< str.size() <<std::endl;

    int first = calcValue(str, 1);

    std::cout << first << std::endl;

    return 0;
}