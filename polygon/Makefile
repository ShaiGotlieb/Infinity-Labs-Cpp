CC=g++
CPPFLAGS=-pedantic -Wall -Wextra 
SRCS = polygon.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: polygon.o libpoint.so
.PHONY: test
test : a.out all
a.out: polygon.o test_polygon.o point.o
	$(CC) ${CPPFLAGS} $^ -o $@
polygon.o: polygon.cpp polygon.hpp ../point/point.hpp
	$(CC) -c $(CPPFLAGS) -I../point/ polygon.cpp -o $@ 
test_polygon.o: test_polygon.cpp polygon.hpp
libpoint.so : point.o
	$(CC) -shared -o libpoint.so   point.o 
point.o : ../point/point.cpp
	$(CC) -c -fpic ${CPPFLAGS} ../point/point.cpp -o $@

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
