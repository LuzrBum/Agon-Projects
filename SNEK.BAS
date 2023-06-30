   10 ON ERROR GOTO 460
   20 MODE 1:VDU 23,1,0 : REM DISABLE TEXT CURSOR
   30 PRINT:PRINT " SNEK for the Agon light (TM) by www.luzrbum.com 2023":PRINT "   created for the 3rd Olimex Coding Challenge...":
   30 PRINT " ...however I missed the deadline, so submitting just for fun!":PRINT "   Design objective was maximum Blinkenlights per line of code.":
   40 PRINT:PRINT:PRINT "     Use WASD to control.":PRINT "     Try to survive as long as possible.":PRINT:PRINT "       Press any key to start."
   50 z$=GET$
   60 CLS : GCOL 0,2
   70 dir%=3
   80 count%=0
   90 REPEAT
  100   k$=INKEY$(1)
  110   rotate%=count% MOD 64
  120   GCOL 0,rotate%
  130   MOVE 640,512
  140   PLOT 148,640,512+10
  150   IF (k$="w" OR k$="W") THEN dir%=2
  160   IF (k$="s" OR k$="S") THEN dir%=3
  170   IF (k$="d" OR k$="D") THEN dir%=1
  180   IF (k$="a" OR k$="A") THEN dir%=0
  190   IF FN_collision >0 THEN GOTO 250
  200   VDU 23,7,1,dir%,1:REM Scroll
  210   IF rotate% MOD 16=0 THEN PROC_colourRotate
  220   PROC_sprinkle
  230   count%=count%+1
  240 UNTIL FALSE
  250 PRINT TAB(10,10)"You completed the Kessel run in ";count%;" parsecs.":FOR count%=0 TO 5000:z$=" ":NEXT
  260 PRINT TAB(10,12)"     Press any key to try again."
  270 z$=GET$
  280 count%=0:GOTO 60
  290 END
  300 DEF FN_collision
  310 crash%=0
  320 IF (dir%=2 AND POINT(640,512+11)>0) THEN crash%=1
  330 IF (dir%=3 AND POINT(640,512-11)>0) THEN crash%=1
  340 IF (dir%=1 AND POINT(640+11,512)>0) THEN crash%=1
  350 IF (dir%=0 AND POINT(640-11,512)>0) THEN crash%=1
  360 = crash%
  370 DEF PROC_sprinkle
  380 IF (dir%=2 AND RND(16)<=2) THEN temp%=RND(1280-11):MOVE temp%,1024-11:PLOT 148,temp%,1023
  390 IF (dir%=3 AND RND(16)<=2) THEN temp%=RND(1280-11):MOVE temp%,11:PLOT 148,temp%,1
  400 IF (dir%=1 AND RND(16)<=2) THEN temp%=RND(1024-11):MOVE 1280-11,temp%:PLOT 148,1279,temp%
  410 IF (dir%=0 AND RND(16)<=2) THEN temp%=RND(1024-11):MOVE 11,temp%:PLOT 148,1,temp%
  420 ENDPROC
  430 DEF PROC_colourRotate
  440 FOR i% = 1 TO 64:COLOUR i%,RND(256):NEXT
  450 ENDPROC
  460 VDU 23,1,1: REM RE-ENABLE TEXT CURSOR
  470 REPORT
  480 PRINT" at line ";ERL
