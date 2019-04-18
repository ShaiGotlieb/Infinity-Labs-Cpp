CC=g++
CPPFLAGS=-pedantic -Werror -Wall -Wextra
SRCS = function_overloading.cpp
DEPFLAGS ?= -MMD -MP
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)
.PHONY: all
all: a.out
a.out: function_overloading.o
	$(CC) ${CPPFLAGS} function_overloading.o -o $@
function_overloading.o: function_overloading.cpp
	$(CC) -c $(CPPFLAGS) $(DEPFLAGS) function_overloading.cpp -o $@
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
