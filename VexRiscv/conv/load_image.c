#include <stdio.h>
#include <stdlib.h>

#include "conv_img.h"

image make_empty_image(int w, int h, int c)
{
    image out;
    out.data = 0;
    out.h = h;
    out.w = w;
    out.c = c;
    return out;
}

image make_image(int w, int h, int c)
{
    image out = make_empty_image(w,h,c);
    out.data = calloc(h*w*c, sizeof(int));
    return out;
}

image load_image(int w, int h, int c)
{

    image im = make_image(w, h, c);
    for(int z = 0; z < c; ++z){
        for(int y = 0; y < h; ++y){
            for(int x = 0; x < w; ++x){
            	int new_v = 15*y;
            	im.data[z*h*w + y*w + x] = new_v;

            }
        }
    }
    //No alpha channels
    if(im.c == 4) im.c = 3;
    return im;

}

void print_matrix(image mat)
{
    if(mat.data==NULL)
        printf("Image is empty");
    else{
        for(int z = 0; z < mat.c; ++z){
            for(int y = 0; y < mat.h; ++y){
               for(int x = 0; x < mat.w; ++x){
                  int index = x + mat.w*y + mat.w*mat.h*z;
                  printf("%f",mat.data[index]);
               }
               printf("\n");
            }
        }
    }

}

void free_image(image im)
{
    free(im.data);
}


