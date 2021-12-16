#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n){
    int min_index;
    for(int i=0;i<n;i++){
        min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index])
                min_index=j;
        }
        cout<<endl<<"After iteration number"<<i<<":";
        cout<<endl<<"Swapping element: "<<arr[i];
        if(min_index!=i){
            int temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }   
        cout<<endl<<"Minumum element: "<<arr[i]<<endl<<"Array:";
        for(int k=0;k<n;k++)
            cout<<arr[k]<<" ";
        cout<<endl;
    }
    cout<<endl<<"Sorted Array using Selection Sort:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
int BinarySearch(int arr[], int key, int n){
    int left=0, right=n-1,count=0;
    if(key>arr[right] || key<arr[left]){
        return -1;
    }
    while(left<right){
        cout<<"\nIteration number: "<<count++<<"\nLeft="<<left<<"  Mid="<<((left+right)/2)<<"  Right="<<right;
        if(key==arr[left])
            return left;
        else if(key==arr[right])
            return right;
        else if(key==arr[(left+right)/2]){
            return (left+right)/2;
        }
        else if (key>arr[(right+left)/2])
            left=((right+left)/2)+1;
        else right=((right+left)/2);
    }
    return -1;
    }
int main(){
    int n;
    cout<<"Enter the length of array to be sorted:"<<endl;
    cin>>n;
    cout<<"Enter the elements of array to be sorted:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<endl<<"Entered Array:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    SelectionSort(arr,n);
    
    while(true){
        cout<<endl<<endl<<"Enter the elemnt to be searched: ";
        int element;
        cin>>element;
        int index;
        index=BinarySearch(arr,element,n);
        if (index!=-1)
            cout<<endl<<"Index of "<<element<<" is: "<<index;
        else
            cout<<endl<<"Element not found.";
    }
    return 0;
}