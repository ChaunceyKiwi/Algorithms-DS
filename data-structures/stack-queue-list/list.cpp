//
//  list.cpp
//  deleteLater
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//
#include <iostream>        // This is a key C++ library
#include "list.h"

using namespace std;


//Default constructor
list::list()
{
    head = NULL;
    length = 0;
}

//Insert at head of list
//return 1 on success,return 0 on failure
int list::insertionAtHead(double data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode){
        newNode->data = data;
        newNode->next = head ;
        head = newNode;
        length++;
        return 1;
    }
    else return 0;
}

//Remove head of list
double list::removeHead()
{
    //checking for removing a null
    double retVal = 0.0;
    if(head)
    {
        retVal = head->data;
        head = head->next;
        return retVal;
    }
    else return -1;
}

//Remove head of list
double list::removeTail()
{
    Node *currentNode;
    currentNode = head;
    double retVal = 0.0;

    if(head == NULL)
      return -1;
    else{
        while(currentNode)
        {
            if(currentNode->next->next == NULL)
                break;
            else
                currentNode = currentNode->next;
        }
        retVal = currentNode->next->data;
        currentNode->next = NULL;
      }
    return retVal;
}

//prints list from head to end
void list::printList()
{
    Node *currentNode;
    currentNode = head;

    while(currentNode)
    {
        cout<<currentNode->data<<endl;
        currentNode = currentNode->next;
    }
}
