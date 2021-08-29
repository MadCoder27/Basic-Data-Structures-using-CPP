/*
Practical No: 11
Title       : Write C++ program to store roll numbers of student in array who attended training program
in random order. Write function for-
(a) Searching whether particular student attended training program or not using linear search. 
(b) Searching whether particular student attended training program or not using binary search.

Started On: 10th September 2019
Completed On: 10th September 2019

Batch: A
Roll No.: 9
*/

#include<iostream>
using namespace std;

int List[] = {10,20,30,40,50};
int size = 5;

void Linear_Search()
{
   int key, cnt = 0, i;
   
   cout<<"\n\t\t---***Linear Search***---";
   cout<<"\n\n\t\tEnter the key to be searched :  ";
   cin>>key;
   
   for(i=0; i<size; i++)
   {
      cnt++;
      if(key == List[i])
      {
         cout<<"\n\t\tKey found...!!!";
         cout<<"\n\t\tNo. of comparisons required : "<<cnt;
         break;
      }
   }
   
   if(i == size)
   {
      cout<<"\n\t\tKey not found...!!!";
      cout<<"\n\t\tNo. of comparisons required : "<<cnt;
   }   
}

void Binary_Search()
{
   int key, cnt, Mid, Low, High;
   cnt = 0;
   Low = 0;
   High = size-1;
   
   cout<<"\n\t\t---***Binary Search***---";
   cout<<"\n\t\tEnter the key to be searched :  ";
   cin>>key;
    
   while(Low <= High)
   {
      Mid = (Low + High)/2;
      cnt++;
      
      if(key == List[Mid])
      {
         cout<<"\n\t\tKey found...!!!";
         cout<<"\n\t\tNo. of comparisons required : "<<cnt;
         break;
      }
      
      else if(key < List[Mid])
         High = Mid - 1;
      else
         Low = Mid + 1;
   }
   
   if(Low > High)
   {
      cout<<"\n\t\tKey not found...!!!";
      cout<<"\n\t\tNo. of comparisons required : "<<cnt;
   }   
}

void display()
{
   cout<<"\n\nThe elements in the list are :";
   for(int i = 0; i<size ; i++)
      cout<<" "<<List[i];
}

int main()
{
   int ch;
   char ans;
   
   do
   {
      display();
      cout<<"\n\n\t---Search choices---";
      cout<<"\n\t1. Linear Search";
      cout<<"\n\t2. Binary Search";
      cout<<"\n\n\tWhich search do you want to perform?  ";
      cin>>ch;
      
      switch(ch)
      {
         case 1: Linear_Search();
                 break;
                 
         case 2: Binary_Search();
                 break;
         
         default : cout<<"\n\tInvalid choice...!!!";   
      }
      cout<<"\n\n\tDo you want to continue?(y/n) : ";
      cin>>ans;
   }while(ans == 'y');
   
   cout<<"\n\n";
   return 0;
}

/* 
OUTPUT:
student@ubuntu:~$ g++ Pr11_Search.cpp -o a
student@ubuntu:~$ ./a


The elements in the list are : 10 20 30 40 50

	---Search choices---
	1. Linear Search
	2. Binary Search

	Which search do you want to perform?  1

		---***Linear Search***---

		Enter the key to be searched :  10

		Key found...!!!
		No. of comparisons required : 1

	Do you want to continue?(y/n) : y


The elements in the list are : 10 20 30 40 50

	---Search choices---
	1. Linear Search
	2. Binary Search

	Which search do you want to perform?  2 

		---***Binary Search***---
		Enter the key to be searched :  10

		Key found...!!!
		No. of comparisons required : 2

	Do you want to continue?(y/n) : y


The elements in the list are : 10 20 30 40 50

	---Search choices---
	1. Linear Search
	2. Binary Search

	Which search do you want to perform?  1

		---***Linear Search***---

		Enter the key to be searched :  30

		Key found...!!!
		No. of comparisons required : 3

	Do you want to continue?(y/n) : y


The elements in the list are : 10 20 30 40 50

	---Search choices---
	1. Linear Search
	2. Binary Search

	Which search do you want to perform?  2

		---***Binary Search***---
		Enter the key to be searched :  30

		Key found...!!!
		No. of comparisons required : 1

	Do you want to continue?(y/n) : y


The elements in the list are : 10 20 30 40 50

	---Search choices---
	1. Linear Search
	2. Binary Search

	Which search do you want to perform?  1

		---***Linear Search***---

		Enter the key to be searched :  50

		Key found...!!!
		No. of comparisons required : 5

	Do you want to continue?(y/n) : y


The elements in the list are : 10 20 30 40 50

	---Search choices---
	1. Linear Search
	2. Binary Search

	Which search do you want to perform?  2

		---***Binary Search***---
		Enter the key to be searched :  50

		Key found...!!!
		No. of comparisons required : 3

	Do you want to continue?(y/n) : n



*/











