#include <iostream>

using namespace std; 


int maxsize=5;
int queue[10];
int front = -1, rear = -1;


void insertQ();  
void deleteQ();  
void displayQ(); 


int main()  
{  
    int choice;   
    while(1)   
    {     
        
        cout<<"\n---------------------------------";
        cout<<"\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n";  
        cout<<"\nEnter your choice :";  
        cin>>choice;
        
        switch(choice)  
        {  
            case 1:  
            insertQ();  
            break;  
            case 2:  
            deleteQ();  
            break;  
            case 3:  
            displayQ();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            cout<<"\nEnter valid choice.\n";  
        }  
    }  
}
void insertQ(){
    cout<<"Enter the element to be inserted in queue: ";
    int n;
    cin>>n;
    if(rear==maxsize-1)
        cout<<"\nQueue is full";
    else{
        if(front==rear && front==-1){
            front=0;
            rear=0;
        }
        else{
            rear++;
        }    
        queue[rear]=n;
        cout<<"\n"<<n<<" is inserted in queue.";
    }
}

void deleteQ(){
    int n;
    if(front==-1 && rear==-1)
        cout<<"\nQueue is empty. Unable to perform deletion";
    else{
        cout<<"\n"<<queue[front]<<"is deleted from queue.";
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
    }
}

void displayQ(){
    if(front==-1&& rear==-1)
        cout<<"\nQueue is empty.";
    else{
        cout<<"\nQueue is:\nfront->";
        for(int i=front;i<=rear;i++)
            cout<<" "<<queue[i];
        cout<<" <-rear";
    }
}