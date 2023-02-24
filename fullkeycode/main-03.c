//STARFIELD
#include <stdio.h>
#include <Stdlib.h>
#include <ctype.h>
#include "mos-interface.h"
#include "vdp.h"
#include "mos-keycode.h"
#include "agontimer.h"
#include "Math.h"


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
	int i,j;
	char c;
	BOOL running;
	char myString[];
	int starX[128];
	int starY[128];
	int starZ[128];
	int starRange = 2500;
	int maxd = 150;
	int cx,cy,cz;
	int maxX=640;
	int maxY=480;
	float cosT = 0.9848;
	float sinT = 0.1736;
	float rx, ry;

	for(i=0;i<128;i++)	{
		starX[i]=starRange-2*(rand()%starRange);
		starY[i]=starRange-2*(rand()%starRange);
		starZ[i]=rand()%maxd;
		}
	//rx = starX[i]*cosT-starY[i]*sinT;
	//ry = starY[i]*cosT+starY[i]*sinT;	

		x1=150;
	y1=150;
	vdp_mode(0);
	vdp_cls();
	vdp_fgcolour(255,255,255);
	
	
	running=TRUE;
	while(running)
	{
		key = getfullkeycode();
		
		for(i=0;i<128;i++)	{
			starZ[i]=starZ[i]-1;
			if(starZ[i]<=0) {
				starZ[i]=maxd;
				starX[i]=starRange-2*(rand()%starRange);
				starY[i]=starRange-2*(rand()%starRange);
				starZ[i]=rand()%maxd;
				}		
			}
		vdp_cls();
		for(i=0;i<128;i++)	{
			cz = starZ[i];
			cx = starX[i]/cz;
			cy = starY[i]/cz;
			
			if((cx<-320) || (cx>320)) {
				starZ[i]=maxd;
				starX[i]=starRange-2*(rand()%starRange);
				starY[i]=starRange-2*(rand()%starRange);
				starZ[i]=rand()%maxd;
				}
			if((cy<-240) || (cy>240)) {
				starZ[i]=maxd;
				starX[i]=starRange-2*(rand()%starRange);
				starY[i]=starRange-2*(rand()%starRange);
				starZ[i]=rand()%maxd;
				}	
			plot(255,320+cx,240+cy);
		}
		
				
		
		switch( (key&0xFF))
			{
				case 0x0a:
						//puts("DOWN");
						y1++;
						plot(255,x1,y1);
						for(i=0;i<128;i++)	{
							starY[i]=starY[i]-200;
							}		
						break;
				case 0x0b:
						//puts("UP");
						y1--;
						plot(255,x1,y1);
						for(i=0;i<128;i++)	{
							starY[i]=starY[i]+200;
							}		
						break;
				case 0x08:
						//puts("LEFT");
						x1--;
						plot(255,x1,y1);
						for(i=0;i<128;i++)	{
							starX[i]=starX[i]-200;
							}		
						break;
				case 0x15:
						//puts("RIGHT");
						x1++;
						plot(255,x1,y1);
						starX[i]=starX[i]+200;
						break;
				
				case 0x20:
						//puts("SPACE");												
						x1 = 133;
						y1 = 133;
						vdp_cls();
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

