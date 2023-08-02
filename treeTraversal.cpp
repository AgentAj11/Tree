// tree traversal
// 1. in order
// 2. pre order
// 3. post order


#include <iostream>
using namespace std;


struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
}


struct node* insertLeft(struct node* root, int data){
    struct node* newNode = createNode(data);
    root -> left = newNode;
    return newNode;
}


struct node* insertRight(struct node* root, int data){
    struct node* newNode = createNode(data);
    root -> right = newNode;
    return newNode;
}


void preOrder(struct node* root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}


void inOrder(struct node* root){
    if(root == NULL)
        return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}


void postOrder(struct node* root){
    if(root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}


int main(void){

    struct node* root = NULL;

    root = createNode(10);

    root -> left = insertLeft(root, 20);
    root -> right = insertRight(root, 30);

    root -> left -> left = insertLeft(root -> left, 40);
    root -> left -> right = insertRight(root -> left, 50);

    root -> right -> left = insertLeft(root -> right, 60);
    root -> right -> right = insertRight(root -> right, 70);


    cout << "\nPre Order : ";
    preOrder(root);
    cout << "\nInorder : ";
    inOrder(root);
    cout << "\nPost Order : ";
    postOrder(root);

    return 0;
}


