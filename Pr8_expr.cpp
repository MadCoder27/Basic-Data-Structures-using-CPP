/*
Practical No: 8
Title: Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions
     i. Operands and operator, both must be single character.
    ii. Input Postfix expression must be in a desired format.
   iii. Only '+', '-', '*' and '/ ' operators are expected.

Started On: 27th August 2019
Completed On: 30th August 2019

Batch: A
Roll No.: 9
*/

#include<iostream>
using namespace std;

//....................................for Char Stack

char stk[25];
int size = 25;
int top = -1;

char postfix[25];

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

//..............................................................

void Infix_to_Postfix()
{
   char infix[25],ch;
   int i;
   int j=0;
   cout<<"\n\nEnter the infix expression: ";
   cin>>infix;
   
   for(i=0; infix[i]!='\0' ;i++)
   {
      if(infix[i]=='(' || infix[i]=='{' || infix[i]=='[')
         {
            if(!stk_full())
               push(infix[i]);
            else
               cout<<"\nThe stack is full...!!!";
         }
           
      else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
         {
            if(!stk_full())
               push(infix[i]);
            else
               cout<<"\nThe stack is full...!!!";
         }
      
      else if(infix[i]==')' || infix[i]==']' || infix[i]=='}')
         {
            while(stk[top]!='(' && stk[top]!='[' && stk[top]!='{')
            {
               ch = pop();
               postfix[j] = ch;
               j++;
            }
            ch = pop();
         }
         
      else
         {
            postfix[j] = infix[i];
            j++;   
         }         
   }
   
   while(!stk_empty())
   {
      postfix[j] = pop();
      j++;   
   }
   cout<<"\nThe postfix expression is :  "<<postfix;
}

//----------------------------------------------------------
//....................................for Int Stack
int stk1[10];
int size1 = 10;
int top1 = -1;


int stk1_empty()
{
    if(top1 == -1)
       return 1;
    else
       return 0;
}
     
int stk1_full()
{
    if(top1 == size1-1)
       return 1;
    else
       return 0;
}

void push1(int No)
{
    top1++;
    stk1[top1] = No;
}
      
int pop1()
{
    int No = stk1[top1];
    top1--;
    return No;
}  

void Postfix_Evaluation()
{
     int i,op1,op2;
     
     char ch;
     
     for(i=0; postfix[i]!='\0'; i++)
     {
        ch=postfix[i];
        
        if(ch =='+'|| ch =='-'|| ch =='*'|| ch =='/')
        {
           op2 = pop1();
           op1 = pop1();
     
           switch (ch)   
           {
            case'+':push1(op1 + op2);
                    break;            
            case'-':push1(op1 - op2);
                    break;                            
            case'*':push1(op1 * op2);
                    break;                    
            case'/':push1(op1 / op2);
                    break;
            } 
         }
         
        else   //operand
        {
            push1(ch - '0');
        }
      }                    
      cout<<"\n\n\t Answer is =  "<<stk1[top1];
}  
   
int main()
{

   cout<<"\n---------------Conversion of expression from infix to postfix---------------";
   
   Infix_to_Postfix();
   
   cout<<"\n";
   
   cout<<"\n---------------Postfix Evaluation---------------";
   
   Postfix_Evaluation();
  
   cout<<"\n\n";   
   return 0;
}

/*
student@ubuntu:~$ g++ Pr8_expr.cpp -o a
student@ubuntu:~$ ./a

---------------Conversion of expression from infix to postfix---------------

Enter the infix expression: 5*(2+3)

The postfix expression is :  523+*

---------------Postfix Evaluation---------------

	 Answer is =  25


student@ubuntu:~$ ./a

---------------Conversion of expression from infix to postfix---------------

Enter the infix expression: [(2+4)*(5-2)]

The postfix expression is :  24+52-*

---------------Postfix Evaluation---------------

	 Answer is =  18

student@ubuntu:~$ ./a

---------------Conversion of expression from infix to postfix---------------

Enter the infix expression: 1*3*9*4

The postfix expression is :  1394***

---------------Postfix Evaluation---------------

	 Answer is =  108

*/
