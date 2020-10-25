#pragma once
#include <vector>

struct couple
{
	int firstInt;
	int secoundInt;
};

using vectorCoupleT = std::vector<couple>;

//Class
class diffOfTwo {
public:
	//Constructor
	diffOfTwo(const std::vector<int> &);

private:
	vectorCoupleT initCoupleVec(const std::vector<int>&);
	void printRes(const vectorCoupleT&);
};










//Steplist:
//step1: create a new type for couples called "couple"
//step2: create a vec for that type
//step3: 
//step4: print