#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cout<<"Enter size of the array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"\nEnter element to search : ";
    cin>>k;
    int mid,start=0,end=n-1;
    bool flag= false;
    while(start<=end){
     mid = (start+end)/2;
     if(a[mid]==k){
      flag= true;
      break;
     }
     else if(a[mid]>k){
      end= mid-1;
     }
     else{
      start=mid+1;
     }
    }
    if(!flag){
     cout<<"\nElement not present! \n";
    }
    else{
      cout<<"\nElement present at position "<<mid<<" .\n";
     }
    return 0;
}
