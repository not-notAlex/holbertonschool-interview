#!/usr/bin/python3
"""
moduel for rain function
"""


def rain(walls):
    """
    returns how many square units of water will be retained
    """
    if len(walls) == 0:
        return 0
    total = 0
    x = 0
    while x < len(walls):
        if walls[x] == 0:
            x += 1
            continue
        y = x + 1
        if y >= len(walls):
            return total
        while walls[y] == 0:
            y += 1
            if y >= len(walls):
                return total
        if walls[x] < walls[y]:
            width = walls[x]
        else:
            width = walls[y]
        total += (y - x - 1) * width
        x += 1
