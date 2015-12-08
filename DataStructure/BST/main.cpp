#include "BST.h"

int main(void){
  BST tree;
  tree.insert(10);
  tree.insert(2);
  tree.insert(4);
  tree.insert(12);
  tree.insert(23);
  tree.traverse();
  tree.custom_print();
  return 0;
}
