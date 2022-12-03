#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int value;
} matrix;
int main()
{
    int n;
    printf("Enter the no: of non zero elements: ");
    scanf("%d", &n);
    matrix a[n + 1];
    a[0].value = n;
    printf("Enter the no: of rows and columns: ");
    scanf("%d %d", &a[0].row, &a[0].col);
    printf("Enter the sparse matrix representation: \n");
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    printf("Sparse matrix representation\n");
    printf(" ROW  COL  VAL\n");
    for (int i = 0; i <= n; i++)
        printf("%4d %4d %4d\n", a[i].row, a[i].col, a[i].value);
    float sparsity = (float)(a[0].row * a[0].col - a[0].value) / (a[0].row * a[0].col);
    printf("Sparsity = %0.5f\n", sparsity);
}