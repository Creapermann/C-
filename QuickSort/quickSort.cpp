#include "quickSort.hpp"
#include <cassert>

quickSort::quickSort(TIntVec a, int n){
    mainSort(a, 0, n);
    std::cout << "VVVV" << std::endl;
    quickSort::printResVec(a, n);
}

void quickSort::mainSort(TIntVec &a, int s, int e){

    std::cout <<"s: " <<s << ",e:  " << e << std::endl;

    int pIndex = partitioning2(a, s, e);
    std::cout << "pindex: " << pIndex << std::endl;
    if ( s == pIndex ) //check if you can  decrement pIndex
       return;
       mainSort(a, s, pIndex - 1);
    if(pIndex == e)//check if you can increment pIndex
       return;
       mainSort(a, pIndex + 1, e);
}

//[0,4)  0,1,2,3        Close Open interwall
//[0,4]  0,1,2,3,4      Close Close inverwall


int quickSort::partitioning2(TIntVec &a, int s, int e){
    int pIndex = s+ (e-s)/2; //index ALWAYS in the middle

    //left side of array , at the end of loop all elements from the range [s,pIndex) are less than a[pIndex]
    for(auto i = s; i < pIndex; i++)
       if(a[i]> a[pIndex])
          std::swap(a[i],a[pIndex]);
//right side of array , at the end of loop all elements from the range [pIndex+1,e) are greather than a[pIndex]
    for(auto i = pIndex+1; i < e; i++)
       if(a[i] < a[pIndex])
          std::swap(a[i],a[pIndex]);




    return pIndex;
}


int quickSort::partitioning(TIntVec &a, int s, int e){
    int pIndex = s;
    int pivot = a[e - 1];
    //[0,4)  0,1,2,3        Close Open interwall
    //[0,4]  0,1,2,3,4      Close Close inverwall
    for(int i = s; i < e; i++){
        if(a[i] <= pivot){
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = a[e-1];
    a[e-1] = a[pIndex];
    a[pIndex] = temp;
    
    return pIndex;
}

void quickSort::printResVec(TIntVec a, int n){
    for(int i = 0; i < n; i++){
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}
