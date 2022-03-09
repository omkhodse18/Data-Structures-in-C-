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
    Node *temp = NULL;

    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            temp = newNode;
            temp->next = head;
            head = temp;
            // tail = tail->next;
            // head = newNode;
        }

        cin>>data;
    
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
    print(head);
    return 0;
}