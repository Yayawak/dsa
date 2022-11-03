// C++ program for left rotation of matrix
// by 90 degree without using extra space
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

// Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(int arr[R][C])
{
    int n = R; // n=size of the square matrix
    int a = 0, b = 0, c = 0, d = 0;

    // iterate over all the boundaries of the matrix
    for (int i = 0; i <= n / 2 - 1; i++) {

        // for each boundary, keep on taking 4 elements (one
        // each along the 4 edges) and swap them in
        // anticlockwise manner
        for (int j = 0; j <= n - 2 * i - 2; j++) {
            a = arr[i + j][i];
            b = arr[n - 1 - i][i + j];
            c = arr[n - 1 - i - j][n - 1 - i];
            d = arr[i][n - 1 - i - j];

            arr[i + j][i] = d;
            arr[n - 1 - i][i + j] = a;
            arr[n - 1 - i - j][n - 1 - i] = b;
            arr[i][n - 1 - i - j] = c;
        }
    }
}

// Function for print matrix
void printMatrix(int arr[R][C])
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

// Driven code
int main()
{
    int arr[R][C] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotateby90(arr);
    printMatrix(arr);
    return 0;
}

// This code is contributed by Md. Enjamum
// Hossain(enja_2001)
