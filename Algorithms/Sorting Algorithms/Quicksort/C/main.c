#include <stdio.h>
#include "qSort.c"
#include "arr_helper.c"

int	main(void)
{
	/* int	list[7], n; */
	int	n;

	int	list[] = {10, 5, 23, 67, 20, 30, 60};
	//{67, 5, 23, 10, 20, 30, 60}; 
	// while b
	// 5 <= 67  => i = 2;
	// 23 <= 67 => i = 3;
	// 10 <= 67 => i = 4;
	// 20 <= 67 => i = 5;
	// 60 <= 67 => i = 6;
	// i <= n == 7 <= 6 ? yes!
	// while c
	// 60 > 67 ? no! = > j remain same => j = 6;
	
	// while a
	// now i = 6
	// 60 <= 67 => i = 7 !!!
	// while b 
	// 60 > 67 ? no! => j same -> j = 6;
	// 7 !< 6 : no swap
	n = 7;
	/* printf("Enter the number of elements in the list max = 10\n"); */
	/* scanf("%d", &n); */
	/* read_list(list, n); */


	printf("\nThe list before sorting is :\n");
	print_list(list, n);

	qSort(list, 0, n-1);
	printf("\nThe list after sorting is:\n");
	print_list(list, n);
	return (0);
}
