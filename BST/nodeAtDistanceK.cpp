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

void nodeAtLevelK(BinaryTreeNode<int>* root,int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    nodeAtLevelK(root->leftChild,k-1);
    nodeAtLevelK(root->rightChild,k-1);
}

int helper(BinaryTreeNode<int>* root,int node,int k){
    if(root==NULL){
        return -1;
    }

    if(node == root->data){
        nodeAtLevelK(root,k);
        return 0;
    }

    int lDistance = helper(root->leftChild,node,k);
    if(lDistance != -1){
        if(lDistance + 1 == k){
            cout<<root->data<<" "<<endl;
        }
        else{
            nodeAtLevelK(root->rightChild,k-lDistance-2);
        }
        return lDistance+1;
    }

    int rDistance = helper(root->rightChild,node,k);
    if(rDistance != -1){
        if(rDistance + 1 == k){
            cout<<root->data<<" "<<endl;
        }
        else{
            nodeAtLevelK(root->leftChild,k-rDistance-2);
        }
        return rDistance+1;
    }

    return -1;
}

void nodeAtDistanceK(BinaryTreeNode<int>* root,int node,int k){
    helper(root,node,k);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int targetNode, k;
    cin >> targetNode >> k;
    nodeAtDistanceK(root, targetNode, k);
    delete root;
}