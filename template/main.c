#include <stdio.h >
#include <ctype.h>
#include "mos-interface.h"
#include "vdp.h"
#include "agontimer.h"


	
int main(int argc, char * argv[]) { 
	UINT16 received,key,keycount;
	UINT8 resultTX;
	int resultRX;
	BOOL running;
	UART myUART1;
	UART *mypUART=&myUART1;
	char myString[];
	
	
	myUART1.baudRate=38400;
	myUART1.dataBits =8;				//!< The number of databits per character to be used.
	myUART1.stopBits =1;				//!< The number of stopbits to be used.
	myUART1.parity=0;				   //!< The parity bit option to be used.
    myUART1.flowcontrol =0;
	myUART1.eir =0;
	vdp_mode(3);
	mos_uopen(mypUART);
	puts("Opened serial port on UART1 = Pins 14&15 \r\n");

    keycount = getsysvar_vkeycount();
    
	running=TRUE;
    while (running) {
        
        if (getsysvar_vkeycount() != keycount && getsysvar_vkeydown() == 1) { 
			key=getsysvar_keyascii();
			mos_uputc(key);
			keycount = getsysvar_vkeycount();
			switch( (key&0xFF)) {	
			
				case 0x1b:
						puts("ESC - BYE");
						running = FALSE;					
				default:						
						break;								
				}
			}
		received = mos_ugetc();
		if(received>255) {
			printf("%c",received&0xFF);
			}	
		
    }

	puts("Clean exit.");
	return 0;
}

