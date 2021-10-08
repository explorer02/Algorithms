//Write a program to calculate sum, difference, product and quotient of two rational numbers(p/q).
#include<iostream>
#include<algorithm>
using namespace std;
int lcm(int a,int b)
{
    return (a*b)/__gcd(a,b);
}
void simple(int num,int den)
{
    int n=__gcd(num,den);
    num/=n;
    den/=n;
    cout<<"("<<num<<"/"<<den<<")"<<endl;
}

void add(int n1,int d1,int n2,int d2)
{
  int den=lcm(d1,d2);
  int num=n1*den/d1+n2*den/d2;
  cout<<"Sum is: ";
  simple(num,den);
}
void sub(int n1,int d1,int n2,int d2)
{
  int den=lcm(d1,d2);
  int num=n1*den/d1-n2*den/d2;
  cout<<"Difference is: ";
  simple(num,den);
}
void mul(int n1,int d1,int n2,int d2)
{
  int den=d1*d2;
  int num=n1*n2;
  cout<<"Product is: ";
  simple(num,den);

}
void div(int n1,int d1,int n2,int d2)
{
  int den=d1*n2;
  int num=n1*d2;
  cout<<"Quotient is: ";
  simple(num,den);
}

int main()
{
      int n1,d1,n2,d2;
      cout<<"Enter first Number ";
      cin>>n1>>d1;
      cout<<"Enter second Number ";
      cin>>n2>>d2;
      add(n1,d1,n2,d2);
      sub(n1,d1,n2,d2);
      mul(n1,d1,n2,d2);
      div(n1,d1,n2,d2);
}
