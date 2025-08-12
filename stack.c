#include <stdio.h>
int push();
int pop();
void display();
void main()
{
    int num,choice=0,top=-1;
    printf("Enter the size of stack: ");
    scanf("%d",&num);
    int stack[num];
    int max=(num-1);
    do
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                top=push(stack,max,top);
                break;
            case 2: 
                top=pop(stack,max,top);
                break;
            case 3:
                display(stack,top);
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
int push(int stack[],int max,int top)
{
    int n;
    printf("Enter the element to push: ");
    scanf("%d",&n);
    if(top==max)
    {
        printf("Stack overflow\n");
        return top;
    }
    else if(top==-1)
    {
        top=0;
        stack[top]=n;
        printf("Element inserted to stack\n");
        return top;
    }
    else
    {
        top+=1;
        stack[top]=n;
        printf("Element inserted to stack\n");
        return top;
    }
}
int pop(int stack[],int max,int top)
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return top;
    }
    else
    {
        int n=stack[top];
        top-=1;
        printf("Popped element : %d\n",n);
        return top;
    }
}
void display(int stack[],int top)
{
    if(top==-1)
    	printf("No elemnt in stack to display\n");
    else
    {
    	for(int i=top;i>=0;i--)
    	{
        	printf("Element in stack: %d\n",stack[i]);
    	}
    }
}


