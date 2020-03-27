#include <stdlib.h>
#include <stdio.h>

int main()
{
int Allocated[10][10], Max[10][10], Need[10][10], Available[10], Completed[10];
int p, r, i, j, process, count;
count = 0;

printf("Enter the number of processes : ");
scanf("%d", &p);

for(i = 0; i< p; i++)
	{
		Completed[i] = 0;
	}
printf("\n\nEnter the number of different type resources( if same type enter one ) : ");
scanf("%d", &r);

printf("\n\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ",i + 1);
	for(j = 0; j < r; j++)
		{
			scanf("%d", &Allocated[i][j]);
		}
}

printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j < r; j++)
		{
			scanf("%d", &Max[i][j]);
		}
}

printf("\n\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
		{
		scanf("%d", &Available[i]);	
		}

for(i = 0; i < p; i++)
	{
		for(j = 0; j < r; j++)
			{
				Need[i][j] = Max[i][j] - Allocated[i][j];
			}
	}
do
{
	printf("\n Max matrix:\tAllocation matrix:\n");
	for(i = 0; i < p; i++)
	{
		for( j = 0; j < r; j++)
			printf("%d  ", Max[i][j]);
		printf("\t\t");
		for( j = 0; j < r; j++)
			printf("%d  ", Allocated[i][j]);
		printf("\n");
	}

	process = -1;

	for(i = 0; i < p; i++)
	{
		if(Completed[i] == 0)
		{
			process = i ;
			for(j = 0; j < r; j++)
			{
				if(Available[j] < Need[i][j])
				{
					process = -1;
					break;
				}
			}
		}
		if(process != -1)
			break;
	}

	if(process != -1)
	{
		printf("\nProcess %d runs to completion : ", process + 1);
		count++;
		for(j = 0; j < r; j++)
		{
			Available[j] += Allocated[process][j];
			Allocated[process][j] = 0;
			Max[process][j] = 0;
			Completed[process] = 1;
		}
	}
}while(count != p && process != -1);

if(count == p)
{
	printf("\n\nThe system is in a safe state\n");
}
}
