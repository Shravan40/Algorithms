#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int height(Node* root)
{
    if(root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return(max(lh,rh)+1);
}

void print_given_level(Node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        cout<<root->data<<" ";
    else if(level > 1)
    {
        print_given_level(root->left,level-1);
        print_given_level(root->right,level-1);
    }
}

void print_level_order(Node* root)
{
    int h = height(root);
    for(int i = 1; i <= h; i++)
        print_given_level(root,i);
}
Node* New_Node(int val)
{
    Node* new_node = new Node();
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

Node* insert(Node* root, int val)
{
    if(root == NULL)
        return (New_Node(val));
    if(root->data < val)
       root->right =  insert(root->right,val);
   else
       root->left = insert(root->left,val);
    return (root);
}

int main()
{
    Node* root = NULL;
    root = insert(root,2);
    root = insert(root,5);
    root = insert(root,20);
    root = insert(root,24);
    root = insert(root,10);
    root = insert(root,7);
    root = insert(root,12);
    root = insert(root,9);
    print_level_order(root);
    cout<<"\n";
    return 0;
}
