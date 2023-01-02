#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"
#include "colours.h"

#define MAXSIZE 10

int stack[MAXSIZE], top = -1;

// displays help message
void help()
{
    printf("Options:(case sensitive)\n");
    printf("push <VALUES>       Pushes elements to the *top of stack(or TOS) recursively\n");
    printf("                    Enter each values seperated by \",\"\n");
    printf("                    eg. \"push 1\" or \"push 1,2,3,4,5\"\n");
    printf("pop                 Pops the element at the *top of stack(or TOS)\n");
    printf("pop <VALUE> times   Pops elements from the *top of stack(or TOS) recursively n times\n");
    printf("peek                Shows the elements at the top of stack(or TOS)\n");
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
                if (!printf(GRN "%d Pushed\n", push(stack, &top, atoi(temp), MAXSIZE)))
                    printf(RED "STACK OVERFLOW\n");
                temp = strtok(NULL, ",");
            }
        }
        else if (!strcmp("pop", cmd))
        {
            if (scanf("%[^\n]s", val))
            {
                for (i = 1; i <= atoi(val); i++)
                {
                    if (!pop(stack, &top))
                        printf(RED "STACK UNDERFLOW\n");
                    else
                        printf(GRN "Popped\n");
                }
            }
            else
            {
                if (!pop(stack, &top))
                    printf(RED "STACK UNDERFLOW\n");
                else
                    printf(GRN "Popped\n");
            }
        }
        else if (!strcmp("peek", cmd))
            printf("%i", peek(stack, &top));
        else if (!strcmp("display", cmd))
            displayStack(stack, &top);
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