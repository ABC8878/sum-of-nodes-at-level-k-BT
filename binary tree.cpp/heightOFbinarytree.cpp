#include <iostream>
#include <queue>
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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node!=NULL)
        {
           if(node->left!=NULL){
             q.push(node->left);
           }
           if(node->right!=NULL){
            q.push(node->right);
           }
           
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return level+1;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(4);
    root->left->left->left->left = new Node(4);
    cout<<height(root);
    return 0;
}