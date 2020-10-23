#include "filterMotives.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>


//Default-Constructor
filterMotives::filterMotives(std::vector<int> mainVec, int allowedAmount) {

    std::unordered_set<int> noDoubleValuesUSet(mainVec.begin(), mainVec.end());
    std::vector<int> noDoubleValuesVec(noDoubleValuesUSet.begin(), noDoubleValuesUSet.end());

    auto HistogramVc = initHistogramVector(mainVec, noDoubleValuesVec);
    auto resVec = sortUnAllowedElements(mainVec, HistogramVc, allowedAmount);
    printOutputVec(resVec);
}



void filterMotives::printOutputVec(std::vector<int> mainVec) {
    for (auto i : mainVec) {
        std::cout << i << std::endl;
    }
}



std::vector<int> filterMotives::removeElements(int howManyTooMuch, const std::vector<int>& mainVec, int motive) {
    auto res = mainVec;
    for (auto i = 0; i < howManyTooMuch; i++) {
        auto it = std::find(res.rbegin(), res.rend(), motive);
        res.erase(std::next(it).base());               //convertierung von reverse Iterator zu normal Iterator
    }

    return  res;
}


std::vector<int> filterMotives::sortUnAllowedElements(const std::vector<int>& mainVec, vectorHistogram& HistogramVc, const int& allowedAmount) {

    auto res = mainVec;

    auto it = std::partition(HistogramVc.begin(), HistogramVc.end(), [allowedAmount = allowedAmount](auto& o) -> bool {
        return o.cnt > allowedAmount;
        });

    auto dist = static_cast<size_t>(std::distance(HistogramVc.begin(), it));
    for (auto i = 0u; i < dist; i++) {
        int howManyTooMuch = HistogramVc[i].cnt - allowedAmount;
        res = removeElements(howManyTooMuch, res, HistogramVc[i].elem);
    }
    return res;
}



vectorHistogram filterMotives::initHistogramVector(std::vector<int>& mainVec, std::vector<int>& noDoubleValuesVec) {    //inits the Histogram

    auto HistogramVc = vectorHistogram(noDoubleValuesVec.size());

    std::transform(noDoubleValuesVec.begin(), noDoubleValuesVec.end(), HistogramVc.begin(), [mainVec = mainVec](auto& element) -> histogram {
        auto temp = histogram();
        temp.elem = element;
        temp.cnt = std::count(mainVec.begin(), mainVec.end(), element);

        return temp;
        });

    return HistogramVc;
}