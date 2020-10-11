/*Implement the function unique_in_order which takes as argument a sequence and returns a list of items 
without any elements with the same value next to each other and preserving the original order of elements.*/


#include <unordered_map>
#include <iostream>


void /*std::unordered_map<std::string, std::string>*/ printRightPairs(const std::string& inputString) {

	std::unordered_map<char, char> uMap;

	uMap.insert(std::pair<char, char>('A', 'T'));
	uMap.insert(std::pair<char, char>('T', 'A'));
	uMap.insert(std::pair<char, char>('G', 'C'));
	uMap.insert(std::pair<char, char>('C', 'G'));

	std::vector<char> charVec(inputString.begin(), inputString.end());

	for (int i = 0; i < charVec.size(); i++) {

		std::cout << uMap[charVec[i]];
	}

	std::cout << std::endl;
}


int main() {

	std::string userInput;
	std::cin >> userInput;

	printRightPairs(userInput);

	int eND;
	std::cin >> eND;
	return 0;
}
