#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include "remove_motives/remove_motives.h"





//prints out the "mainVec"
void remove_motives::printMainVec() {
   for (auto i : motives_) {
      std::cout << i << std::endl;
   }
     std::cout << "finish!" << std::endl;
}


std::vector<int> remove_motives::result() const
{
   return motives_;
}

//constructor
remove_motives::remove_motives(const std::vector<int> &motives, int amount):
   motives_(motives),amount_(amount)
{
   //find all unique motives
   auto tmp=motives;
   std::sort(begin(tmp),end(tmp));
   std::unique_copy(begin(tmp),end(tmp),std::back_inserter(uniq_motives_));


   while(1)
   {
      auto countMot=countMotives();
      //find one element that is bigger then amount
      auto it=std::find_if(begin(countMot),end(countMot),[amount=amount](auto &o)->bool
      {
         return o > amount;
      });
      if(it!=end(countMot))
      {
         auto index=std::distance(begin(countMot),it);
         auto iterNthElem=find_nth(begin(motives_),end(motives_),uniq_motives_[index],amount+1);
         assert(iterNthElem!=end(motives_));
         motives_.erase(iterNthElem);
      }
      else //nothing found , exit from loop
         break;

   }
   printMainVec();
}




std::vector <int> remove_motives::countMotives()
{
   std::vector <int> count_motives(uniq_motives_.size());
   std::transform(begin(uniq_motives_),end(uniq_motives_),count_motives.begin(),[this](auto &o)->int
   {
      return std::count(begin(motives_),end(motives_),o);//count ocurrence of o
   });
   return count_motives;
}





