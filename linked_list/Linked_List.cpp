// Write a program to insert, delete and print elements in Linked List.

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this->next=NULL;
    }
};

Node* insertNode(Node*head,int data,int pos=1) {

  Node*temp=new Node(data);
  Node*t=head;
  if(pos==1||head==NULL)
  {
      temp->next=head;
      head=temp;
      return head;
  }
  for(int i=0;t!=NULL&&i<pos-2;i++)
      t=t->next;
  if(t!=NULL)
  {
      temp->next=t->next;
      t->next=temp;
  }
  return head;
}

Node* deleteNode(Node*head,int pos) {

  auto p=head;
  for(int i=0;p!=NULL&&i<pos-2;i++)
    p=p->next;
  if(p!=NULL)
  {
      auto t=p->next;
      p->next=t->next;
      delete t;
      return head;
  }
}

void print(Node *head)
{
    cout<<"List: ";
    for(auto t=head;t!=NULL;t=t->next)
        cout<<t->data<<" ";
    cout<<endl;
}

int main()
{
    Node*head=NULL;

    cout<<"1. Insert a node"<<endl;
    cout<<"2. Delete a node"<<endl;
    cout<<"3. Print list"<<endl;
    int choice=0;
    cout<<"Enter Choice ";
    cin>>choice;
    int data,pos;
    while(choice<4&&choice>0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter data and position ";
            cin>>data>>pos;
            head=insertNode(head,data,pos);
            break;
        case 2:
            cout<<"Enter position ";
            cin>>pos;
            head=deleteNode(head,pos);
            break;
        case 3:
               print(head);
        }
    cout<<"Enter Choice ";
    cin>>choice;
    }
}
