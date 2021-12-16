#include <iostream>
using namespace std;

struct node   
{  
    struct node *prev;  
    int coeff;  
    int power;
    struct node *next;  
}; 

struct node *head1=NULL,*head2=NULL; 

struct node *create(struct node *head,int);
struct node *insert_node(struct node *head, int coeff, int power);
void display(struct node *);
void addition(struct node *, struct node *);

int main()
{
    int n;
    
    cout<<"\n Enter number of terms in first polynomial: ";
    cin>>n;
    head1 = create(head1,n);
    
    
    cout<<"\n Enter number of terms in second polynomial: ";
    cin>>n;
    head2 = create(head2,n);
    
    cout<<"\n\nThe first polynomial .....\n";
    display(head1);
    cout<<"\n\nThe second polynomial .....\n";
    display(head2);
    
    addition(head1,head2);
    
}

struct node *create(struct node *head, int n)
{
    int i,coeff,power;
    cout<<"\n Enter polynomial terms in descending order of power.";
    for(i=0;i<n;i++)
    {
        cout<<"\n Enter Coefficient:";
        cin>>coeff;
        cout<<"\n Enter power:";
        cin>>power;
        head= insert_node(head,coeff,power);
    }
    return head;
}

struct node *insert_node(struct node* head, int coeff, int power)    // inserts the node at the end of poly
{
    struct node *ptr, *temp;
    
    ptr=(struct node*)malloc(sizeof(struct node));
        // aalocate memory for new node
    if(ptr==NULL)
    {
        cout<<"\n Memory is not allocated.";
    }

    else
    {
        ptr->coeff=coeff;     // enter data fields
        ptr->power=power;
        ptr->next=NULL;       // init aadresss  fields
        ptr->prev=NULL;
            
        if(head==NULL)    // empty DLL 
            head=ptr;    // new node will become first/head node of DLL
        else
        {                  // add the node at the end
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
                
            temp->next=ptr;
            ptr->prev=temp;
        }
    }
    return head;   
}

void display(struct node *head)
{
    struct node *temp;
    
    if(head==NULL)
    {
        cout<<"\n The polynomial is empty.";
    }

    else
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->coeff<<"*X^"<<temp->power;
            if(temp->next!=NULL)
            cout<<"  +  ";
            temp=temp->next;
        }
    }
}

void addition(struct node *head1, struct node *head2)
{
    struct node *head3, *ptr1, *ptr2;

    ptr1=head1;
    ptr2=head2;
    head3=NULL;

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if (ptr1->power==ptr2->power)
        {
            head3=insert_node(head3, ptr1->coeff+ptr2->coeff, ptr1->power);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        else
            if(ptr1->power > ptr2->power)
            {
                head3=insert_node(head3, ptr1->coeff+ptr2->coeff, ptr1->power);
                ptr1=ptr1->next;
            }

            else
            {
                if(ptr1->power < ptr2->power)
                {
                    head3=insert_node(head3, ptr2   ->coeff, ptr2->power);
                    ptr2=ptr2->next;
                }
            }
    }

    while(ptr1!=NULL)
    {
        head3=insert_node(head3, ptr1->coeff, ptr1->power);
        ptr1=ptr1->next;
    }

    while(ptr2!=NULL)
    {
        head3=insert_node(head3, ptr2->coeff, ptr2->power);
        ptr2=ptr2->next;
    }

    cout << "\n\nThe addition of two polynomials is: \n";
    display(head3);  
}