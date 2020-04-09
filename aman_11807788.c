#include<stdio.h>
#include<conio.h>
int Comp_time,Take_time=0,Flag =-1,i=-1;
struct take_process
{
	int Process_id,Burst_time,Arrival_time,Priority_num,Waiting_time;
}Create_process[10],Process_queue[20],flag,Final_queue[10];

int process_create()
{
	int n;
	printf("enter the number of process : ");
	scanf("%d",&n);
	printf("\n");
	return n;
}
//function to execute the process and finish it


/*to give the process id,burst time,arrival time
and sort the array according to arrival time and if arrival time is equal
then sort according to burst time in main*/

int Take_input()
{
	int i,j,num=No_Process();
	
	for(i=0;i<num;i++)
	{
		Create_process[i].Process_id=(i+1);
		printf("\nEnter the arrival time of process[%d]: ",(i+1));
		scanf("%d",&Create_process[i].Arrival_time);
		printf("Enter the burst time of process[%d]: ",(i+1));
		scanf("%d",&Create_process[i].Burst_time);
		Create_process[i].Priority_num=0;
		Create_process[i].Waiting_time=0;
		Take_time=Take_time+Create_process[i].Burst_time;
	}
	
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(Create_process[i].Arrival_time==Create_process[j].Arrival_time)
			{
				if(Create_process[i].Burst_time<=Create_process[j].Burst_time)
				{
				flag=Create_process[i];
				Create_process[i]=Create_process[j];
				Create_process[j]=flag;
				}
			}
			else if(Create_process[i].Arrival_time<Create_process[j].Arrival_time)
			{
				flag=Create_process[i];
				Create_process[i]=Create_process[j];
				Create_process[j]=flag;
			}
			
	    }
	}
	return num;
}

int display()
{
	int l,j,count=0;
	int n=Take_input();
	//	printing the sorted process id with respect to arrival time and if arrival time is equal than burst time.
	printf("VALUES ENTERED:\n*(TABLE SORTED ACCORDING TO THE AARIVAL TIME)\n\n");
	printf("               PROCESS TABLE \n");
	printf("\n.............................................\n");
	printf(" PROCESS ID           ARRIVAL TIME        SERVICE TIME \n");
	printf("\n.............................................\n");
	for(l=0;l<n;l++)
	{
		printf(" %d            	   %d                   %d\n",Create_process[l].Process_id,Create_process[l].Arrival_time,Create_process[l].Burst_time );
	}
	Comp_time=Create_process[0].Arrival_time;
	for(j=Create_process[0].Arrival_time;j<=Create_process[n-1].Arrival_time;j++)
	{
		for(l=0;l<n;l++)
		{
			if(Create_process[l].Arrival_time==j && count!=n)
			{
				Flag++;
				Process_queue[Flag]=Create_process[l];
				count++;
			}
			if(count==n)
				break;
		}
		Round_Robin_algo();
		Comp_time++;
	while(Take_time!=0 && count==n)
	{
		Round_Robin_algo();
		Comp_time++;
	}
	if(count==n)
		break;
	}
	return n;
}



void main()
{
	display();
}
