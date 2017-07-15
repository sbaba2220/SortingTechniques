#include<stdio.h>
#include<stdlib.h>
void quick(int *,int,int);
int partition(int *,int,int);
void swap(int *,int *);
int main()
{
	int index,*arr,length;
	printf("Enter the size of the array\n");
	scanf("%d",&length);
	arr=(int*)malloc(sizeof(int)*length);
	printf("Enter the elements into array\n");
	for(index=0;index<length;index++)
	scanf("%d",(arr+index));
	quick(arr,0,length-1);
	printf("Elements in sorted order:\n");
	for(index=0;index<length;index++)
	printf("  %d",*(arr+index));
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void quick(int *arr,int start,int end)
{
	int pindex;
	if(start<end)
	{
		pindex=partition(arr,start,end);
		quick(arr,start,pindex-1);
		quick(arr,pindex+1,end);
	}
	return;
}
int partition(int *arr,int start,int end)
{
	int pindex=start,pivot=*(arr+end),index=start;
	while(index<end)
	{
		if(*(arr+index)<=pivot)
		{
			swap((arr+index),(arr+pindex));
			pindex++;
		}
		index++;
	}
	swap((arr+pindex),(arr+end));
	return pindex;
}
