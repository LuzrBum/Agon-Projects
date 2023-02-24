//MOVE a pixel across the screen with Arrow keys AND an X across the screen with ASDW
#include <stdio.h>
#include <ctype.h>
#include "mos-interface.h"
#include "vdp.h"
#include "mos-keycode.h"
#include "agontimer.h"

void plot(char color, UINT16 Lx, UINT16 Ly ) {
	vdp_fgcolour(color, color, color);
	vdp_plot(4,Lx,Ly);
	vdp_plot(5,Lx,Ly);
	}
	
int main(int argc, char * argv[]) {
	UINT16 key;
	UINT16 x,y,moveclock =0, animationclock=0, movestate=0, timer2;
	UINT16 x1,y1;
	UINT8 frame,r,g,b,filehandle;
	UINT8 xpos,ypos;
	char c;
	BOOL running;
	char myString[];
	
	x1=150;
	y1=150;
	vdp_mode(0);
	vdp_cls();
	vdp_fgcolour(255,255,255);
	xpos = 10;
	ypos = 5;
	vdp_cursorGoto(xpos,ypos);
	puts("#AgonLight - Hello world!\r\n");
	
	//printf("Press any key:\r\n\r\n"); - don't mix printf and puts ;)
	c=0;
	running=TRUE;
	while(running)
	{
		key = getfullkeycode();
		// For "realtime" operation you must comment out ";jr z, waitkey" in mos-keycode.asm
		delayms(5);
		c++;
		vdp_cursorGoto(xpos,ypos);
		if((c%2)==1) {puts("A");} else {puts("B");}
		//myString[] = "";
		//sprintf(myString,"\rKeycode %2x, mod %2x",(key&0xFF),(key&0xFF00)>>8);
		//puts(myString);
		//printf("\rKeycode %2x, mod %2x",(key&0xFF),(key&0xFF00)>>8);
		switch( (key&0xFF))
			{
				case 0x0a:
						//puts("DOWN");
						y1++;
						plot(255,x1,y1);
						break;
				case 0x0b:
						//puts("UP");
						y1--;
						plot(255,x1,y1);
						break;
				case 0x08:
						//puts("LEFT");
						x1--;
						plot(255,x1,y1);
						break;
				case 0x15:
						//puts("RIGHT");
						x1++;
						plot(255,x1,y1);
						break;
				//keycodes a=61, d= 64, s = 73, w= 77, q= 71, e = 65, 1= 31)
				case 0x73:
						//puts("S");
						puts(" ");
						ypos++;						
						vdp_cursorGoto(xpos,ypos);
						puts("X");
						break;
				case 0x77:
						//puts("W");
						puts(" ");
						ypos--;
						vdp_cursorGoto(xpos,ypos);
						puts("X");
						break;
				case 0x61:
						//puts("A");
						puts(" ");
						xpos--;
						vdp_cursorGoto(xpos,ypos);
						puts("X");
						break;
				case 0x64:
						//puts("D");
						puts(" ");
						xpos++;
						vdp_cursorGoto(xpos,ypos);
						puts("X");
						break;
				
				case 0x20:
						//puts("SPACE");							
						puts(" ");
						xpos = 10;
						ypos = 5;
	
						vdp_cursorGoto(xpos,ypos);
						puts("O");
						break;
				case 0x1b:
						puts("ESC - BYE");
						running = FALSE;
					
				default:
						
						break;
				
				
			}
	}
	vdp_cls();
	
	return 0;
}

