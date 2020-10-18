#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include "remove_motives/remove_motives.h"
//utility-Methods
void clearCons() {
    system("CLS");
}






int main()
{
   //Vars
   auto allowedAmount = 1;
   std::vector<int> mainVec = { 20, 21, 32, 47, 20, 32, 32 };
   auto good1=std::vector<int>{20,21,32,47};


   auto obj1=remove_motives(mainVec, 1);
   auto myres1=obj1.result();
   assert(good1.size()==myres1.size());


   auto good2=std::vector<int>{20,21,32,47,20,32};
   auto obj2=remove_motives(mainVec, 2);
   auto myres2=obj2.result();
   assert(good1.size()==myres1.size());

   auto it1=find_nth(begin(mainVec),end(mainVec),20,1);
   assert(0==std::distance(begin(mainVec),it1));

   auto it2=find_nth(begin(mainVec),end(mainVec),32,3);
   assert(6==std::distance(begin(mainVec),it2));

}

