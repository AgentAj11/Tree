// Program to count leaf nodes present in the given binary tree

#include <iostream>
using namespace std;


class Node{
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this -> data = data;
            this -> left = this -> right = NULL;
        }
};


void count(Node *root, int &leafNodes){
    if(!root)
        return;
    if(root -> left == NULL && root -> right == NULL){
        leafNodes++;
    }

    count(root -> left, leafNodes);
    count(root -> right, leafNodes);
}


int main(void){

    Node* root = NULL;

    int leafNodes = 0;
    count(root, leafNodes);
    
    cout << "\nLeaf Nodes = " << leafNodes << endl;

    return 0;
}