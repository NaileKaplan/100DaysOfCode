# for C++ define  CC = g++
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g

SRC    = $(wildcard *.cpp)
HEADER = $(wildcard *.h)
OBJS   = $(SRC:%.cpp=%.o)
TARGET = castingOp

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

all:	$(TARGET)

clean:
	rm -rf $(OBJS) $(TARGET)
