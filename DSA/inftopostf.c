#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 100

char stack[n];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == n - 1;
}

void push(char ch)
{
    if (!isFull())
    {
        top = top + 1;
        stack[top] = ch;
    }
}

char peek()
{
    if (!isEmpty())
    {
        return stack[top];
    }
    return '\0'; // Return null character if stack is empty
}

char pop()
{
    if (!isEmpty())
    {
        char ch = stack[top];
        top = top - 1;
        return ch;
    }
    return '\0'; // Return null character if stack is empty
}

int opcheck(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void itop(char infix[])
{
    int j = -1;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (opcheck(infix[i]))
        {
            printf("%c", infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (peek() != '(' && !isEmpty())
            {
                printf("%c", pop());
            }
            if (peek() == '(')
            {
                pop(); // Discard the opening parenthesis
            }
        }
        else
        {
            while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
            {
                printf("%c", pop());
            }
            push(infix[i]);
        }
    }
    while (!isEmpty())
    {
        printf("%c", pop());
    }
}

int main()
{
    char infix[n];
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    printf("Postfix Expression:\n");
    itop(infix);
    return 0;
}
