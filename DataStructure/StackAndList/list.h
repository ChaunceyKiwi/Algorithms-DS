//
//  list.h
//  deleteLater
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//

#ifndef __deleteLater__list__
#define __deleteLater__list__

class list{
    public:
    struct Node{
        double data;
        Node *next;
    };
    
    Node *head;
    int length;
    
    list();
    int insertionAtHead(double data);
    double removeHead();
    void printList();
    
};
#endif /* defined(__deleteLater__list__) */
