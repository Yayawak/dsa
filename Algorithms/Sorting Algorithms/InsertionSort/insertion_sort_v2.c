#include <stdio.h>
//find minimum element -> insert to left most of array

void    swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void    print_array(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void    selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            /* if (arr[j] < arr[min_idx]) */
            if (arr[j] > arr[min_idx])
                min_idx = j;
            // THIS IS BUG
            /* swap(&arr[min_idx], &arr[i]); */
        }
        swap(&arr[min_idx], &arr[i]);
        print_array(arr, n);
    }
}


int main(void)
{
    /* int arr[] = {6, 2, 1, 3, -2}; */
    int arr[] = {-9, 10, 20, 2, -5, -13, 4, 7}; // failed test case
    /* int arr[] = {-9, 10, 20, 2, -5, 4, -13, 7}; */
    int n = sizeof(arr) / sizeof(arr[0]);
    /* printf("Unsorted array : \n"); */
    /* print_array(arr, n); */

    selection_sort(arr, n);

    printf("Sorted array : \n");
    print_array(arr, n);

    /* selection_sort(arr, n); */
    /* printf("Sorted array : \n"); */
    /* print_array(arr, n); */
    return (0);
}
