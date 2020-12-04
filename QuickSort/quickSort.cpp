#include "quickSort.hpp"
#include <algorithm>
#include <cassert>

quickSort::quickSort(TIntVec a, int n){
   if(n>=2)
   {
      mainSort(a, 0, n);
      std::cout << "VVVV" << std::endl;
      auto b=std::is_sorted(a.begin(),a.end());
      assert(b);
   }
   quickSort::printResVec(a, n);
}


//++++++VERY IMPORTANT:The interval is [s,e)++++++++++++++

//EXEMPLE: [0,4)  0,1,2,3        Close Open interwall



void quickSort::mainSort(TIntVec &a, int s, int e){

   //This "if" is useless , just two make it clearly
   //the shortcuts are below , when calling mainSort
   if(e==s+1) //subarray contains just one element , nothing to do
   {
      std::cout <<"Fertig: s= "  << s<<std::endl;
      return;
   }
   std::cout <<"s: " <<s << ",e:  " << e << std::endl;

   int pIndex = partitioning2(a, s, e);
   std::cout << "pindex: " << pIndex << std::endl;

   if(s + 1  < pIndex) //call mainSort just if there are at least 2 elements
      mainSort(a, s, pIndex );//pIndex-s >=2

   if(pIndex + 2 <  e) //call mainSort just if there are at least 2 elements
      mainSort(a, pIndex + 1, e); //e-pIndex-1 >=2
}



int quickSort::partitioning2(TIntVec &a, int s, int e){
   int pIndex = s+ (e-s)/2; //index ALWAYS in the middle


   if(e-s==2) //just two elements
   { if(a[s]>a[e-1]) //swap if necessary
         std::swap(a[s],a[e-1]);
      return pIndex;
   }



   for(;;)
   {
      bool bDone=true;

      //left side of array , at the end of loop all elements from the range [s,pIndex) are less than a[pIndex]
      for(auto i = s; i < pIndex; i++)
         if(a[i]> a[pIndex])
         {
            std::swap(a[i],a[pIndex]);
         }
      //right side of array , at the end of loop all elements from the range [pIndex+1,e) are greather than a[pIndex]
      for(auto i = pIndex+1; i < e; i++)
         if(a[i] < a[pIndex])
         {
            //a smaller element was found , put it in the middle
            std::swap(a[i],a[pIndex]);
            //the loop is not finished
            bDone=false;
         }
      if(bDone)
         break;
      std::cout << "swap detected"<< std::endl;
      //if you arrive here , loop again. now in a[pIndex] is an element that does not satisfy the property for the first half of array
      //loop again
   }


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
