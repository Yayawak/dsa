#include <stdio.h>

void	read_list(int list[], int n)
{
	printf("Enter the elements\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &list[i]);
	}
		/* *list[i] = sca */
}

void	print_list(int list[], int n)
{
	printf("The elements of the list are : \n");
	for (int i = 0; i < n; i++)
		printf("%d\t", list[i]);
	printf("\n");
}
