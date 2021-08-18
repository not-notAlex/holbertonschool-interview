#include "sandpiles.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_grids - adds two sandpiles together
 * @grid1: first sandpile
 * @grid2: second sandpile
 * Return: if the grid overflows
 */
int add_grids(int grid1[3][3], int grid2[3][3])
{
	int x, y, hasChanged = 0;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
		{
			grid1[x][y] += grid2[x][y];
			if (grid1[x][y] > 3)
				hasChanged = 1;
		}

	return (hasChanged);
}

/**
 * sandpiles_sum - adds two sandpiles together
 * @grid1: first grid
 * @grid2: second grid
 * Return: no return
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y, hasChanged, hasPrinted = 0, i = 0, newX, newY;
	int changes[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	hasChanged = add_grids(grid1, grid2);
	while (hasChanged)
	{
		i = 0;
		hasChanged = 0;
		hasPrinted = 0;
		for (x = 0; x < 3; x++)
			for (y = 0; y < 3; y++, i++)
				if (grid1[x][y] > 3)
				{
					if (hasPrinted == 0)
					{
						printf("=\n");
						print_grid(grid1);
						hasPrinted = 1;
					}
					changes[i] = 1;
					hasChanged = 1;
				}
		for (x = 0; x < 9; x++)
			if (changes[x])
			{
				newX = x / 3;
				newY = x % 3;
				grid1[newX][newY] -= 4;
				if (newX > 0)
					grid1[newX - 1][newY] += 1;
				if (newX < 2)
					grid1[newX + 1][newY] += 1;
				if (newY > 0)
					grid1[newX][newY - 1] += 1;
				if (newY < 2)
					grid1[newX][newY + 1] += 1;
				changes[x] = 0;
			}
	}
}
