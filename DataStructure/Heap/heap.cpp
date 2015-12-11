#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream>
#include "heap.h"

using namespace std;
typedef vector<int> ::iterator vecIter;
typedef vector<int> ::const_iterator vecCiter;

//add a dud first element
Heap::Heap():queue_(1,0),size_(0) {}

bool Heap::isEmpty() const
{
    return (size_ == 0);
}

int Heap::size() const
{
    return size_;
}

void Heap::clear()
{
    queue_.clear();
    queue_.push_back(0);//first item is a dud
}

int Heap::getItem(unsigned int idx) const
{
    return queue_[idx];
}


int Heap::parent(unsigned int idx) const
{
    if(size_ <= 1) return -1;
    return ((int)(idx/2));
}

int Heap::child(unsigned int idx) const
{
    if(size_ <= 1||2 * idx > size_) return -1; //empty of root has not child
    return 2*idx;
}

int Heap::find(unsigned int idx, int val) const
{
    if(idx > size_) return -1; //base case:idx out of bounds
    if(val < queue_[idx]) return -1; //base case:val not in min-heap
    if(queue_[idx] == val) return idx;//found the val,return its index

    int childIdx = child(idx), i = -1;

    if(childIdx != -1) //find in left and right children
    {
        i = max(find(childIdx,val),find(childIdx +1, val));
    }
    return i;
}

void Heap::bubbleUp(int idx)
{
    int parentIdx = parent(idx);
    if(parentIdx == -1) return;  //base case:root of heap

    if(queue_[parentIdx] > queue_[idx])
    {
        swap(queue_[parentIdx],queue_[idx]);
        bubbleUp(parentIdx);
    }
}

void Heap::insert(int val)
{
    queue_.push_back(val);
    size_++;
    bubbleUp(size_);
}

int Heap::getMinIdx(int aIdx, int bIdx, int cIdx)
{
    bool isLeftSmaller = (queue_[aIdx] < queue_[bIdx]);

    if(cIdx > (int)size_) //the last right child does not exist
    {
        return isLeftSmaller?aIdx:bIdx;
    }
    else if(isLeftSmaller)
    {
        return (queue_[aIdx] < queue_[bIdx])?aIdx:cIdx;
    }
    else
    {
        return (queue_[bIdx] < queue_[cIdx])?bIdx:cIdx;
    }
}

void Heap::bubbleDown(int idx)
{
    int childIdx = child(idx);
    if(childIdx == -1) return;
    int minIdx = getMinIdx(idx, childIdx, childIdx + 1);

    if(minIdx != idx)
    {
        swap(queue_[minIdx],queue_[idx]);
        bubbleDown(minIdx);
    }
}

void Heap::remove(int val)
{
    int idx = find(1,val);
    if(idx == -1) return;

    queue_[idx] = queue_[size_--];
    queue_.resize(size_ + 1);
    bubbleDown(idx);
    bubbleUp(idx);
}

int Heap::extractMin()
{
    if(isEmpty()) throw "Empty Heap!";

    int min = queue_[1];
    remove(min);
    return min;
}

vector<int> Heap::heapSort()
{
    vector<int> sortedItems;
    sortedItems.reserve(size_);
    while(!isEmpty())
    {
        sortedItems.push_back(extractMin());
    }
    return sortedItems;
}

void Heap::makeHeap(int array[], int n)
{
    size_ = n;
    int i = 0;

    for(;i < n;i++)
        queue_.push_back(array[i]);
    for(int i = n;i > 0;i--)
        bubbleDown(i);
}

void Heap::makeHeap(std::vector<int> &input)
{
    size_ = (unsigned int)input.size();
    vecCiter citer = input.begin();

    for(;citer != input.end();citer++)
    {
        queue_.push_back(*citer);
    }

    for(int i = size_;i > 0;i--)
    {
        bubbleDown(i);
    }
}

string Heap::toString() const
{
    if(isEmpty()) return "";

    ostringstream sstream;
    copy(queue_.begin() + 1,queue_.end() - 1,ostream_iterator<int>(sstream," "));
    sstream << *(queue_.end() -1);

    return sstream.str();
}
