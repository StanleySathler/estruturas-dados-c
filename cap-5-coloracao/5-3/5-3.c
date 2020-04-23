#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Due our compilation flow, we should consider
 * "libs/" as the base dir.
 */
#include "../cap-5-coloracao/drawer/drawer.h"

Image
exec_5_3(char* file_path)
{
  char curr_ch;
  int content[200];
  int total_px = 0;
  int width = -1;
  int height = -1;

  FILE* f = fopen(file_path, "r");
  if (f == NULL) {
    fprintf(stderr, "Couldn't open file");
    exit(1);
  }

  /* For each char in the file. */
  for (int i = 0; curr_ch = getc(f) != EOF; i++) {
    /* If newline and width was not set before,
     * we set the width.
     */
    if (width == -1 && curr_ch == '\n')
      width = total_px;

    /* If number (single digit), we treat it as
     * a pixel.
     */
    if (isdigit(curr_ch)) {
      content[total_px] = curr_ch;
      total_px++;
    }
  }

  /* After reading the whole file, we set the height. */
  height = (total_px / width);
  if (total_px % width > 0)
    height++;

  return drawer_image_create(content, width, height);
}
