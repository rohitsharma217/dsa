#include <iostream>
using namespace std;
class node {
public:
  node *left, *right;
  int data;
  bool lthread, rthread;
  node() { left = right = NULL; }
};
class tbt {
  node *root;

public:
  node *insert(node *, int);
  node *successor(node *);
  void inorder(node *);
  tbt() { root == NULL; }
};
node *tbt::insert(node *root, int key) {
  node *ptr = root;
  node *par = NULL;
  while (ptr != NULL) {
    if (ptr->data == key) {
      return root;
    }
    par = ptr;
    if (key < ptr->data) {
      if (ptr->lthread == false)
        ptr = ptr->left;
      else
        break;
    } else {
      if (ptr->rthread == false)
        ptr = ptr->right;
      else
        break;
    }
  }
  node *tmp = new node;
  tmp->data = key;
  tmp->lthread = true;
  tmp->rthread = true;

  if (par == NULL) {
    root = tmp;
    tmp->left = NULL;
    tmp->right = NULL;
  } else if (key < (par->data)) {
    tmp->left = par->left;
    tmp->right = par;
    par->lthread = false;
    par->left = tmp;
  } else {
    tmp->left = par;
    tmp->right = par->right;
    par->rthread = false;
    par->right = tmp;
  }

  return root;
}
node *tbt ::successor(node *ptr) {
  if (ptr->rthread == true)
    return ptr->right;

  ptr = ptr->right;
  while (ptr->lthread == false)
    ptr = ptr->left;
  return ptr;
}

void tbt::inorder(node *root) {

  if (root == NULL)
    printf("Tree is empty");

  struct node *ptr = root;
  while (ptr->lthread == false)
    ptr = ptr->left;

  // One by one print successors
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = successor(ptr);
  }
}
int main() {
  tbt a;
  node *root = NULL;
  root = a.insert(root, 90);
  root = a.insert(root, 56);
  root = a.insert(root, 600);
  root = a.insert(root, 9);
  root = a.insert(root, 10);
  cout << "Inorder:\t";
  a.inorder(root);
}
