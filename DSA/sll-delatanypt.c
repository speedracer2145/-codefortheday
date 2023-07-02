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
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");

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

struct node *DelAny(struct node *head,unsigned int pos)
{
    int c=0;
    struct node *temp,*curr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
        printf("Empty");
    else 
    {
        if(pos==1)
        {
            temp=head;
            head=head->next;
            free(temp);
        }
        else 
        {
            c=1;
            curr=head;
            while(c<pos-1 && curr->next!=NULL)
            {
                c++;
                curr=curr->next;
            } 
            if(curr->next==NULL)
            {
                printf("No node");
            }
            else
            {
                temp=curr->next;
                curr->next=temp->next;
                free(temp);
            }
        }
    }
}
int main()
{
    struct node * head=NULL;
    
  
    

    char ch;
    unsigned int pos;
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

            case 'd':
            scanf("%d",&pos);
            DelAny(head,pos);
            break;
        }
    }
}