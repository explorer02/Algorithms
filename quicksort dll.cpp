#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node*prev;
    Node(int data){
        this -> data = data;
        this->next=NULL;
        this->prev=NULL;
    }
};

Node* push(Node* head, int data)
{

    Node* new_node = new Node(data);
   new_node->next =head;
    new_node->prev = NULL;

  if (head!= NULL)
        head->prev = new_node;
  head = new_node;
  return head;
}

void print(Node *head)
{
    cout<<"List: ";
    for(auto t=head;t!=NULL;t=t->next)
        cout<<t->data<<" ";
    cout<<endl;
}

Node*partition(Node*start,Node*end)
{
    Node* t=start;
    int count=0;
    int x=end->data;
    for(auto p=start;p!=end;p=p->next)
    {
        if(p->data<x)
        {
            int temp=p->data;
            p->data=t->data;
            t->data=temp;
            t=t->next;
        }
    }

    int temp=end->data;
    end->data=t->data;
    t->data=temp;
    return t;
}


void quickSort(Node*start,Node*end)
{
    if(start==end)
        return;

    Node*p=partition(start,end);
    if(p!=start&&p->prev!=start)
        quickSort(start,p->prev);
    if(p!=end&&p->next!=end)
        quickSort(p->next,end);

}
void quickSort(Node*head)
{
    auto p=head;
    while(p->next!=NULL)
        p=p->next;
    quickSort(head,p);
}
int main()
{

    Node*head=NULL;
    head=push(head,1);
    head=push(head,4);
    head=push(head,3);
    head=push(head,7);
    head=push(head,9);
    head=push(head,8);
    head=push(head,11);


    cout << "Linked List before sorting \n";
    print(head);

    quickSort(head);

    cout << "Linked List after sorting \n";
    print(head);

    return 0;
}
