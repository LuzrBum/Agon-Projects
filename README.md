# Agon-Projects
Various coding experiments for the Agon Light https://www.thebyteattic.com/p/agon.html  
Discussed in the video https://youtu.be/S7iilqWDxNE
# MOS & VDP update walkthorugh
https://github.com/LuzrBum/Agon-Projects/blob/main/agon-firmware-upgrade.md

# fullkeycode
* Project for use with ZDS II https://www.zilog.com/index.php?option=com_zcm&task=view&soft_id=38&Itemid=74
* based on original https://github.com/envenomator/Agon/tree/master/scratch, it is called "fullkeycode" because I was not able to rename the project....
* Copy the entire folder to your PC
* you may have to adjust the paths in fullkeycode.linkcmd to match the location of your ZDS
* Grab fullkeycode.hex file from Debug folder, then hex2bin, then transfer to your SD card
* https://sourceforge.net/projects/hex2bin/


* I have 3 versions of "main.c" in the folder-01, -02, -03, copy the contents to main.c and Rebuild All
* main-01 = Move an X across the screen with Arrow keys
* main-02 = MOVE a pixel across the screen with Arrow keys AND an X across the screen with ASDW
* main-03 = STARFIELD SIMULATION - THIS IS THE DEFAULT

* note change in mos-keycode.asm = commented out the waitkey so it just loops even with no keypress

# StarFieldInBBCBasic
The BBC Basic file from the video 
