#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE], front = -1, rear = -1;

void insert(int data)
{
   if(front == -1 && rear == -1)
   {
      front = rear = 0;
   }
   if(rear == MAX_SIZE-1)
   {
      printf("Queue is full\n");
   }
   else
   {
      queue[rear] = data;
      rear++;
   }
}

void deleteElement()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("deleted item is %d\n", queue[front]);
        front++;
    }
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(int i = front; i < rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void sort()
{
    int temp;
    int i, j;
    for (i = front; i < rear; i++)
    {
        for (j = front; j < rear - 1; j++)
        {
            if (queue[j] < queue[j + 1]) 
            {
                temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}


int main()
{
    char ch;
    int d = 0, data;
    while(d != 1)
    {
        scanf(" %c", &ch);
        switch(ch)
        {
            case 'a':
            {
               scanf("%d", &data);
               insert(data);
               sort();
               break;
            }
            case 'b':
            {
                d=1;
               deleteElement();
               break;
            }
            case 'c':
            {
               d = 1;
               display();
               break;
            }
            default:
               printf("Invalid choice\n");
        }
    }

    return 0;
}