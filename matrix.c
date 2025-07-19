#include <stdio.h>
void sum();
void transpose();
void main()
{
	int m1r,m1c,m2r,m2c,c1=0,c2=0,choice;
	printf("Enter the number of rows of Matrix 1: ");		
	scanf("%d",&m1r);
	printf("Enter the number of columns of Matrix 1: ");		
	scanf("%d",&m1c);
	printf("Enter the number of rows of Matrix 2: ");		
	scanf("%d",&m2r);
	printf("Enter the number of columns of Matrix 2: ");		
	scanf("%d",&m2c);
	int A[m1r][m1c],B[m2r][m2c];
	printf("\nFIRST MATRIX\n");
	for(int i=0;i<m1r;i++)
	{
		for(int j=0;j<m1c;j++)
		{
			printf("Element at position %d*%d of Matrix 1 = ",i+1,j+1);
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n");
	printf("SECOND MATRIX\n");
	for(int i=0;i<m2r;i++)
	{
		for(int j=0;j<m2c;j++)
		{
			printf("Element at position %d*%d of Matrix 2 = ",i+1,j+1);
			scanf("%d",&B[i][j]);
		}
	}
	printf("\n");
	printf("FIRST MATRIX\n");
	for(int i=0;i<m1r;i++)
	{
		for(int j=0;j<m1c;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("SECOND MATRIX\n");
	for(int i=0;i<m2r;i++)
	{
		for(int j=0;j<m2c;j++)
		{
			printf("%d\t",B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<m1r;i++)
	{
		for(int j=0;j<m1c;j++)
		{
			if((A[i][j])!=0)
				c1+=1;
		}
	}
	for(int i=0;i<m2r;i++)
	{
		for(int j=0;j<m2c;j++)
		{
			if(B[i][j]!=0)
				c2+=1;
		}	
	}
	int s1[c1+1][3],s2[c2+1][3];
	s1[0][0]=m1r;
	s1[0][1]=m1c;
	s1[0][2]=c1;
	s2[0][0]=m2r;
	s2[0][1]=m2c;
	s2[0][2]=c2;
	
	int b=1;
	for(int i=0;i<m1r;i++)
	{
		for(int j=0;j<m1c;j++)
		{
			if((A[i][j])!=0)
			{
				s1[b][0]=i;
				s1[b][1]=j;
				s1[b][2]=A[i][j];
				b++;
			}
		}
	}
	b=1;
	for(int i=0;i<m2r;i++)
	{
		for(int j=0;j<m2c;j++)
		{
			if((B[i][j])!=0)
			{
				s2[b][0]=i;
				s2[b][1]=j;
				s2[b][2]=B[i][j];
				b++;
			}
		}
	}
	printf("FIRST SPARSE MATRIX\n");
	printf("ROW\tCOLUMN\tVALUE\n");
	for(int i=0;i<c1+1;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",s1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("SECOND SPARSE MATRIX\n");
	printf("ROW\tCOLUMN\tVALUE\n");
	for(int i=0;i<c2+1;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",s2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	do
	{
		printf("1. Add the two matrices\n2. Find transpose of matrix 1\n3. Find transpose of matrix 2\n4. Exit \n\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				sum(s1,s2);
				break;
			case 2:
				transpose(s1);
				break;
			case 3:
				transpose(s2);
				break;
			case 4:
				printf("EXITING...");
				break;
			default:
				printf("INVALID CHOICE \n\n");
		}
	}while(choice!=4);


}
void sum(int s1[][3], int s2[][3])
	{
		int r1 = s1[0][0], c1 = s1[0][1], n1 = s1[0][2];
		int r2 = s2[0][0], c2 = s2[0][1], n2 = s2[0][2];

    	if (r1 != r2 || c1 != c2) 
    	{
        	printf("DIMENSIONS DOESN'T MATCH! CAN'T ADD.\n");
			printf("\n");
        	return;
   	}
    int s3[n1+n2+1][3];
  	s3[0][0] = r1;
   	s3[0][1] = c1;
	int k = 1;
	for (int i = 1; i <= n1; i++)
	{
       		s3[k][0] = s1[i][0];
        	s3[k][1] = s1[i][1];
        	s3[k][2] = s1[i][2];
        	k++;
    }
    for (int i = 1; i <= n2; i++)
    {
        int row = s2[i][0];
        int col = s2[i][1];
        int val = s2[i][2];
        int found = 0;
        for (int j = 1; j < k; j++) 
        {
            	if (s3[j][0] == row && s3[j][1] == col) 
            	{
            		s3[j][2] += val;
                	found = 1;
                	break;
            	}
        }
        if (!found) 
        {
            	s3[k][0] = row;
            	s3[k][1] = col;
           	    s3[k][2] = val;
            	k++;
        }
	}
    s3[0][2] = k - 1;
    printf("RESULTANT SPARSE MATRIX\nROW\tCOLUMN\tVALUE\t\n");
    for (int i = 0; i < k; i++) 
    {
        printf("%d\t%d\t%d\n", s3[i][0], s3[i][1], s3[i][2]);
    }
	printf("\n");
}


void transpose(int s[][3]) 
{
    int rows = s[0][0];
    int cols = s[0][1];
    int value = s[0][2];

    int t[value + 1][3];
    t[0][0] = cols; 
    t[0][1] = rows;
    t[0][2] = value;

    int k = 1;
    for (int col = 0; col < cols; col++) 
	{
        for (int i = 1; i <= value; i++) 
		{
			if (s[i][1] == col)
			{
                t[k][0] = s[i][1]; 
                t[k][1] = s[i][0]; 
                t[k][2] = s[i][2];
                k++;
			}
            
        }
    }

    printf("TRANSPOSE OF SPARSE MATRIX\nROW\tCOLUMN\tVALUE\n");
    for (int i = 0; i <= value; i++) 
	{
        printf("%d\t%d\t%d\n", t[i][0], t[i][1], t[i][2]);
    }
    printf("\n");
}

    
