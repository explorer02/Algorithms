#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;         // take input from user the size of array
    cout<<"Enter the size of Array : "<<endl;
    cin>>n;

    int *arr = new int(n);
    
    cout << "Enter " << n << " items" << endl;
	
    for (int x = 0; x < n; x++) {
		cin >> arr[x];
	}
    
    int ele;
    cout<<"Enter the element you wanna search: ";
    cin>>ele;

    //linear search algo
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            flag=true;
            cout<<"The element "<<ele<<" is at index : "<<i<<endl;
            break;
        }
    }
    if(!flag){
        cout<<"The entered element is not in the array"<<endl;
    }


    return 0;
}
