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

class BST{
    BinaryTreeNode<int>* root;

    public:
    BST(){
        root = NULL;
    }

    ~BST(){
        delete root;
    }

    private:
    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int>* root,int data){
        if(root==NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(root->data > data){
            root->leftChild = insertHelper(root->leftChild,data);
        }
        else{
            root->rightChild = insertHelper(root->rightChild,data);
        }
        return root;
    }

    public:
    void insert(int data){
        root = insertHelper(root,data);
    }

    private:
    BinaryTreeNode<int>* deleteDataHelper(BinaryTreeNode<int>* root,int data){
        if(root==NULL){
            return NULL;
        }

        if(root->data > data){
            root->leftChild = deleteDataHelper(root->leftChild,data);
            return root;
        }
        else if(root->data <data){
            root->rightChild = deleteDataHelper(root->rightChild,data);
            return root;
        }
        else{
            if(root->leftChild==NULL && root->rightChild==NULL){
                delete root;
                return NULL;
            }
            else if(root->leftChild == NULL){
                BinaryTreeNode<int>* temp = root->rightChild;
                root->rightChild = NULL;
                delete root;
                return temp;
            }
            else if(root->rightChild == NULL){
                BinaryTreeNode<int>* temp = root->leftChild;
                root->leftChild = NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = root->rightChild;
                while(minNode->leftChild != NULL){
                    minNode = minNode->leftChild;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->rightChild = deleteDataHelper(root->rightChild,rightMin);
                return root;
            }
        }
    }

    public:
    void deleteData(int data){
        root = deleteDataHelper(root,data);
    }

    private:
    bool hasData(BinaryTreeNode<int>* root,int data){
        if(root==NULL)  return false;

        if(root->data == data){
            return true;
        }else if(root->data > data){
            return hasData(root->leftChild,data);
        }else {
            return hasData(root->rightChild,data);
        }
    }

    public:
    bool hasData(int data){
        return hasData(root,data);
    }

    private:
    void printTree(BinaryTreeNode<int>* root){
        queue<BinaryTreeNode<int>*> pendingNode;
        pendingNode.push(root);
        while(pendingNode.size()!=0){
            BinaryTreeNode<int>* Front = pendingNode.front();
            pendingNode.pop();
            cout<<Front->data<<" : ";

            if (Front->leftChild != NULL){
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
    
    public:
    void printTree(){
        printTree(root);
    }
};

int main(){
    BST *tree = new BST();
    tree->insert(40);
    tree->insert(20);
    tree->insert(10);
    tree->insert(30);
    tree->insert(50);
    tree->insert(60);
    tree->insert(70);

    tree->printTree();    
    cout<<endl;
    tree->deleteData(40);
    tree->printTree();    
    (tree->hasData(10)) ? cout<<"true\n" : cout<<"false\n";

    //   BST *tree = new BST();
    // int choice, input, q;
    // cin >> q;
    // while (q--) {
    //     cin >> choice;
    //     switch (choice) {
    //         case 1:
    //             cin >> input;
    //             tree->insert(input);
    //             break;
    //         case 2:
    //             cin >> input;
    //             tree->deleteData(input);
    //             break;
    //         case 3:
    //             cin >> input;
    //             cout << ((tree->hasData(input)) ? "true\n" : "false\n");
    //             break;
    //         default:
    //             tree->printTree();
        //         break;
        // }
    // }
}