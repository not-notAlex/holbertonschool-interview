#include "holberton.h"

#include <stdlib.h>

/**
 * error - prints error message and exits program
 */
void error(void)
{
	int i = 0;
	char error[6] = "Error";

	for (i = 0; error[i]; i++)
		_putchar(error[i]);
	_putchar('\n');
	exit(98);
}

/**
 * _print - prints a string
 * @str: string to print
 * @size: size of array
 *
 * Return: no return
 */

void _print(char *str, int size)
{
	int i, j;

	i = j = 0;
	while (i < size)
	{
		if (str[i] != '0')
			j = 1;
		if (j || i == size - 1)
			_putchar(str[i]);
		i++;
	}

	_putchar('\n');
	free(str);
}

/**
 * mul - multiply two ints regardless of size
 * @n: char
 * @num: number
 * @num_index: index of number
 * @dest: destination
 * @dest_index: index of destination
 *
 * Return: dest
 */
char *mul(char n, char *num, int num_index, char *dest, int dest_index)
{
	int j, k, mul, mulrem, add, addrem;

	mulrem = addrem = 0;
	for (j = num_index, k = dest_index; j >= 0; j--, k--)
	{
		mul = (n - '0') * (num[j] - '0') + mulrem;
		mulrem = mul / 10;
		add = (dest[k] - '0') + (mul % 10) + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	for (addrem += mulrem; k >= 0 && addrem; k--)
	{
		add = (dest[k] - '0') + addrem;
		addrem = add / 10;
		dest[k] = add % 10 + '0';
	}
	if (addrem)
		return (NULL);
	return (dest);
}

/**
 * checknum - dtermines if string is a number
 * @av: string to check
 *
 * Return: 0 if digits, 1 if not
 */

int checknum(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
		for (j = 0; av[i][j]; j++)
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
	return (0);
}

/**
 * init - initializes string array
 * @str: array to set up
 * @size: size of array
 *
 * Return: void
 */
void init(char *str, int size)
{
	int i;

	for (i = 0; i < size; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int l1, l2, ti, i;
	char *a;
	char *t;

	if (argc != 3 || checknum(argv))
		error();
	for (l1 = 0; argv[1][l1]; l1++)
		;
	for (l2 = 0; argv[2][l2]; l2++)
		;
	a = malloc((l1 + l2 + 1) * sizeof(char));
	if (a == NULL)
		error();
	init(a, l1 + l2);
	for (ti = l2 - 1, i = 0; ti >= 0; ti--, i++)
	{
		t = mul(argv[2][ti], argv[1], l1 - 1, a, (l1 + l2 - 1) - i);
		if (t == NULL)
		{
			free(a);
			error();
		}
	}
	_print(a, l1 + l2);
	return (0);
}
