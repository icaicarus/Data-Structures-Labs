CC = g++
CFLAGS = -I. -I../inc -g
OBJ = objPos.o objPosArrayList.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o objPosDLinkedList.o
DEPS = *.h

ifeq (${OS}, Windows_NT)
	OSSETTING = -DWINDOWS
else
	OSSETTING = -DPOSIX
	POSTLINKER = -lncurses   
endif

EXEC = Project

%.o: %.cpp $(DEPENDS)
	$(CC) ${OSSETTING} -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJ)
	$(CC)  ${OSSETTING} -o $@ $^ $(CFLAGS) ${POSTLINKER}

clean :
	rm -rf ${OBJ} ${EXEC} ${EXEC}.exe

