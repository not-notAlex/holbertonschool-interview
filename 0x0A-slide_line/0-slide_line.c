#include "slide_line.h"

/**
 * slide_line - slides elements in array and combines same
 * @line: pointer to line
 * @size: size of array
 * @direction: the direction to slide the line
 * Return: 1 on success 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (size < 2)
		return (1);
	if (direction == SLIDE_LEFT)
		return (slide_line_left(line, size));
	else
		return (slide_line_right(line, size));
}

/**
 * slide_line_left - slides line to the left
 * @line: pointer to line
 * @size: size of array
 * Return: 1 on success 0 on failure
 */
int slide_line_left(int *line, size_t size)
{
	size_t i, x, merge = 0;

	for (i = 1; i < size; i++)
	{
		if (line[i] == 0)
			continue;
		for (x = i; x > 0; x--)
		{
			if (line[x - 1] != 0)
			{
				if (line[x - 1] == line[x] && merge == 0)
				{
					line[x - 1] *= 2;
					line[x] = 0;
					merge = 1;
					break;
				}
				merge = 0;
				break;
			}
			line[x - 1] = line[x];
			line[x] = 0;
		}
	}
	return (1);
}

/**
 * slide_line_right - slides line to the right
 * @line: pointer to line
 * @size: size of array
 * Return: 1 on success 0 on failure
 */
int slide_line_right(int *line, size_t size)
{
	long int i, merge = 0;
	size_t x;

	for (i = size - 2; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;
		for (x = i; x < size - 1; x++)
		{
			if (line[x + 1] != 0)
			{
				if (line[x + 1] == line[x] && merge == 0)
				{
					line[x + 1] *= 2;
					line[x] = 0;
					merge = 1;
					break;
				}
				merge = 0;
				break;
			}
			line[x + 1] = line[x];
			line[x] = 0;
		}
	}
	return (1);
}
