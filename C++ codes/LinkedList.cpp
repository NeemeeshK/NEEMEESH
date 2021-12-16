#include <iostream>

using namespace std;

struct node{  
    int data;  
    struct node *next;   
};  
struct node *head=NULL;    
  
void beginInsert ();   
void lastInsert ();  
void randomInsert();  
void display();  
void beginDelete();
void lastDelete();
void SearchnModify();

int main()
{
    int choice, n;
    
    while(1)
    {
        
        cout<<"\n-------------------------";
        cout<<"\n1. Insert at Beginning\n2. Insert at Last \n3. Insert at Random Place \n4. Display \n5. Begin Delete \n6. Last Delete \n7. Search and Modify \n8. Exit\n";
        cout<<"\n Enter your choice:";
        cin>>choice;
        
        switch(choice)
        {
            case 1:  
            beginInsert();      
            break;  
            case 2:  
            lastInsert();         
            break;  
            case 3:  
            randomInsert();       
            break;  
            case 4:  
            display();       
            break; 
            case 5:  
            beginDelete();       
            break; 
            case 6:  
            lastDelete();       
            break; 
            case 7:  
            SearchnModify();       
            break;  
            case 8:  
            exit(0);        
            break; 
            default:  
            cout<<"Enter appropriate choice.";
        }
    }
}

void beginInsert ()
{
    int data;
    struct  node *p;
    p=(struct node*)malloc(sizeof(struct node *));
    cout<<"\n-------------------------";
    cout<<"\nInsert at beginning"<<endl;
    if(p==NULL)
    cout<<"Memory not available...."<<endl;
    else{
        cout<<"Enter the element to be inserted at beginning: "<<endl;
        cin>>data;
        p->data=data;
        p->next=NULL;
        if(head==NULL){
            head=p;
        }
        else{
            p->next=head;
            head=p;
        }
    }
}
void lastInsert ()
{
    int data;
    struct  node *p,*temp;
    p=(struct node*)malloc(sizeof(struct node *));
    cout<<"\n-------------------------";
    cout<<"\nInsert at last\n";
    if(p==NULL)
    cout<<"Memory not available...."<<endl;
    else{
        cout<<"Enter the element to be inserted at last: "<<endl;
        cin>>data;
        p->data=data;
        p->next=NULL;
        if(head==NULL){
            head=p;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=p;
        }
    }
}
void randomInsert()
{
    struct node *p,*q;
    p=head;
    int length=0;
    while(p!=NULL){
        p=p->next;
        length++;
    }
    q=(struct node*)malloc(sizeof(struct node *));
    cout<<"\n-------------------------";
    cout<<"\nInsert at random\n Enter the index at which node is to be inserted:";
    int ind;
    cin>>ind;
    if(ind>length)
        cout<<"\nLL does not have index no. "<<ind<<".";
    else{
        p=head;
        cout<<"Enter the element to be inserted at index no. "<<ind<<" :";
        cin>>q->data;
        q->next=NULL;
        if(p==NULL){
            head=q;
        }
        else if(ind==0){
            q->next=p;
            head=q;
        }
        else{
            while((ind-1)!=0){
                p=p->next;
                ind--;
            }
            q->next=p->next;
            p->next=q;
        }
        cout<<"Element inserted succesfully.\n";
    }
}
void display()
{
    cout<<"\n-------------------------";
    cout<<"\nDisplay\n";
    struct node *p;
    p=head;
    if(p==NULL)
    cout<<"LL is empty.\n";
    else{
        cout<<"\nNode Address\tNode Data\tNext Address\n";
        while(p!=NULL){
            cout<<p<<"\t"<<p->data<<"\t\t"<<p->next<<endl;
            p=p->next;
        }
    }
}

void beginDelete(){
    struct node *p;
    cout<<"\n-------------------------";
    cout<<"\nBegin Delete\n";
    if(head==NULL)
        cout<<"\nLL is Empty"<<endl;
    else{
        p=head;
        head=head->next;
        free(p);
        cout<<"\nThe first node is deleted.\n";
    }
}

void lastDelete(){
    cout<<"\n-------------------------";
    cout<<"\nLast Delete\n";
    struct node *p;
    p=head;
    while(p->next->next!=NULL)
        p=p->next;
    p->next=NULL;
    free(p->next);
    cout<<"\nThe last node is deleted.\n";
}

void SearchnModify(){
    cout<<"\n-------------------------";
    cout<<"\nSearch and Modify\n";
    cout<<"Enter the data to be searched and modified: ";
    int data,newdata;
    cin>>data;
    cout<<"Enter the new data: ";
    cin>>newdata;
    struct node *p;
    p=head;
    if(p==NULL)
        cout<<"\nLL is Empty.";
    else{
        while(p->data!=data)
            p=p->next;
        p->data=newdata;
    }
}