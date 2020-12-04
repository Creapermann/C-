#include <iostream>

#include "quickSort.hpp"

int main(){

    std::vector<int> a = { 3, 19, 32 , 7, 21, 19 ,45,0,67};

    int n = a.size();

    quickSort qs(a, n);

    return 0;
}
