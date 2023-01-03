#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "colours.h"
#include "Stack_char.h"

#define MAXSIZE 50
char infix[MAXSIZE], postfix[MAXSIZE], tmpStack[MAXSIZE];
float valStack[MAXSIZE];
int tmpTop = -1, postTop = -1, valTop = -1;

// checks if stack is full
int isFullFloat(float stack[], int *top, int size)
{
    if (*top >= size)
        return 1;
    else
        return 0;
}

// checks if stack is Empty
int isEmptyFloat(float stack[], int *top)
{
    if (*top == -1)
        return 1;
    else
        return 0;
}

// Push element into *top of stack
int pushFloat(float stack[], int *top, int data, int size)
{
    if (!isFullFloat(stack, &*top, size))
    {
        stack[++*top] = data;
        return stack[*top];
    }
}

// Pop the *top element
int popFloat(float stack[], int *top)
{
    if (!isEmptyFloat(stack, &*top))
        return stack[(*top)--];
    else
        return 0;
}

float postfixEvaluvate()
{
    float A, B;
    char ch;
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
            pushFloat(valStack, &valTop, ch - 48, MAXSIZE);
        else
        {
            B = popFloat(valStack, &valTop);
            A = popFloat(valStack, &valTop);
            if (ch == '^')
                pushFloat(valStack, &valTop, (pow(A, B)), MAXSIZE);
            else if (ch == '*')
                pushFloat(valStack, &valTop, (A * B), MAXSIZE);
            else if (ch == '/')
                pushFloat(valStack, &valTop, (A / B), MAXSIZE);
            else if (ch == '+')
                pushFloat(valStack, &valTop, (A + B), MAXSIZE);
            else if (ch == '-')
                pushFloat(valStack, &valTop, (A - B), MAXSIZE);
        }
    }
    return valStack[valTop];
}
void main()
{
    int n, i;
    char cmd[10];
    system("clear"); // clears the terminal for a CLI-like interface
    while (1)
    {
        printf(YEL ">>>> " RESET);
        tmpTop = -1;
        postTop = -1;
        scanf("%s", postfix);
        if (!strcmp(postfix, "exit"))
            break;
        printf("Value = %f\n", postfixEvaluvate(postfix));
    }
    printf(YEL "THANK YOU\n" RESET);
}