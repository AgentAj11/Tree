// Tree creation by level order pardigm
// and displaying in similar fashion
// Level Order Traversal => Queue

#include <iostream>
#include <queue>
using namespace std;


class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this -> data = data;
            this -> left = this -> right = NULL;
        }
};


void tree(Node* &root){

    int data;
    cout << "\nRoot : ";
    cin >> data;

    queue<Node*> q;
    Node* temp = NULL;

    root = new Node(data);
    
    q.push(root);

    while(!q.empty()){
        
        temp = q.front();
        q.pop();

        int leftChild;
        cout << "\nLeft Child of " << temp -> data << " : ";
        cin >> leftChild;
        
        if(leftChild != -1){
            temp -> left  = new Node(leftChild);
            q.push(temp -> left);
        }

        int rightChild;
        cout << "\nRight Child of " << temp -> data << " : ";
        cin >> rightChild;

        if(rightChild != -1){
            temp -> right = new Node(rightChild);
            q.push(temp -> right);
        }
    }
}


void display(Node* root){

    if(!root) return;

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node -> left)
            q.push(node -> left);
        
        if(node -> right)
            q.push(node -> right);
        
        cout << node -> data << " ";
    }
}


int main(void){

    Node* root = NULL;
    tree(root);
    display(root);
    return 0;
}