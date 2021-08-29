/*
Practical No: 13
Title: Write C++ program to store first year percentage of students in array. Sort array of floating point numbers in ascending order using quick sort and display top five scores.

Started On: 27th September 2019
Completed On: 27th September 2019

Batch: A
Roll No.: 9

*/

#include<iostream>
using namespace std;

void Quick_Sort(float A[], int low, int high);

int main()
{
   int i, size = 5;
   float A[10];
   
   cout<<"\n\nEnter the percentages of the students : ";
   for(i=0; i<size; i++)
   {
      cout<<"\n\tFor student "<<i+1<<" :  ";
      cin>>A[i];
   }
   
   cout<<"\n\nSorted list using Quick Sort algorithm :";
   Quick_Sort(A, 0, size-1);
   
   cout <<"\n\nSorted percentages are : ";
   for(i=0; i<5; i++)
      cout<<A[i]<<"%   ";
  	     
   cout<<"\n\n";
   return 0;
}

void Quick_Sort(float A[], int low, int high)
{
   float pivot, temp;
   int i, j;
   
   if(low<high)
   {
      pivot = A[low];
      i = low;
      j = high;
      
      while(i<j)
      {
         while(pivot >= A[i] && i<j)
            i++;
         while(pivot < A[j] && i<=j)
            j--;
         
         if(i <= j)
         {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
         }
      }
      
      temp = A[j];
      A[j] = A[low];
      A[low] = temp;
      
      cout <<"\nPass : ";
      for(i=0; i<5; i++)
  	     cout<<A[i]<<"   ";
  	   
      Quick_Sort(A, low , j-1);		
      
      Quick_Sort(A, j+1 , high); 
   }   
}

/*
OUTPUT :
student@ubuntu:~$ g++ Pr13_Quick.cpp -o a
student@ubuntu:~$ ./a


Enter the percentages of the students : 
	For student 1 :  97.4

	For student 2 :  86.4

	For student 3 :  55.2

	For student 4 :  35.4

	For student 5 :  72.4


Sorted list using Quick Sort algorithm :
Pass : 72.4   86.4   55.2   35.4   97.4   
Pass : 55.2   35.4   72.4   86.4   97.4   
Pass : 35.4   55.2   72.4   86.4   97.4   

Sorted percentages are : 35.4%   55.2%   72.4%   86.4%   97.4% 


student@ubuntu:~$ ./a


Enter the percentages of the students : 
	For student 1 :  26

	For student 2 :  14

	For student 3 :  21

	For student 4 :  18

	For student 5 :  10


Sorted list using Quick Sort algorithm :
Pass : 10   14   21   18   26   
Pass : 10   14   21   18   26   
Pass : 10   14   21   18   26   
Pass : 10   14   18   21   26   

Sorted percentages are : 10   14   18   21   26   



*/







