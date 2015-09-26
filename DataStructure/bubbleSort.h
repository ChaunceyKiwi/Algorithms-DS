//
//  bubbleSort.h
//  ChaunceysLibrary
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//

#ifndef __ChaunceysLibrary__bubbleSort__
#define __ChaunceysLibrary__bubbleSort__

#include <stdio.h>

void bubbleSort(int* arr,int n)
{
    bool swapped = true;
    int j = 0;
    int tmp;
    while(swapped)
    {
        swapped = false;
        j++;
        for(int i = 0;i < n- j;i++)
        {
            if(arr[i] > arr[i+1])
            {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true;
            }
        }
    }
}

#endif /* defined(__ChaunceysLibrary__bubbleSort__) */
