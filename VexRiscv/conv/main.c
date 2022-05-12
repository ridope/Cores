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
	timer0_load_write (-1);
	timer0_en_write(1);
	timer0_update_value_write(1);
    	int start = timer0_value_read();

	
	//Value definition
	int g[] = {1, 3, 1, 1, 1, 2, 1, 1, 1, 1, 4, 2, 2, 1, 1, 1, 2, 1, 2, 5};
	int f[] = {1, 1, 2, 2, 1, 2, 1, 3, 1, 2, 1, 2, 2, 1, 1, 1, 2, 1, 2, 3};
	int len_g = sizeof g;
	int len_f = sizeof f;
	int len_c = len_g+len_f-1;
  	
  	int i,j,l;
	//Alocate space
  	int *r = (int*) calloc(len_c, sizeof(int));

  	for (i=0; i<len_c; i++){
  		l=i;
   		for(j=0; j<len_f; j++){
   			if(l>=0 && l<len_g){
				r[i] += r[i] + g[l]*f[j]; 
				l=l-1;
			}
		}
		
  	}
  	for (i=0; i<len_c; i++){
  	printf("%d ",r[i]);
  	}
  	puts("");
  	free(r);
  	//Print timer value
  	timer0_update_value_write(1);
	int end = timer0_value_read();
	int cpu_time = ((int) (-end-start)) / CLOCKS_PER_SEC;
    	printf("Time taken to complete function is %d seconds", cpu_time);
	  
}

static void conv_img(void)
{
	//Configure timer
	timer0_en_write(0);
	timer0_load_write (-1);
	timer0_en_write(1);
	timer0_update_value_write(1);
    	int start = timer0_value_read();

	image im = load_image(20, 20, 1);
	image flr = new_filter(7); //normalised filter
	//Convolve
	image c_img = convolve_image(im, flr);

	clamp_image(c_img);
	print_matrix(c_img);
	free_image(c_img);
	
	//Print timer value
	timer0_update_value_write(1);
	int end = timer0_value_read();
	int cpu_time = ((int) (-end-start)) / CLOCKS_PER_SEC;
    	printf("Time taken to complete function is %d seconds", cpu_time);
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
