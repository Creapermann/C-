//TRIBONACCI
#include <iostream>
#include <vector>

int returnTribonacciVal(std::vector<int> mainVec){

    return mainVec[mainVec.size() - 1] + mainVec[mainVec.size() - 2] + mainVec[mainVec.size() - 3];
}

int main()
{
    std::vector<int> mainVec;

    int num1;
    int num2;
    int num3;

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
    int range;
    std::cin >> range;
    system("CLS");

    for (int i = 0; i < range; i++) {
        mainVec.push_back(returnTribonacciVal(mainVec));
    }

    for (int i : mainVec) {
        std::cout << i << std::endl;
    }
}
