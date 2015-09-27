//
//  stack.h
//  deleteLater
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//

#ifndef __deleteLater__stack__
#define __deleteLater__stack__

#include <stdio.h>
#include "list.h"

class Stack{
    private:
        int size;
    public:
        list stack;
        Stack();
        int getSize();
        void print();
        void push(double data);
        double pop();
};

#endif /* defined(__deleteLater__stack__) */
