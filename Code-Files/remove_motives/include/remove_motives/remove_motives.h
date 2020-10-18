#pragma once
//find the nth ocurrence in one vector
template<class InputIterator, class T >
InputIterator find_nth(InputIterator first, InputIterator last,  const T &value,int Nth)
{

//"value" is passed by value
//Nth is passed by reference
return std::find_if(first,last,[value=value,&Nth=Nth](auto &o)->bool
{
   return o==value && //found first element , then the decrement operator is bitting
          (0==--Nth); //return true if we found the value and Nth is 0
});
}


class remove_motives{
public:
explicit remove_motives(const std::vector<int> &motives,int amount);
std::vector<int> result() const;

private:
   void printMainVec();
   std::vector<int> countMotives();


   std::vector<int> motives_;
   int amount_;
   std::vector<int> uniq_motives_;
};
