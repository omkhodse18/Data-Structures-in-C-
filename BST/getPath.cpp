#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput(){
    int rootData,lChild,rChild;
    cout<<"Enter root data : ";
    cin>>rootData;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(q.size()!=0){
        BinaryTreeNode<int>* Front = q.front();
        q.pop();
        
        cout<<"Enter left child of "<<Front->data<<" : ";
        cin>>lChild;
        if(lChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(lChild);
            Front->left = child;
            q.push(child);
        }

        cout<<"Enter right child of "<<Front->data<<" : ";
        cin>>rChild;
        if(rChild != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rChild);
            Front->right = child;
            q.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(q.size()!=0){
        BinaryTreeNode<int>* Front = q.front();
        q.pop();
        cout<<Front->data<<" : ";

        if(Front->left != NULL){
            cout<<"L:"<<Front->left->data<<" ";
            q.push(Front->left);
        }
        else{
            cout<<"L:  ";
        }

        if(Front->right != NULL){
            cout<<"R:"<<Front->right->data<<endl;
            q.push(Front->right);
        }
        else{
            cout<<"R:\n";
        }
    }
}

vector<int>* getPath(BinaryTreeNode<int>* root,int data){
    if(root==NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getPath(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getPath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }else{
        return NULL;
    }
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printTree(root);
    int k;
    cin>>k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}