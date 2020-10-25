#include "remove_motives/diffN.h"
diffN::diffN(const TVctInt &vct, int diff):
   vct_(vct),diff_(diff)
{
   if(vct_.size() <=1 ) //maximal one element nothing to do
      return;
   //sort first the vector
   std::sort(begin(vct_),end(vct_));




   auto optVct=VctOptPair(vct_.size()-1);//I  get size-1 pairs
   //I scroll until the last but one (penultimate element)
   std::transform(begin(vct_),std::prev(end(vct_)),optVct.begin(),[this](auto &o)->OptPair
   {
      auto ret=OptPair();//initialize the optional that is NOT present
      auto it= std::find_if(begin(vct_),end(vct_),[o=o,diff=diff_](auto &e)->bool
      {
         return (e-o==diff); //the vector is sorted, looking for one element e which is bigger than o
      });
      if(it!=end(vct_)) //found one element , initialize the pair
         ret= std::pair{o,*it};
      return ret;//return ALWAYS a optional pair (the value may NOT be present)
   });

   //filter the values that ARE present
   //the validValues ending at itEndRes
   auto itEndRes=std::partition(begin(optVct),end(optVct),[](auto &o)->bool
   {
      if(o) //o is optional
         return true; //select the valid values
      else
         return false;
   });



   auto resSize=static_cast<size_t>(std::distance(begin(optVct),itEndRes));
   res_.resize(resSize); // the size of result
   //transform to the result which is as simply as dereferencig the optional value
   std::transform(begin(optVct),itEndRes,res_.begin(),[](auto &o)->std::pair<int,int>
   {
      assert(o);//here the optional value is present so I can dereference
      return *o;
   });
}

VctPair diffN::res() const
{
   return res_;
}


void diffN::printRes(const VctPair& resVec) {
    for (auto& o : resVec) {
        std::cout << o.first << " " << o.second << std::endl;
    }
}
