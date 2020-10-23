#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>

struct histogram{

   int cnt;
   int elem;
};
using vectorHistogram = std::vector<histogram>;

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



std::vector<int> removeElements(int howManyTooMuch, const std::vector<int> &mainVec, int motive){
   auto res = mainVec;
   for(auto i = 0; i < howManyTooMuch; i++){
      auto it = std::find(res.rbegin(), res.rend(), motive);
      res.erase( std::next(it).base() );               //convertierung von reverse Iterator zu normal Iterator
   }

   return  res;
}


//finds and erases the duplicates which are not allowed to exist 
std::vector<int> sortUnAllowedElements( const std::vector<int> &mainVec, vectorHistogram &HistogramVc, const int &allowedAmount) {

   //setp 1 -> partition to find which objects out of "HistogramVc" have a higher cnt than "allowedAmount"
   //step 2 -> for-loop for everything in "HistogramVc" to it, get out how many elems too much and call removeFromNthElement
   //step 3 -> print
   auto res = mainVec;

   auto it = std::partition(HistogramVc.begin(), HistogramVc.end(), [allowedAmount = allowedAmount](auto &o) -> bool {
      return o.cnt > allowedAmount;
   });

   auto dist = static_cast<size_t>(std::distance(HistogramVc.begin(), it));
   for(auto i = 0u; i < dist; i++){
      int howManyTooMuch = HistogramVc[i].cnt - allowedAmount;
      res = removeElements(howManyTooMuch, res, HistogramVc[i].elem);
   }
   return res;
}

vectorHistogram initHistogram(std::vector<int> &mainVec, std::vector<int> &noDoubleValuesVec){
   auto res = vectorHistogram(noDoubleValuesVec.size());

   std::transform(noDoubleValuesVec.begin(), noDoubleValuesVec.end(), res.begin(), [mainVec = mainVec](auto &o) -> histogram {
      auto temp = histogram();
      temp.elem = o;
      temp.cnt = std::count(mainVec.begin(), mainVec.end(), o);

      return temp;
   });

   return res;
}

int main()
{
   //Vars
   auto allowedAmount = 2;
   std::vector<int> mainVec = { 20, 21,20,21, 32, 47, 20, 32, 20, 21, 32 };

   std::unordered_set<int> noDoubleValuesUSet(mainVec.begin(), mainVec.end());
   std::vector<int> noDoubleValuesVec(noDoubleValuesUSet.begin(), noDoubleValuesUSet.end());        //creates a vector with every value just once

   auto vctHist = initHistogram(mainVec, noDoubleValuesVec);


   auto res = sortUnAllowedElements(mainVec, vctHist, allowedAmount);

   printMainVec(res);
}

