/*
Practical No: 7
Title: In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.

Started On: 23rd August 2019
Completed On: 23rd August 2019

Batch: A
Roll No.: 9

*/

#include<iostream>
#include<cstring>
using namespace std;

char stk[10];
int size = 8;
int top = -1;

int stk_empty()
{
   if(top == -1)
      return 1;
   else 
      return 0;
}

int stk_full()
{
   if(top == size-1)
      return 1;
   else
      return 0;
}

void push(char ch)
{
    top++;
    stk[top] = ch;
}

char pop()
{
   char x = stk[top];
   top--;
   return x;   
}

void display()
{
   for(int i=0; i<top; i++)
      cout<<" "<<stk[i];
}

void check_para()
{
   char expr[10],ch;
   int i;
   cout<<"\nEnter the expression: ";
   cin>>expr;
   
   for(i=0; expr[i]!='\0' ;i++)
   {
      if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{')
      {
         if(!stk_full())
           push(expr[i]);
         else
            cout<<"\nCan't push the character since the stack is full...!!!";         
      }
      else
      {
         ch = pop();
         if(expr[i]==')' && ch!='(') 
         {
            cout<<"\nExpression is not well parenthesized ";
            push(ch);
            break;
         } 
         if(expr[i]=='}' && ch!='{') 
         {
            cout<<"\nExpression is not well parenthesized ";
            push(ch);
            break;
         } 
         if(expr[i]==']' && ch!='[') 
         {
            cout<<"\nExpression is not well parenthesized ";
            push(ch);
            break;
         }    
      }
   }
   
   if(!stk_empty())
   cout<<"\nExpression is not well parenthesized..!!!";
   else
   cout<<"\nExpression is well parenthesized..!!!";
}

int main()
{
   cout<<"\nChecking expression is well parenthesized or not...";
   check_para();
   cout<<"\n\n";
   return 0;
}

/*
student@ubuntu:~$ g++ Pr7_stack.cpp -o a
student@ubuntu:~$ ./a


Checking expression is well parenthesized or not...
Enter the expression: {]

Expression is not well parenthesized 
Expression is not well parenthesized..!!!


student@ubuntu:~$ ./a

Checking expression is well parenthesized or not...
Enter the expression: {}

Expression is well parenthesized..!!!

student@ubuntu:~$ ./a

Checking expression is well parenthesized or not...
Enter the expression: {[()]}

Expression is well parenthesized..!!!

student@ubuntu:~$ ./a

Checking expression is well parenthesized or not...
Enter the expression: {[()]

Expression is not well parenthesized..!!!

student@ubuntu:~$ ./a

Checking expression is well parenthesized or not...
Enter the expression: {[] 

Expression is not well parenthesized..!!!

student@ubuntu:~$ ./a

Checking expression is well parenthesized or not...
Enter the expression: {[}]

Expression is not well parenthesized 
Expression is not well parenthesized..!!!

*/
