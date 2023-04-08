Complete and tested(-ish) steps to update Agon Light from 1.02 to latest

# Procure required HW
- Agon + microSD
- PC (Win10 in my case) with microSD slot
- USB-C cable

# Download required SW  
- BBC Basic 1.04 RC3 https://github.com/breakintoprogram/agon-bbc-basic/releases/tag/v1.04-RC3
- This requires VDP 1.03 RC3 and MOS 1.03 RC3
-
- VDP https://github.com/breakintoprogram/agon-vdp
- https://github.com/breakintoprogram/agon-vdp/releases/tag/v1.03-RC3
- Arduino IDE https://www.arduino.cc/en/software
- using version 1.8.19 for now (to avoid the python serial error) 
-
- MOS https://github.com/breakintoprogram/agon-mos
- https://github.com/breakintoprogram/agon-mos/releases/tag/v1.03-RC3
- A CRC code for your version https://simplycalc.com/crc32-file.php
- MOS update utility https://github.com/envenomator/agon-flash 
- https://github.com/envenomator/agon-flash/releases/tag/v1.2

# UPGRADE
## Prep
- Tidy up your SD Card (optional)
- Copy BBC Basic 1.04 RC3 to the SD card (because why the hell not)
## MOS
- Copy MOS Update utility (to /MOS) & MOS.bin (to /root) to  SD card https://github.com/envenomator/agon-flash 
- Get CRC for MOS version 86696B8A for MOS 1.03 RC3 (different)
- Transfer SD card to Agon and boot Agon
- Flash MOS = Usage: "FLASH \<filename> \<crc32>"
- Test
## VDP
- Install Arduino SW
- Config Arduino SW https://github.com/breakintoprogram/agon-vdp
- Disconnect power & flip jumper x2
- connect USB-C
- Determine COM port
- Update arduino
- Reconnect power & flip jumper x2
- Test

  
