#include<iostream>
using namespace std;
int merge(int[],int,int,int);

void merge_sort(int a[],int first,int last)
{
    if(first>=last)
    {
        return;
    }

    int mid = first + (last-first)/2;
    merge_sort(a,first,mid);
    merge_sort(a,mid+1,last);
    merge(a, first, mid ,last);
}

int main()
{
    int a[100],x,i;

    cout<<"ENTER NUMBER OF ELEMENTS: ";
    cin>>x;

    for(i=0;i<x;i++)
    {
        cout<<"ELEMENT "<<i+1<<":";
        cin>>a[i];
    }

    cout<<"\nTHE INPUT ARRAY IS: "<<endl;
    for(i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }

    merge_sort(a,0,x-1);

    cout<<"\nSORTED ARRAY IN ASCENDING ORDER:"<<endl;
    for(i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }

}

int merge(int a[],int first,int mid,int last)
{
    int N1=mid-first+1;
    int N2=last-mid;
    int A[N1];
    int B[N2];

    for(int i=0;i<N1;i++)
    {
        A[i]=a[first+i];
    }

    for(int i=0;i<N2;i++)
    {
        B[i]=a[mid+1+i];
    }

    int i=0,j=0,k=first;
    while(i<N1&&j<N2)
    {
        if(A[i]<=B[j])
        {
            a[k++]=A[i++];
        }
        else
        {
            a[k++]=B[j++];
        }
    }

    if(i==N1)
    {
        for(;j<N2;)
        {
            a[k++]=B[j++];
        }
    }

    else if(j==N2)
    {
        for(;i<N1;)
        {
            a[k++]=A[i++];
        }
    }

}