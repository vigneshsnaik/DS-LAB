#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// colours for aesthetics
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define RESET "\x1B[0m"

#define MAXSIZE 10

char stackDir = 'f';
int stack[MAXSIZE], fwdTop = -1, bwdTop = MAXSIZE;

// checks if stack is full
int isFull()
{
    if (fwdTop == bwdTop - 1)
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
    if (stackDir == 'f')
        if (fwdTop == -1)
        {
            printf(RED "Forward stack underflow\n");
            return 1;
        }
        else
            return 0;
    else if (stackDir == 'b')
        if (bwdTop == MAXSIZE)
        {
            printf(RED "Backward stack underflow\n");
            return 1;
        }
        else
            return 0;
}

// Push element into fwdTop of stack
void push(int data)
{
    if (!isFull())
    {
        if (stackDir == 'f')
        {
            stack[++fwdTop] = data;
            printf(GRN "%d Pushed into forward stack\n", data);
        }
        else if (stackDir == 'b')
        {
            stack[--bwdTop] = data;
            printf(GRN "%d Pushed into backward stack\n", data);
        }
    }
}

// Pop the fwdTop element
void pop()
{
    if (!isEmpty())
        if (stackDir == 'f')
            printf(GRN "%i Popped from forward stack\n", stack[fwdTop--]);
        else if (stackDir == 'b')
            printf(GRN "%i Popped from backward stack\n", stack[bwdTop++]);
}

// display the elements in the stack
void displayStack()
{
    if (!isEmpty())
    {
        int i;
        if (stackDir == 'f')
        {
            printf("Forwardward stack\n");
            printf(YEL "[%d", stack[0]);
            for (i = 1; i <= fwdTop; i++)
            {
                printf(",%d", stack[i]);
            }
        }
        else if (stackDir == 'b')
        {
            printf("Backward stack\n");
            printf(YEL "[%d", stack[MAXSIZE - 1]);
            for (i = MAXSIZE - 2; i >= bwdTop; i--)
            {
                printf(",%d", stack[i]);
            }
        }
        printf("]\n");
    }
}

// displays help message
void help()
{
    printf("Options:(case sensitive)\n");
    printf("sel <STACK DIR> stack  Select/Change the stack direction\n");
    printf("                       Valid options: \"fwd\" \"bwd\"\n");
    printf("                       Default: \"fwd\"\n");
    printf("push <VALUES>          Pushes elements to the topp of stack(or TOS) recursively\n");
    printf("                       Enter each values seperated by \",\"\n");
    printf("                       eg. \"push 1\" or \"push 1,2,3,4,5\"\n");
    printf("pop                    Pops the element at the top of stack(or TOS)\n");
    printf("pop <VALUE> times      Pops elements from the top of stack(or TOS) recursively n times\n");
    printf("help                   Displays this message\n");
    printf("clear                  Clear the Terminal screen\n");
    printf("exit                   Exits the program\n");
}

void main()
{
    int n, i;
    char cmd[10], val[3], *temp;
    system("clear"); // clears the terminal for a CLI-like interface
    help();
    while (1)
    {
        printf(YEL ">>>> " RESET);
        scanf("%s", cmd);
        if (!strcmp("sel", cmd))
        {
            scanf("%s stack", val);
            if (!strcmp("fwd", val))
            {
                stackDir = 'f';
                printf(YEL "Forward stack selcted\n");
            }
            else if (!strcmp("bwd", val))
            {
                stackDir = 'b';
                printf(YEL "Backward stack selcted\n");
            }
            else
            {
                printf(RED "Invalid direction\n");
                help();
            }
        }
        else if (!strcmp("push", cmd))
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
        else if (!strcmp("exit", cmd))
            break;
        else if (!strcmp("clear", cmd))
            system("clear");
        else
        {
            printf(RED "Enter a valid choice\n");
            help();
        }
    }
    printf(YEL "THANK YOU\n" RESET);
}