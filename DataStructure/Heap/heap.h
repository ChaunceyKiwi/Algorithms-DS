//
//  heap.h
//  deletable
//
//  Created by Chauncey on 9/26/15.
//  Copyright (c) 2015 Chauncey. All rights reserved.
//

#ifndef __deletable__heap__
#define __deletable__heap__

#include <stdio.h>
#include <vector>
#include <string>

class Heap{
    std::vector<int> queue_;
    unsigned int size_;
    
    void bubbleUp(int idx);
    void bubbleDown(int idx);
    int getMinIdx(int aIdx,int bIdx,int cIdx);
    
public:
    Heap();
    ~Heap(){};
    bool isEmpty() const;
    int size() const;
    void clear();
    int getItem(unsigned int idx) const;
    int parent(unsigned int idx) const;
    int child(unsigned int idx) const;
    int find(unsigned int idx,int val) const;
    void insert(int val);
    void remove(int val);
    void makeHeap(int array[],int size);
    void makeHeap(std::vector<int> &input);
    int extractMin();
    std::vector<int> heapSort();
    std::string toString() const;
    
};

#endif /* defined(__deletable__heap__) */
