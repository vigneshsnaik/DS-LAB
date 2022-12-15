// Polynomial evaluation
#include <stdio.h>
#include <math.h>
#define MAXSIZE 10
typedef struct
{
    int exp;
    int coeft;
} poly;

void readpoly(poly a[], int size)
{
    printf("Enter polynomial : \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i].coeft);
        scanf("%d", &a[i].exp);
    }
}
void printpoly(poly a[], int size)
{
    printf("Polynomial :");
    for (int i = 0; i < size - 1; i++)
        printf("%ix^%i + ", a[i].coeft, a[i].exp);
    printf("%ix^%i", a[size - 1].coeft, a[size - 1].exp);
    printf("\n");
}
int evaluate(poly a[], int size, int val)
{
    int result = 0;
    for (int i = 0; i < size; i++)
        result = result + a[i].coeft * pow(val, a[i].exp);
    return result;
}

void main()
{
    poly a[100];
    int size, val, result;
    printf("Enter no. of terms of polynomial : ");
    scanf("%d", &size);
    readpoly(a, size);
    printpoly(a, size);
    printf("Enter the value : ");
    scanf("%d", &val);
    result = evaluate(a, size, val);
    printf("The result is : %d", result);
    printf("\n");
}