#include <iostream>
using namespace std;
#include "list.h"
void bucketSort(int* arr,int n);


int main(void)
{
    int a[8] = {4,7,1,11,3,8,2,6};
    int i;
    
    for(i = 0;i < 8;i++)
        cout<<a[i]<<" ";
    
    cout<<endl;
    
    bucketSort(a, 8);
    
    for(i = 0;i < 8;i++)
        cout<<a[i]<<" ";
}

void changeValue(list mylist,int index,int x)
{
    int i;
    list::Node *mynode = mylist.head;
    
    for(i = 0;i < index;i++)
    {
        mynode = mynode->next;
    }
    
    mynode->data = x;
}

int getElement(list mylist,int index)
{
    int i;
    list::Node *mynode = mylist.head;
    
    for(i = 0;i < index;i++)
    {
        mynode = mynode->next;
    }
    
    return mynode->data;
    
}

void sortNode(list mylist)
{
    int i,j,x;
    int n = mylist.length;
    for(i = 1;i < n;i++)
    {
        x = getElement(mylist,i);
        j = i;
        while(j > 0 && getElement(mylist,i - 1) > x)
        {
            changeValue(mylist,j,getElement(mylist,j - 1));
            j = j - 1;
        }
        changeValue(mylist,j,x);
    }
}


void bucketSort(int* arr,int n)
{
    
    list* mylist = (list*)malloc(sizeof(list::Node) * n);
    for(int i = 0;i < n;i++)
        mylist[arr[i] % n].insertionAtHead(arr[i]);
    for(int i = 0;i < n;i++)
        sortNode(mylist[i]);
    
}


