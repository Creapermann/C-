/*In DNA strings, symbols "A" and "T" are complements of each other, as "C" and "G". You have function with one side of the DNA
(string, except for Haskell); you need to get the other complementary side. DNA strand is never empty or there is no DNA at all (again, except for Haskell).*/


#include <string>
#include <vector>
#include <iostream>
#include <set>


template <typename T>  void uniqueInOrder(const std::vector<T>& iterable) {

	std::vector<T> endVec;

	for (auto i = 0; i < iterable.size(); i++) {
		if (i == 0) {
			endVec.push_back(iterable[i]);
		}
		else if (iterable[i] != iterable[i - 1]) {
			endVec.push_back(iterable[i]);
		}
	}

	for (auto c : endVec) {
		std::cout << c;
	}


}
std::vector<char> uniqueInOrder(const std::string& iterable) {
	std::vector<char> splitInCharsVec(iterable.begin(), iterable.end());

	return splitInCharsVec;
}

int main() {
	std::string input;
	std::cin >> input;

	uniqueInOrder(uniqueInOrder(input));

	int eND;
	std::cin >> eND;
	return 0;
}