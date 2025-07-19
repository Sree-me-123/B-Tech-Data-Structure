#include <stdio.h>
void main()
{
	int n,deg;
	printf("Enter number of polynomial needed to add : ");
	scanf("%d",&n);
	printf("\n");
	int arr[n][50];
	int sum[50]={0};
	for(int i=0;i<n;i++)
	{
		printf("Enter degree of polynomial %d : ",i+1);
		scanf("%d",&deg);
		for(int j=0;j<50;++j)
		{
			arr[i][j]=0;
		}
		for(int j=deg;j>=0;--j)
		{
			printf("Enter the coefficient of x^%d : ",j);
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<50;j++)
		{
			sum[j]+=arr[i][j];
		}
	}
	for (int i=0;i<n;i++)
	{
		printf("POLYNOMIAL %d : ",i+1);
		int print=0;
		for(int j=49;j>=0;j--)
		{
			if(arr[i][j]!=0)
			{
				if (print)
					printf("+ ");
				printf("%dx^%d ",arr[i][j],j);
				print=1;
			}
		}
		printf("\n");
	}	
	printf("\n");
	printf("SUM :");
	int print=0;
	for(int i=49;i>=0;i--)
	{
		if(sum[i]!=0)
		{
			if (print)
				printf("+ ");
			printf("%dx^%d ",sum[i],i);
			print=1;
		}
	}
	printf("\n");
}

