# Agon-Projects
Various coding experiments for the Agon 

# fullkeycode
* Project for use with ZDS II https://www.zilog.com/index.php?option=com_zcm&task=view&soft_id=38&Itemid=74
* based on original https://github.com/envenomator/Agon/tree/master/scratch
* Was not able to rename the folder LOL
* Copy the entire folder to your PC
* you may have to adjust the paths in fullkeycode.linkcmd to match the location of your ZDS
* I have 3 versions of "main.c" in the folder-01, -02, -03, copy the contents to main.c and Rebuild All
* Grab fullkeycode.hex file from Debug folder, then hex2bin, then transfer to your SD card
* main-01 = Move an X across the screen with Arrow keys
* main-02 = MOVE a pixel across the screen with Arrow keys AND an X across the screen with ASDW
* main-03 = starfield simulation

* note change in mos-keycode.asm = commented out the waitkey so it just loops even with no keypress
