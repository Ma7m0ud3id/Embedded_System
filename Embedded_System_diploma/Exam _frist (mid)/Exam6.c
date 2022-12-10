/*
 * Exam6.c
 *
 *  Created on: Dec 2, 2022
 *      Author: mahmo
 */

#include <stdio.h>
int unique(int arr[],int size);
int main()
{
	int arr[100],size;
	printf("Enter size of array : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);
	printf("Enter elements of array : ");
	fflush(stdin); fflush(stdout);
	for(int i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("unique number is: %d",unique(arr,size));
	return 0;
}
int unique(int arr[],int size)
{int num,flag=0;
	for(int i=0;i<size;i++)
	{
		num=arr[i];
		flag=0;
		for(int j=0;j<size;j++)
		{
			if(i==j)
			{
				continue;
			}
			else if(arr[j]==num)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			return num;
		}
	}
	return -1;
}
