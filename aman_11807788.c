#include<stdio.h>
#include<conio.h>
#include<windows.h>

int No_Process();

int Comp_time,Take_time=0,Flag =-1,i=-1;
struct take_process
{
	int Process_id,Burst_time,Arrival_time,Priority_num,Waiting_time;
}Create_process[10],Process_queue[20],flag,Final_queue[10];

int No_Process()
{
	int num;
	printf("Enter the number of process : ");
	scanf("%d",&num);
	printf("\n");
	system("color 57");
	return num;
}

void tab(int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("\t");
	}
}
void star(int d)
{
	int i;
	for(i=0;i<d;i++)
	printf("*");
}
void New(int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf("\n");
	}
}
void line(int x)
{
	int i;
	printf("\n");
	for(i=0;i<x;i++)
	printf("_");
	printf("\n");
}

int Take_input()
{
	int i,j,num=No_Process();
	
	for(i=0;i<num;i++)
	{
		Create_process[i].Process_id=(i+1);
		printf("\nEnter Arrival time for process[%d]: ",(i+1));
		scanf("%d",&Create_process[i].Arrival_time);
		printf("Enter Burst time for process[%d]: ",(i+1));
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
	system("cls");
	return num;
}

void Round_Robin_algo()
{
	if(Flag>=0)
	{
		int wait,j;
		if(Take_time!=0 && Process_queue[0].Burst_time!=0)
		{
			Process_queue[0].Burst_time--;
			Take_time--;
			Process_queue[0].Priority_num++;
			Process_queue[0].Arrival_time=Comp_time+1;
			Comp_time++;
			for(wait=1;wait<=Flag;wait++)
			{
				Process_queue[wait].Priority_num+=2;
				Process_queue[wait].Waiting_time=++Process_queue[wait].Waiting_time;
			}
		}
		if(Process_queue[0].Burst_time==0)
		{
			i++;
			Final_queue[i]=Process_queue[0];
			for(wait=0;wait<Flag;wait++)
			{
				Process_queue[wait]=Process_queue[wait+1];
			}
			Flag--;
		}
		for(wait=0;wait<Flag;wait++)
		{
			for(j=0;j<Flag;j++)
			{
				if(Process_queue[wait].Priority_num<=Process_queue[j].Priority_num)
				{
					flag=Process_queue[wait];
					Process_queue[wait]=Process_queue[j];
					Process_queue[j]=flag;
				}
			}
		}
		if(Process_queue[0].Priority_num<=Process_queue[1].Priority_num && Flag>=1)
		{
			flag=Process_queue[0];
			for(wait=0;wait<Flag;wait++)
			{
				Process_queue[wait]=Process_queue[wait+1];
			}
			Process_queue[Flag]=flag;
		}
	}
}


void bar()
{
	system("color 07");
	New(7);
	tab(5);printf("Displaying the data, Please Wait...\\");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait.../");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...\\");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait.../");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...\\");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait.../");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...\\");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait.../");
	Sleep(111);system("cls");New(7);
	tab(5);printf("Displaying the data, Please Wait...|");
	Sleep(111);system("cls");system("color F1");New(6);star(110);New(1);
	tab(5);printf("The Data that you have Entered.");
}



int display()
{
	system("cls");
	int l,j,count=0,n=Take_input();
	bar();
	printf("\n");star(110);New(1);
	line(110);
	tab(3);printf("PROCESS ID");tab(3);printf("ARRIVAL TIME");tab(3);printf("BURST TIME\n");
	
	for(l=0;l<n;l++)
	{
		tab(3);printf("   P%d",Create_process[l].Process_id);tab(4);printf("    %d",Create_process[l].Arrival_time);tab(4);printf("    %d\n",Create_process[l].Burst_time );
	}
	line(110);
	Comp_time=Create_process[0].Arrival_time;
	for(j=Create_process[0].Arrival_time;j<=Create_process[n-1].Arrival_time;j++)
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
	printf("\n\t\t\t\t\tEnter any Key to Continue...\n");
	getch();
	system("cls");
	return n;
}

void display_result()
{
	
	int l,j,count=0;
	int n=display();
	float averageWaitTime=0;
	New(6);star(110);New(1);tab(5);printf("After Execution the Final Table\n");
	star(110);
	New(1);
	line(110);
	tab(2);printf("PROCESS ID");tab(2);printf("ARRIVAL TIME");tab(2);printf("BURST TIME");tab(2);printf("WAITING TIME\n");
	
	for(l=0;l<n;l++)
	{
		for(j=0;j<n;j++)
		{
			if(Final_queue[l].Process_id==Create_process[j].Process_id)
			{
				tab(2);printf("   P%d",Final_queue[l].Process_id);tab(3);printf("    %d",Create_process[l].Arrival_time);tab(3);printf("    %d",Create_process[l].Burst_time );tab(3);printf("    %d\n",Final_queue[l].Waiting_time);
			}
		}
		averageWaitTime+=(Final_queue[l].Waiting_time);
	}
	line(110);
	New(1);tab(5);
	printf("AVERAGE  WAITING  TIME :%.2f\n",(averageWaitTime/n));
	line(110);
	return 0;
	
}


void main()
{
	display_result();
	return 0;
}
