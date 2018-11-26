#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance ( const PIXEL *A, const PIXEL *B, int image_size ) {
	double d = 0;
	double r, g, b;
	//int unroll = image_size - image_size % 4;
	for (int i = 0; i < image_size; i += 1) {
		// d += (((int) A[i].r - (int) B[i].r)*((int) A[i].r - (int) B[i].r));
		// d += (((int) A[i].b - (int) B[i].b)*((int) A[i].b - (int) B[i].b));
		// d += (((int) A[i].g - (int) B[i].g)*((int) A[i].g - (int) B[i].g));
		r = ((int) A[i].r - (int) B[i].r);
		b = ((int) A[i].b - (int) B[i].b);
		g = ((int) A[i].g - (int) B[i].g);
		d += (r*r);
		d += (b*b);
		d += (g*g);
	}
	d = pow(d, 0.5);
	return d;

}
void comp_fitness_population ( const PIXEL *image , Individual *individual , int population_size ) {
	for (int i = 0; i < population_size; i++) {
		individual[i].fitness = comp_distance(individual[i].image.data, image, individual->image.width * individual->image.height);
	}
}
