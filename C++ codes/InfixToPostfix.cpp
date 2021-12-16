#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
char stack[50];
int top=-1;
void push(char element){
    stack[++top]=element;
}
char pop(){
    return(stack[top--]);
}
int priority(char operators){
    if (operators=='^')
        return 3;
    if (operators=='*'||operators=='/')
        return 2;
    if (operators=='+'||operators=='-')
        return 1;
    return 0; 
}
int main(){
    char infix[50],postfix[50],ch,temp;
    int i=0,k=0;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    infix[strlen(infix)]='\0';
    cout<<"\nEntered expression: "<<infix;
    push('#');
    ch=infix[i];
    while(ch!='\0'){
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))
            postfix[k++]=ch;
        else if(ch==')'){
            while(stack[top]!='(')
                postfix[k++]=pop();
            temp=pop();
        }
        else{
            while(priority(stack[top])>=priority(ch))
                postfix[k++]=pop();
            push(ch);
        }
        ch=infix[++i];
    }
    while(stack[top]!='#')
        postfix[k++]=pop();
    postfix[k]='\0';
    cout<<"\nPostfix expression is: "<<postfix;
    return 0;
}