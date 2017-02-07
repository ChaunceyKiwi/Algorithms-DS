#include <iostream>
#include "NetworkFlow.hpp"
using namespace std;

int main(void)
{
  NetworkFlow networkFlow(6, 0, 5);
  networkFlow.addEdge(0, 1, 16);
  networkFlow.addEdge(1, 3, 12);
  networkFlow.addEdge(3, 5, 20);
  networkFlow.addEdge(0, 2, 13);
  networkFlow.addEdge(2, 4, 14);
  networkFlow.addEdge(4, 5, 4);
  networkFlow.addEdge(1, 2, 10);
  networkFlow.addEdge(2, 1, 4);
  networkFlow.addEdge(3, 2, 9);
  networkFlow.addEdge(4, 3, 7);
  
  cout << networkFlow.fordFulkerson() << endl;
}
