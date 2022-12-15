#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int row;
    int col;
    int val;
} matrix;

void readsparse(matrix m[], char c)
{
    printf("Enter the matrix %c in sparse form\n", c);
    scanf("%d %d %d", &m[0].row, &m[0].col, &m[0].val);
    for (int i = 1; i <= m[0].val; i++)
        scanf("%d %d %d", &m[i].row, &m[i].col, &m[i].val);
}
void printsparse(matrix m[], char c)
{
    printf("Sparse matrix %c\n", c);
    printf(" ROW  COL  VAL\n");
    for (int i = 0; i <= m[0].val; i++)
        printf("%4d %4d %4d\n", m[i].row, m[i].col, m[i].val);
}
void addsparse(matrix a[], matrix b[], matrix c[])
{
    if (a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Matrices can not be added");
        printf("!!!! EXITING PROGRAM !!!!");
        exit(0);
    }
    int ai = 1, bi = 1, ci = 1;
    c[0].col = a[0].col;
    c[0].row = a[0].row;
    while (ai <= a[0].val || bi <= b[0].val)
    {
        if (a[ai].row < b[bi].row)
        {
            c[ci] = a[ai];
            ai++;
        }
        else if (a[ai].row > b[bi].row)
        {
            c[ci] = b[bi];
            bi++;
        }
        else
        {
            if (a[ai].col < b[bi].col)
            {
                c[ci] = a[ai];
                ai++;
            }
            else if (a[ai].col > b[bi].col)
            {
                c[ci] = b[bi];
                bi++;
            }
            else
            {
                c[ci].row = b[bi].row;
                c[ci].col = b[bi].col;
                c[ci].val = a[ai].val + b[bi].val;
                bi++;
                ai++;
            }
        }
        ci++;
    }
    c[0].val=ci-1;
}
void main()
{
    matrix a[50], b[50], c[50];
    readsparse(a, 'A');
    readsparse(b, 'B');
    printsparse(a, 'A');
    printsparse(b, 'B');
    addsparse(a, b, c);
    printf("C=A+B\n");
    printsparse(c, 'C');
}
