#!/usr/bin/python3
"""
module for test question
"""

import math


def minOperations(n):
    """
    finds the minimum operations
    """
    prime_factors = []
    i = 3
    c = n
    if n == 1 or n <= 0:
        return 0
    if n == 2:
        return 2
    if n == 3:
        return 3
    while i <= c:
        if c % 2 == 0:
            c = c / 2
            prime_factors.append(2)
        if c % i == 0:
            c = c / i
            prime_factors.append(i)
            i = 3
        if c == 2:
            prime_factors.append(2)
        i = i + 2
    return sum(prime_factors)
