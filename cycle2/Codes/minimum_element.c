#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// colours for aesthetics
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

#define MAXSIZE 10

int stack[MAXSIZE], auxStack[MAXSIZE], top = -1, auxTop = -1;

// checks if stack is full
int isFull()
{
    if (top >= MAXSIZE)
    {
        printf(RED "STACK OVERFLOW\n");
        return 1;
    }
    else
        return 0;
}

// checks if stack is Empty
int isEmpty()
{
    if (top == -1)
    {
        printf(RED "STACK UNDERFLOW\n");
        return 1;
    }
    else
        return 0;
}
void pushAuxStack(int data)
{
    if (auxTop == -1 || auxStack[auxTop] >= stack[top])
    {
        auxStack[++auxTop] = data;
        printf(GRN "%d Pushed into Auxilary stack\n", data);
    }
}
// Push element into top of stack
void push(int data)
{
    if (!isFull())
    {
        stack[++top] = data;
        printf(GRN "%d Pushed\n", data);
        pushAuxStack(data);
    }
}
void popAuxStack()
{
    if (auxStack[auxTop] == stack[top])
        printf(GRN "%i Popped from Auxilary Stack\n", auxStack[auxTop--]);
}
// Pop the top element
void pop()
{
    if (!isEmpty())
    {
        popAuxStack();
        printf(GRN "%i Popped\n", stack[top--]);
    }
}

// display the elements in the stack
void displayStack()
{
    if (!isEmpty())
    {
        int i;
        printf(YEL "[%d", stack[0]);
        for (i = 1; i <= top; i++)
        {
            printf(", %d", stack[i]);
        }
        printf("]\n");
    }
}

void displayMinElement()
{
    if (!isEmpty())
        printf(YEL "Minimum element is %d\n", auxStack[auxTop]);
}
// displays help message
void help()
{
    printf("Options:(case sensitive)\n");
    printf("push <VALUES>       Pushes elements to the top of stack(or TOS) recursively\n");
    printf("                    Enter each values seperated by \",\"\n");
    printf("                    eg. \"push 1\" or \"push 1,2,3,4,5\"\n");
    printf("pop                 Pops the element at the top of stack(or TOS)\n");
    printf("pop <VALUE> times   Pops elements from the top of stack(or TOS) recursively n times\n");
    printf("minimun             displays the minimum element\n");
    printf("help                Displays this message\n");
    printf("clear               Clear the Terminal screen\n");
    printf("exit                Exits the program\n");
}

void main()
{
    int n, i;
    char cmd[10], val[20], *temp;
    system("clear"); // clears the terminal for a CLI-like interface
    help();
    while (1)
    {
        printf(YEL ">>>> " RESET);
        scanf("%s", cmd);
        if (!strcmp("push", cmd))
        {
            scanf("%[^\n]s", val);
            temp = strtok(val, ",");
            while (temp != NULL)
            {
                push(atoi(temp));
                temp = strtok(NULL, ",");
            }
        }
        else if (!strcmp("pop", cmd))
        {
            if (scanf("%[^\n]s", val))
                for (i = 1; i <= atoi(val); i++)
                    pop();
            else
                pop();
        }
        else if (!strcmp("display", cmd))
            displayStack();
        else if (!strcmp("help", cmd))
            help();
        else if (!strcmp("minimum", cmd))
            displayMinElement();
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