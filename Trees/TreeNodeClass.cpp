#include<iostream>
#include<vector>
using namespace std;
template<typename T>

class treeNode{
    public:
    T data;
    vector<treeNode<T> *> children;

    treeNode(T data){
        this->data = data;
    }
};

void printTree(treeNode<int>* root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;

    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    treeNode<int>* root = new treeNode<int>(1);
    treeNode<int>* Node1 = new treeNode<int>(2);
    treeNode<int>* Node2 = new treeNode<int>(3);
    // treeNode<int>* Node3 = new treeNode<int>(10);

    root->children.push_back(Node1);   
    root->children.push_back(Node2);   
    // Node1->children.push_back(Node3);
    printTree(root);
}