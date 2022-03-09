#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

vector<int> v ;//= new vector<int>();
void helper(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
       
    v.push_back(root->data);
    helper(root->leftChild);
    helper(root->rightChild);
    
}   

void pairSum(BinaryTreeNode<int>* root,int sum){
    if(root==NULL)
        return;

    helper(root);
    sort(v.begin(),v.end());
    int i=0,j=v.size()-1;
    cout<<v.size()<<endl;
    while(i<j){
        int s = v[i] + v[j];
        if(s==sum){
            cout<<v[i]<<" "<<v[j]<<" "<<endl;
            i++;
            j--;
        }
        else if(s < sum){
            i++;
        }
        else{
            j--;
        }
    }
}

int main(){
   BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}