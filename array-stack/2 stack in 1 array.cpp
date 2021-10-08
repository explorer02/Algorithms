#include <iostream>
#define SIZE 10
using namespace std;

int ar[SIZE];
int top1 = -1;
int top2 = SIZE;

void push_stack1 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[++top1] = data;
  }
  else
  {
    cout<<"Stack Full! Cannot Push\n";
  }
}
void push_stack2 (int data)
{
  if (top1 < top2 - 1)
  {
    ar[--top2] = data;
  }
  else
  {
    cout<<"Stack Full! Cannot Push\n";
  }
}

void pop_stack1 ()
{
  if (top1 >= 0)
  {
    int popped_value = ar[top1--];
    cout<<popped_value<<" is being popped from Stack 1\n";
  }
  else
  {
    printf ("Stack Empty! Cannot Pop\n");
  }
}
void pop_stack2 ()
{
  if (top2 < SIZE)
  {
    int popped_value = ar[top2++];
    cout<<popped_value<<" is being popped from Stack 2\n";
  }
  else
  {
    cout<<"Stack Empty! Cannot Pop\n";
  }
}

void print_stack1 ()
{
  int i;
  for (i = top1; i >= 0; --i)
  {
    cout<<ar[i]<<" ";
  }
  cout<<"\n";
}
void print_stack2 ()
{
  int i;
  for (i = top2; i < SIZE; ++i)
  {
    cout<<ar[i]<<" ";
  }
  cout<<"\n";
}

int main()
{
    int choice;

    cout<<"1. Insert value in Stack 1\n";
    cout<<"2. delete value in Stack 1\n";
    cout<<"3. Print stack 1\n";
    cout<<"4. Insert value in stack 2\n";
    cout<<"5. delete value in Stack 2\n";
    cout<<"6. Print stack 2\n";

    cout<<"Enter Choice  ";
    cin>>choice;
    while(choice>0&&choice<7)
    {
        switch(choice)
        {
        case 1:
            int x;
            cout<<"Enter value ";
            cin>>x;
            push_stack1(x);
            break;
        case 2:
            pop_stack1();
            break;
        case 3:
            print_stack1();
            break;
        case 4:
            cout<<"Enter value ";
            cin>>x;
            push_stack2(x);
            break;
        case 5:
            pop_stack2();
            break;
        case 6:
            print_stack2();
            break;
        }
    cout<<"Enter Choice  ";
    cin>>choice;
    }
}
