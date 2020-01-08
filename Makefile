# simple Makefile
# Nooreldean Koteb G01085380
# CS262, lab section 209
# Lab10

CC= gcc
CFLAGS=-g -Wall
TARGET= ShoppingCart

all:$(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)
