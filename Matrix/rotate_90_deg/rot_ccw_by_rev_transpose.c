#include <stdio.h>
# define N 4

void dis_a(int n, int mat[])
{
    for (int i = 0; i < n; i++)
        printf("%d, ", mat[i]);
    printf("\n");
}

void dis_m(int mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}


void    swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void    reverse_row(int n, int A[])
{
    /* printf("Before swap\n"); */
    /* dis_a(n, A); */
    for (int i = 0; i < n / 2; i++)
    {
        swap(&A[i], &A[n - i - 1]);
    }
    /* printf("After swap\n"); */
    /* dis_a(n, A); */
    /* printf("\n\n"); */
}

void    tranpose_m(int n, int mat[][N])
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(&mat[i][j], &mat[j][i]);
}

void    rot_m(int mat[][N])
{
    for (int i = 0; i < N; i++)
        reverse_row(N, mat[i]);
    tranpose_m(N, mat);
}

int main(void)
{

    /* int[, ] mat = { */
    /* int mat[, ] = { */
    int mat[4][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
    /* reverse_row(4, mat[0]); */

    rot_m(mat);

    dis_m(mat);
}

