/*
Practical No: 10
Title       : A double-ended queue(deque) is a linear list in which additions and deletions may be made
at either end. Obtain a data representation mapping a deque into a one-dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either
end of the deque.

Started On: 6th September 2019
Completed On: 9th September 2019

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

char del_fromFront()
{
   char ch;
   front++;
   ch = que[front];
   return ch;    
}

char del_fromRear()
{
   char ch;
   ch = que[rear];
   rear--;
   return ch;    
}

void insert_AtRear(char Job)
{
   rear++;
   que[rear] = Job;
}

void insert_AtFront(char Job)
{
   que[front] = Job;
   front--;
}

void display()
{
   for(int i = front+1 ; i <= rear; i++)
      cout<<que[i]<<" ";
}

int main()
{
   int choice;
   char Job,ans;
   
   do
   {
      cout<<"\n\n\t***List of choices***";
      cout<<"\n1.Insert at rear in the DEQueue";
      cout<<"\n2.Delete job from front from the DEQueue";
      cout<<"\n3.Insert at front in the DEQueue";
      cout<<"\n4.Delete job from rear from the DEQueue";
      
      cout<<"\n\nEnter your choice : ";
      cin>>choice;
      
      switch(choice)
      {
         case 1: cout<<"\n\tEnter the job : ";
                 cin>>Job;
                 insert_AtRear(Job);
                 cout<<"\tStatus of the DEqueue : ";
                 display();
                 break;
                 
         case 2: cout<<"\n\tDeleted... "<<del_fromFront();
                 cout<<"\n\tStatus of the DEqueue : ";
                 display();
                 break;
         
         case 3: cout<<"\n\tEnter the job : ";
                 cin>>Job;
                 insert_AtFront(Job);
                 cout<<"\tStatus of the DEqueue : ";
                 display();
                 break;
                 
         case 4: cout<<"\n\tDeleted... "<<del_fromRear();
                 cout<<"\n\tStatus of the DEqueue : ";
                 display();
                 break;
         
         default:cout<<"\n\tInvalid Choice...!!!";
      }
      
      cout<<"\n\nDo you want to continue?(Y/N) ";
      cin>>ans;
      
   }while(ans == 'Y');
   
}

/*
OUTPUT:
student@ubuntu:~$ g++ Pr10_deque.cpp -o a
student@ubuntu:~$ ./a


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 1

	Enter the job : R
	Status of the DEqueue : R 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 1

	Enter the job : E
	Status of the DEqueue : R E 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 1

	Enter the job : A
	Status of the DEqueue : R E A 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 1

	Enter the job : L
	Status of the DEqueue : R E A L 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 2

	Deleted... R
	Status of the DEqueue : E A L 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 3

	Enter the job : H
	Status of the DEqueue : H E A L 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 4

	Deleted... L
	Status of the DEqueue : H E A 

Do you want to continue?(Y/N) Y


	***List of choices***
1.Insert at rear in the DEQueue
2.Delete job from front from the DEQueue
3.Insert at front in the DEQueue
4.Delete job from rear from the DEQueue

Enter your choice : 1

	Enter the job : D
	Status of the DEqueue : H E A D 

Do you want to continue?(Y/N) N
*/

