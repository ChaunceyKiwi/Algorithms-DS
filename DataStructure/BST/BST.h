#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node();
    Node(int);
};

class BST{
  public:
    Node* root;
    Node* current;
    BST();
    Node* findNodeByValue(int);
    Node* findParentForNode(int);
    Node* findRightNode(int);
    void insert(int);
    void remove(int);
    void traverse();
    int retrive();
    void custom_print();
    void inorder(Node *);
    void postorder(Node *);
    void preorder(Node *);
};
