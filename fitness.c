#include "a4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double comp_distance ( const PIXEL *A, const PIXEL *B, int image_size ) {
	// image_size is the number of pixels, each with 3 channels
	double d = 0;
	// do unrolling by 4 to optomize computation time !!!
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
	// for (int i = 0; i < unroll; i += 4) {
	// 	// d += (((int) A[i].r - (int) B[i].r)*((int) A[i].r - (int) B[i].r));
	// 	// d += (((int) A[i].b - (int) B[i].b)*((int) A[i].b - (int) B[i].b));
	// 	// d += (((int) A[i].g - (int) B[i].g)*((int) A[i].g - (int) B[i].g));
	// 	r = ((int) A[i].r - (int) B[i].r);
	// 	b = ((int) A[i].b - (int) B[i].b);
	// 	g = ((int) A[i].g - (int) B[i].g);
	// 	d += (r*r);
	// 	d += (b*b);
	// 	d += (g*g);

	// 	r = ((int) A[i + 1].r - (int) B[i + 1].r);
	// 	b = ((int) A[i + 1].b - (int) B[i + 1].b);
	// 	g = ((int) A[i + 1].g - (int) B[i + 1].g);
	// 	d += (r*r);
	// 	d += (b*b);
	// 	d += (g*g);

	// 	r = ((int) A[i + 2].r - (int) B[i + 2].r);
	// 	b = ((int) A[i + 2].b - (int) B[i + 2].b);
	// 	g = ((int) A[i + 2].g - (int) B[i + 2].g);
	// 	d += (r*r);
	// 	d += (b*b);
	// 	d += (g*g);

	// 	r = ((int) A[i + 3].r - (int) B[i + 3].r);
	// 	b = ((int) A[i + 3].b - (int) B[i + 3].b);
	// 	g = ((int) A[i + 3].g - (int) B[i + 3].g);
	// 	d += (r*r);
	// 	d += (b*b);
	// 	d += (g*g);
	// 	// d += pow(((int) ((*(A + i)).r) - (int) ((*(B + i)).r)),2);
	// 	// d += pow(((int) ((*(A + i)).b) - (int) ((*(B + i)).b)),2); //A[i].b 
	// 	// d += pow(((int) ((*(A + i)).g) - (int) ((*(B + i)).g)),2);
	// }
	// for (int i = unroll; i < image_size; i++) {
	// 	r = ((int) A[i].r - (int) B[i].r);
	// 	b = ((int) A[i].b - (int) B[i].b);
	// 	g = ((int) A[i].g - (int) B[i].g);
	// 	d += (r*r);
	// 	d += (b*b);
	// 	d += (g*g);
	// }
	d = pow(d, 0.5);
	return d;

}
void comp_fitness_population ( const PIXEL *image , Individual *individual , int population_size ) {
	for (int i = 0; i < population_size; i++) {
		individual[i].fitness = comp_distance(individual[i].image.data, image, individual->image.width * individual->image.height);
	}
}
