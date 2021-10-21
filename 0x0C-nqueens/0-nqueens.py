#!/usr/bin/python3
"""
module for task
"""

import sys
grid = []
results = []


def addResult(cords):
    """
    adds answer to list
    """
    global results
    res = []
    for x in range(len(grid)):
        for y in range(len(grid)):
            if cords[x][y]:
                res.append([x, y])
    if res not in results:
        results.append(res)


def nqueens(n):
    """
    solves the nqueens problem
    """
    global grid
    count = 0
    for x in range(n):
        for y in range(n):
            if grid[x][y] == 0:
                if canPlace(x, y):
                    grid[x][y] = 1
                    nqueens(n)
                    grid[x][y] = 0
            else:
                count += 1
    if count == len(grid):
        addResult(grid)


def canPlace(x, y):
    """
    checks if you can place a queen on grid
    """
    global grid
    for i in range(len(grid)):
        if grid[x][i] or grid[i][y]:
            return False
    for i in range(len(grid)):
        for j in range(len(grid)):
            if (i + j == x + y) or (i - j == x - y):
                if grid[i][j]:
                    return False
    return True


if __name__ == "__main__":
    """
    main function
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception as e:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    for i in range(n):
        row = []
        for j in range(n):
            row.append(0)
        grid.append(row)
    nqueens(n)
    for i in results:
        print(i)
