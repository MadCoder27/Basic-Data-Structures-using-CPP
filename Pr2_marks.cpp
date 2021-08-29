/*
Practical No: 2
Title: Write C/C++ program to store marks scored for first test of subject 'Data Structures and 
       Algorithms' for N students. Compute 
       i.    The average score of class
       ii.   Highest score and lowest score of class
       iii.  Marks scored by most of the students
       iv.  list of students who were absent for the test

Started On: 4th July 2019
Completed On: 4th July 2019

Batch: A
Roll No.: 9
*/

#include<iostream>
using namespace std;

int s, A[20];

void input()
{
   int i;
   cout<<"**************************************************************";
   cout<<"\n\nMarks of how many students is to be entered?\t";
   cin>>s;
  
   cout<<"\nEnter marks(use 0 for absent students): \t";
   for(i=0;i<s;i++)
      cin>>A[i]; 
}

void display()
{
   int i;
   cout<<"\n***********************************************************";
   cout<<"\n\nMarks scored by "<<s<<" students in the first test of Data Structures Lab are:  \n ";
   
   for(i=0;i<s;i++)
      cout<<A[i]<<" "; 
}

void avg()
{
   int sum,i;
   int avg;
   
   for(i=0;i<s;i++)
      sum=sum+A[i];
      
   avg=sum/s;
   cout<<"\n\nAverage marks scored by the students are:   "<<avg<<"\n";
}

void high()
{
   int i,High;
   High=0;
      for(i=0;i<s;i++)
         {  
            if(High<A[i])
            High=A[i];  
         }       
      
   cout<<"\nHighest marks scored are:   "<<High<<"\n";
}

void low()
{
   int i,Low;
   Low=999;
      for(i=0;i<s;i++)
         {  
            if(Low>A[i])
            Low=A[i];  
         }       
      
   cout<<"\nLowest marks scored are:   "<<Low<<"\n";
}

void absent()
{
   int count,i;
   count=0;
   for(i=0;i<s;i++)
      {
         if(A[i]==0)
            count=count+1;
      }
   cout<<"\n"<<count<<" students were absent for the test.\n";   
}

void most()
{  
   int i,j,k,most,count[s];
   k=0;
   for(i=0;i<s;i++)
      {
         for(j=0;j<s;j++)
         {
            if(A[i]==A[j])
              {
              k=k+1;
              }        
         }
          count[i]=k;
          k=0;
      }
   int High; 
   High=0;
      for(i=0;i<s;i++)
         {  
            if(High<count[i])
            {
               High=count[i];
               most=i;
            }     
         }        
   cout<<"\nMarks scored by most of the students is "<<A[most]<<" (occurences "<<count[most]<<")\n\n";
   cout<<"\n*************************************************************";
}

int main()
{
input();
display();
avg();
high();
low();
absent();
most();
return 0;
}

/*
student@ubuntu:~$ g++ Pr2.cpp -o a
student@ubuntu:~$ ./a
**************************************************************************

Marks of how many students is to be entered? 10

Enter marks(use 0 for absent students):  30 20 22 10 0 40 25 35 35 24

**************************************************************************

Marks scored by 10 students in the first test of Data Structures Lab are:  
30 20 22 34 0 40 0 35 35 24 

Average marks scored by the students are:   24

Highest marks scored are:   40

Lowest marks scored are:   0

2 students were absent for the test.

Marks scored by most of the students is 35 (occurences 3)
**************************************************************************
*/
