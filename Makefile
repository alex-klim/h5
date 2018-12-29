CPPFLAGS = -std=c++11 -Wall -Wpedantic

.PHONY: all clean re

all: main

main:
	g++ ${CPPFLAGS} -o main main.cpp port.cpp vintage_port.cpp

clean:
	/bin/rm -f main

re: clean all
