
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    int * a;

};

int stop(struct stack *s)
{
return s->a[s->top];
}

int isfull(struct stack *s)
{
     if(s->top==s->size-1)
    {
        printf("Stack overflow");
        return 1;
    }
    return 0;    

}

int isempty(struct stack *s)
{
    if(s->top==-1)
    {
       
                
                
                return 1;
                }
               
    
    return 0;
}

void push(struct stack *s , char value)
{
    if(isfull(s))
    {
         printf("Unsuccessful push");
        
    }
    else{
        s->top++;
        s->a[s->top]=value;
       
    }

}

char pop(struct stack *s)
{
   int value;

    if(!isempty(s))
    {
        value=s->a[s->top--];
        
        
        
    }
    
    return value;
    

}





int isoperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='/'||ch=='*')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int evalpos(char * infix)
{
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->a=(int *)malloc(sizeof(int)*s->size);
int res,i;
    for(i=0;infix[i]!='\0';i++)
    {
        int a,b;
        if(isoperator(infix[i]))
        {
            b=pop(s);
            a=pop(s);
            switch (infix[i]) {
            case '+':
                push(s, a+b);
                break;
            case '-':
                push(s, a-b);
                break;
            case '*':
                push(s, a*b);
                break;
            case '/':
                push(s, a/b);
                break;
            }
            
            

            

        }
        else
        {
            push(s,infix[i]-'0');
            
        }
    
    }
    return pop(s);
}


int main()
{
       char  infix[20];
     scanf("%s",infix);
     printf("The result is: %d",evalpos(infix));

}