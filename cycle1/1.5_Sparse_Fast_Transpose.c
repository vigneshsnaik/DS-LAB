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

void fastTranspose(sparse s[], sparse t[])
{
    int start_pos[30], row_terms[30];
    int i, j, k;
    int num_terms = s[0].value;
    int num_cols = s[0].col;
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].value = s[0].value;
    if (num_terms > 0)
    {
        for (i = 0; i < num_cols; i++)
            row_terms[i] = 0; 
        for (i = 1; i <= num_terms; i++)
            row_terms[s[i].col]++;
        start_pos[0] = 1;
        for (i = 1; i < num_cols; i++)
            start_pos[i] = start_pos[i - 1] + row_terms[i - 1];
        for (i = 1; i <= num_terms; i++)
        {
            j = start_pos[s[i].col]++;
            t[j].row = s[i].col;
            t[j].col = s[i].row;
            t[j].value = s[i].value;
        }
    }
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
    fastTranspose(s, t);
    printsparse(t);
}
