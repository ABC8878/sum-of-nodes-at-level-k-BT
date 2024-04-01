#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int countnodes(Node *root)
{
    if (root == NULL)
        return 0;

    root->data= countnodes(root->left) + countnodes(root->right) + root->data;
    return root->data;
}

void inorder(Node*root){
    if(root==NULL){
        return;
    }
cout<<root->data<<" ";
inorder(root->left);

inorder(root->right);

}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

     countnodes(root);
inorder(root);
    return 0;
}