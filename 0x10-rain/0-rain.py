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
    for x, h in enumerate(walls):
        left = max(walls[:x + 1])
        right = max(walls[x:])
        filler = min(left, right)
        total += max(filler - h, 0)
    return total
