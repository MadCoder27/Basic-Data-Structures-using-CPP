/*

Practical No: 1
Practical  name: In Second year Computer Engineering class of M students, set A of students
                 play cricket and set B of students play badminton. Write C/C++ program to find and
                 display
                 i.  Set of students who play either cricket or  badminton or both
                 ii. Set of students who play both cricket and badminton 
                 iii.Set of students who play only cricket 
                 iv. Set of students who play only badminton 
                 v.  Number of students who play neither cricket nor badminton
                 (Note-While realizing the set duplicate entries are to be avoided)

Started On: 2nd July 2019
Completed On: 4th July 2019

Batch: A
Roll No.: 9
*/

//---------------------------------------------------------------Header Files
#include<iostream>
using namespace std;

//---------------------------------------------------------------Global variables

int M[10],A[5],B[5],AUB[10];
int msize = 10;
int absize = 5;
int AUBsize = 0;

//---------------------------------------------------------------Input Function

void input()			//To input into Arrays
{
   int i;
   
   cout<<"\n\n Enter roll numbers of 10 students: ";
   for(i=0; i<msize; i++)	//To fill M[]
      cin>>M[i];

   cout<<"\n\n Enter roll numbers of 5 sudents who play cricket: ";      
   for(i=0; i<absize; i++)	//To fill A[]
      cin>>A[i];
      
   cout<<"\n\n Enter roll numbers of 5 sudents who play badminton: ";      
   for(i=0; i<absize; i++)	//To fill B[]
      cin>>B[i];            
}

//---------------------------------------------------------------Display Function

void display()			//To input into Arrays
{
   int i;
   
   cout<<"\n\t Set S : ";
   for(i=0; i<msize; i++)	//To display M[]
      cout<<M[i]<<", ";
   
   cout<<"\n\t Set C : ";   
   for(i=0; i<absize; i++)	//To display A[]
      cout<<A[i]<<", ";
      
   cout<<"\n\t Set B : ";      
   for(i=0; i<absize; i++)	//To display B[]
      cout<<B[i]<<", ";            
}

//---------------------------------------------------------------AUB Function
void AuniB()
{
   int i,j,k,flag;
   AUBsize = 0;
   
   for(i=0; i<absize; i++)	//To fill A[] into AUB[]
   {
      AUB[AUBsize] = A[i];   
      AUBsize++;
   }
   
   for(i=0; i<absize; i++)	//To copy B[] into AUB[]   
   {
       flag = 0;
       for(j=0; j<absize; j++)	//To compare B[] with A[]
       {
           if(B[i] == A[j])
           {
               flag = 1;
               break;
           }
       } 
       if(flag == 0)
       {
          AUB[AUBsize] = B[i];
          AUBsize++;
       }
   }   
   
   cout<<"\n\t Students who play at least one game : ";      
   for(i=0; i<AUBsize; i++)			//To display AUB[]
      cout<<AUB[i]<<", "; 
}

//---------------------------------------------------------------AintB Function
void AintB()
{
   int i,j,k,flag,AintB[10];
   k = 0;
   
   for(i=0; i<absize; i++)	//To copy B[] into AUB[]   
   {
       flag = 0;
       for(j=0; j<absize; j++)	//To compare B[] with A[]
       {
           if(B[i] == A[j])
           {
               flag = 1;
               break;
           }
       } 
       if(flag == 1)
       {
          AintB[k] = B[i];
          k++;
       }
   }  
   
   cout<<"\n\t Students who play both the games : ";      
   for(i=0; i<k; i++)			//To display AintB[]
      cout<<AintB[i]<<", ";  
}

//---------------------------------------------------------------AminB Function
void AminB()
{
   int i,j,k,flag,AminB[10];
   k = 0;
   
   for(i=0; i<absize; i++)	//For A[]
   {
       flag = 0;
       for(j=0; j<absize; j++)	//for B[]
       {
           if(A[i] == B[j])
           {
               flag = 1;
               break;
           }
       } 
       if(flag == 0)
       {
          AminB[k] = A[i];
          k++;
       }
   }  

   cout<<"\n\t Students who play only cricket : ";      
   for(i=0; i<k; i++)			//To display AminB[]
      cout<<AminB[i]<<", ";  
   
}

//---------------------------------------------------------------BminA Function

void BminA()
{
   int i,j,k,flag,BminA[10];
   k = 0;
   
   for(i=0; i<absize; i++)	//For B[]
   {
       flag = 0;
       for(j=0; j<absize; j++)	//for A[]
       {
           if(B[i] == A[j])
           {
               flag = 1;
               break;
           }
       } 
       if(flag == 0)
       {
          BminA[k] = B[i];
          k++;
       }
   }  

   cout<<"\n\t  Students who play only badminton : ";      
   for(i=0; i<k; i++)			//To display BminA[]
      cout<<BminA[i]<<", ";  
   
}

//---------------------------------------------------------------MminAUB Function

void MminAUB()
{
   int i,j,k,flag,MminAUB[10];
   k = 0;
   
   for(i=0; i<msize; i++)	//For M[]
   {
       flag = 0;
       for(j=0; j<AUBsize; j++)	//for AUB[]
       {
           if(M[i] == AUB[j])
           {
               flag = 1;
               break;
           }
       } 
       if(flag == 0)	//Not matching then copy...
       {
          MminAUB[k] = M[i];
          k++;
       }
   }  

   cout<<"\n\t Students who play neither cricket nor badminton : ";      
   for(i=0; i<k; i++)			//To display M-AUB[]
      cout<<MminAUB[i]<<", ";  
   
}

//---------------------------------------------------------------Main_Function

int main()
{
   cout<<"\n\n ***-------Set Operations-------***";
   input();
   cout<<"\n\n ***Inputs:";
   display(); 
   
   cout<<"\n\n ***Outputs:";   
   AuniB();
   AintB();
   AminB();
   BminA();
   MminAUB();
   
   cout<<"\n\n";
   return 0;
}

/*-----------OUTPUT----------------------

student@ubuntu:~$ g++ Pr1_Set.cpp -o a
student@ubuntu:~$ ./a


 ***-------Set Operations-------***

 Enter roll numbers of 10 students: 1 2 3 4 5 6 7 8 9 10


 Enter roll numbers of 5 sudents who play cricket: 1 2 3 4 5


 Enter roll numbers of 5 sudents who play badminton: 4 5 6 7 8


 ***Inputs:
	 Set S : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
	 Set C : 1, 2, 3, 4, 5, 
	 Set B : 4, 5, 6, 7, 8, 

 ***Outputs:
	 Students who play at least one game: 1, 2, 3, 4, 5, 6, 7, 8, 
	 Students who play both the games : 4, 5, 
	 Students who play only cricket : 1, 2, 3, 
	 Students who play only badminton : 6, 7, 8, 
	 Students who play neither cricket nor badminton : 9, 10, 

student@ubuntu:~$ 

*/



