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
