#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int value) {
    if(root == NULL)
        return createNode(value);
    else if(value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout<<"Duplicate value "<<value<<" not allowed.\n";
    return root;
}
bool search(Node* root, int value) {
    if(root == NULL) return false;
    if(value == root->data) return true;
    if(value < root->data) return search(root->left, value);
    return search(root->right, value);
}
void preorder(Node* root)
{
    if (root!=NULL)
    {
        cout<<root->data<< " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(Node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<< " ";
    }
}
Node* findMin(Node* root){
    if(root == NULL) 
	return NULL;
    if(root->left == NULL) 
	return root;
    return findMin(root->left);
}
Node* findMax(Node* root) {
    if(root == NULL) 
	return NULL;
    else if(root->right == NULL) 
	return root;
    return findMax(root->right);
}
int height(Node* root) {
    if (root == NULL) 
	return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
int countNodes(Node* root){
    if(root == NULL) 
	return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int countLeafNodes(Node* root){
    if (root == NULL) 
	return 0;
    else if(root->left == NULL && root->right == NULL)
	return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main() {
    Node* root=NULL;
    int choice,value;
    do {
        cout<<"\n===== BST MENU =====\n";
        cout<<"1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n";
        cout<<"6. Find Min\n7. Find Max\n8. Height\n9. Count Nodes\n";
        cout<<"10. Count Leaf Nodes\n0. Exit\nEnter choice: ";
        cin>>choice;
        switch (choice){
        case 1: {
            int n;
            cout<<"How many values do you want to insert? ";
            cin>>n;
            for(int i = 1; i <= n; i++) {
                cout<<"Enter value " << i << ": ";
                cin>>value;
                root=insert(root, value);
            }
            break;
        }
        case 2:
            cout<<"Enter value to search: ";
            cin>>value;
            cout<<value<<(search(root, value) ?" found.\n":" not found.\n");
            break;
        case 3:
            cout<<"Inorder: ";
            inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder: ";
            preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder: ";
            postorder(root);
            cout<<endl;
            break;
        case 6: {
            Node* m=findMin(root);
            if (m) 
			cout<<"Minimum: "<< m->data << endl;
            else 
			cout<<"Tree is empty.\n";
            break;
        }
        case 7: {
            Node* m=findMax(root);
            if (m) 
			cout<<"Maximum: "<<m->data << endl;
            else 
			cout<<"Tree is empty.\n";
            break;
        }
        case 8:
            cout<<"Height: " << height(root) << endl;
            break;
        case 9:
            cout<<"Total nodes: "<<countNodes(root) << endl;
            break;
        case 10:
            cout<<"Leaf nodes: "<<countLeafNodes(root) << endl;
            break;
        case 0:
            cout<<"Exiting.\n";
            break;
        default:
            cout<<"Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
