Source https://github.com/nihirash/Agon-MOS-Tools/tree/main/esp8266/snail
# 1-time Prep Usage
- Download netman from https://github.com/nihirash/Agon-MOS-Tools/tree/main/esp8266/netman 
- ... and place in /mos folder
- Connect to access point via it TBD

- Download esp-at-tester from https://github.com/nihirash/Agon-MOS-Tools/tree/main/esp8266/esp-at-tester
- ...and execute it(This step should be replaced with esp-update but it don't work correctly and I don't know why)
- Check firmware version with AT+GMR command(they're case sensitive). If it less than 1.7.5.0(Oct 20 2021):
- Call Over The Air update with command AT+CIUPDATE
- When it will be completed check firmware version with AT+GMR - it should be 1.7.5.0(Oct 20 2021) or later
- Reset your wifi module with AT+RST command and restore "factory defaults" with command AT+RESTORE

Exit from this utility with BYE command


Run netman again and connect access point.

# Actual usage
- Download snail.bin from TBD (note dfiferent bin for VDP 1.04 and above)
- and put it into some directory of Agon's SD card
- Enter directory from MOS and call LOAD SNAIL.BIN and RUN
- Enjoy gopherspace

