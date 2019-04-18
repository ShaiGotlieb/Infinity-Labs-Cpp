CC=g++
CPPFLAGS=-pedantic -Werror -Wall -Wextra
SRCS = default_parameters.cpp
DEPFLAGS ?= -MMD -MP
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)
.PHONY: all
all: a.out
a.out: default_parameters.o
	$(CC) ${CPPFLAGS} default_parameters.o -o $@
default_parameters.o: default_parameters.cpp
	$(CC) -c $(CPPFLAGS) $(DEPFLAGS) default_parameters.cpp -o $@
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
