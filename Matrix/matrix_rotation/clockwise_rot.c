#include <stdio.h>
# define R 4
# define C 4

void    rotate_matrix(int m, int n, int mat[R][C])
{
    int row = 0, col = 0;
    int prev, cur;

    /*
    m - ending row index
    n - ending col index
    */
    while (row < m && col < n)
    {
        // prevent inner ring
        if (row + 1 == m || col + 1 == n)
            break ;

        prev = mat[row + 1][col]; // ij = (1,0) // replace 4 -> 1 // prev = 4
        // iterate over row 0 : all col
        for (int i = col; i < n; i++)
        {
            // start from element 1 (pos = (0,0))
            cur = mat[row][i]; // cur = 1 // 2. cur = 2 // 3. cur = 3
            mat[row][i] = prev; // mat[0][0] = 4 // 2. mat[0][1] = 1 // 3.mat[0][2] = 2
            prev = cur; // prev = 1 // 2. prev = 2 // 3. prev = 3
        }
        // prev = 3
        row++; // row = 1
        // next row -> row 1
        for (int i = row; i < m; i++)
        {
            cur = mat[i][n - 1]; // cur = mat[1][2] = 6
            mat[i][n - 1] = prev; // mat[1][2] = 3
            prev = cur;
        }
        n--;
        if (row < m) // while (1 < 3)
        {
            // endif i >= 0
            for (int i = n - 1; i >= col; i--)
            {
                // LAST ROW
                cur = mat[m - 1][i];
                mat[m - 1][i] = prev; // prev = 6
                prev = cur;
            }
            // prev = 7
        }
        m--; // 3 -> 2
        if (col < n) // 0 < 2
        {
            for (int i = m - 1; i >= row; i--)
            {
                cur = mat[i][col];
                mat[i][col] = prev;
                prev = cur;
            }
        }
        col++; // col = 1
    }
}

/* void    print_mat(int M[R][C], int m, int n) */
/* void    print_mat(int **M, int m, int n) */
void    print_mat(int M[4][4], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}
int     main(void)
{
    /* wathc matrix as "ring" */
    /* int M[R][C] = { */
    /*     {1, 2, 3}, */
    /*     {4, 5, 6}, */
    /*     {7, 8, 9} */
    /* }; */
    int M[R][C] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    /* print_mat(M1, R, C); */
    print_mat(M, R, C);
    rotate_matrix(R, C, M);
    printf("After rotation\n");
    /* print_mat(M1, R, C); */
    print_mat(M, R, C);
}

