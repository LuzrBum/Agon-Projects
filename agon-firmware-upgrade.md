# This is thankfully outdated, keeping below for reference (and anyone below 1.04 RC1)
- New "flash" tool from envenomator https://github.com/envenomator/agon-flash does both VDP and MOS (!)
- Easy to up/downgrade
- See also in this video https://youtu.be/iLz1VUNjSAU
- Binaries https://github.com/envenomator/agon-binaries/tree/master and https://github.com/AgonConsole8




# Upgrading MOS and VDP on an Agon light OLD SKOOL
- Complete and tested(-ish) steps to update Agon Light from ~~1.02~~ 1.03-RC3 to latest (1.03 Official Release)
- More or less successfully stumbled through these steps in this livestream https://www.youtube.com/live/1YSsFT5JrCM and https://www.youtube.com/live/7eSDdzOzUZU

# Procure required HW
- Agon + microSD
- PC (Win10 in my case) with microSD slot
- USB-C cable

# Download required SW  
- MOS 1.03 Final binary https://github.com/breakintoprogram/agon-mos/releases/download/v1.03/MOS.bin
- MOS update utility https://github.com/envenomator/agon-flash/releases/download/v1.2/flash.bin
- If you need to create  a CRC code for your VDP version https://simplycalc.com/crc32-file.php
-
- VDP1.03 Final https://github.com/breakintoprogram/agon-vdp/archive/refs/tags/v1.03.zip
- Extract the Zip, and rename the folder containing the source to "video"
- Arduino IDE https://www.arduino.cc/en/software
- using version IDE 1.8.19 for now (to avoid the python serial error)
-
- BBC Basic 1.04 Final binary https://github.com/breakintoprogram/agon-bbc-basic/releases/download/v1.04/bbcbasic.bin
- BBC Basic "examples" & "tests" & "resources" folders from https://github.com/breakintoprogram/agon-bbc-basic/archive/refs/tags/v1.04.zip
-
# UPGRADE
- Always do the MOS first while the Agon is in a stable config because it needs to be launched from MOS command line. MOS update may break screen/keyboard, then you cannot type the command anymore. Then do the VDP second.
- 
## Prep
- Download
- Tidy up your SD Card (optional)
- Copy BBC Basic 1.04 Final to the SD card + all sample files (optional but good for testing)
-  
## MOS
- Copy MOS Update utility "flash.bin" to (to /MOS) & MOS.bin (to /root) to  SD card
- Get CRC for MOS version ~~0x86696B8A for MOS 1.03 RC3~~ 0x81E397C9 for MOS 1.03 Final (different for each version)
- Transfer SD card to Agon and boot Agon
- Flash MOS = Usage: "FLASH \<filename> \<crc32>"
- Test - you may not be able to type and or screen will look weird because MOS is now speaking differently
- 
## VDP
- Install Arduino IDE
- Config Arduino IDE - follow ALL instructions https://github.com/breakintoprogram/agon-vdp , enter the URL + install the board, also install the two libraries selecting the right version (note: since 1.04x, it uses vdp-gl instead of fab-gl) 
- Open the folder of your VDP version
- Disconnect power ~~& flip jumper x2 (ON)
- connect USB-C to Agon and PC
- Determine COM port (I had to go into windows devide manager and disable Bluetooth that was hogging COM3 and COM4)
- Update VDP: Menu - Sketch - Upload, or press ctrl+U
- Wait for successfu write: You will see successful write at the bottom of the Arduino IDE screen, and you should see VDP come up on your VGA screen 
- ~~Flip jumper x2 (OFF) &~~ Reconnect power
- Test 

  
