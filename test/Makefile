CC     = clang
CFLAGS = -I..

SRC    = ./main.c
LIB    = ./lazy-test.h ./pretty-test.h

TARGET = ./test

all: $(TARGET)

$(TARGET): $(SRC) $(LIB)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
