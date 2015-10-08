#include <iostream>

void setSort(int* arr,int n)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int a = 0 ; a < n; a++) {
        if(arr[a] == 0)
            count0++;
        else if (arr[a] == 1)
            count1++;
        else if (arr[a] == 2)
            count2++;
    }
    
    for(int i = 0;i < count0;i++)
        arr[i] = 0;
    
    for(int i = 0;i < count1;i++)
        arr[count0 + i] = 1;
    
    for(int i = 0;i < count2;i++)
        arr[count0 + count1 + i] = 2;
}

int main(void) {
    int a[12] = {0,0,1,0,1,2,2,1,0,2,1,2};

    setSort(a,12);
    return 0;
}


