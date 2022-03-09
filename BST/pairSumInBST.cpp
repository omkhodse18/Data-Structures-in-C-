#include<iostream>
#include<queue>
#include<stack>
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

int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1 + countNodes(root->leftChild) + countNodes(root->rightChild);
}

void printNodesSumToS(BinaryTreeNode<int>* root, int s){
    int totalNodes = countNodes(root);
    int count = 0;

    stack<BinaryTreeNode<int>*> inorder;
    stack<BinaryTreeNode<int>*> revInorder;
    BinaryTreeNode<int>* temp = root;

    while(temp!=NULL){
        inorder.push(temp);
        temp=temp->leftChild;
    }

    temp=root;
    
    while(temp!=NULL){
        revInorder.push(temp);
        temp=temp->rightChild;
    }

    while(count < totalNodes-1){
        BinaryTreeNode<int>* top1 = inorder.top();
        BinaryTreeNode<int>* top2 = revInorder.top();

        if(top1->data + top2->data == s){
            cout<<top1->data<<" "<<top2->data<<endl;

            BinaryTreeNode<int>* top = top1;
            inorder.pop();
            count++;
            if(top->rightChild != NULL){
                top = top->rightChild;
                while(top!=NULL){
                    inorder.push(top);
                    top = top->leftChild;
                }
            }

            top = top2;
            revInorder.pop();
            count++;
            if(top->leftChild != NULL){
                top = top->leftChild;
                while(top!=NULL){
                    revInorder.push(top);
                    top = top->rightChild;
                }
            }
        }
        else if(top1->data + top2->data > s){
            BinaryTreeNode<int>* top = top2;
            revInorder.pop();
            count++;
            if(top->leftChild != NULL){
                top = top->leftChild;
                while(top!=NULL){
                    revInorder.push(top);
                    top = top->rightChild;
                }
            }
        }
        else{
            BinaryTreeNode<int>* top = top1;
            inorder.pop();
            count++;
            if(top->rightChild != NULL){
                top = top->rightChild;
                while(top!=NULL){
                    inorder.push(top);
                    top = top->leftChild;
                }
            }
        }
    }


}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
}
