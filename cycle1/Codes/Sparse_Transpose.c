#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} sparse;
void readsparse(sparse s[], int limit)
{
    for (int i = 0; i <= limit; i++)
        scanf("%d %d %d", &s[i].row, &s[i].col, &s[i].value);
}

void printsparse(sparse s[])
{
    int total = s[0].value + 1;
    for (int i = 0; i < total; i++)
        printf("%d %d %d\n", s[i].row, s[i].col, s[i].value);
}

void transpose(sparse s[], sparse t[])
{
    
}

int main()
{
    sparse s[100], t[100];
    int v;
    printf("Total no. of Non zero Values in the Matrix: : ");
    scanf("%d", &v);
    printf("Enter the Sparse Matrix Representation\n");
    readsparse(s, v);
    printf("The Transpose of Sparse Matrix Representation is: \n");
    transpose(s, t);
    printsparse(t);
}
