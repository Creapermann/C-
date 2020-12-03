#include "quickSort.hpp"


quickSort::quickSort(TIntVec a, int n){
    mainSort(a, 0, n);
    std::cout << "VVVV" << std::endl;
    quickSort::printResVec(a, n);
}

void quickSort::mainSort(TIntVec &a, int s, int e){

    std::cout << s << "  " << e << std::endl;
    if(s == e){
        std::cout << "Fertig" << std::endl;
        return;
    }
    int pIndex = partitioning(a, s, e);
    std::cout << "pindex: " << pIndex << std::endl;
    mainSort(a, 0, pIndex - 1);
    mainSort(a, pIndex + 1, e);
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
