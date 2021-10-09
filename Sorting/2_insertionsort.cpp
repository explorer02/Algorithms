#include<iostream>
using namespace std;
int insertion(int[],int);

int main()
{
    int a[100],n,i;
    cout<<"ENTER NUMBER OF ITEMS: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
        cout<<"ENTER ITEM "<<i+1<<":";
        cin>>a[i];
    }

    insertion(a,n);

    cout<<"SORTED DATA"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}    

int insertion(int A[],int N)
{
    int i,j,temp;
    for(i=1;i<N;i++)
    {
        temp=A[i];
        j=i-1;

        while((temp<A[j])&&(j>=0))
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=temp;
    }
}