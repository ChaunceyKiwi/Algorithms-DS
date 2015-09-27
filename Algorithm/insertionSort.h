//
//  insertionSort.h
//  ChaunceysLibrary
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//

#ifndef ChaunceysLibrary_insertionSort_h
#define ChaunceysLibrary_insertionSort_h

void insertionSort(int* arr,int n)
{
    int i,j,x;
    for(i = 1;i < n ;i++)
    {
        x = arr[i];
        j = i;
        while(j > 0 && arr[j-1] > x)
        {
            arr[j] = arr[j-1];
            j = j-1;
        }
        arr[j] = x;
    }
}

#endif
