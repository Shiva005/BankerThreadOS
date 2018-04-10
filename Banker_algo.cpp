#include<stdio.h>

int avail[][4]={1,5,2,0};
int alloc[5][4]={{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
int max[5][4]={{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
int need[5][4];
int main()
{
	int i,j,flag=0;
	printf("\n*** Max Table is ***\n");
	for(i=0;i<=4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d  ",max[i][j]);
		}
		printf("\n");
	}
	
	printf("\n*** Allocation Table is ***\n");
	for(i=0;i<=4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d  ",alloc[i][j]);
		}
		printf("\n");
	}
	
	printf("\n*** Need Matrix Table is ***\n");
	for(i=0;i<=4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d  ",max[i][j]-alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
		printf("\n");
	}
	
	printf("\n*** Available Matrix Table After each Allocation is ***\n");	
	for(i=0;i<=4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(need[i][j]<=avail[0][j])
			{
				avail[0][j]=avail[0][j]-need[i][j];
				avail[0][j]=avail[0][j]+max[i][j];
				printf("%d   ",avail[0][j]);
			}
		}
		printf("\n");
	}
	
	printf("\n*** Available Resources is ***\n");
	for(i=0;i<4;i++)
	{
		printf("%d  ",avail[0][i]);
	}
}
