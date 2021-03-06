#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1E9

int cmp;
int LinSearch(int array[], int,int);


void main()
{
	struct timespec start, end;
	double totaltime = 0;
	int n,i,j,key;
	printf("For a Linear Search Algorithm\n\n\n");
	for(j=0;j<5;j++)
	{
		scanf("%d",&n);
		int array[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&array[i]);

		}
		for(i=0;i<1000;i++)
		{
			scanf("%d",&key);

			clock_gettime(CLOCK_REALTIME, &start);
			int pos = LinSearch(array,n,key);
			clock_gettime(CLOCK_REALTIME, &end);

			double accum = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/BILLION;
			totaltime += accum;


		}
		printf("In an array with %d elements\n",n);
		printf("The avg. time for searching is  %lfs \n",totaltime/1000);
		printf("The avg. no of comparisons is  %d\n\n\n",cmp/1000);
		cmp = 0;
	}
}


int LinSearch(int list[],int size,int key)
{	
	int i;
	for(i=0;i<size;i++)
	{	
		cmp+=1;
		if(list[i]==key)
		{
			return i;
		}	
	}
	return -1;
}
