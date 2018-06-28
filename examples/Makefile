CC = gcc
CFLAGS = -Wall
INCLUDES = -I deps/include
LDFLAGS = -ldl -lm -lglfw
TARGET = cube
SRC = deps/src/glad.c $(TARGET).c

all: $(TARGET)

${TARGET}:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LDFLAGS)
