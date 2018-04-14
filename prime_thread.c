#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int prime_arr[50];
void *prime()
{
	int init,finish,i,j,k=0,count=0;
	printf("Enter the starting number to calculate prime : ");
	scanf("%d",&init);
	printf("Enter the Ending number to calculate prime : ");
	scanf("%d",&finish);
	for(i=init;i<=finish;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				break;
			}
		}
		if(i==j)
		{
			count++;
			prime_arr[k]=i;
			k=k+1;
		}	
	}
	for(i=0;i<count;i++)
	{
		printf("%d\n",prime_arr[i]);
	}
}

int main()
{
	pthread_t thread1;
	pthread_create(&thread1,NULL,prime,NULL);
	pthread_join(thread1,NULL);
	pthread_exit(0);
}
