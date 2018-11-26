#include "a4.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  PPM_IMAGE *image = read_ppm("mona_lisa.ppm");
  //write_ppm("test.ppm",image);
  //exit(EXIT_SUCCESS);
  int population_size = 49; // @ 10, 50, 30 seg fault ??
  int num_generations = 50000;//minute*60; // 4000 iterations per minute
  double rate = 3e-2;
  printf("\nFile new_out.ppm:\nSize: %dx%d, max color %d, pixels to mutate %d\n",
   image->width, image->height, image->max_color, (int)(rate/100*image->width*image->height));
  PPM_IMAGE * new_image = evolve_image ( image , num_generations , population_size , rate );
  write_ppm("alr_escher.ppm",new_image);
  free_image(image);
  free_image(new_image);
  exit(EXIT_SUCCESS);
}