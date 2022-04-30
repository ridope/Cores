#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "conv_img.h"

#include <irq.h>
#include <uart.h>
#include <console.h>
#include <generated/csr.h>


static char *readstr(void)
{
	char c[2];
	static char s[64];
	static int ptr = 0;

	if(readchar_nonblock()) {
		c[0] = readchar();
		c[1] = 0;
		switch(c[0]) {
			case 0x7f:
			case 0x08:
				if(ptr > 0) {
					ptr--;
					putsnonl("\x08 \x08");
				}
				break;
			case 0x07:
				break;
			case '\r':
			case '\n':
				s[ptr] = 0x00;
				putsnonl("\n");
				ptr = 0;
				return s;
			default:
				if(ptr >= (sizeof(s) - 1))
					break;
				putsnonl(c);
				s[ptr] = c[0];
				ptr++;
				break;
		}
	}

	return NULL;
}

static char *get_token(char **str)
{
	char *c, *d;

	c = (char *)strchr(*str, ' ');
	if(c == NULL) {
		d = *str;
		*str = *str+strlen(*str);
		return d;
	}
	*c = 0;
	d = *str;
	*str = c+1;
	return d;
}

static void prompt(void)
{
	printf("RUNTIME>");
}

static void help(void)
{
	puts("Available commands:");
	puts("help                            - this command");
	puts("reboot                          - reboot CPU");
	puts("conv                            - 1D convolution test");
	puts("float                           - float test");
	puts("double                          - double test");
	puts("int                             - double test");
	puts("img                             - convolve image test");
}

static void reboot(void)
{
	ctrl_reset_write(1);
}
static void convolve_test(void)
{
	//Configure timer
	timer0_en_write(0);
	timer0_load_write(0);
	timer0_reload_write(0xFFFFFFFF);
	timer0_en_write(1);
	timer0_update_value_write(1);

	timer0_update_value_write(1);
	uint32_t time_begin = timer0_value_read();
	
	//Value definition
	float g[] = {1.0, 1.0, 1.0, 1.0, 1.0, 2.0};
	float f[] = {1.0, 1.0, 1.0, 1.0, 1.0, 2.0};
	int len_g = sizeof g;
	int len_f = sizeof f;
	int len_c = len_g+len_f-1;
  	
  	int i,j,l;
	//Alocate space
  	float *r = (float*) calloc(len_c, sizeof(float));

  	for (i=0; i<len_c; i++){
  		l=i;
   		for(j=0; j<len_f; j++){
   			if(l>=0 && l<len_g){
				r[i] += r[i] + g[l]*f[j]; 
				l=l-1;
			}
		}
		printf("%d ",r[i]);
  	}
  	puts("");
  	free(r);
  	//Print timer value
  	timer0_update_value_write(1);
	uint32_t time_end = timer0_value_read();
	float time_spent_ms = (time_begin - time_end)/(CONFIG_CLOCK_FREQUENCY/1000.0);
	printf("Time taken to complete function is %f seconds", time_spent_ms);
	  
}
/*-----------------------------------------------------------------------*/
/* quadratic function using double values                                */
/*-----------------------------------------------------------------------*/
static void double_test(void){
	//Configure timer
	//clock_t start, end;
    	//start = clock();

	timer0_update_value_write(1);
	uint32_t time_begin = timer0_value_read();


	//Value definition
	int a=0, b=0, c=0;
	a=1;
	b=1;
	c=1;
	printf("%d\t%d\n", a, b);
	int i;
	//loop over quadratic function
	for(i=0; i<100; i++) {
        	int d = (int)sqrt((b*b + 4.0*a*c));
        	int r1 = (b + d) / (2.0*a);
        	int r2 = (b + d) / (a);
        	printf("%d\t%d\t%d\n", r1, r2, d);
        	//Update values
        	a = a*r1;
        	b = b*r1;
        	c = c*r1;
	}
	//Print timer value
	//end = clock();
	//float cpu_time = ((float) (end - start)) / CLOCKS_PER_SEC;
    	//printf("Time taken to complete function is %f seconds", cpu_time);
}
static void int_test(void){
	//Configure timer
	//clock_t start, end;
    	//start = clock();
	
	//Value definition
	int a, b, c;
	a=1;
	b=1;
	c=1;
	printf("%d\t%d\n", a, b);
	int i;
	//loop over quadratic function
	for(i=0; i<20; i++) {
        	int d = (int)sqrt((double)(b*b + 4*a*c));
        	int r1 = (b + d) / (2*a);
        	int r2 = (b + d) / (a);
        	printf("%d\t%d\n", r1, r2);
        	//Update values
        	a = a*r1;
        	b = b*r1;
        	c = c*r1;
	}
	//Print timer value
	//end = clock();
	//float cpu_time = ((float) (end - start)) / CLOCKS_PER_SEC;
    	//printf("Time taken to complete function is %f seconds", cpu_time);
}

/*-----------------------------------------------------------------------*/
/* quadratic function using float values                                 */
/*-----------------------------------------------------------------------*/
static void float_test(void){
	printf("float_test...\n");
	//Configure timer
	//clock_t start, end;
	//start = clock();
	
	//Value definition
	float a, b, c;
	a=1.0;
	b=2.5;
	c=1.0;
	printf("%f\t%f\t%f\n", a, b, c);
	int i;
	//loop over quadratic function
	for(i=0; i<20; i++) {
        	float d = (float)sqrt(b*b + 4.0*a*c);
        	float r1 = (float)(b + d) / (2.0*a);
        	float r2 = (float)(b + d) / (2.0*a);
        	printf("%f\t%f\t%f\n", r1, r2);
        	//Update values
        	a = a*r1;
        	b = b*r2;
        	c = c*r1;
	}
	//Print timer value
	//end = clock();
	//float cpu_time = ((float) (end - start)) / CLOCKS_PER_SEC;
    	//printf("Time taken to complete function is %f seconds", cpu_time);
}

static void conv_img(void)
{
	//Configure timer
	clock_t start, end;
	start = clock();
	//Load and create paramters
	image im = load_image("img/cameraman.png");
	image flr = new_filter(7); //normalised filter
	//Convolve
	image c_img = convolve_image(im, flr);

	clamp_image(c_img);
	save_png(c_img, "img/cameraman_conv.png");
	free_image(c_img);
	
	//Print timer value
	end = clock();
	float cpu_time = ((float) (end - start)) / CLOCKS_PER_SEC;
    	printf("Time taken to complete function is %f seconds", cpu_time);
}


static void console_service(void)
{
	char *str;
	char *token;

	str = readstr();
	if(str == NULL) return;
	token = get_token(&str);
	if(strcmp(token, "help") == 0)
		help();
	else if(strcmp(token, "reboot") == 0)
		reboot();
	else if(strcmp(token, "conv") == 0)
		convolve_test();	
	else if(strcmp(token, "float") == 0)
		float_test();
	else if(strcmp(token, "double") == 0)
		double_test();
	else if(strcmp(token, "int") == 0)
		int_test();
	else if(strcmp(token, "img") == 0)
		conv_img();
			
	prompt();
}

int main(void)
{
#ifdef CONFIG_CPU_HAS_INTERRUPT
	irq_setmask(0);
	irq_setie(1);
#endif
	uart_init();

	puts("\nCPU testing software built "__DATE__" "__TIME__"\n");
	help();
	prompt();

	while(1) {
		console_service();
	}

	return 0;
}
