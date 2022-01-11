#include <iostream>
#include<deque>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void showdq(deque <int> g){
    deque <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it) cout << '\t' << *it;
    cout << '\n';
}
void HitMissCalculate(int capacity,int size,int arr[]){
    deque<int> q(capacity);
    int count=0;
    int miss=0,hit=0;
    deque<int>::iterator itr;
    q.clear();
    for(int i=0;i<size;i++){
        itr = find(q.begin(),q.end(),arr[i]);
        if(!(itr != q.end())){
            miss++;
            if(q.size() == capacity){
                q.erase(q.begin());
                q.push_back(arr[i]);
            }
            else q.push_back(arr[i]);
        }
        else{
            hit++;
            q.erase(itr);
            q.push_back(arr[i]);		
        }
        showdq(q);
    }
    cout<<"\nFor frame size "<<capacity<<" and having pages ";
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<"\nNo. of page faults(miss): "<<miss;
    cout<<"\nNo. of page hits are: "<<hit;
    float hratio=hit*100/(hit+miss), mratio=miss*100/(hit+miss);
    cout<<"\nHit %: "<<hratio;
    cout<<"\nMiss %: "<<mratio;
}
int main()
{   
    int choice;
    cout<<"********Least Reacently Used Implementation********";
        int capacity,size;
        cout<<"\nEnter Frame size: ";
        cin>>capacity;
        cout<<"\nEnter no. of pages: ";
        cin>>size;
        cout<<"\nEnter the pages seperated by spaces:\n";
        int arr[size];
        for(int i=0;i<size;i++) cin>>arr[i];
        HitMissCalculate(capacity,size,arr);
    while(1){
        cout<<"\n1. Find hit/miss for the same pages with different framesize.\n2. Apply LRU for all different inputs.\n3. Exit.\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\nEnter Frame size: ";
                cin>>capacity;
                HitMissCalculate(capacity,size,arr);
                break;
            case 2:
                system("cls");
                cout<<"********Least Reacently Used Implementation********";
                cout<<"\nEnter Frame size: ";
                cin>>capacity;
                cout<<"\nEnter no. of pages: ";
                cin>>size;\
                cout<<"\nEnter the pages seperated by spaces:\n";
                for(int i=0;i<size;i++) cin>>arr[i];
                HitMissCalculate(capacity,size,arr);
                break;
            case 3:
                cout<<"Exiting.....";
                return 0;
            default:
            cout<<"Enter the valid choice."<<endl;
            break;
        }
    }
}