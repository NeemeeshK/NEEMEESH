#include <iostream>
using namespace std;
#include<stdlib.h>
struct node{  
    int data;  
    struct node *next;   
};  
struct node *head=NULL;
void push ();   
void pop ();  
void display();
int main(){
    int choice;
    while(1)
    {
        cout<<"\n----------------------------------------";
        cout<<"\n1. Push\n2. Pop \n3. Diaplay Stack \n4. Exit";
        cout<<"\n Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            push();
            break;
            
            case 2:
            pop();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            cout<<"\nExiting...";
            return 0;
            
            default:
            cout<<"\n Enter appropriate choice";
        }
    }
}
void push(){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node*));
    if(p==NULL){
        cout<<"Memory not available.";
    }
    else{
        cout<<"Enter the element to push in stack: ";
        cin>>p->data;
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
void pop(){
    struct node *p;
    if(head==NULL){
        cout<<"\nStack is empty.";
    }
    else{
        cout<<"\n"<<head->data<<" is popped.";
        p=head;
        head=head->next;
        free(p);
    }
}
void display(){
    struct node *p;
    p=head;
    if(p==NULL)
        cout<<"Stack is empty.\n";
    else{
        cout<<"\n             ****STACK****\nNode Address\tNode Data\tNext Address\n";
        while(p!=NULL){
            cout<<p<<"\t"<<p->data<<"\t\t"<<p->next<<endl;
            p=p->next;
        }
    }
}