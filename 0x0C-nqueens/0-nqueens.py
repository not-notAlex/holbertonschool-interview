#!/usr/bin/python3
"""
module for task
"""

from sys import argv


if __name__ == "__main__":
    """
    main function
    """
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if type(argv[1]) is not int:
        print("N must be a number")
        exit(1)
    if int(argv[1]) < 4:
        print("N must be at least 4")
        exit(1)
    nqueens(int(argv[1]))

def nqueens(n):
    """
    solves the nqueen problem
    """
    print("yo")
