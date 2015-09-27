//
//  stack.cpp
//  deleteLater
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//

#include "stack.h"
#include <iostream>

using namespace std;

//Default constructor
Stack::Stack()
{
    size = 0;
}

int Stack::getSize()
{
    return size;
}

void Stack::print()
{
    cout<< size <<endl;
}

void Stack::push(double data)
{
    if(getSize()>5)
    {
        cout<<"Stack is full!"<<endl;
    }
    else
    {
    stack.insertionAtHead(data);
    size++;
    }
}

double Stack::pop()
{
    double data = stack.removeHead();
    if(data < 0)
    {
        cout<<"Nothing"<<endl;
        return -1;
    }
    else
        return data;
}

