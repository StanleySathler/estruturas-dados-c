#include <stdio.h>
#include <stdlib.h>
#include "include/queue.h"
#include "drawer.h"

#define coord(line, column)     ((line) * 100 + (column))
#define coord_to_line(coord)    ((coord) / 100)
#define coord_to_column(coord)  ((coord) % 100)

static int
calc_offset(Image img, int line, int column)
{
  return line * img->width + column;
}

static int
coord_color(Image img, int line, int column)
{
  return (
    line >= 0 && line < img->height &&
    column >= 0 && column < img->width
  )
    ? img->pixels[calc_offset(img, line, column)]
    : -1;
}

void
flood_fill(Image img, int line, int column, int color)
{
  int px_offset = calc_offset(img, line, column);
  int prev_color = img->pixels[px_offset];

  /* Are colors equal? Return immediately. */
  if (prev_color == color)
    return;

  queue_t q = queue_create(img->height * img->width);
  int curr_coord = coord(line, column);

  /* Paint pixel and push into the queue. */
  img->pixels[px_offset] = color;
  queue_add(&q, curr_coord);

  while (!queue_empty(&q)) {
    /* Current pixel. */
    curr_coord = queue_consume(&q);
    line = coord_to_line(curr_coord);
    column = coord_to_column(curr_coord);

    /* Top neighbor. */
    if (coord_color(img, line - 1, column) == prev_color) {
      img->pixels[calc_offset(img, line - 1, column)] = color;
      queue_add(&q, coord(line - 1, column));
    }

    /* Right neighbor. */
    if (coord_color(img, line, column + 1) == prev_color) {
      img->pixels[calc_offset(img, line, column + 1)] = color;
      queue_add(&q, coord(line, column + 1));
    }

    /* Bottom neighbor. */
    if (coord_color(img, line + 1, column) == prev_color) {
      img->pixels[calc_offset(img, line + 1, column)] = color;
      queue_add(&q, coord(line + 1, column));
    }

    /* Left neighbor. */
    if (coord_color(img, line, column - 1) == prev_color) {
      img->pixels[calc_offset(img, line, column - 1)] = color;
      queue_add(&q, coord(line, column - 1));
    }
  }

  queue_destroy(&q);
}

Image
drawer_image_create(int* content, int width, int height)
{
  /* Allocate required space in the Heap segment. */
  Image img = malloc(sizeof(image_t));
  img->pixels = malloc(sizeof(int) * width * height);

  /* Initialize basic values. */
  img->height = height;
  img->width = width;

  /* Initialize each pixel by copying from content. */
  int offset = 0;
  for (int lin = 0; lin < height; lin++) {
    for (int col = 0; col < width; col++) {
      offset = lin * width + col;
      img->pixels[offset] = content[offset];
    }
  }

  return img;
}

void
drawer_image_destroy(Image img)
{
  free(img->pixels);
  free(img);
}
