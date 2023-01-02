#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "colours.h"

#define MAXSIZE 50
char infix[MAXSIZE], postfix[MAXSIZE], tmpStack[MAXSIZE];
int tmpTop = -1, postTop = -1;

// checks if stack is full
int isFull(char stack[], int *top, char size)
{
    if (*top >= size)
        return 1;
    else
        return 0;
}

// checks if stack is Empty
int isEmpty(char stack[], int *top)
{
    if (*top == -1)
        return 1;
    else
        return 0;
}

// Push element into *top of stack
int push(char stack[], int *top, char data, int size)
{
    if (!isFull(stack, &*top, size))
    {
        stack[++*top] = data;
        return stack[*top];
    }
}

// Pop the *top element
int pop(char stack[], int *top)
{
    if (!isEmpty(stack, &*top))
        return stack[(*top)--];
    else
        return 0;
}

// Peek the top element
int peek(char stack[], int *top)
{
    if (!isEmpty(stack, &*top))
        return stack[*top];
    else
        return 0;
}
// display the elements in the stack
void displayStack(char stack[], int *top)
{
    if (!isEmpty(stack, &*top))
    {
        int i;
        for (i = 0; i <= *top; i++)
        {
            printf("%c", stack[i]);
        }
        printf("\n");
    }
}

void help()
{
    printf("Options:(case sensitive)\n");
    printf("push <expression>   Push an expression to obtain its postfix\n");
    printf("clear               Clear the Terminal screen\n");
    printf("exit                Exits the program\n");
}
int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    return 0;
}
void infixtopostfix()
{
    int i;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
            push(postfix, &postTop, infix[i], MAXSIZE);
        else if (infix[i] == '(')
            push(tmpStack, &tmpTop, infix[i], MAXSIZE);
        else if (infix[i] == ')')
        {
            while (tmpStack[tmpTop] != '(')
                push(postfix, &postTop, pop(tmpStack, &tmpTop), MAXSIZE);
            pop(tmpStack, &tmpTop);
        }
        else if (isEmpty(tmpStack, &tmpTop))
            push(tmpStack, &tmpTop, infix[i], MAXSIZE);
        else
        {
            if (priority(peek(tmpStack, &tmpTop)) >= priority(infix[i]))
                push(postfix, &postTop, pop(tmpStack, &tmpTop), MAXSIZE);
            push(tmpStack, &tmpTop, infix[i], MAXSIZE);
        }
    }
    while (!isEmpty(tmpStack, &tmpTop))
        push(postfix, &postTop, pop(tmpStack, &tmpTop), MAXSIZE);
}
void main()
{
    int n, i;
    char cmd[10];
    system("clear"); // clears the terminal for a CLI-like interface
    help();
    while (1)
    {
        printf(YEL ">>>> " RESET);
        scanf("%s", cmd);
        if (!strcmp("push", cmd))
        {
            tmpTop = -1;
            postTop = -1;
            scanf("%[^\n]s", infix);
            infixtopostfix();
            displayStack(postfix, &postTop);
        }
        else if (!strcmp("help", cmd))
            help();
        else if (!strcmp("clear", cmd))
            system("clear");
        else if (!strcmp("exit", cmd))
            break;
        else
        {
            printf(RED "Enter a valid choice\n");
            help();
        }
    }
    printf(YEL "THANK YOU\n" RESET);
}