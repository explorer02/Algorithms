#include<bits/stdc++.h>
using namespace std;

void insheap(int a[],int n,int item)
{
    a[n]=item;
    int child=n;
    int parent=(child-1)/2;
    while(parent>0&&a[parent]<a[child])
    {
        int temp=a[parent];
        a[parent]=a[child];
        a[child]=temp;
        child=parent;
        parent=(child-1)/2;
    }
    if(parent==0&&a[parent]<a[child])
    {
        int temp=a[parent];
        a[parent]=a[child];
        a[child]=temp;

    }

}
void delheap(int a[],int n)
{
    int temp=a[0];
    a[0]=a[n];
    a[n]=temp;
    n--;
    int par=0;
    int l=2*par+1;
    int r=l+1;
    while(l<n&&r<n)
    {
        int i=par;
        if(a[l]>=a[r]&&a[l]>=a[par])
            i=l;
        if(a[r]>=a[l]&&a[r]>=a[par])
            i=r;
        if(i==par)
            return;
        int temp=a[i];
        a[i]=a[par];
        a[par]=temp;
        par=i;
        l=2*par+1;
        r=l+1;
    }

}
void printheap(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        insheap(a,i,a[i]);
    for(int i=n-1;i>=0;i--)
        delheap(a,i);
    printheap(a,n);
}

// 21 12 15 3 42 52 66 21 52 63 14 25 12 10 11 1 2 2 2 5 7 8
