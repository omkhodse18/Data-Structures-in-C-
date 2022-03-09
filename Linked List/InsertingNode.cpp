#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node *takeInput(){
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }

        cin>>data;
    
    }

    return head;

}

Node* insertNode(Node *head,int data,int pos){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    if(temp != NULL){
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }

    return head;

}

void print(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){  
    Node *head = takeInput();
    int data,pos;

    cout<<"Enter the number : ";
    cin>>data;
    cout<<"Enter the position at which element to be insert : ";
    cin>>pos;

    cout<<"\nLinked list before insertion....\n";
    print(head);

    head = insertNode(head,data,pos);
    cout<<"Linked list after insertion...\n";
    print(head);
    return 0;
}