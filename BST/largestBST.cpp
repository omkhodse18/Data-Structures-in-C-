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

class Pair{
    public:
    int minimum;
    int maximum;
    int height;
    bool isBST;
};

Pair BST(BinaryTreeNode<int>* root){
    if(root==NULL){
        Pair p;
        p.minimum = INT_MAX;
        p.maximum = INT_MIN;
        p.height = 0;
        p.isBST = true;
        return p;
    }

    Pair left = BST(root->leftChild);
    Pair right = BST(root->rightChild);

    int minimum = min(root->data,min(left.minimum,right.minimum));
    int maximum = max(root->data,max(left.maximum,right.maximum));
    bool isBSTFinal = (root->data > left.maximum) && (root->data < right.minimum) && left.isBST && right.isBST;

    Pair obj;
    obj.minimum = minimum;
    obj.maximum = maximum;
    obj.isBST = isBSTFinal;

    if(isBSTFinal){
        obj.height = 1+max(left.height,right.height);
    }
    else{
        obj.height = max(left.height,right.height);
    }
    return obj;
}

int largestBST(BinaryTreeNode<int>* root){
    return BST(root).height;
}
int main(){
    BinaryTreeNode<int>* root = takeInput();
    // printLevelwise(root);
    cout<<endl<<endl;
    cout<<largestBST(root);
}