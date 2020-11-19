#include<stdio.h>
void main()
{
	int a[]={256,712,763,10,48,212,371,2};
	int n=sizeof(a)/sizeof(int);
	int i;
	printf("Elements before sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	radixSort(a,n);
	printf("\nElements after sorting : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void radixSort(int* a,int size)
{
	int i,max=0;
	for(i=0;i<size;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	for(i=1;(max/i);i*=10)
	{
		countSort(a,size,i);
	}
}
void countSort(int *a,int size,int divisor)
{
	int i,countArr[10];
	for(i=0;i<10;i++)
		countArr[i]=0;
	for(i=0;i<size;i++)
		countArr[(a[i]/divisor)%10]+=1;
	for(i=0;i<10;i++)
		countArr[i+1]+=countArr[i];
	int* b=(int*)malloc(size*sizeof(int));
	for(i=size-1;i>=0;i--)
	{
		b[countArr[(a[i]/divisor)%10]-1]=a[i];
		countArr[(a[i]/divisor)%10]-=1;
	}
	for(i=0;i<size;i++)
		a[i]=b[i];
	free(b);
}
