#include <iostream>

#include "quickSort.hpp"
#include <cassert>
int main(){

    std::vector<int> a = {  19,3,78,1,0,23,100,5,3,0,56,4,1};

    int n = a.size();

    quickSort qs(a, n);

    return 0;
}
