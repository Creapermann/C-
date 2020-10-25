#pragma once
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>
#include <utility>
#include <optional>
#include <iostream>

using TVctInt=std::vector<int>;
using  OptPair=std::optional<std::pair<int,int>>; //optional of std::pair<int,int>
using  VctOptPair=std::vector<OptPair>;//vector of optional
using  VctPair=std::vector<std::pair<int,int>>;//vector of pair




class diffN{
public:
   explicit diffN(const TVctInt &vct,int diff);

   VctPair res() const;

   void printRes(const VctPair &resVec);
private:
   TVctInt vct_;
   int diff_;
   VctPair res_;

};
