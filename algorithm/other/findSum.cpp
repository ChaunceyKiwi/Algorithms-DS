#include <iostream>
#include "quickSort.h"

//Time complexity = O(n) + 2 * O(nlogn) + o(2n) = O(nlogn)
bool existSum(int* s1 ,int* s2,int n,int x)
{
    int s3[8];    //s3[i] = x - s2[i]

    for(int k = 0;k < 8;k++)   //give value to s3 ,O(n)
        s3[k] = x - s2[k];

    quickSort(s1, 0, n - 1);   //sort array s1, O(nlogn)
    quickSort(s3, 0, n - 1);   //sort array s3, O(nlogn)

    int i = 0,j = 0;

    //if s1[i] = s3[j],which means s1[i] = x - s2[j],then s1[i] +s2[j] = x
    //Operation need O(2n)
    while(i < n && j < n){
        if(s1[i] == s3[j]) return 1; //exists such a pair
        else if (s1[i] > s3[j]) j++;
        else i++;
    }
    return 0;  //do not exists such a pair
}

int main(void) {
    int s1[8] = {3,6,8,2,11,4,1,7};
    int s2[8] = {1,8,3,6,23,12,6,9};

    if(existSum(s1, s2, 8, 23) == true)
        printf("exists.\n");
    else
        printf("Do not exists.\n");
    return 0;
}
