#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "conv_img.h"


float get_pixel(image im, int x, int y, int c)
{       
	//pixel array has a total number of elements equaling WIDTH * HEIGHT * channels
	float pix = im.data[im.w*im.h*c+x+y*im.w];
	
	return pix;
}
void set_pixel(image im, int x, int y, int c, float v)
{
	//set pixel to new value 
	im.data[c*im.h*im.w + y*im.w + x] = v;
}

void clamp_image(image im)
{
	for(int c=0; c<im.c; c++){
		for(int y=0; y<im.h; y++){
	    		for(int x=0; x<im.w; x++){
	    			if(get_pixel(im, x, y, c)<0)
	    				set_pixel(im, x, y, c, 0);
	    			else if(get_pixel(im, x, y, c)>255)
	    				set_pixel(im, x, y, c, 255);
	    			}
	    	}
	}
	    			    		
}


void normalize(image im)
{
	for(int c=0; c<im.c; c++){
		for(int y=0; y<im.h; y++){
	    		for(int x=0; x<im.w; x++){
	    			set_pixel(im, x, y, c, get_pixel(im, x, y, c)/(im.h*im.w));  // 1/N*M
	    		}
	    	}
	 }
}
image new_filter(int w)
{
	// new square filter 
	image flr = make_image(w,w,1);
	// fill filter
	for(int z=0; z<flr.c; z++){
		for(int y=0; y<w; y++){
	    		for(int x=0; x<w; x++){	
	    			int v = 1;
            			set_pixel(flr, x, y, z, v);
	    		}
	    	}
	}        
	// normalise it
	normalize(flr);
	return flr;
}

image convolve_image(image im, image filter)
{
	image new_im = make_image(im.w, im.h, im.c);
	for(int c=0; c<im.c; c++){
		for(int y=0; y<im.h; y++){
	    		for(int x=0; x<im.w; x++){
                		float new_v = 0;
                		for (int fh = 0; fh < filter.h; fh++) {                   		
                    			for (int fw = 0; fw < filter.w; fw++) {
                    		
        	               	 	float flr_v = filter.data[filter.w*filter.h*(filter.c-1)*c + fh*filter.w + fw];
        	                	
        	               	 	int filterw = x - filter.w/2 + fw;
        	               	 	int filterh = y - filter.h/2 + fh;
        	               	 	
        	               	 	new_v += get_pixel(im, filterw, filterh, c) * flr_v;
                    			}
                		}
              			set_pixel(new_im, x, y, c, new_v);
			}
		}
	}
	return new_im;
	

}
