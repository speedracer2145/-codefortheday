#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void Access(struct node * head)
{
    struct node * temp=head;
     printf("Elements in the linked list :\n");
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);

}

struct node * insFirst(struct node * head,int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    new->next=head;
    new->data=data;
    return new;

}

struct node * insEnd(struct node * head,int data)
{
    struct node * new=(struct node *)malloc(sizeof(struct node));
    struct node * a=(struct node *)malloc(sizeof(struct node));
    a=head;
    new->data=data;
    new->next=NULL;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    a->next=new;
    
    return head;

}




int main()
{
    struct node * head=NULL;
    
  
    

    char ch;
    
    int n;
    int d=0;
 while(d!=1)
    {
        ch=getchar();
        switch(ch)
        {

            case 'b':
            
            scanf("%d ",&n);
            
            head=insFirst(head,n);
            break;

            case 'c':
            
            scanf("%d ",&n);
            
            insEnd(head,n);
            break;

            case 'a':
            Access(head);
            d=1;
            break;
        }
    }
}