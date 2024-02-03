# Agon-Projects
Various coding experiments for the Agon Light SBC - described here https://www.thebyteattic.com/p/agon.html  

LOTS OF SOFTWARE HERE https://github.com/sabotrax/agon-software

# MOS & VDP update walkthrough
- New "flash" tool from envenomator https://github.com/envenomator/agon-flash does both VDP and MOS (!) Easy to up/downgrade
- Shown  in this video https://youtu.be/iLz1VUNjSAU
- Binaries https://github.com/envenomator/agon-binaries/tree/master and https://github.com/AgonConsole8
- OLD SKOOL version if below MOS 1.04 RC1 https://github.com/LuzrBum/Agon-Projects/blob/main/agon-firmware-upgrade.md
- I more or less successfully stumbled thorough these in this livestream https://www.youtube.com/live/1YSsFT5JrCM and https://www.youtube.com/live/7eSDdzOzUZU

# Agon Ascii Star Wars
- https://github.com/LuzrBum/Agon-Projects/tree/main/ASW

 # "WordyBird" game 
- https://github.com/LuzrBum/Agon-Projects/tree/main/WordyBird
- My submission for this challenge:  
https://olimex.wordpress.com/2023/05/05/agonlight-weekend-programming-challenge-issue-2/
- I "won"- YouTube news report https://www.youtube.com/watch?v=9VNhshYAGQ0

# "SNEK" game
- For 3rd Week Olimex Coding challenge 2023 https://olimex.wordpress.com/2023/06/02/agonlight-week-programming-challenge-issue-3/
- YouTube video https://youtu.be/bDwvFlDvt2M
- https://github.com/LuzrBum/Agon-Projects/blob/main/snek.bbc
- BAS version (=plaintext) https://github.com/LuzrBum/Agon-Projects/blob/main/SNEK.BAS
- 
# Emulation
See Sabotrax link up top 

# "Simon" game 
- for Olimex weekend Coding Challenge April 2023 https://olimex.wordpress.com/2023/04/21/agonlight-weekend-programming-challenge-issue-1/
- for YouTube Video https://youtu.be/oXMx9FPrQQU
- Original 1983 vesrion by D.Whitworth from https://www.bbcmicro.co.uk/game.php?id=3163

# Serial terminal (e.g. to Raspberry Pi console)  
- https://github.com/LuzrBum/Agon-Projects/tree/main/AgonTerm/template

# fullkeycode
Below Discussed in the video https://www.youtube.com/watch?v=S7iilqWDxNE
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
