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
    int temp=0;
    int miss=0,hit=0;
    deque<int>::iterator itr;
    q.clear();

    //insert next page into the queue if not present in queue and inc miss
    for(int i=0;i<size;i++){
        itr = find(q.begin(),q.end(),arr[i]);//find whether new page is present in the queue and stores it in itr and if not found it stores q.end
        if(itr == q.end()){
            miss++;
            if(q.size() == capacity){      //checks whether frame in full or not
                q.erase(q.begin());         //deletes LRU page
                q.push_back(arr[i]);        //Push new page to MRU
            }
            else q.push_back(arr[i]);       //push new page to MRU
        }
        else{
            hit++;
            q.erase(itr);   //deletes found page
            q.push_back(arr[i]);		//push the same page to MRU
        }
        //For printing
        if(temp==0){
        cout<<"\tLRU";
        for(int i=0;i<capacity-1;i++) cout<<"\t";
        cout<<"MRU\n";
        temp=1;}
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
int main(){   
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