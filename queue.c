# include <stdio.h>
void main()
{
	int front=-1,rear=-1,n,choice=0,max,num;
	printf("Enter the size of the Queue: ");
	scanf("%d",&n);
	max=n-1;
	int queue[n];
	do
	{
		printf("\n1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		printf("\n");
		switch (choice)
        	{
            	case 1:
			printf("Enter the number to insert: ");
			scanf("%d",&num);
			if(front==-1&&rear==-1)
			{
				front=rear=0;
				queue[rear]=num;
				printf("Element Inserted\n");
			}
			else if(rear==max)
			{
				printf("Queue Overflow\n");
			}
			else
			{
				rear+=1;
				queue[rear]=num;
				printf("Element Inserted\n");
			}
                	break;
            	case 2: 
                	if(front==-1)
				printf("Queue Underflow\n");
			else if(front==rear)
			{
				printf("Deleted Element: %d\n",queue[front]);
				front=rear=-1;
			}		
			else
			{
				printf("Deleted Element: %d\n",queue[front]);
				front++;
			}		
                	break;
            	case 3:
                	if(front==-1 && rear==-1)
				printf("No Element in Queue to Display\n");
			else
			{
				for(int i=front;i<=rear;i++)
					printf("Element in Queue : %d\n",queue[i]);
			}
                	break;
            	case 4:
                	printf("Exiting..\n");
                	break;
            	default:
                	printf("Enter a valid choice\n");
                	break;
        	}
    	} while (choice!=4);
}

	
