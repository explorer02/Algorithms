#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

int deQueue()
    {

        if (s1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }

void display(){
     stack<int> temp = s1;
     while(!temp.empty()){
      cout<<temp.top()<<" ";
      temp.pop();
     }
     cout<<endl;
    }
};

int main()
{
    Queue q;
            int f=1,a;
            while(f<=3&&f>=1){

            cout<<"1) Push  2)Pop  3)Display\n";
            cin>>f;
            switch(f) {
            case 1 : cout<<"Enter the element to be added to queue\n";
                    cin>>a;
                     q.enQueue(a);

                     break;

            case 2 : q.deQueue();

                     break;

            case 3 : q.display();

                     break;

        }
        }
    return 0;
}

