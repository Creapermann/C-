#pragma once
//find the nth ocurrence in one vector
template<typename InputIterator, typename T >
InputIterator find_nth(InputIterator first, InputIterator last,  const T &value,int Nth)
{

//"value" is passed by value
//Nth is passed by reference
return std::find_if(first,last,[value=value,&NthCapt=Nth](auto &o)->bool
{
   return o==value && //found first element , then the decrement operator is bitting
          (--NthCapt==0); //return true if we found the value and Nth is 0
});
}

//remove value from the nth ocurrence in one vector
template<typename InputIterator, typename T >
InputIterator remove_from_nth(InputIterator first, InputIterator last,  const T &value,int Nth)
{

auto it=find_nth(first,last,value, Nth);
if (last==it)
    return last;
return remove(it,last,value);
}


struct histogram{
    int motiv;
    int cnt;
};
//typedef std::vector<histogram> Vcthistogram;
using Vcthistogram=std::vector<histogram>;

class remove_motives{
public:
explicit remove_motives(const std::vector<int> &motives,int amount);
std::vector<int> result() const;

private:
   void printMainVec();
   std::vector<int> findBoringMotives();


   std::vector<int> motives_;
   int amount_;
   std::vector<int> uniq_motives_;
};
