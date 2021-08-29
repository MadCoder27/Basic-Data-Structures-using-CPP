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

int A[5];		//Array to Sort
int n = 5;      //Size of Array

void input()
{
   int i;
   
   cout<<"\n\n Enter the Values in Array: ";
   for(i=0; i<n; i++)
   {
      cout<<"\n\t Enter value: ";
      cin>>A[i];
   }
}

void output()
{
   int i;
   
   for(i=0; i<n; i++)
   {
      cout<<"  "<<A[i];
   }
}

void Bubble_Sort()
{
   int i,j,temp;
   
   input();
   for(i=0; i<n-1; i++)		//Passes
   {
      for(j=0; j<n-1; j++)	//Comparisons
      {
         if( A[j] > A[j+1] )
         {
            temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
         }
      }
      cout<<"\n\t Pass "<<i+1<<" :";
      output();
   }   
}

void Selection_Sort()
{
   int i,j,temp;
   
   input();
   for(i=0; i<n-1; i++)		//Passes
   {
      for(j=i+1; j<n; j++)	//Comparisons
      {
         if( A[i] > A[j] )
         {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
         }
      }
      cout<<"\n\t Pass "<<i+1<<" :";
      output();
   }      
}

void Insertion_Sort()
{
   int i,j,k,temp;
   
   input();
   for(i=1; i<n; i++)		//Passes
   {
      for(j=0; j<1; j++)	//Comparisons
      {
         if( A[j] > A[i] )
         {
            temp = A[i];
            for(k=i-1; k>=j; k--)
               A[k+1] = A[k];   
            A[j] = temp;
         }
      }
      cout<<"\n\t Pass "<<i<<" :";
      output();
   }   
}

int main()
{
   cout<<"\n\n -------*** Sorting Algorithms ***-------";

   cout<<"\n\n 1....Bubble Sort Algorithm";
   Bubble_Sort();
   
   cout<<"\n\n 2....Selection Sort Algorithm";
   Selection_Sort();
   
   cout<<"\n\n 3....Insertion Sort Algorithm";
   Insertion_Sort();
   
   cout<<"\n\n";
   return 0;
}

/*
OUTPUT:
student@ubuntu:~$ g++ Pr12_sorting.cpp -o a
student@ubuntu:~$ ./a


 -------*** Sorting Algorithms ***-------

 1....Bubble Sort Algorithm

 Enter the Values in Array: 
	 Enter value: 5

	 Enter value: 4

	 Enter value: 3

	 Enter value: 2

	 Enter value: 1

	 Pass 1 :  4  3  2  1  5
	 Pass 2 :  3  2  1  4  5
	 Pass 3 :  2  1  3  4  5
	 Pass 4 :  1  2  3  4  5

 2....Selection Sort Algorithm

 Enter the Values in Array: 
	 Enter value: 5

	 Enter value: 4

	 Enter value: 3

	 Enter value: 2

	 Enter value: 1

	 Pass 1 :  1  5  4  3  2
	 Pass 2 :  1  2  5  4  3
	 Pass 3 :  1  2  3  5  4
	 Pass 4 :  1  2  3  4  5

 3....Insertion Sort Algorithm

 Enter the Values in Array: 
	 Enter value: 5

	 Enter value: 4

	 Enter value: 3

	 Enter value: 2

	 Enter value: 1

	 Pass 1 :  4  5  3  2  1
	 Pass 2 :  3  4  5  2  1
	 Pass 3 :  2  3  4  5  1
	 Pass 4 :  1  2  3  4  5


*/
























