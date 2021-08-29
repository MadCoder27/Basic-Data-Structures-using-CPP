/*
Practical No: 6
Title: Write C++ program for storing binary number using doubly linked lists. Write functions-
       a) to compute 1‘s and 2‘s complement 
       b) add two binary numbers

Started On: 16th August 2019
Completed On: 20th August 2019

Batch: A
Roll No.: 9

*/


#include<iostream>
using namespace std;

struct DLLNode
{
    int bit;
    struct DLLNode *prev,*next;
    
}*Head1,*Head2;

int Carry;

struct DLLNode *Create_DLL()
{
       struct DLLNode *NewNode,*p,*Head;
       int i;
       Head = NULL;
       cout<<"\n";
       for(i=0; i<4; i++)
       {
           NewNode = new(struct DLLNode);
           cout<<"\t Enter a bit: ";
           cin>>NewNode->bit;
           NewNode->prev = NewNode->next=NULL;
           if(Head == NULL)
           {
               Head = NewNode;
                  p = Head;           
           }
           else
           {
             p->next = NewNode;
             NewNode->prev = p;
             p =NewNode;           
           }
           
       }
       return Head;
}

void Display(struct DLLNode *Head)
{
    struct DLLNode *p;
    p = Head;
    while(p!=NULL)
    {
        cout<<" "<<p->bit;
        p = p->next;
    }
    cout<<"\n";
}

void Add_Bin()
{
   struct DLLNode *p,*q;
   Carry=0;
   p = Head1;
   q = Head2;
   while(p->next != NULL)
     p=p->next;
   while(q->next != NULL)
     q=q->next;  
   
   while(p != NULL || q != NULL)
   {
      if(p->bit == 0 && q->bit == 0)
         {
           if(Carry==1)
              {
                p->bit = 1;
                Carry = 0;
              }
           else
              {
                p->bit = 0;
                Carry = 0;
              }
         }
      else if(p->bit == 0 && q->bit == 1)
         {  
           if(Carry==1)
              {
                p->bit = 0;
                Carry = 1;
              }
           else
              {
                p->bit = 1;
                Carry = 0;
              }
         }
      else if(p->bit == 1 && q->bit == 0)
         {  
           if(Carry==1)
              {
                p->bit = 0;
                Carry = 1;
              } 
           else
              {
                p->bit = 1;
                Carry = 0;
              } 
         }
      else if(p->bit == 1 && q->bit ==1)
        {  
           if(Carry==1)
              {
                p->bit = 1;
                Carry = 1;
              } 
           else
              {
                p->bit = 0;
                Carry = 1;
              }
        }
      q=q->prev;
      p=p->prev;  
   }
   
}

void Comp_1s()
{
   struct DLLNode *p,*q;
   p=Head1;
   q=Head2;
   while(q != NULL)
   {
      if(q->bit == 0)
        p->bit = 1;
      if(q->bit ==1)
        p->bit = 0;
      p=p->next;
      q=q->next;   
   }
   cout<<"\n 1's complement of ";
   Display(Head2);
   cout<<" is :";
   Display(Head1);
}

void Comp_2s()
{
   struct DLLNode *p;
   p=Head1;
   while(p->next != NULL)
      p=p->next;
   while(p != NULL)
   {
      if(p->bit ==0)
      {
         p->bit = 1;
         break;
      }
      else
      {
         p->bit = 0;
         p=p->prev;
      }
   }
   cout<<"\n 2's complement of ";
   Display(Head2);
   cout<<" is :";
   Display(Head1);
}

int main()
{

   cout<<"\n\tFirst binary no: ";
   Head1 = Create_DLL();
   cout<<"\n\tSecond binary no: ";
   Head2 = Create_DLL();
   
   cout<<"\n\tFirst binary no: ";
   Display(Head1);
   cout<<"\n\tSecond binary no: ";
   Display(Head2);
   
   cout<<"\n\tAddition of binary nos.: ";
   Add_Bin();
   Display(Head1);
   cout<<"\tCarry= "<<Carry<<"\n";
   
   Comp_1s();
   Comp_2s();
   
   return 0;
}

/*
student@ubuntu:~$ g++ Binary.cpp -o a
student@ubuntu:~$ ./a

	First binary no: 
	 Enter a bit: 1
	 Enter a bit: 1
	 Enter a bit: 1
	 Enter a bit: 1

	Second binary no: 
	 Enter a bit: 0
	 Enter a bit: 0
	 Enter a bit: 1
	 Enter a bit: 0

	First binary no:  1 1 1 1

	Second binary no:  0 0 1 0

	Addition of binary nos.:  0 0 0 1
	Carry= 1

 1's complement of  0 0 1 0
 is : 1 1 0 1

 2's complement of  0 0 1 0
 is : 1 1 1 0

*/

