/*
Practical No: 12
Title       : Write C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Bubble Sort
b) Selection Sort 
b) Insertion sort and display top five scores.

Started On: 13th September 2019
Completed On: 17th September 2019

Batch: A
Roll No.: 9

*/

#include<iostream>
using namespace std;

float S[5];
int n = 5;

void Input()
{
   cout<<"\n\nEnter the percentages of students : ";
   
   for(int i=0; i<n; i++)
   {
      cout<<"\n\t Enter percentage : ";
      cin>>S[i];
   }
}   

void Output()
{
   for(int i=0; i<n; i++)
   {
      cout<<"  "<<S[i]<<"%";
   }
}

void Bubble_Sort()
{
   int i,j;
   float temp;
   
   Input();
   for(i=0; i<n-1; i++)
   {
      for(j=0; j<n-1; j++)
      {
         if(S[j] > S[j+1])
         {
            temp = S[j];
            S[j] = S[j+1];
            S[j+1] = temp;   
         }
      }
      cout<<"\n\t Pass "<<i+1<<" :";
      Output();
   }
}

int main()
{
   cout<<"\n\n~~~~~~~~~~~ Sorting Algorithms ~~~~~~~~~~~";
   cout<<"\n\n1) Using Bubble Sort: ";
   Bubble_Sort();
   
   cout<<"\n\nSorted Percentages : ";
   Output();
   
   cout<<"\n\n";
   return 0;
}

/*
student@ubuntu:~$ g++ Pr12_Sort.cpp -o a
student@ubuntu:~$ ./a


~~~~~~~~~~~ Sorting Algorithms ~~~~~~~~~~~

1) Using Bubble Sort: 

Enter the percentages of students : 
	 Enter percentage : 99.7

	 Enter percentage : 98.4

	 Enter percentage : 84.5

	 Enter percentage : 76.1

	 Enter percentage : 72.1

	 Pass 1 :  98.4%  84.5%  76.1%  72.1%  99.7%
	 Pass 2 :  84.5%  76.1%  72.1%  98.4%  99.7%
	 Pass 3 :  76.1%  72.1%  84.5%  98.4%  99.7%
	 Pass 4 :  72.1%  76.1%  84.5%  98.4%  99.7%

Sorted Percentages :   72.1%  76.1%  84.5%  98.4%  99.7%

*/


