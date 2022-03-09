#include<iostream>
#include<vector>
#include<queue>
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

treeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Root : ";
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);
    queue<treeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0){
        treeNode<int>* Front = pendingNode.front();
        pendingNode.pop();

        int numChild;
        cout<<"How many childrens "<<Front->data<<" have : ";
        cin>>numChild;

        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter the "<<i<<"th child of "<<Front->data<<" : ";
            cin>>childData;
            treeNode<int>* Child = new treeNode<int>(childData);
            Front->children.push_back(Child);
            pendingNode.push(Child);
        }
    }
    return root;
}

void printTree(treeNode<int>* root){
    queue<treeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0){
        treeNode<int>* Front = pendingNode.front();
        pendingNode.pop();
        cout<<Front->data<<" : ";
        for(int i=0;i<Front->children.size();i++){
            treeNode<int>* grandChild = Front->children[i];
            cout<<grandChild->data<<" ";
            if (i != Front->children.size()-1)
            {
                cout<<", ";
            }
            pendingNode.push(grandChild);
        }
        cout<<endl;
    }
}

int main(){
    treeNode<int>* root = takeInput();
    printTree(root);
}