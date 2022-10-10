#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
/* Function to traverse the binary tree without recursion and without stack */
void mtraversal(struct Node* root)
{
    struct Node *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }    
    }
}
 
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Driver program to test above functions*/
int main()
{
 
    /* Binary tree is given as:
            1
          /   \
         2     3
       /   \
      4     5
  */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    mtraversal(root);
 
    return 0;
}