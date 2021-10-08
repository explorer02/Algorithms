#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* a,int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
 insertionSort(arr,n);
 cout<<"\nSorted array is : ";
 for(auto i:arr){
  cout<<i<<" ";
 }
 cout<<endl;
}
