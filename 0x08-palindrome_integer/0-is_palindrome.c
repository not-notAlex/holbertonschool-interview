#include "palindrome.h"

/**
 * is_palindrome - checks if an int is a palindrome
 * @n: number to check
 *
 * Return: 1 if true 0 if false
 */
int is_palindrome(unsigned long n)
{
	int len = 0, x;
	unsigned long int i = n, t = 1;

	while (i > 0)
	{
		i /= 10;
		len++;
	}
	if (len == 1)
		return (1);
	for (x = 1; x < len; x++)
	{
		t *= 10;
	}
	x = 1;
	i = n;
	while (x <= (len / 2))
	{
		if ((i % 10) != ((i / t) % 10))
			return (0);
		x++;
		t /= 100;
		i /= 10;
	}
	return (1);
}
