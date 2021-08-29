/*
Practical No.:5

Title: Write C++ program for storing appointment schedule for day. Appointments are booked
       randomly using linked list. Set start and end time and min and max duration for visit slot.

       Write functions for-
        a) Display free slots
        b) Book appointment
        c) Cancel appointment (check validity, time bounds, availability etc)
        d) Sort list based on time
        e) Sort list based on time using pointer manipulation

Started on: 30th July 2019
Completed on:  6th August 2019

Batch: A
Roll No.: 9  
*/

#include<iostream>
#include<cstring>
using namespace std;

struct Node
{
   int Status;
   char Start[10];
   char End[10];
   char Min[10];
   char Max[10];
   struct Node *Next;
     
}*Head;

int nodes;
void Create_app()
{
    int i;
    struct Node *p,*tmp;
    
    cout<<"\n\nHow many appointments?  ";
    cin>>nodes;
    
    Head=NULL;
    
    for(i=0;i<nodes;i++)
    {
       cout<<"\n For Appointment "<<i+1<<" : \n";
       
       tmp = new(struct Node);
       tmp->Status=0;
       cout<<"\tEnter start time:  ";
       cin>>tmp->Start;
       cout<<"\tEnter end time:  ";
       cin>>tmp->End;
       cout<<"\tEnter miniumum duration:  ";
       cin>>tmp->Min;
       cout<<"\tEnter maximum duration:  ";
       cin>>tmp->Max;
       tmp->Next=NULL;
       if(Head==NULL)
       {
          Head=tmp;
          p=Head;
       }
       else
       {
          p->Next=tmp;
          p=tmp;
       }
       cout<<"\n";
    }
        
}


void Display_app()
{
   struct Node *p;
   
   cout<<"\n\n--------*** Appointments Schedule ***--------\n";
   cout<<"\n\tStatus\tStart\tEnd\tMin time\tMax time\n";
   
   p=Head;
   
   while(p!=NULL)
   {
      if(p->Status==0)
         cout<<"\tFree";
      else   
         cout<<"\tBooked";
      cout<<"\t"<<p->Start;
      cout<<"\t"<<p->End;
      cout<<"\t"<<p->Min;
      cout<<"\t\t"<<p->Max;
      cout<<"\n";   
      p=p->Next;
   }

}

void Book_appl()
{
    char time[10];
    struct Node *p;
    
    cout<<"\n\n To Book the Appointment.....";
    cout<<"\n\t Enter Start Time: ";
    cin>>time;
    
    p=Head;
   
   while(p != NULL)
   {
       if(strcmp(time, p->Start) == 0)
       {
           if(p->Status == 0)
           {
               p->Status = 1;
               cout<<"\n\n Your Appointment has been booked....!!!";
           }
           else
               cout<<"\n\n The Appointment slot is Busy....!!!";
           break;    
       }
       else
          p = p->Next;
   }
   
   if(p == NULL)
      cout<<"\n\n The Appointment slot is not available....!!!";
   
   Display_app(); 
}

void Cancel_appl()
{
    char Time[10];
    struct Node *p;
    
    cout<<"\n\n To cancel the appointment:";
    cout<<"\n\t Enter start time: ";
    cin>>Time;
    
    p=Head;
   
    while(p != NULL)
    {
        if(strcmp(Time, p->Start) == 0)
        {
            if(p->Status == 1) 
            {
               p->Status = 0;
               cout<<"\n\n Your appointment has been canceled..!!!";
            }
            else
               cout<<"\n\n The appointment slot was not booked..!!!";
            break;    
        } 
        else
           p = p->Next;
    }
   
    if(p == NULL)
       cout<<"\n\n The appointment slot is not available....!!!";
   
    Display_app(); 

}

void Sort()
{
    int i, tmp;
    char str[10];
    struct Node *p;
    
    for(i=0; i< nodes-1; i++)
    {
      p = Head;
      while(p->Next != NULL)
      {
        if(strcmp(p->Start, p->Next->Start) > 0)
        {
            		tmp = p->Status;
	          p->Status = p->Next->Status;
            p->Next->Status = tmp;

            strcpy(str , p->Start);            
            strcpy(p->Start , p->Next->Start);
            strcpy(p->Next->Start, str);            
            
            strcpy(str , p->End);            
            strcpy(p->End , p->Next->End);
            strcpy(p->Next->End, str);            


            strcpy(str , p->Min);            
            strcpy(p->Min , p->Next->Min);
            strcpy(p->Next->Min, str);            


            strcpy(str , p->Max);            
            strcpy(p->Max , p->Next->Max);
            strcpy(p->Next->Max, str);                        
        }
        else
           p = p->Next;
      }
      Display_app();
    }  
    
}

int main()
{
   int a;
   char ch;
   Create_app();
   Display_app();
   
   do
   {
   cout<<"\n\n\tDo you want to book the appointment?...Press-1\n\tDo you want to cancel the appointment?....Press-2\n\tDo you want to sort the appointments?...Press-3\n\t";
   cin>>a;
   
   switch(a)
   {
       case 1: Book_appl();
               break;
       case 2: Cancel_appl();
               break;
       case 3: Sort();   
               break;
       default: cout<<"Incorrect Option...!!!!!"; 
               break;
   }
   
   cout<<"\nDo you want to continue?...Press-Y\t";
   cin>>ch;
   }while(ch=='Y');
   
   
   return 0;
}

/*
student@ubuntu:~$ g++ Pr5_appointment.cpp -o a
student@ubuntu:~$ ./a


How many appointments?  4

 For Appointment 1 : 
	Enter start time:  14pm
	Enter end time:  15pm
	Enter miniumum duration:  30min
	Enter maximum duration:  1hr


 For Appointment 2 : 
	Enter start time:  13pm
	Enter end time:  14pm
	Enter miniumum duration:  45min
	Enter maximum duration:  1hr


 For Appointment 3 : 
	Enter start time:  10am
	Enter end time:  11am
	Enter miniumum duration:  30min
	Enter maximum duration:  1hr


 For Appointment 4 : 
	Enter start time:  11am
	Enter end time:  12pm
	Enter miniumum duration:  45min
	Enter maximum duration:  1hr



--------*** Appointments Schedule ***--------

	Status	Start	End	Min time	Max time
	Free	14pm	15pm	30min		1hr
	Free	13pm	14pm	45min		1hr
	Free	10am	11am	30min		1hr
	Free	11am	12pm	45min		1hr


	Do you want to book the appointment?...Press-1
	Do you want to cancel the appointment?....Press-2
	Do you want to sort the appointments?...Press-3
	1


 To Book the Appointment.....
	 Enter Start Time: 14pm


 Your Appointment has been booked....!!!

--------*** Appointments Schedule ***--------

	Status	Start	End	Min time	Max time
	Booked	14pm	15pm	30min		1hr
	Free	13pm	14pm	45min		1hr
	Free	10am	11am	30min		1hr
	Free	11am	12pm	45min		1hr

Do you want to continue?...Press-Y     Y


	Do you want to book the appointment?...Press-1
	Do you want to cancel the appointment?....Press-2
	Do you want to sort the appointments?...Press-3
	3


--------*** Appointments Schedule ***--------

	Status	Start	End	Min time	Max time
	Free	13pm	14pm	45min		1hr
	Free	10am	11am	30min		1hr
	Free	11am	12pm	45min		1hr
	Booked	14pm	15pm	30min		1hr


--------*** Appointments Schedule ***--------

	Status	Start	End	Min time	Max time
	Free	10am	11am	30min		1hr
	Free	11am	12pm	45min		1hr
	Free	13pm	14pm	45min		1hr
	Booked	14pm	15pm	30min		1hr


--------*** Appointments Schedule ***--------

	Status	Start	End	Min time	Max time
	Free	10am	11am	30min		1hr
	Free	11am	12pm	45min		1hr
	Free	13pm	14pm	45min		1hr
	Booked	14pm	15pm	30min		1hr

Do you want to continue?...Press-Y


*/












