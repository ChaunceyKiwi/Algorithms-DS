#include <stdio.h>
#include "list.h"

class Queue{
    private:
        int size;
    public:
        list queue;
        Queue();
        int getSize();
        void print();
        void push(double data);
        double pop();
};
