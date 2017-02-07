#include <iostream>
#include <vector>

using namespace std;

class Heap{
  vector<int> queue;
  unsigned int size_;

  void bubbleUp(int index);
  void bubbleDown(int index);
  int getMinIndex(int aIndex,int bIndex,int cIndex);

public:
  Heap();
  bool isEmpty();
  unsigned int size();
  int parent(unsigned int index);
  int child(unsigned int index);
  void insert(int val);
  void printHeap();
  void remove(int index);
  int extractMin();
  vector<int> heapSort();


};

Heap::Heap(){
  size_ = 0;
  queue.push_back(0);
}

bool Heap::isEmpty(){
  return (size_ == 0);
}

unsigned int Heap::size(){
  return size_;
}

void Heap::remove(int index){
  queue[index] = queue[size_];
  size_--;

  if(queue[index] < queue[parent(index)])
    bubbleUp(index);
  if((queue[index] > queue[child(index)]) || (queue[index] > queue[child(index) + 1]))
    bubbleDown(index);
}

int Heap::getMinIndex(int aIndex, int bIndex, int cIndex){
    bool isLeftSmaller = (queue[aIndex] < queue[bIndex]);

    if(cIndex > (int)size_){ //the last right child does not exist
        return isLeftSmaller?aIndex:bIndex;
    }else if(isLeftSmaller){
        return (queue[aIndex] < queue[bIndex])?aIndex:cIndex;
    }else{
        return (queue[bIndex] < queue[cIndex])?bIndex:cIndex;
    }
}

int Heap::parent(unsigned int index){
  if(size_ <= 1)
    return -1;
  else
    return ((int)(index / 2));
}

int Heap::child(unsigned int index){
  if(size_ <= 1 || 2 * index > size_)
    return -1;  //empty or root has no child
  else
    return 2 * index;
}

int Heap::extractMin(){
  if(isEmpty()) throw "Empty Heap!";
  int min = queue[1];
  remove(1);
  return min;
}

void Heap::bubbleUp(int index){
  int parentIndex = parent(index);

  if(parentIndex == -1)  //base case root
   return;
  if(queue[parentIndex] > queue[index]){
    swap(queue[parentIndex],queue[index]);
    bubbleUp(parentIndex);
  }
}
void Heap::bubbleDown(int index){
  int childIndex = child(index);
  if(childIndex == -1) return;
  int minIndex = getMinIndex(index,childIndex,childIndex + 1);

  if(minIndex != index){
    swap(queue[minIndex],queue[index]);
    bubbleDown(minIndex);
  }
}

void Heap::insert(int val){
  queue.push_back(val);
  size_++;
  bubbleUp(size_);
}

void Heap::printHeap(){
  int i;
  for(i = 1;i < size() + 1;i++)
    cout<<queue[i]<<" ";
  cout<<endl;
}

vector<int> Heap::heapSort(){
  vector<int> sortedItems;
  sortedItems.reserve(size_);
  while(!isEmpty()){
    int a = extractMin();
    sortedItems.push_back(a);
  }
  return sortedItems;
}
