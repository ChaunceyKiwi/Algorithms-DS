#include <iostream>
#include "NetworkFlow.hpp"
using namespace std;

int main(void)
{
  NetworkFlow networkFlow(12, 0, 11);
  
  // connect left nodes to sink
  for(int i = 1; i <= 5; i++) {
    networkFlow.addEdge(0, i, 1);
  }
  
  // matchings
  networkFlow.addEdge(1, 6, 1);
  networkFlow.addEdge(1, 8, 1);
  networkFlow.addEdge(2, 6, 1);
  networkFlow.addEdge(2, 7, 1);
  networkFlow.addEdge(2, 8, 1);
  networkFlow.addEdge(3, 9, 1);
  networkFlow.addEdge(4, 8, 1);
  networkFlow.addEdge(5, 9, 1);
  networkFlow.addEdge(5, 10, 1);
  
  // connect right nodes to source
  for(int i = 6; i <= 10; i++) {
    networkFlow.addEdge(i, 11, 1);
  }
  
  // using ford-fulkerson to find max matchings
  cout << networkFlow.fordFulkerson() << endl;
}
