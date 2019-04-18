CC=g++
CPPFLAGS=-pedantic -Wall -Wextra
SRCS = shape.cpp test_shape.cpp rectangle.cpp square.cpp line.cpp circle.cpp group.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all:a.out
a.out: shape.o test_shape.o rectangle.o circle.o square.o line.o group.o
	$(CC) ${CPPFLAGS} $^ -o $@  -Wl,-rpath=. ../lib/libglut_utils.so ../lib/libpoint.a
rectangle.o: rectangle.cpp ../include/rectangle.hpp
	$(CC) -c $(CPPFLAGS) rectangle.cpp -I ../include -o $@ 
shape.o: shape.cpp ../include/shape.hpp
	$(CC) -c $(CPPFLAGS) shape.cpp -I ../include -o $@ 
square.o: square.cpp ../include/square.hpp
	$(CC) -c $(CPPFLAGS) square.cpp -I ../include -o $@ 
line.o: line.cpp ../include/line.hpp
	$(CC) -c $(CPPFLAGS) line.cpp -I ../include -o $@ 
circle.o: circle.cpp ../include/circle.hpp
	$(CC) -c $(CPPFLAGS) circle.cpp -I ../include -o $@ 
group.o: group.cpp ../include/group.hpp
	$(CC) -c $(CPPFLAGS) group.cpp -I ../include -o $@ 
test_shape.o: test_shape.cpp ../include/shape.hpp 
	$(CC) -c $(CPPFLAGS) -I ../include test_shape.cpp -o $@

.PHONY: gc11
gc11: CC += -std=c++11 -Werror
gc11: all

.PHONY: gd11
gd11: CC += -std=c++11 -Werror -g
gd11: all

.PHONY: gdp
gdp: CPPFLAGS += -std=c++98 -g
gdp: all

.PHONY: gdpp
gdpp: CPPFLAGS += -std=c++98 -Werror -g
gdpp: all

.PHONY: gcp
gcp: CPPFLAGS += -std=c++98 -Werror -DNDEBUG -O3
gcp: all

.PHONY: debug
debug:
	echo $(TARGET_LIB)

.PHONY: clean
clean:
	rm -f *.o
