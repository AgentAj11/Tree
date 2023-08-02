// creating simplest staic binary tree

#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
};


void preOrder(Node* root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}


void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}


void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}


void levelOrder(Node* root){
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp -> left){
            q.push(temp -> left);
        }   if(temp -> right){
            q.push(temp -> right);
        }

        cout << temp -> data << " ";
    }
}


int main(void){
    
    Node* root = new Node(10);

    root -> left = new Node(20);
    root -> right = new Node(30);

    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);

    root -> right -> left = new Node(60);
    root -> right -> right = new Node(70);

    root -> left -> left -> left = new Node(80);
    root -> left -> left -> right = new Node(90);

    cout << "\nPre Order : ";
    preOrder(root);
    cout << "\nInorder : ";
    inOrder(root);
    cout << "\nPost Order : ";
    postOrder(root);
    cout << "\nLevel Order : ";
    levelOrder(root);

    return 0;
}