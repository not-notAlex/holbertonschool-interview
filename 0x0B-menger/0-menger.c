#include "menger.h"


/**
 * menger - draws a 2D menger sponge
 * @level: the size of the cube
 *
 * Return: no return
 */
void menger(int level)
{
	int x, y, sides = 3, p, z;

	if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (level < 0)
		return;
	for (x = 1; x < level; x++)
		sides *= 3;
	for (x = 0; x < sides; x++)
	{
		for (y = 0; y < sides; y++)
		{
			p = 1;
			for (z = 1; z < sides; z *= 3)
				if (((x / z) % 3) == 1 && ((y / z) % 3) == 1)
					p = 0;
			if (p)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
