#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

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
	puts("float                           - float test");
	puts("double                          - double test");
}

static void reboot(void)
{
	ctrl_reset_write(1);
}

/*-----------------------------------------------------------------------*/
/* quadratic function using double values                                */
/*-----------------------------------------------------------------------*/
static void double_test(void){
	//Configure timer
	timer0_en_write(0);
	timer0_load_write (-1);
	timer0_en_write(1);
	timer0_update_value_write(1);
    	int start = timer0_value_read();

	//Value definition
	double a=0, b=0, c=0;
	a=1.0;
	b=1.0;
	c=1.0;
	printf("%f\t%f\n", a, b);
	int i;
	//loop over quadratic function
	for(i=0; i<100; i++) {
        	double d = (double)sqrt((b*b + 4.0*a*c));
        	double r1 = (b + d) / (2.0*a);
        	double r2 = (b + d) / (a);
        	printf("%d\t%d\t%d\n", r1, r2, d);
        	//Update values
        	a = a*r1;
        	b = b*r1;
        	c = c*r1;
	}
	//Print timer value
	timer0_update_value_write(1);
	int end = timer0_value_read();
	int cpu_time = ((int) (-end-start)) / CLOCKS_PER_SEC;
    	printf("Time taken to complete function is %d seconds", cpu_time);
}

/*-----------------------------------------------------------------------*/
/* quadratic function using float values                                 */
/*-----------------------------------------------------------------------*/
static void float_test(void){
	printf("float_test...\n");
	timer0_en_write(0);
	timer0_load_write (-1);
	timer0_en_write(1);
	timer0_update_value_write(1);
    	int start = timer0_value_read();
	
	//Value definition
	float a, b, c;
	a=1.0;
	b=2.5;
	c=1.0;
	printf("%f\t%f\t%f\n", a, b, c);
	int i;
	//loop over quadratic function
	for(i=0; i<100; i++) {
        	float d = (float)sqrt(b*b + 4.0*a*c);
        	float r1 = (float)(b + d) / (2.0*a);
        	float r2 = (float)(b + d) / (2.0*a);
        	printf("%d\t%d\t%d\n", r1, r2);
        	//Update values
        	a = a*r1;
        	b = b*r2;
        	c = c*r1;
	}
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
	else if(strcmp(token, "float") == 0)
		float_test();
	else if(strcmp(token, "double") == 0)
		double_test();
			
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
