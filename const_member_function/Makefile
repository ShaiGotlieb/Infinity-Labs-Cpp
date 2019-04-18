CC=g++
CPPFLAGS=-pedantic -Werror -Wall -Wextra
SRCS = const_member_function.cpp
DEPFLAGS ?= -MMD -MP
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
-include $(DEPS)
.PHONY: all
all: a.out
a.out: const_member_function.o
	$(CC) ${CPPFLAGS} const_member_function.o -o $@
const_member_function.o: const_member_function.cpp
	$(CC) -c $(CPPFLAGS) $(DEPFLAGS) const_member_function.cpp -o $@
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
