#include "arr_helper.c"

void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	getPivotPos(int i, int j)
{
	return ((i+j)/2);
}

void	qSort(int list[], int m, int n)
{
	// ? m & n is always constant
	/* print_list(list, n); */
	int	key, i, j, p;

	if (m < n)
	{
		p = getPivotPos(m, n);
		/* swap(&list[m], &list[n]); */
		swap(&list[m], &list[p]);

		key = list[m];
		i = m + 1;
		j = n;

		while (i <= j)
		{
			while ((i <= n) && (list[i] <= key))
				i++;
			while ((j >= m) && (list[j] > key))
				j--;
			if (i < j)
				swap(&list[i], &list[j]);
		}
		swap(&list[m], &list[j]);
		qSort(list, m, j-1);
		qSort(list, j+1, n);
	}
}
