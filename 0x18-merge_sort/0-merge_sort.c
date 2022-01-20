#include "sort.h"

/**
 * merge - merges left and right into array
 * @array: array to merge
 * @size: size of array
 * @L: left array
 * @R: right array
 * Return: no return
 **/
void merge(int *array, int *L, int *R, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, size_l);
	printf("[right]: ");
	print_array(R, size_r);
	while (i < size_l && j < size_r)
	{
		if (L[i] < R[j])
		{
			array[k] = L[i];
			k++;
			i++;
		}
		else
		{
			array[k] = R[j];
			k++;
			j++;
		}
	}
	while (i < size_l)
		array[k++] = L[i++];
	while (j < size_r)
		array[k++] = R[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Uses merge sort on array
 * @array: list to sort
 * @size: size of array
 * Return: no return
 */
void merge_sort(int *array, size_t size)
{
	size_t m = 0, i;
	int L[100];
	int R[100];

	if (array == NULL || size < 2)
		return;
	m = size / 2;
	for (i = 0; i < m; i++)
		L[i] = array[i];
	for (i = m; i < size; i++)
		R[i - m] = array[i];
	merge_sort(L, m);
	merge_sort(R, size - m);
	merge(array, L, R, size);
}
