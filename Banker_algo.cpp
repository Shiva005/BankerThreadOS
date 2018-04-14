
#include<iostream>
using namespace std;
void calculateNeed(int need[5][4], int max[5][4],int alloc[5][4])
{		  
	int i,j; 
    for (i = 0 ; i < 5 ; i++)
        for (j = 0 ; j < 4 ; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    
    printf("\n\n  The NEED Matrix is :\n\n");
    for (int i = 0 ; i < 5 ; i++)
    {
    	for (int j = 0 ; j < 4 ; j++)
    	{
    		printf("\t%d",need[i][j]);
		}
		printf("\n"); 
	}
            
        
}
bool checkSafety(int processes[], int avail[], int max[][4],int alloc[][4])
{
    int need[5][4];
    calculateNeed(need, max, alloc);
    bool finish[5] = {0};
    int safeSeq[5];
    int work[4];
    for (int i = 0; i < 4 ; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < 5)
    {
        bool found = false;
        for (int p = 0; p < 5; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < 4; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == 4)
                {
                    for (int k = 0 ; k < 4 ; k++)
                        work[k] += alloc[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (found == false)
        {
            printf(" \n\n  System is not in safe state");
            return false;
        }
    }
    
    printf("\n  System is in safe state.\n\n  Safe sequence is : ");
	
    for (int i = 0; i < 5 ; i++)
    {
    	printf ("\t%d", safeSeq[i]);
	}
        
    return true;
}
int main()
{   
	int processes[] = {0, 1, 2, 3, 4};
    int avail[] = {1,5,2,0};
    int max[5][4]={{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};
    int alloc[5][4]={{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
    
	printf("\n\n  The Initial Available Resource is : \n\n");
	for(int i=0;i<4;i++)
	{
		printf("\t%d",avail[i]);
	}
	
	printf("\n\n  The MAX Table is : \n\n");
	for(int i=0;i<5;i++)
    {
    	for(int j=0;j<4;j++)
    	{
    		printf("\t%d  ",max[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n  The Allocation Table is :\n\n");
	for(int i=0;i<5;i++)
    {
    	for(int j=0;j<4;j++)
    	{
    		printf("\t%d  ",alloc[i][j]);
		}
		printf("\n");
	}
	
    checkSafety(processes, avail, max, alloc);
    return 0;
}
