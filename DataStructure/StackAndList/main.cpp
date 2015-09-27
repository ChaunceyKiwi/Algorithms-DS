#include <iostream>
#include "stack.h"
using namespace std;

int main ()
{
    Stack stack1;
    stack1.push(3.14);
    stack1.push(6.28);
    stack1.push(3.14);
    stack1.push(6.28);
    stack1.push(3.14);
    stack1.push(6.28);
    stack1.push(3.14);
    stack1.push(6.28);
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
}