#include <iostream>
#include<math.h>
using namespace std;
struct node{
    int coef,exp;  
    struct node *next;  
    struct node *prev;
};  
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
void create();
void display();
void sum();
int main(){
    int choice;
    while(1)
    {
        cout<<"\n----------------------------------------";
        cout<<"\n1. Create \n2. Display \n3. Sum \n4. Exit";
        cout<<"\n Enter your choice:";
        cin>>choice;
        switch(choice)        {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            sum();
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
    cout<<"\nEnter the Polynominal1 terms in descending order of exponent:";
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
        if(head1==NULL)
            head1=p;
        else{
            q=head1;
            while(q->next!=NULL)
                q=q->next;
            q->next=p;
            p->prev=q;
        }
        if(p->exp==0)
            break;
    }
    struct node *r,*s;
    cout<<"\nEnter the Polynominal2 terms in descending order of exponent:";
    while(1){
        r=(struct node *)malloc(sizeof(struct node));
        if(r==NULL)
            cout<<"\nMemory not available.";
        else{
            cout<<"\nEnter coefficient: ";
            cin>>r->coef;
            cout<<"\nEnter exponent: ";
            cin>>r->exp;
            r->next=NULL;
            r->prev=NULL;
        }
        if(head2==NULL)
            head2=r;
        else{
            s=head2;
            while(s->next!=NULL)
                s=s->next;
            s->next=r;
            r->prev=s;
        }
        if(r->exp==0)
            break;
    }
}
void display(){
    struct node *p;
    if(head1==NULL)
        cout<<"\nPolynomial1 is empty";
    else{
        cout<<"\nThe entered Polynomial is: \n";
        p=head1;
        cout<<"P(x)= ";
        while(p!=NULL){
            cout<<p->coef<<" * x^"<<p->exp;
            if(p->exp!=0)
                cout<<"  +  ";
            p=p->next;
        }
    }
    struct node *q;
    if(head2==NULL)
        cout<<"\nPolynomial2 is empty";
    else{
        cout<<"\nThe entered Polynomial2 is: \n";
        q=head2;
        cout<<"Q(x)= ";
        while(q!=NULL){
            cout<<q->coef<<" * x^"<<q->exp;
            if(q->exp!=0)
                cout<<"  +  ";
            q=q->next;
        }
    }
}
void sum(){
    struct node *p=head1,*q=head2,*s=head3,*t;
    while(p!=NULL && q!=NULL){
        struct node *r;
        r=(struct node *)malloc(sizeof(struct node));
        if(r==NULL){
            cout<<"\nMemory not available.";
        }
        r->prev=NULL;
        r->next=NULL;
        if(p->exp==q->exp){
            r->exp=p->exp;
            r->coef=p->coef+q->coef;
            p=p->next;
            q=q->next;
            if(head3==NULL){
                head3=r;
                s=head3;
            }
            else{
                s->next=r;
                r->prev=s;
                r->next=NULL;
                s=s->next;
            }
        }
        else if((p->exp)>(q->exp)){
            r->exp=p->exp;
            r->coef=p->coef;
            p=p->next;
            if(head3==NULL){
                head3=r;
                s=head3;
            }
            else{
                s->next=r;
                r->prev=s;
                r->next=NULL;
                s=s->next;
            }
        }
        else if((p->exp)<(q->exp)){
            r->exp=q->exp;
            r->coef=q->coef;
            q=q->next;
            if(head3==NULL){
                head3=r;
                s=head3;
                
            }
            else{
                s->next=r;
                r->prev=s;
                r->next=NULL;
                s=s->next;
            }
        }
    }
    if(head3==NULL)
        cout<<"\nPolynomial is empty";
    else if(head3!=NULL){
        cout<<"\nThe Sum of entered Polynomials is: \n";
        t=head3;
        cout<<"P(x)+Q(x)= ";
        while(t!=NULL){
            cout<<t->coef<<" * x^"<<t->exp;
            if(t->exp!=0)
                cout<<"  +  ";
            t=t->next;
        }
    }
}