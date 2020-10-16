//TRIBONACCI
/*Well met with Fibonacci bigger brother, AKA Tribonacci.

As the name may already reveal, it works basically like a Fibonacci, but summing the last 3 (instead of 2) numbers of the sequence to 

generate the next. And, worse part of it, regrettably I won't get to hear non-native Italian speakers trying to pronounce it :(

So, if we are to start our Tribonacci sequence with [1, 1, 1] as a starting input (AKA signature), we have this sequence:

[1, 1 ,1, 3, 5, 9, 17, 31, ...]
But what if we started with [0, 0, 1] as a signature? As starting with [0, 1] instead of [1, 1] basically shifts the common

Fibonacci sequence by once place, you may be tempted to think that we would get the same sequence shifted by 2 places, but that is not the case and we would get:

[0, 0, 1, 1, 2, 4, 7, 13, 24, ...]
Well, you may have guessed it by now, but to be clear: you need to create a fibonacci function that given a signature array/list,

returns the first n elements - signature included of the so seeded sequence.

Signature will always contain 3 numbers; n will always be a non-negative number; if n == 0, then return an empty array (except

in C return NULL) and be ready for anything else which is not clearly specified*/


#include <iostream>
#include <vector>

int returnTribonacciVal(const std::vector<int> &mainVec){

    return mainVec[mainVec.size() - 1] + mainVec[mainVec.size() - 2] + mainVec[mainVec.size() - 3];
}

int main()
{
    std::vector<int> mainVec;

    auto num1 = 0;
    auto num2 = 0;
    auto num3 = 0;

    std::cout << "What 3 numbers do you want to start with?" << std::endl;
    std::cin >> num1;
    system("CLS");
    std::cin >> num2;
    system("CLS");
    std::cin >> num3;
    system("CLS");

    mainVec.push_back(num1);
    mainVec.push_back(num2);
    mainVec.push_back(num3);

    std::cout << "How far do you want to go?" << std::endl;
    auto range = 3;
    std::cin >> range;
    system("CLS");

    for (auto i = 0; i < range; i++) {
        mainVec.push_back(returnTribonacciVal(mainVec));
    }

    for (auto i : mainVec) {
        std::cout << i << std::endl;
    }
}
