/*
Practical No.:03
Title: A magic square is an n*n matrix of the integers 1 to n^2 such that the sum of each row, 
      column, and diagonal is the same. The figure given below is an example of magic square for 
      case n=5. In this example, the common sum is 65. Write C/C++ Program for magic square.

15   8   1  24  17
16  14   7   5  23
22  20  13   6   4
3   21  19  12  10
9   2   25  18  11

Started on: 9th July 2019
Completed on: 12th July 2019

Batch: A
Roll No.: 9
*/

#include<iostream>
using namespace std;
int s, M[10][10];

void initial()
{
 int i,j;
 cout<<"\nEnter the number of rows/columns for the magic square:\t";
 cin>>s;
 for(i=0;i<s;i++)
 {
    for(j=0;j<s;j++)
    {
       M[i][j]=0;
    }
 }
}

void magic_square()
{
   int i,j,s,val;
   i=s/2;
   j=s-1;
   
   for(val=1;val<=s*s;val++)
      {
         if(i==-1 && j==s)
         {
            j=s-2;
            i=0;
         }
         else
         {
            if(j==s)
               j=0;
            if(i<0)
               i=s-1;
         }
         
         if(M[i][j])
         {
            j=j-2;
            i=i+1;
         }
         
         M[i][j]=val;
           j++;
           i--;
      }
   
}

void display()
{
 int i,j;
 cout<<"The "<<s<<"*"<<s<<" magic square is:\n";

 for(i=0;i<s;i++)
 {
    for(j=0;j<s;j++)
    {
       cout<<M[i][j];
       cout<<"\t";       
    }
    cout<<"\n";
 }
}

int main()
{
initial();
magic_square();
display();
return 0;
}
