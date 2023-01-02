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
    printf("infix <expression>    Push an expression to obtain its postfix and evaluvate it\n");
    printf("postfix <expression>  Push an expression to obtain its postfix and evaluvate it\n");
    printf("clear                 Clear the Terminal screen\n");
    printf("exit                  Exits the program\n");
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
    char ch;
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
            pushFloat(valStack, &valTop, ch - 48.0, MAXSIZE);
        else if (ch == '+')
            pushFloat(valStack, &valTop, (popFloat(valStack, &valTop) + popFloat(valStack, &valTop)), MAXSIZE);
        else if (ch == '-')
            pushFloat(valStack, &valTop, (popFloat(valStack, &valTop) - popFloat(valStack, &valTop)), MAXSIZE);
        else if (ch == '*')
            pushFloat(valStack, &valTop, (popFloat(valStack, &valTop) * popFloat(valStack, &valTop)), MAXSIZE);
        else if (ch == '/')
            pushFloat(valStack, &valTop, (popFloat(valStack, &valTop) / popFloat(valStack, &valTop)), MAXSIZE);
        else if (ch == '^')
            pushFloat(valStack, &valTop, pow(popFloat(valStack, &valTop), popFloat(valStack, &valTop)), MAXSIZE);
    }
    return valStack[valTop];
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
        if (!strcmp("infix", cmd))
        {
            tmpTop = -1;
            postTop = -1;
            scanf("%[^\n]s", infix);
            printf("Postfix :");
            infixtopostfix();
            displayStack(postfix, &postTop);
            printf("Value = %f\n", postfixEvaluvate(postfix));
        }
        else if (!strcmp("postfix", cmd))
        {
            tmpTop = -1;
            postTop = -1;
            scanf("%[^\n]s", postfix);
            printf("Value = %f\n", postfixEvaluvate(postfix));
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