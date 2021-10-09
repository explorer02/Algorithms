//using last element as pivot
#include<iostream>
using namespace std;

void swap(int *a,int*b)
{
    int temp;
    temp=*a;
    *a = *b;
    *b = temp;
}
int partition(int arr[100],int low,int high)
{
    int pivot = arr[high];
    int i = low -1;
    cout<<"Pivot:"<<pivot<<"\n";
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}
void quicksort(int arr[100],int low,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main()
{
    int n;
    cout<<"ENTER NUMBER OF ELEMENTS: ";
    cin>>n;

    int arr[n];
    cout<<"ENTER ARRAY: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    quicksort(arr,0,n-1);

    cout<<"SORTED ARRAY: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}