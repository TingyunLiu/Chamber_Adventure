CXX = g++
CXXFLAGS = -MMD -g
EXEC = cc3k
OBJECTS = main.o game.o floor.o item.o poison.o gold.o character.o player.o enemy.o shade.o goblin.o vampire.o drow.o troll.o human.o merchant.o dwarf.o halfling.o elf.o orc.o dragon.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
