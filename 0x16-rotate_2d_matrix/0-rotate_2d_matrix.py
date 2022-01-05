#!/usr/bin/python3
"""
module for task 0
"""


def rotate_2d_matrix(matrix):
    """
    rotates a 2D matrix clockwise
    """
    n = len(matrix)
    for i in range(0, int(n / 2)):
        for j in range(i, n - i - 1):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = tmp
