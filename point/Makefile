CC=g++
CPPFLAGS=-pedantic -Wall -Wextra
SRCS = point.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: a.out
a.out: point.o point_test.o
	$(CC) ${CPPFLAGS} $^ -o $@
point_test.o: point_test.cpp point.cpp point.hpp
	$(CC) -c $(CPPFLAGS) point_test.cpp -o $@

.PHONY: gc11
gc11: CC += -std=c++11 -Werror
gc11: all

.PHONY: gd11
gd11: CC += -std=c++11 -Werror -g
gd11: all

.PHONY: gdp
gdp: CPPFLAGS += -g
gdp: all

.PHONY: gdpp
gdpp: CPPFLAGS += -Werror -g
gdpp: all

.PHONY: gcp
gcp: CPPFLAGS += -Werror -DNDEBUG -O3
gcp: all

.PHONY: debug
debug:
	echo $(TARGET_LIB)

.PHONY: clean
clean:
	rm -f *.o *.d
