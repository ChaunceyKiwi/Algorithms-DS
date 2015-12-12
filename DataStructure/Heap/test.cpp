#include "heap.hpp"

int main(void)
{
    Heap h1;
    int i;
    vector<int> sortedItems;
    h1.insert(10);
    h1.insert(9);
    h1.insert(33);
    h1.insert(7);
    h1.insert(6);
    h1.insert(5);
    h1.insert(4);
    h1.insert(3);
    h1.insert(2);
    h1.insert(1);
    sortedItems = h1.heapSort();

    for(i = 0;i < 10;i++)
      cout<<sortedItems[i]<<" ";
    cout<<endl;

    return 0;
}
