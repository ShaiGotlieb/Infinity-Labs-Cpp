CC=g++
CPPFLAGS=-pedantic -Wall -Wextra
SRCS = fraction.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: a.out
a.out: fraction.o test_fraction.o
	$(CC) ${CPPFLAGS} $^ -o $@
test_fraction.o: test_fraction.cpp fraction.cpp fraction.hpp
	$(CC) -c $(CPPFLAGS) test_fraction.cpp -o $@

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
