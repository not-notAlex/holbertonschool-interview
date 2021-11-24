#ifndef SORT_H_
#define SORT_H_

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i, int *array_p, size_t size_p);
void heap_sort_print(int *array, size_t size, int *array_p, size_t size_p);

#endif
