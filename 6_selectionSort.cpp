#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[minIndex])
            minIndex = j;

        swap(arr[minIndex], arr[i]);
    }
}

int main(){
 int n;
 cout<<"Enter size : ";
 cin>>n;
 int arr[n];
 cout<<"Enter array : ";
 for(int i=0;i<n;i++){
  cin>>arr[i];
 }
 selectionSort(arr,n);
 cout<<"\nSorted array is : ";
 for(auto i:arr){
  cout<<i<<" ";
 }
 cout<<endl;
}
