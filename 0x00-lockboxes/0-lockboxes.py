#!/usr/bin/python3
"""
module for lockboxes challenge
"""


def canUnlockAll(boxes):
    """
    returns True if all lockboxes can be opened
    """
    opened = [0]
    for x in opened:
        for y in boxes[x]:
            if y < len(boxes) and y not in opened:
                opened.append(y)
    if len(opened) == len(boxes):
        return True
    else:
        return False
