#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

// void printIthNode(Node *head, int i)
// {
//     //Write your code here
//     Node *temp = head;
//     int count = 0;

//     while(temp != NULL){
//         temp = temp ->next;
//         count++;
//     }
    
//     cout<<temp->data;
      
// }

void printIthNode(Node *head, int i) {
  
    Node* temp = head;
    int count =0;
    while(temp)
    {
        if(i==count)
        {
            cout<< temp->data<<endl;
            return;
        }
        
        count++;
        temp=temp->next;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
	return 0;
}