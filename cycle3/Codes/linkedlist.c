#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "SLL.h"
#include "colours.h"

void display(Node *Head)
{
    printf(YEL "Head ");
    Node *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        printf("-> %d ", temp->data);
    }
    printf("-> NULL\n");
}
// displays help message
void help()
{
    printf("Options:(case sensitive)\n");
    printf("insert <VALUES>       insertes elements to the *top of stack(or TOS) recursively\n");
    printf("                    Enter each values seperated by \",\"\n");
    printf("                    eg. \"insert 1\" or \"insert 1,2,3,4,5\"\n");
    printf("remove Back                removes the element at the *top of stack(or TOS)\n");
    printf("remove front        removes elements from the *top of stack(or TOS) recursively n times\n");
    printf("peek                Shows the elements at the top of stack(or TOS)\n");
    printf("help                Displays this message\n");
    printf("clear               Clear the Terminal screen\n");
    printf("exit                Exits the program\n");
}
void main()
{
    int i;
    char cmd[10], val[20], *temp;
    Node *head1 = (Node *)malloc(sizeof(Node));
    system("clear"); // clears the terminal for a CLI-like interface
    help();
    while (1)
    {
        printf(YEL ">>>> " RESET);
        scanf("%s", cmd);
        if (!strcmp("insert", cmd))
        {
            scanf(" at %s", cmd);
            scanf("%[^\n]s", val);
            if (!strcmp("back", cmd))
            {
                temp = strtok(val, ",");
                while (temp != NULL)
                {
                    printf(GRN "%d inserted\n", insertAtBack(&*head1, atoi(temp)));
                    temp = strtok(NULL, ",");
                }
            }
            else if (!strcmp("front", cmd))
            {
                temp = strtok(val, ",");
                while (temp != NULL)
                {
                    printf(GRN "%d inserted\n", insertAtFront(&*head1, atoi(temp)));
                    temp = strtok(NULL, ",");
                }
            }
            else if (isdigit(cmd[0]))
            {
                temp = strtok(val, ",");
                while (temp != NULL)
                {
                    printf(GRN "%d inserted\n", insertAtPosition(&*head1, atoi(temp), atoi(cmd)));
                    temp = strtok(NULL, ",");
                }
            }
            else
            {
                printf(RED "INVALID COMMAND\n");
                help();
            }
        }
        else if (!strcmp("delete", cmd))
        {
            scanf(" from %s", cmd);
            if (!strcmp("back", cmd))
                if (scanf("%[^\n]s", val))
                    for (i = 1; i <= atoi(val); i++)
                        printf(GRN "%i Deleted\n", deleteFromBack(&*head1));
                else
                    printf(GRN "%i Deleted\n", deleteFromBack(&*head1));
            else if (!strcmp("front", cmd))
                if (scanf("%[^\n]s", val))
                    for (i = 1; i <= atoi(val); i++)
                        printf(GRN "%i Deleted\n", deleteFromFront(&*head1));
                else
                    printf("%i Deleted\n", deleteFromFront(&*head1));
            else if (isdigit(cmd[0]))
            {
                if (scanf("%[^\n]s", val))
                    for (i = 1; i <= atoi(val); i++)
                        printf(GRN "%i Deleted\n", deleteFromPosition(&*head1, atoi(cmd)));
                else
                    printf(GRN "%i Deleted\n", deleteFromPosition(&*head1, atoi(cmd)));
            }
            else
            {
                printf(RED "INVALID VALUE");
                help();
            }
        }
        else if (!strcmp("display", cmd))
            display(&*head1);
        else if (!strcmp("help", cmd))
            help();
        else if (!strcmp("clear", cmd))
            system("clear");
        else if (!strcmp("exit", cmd))
            break;
        else
        {
            printf(RED "Enter a valid Command\n");
            help();
        }
    }
    printf(YEL "THANK YOU\n" RESET);
}