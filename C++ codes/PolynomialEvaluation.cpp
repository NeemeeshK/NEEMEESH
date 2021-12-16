#include <iostream>
#include<math.h>
using namespace std;

struct node{  
    int coef,exp;  
    struct node *next;  
    struct node *prev;
};  
struct node *head=NULL;

void create();
void display();
void evaluate();

int main()
{
    int choice;
    
    while(1)
    {
        cout<<"\n----------------------------------------";
        cout<<"\n1. Create \n2. Display \n3. Evaluate \n4. Exit";
        cout<<"\n Enter your choice:";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            create();
            break;
            
            case 2:
            display();
            break;
            
            case 3:
            evaluate();
            break;
            
            case 4:
            cout<<"\nExiting...";
            exit(0);
            
            default:
            cout<<"\n Enter appropriate choice";
        }
    
    }
}
void create(){
    struct node *p,*q;
    cout<<"\nEnter the polynominal terms in descending order of exponent:";
    while(1){
        p=(struct node *)malloc(sizeof(struct node));
        if(p==NULL)
            cout<<"\nMemory not available.";
        else{
            cout<<"\nEnter coefficient: ";
            cin>>p->coef;
            cout<<"\nEnter exponent: ";
            cin>>p->exp;
            p->next=NULL;
            p->prev=NULL;
        }
        if(head==NULL)
            head=p;
        else{
            q=head;
            while(q->next!=NULL)
                q=q->next;
            q->next=p;
            p->prev=q;
        }
        if(p->exp==0)
            break;
    }
}

void display(){
    struct node *p;
    if(head==NULL)
        cout<<"\nPolynomial is empty";
    else{
        cout<<"\nThe entered Polynomial is: \n";
        p=head;
        cout<<"P(x)= ";
        while(p!=NULL){
            cout<<p->coef<<" * x^"<<p->exp;
            if(p->exp!=0)
                cout<<"  +  ";
            p=p->next;
        }
    }
}

void evaluate(){
    int ans=0,x;
    struct node *p;
    cout<<"\nEnter the value of x for which polynomial will be evaluated: ";
    cin>>x;
    p=head;
    while(p!=NULL){
        ans+=p->coef*pow(x,p->exp);
        p=p->next;
    }
    cout<<"\nEvaluation of entered polynomial is: "<<ans;
}