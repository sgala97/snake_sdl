CC = g++
CFLAGS = -w -g 
LFLAGS = -lSDL2
SRC = src/main.cpp src/init.cpp src/RenderWindow.cpp src/funciones.cpp src/snake.cpp src/coin.cpp
HPP = src/init.hpp src/RenderWindow.hpp src/funciones.hpp src/snake.hpp src/coin.hpp

main: $(SRC) $(HPP)
	$(CC) $(CFLAGS) $(LFLAGS) $(SRC) -o main
