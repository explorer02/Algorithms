//Write a program to insert and delete elements in Stack.

#include <iostream>
using namespace std;

class Stack {
    int *data;
    int top;
	int size;

    public:
    Stack(int size = 5) {
        data = new int[size];
        top = 0;
        this->size = size;
    }
    int pop();
    int top_();
    void push(int s);
    bool isEmpty();
    int getSize();

};
int Stack:: getSize() {
        return top;
    }
bool Stack:: isEmpty() {
        return top == 0;
    }
void Stack:: push(int element) {
        if(size == top) {
            cout << "Stack is full ! " << endl;
            return;
        }
        data[top] = element;
        top++;
    }

int Stack:: top_() {
        if(top == 0) {
            cout << "Stack is empty ! " << endl;
            return INT_MIN;
        }
        return data[top - 1];
    }
int Stack:: pop() {
        if(top == 0) {
            cout << "Stack is empty ! " << endl;
            return INT_MIN;
        }
        top--;
        return data[top];
    }

int main() {
    Stack s;
    int choice =0;
    cout<<"1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. IsEmpty?"<<endl;
    cout<<"4. Top"<<endl;
    cout<<"5. Size"<<endl;
    cout<<"Enter choice  ";
    cin>>choice;
    while(choice<=5)
    {
        int num;
        switch(choice)
        {
        case 1:
                cout<<"Enter element ";
                cin>>num;
                s.push(num);
                break;
        case 2:
            if(s.getSize())
                cout<<"Element Deleted "<<s.pop()<<endl;
            else s.pop();
                break;
        case 3:
                cout<<"Is Empty: ";
                (s.isEmpty())?cout<<"True"<<endl:cout<<"False"<<endl;
                break;
        case 4:
               cout<<"Top: "<<s.top_()<<endl;
                break;
        case 5:
               cout<<"Size: "<<s.getSize()<<endl;
                break;
        }
    cout<<"Enter choice  ";
    cin>>choice;
    }

}
