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

    auto set=std::unordered_set<int>(begin(motives),end(motives));
    uniq_motives_=std::vector<int>(begin(set),end(set));

    auto toremove_motives=findBoringMotives();
    for (auto &o:toremove_motives)
    {
        auto it=remove_from_nth(begin(motives_),end(motives_),o,amount+1);
        motives_.erase(it,end(motives_));
    }

    printMainVec();
}





std::vector<int> remove_motives::findBoringMotives()
{

    Vcthistogram histograms(uniq_motives_.size());
    //build histogram
    std::transform(begin(uniq_motives_),end(uniq_motives_),histograms.begin(),
            [this](auto &o)->histogram
    {
        int cnt=std::count(begin(motives_),end(motives_),o); //count ocurrence of o
        return histogram {o,
                    cnt};
    });
    //find boring motives
    auto itPart=std::partition(begin(histograms),end(histograms),
                               [amount=amount_](auto &o)-> bool
    {
        return o.cnt > amount;
    });

    auto dist=static_cast<size_t>(std::distance(begin(histograms),itPart));
    //return boring motives as vector of ints
    std::vector <int> res(dist);

    std::transform(begin(histograms),itPart,res.begin(),[](auto &o)->int
    {
        return o.motiv;
    });
    assert(res.size()==histograms.size());
    return res;
}





