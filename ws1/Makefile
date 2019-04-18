CC=g++
CPPFLAGS=-pedantic -Werror -Wall -Wextra
SRCS = ws1.cpp
DEPFLAGS ?= -MMD -MP
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)
.PHONY: all
all: a.out
a.out: ws1.o
	$(CC) ${CPPFLAGS} ws1.o -o $@
ws1.o: ws1.cpp
	$(CC) -c $(CPPFLAGS) $(DEPFLAGS) ws1.cpp -o $@
.PHONY: g11
g11: CC += -std=c++11
.PHONY: gp
gp: all
.PHONY: gpr
gpr: CPPFLAGS +=  -DNDEBUG -O3
gpr: all
.PHONY: debug
debug:
	echo $(TARGET_LIB)
.PHONY: clean
clean:
	rm -f *.o *.d
