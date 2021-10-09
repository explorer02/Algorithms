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

Node* insertNode(Node*head,int data) {

  Node*temp=new Node(data);
  Node*n=head,*p=NULL;

  if(head==NULL){
    return temp;
  }
  if(head->data>data){
    temp->next=head;
    head=temp;
    return head;
  }
  while(n!=NULL&&n->data<data){
    p=n;
    n=n->next;
  }
  if(n==NULL){
    p->next=temp;
    return head;
  }
  p->next=temp;
  temp->next=n;

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
            cout<<"Enter data ";
            cin>>data;
            head=insertNode(head,data);
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
