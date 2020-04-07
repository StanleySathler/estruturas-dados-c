#include <stdio.h>
#include "include/queue.h"
#include "coloring.h"

#define coord(line, column)     ((line) * 100 + (column))
#define coord_to_line(coord)    ((coord) / 100)
#define coord_to_column(coord)  ((coord) % 100)

static int
coord_color(int image[HEIGHT][WIDTH], int line, int column)
{
  return (
    line >= 0 && line < HEIGHT &&
    column >= 0 && column < HEIGHT
  )
    ? image[line][column]
    : -1;
}

void
flood_fill(int image[HEIGHT][WIDTH], int line, int column, int color)
{
  int prev_color = image[line][column];

  /* Are colors equal? Return immediately. */
  if (prev_color == color)
    return;

  queue_t q = queue_create(HEIGHT * WIDTH);
  int curr_coord = coord(line, column);

  /* Paint pixel and push into the queue. */
  image[line][column] = color;
  queue_add(&q, curr_coord);

  while (!queue_empty(&q)) {
    /* Current pixel. */
    curr_coord = queue_consume(&q);
    line = coord_to_line(curr_coord);
    column = coord_to_column(curr_coord);

    /* Top neighbor. */
    if (coord_color(image, line - 1, column) == prev_color) {
      image[line - 1][column] = color;
      queue_add(&q, coord(line - 1, column));
    }

    /* Right neighbor. */
    if (coord_color(image, line, column + 1) == prev_color) {
      image[line][column + 1] = color;
      queue_add(&q, coord(line, column + 1));
    }

    /* Bottom neighbor. */
    if (coord_color(image, line + 1, column) == prev_color) {
      image[line + 1][column] = color;
      queue_add(&q, coord(line + 1, column));
    }

    /* Left neighbor. */
    if (coord_color(image, line, column - 1) == prev_color) {
      image[line][column - 1] = color;
      queue_add(&q, coord(line, column - 1));
    }
  }

  queue_destroy(&q);
}
