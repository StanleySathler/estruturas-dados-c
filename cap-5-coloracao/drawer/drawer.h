#pragma once

  #define HEIGHT 9
  #define WIDTH 9

  typedef struct {
    int* pixels; /* A 2D-array representing the pixels. */
    int height;  /* Total of rows. */
    int width;   /* Total of columns. */
  } image_t, *Image;

  /**
   * Free allocated memory.
   */
  void
  drawer_image_destroy(Image img);

  /**
   * Create an image representation.
   */
  Image
  drawer_image_create(int* content, int width, int height);

  /**
   * Fill a region using flood-fill strategy.
   */
  void
  flood_fill(Image img, int line, int column, int color);
