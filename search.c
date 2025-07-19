#include <stdio.h>
void linearSearch();
int binarySearch();
int binary();
void main()
{
	int n,c=0;
	printf("Enter number of elemnts to enter : ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter number %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\n");

	do
	{
		printf("Enter 1 to do Linear Search \nEnter 2 to do Binary Search \nEnter 3 to Exit \n\n");
		printf("Enter your Choice : ");
		scanf("%d",&c);
		printf("\n");
	
		switch(c)
		{
			case 1:
				linearSearch(n,arr);
				break;
			case 2:
				binarySearch(n,arr);
				break;
			case 3:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid input\n");
				break;
		}
	}while(c!=3);
}


void linearSearch(int n, int arr[])
{
	int flag=0,num;
	printf("Enter number to search : ");
	scanf("%d",&num);
	for(int i=0;i<n;i++)
	{
		if (num==arr[i])
		{
			flag=1;
			printf("Position of number is %d\n\n",i+1);
			break;
		}
	}
	if (flag!=1)
		printf("Number not found \n\n");
}


int binarySearch(int n,int arr[])
{
	int num,temp,l,h,flag;
	printf("Enter number to search : ");
	scanf("%d",&num);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if (arr[i]<arr[j])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	l=0;
	h=n-1;
	flag = binary(l,h,num,arr);
	if (flag!=1)
		printf("Number not found \n\n");			
}


int binary(int l,int h,int num,int arr[])
{
	int mid,flag;
	mid=(l+h)/2;
	while(l<h)
	{
		if (num==arr[mid])
		{
			printf("Position of number is %d \n\n",mid+1);
			flag=1;
			return flag;
		}
		else if (arr[mid]<num)
		{
			l=mid+1;
			return binary(l,h,num,arr);
		}
		else if (arr[mid]>num)
		{
			h=mid-1;
			return binary(l,h,num,arr);
		}
	}
}
