#include "sort.h"

/**
 * heap_sort - sorta an array using the heap method
 * @array: array to sort
 * @size: size of array
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	heap_sort_print(array, size, array, size);
}

/**
 * heap_sort_print - prints the array sorted by heap
 * @array: array to sort
 * @size: size of the array
 * @p_array: array to print
 * @p_size: size of array to print
 * Return: no return
 */
void heap_sort_print(int *array, size_t size, int *p_array, size_t p_size)
{
	int i = 0, temp = 0;

	for (i = (size - 1) / 2; i >= 0; i--)
	{
		heapify(array, size, i, p_array, p_size);
	}
	for (i = (size - 1); i > 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		p_array[i] = array[i];
		p_array[0] = array[0];
		print_array(p_array, p_size);

		heapify(array, i, 0, p_array, p_size);
	}
}

/**
 * heapify - heapifies the array
 * @array: array to sort
 * @size: size of array
 * @i: index
 * @p_array: array to print
 * @p_size: size of array to print
 * Return: no return
 */
void heapify(int *array, size_t size, int i, int *p_array, size_t p_size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp = 0;

	if (left < (int)size && array[left] > array[max])
		max = left;
	if (right < (int)size && array[right] > array[max])
		max = right;
	if (max != i)
	{
		temp = array[i];
		array[i] = array[max];
		array[max] = temp;
		p_array[i] = array[i];
		p_array[max] = array[max];
		print_array(p_array, p_size);

		heapify(array, size, max, p_array, p_size);
	}
}
