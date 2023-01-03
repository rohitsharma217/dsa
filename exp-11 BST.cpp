//Binary Search Tree

#include <iostream>
using namespace std;
struct Node
{
   int data;
   struct Node *left;
   struct Node *right;
};

struct Node *create(int key)
{
   struct Node *newnode = new Node;
   newnode->data = key;
   newnode->left = NULL;
   newnode->right = NULL;
   return newnode;
}

struct Node *insert(struct Node *node,int key)
{
   if(node == NULL)
      return create(key);
   if(key < node->data)
      node->left = insert(node->left,key);
   else if(key > node->data)
      node->right = insert(node->right,key);
   return node;
}

int search(struct Node *root,int key)
{
   if(root == NULL || root->data == key)
      return root->data;
   if(key < root->data)
      search(root->left,key);
   else if(key > root->data)
      search(root->right,key);
   return root->data;
}

void inorder(struct Node *node)
{
   if(node != NULL)
   {
      inorder(node->left);
      cout<<node->data<<"->";
      inorder(node->right);
   }
}

int main()
{
   struct Node *root = new Node;
   root = create(1035);
   root = insert(root, 10);
   root = insert(root, 2066);
   inorder(root);

   return 0;
}

