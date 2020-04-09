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
void bar()
{
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
	Sleep(111);system("cls");New(6);star(110);New(1);
	tab(5);printf("The Data that you have Entered.");
}
//function to execute the process and finish it


/*to give the process id,burst time,arrival time
and sort the array according to arrival time and if arrival time is equal
then sort according to burst time in main*/
void Round_Robin_algo()
{
	if(Flag>=0)
	{
		int wait,j;
		//to increase the Priority_numity and decrease the burst time of Priority_numity in excecution
		if(Take_time!=0 && Process_queue[0].Burst_time!=0)
		{
			Process_queue[0].Burst_time--;
			Take_time--;
			Process_queue[0].Priority_num++;
			Process_queue[0].Arrival_time=Comp_time+1;
			Comp_time++;
		//to increase the wait and Priority_numity of waiting process	
			for(wait=1;wait<=Flag;wait++)
			{
				Process_queue[wait].Priority_num+=2;
				Process_queue[wait].Waiting_time=++Process_queue[wait].Waiting_time;
			}
		}
		//if process gets completed ,it is put in Final_queue Process_queue
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
		//to sort the process again in by Priority_numity
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
	system("cls");
	int l,j,count=0,n=Take_input();
	//	printing the sorted process id with respect to arrival time and if arrival time is equal than burst time.
	bar();
	printf("\n");star(110);New(1);
	line(110);
	tab(2);printf("PROCESS ID");tab(2);printf("ARRIVAL TIME");tab(2);printf("SERVICE TIME\n");
	
	for(l=0;l<n;l++)
	{
		tab(2);printf("   P%d",Create_process[l].Process_id);tab(3);printf("   %d",Create_process[l].Arrival_time);tab(3);printf("   %d\n",Create_process[l].Burst_time );
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
	return n;
}



void main()
{
	display();
}
