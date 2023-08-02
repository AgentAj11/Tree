// build binary tree : pre-order

#include <iostream>
using namespace std;


class Node{
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};


// here root does not refer to the real root of the tree instead it represents the root of smallest sub-tree at any time
Node* tree(struct Node* root){

    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new Node(data);

    cout << "\nLeft of " << data << " : ";
    root -> left = tree(root -> left);

    cout << "\nRight of " << data << " : ";
    root -> right = tree(root -> right);

    return root;
}


void preOrder(Node* root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}


void inOrder(struct Node* root){
    if(root == NULL)
        return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}


void postOrder(struct Node* root){
    if(root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}


int main(void){

    Node* root = NULL;

    root = tree(root);

    cout << "\nPre Order : ";
    preOrder(root);
    cout << "\nInorder : ";
    inOrder(root);
    cout << "\nPost Order : ";
    postOrder(root);

    return 0;
}