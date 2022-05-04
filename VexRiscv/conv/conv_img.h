#ifndef CONV_IMG_H
#define CONV_IMG_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>


#include <irq.h>
#include <libbase/uart.h>
#include <libbase/console.h>
#include <generated/csr.h>



typedef struct{
    int w,h,c;
    float *data;
} image;


// Loading and saving
image make_empty_image(int w, int h, int c);
image make_image(int w, int h, int c);
void save_image_stb(image im, const char *name, int png);
void save_png(image im, const char *name);
void save_image(image im, const char *name);
image load_image_stb(char *filename, int channels);
image load_image(char *filename);
void free_image(image im);

// Basic operations
float get_pixel(image im, int x, int y, int c);
void set_pixel(image im, int x, int y, int c, float v);
void clamp_image(image im);


// Filtering + Convolution
image convolve_image(image im, image filter);
image new_filter(int w);
void normalize(image im);


#endif
