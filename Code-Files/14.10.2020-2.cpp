/*Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is 

produced. The input will be a non-negative integer.

Examples:
16      -->  1 + 6 = 7
942     -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2*/

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>

//git add start.h

int retResult(std::string &inputNumString) {

    
    int Result = 10;

    while (std::to_string(Result).size() != 1)
    {
        std::vector<int> seppedInts;
        for (int i = 0; i < inputNumString.size(); i++) {
            char k = inputNumString[i];
            int j = k - 48;                                                                  //-48 Ascci tabelle -> 0
            seppedInts.push_back(j);
        }

        Result = std::accumulate(seppedInts.begin(), seppedInts.end(), 0);
        inputNumString = std::to_string(Result);
    }

    return Result;
}

std::string convIntToString(const int &inputNum) {
    return std::to_string(inputNum);
}

int getInput() {
    int i;
    std::cin >> i;

    return i;
}

int main()
{
    int inputNum = getInput();
    std::string inputNumString = convIntToString(inputNum);
    std::cout << retResult(inputNumString) << std::endl;


    int eND;
    std::cin >> eND;
    return 0;
}
