CC=g++
CPPFLAGS=-pedantic -Wall -Wextra -g
SRCS = ctor_dtor.cpp 
DEPFLAGS ?= -MMD -MP
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)
.PHONY: all
all: a.out
a.out: ctor_dtor.o 
	$(CC) ${CPPFLAGS} ctor_dtor.o  -o $@
ctor_dtor.o: ctor_dtor.cpp 
	$(CC) -c $(CPPFLAGS) $(DEPFLAGS) ctor_dtor.cpp -o $@
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
