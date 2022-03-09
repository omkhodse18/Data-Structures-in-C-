#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* leftChild;
    BinaryTreeNode<T>* rightChild;

    BinaryTreeNode(T data){
        this->data=data;
        leftChild = NULL;
        rightChild = NULL;
    }
};

BinaryTreeNode<int>* takeInput(){
    int rootData,leftChildData,rightChildData;
    cout<<"Enter Root data : ";
    cin>>rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.size() != 0){
        BinaryTreeNode<int>* Front = pendingNode.front();
        pendingNode.pop();
        
        cout<<"Enter left child of "<<Front->data<<" : ";
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            Front->leftChild = child;
            pendingNode.push(child);
        }

        cout<<"Enter right child of "<<Front->data<<" : ";
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* ChildRight = new BinaryTreeNode<int>(rightChildData);
            Front->rightChild = ChildRight;
            pendingNode.push(ChildRight);
        }
    }
    return root;
}

void printLevelwise(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        BinaryTreeNode<int>* Front = pendingNode.front();
        pendingNode.pop();
        cout<<Front->data<<" : ";

        if (Front->leftChild != NULL)
        {
            cout<<"L:"<<Front->leftChild->data<<" ";
            pendingNode.push(Front->leftChild);
        }
        else{
            cout<<"L:  ";
        }
        
        if (Front->rightChild != NULL)
        {
            cout<<"R:"<<Front->rightChild->data<<endl;
            pendingNode.push(Front->rightChild);
        }
        else{
            cout<<"R:  "<<endl;
        }
    }
}

void elementBetweenRange(BinaryTreeNode<int>* root,int min,int max){
    if(root==NULL)  return;

    // if(root->data >= min && root->data <=max){
    //     cout<<root->data<<" ";
    // }

    // if(root->data < max){
    //     elementBetweenRange(root->rightChild,min,max);
    // }
    // else if(root->data > min){
    //     elementBetweenRange(root->leftChild,min,max);
    // }

    if(root!=NULL){
        if(root->data >= min && root->data <= max){
            elementBetweenRange(root->leftChild,min,max);
            cout<<root->data<<" ";
            elementBetweenRange(root->rightChild,min,max);
        }
        else if(root->data < max){
                elementBetweenRange(root->rightChild,min,max);
            }
        else if(root->data > min){
            elementBetweenRange(root->leftChild,min,max);
        }
    }
}

// 45 35 68 15 42 64 78 -1 -1 -1 -1 -1 -1 -1 -1

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printLevelwise(root);
    cout<<"To check the numbers which are lying between two numbers : ";
    int min,max;
    cin>>min>>max;
    cout<<endl;
    elementBetweenRange(root,min,max);
}