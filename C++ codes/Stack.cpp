#include<iostream>
using namespace std;
bool isfull(int top,int n){
    top++;
    if(top==4){
            cout<<"Stack is full. Unable to add "<<n<<" in Stack."<<endl<<endl;
            return true;
        }
    return false;
}
bool isempty(int top){
    if(top==-1){
            cout<<"Stack is empty. Unable to pop."<<endl<<endl;
            return true;
        }
    return false;
}
int push(int arr[],int top,int n){
    top++;
    arr[top]=n;
    cout<<n<<" is pushed in Stack at "<<top<<"."<<endl<<endl;
    return top;
}
int pop(int arr[],int top){
    cout<<arr[top]<<" is popped from the Stack."<<endl<<endl;
    arr[top]=0;
    top--;
    return top;
}
void display(int arr[],int top){
    for(int i=0;i<=top;i++){
        cout<<"["<<i<<"]   "<<arr[i]<<endl<<endl;
    }
}
int main(){
    int top=-1,choice,arr[4];
    while(1){
    cout<<"------------**Stack Program**------------"<<endl;
    cout<<"Choose from the following:\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n";
    cin>>choice;
    switch(choice)
        {
            case 1:
            cout<<"Enter the element to push in stack: ";
            int n;
            cin>>n;
            if(!isfull(top,n)){
                cout<<"\nPushing....\n";
                top=push(arr,top,n);
                }
            break;
            
            case 2:
            if(!isempty(top)){
                cout<<"\nPopping....\n";
                top=pop(arr,top);
            }
            break;
            
            case 3:
            if(top!=-1){
                cout<<"\nDisplaying....\n";
                display(arr,top);
            }
            else{
                cout<<"\nStack is empty. Unable to display.\n\n";
            }
            break;
            
            case 4:
            cout<<"\nExiting...";
            return 0;
            
            default:
            cout<<"\n Enter the appropriate choice."<<endl<<endl;
        }
    }
}