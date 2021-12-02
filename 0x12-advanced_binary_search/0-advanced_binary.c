#include "search_algos.h"

/**
 * advanced_binary - performs a binary search on an array
 * @array: array to search
 * @size: size of the array
 * @value: value to search for
 * Return: index found or -1 if not
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return -1;

	return (binary(array, value, 0, size - 1));
}

/**
 * binary - recursive binary search
 * @array: array to search
 * @value: value to search
 * @l: left index
 * @r: right index
 * Return: index found or -1 if not
 */
int binary(int *array, int value, size_t l, size_t r)
{
	unsigned int x;
	int half = ((r + l) / 2);

	printf("Searching in array: ");
	for (x = l; x <= r; x++)
	{
		printf("%d", array[x]);
		if (x != r)
			printf(", ");
	}
	printf("\n");
	if (array[half] == value)
		return (half);
	if (l == r)
		return (-1);
	if (array[half] >= value)
		return (binary(array, value, l, half - 1));
	else
		return (binary(array, value, half + 1, r));
}
