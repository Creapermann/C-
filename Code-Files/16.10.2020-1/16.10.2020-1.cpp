#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>

//utility-Methods
void clearCons() {
    system("CLS");
}




//prints out the "mainVec"
void printMainVec(std::vector<int> mainVec) {
    for (auto i : mainVec) {
        std::cout << i << std::endl;
    }
}

//checks if every value in the "amountVec" (which includes the amount of the multiple exictenze of the data out of the "mainVec") and ends the while loop
bool checkIfEverythingBelowAllowedAmount(const std::vector<int> &amountVec, const int &allowedAmount, bool &everythingIsBelowAllowedAmount) {

    for (auto i = 0; i < amountVec.size(); i++) {
        if (amountVec[i] <= allowedAmount) {               //turns the bool "everythingIsBelowAllowedAmount" -> true if every element in the "amountVec" is below                                                 */
            everythingIsBelowAllowedAmount = true;         //the int "allowedAmount" which announces how often a duplicate of an element is allowed to exist
        }
    }

    return everythingIsBelowAllowedAmount;
}

//finds and erases the duplicates which are not allowed to exist 
void eraseAndFindElements(const std::vector<int> &noDoubleValuesVec, std::vector<int> &mainVec, const std::vector<int> &amountVec, const int &allowedAmount) {

    for (auto i = 0; i < amountVec.size(); i++) {
        if (amountVec[i] > allowedAmount) {                                             //checks if the amount of the element is allowed
            auto it = std::find(mainVec.begin(), mainVec.end(), noDoubleValuesVec[i]);  //if the amount of the element is not allowed, the type of the element is getting found
            mainVec.erase(it);                                                          //if the amount of the element is not allowed, the previous location is erased (marked by an iterator)
        }
    }
}

//refreshes the "amountVec" to hold the amount of duplicates of the mainVec up to date after getting deleted
void refreshNoDoubleValuesVec(std::vector<int> &noDoubleValuesVec, const std::vector<int> &mainVec, std::vector<int> &amountVec) {

    auto t = 0;
    for (auto i = 0; i < noDoubleValuesVec.size(); i++) {
        for (auto k = 0; k < mainVec.size(); k++) {
            if (noDoubleValuesVec[i] == mainVec[k]) {       //gets how many duplicates of the element exists
                t++;                                        //adds up a variable for 1 everytime a duplicate of that element was found
            }
        }
        amountVec.push_back(t);                             //ads this variable which was added up a certain time before to the "amountVec"
        t = 0;                                              //resets this varibable
    }
}

//is looping through all methods
void loopThroughMethods(std::vector<int> &mainVec, const int &allowedAmount) {
    
    std::unordered_set<int> noDoubleValuesUSet(mainVec.begin(), mainVec.end());
    std::vector<int> noDoubleValuesVec(noDoubleValuesUSet.begin(), noDoubleValuesUSet.end());        //creates a vector with every value just once

    std::vector<int> amountVec;

    
    auto everythingIsBelowAllowedAmount = false;
    while (everythingIsBelowAllowedAmount != true) {

        refreshNoDoubleValuesVec(noDoubleValuesVec, mainVec, amountVec);
        eraseAndFindElements(noDoubleValuesVec, mainVec, amountVec, allowedAmount);
        checkIfEverythingBelowAllowedAmount(amountVec, allowedAmount, everythingIsBelowAllowedAmount);

        amountVec.clear();
    }

    printMainVec(mainVec);
    
}



int main()
{
    //Vars
    auto allowedAmount = 1;
    std::vector<int> mainVec = { 20, 21, 32, 47, 20, 32, 32 };
    auto res=std::vector<int>{20,21,32,47};
    
    loopThroughMethods(mainVec, allowedAmount);
    assert(res.size()==mainVec.size());
}

