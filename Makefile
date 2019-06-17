PROGRAM=stepaiv3

CC=g++
CFLAGS=-std=c++11 -Wall -pedantic -Wextra -Wno-long-long -O0 -ggdb
NCS=-lncurses
all: compile doc

run: compile
	./$(PROGRAM)

doc: src/main.cpp src/constants.h src/MenuInfo.h src/Coordinate.h src/Player.h src/HumanPlayer.h src/GameBoard.h \
	src/CPUPlayer.h src/NCurGameBoard.h src/NCurCursor.h src/ScreenInfo.h src/Terminal.h src/ServerPlayerListener.h \
	src/ClientPlayerListener.h src/ServerHumanPlayer.h src/ClientHumanPlayer.h src/Server.h src/Client.h src/Menu.h \
	src/OpeningMenu.h src/MainMenu.h src/Option.h src/OptionVal.h src/OptionNumber.h src/OptionString.h src/MoveAdvisor.h \
	src/Game.h src/CFile.h
	doxygen Doxyfile

compile: $(PROGRAM)

$(PROGRAM): objs/main.o objs/Coordinate.o objs/Player.o objs/HumanPlayer.o objs/GameBoard.o objs/CPUPlayer.o objs/NCurGameBoard.o objs/NCurCursor.o objs/ScreenInfo.o \
	objs/Terminal.o objs/ServerPlayerListener.o objs/ClientPlayerListener.o objs/ServerHumanPlayer.o objs/ClientHumanPlayer.o objs/Server.o \
	objs/Client.o objs/Menu.o objs/OpeningMenu.o objs/MainMenu.o objs/Option.o objs/OptionVal.o objs/OptionNumber.o objs/OptionString.o \
	objs/MoveAdvisor.o objs/Game.o objs/CFile.o
	$(CC) $(CFLAGS) $^ -o $@ $(NCS)


objs/main.o: src/main.cpp src/constants.h src/MenuInfo.h src/Client.h src/Coordinate.h src/Server.h src/ScreenInfo.h src/MoveAdvisor.h \
	src/GameBoard.h src/Player.h src/HumanPlayer.h src/NCurCursor.h src/NCurGameBoard.h src/CPUPlayer.h src/ServerHumanPlayer.h \
	src/ClientHumanPlayer.h src/ServerPlayerListener.h src/ClientPlayerListener.h src/Terminal.h src/Option.h src/OptionVal.h src/OptionNumber.h \
	src/OptionString.h src/Menu.h src/OpeningMenu.h src/MainMenu.h src/CFile.h src/Game.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Coordinate.o: src/Coordinate.cpp src/Coordinate.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Player.o: src/Player.cpp src/Player.h src/constants.h src/Coordinate.h |objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/HumanPlayer.o: src/HumanPlayer.cpp src/Player.h src/constants.h src/Coordinate.h src/HumanPlayer.h src/NCurCursor.h \
	src/ScreenInfo.h src/NCurGameBoard.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/GameBoard.o: src/GameBoard.cpp src/GameBoard.h src/constants.h src/Coordinate.h src/Player.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/CPUPlayer.o: src/CPUPlayer.cpp src/CPUPlayer.h src/Coordinate.h src/Player.h src/constants.h src/GameBoard.h src/MoveAdvisor.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/NCurGameBoard.o: src/NCurGameBoard.cpp src/NCurCursor.h src/constants.h src/ScreenInfo.h src/NCurGameBoard.h src/Player.h \
	src/Coordinate.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/NCurCursor.o: src/NCurCursor.cpp src/constants.h src/NCurCursor.h src/ScreenInfo.h src/NCurGameBoard.h src/Player.h src/Coordinate.h \
	src/GameBoard.h src/MoveAdvisor.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/ScreenInfo.o: src/ScreenInfo.cpp src/constants.h src/ScreenInfo.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Terminal.o: src/Terminal.cpp src/Terminal.h src/Coordinate.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/ServerPlayerListener.o: src/ServerPlayerListener.cpp src/ServerPlayerListener.h src/Coordinate.h src/Player.h src/constants.h src/Server.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/ClientPlayerListener.o: src/ClientPlayerListener.cpp src/ClientPlayerListener.h src/Coordinate.h src/Player.h src/constants.h src/Client.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/ServerHumanPlayer.o: src/ServerHumanPlayer.cpp src/ServerHumanPlayer.h src/Coordinate.h src/HumanPlayer.h src/Player.h src/constants.h src/NCurCursor.h \
	src/ScreenInfo.h src/NCurGameBoard.h src/Server.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/ClientHumanPlayer.o: src/ClientHumanPlayer.cpp src/ClientHumanPlayer.h src/Coordinate.h src/HumanPlayer.h src/Player.h src/constants.h src/NCurCursor.h \
	src/ScreenInfo.h src/NCurGameBoard.h src/Client.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Server.o: src/Server.cpp src/Server.h src/Coordinate.h src/constants.h  | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Client.o: src/Client.cpp src/Client.h src/Coordinate.h src/constants.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Menu.o: src/Menu.cpp src/Menu.h src/Coordinate.h src/OptionVal.h src/Option.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/OpeningMenu.o: src/OpeningMenu.cpp src/OpeningMenu.h src/MenuInfo.h src/Client.h src/Coordinate.h src/constants.h src/Server.h src/OptionVal.h src/Option.h \
	src/OptionNumber.h src/OptionString.h src/Menu.h src/MainMenu.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/MainMenu.o: src/MainMenu.cpp src/MainMenu.h src/constants.h src/MenuInfo.h src/Client.h src/Coordinate.h src/Server.h src/OptionVal.h src/Option.h \
	src/OptionNumber.h src/OptionString.h src/Menu.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Option.o: src/Option.cpp src/Option.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/OptionVal.o: src/OptionVal.cpp src/OptionVal.h src/Option.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/OptionNumber.o: src/OptionNumber.cpp src/OptionNumber.h src/OptionVal.h src/Option.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/OptionString.o: src/OptionString.cpp src/OptionString.h src/OptionVal.h src/Option.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/MoveAdvisor.o: src/MoveAdvisor.cpp src/MoveAdvisor.h src/constants.h src/Coordinate.h src/GameBoard.h src/Player.h  | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/Game.o: src/Game.cpp src/Game.h src/constants.h src/MenuInfo.h src/Client.h src/Coordinate.h src/Server.h src/ScreenInfo.h src/Terminal.h src/NCurCursor.h src/NCurGameBoard.h src/Player.h \
	src/GameBoard.h src/CFile.h src/HumanPlayer.h src/CPUPlayer.h src/MoveAdvisor.h src/ServerHumanPlayer.h src/ClientHumanPlayer.h src/ServerPlayerListener.h \
	src/ClientPlayerListener.h | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/CFile.o: src/CFile.cpp src/CFile.h src/MenuInfo.h src/Client.h src/Coordinate.h src/constants.h src/Server.h | objs
	$(CC) $(CFLAGS) -c $< -o $@


objs: 
	mkdir objs

clean:
	rm -rf $(PROGRAM) objs/ doc/ 2>/dev/null