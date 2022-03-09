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

int maximum(BinaryTreeNode<int>* root){
    if(root==NULL)   return INT_MIN;
    int ans = root->data;
    
    return max(ans,max(maximum(root->leftChild),maximum(root->rightChild)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root==NULL)   return INT_MAX;
    int ans = root->data;
    
    return min(ans,min(minimum(root->leftChild),minimum(root->rightChild)));
}

bool isBST(BinaryTreeNode<int>* root){
    if(root==NULL)  return true;

    int leftMax = maximum(root->leftChild);
    int rightMin = minimum(root->rightChild);
    bool output = (leftMax < root->data) && (rightMin >= root->data) 
                    && isBST(root->leftChild) && isBST(root->rightChild);
    return output;
}
// 6 3 9 1 2 8 10 -1 -1 -1 -1 -1 -1 -1 -1

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printLevelwise(root);
    isBST(root)?cout<<"Given tree is BST":cout<<"Given tree is not BST";
}