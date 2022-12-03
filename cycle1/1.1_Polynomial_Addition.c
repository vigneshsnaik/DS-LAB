// Polynomial addition
#include <stdio.h>
#define MAXSIZE 10
typedef struct
{
    int exp;
    int coeft;
} poly;

void readpoly(poly a[], int start, int end, char c)
{
    printf("Enter polynomial %c in increasing order of exponents : \n", c);
    for (int i = start; i <= end; i++)
    {
        scanf("%d", &a[i].coeft);
        scanf("%d", &a[i].exp);
    }
}
void printpoly(poly a[], int start, int end, char c)
{
    printf("Polynomial %c : ", c);
    for (int i = start; i < end; i++)
        printf("%ix^%i + ", a[i].coeft, a[i].exp);
    printf("%ix^%i", a[end].coeft, a[end].exp);
}
int addpoly(poly a[], int startA, int endA, int startB, int endB, int startSum)
{
    while (startA <= endA || startB <= endB)
    {
        if (a[startA].exp > a[startB].exp)
        {
            a[startSum].coeft = a[startA].coeft;
            a[startSum].exp = a[startA].exp;
            startA++;
            startSum++;
        }
        else if (a[startA].exp < a[startB].exp)
        {
            a[startSum].coeft = a[startB].coeft;
            a[startSum].exp = a[startB].exp;
            startB++;
            startSum++;
        }

        else
        {
            a[startSum].coeft = a[startB].coeft + a[startA].coeft;
            a[startSum].exp = a[startB].exp;
            startA++;
            startB++;
            startSum++;
        }
    }
    return startSum-1;
}

void main()
{
    poly a[100];
    int n1, n2, startA, endA, startB, endB, startSum, endSum;

    printf("Enter no. of terms of first polynomial : ");
    scanf("%d", &n1);
    startA = 0;
    endA = n1 - 1;
    startB = n1;

    printf("Enter no. of terms of second polynomial : ");
    scanf("%d", &n2);
    endB = n1 + n2 - 1;
    startSum = n1 + n2;

    readpoly(a, startA, endA, 'A');
    printf("\n");
    readpoly(a, startB, endB, 'B');
    printf("\n");

    endSum = addpoly(a, startA, endA, startB, endB, startSum);

    printpoly(a, startA, endA, 'A');
    printf("\n");

    printpoly(a, startB, endB, 'B');
    printf("\n");

    printpoly(a, startSum, endSum, 'C');
    printf("\n");
}