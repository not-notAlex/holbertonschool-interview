#!/usr/bin/python3
"""
module for task 0
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island in grid
    """
    result = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if (y+1) < len(grid[0]) and grid[x][y+1] == 0:
                    result += 1
                if y == (len(grid[0]) - 1):
                    result += 1
                if y == 0:
                    result += 1
                if grid[x][y-1] == 0 and y > 0:
                    result += 1
                if grid[x-1][y] == 0 and x > 0:
                    result += 1
                if x == 0:
                    result += 1
                if (x+1) < len(grid) and grid[x+1][y] == 0:
                    result += 1
                if x == len(grid) - 1:
                    result += 1
    return result
