# for C++ define  CC = g++
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g

SRC    = $(wildcard *.cpp)
HEADER = $(wildcard *.h)
OBJS   = $(SRC:%.cpp=%.o)
TARGET = mapExample

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

all:	$(TARGET)

clean:
	rm -rf $(OBJS) $(TARGET)
install:
	cp $(TARGET) /usr/local/bin
