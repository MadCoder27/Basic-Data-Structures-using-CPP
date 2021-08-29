/*
Practical No.:4

Title:Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
      Second, third and final year of department can be granted membership on request. Similarly
      one may cancel the membership of club. First node is reserved for president of club and last
      node is reserved for secretary of club. Write C++ program to maintain club member‘s
      information using singly linked list. Store student PRN and Name. Write functions to 
a)Add and delete the members as well as president or even secretary.
b)Compute total number of members of club
c)Display members
d)Display list in reverse order using recursion
e)Two linked lists exists for two divisions. Concatenate two lists.

Started on: 19th July 2019
Completed on: 30th July 2019  
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
    int PRN;
    char Name[10];
    struct Node *next;    
}*head,*head1,*head2;

void Createlist1()
{
    int i,n;
    struct Node *crnt,*prev;
    
    head = NULL;
    
    cout<<"\nFor Division A:\nInformation of how many members is to be stored?\t";
    cin>>n;

    for(i=0;i<n;i++)
    {
       crnt = new(struct Node);
       
       cout<<"\n\tEnter PRN no.:";
       cin>>crnt->PRN;
       
       cout<<"\n\tEnter name:";
       cin>>crnt->Name;
       
       crnt->next=NULL;
       
       if(head == NULL)
       {
          head = crnt;
          prev = head;          
       }
       else
       {
          prev->next = crnt;
          prev = crnt;
       }
    }
}


void Createlist2()
{
    int i,n;
    struct Node *crnt1,*prev1;
    
    head1 = NULL;
    
    cout<<"\nFor Division B:\nInformation of how many members is to be stored?\t";
    cin>>n;

    for(i=0;i<n;i++)
    {
       crnt1 = new(struct Node);
       
       cout<<"\n\tEnter PRN no.:";
       cin>>crnt1->PRN;
       
       cout<<"\n\tEnter name:";
       cin>>crnt1->Name;
       
       crnt1->next=NULL;
       
       if(head1 == NULL)
       {
          head1 = crnt1;
          prev1 = head1;          
       }
       else
       {
          prev1->next = crnt1;
          prev1 = crnt1;
       }
    }
}

void Displaylist()
{
    struct Node *a;
    
    a = head;
    cout<<"\nHead";
    
    while(a != NULL)
    {
       cout<<"----->|"<<a->PRN<<"|"<<a->Name<<"|";
       a = a->next;
    }
    
    cout<<"----->NULL\n\n";

}

void Count()
{
    struct Node *c;
    c = head;
    int count=0;
    
    while(c != NULL)
    {
       count=count+1;
       c = c->next;
    }
    
    cout<<count<<"\n\n";
}

void Reverse()
{
    struct Node *p, *temp;
    p = head;
    head2 = NULL;
    while(p != NULL)
    {
       temp=new(struct Node);
       temp->PRN = p->PRN;
       strcpy(temp->Name,p->Name);
       temp->next = NULL;
       
       if(head2 == NULL)
          head2 = temp;
       else
       {
          temp->next = head2;
          head2 = temp;  
       }
       p=p->next;
    } 
        
    {                                                //Displaying reverse list
        p = head2;
        cout<<"\n\nHead2";
    
        while(p != NULL)
        {
           cout<<"----->|"<<p->PRN<<"|"<<p->Name<<"|";
           p = p->next;
        }
    
        cout<<"----->NULL\n\n"; 
    }       
}

void Concatenate()
{
     struct Node *p;
     p = head;
     while(p->next != NULL)
         p = p->next;
     p->next = head1;
          
     Displaylist(); 
}

void Delete()
{
   struct Node *p, *q;
   int rno;
   cout<<"\nEnter PRN no. to be deleted\t";
   cin>>rno;
   p=q=head;
   
   while(p!=NULL)
   {
      if(rno==p->PRN)
      {
         if(p==head)
         {
            head==head->next;
            delete p;
         }
         else
         {
            q->next=p->next;
            delete p;
         }
         break;
      }
      else
      {
         q=p;
         p=p->next;
      }
   
   }
   Displaylist();
}


int main()
{
    cout<<"\n-----------------------------------------------\n\n";
    cout<<">>>>>>>>>>>>> Creation of list:\n";
    Createlist1();

    cout<<"\n\n>>>>>>>>>>>>>> Displaying list:\n";
    Displaylist();
    
    cout<<"\n>>>>>>>>>>>>>> Total number of members are:\t";
    Count();
   
    cout<<"\n>>>>>>>>>>>>>> List in Reverse order:";
    Reverse();
    
    Createlist2();
    cout<<"\n>>>>>>>>>>>>>> Concatenated list:";
    Concatenate();
      
    cout<<"\n>>>>>>>>>>>>>> Deletion of Node:";
    Delete();       
    return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
student@ubuntu:~$ gedit Pr4_linklist.cpp
student@ubuntu:~$ g++ Pr4_linklist.cpp -o t
student@ubuntu:~$ ./t

-----------------------------------------------

>>>>>>>>>>>>> Creation of list:

For Division A:
Information of how many members is to be stored?	3

	Enter PRN no.:123

	Enter name:Tanvi 

	Enter PRN no.:456

	Enter name:Sakshi

	Enter PRN no.:789

	Enter name:Sayali


>>>>>>>>>>>>>> Displaying list:

Head----->|123|Tanvi|----->|456|Sakshi|----->|789|Sayali|----->NULL


>>>>>>>>>>>>>> Total number of members are:	3


>>>>>>>>>>>>>> List in Reverse order:

Head2----->|789|Sayali|----->|456|Sakshi|----->|123|Tanvi|----->NULL


For Division B:
Information of how many members is to be stored?	3

	Enter PRN no.:321

	Enter name:Nikita

	Enter PRN no.:654

	Enter name:Sejal

	Enter PRN no.:987

	Enter name:Rituja

>>>>>>>>>>>>>> Concatenated list:
Head----->|123|Tanvi|----->|456|Sakshi|----->|789|Sayali|----->|321|Nikita|----->|654|Sejal|----->|987|Rituja|----->NULL


>>>>>>>>>>>>>> Deletion of Node:
Enter PRN no. to be deleted 987

Head----->|123|Tanvi|----->|456|Sakshi|----->|789|Sayali|----->|321|Nikita|----->|654|Sejal|----->NULL

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/














