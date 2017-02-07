#include "BST.h"

Node::Node(){
  left = right = NULL;
}

Node::Node(int val){
  left = right = NULL;
  data = val;
}

BST::BST(){
  root = current = NULL;
}

void BST::insert(int val){
  if(root == NULL)
    root = new Node(val);
  else{
    Node* p = findNodeByValue(val);
    if(p == NULL)
    {
      Node* parent = root;
      if(p != root)
        parent = findParentForNode(val);
      if(val > parent->data)
        parent->right = new Node(val);
      else
        parent->left = new Node(val);
    }
  }
}

Node* BST::findNodeByValue(int key){
  Node *p = root;
  while((p != NULL) && (p->data != key)){
    if(key < p->data)
      p = p->left;
    else p = p->right;
  }
  return p;
}

Node* BST::findParentForNode(int key){
  Node *p = root;
  Node *q;
  while((p != NULL) && (p->data != key)){
    q = p;
    if(key < p->data)
      p = p->left;
    else p = p->right;
  }
  return q;
}

void BST::inorder(Node *p){
  if(p != NULL){
    inorder(p->left);
    cout<<p->data<<" ";
    inorder(p->right);
  }
}

void BST::preorder(Node *p){
  if(p != NULL){
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
  }
}

void BST::postorder(Node *p){
  if(p != NULL){
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<" ";
  }
}

void BST::traverse(){
  cout<<"Preorder: ";
  preorder(root);
  cout<<endl<<"Inorder: ";
  inorder(root);
  cout<<endl<<"PostOrder: ";
  postorder(root);
  cout<<endl;
}

void BST::custom_print(){
  if(root == NULL) return;
  queue<Node*> Q;
  Q.push(root);
  while(!Q.empty()){
    current = Q.front();
    cout<<current->data<<" ";
    Q.pop();
    if(current->left != NULL)
    Q.push(current->left);
    if(current->right != NULL)
    Q.push(current->right);
  }
  cout<<endl;
}
