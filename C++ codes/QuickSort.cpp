#include<iostream>
using namespace std;
int partition(int arr[],int low,int high){
    int i=low-1,j=low,pivot=arr[high],temp;
    for (j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i+1);
}
void quicksort(int arr[], int low, int high){
    int pi=high,count=1;
    if(high>low){
        cout<<"\nPivot Index before pass no. "<<count<<" is: "<<pi;
        cout<<"\nArray before pass no. "<<count<<" is: " ;
        for(int i=0;i<high;i++)
            cout<<arr[i]<<" ";
        pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
        count++;
    }
}
int main(){
    int n;
    cout<<"Enter no. of element in Array: ";
    cin>>n;
    cout<<endl<<"Enter elements of the Array: ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int low=0,high=n-1,x;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    // x=partition(arr,low,high);
    // cout<<"\nPosition of Pivot: "<<x<<endl;
    quicksort(arr,low,high);
    cout<<"\nSorted Array: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        return 0;
}