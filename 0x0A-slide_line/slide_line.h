#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
int slide_line_left(int *line, size_t size);
int slide_line_right(int *line, size_t size);
#define SLIDE_LEFT  -1
#define SLIDE_RIGHT  1

#endif
