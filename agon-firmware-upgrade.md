# Upgrading MOS and VDP on an Agon light 
Complete and tested(-ish) steps to update Agon Light from 1.02 to latest
I more or less successfully stumbled through thesesteps in this livestream https://www.youtube.com/live/1YSsFT5JrCM and https://www.youtube.com/live/7eSDdzOzUZU

# Procure required HW
- Agon + microSD
- PC (Win10 in my case) with microSD slot
- USB-C cable

# Download required SW  
- BBC Basic 1.04 RC3 https://github.com/breakintoprogram/agon-bbc-basic/releases/tag/v1.04-RC3
-
- https://github.com/breakintoprogram/agon-vdp/releases/tag/v1.03-RC3
- Arduino IDE https://www.arduino.cc/en/software
- using version 1.8.19 for now (to avoid the python serial error) 
-
- https://github.com/breakintoprogram/agon-mos/releases/tag/v1.03-RC3
- MOS update utility https://github.com/envenomator/agon-flash/releases/tag/v1.2
- If you need to create  a CRC code for your VDP version https://simplycalc.com/crc32-file.php


# UPGRADE
- Always do the MOS first while the Agon is in a stable config because it needs to be launched from MOS command line. MOS update may break screen/keyboard, then you cannot type the command anymore. Then do the VDP second.

## Prep
- Download
- Tidy up your SD Card (optional)
- Copy BBC Basic 1.04 RC3 to the SD card (because why the hell not) + sa
## MOS
- Copy MOS Update utility (to /MOS) & MOS.bin (to /root) to  SD card https://github.com/envenomator/agon-flash 
- Get CRC for MOS version 86696B8A for MOS 1.03 RC3 (different for each version)
- Transfer SD card to Agon and boot Agon
- Flash MOS = Usage: "FLASH \<filename> \<crc32>"
- Test - you may not be able to type and or screen will look weird because MOS is now speaking differently
## VDP
- Install Arduino IDE
- Config Arduino IDE - follow ALL instructions https://github.com/breakintoprogram/agon-vdp , enter the URL + install the board, also install the two libraries selecting the right version
- Open the folder of your VDP version - no
- Disconnect power & flip jumper x2
- connect USB-C to Agon and PC
- Determine COM port (I had to go into windows devide manager and disable Bluetooth that was hogging COM3 and COM4)
- Update VDP: Menu - Sketch - Upload, or press ctrl+U
- Wait for successfu write: You will see successful write at the bottom of the Arduino IDE screen, and you should see VDP come up on your VGA screen 
- Reconnect power & flip jumper x2
- Test

  
