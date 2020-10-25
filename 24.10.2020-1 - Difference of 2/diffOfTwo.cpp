#include "diffOfTwo.hpp"
#include <algorithm>
#include <iostream>
#include <vector>


//Constructor
diffOfTwo::diffOfTwo(const std::vector<int>& mainVec) {
	auto coupleVec = initCoupleVec(mainVec);
	printRes(coupleVec);
}

//std::optional


//Methods
vectorCoupleT diffOfTwo::initCoupleVec(const std::vector<int>& mainVec) {

	auto mainVecCopy = mainVec;
	vectorCoupleT coupleVec;

	std::sort(mainVecCopy.begin(), mainVecCopy.end());

	for (auto i = 0; i < mainVecCopy.size(); i++) {
		for (auto k = 0; k < mainVecCopy.size(); k++) {
			if (mainVecCopy[k] + 2 == mainVecCopy[i] || mainVecCopy[k] - 2 == mainVecCopy[i]) {
				auto cpl = couple();

				cpl.firstInt = mainVecCopy[i];
				cpl.secoundInt = mainVecCopy[k];

				if (std::none_of(coupleVec.begin(), coupleVec.end(), [i = i, k = k, mainVecCopy = mainVecCopy](auto o) {     //Checks if couple doesnt already exists in swaped way
					if (o.firstInt == mainVecCopy[k] && o.secoundInt == mainVecCopy[i]) {
						return true;
					}
					else {
						return false;
					}
				})) {
					coupleVec.emplace_back(cpl);
				}
			}
		}
	}
	

	return coupleVec;
}


void diffOfTwo::printRes(const vectorCoupleT& resVec) {
	for (auto& o : resVec) {
		std::cout << o.firstInt << " " << o.secoundInt << std::endl;
	}
}