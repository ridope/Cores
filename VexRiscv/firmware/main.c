#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	puts("display                         - display test");
	puts("led                             - led test");
	puts("lkr                             - led knight rider test");
	puts("fill                            - led fill up test");
	puts("clock                           - clock demo");
}

static void reboot(void)
{
	ctrl_reset_write(1);
}

static void display_test(void)
{
	int i;
	printf("display_test...\n");
	
	for(i=0; i<10; i++) {
	display0_sel_write(0);
	display0_value_write(i);
	display0_write_write(1);
	
	display1_sel_write(1);
	display1_value_write(i);
	display1_write_write(1);
	
	display2_sel_write(2);
	display2_value_write(i);
	display2_write_write(1);
	
	display3_sel_write(3);
	display3_value_write(i);
	display3_write_write(1);
	
	display4_sel_write(4);
	display4_value_write(i);
	display4_write_write(1);
	
	display5_sel_write(5);
	display5_value_write(i);
	display5_write_write(1);
	busy_wait(500);
	}
}

static void clock_test(void)
{
	int so; int st=0; int mo=0; int mt=0; int ho=0; int ht=0;

	printf("clock_test...\n");
	
	for(so=0; so<10; so++) {
	display0_sel_write(0);
	display0_value_write(so);
	display0_write_write(1);
	busy_wait(500);
		if(so==9){
			so=-1;
			display0_sel_write(0);
			display0_value_write(so);
			display0_write_write(1);
			st=st+1;
			display1_sel_write(1);
			display1_value_write(st);
			display1_write_write(1);
			
			if(st==6){
			st=0;
			display1_sel_write(1);
			display1_value_write(st);
			display1_write_write(1);
			
			mo=mo+1;
			display2_sel_write(2);
			display2_value_write(mo);
			display2_write_write(1);
			}
			
		
		}
		if(mo==10){
			mo=0;
			display2_sel_write(2);
			display2_value_write(mo);
			display2_write_write(1);
			
			mt=mt+1;
			display3_sel_write(3);
			display3_value_write(mt);
			display3_write_write(1);
			
			if(mt==6){
			mt=0;
			display3_sel_write(3);
			display3_value_write(mt);
			display3_write_write(1);
			
			ho=ho+1;
			display4_sel_write(4);
			display4_value_write(ho);
			display4_write_write(1);
			}
			
		}
		if(ho==10){
			ho=0;
			display4_sel_write(4);
			display4_value_write(ho);
			display4_write_write(1);
			
			ht=ht+1;
			display5_sel_write(5);
			display5_value_write(ht);
			display5_write_write(1);
		}
		if((ht==2)&&(ho==4)){
			ht=0;
			display5_sel_write(5);
			display5_value_write(ht);
			display5_write_write(1);
			
			ho=0;
			display4_sel_write(4);
			display4_value_write(ho);
			display4_write_write(1);
				
			mo=0;
			display2_sel_write(2);
			display2_value_write(mo);
			display2_write_write(1);
				
			mt=0;
			display3_sel_write(3);
			display3_value_write(mt);
			display3_write_write(1);
				
			st=0;
			display1_sel_write(1);
			display1_value_write(st);
			display1_write_write(1);
				
			so=0;
			display0_sel_write(0);
			display0_value_write(so);
			display0_write_write(1);
				
			busy_wait(1000);
				
			ctrl_reset_write(1);
				
		}
		
	}
	
}

static void led_test(void)
{
	int i;
	printf("led_test...\n");
	for(i=0; i<32; i++) {
		leds_out_write(i);
		busy_wait(1);
	}
}


static void fillup_test(void)
{
	int i, j;
	printf("Led fill up test...\n");
	for(i=0; i<=512; i++) {
		leds_out_write(i);
		busy_wait(1);
		for(j=512; j>=0; j--) {
			leds_out_write(i);
			busy_wait(1);
		}
	}
}

static void rider_test(void)
{	
	int i;
	for(i=0; i<4; i++) {
		leds_out_write(1);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(2);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(4);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(8);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(16);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(32);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(64);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(128);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(256);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(512);
		busy_wait(75);
		leds_out_write(0);
		
		leds_out_write(256);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(128);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(64);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(32);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(16);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(8);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(4);
		busy_wait(75);
		leds_out_write(0);
		leds_out_write(2);
		busy_wait(75);
		leds_out_write(0);
	
		
	}
	ctrl_reset_write(1);
	
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
	else if(strcmp(token, "display") == 0)
		display_test();
	else if(strcmp(token, "led") == 0)
		led_test();
	else if(strcmp(token, "lkr") == 0)
		rider_test();
	else if(strcmp(token, "fill") == 0)
		fillup_test();
	else if(strcmp(token, "clock") == 0)
		clock_test();
	prompt();
}

int main(void)
{
#ifdef CONFIG_CPU_HAS_INTERRUPT
	irq_setmask(0);
	irq_setie(1);
#endif
	uart_init();

	puts("\nLab004 - CPU testing software built "__DATE__" "__TIME__"\n");
	help();
	prompt();

	while(1) {
		console_service();
	}

	return 0;
}
