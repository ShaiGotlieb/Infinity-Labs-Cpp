CC=g++
CPPFLAGS=-pedantic -Werror -Wall -Wextra
SRCS = member_function.cpp point_test.cpp
DEPFLAGS ?= -MMD -MP
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)
.PHONY: all
all: a.out
a.out: point_test.o member_function.o member_function.hpp
	$(CC) ${CPPFLAGS} member_function.o point_test.o -o $@
member_function.o: member_function.cpp
	$(CC) -c $(CPPFLAGS) $(DEPFLAGS) member_function.cpp -o $@
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
