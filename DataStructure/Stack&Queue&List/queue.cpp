#include "queue.h"
#include <iostream>

using namespace std;

//Default constructor
Queue::Queue()
{
    size = 0;
}

int Queue::getSize()
{
    return size;
}

void Queue::print()
{
    cout<< size <<endl;
}

void Queue::push(double data)
{
    if(getSize()>5)
    {
        cout<<"Queue is full!"<<endl;
    }
    else
    {
    queue.insertionAtHead(data);
    size++;
    }
}

double Queue::pop()
{
    double data = queue.removeTail();
    if(data < 0)
    {
        cout<<"Nothing"<<endl;
        return -1;
    }
    else
        return data;
}
