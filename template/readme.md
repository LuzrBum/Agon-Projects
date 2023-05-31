# Serial terminal
- requires flashing slightly hacked MOS based on 1.04RC1 Only modifies serial/UART1
- actual terminal program is "MUD.BIN"
- Both in "BINARIES" folder
- Code builds OK with ZDS 5.3.4

# Raspberry pi: 
- "sudo raspi-config", interfaces, Serial console , enable (something like that)
- After reboot "sudo nano /boot/cmdline.txt", change speed from 115200 to 38400 and reboot

# Wiring
| FUNCTION | AGON | RASPI |
| GND | 3 | 3 |
| RX-TX | 14 | 4 |
| TX-RX | 15 | 5 |
