#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>


struct histogram {

    int cnt;
    int elem;
};

using vectorHistogram = std::vector<histogram>;



class filterMotives {
public:
    filterMotives(std::vector<int> mainVec, int allowedAmount);

private:
    //Methods
    void printOutputVec(std::vector<int> mainVec);
    std::vector<int> removeElements(int howManyTooMuch, const std::vector<int>& mainVec, int motive);
    std::vector<int> sortUnAllowedElements(const std::vector<int>& mainVec, vectorHistogram& HistogramVc, const int& allowedAmount);
    vectorHistogram initHistogramVector(std::vector<int>& mainVec, std::vector<int>& noDoubleValuesVec);
};