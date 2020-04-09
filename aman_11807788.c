#include<stdio.h>
#include<conio.h>
struct take_process
{
	int Process_id;
}pcreate[10],queue[20],swap;
int burst_time=0; 

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

int input()
{
	int n=process_create();
	int l,j;

	for(l=0;l<n;l++)
	{
		pcreate[l].Process_id=l+1;
		printf("\nEnter the arrival time of process[%d]: ",l+1);
		scanf("%d",&pcreate[l].Arrival_time);
		printf("Enter the burst time of process[%d]: ",l+1);
		scanf("%d",&pcreate[l].Burst_time);
		pcreate[l].Priority_num=0;
		pcreate[l].Waiting_time=0;
		burst_time=burst_time+pcreate[l].Burst_time;
	}
	for(l=0;l<n;l++)
	{
		for(j=0;j<n;j++)
		{
		if(pcreate[l].Arrival_time<pcreate[j].Arrival_time)
		{
			swap=pcreate[l];
			pcreate[l]=pcreate[j];
			pcreate[j]=swap;
		}
		if(pcreate[l].Arrival_time==pcreate[j].Arrival_time)
		{
			if(pcreate[l].Burst_time<=pcreate[j].Burst_time)
			{
			swap=pcreate[l];
			pcreate[l]=pcreate[j];
			pcreate[j]=swap;
			}
	 	}
	    }
	}
	return n;
}





void main()
{
	input();
}
