#!/usr/bin/python3
"""
module for UTF-8 Validation
"""


def validUTF8(data):
    """
    determines if list is UTF-8 valid
    """
    i = 0
    while(i < len(data)):
        if data[i] >> 7 == 0:
            i += 1
            continue
        mask1 = 1 << 7
        nbytes = 0
        while(mask1 & data[i]):
            nbytes += 1
            mask1 = mask1 >> 1
        if nbytes == 0:
            return False
        j = 1
        i += 1
        if j == 1:
            return False
        while(j < nbytes):
            mask1 = 1 << 7
            mask2 = 1 << 6
            try:
                if not (data[i] & mask1 and not (data[i] & mask2)):
                    return False
            except:
                return False
            i += 1
            j += 1
    return True
