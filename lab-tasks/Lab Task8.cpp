#include<iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};
BSTNode* CreateNode(int value)
{
    BSTNode* newNode = new BSTNode;

    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

BSTNode* Insert(BSTNode* root, int value)
{
    if (root==NULL)
    {
        return CreateNode(value);
    }
    else if(value<root->data)
    {
        root->left=Insert(root->left, value);
    }
    else if (value>root->data)
    {
        root->right=Insert(root->right, value);
    }
    return root;
}
void Preorder(BSTNode* root)
{
    if (root!=NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Inorder(BSTNode* root)
{
    if (root!=NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
void Postorder(BSTNode* root)
{
    if (root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    BSTNode* root=NULL;
    int n, value;
    cout<<"Enter number of nodes: ";
    cin>>n;

    for (int i=0; i<n; i++)
    {
        cout<<"Enter value: ";
        cin>>value;
        root=Insert(root, value);
    }

    cout<<"\nPreorder Traversal:"<<endl;
    Preorder(root);

    cout<<"\n\nInorder Traversal:"<<endl;
    Inorder(root);

    cout<<"\n\nPostorder Traversal:"<<endl;
    Postorder(root);
    cout<<endl;

    return 0;
}
