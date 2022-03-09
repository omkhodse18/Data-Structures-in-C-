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


void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->leftChild != NULL) {
            q.push(first->leftChild);
        }
        if (first->rightChild != NULL) {
            q.push(first->rightChild);
        }
    }
}
int sumofNode(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return root->data + sumofNode(root->leftChild) + sumofNode(root->rightChild);
}

void replaceWithLargerNode(BinaryTreeNode<int>* root,int sum=0){
    if(root==NULL)  return;

    int rightSum = sumofNode(root->rightChild);
    root->data += rightSum+sum;

    replaceWithLargerNode(root->rightChild,sum);
    sum = root->data;
    replaceWithLargerNode(root->leftChild,sum);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    cout<<endl;
    // printLevelATNewLine(root);
    replaceWithLargerNode(root);
    cout<<endl;
    printLevelATNewLine(root);
}