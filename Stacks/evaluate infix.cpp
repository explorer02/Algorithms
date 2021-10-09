#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool pres(char c1,char c2)
{
    if(c1=='^')
        return true;
    if((c1=='/'||c1=='*') && c2!='^')
      return true;
    if((c1=='+'||c1=='-') && (c2=='+'||c2=='-'))
      return true;
    return false;

}
bool isnum(char c)
{
    return c>='0'&&c<='9';
}
bool isoper(char c)
{
    return c=='^'||c=='/'||c=='*'||c=='+'||c=='-';
}
int applyop(int x,int y,char c)
{
    if(c=='^')
        return pow(x,y);
    if(c=='/')
        return x/y;
    if(c=='*')
        return x*y;
    if(c=='+')
        return x+y;
    if(c=='-')
        return x-y;

}

void evaluate(string s)
{
    stack<int>val;
    stack<char>oper;
    for(int i=0;i<s.size();)
    {
        if(isnum(s[i]))
        {
            int x=0;
            while(isnum(s[i]))
            {
                x*=10;
                x+=s[i]-'0';
                i++;
            }
            val.push(x);
            continue;
        }
        else if(s[i]=='(')
                oper.push(s[i]);
        else if(s[i]==')')
        {
            while(oper.top()!='(')
            {
                int y=val.top();
                val.pop();
                int x=val.top();
                val.pop();
                char c=oper.top();
                oper.pop();
                int z=applyop(x,y,c);
                val.push(z);
            }
            oper.pop();
        }
        else if(isoper(s[i]))
        {
            if(oper.empty())
                oper.push(s[i]);
            else
            {while(!oper.empty()&&pres(oper.top(),s[i]))
            {
                int y=val.top();
                val.pop();
                int x=val.top();
                val.pop();
                char c=oper.top();
                oper.pop();
                val.push(applyop(x,y,c));
            }
            oper.push(s[i]);}
        }
        i++;
    }

    while(!oper.empty())
    {
        int y=val.top();
        val.pop();
        int x=val.top();
        val.pop();
        char c=oper.top();
        oper.pop();
        val.push(applyop(x,y,c));
    }
    cout<<val.top();
}

int main()
{
    string s;
    cout<<"Enter infix expression:  ";
    getline(cin,s);
    evaluate(s);
}
