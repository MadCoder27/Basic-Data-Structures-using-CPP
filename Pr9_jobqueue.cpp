/*
Practical No: 9
Title: Queues are frequently used in computer programming, and a typical example is the creation
of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating
job queue. Write functions to add job and delete job from queue.

Started On: 3rd September 2019
Completed On: 6th September 2019

Batch: A
Roll No.: 9
*/

#include<iostream>
using namespace std;

char que[5];
int front = -1;
int rear = -1;
int size = 5;

int que_full()
{
   if(rear == size-1)
      return 1;
   else
      return 0;
}

int que_empty()
{
   if((front == rear == -1) || front == rear)
      return 1;
   else
      return 0;
}

char del_job()
{
   char ch;
   front++;
   ch = que[front];
   return ch;    
}

void insert(char Job)
{
   rear++;
   que[rear] = Job;
}

void display()
{
   for(int i = front+1 ; i <= rear; i++)
      cout<<que[i]<<" ";
}

int main()
{
   int i,cnt;
   char Job;
   
   cout<<"\nHow many jobs?  ";
   cin>>cnt;
   
   for(i=0; i<cnt; i++)
   {
      cout<<"\nEnter the job : ";
      cin>>Job;
      
      if(!que_full())
         insert(Job);
      else
      {
         cout<<"\nThe queue is full...!!!";
         break;
      }   
   }
   
   cout<<"\nJobs in the queue : ";
   display();
   
   while(!que_empty())
   {
      cout<<"\nProcessed Job : "<<del_job(); 
   }
   
   cout<<"\nQueue is empty...!!!\n\n";       
   return 0;
}

/*
OUTPUT:

student@ubuntu:~$ g++ Pr9_jobqueue.cpp -o a
student@ubuntu:~$ ./a

How many jobs?  6

Enter the job : A

Enter the job : B

Enter the job : C

Enter the job : D

Enter the job : E

Enter the job : F

The queue is full...!!!
Jobs in the queue : A B C D E 
Processed Job : A
Processed Job : B
Processed Job : C
Processed Job : D
Processed Job : E
Queue is empty...!!!

*/

