CC     = clang
CFLAGS = -I..

PWD=.

SRC    = $(PWD)/main.c
LIB    = $(PWD)/lazy-test.h

TARGET = $(PWD)/test

all: $(TARGET)

$(TARGET): $(SRC) $(LIB)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
