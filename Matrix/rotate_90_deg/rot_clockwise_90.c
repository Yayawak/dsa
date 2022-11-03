#include <stdio.h>
# define N 4

void    display_matrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void    rot_m(int mat[][N])
{
    // how many rings to run ?
    for (int x = 0; x < N / 2; x++)
    {
        // consifer elements i group of 4 in current square
        for (int y = x; y < N - x - 1; y++)
        {
            int tmp = mat[x][y];

            // move signle value from right -> top
            mat[x][y] = mat[y][N - 1 - x];

            // move val from bot -> right
            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y];

            // move val from left -> bot
            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x];

            // top -> left
            mat[N - 1 -y][x] = tmp;
        }
    }
}

int main(void)
{
    int mat[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rot_m(mat);

    display_matrix(mat);

    return (0);
}
