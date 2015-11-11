#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

int main ()
{
//     Stack stack1;
//     stack1.push(3.14);
//     stack1.push(6.28);
//     stack1.push(3.14);
//     stack1.push(6.28);
//     stack1.push(3.14);
//     stack1.push(6.28);
//     stack1.push(3.14);
//     stack1.push(6.28);
//     cout<<stack1.pop()<<endl;
//     cout<<stack1.pop()<<endl;

    Queue stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    stack1.push(7);
    stack1.push(8);
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
}
