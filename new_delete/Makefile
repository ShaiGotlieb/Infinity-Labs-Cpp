CC=g++
CPPFLAGS=-pedantic -Wall -Wextra -g
SRCS = new_delete.cpp test_new_delete.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: a.out
a.out: new_delete.o test_new_delete.o
	$(CC) ${CPPFLAGS} $^ -o $@
new_delete.o: new_delete.cpp new_delete.hpp
	$(CC) -c $(CPPFLAGS) new_delete.cpp -o $@
test_new_delete.o: test_new_delete.cpp new_delete.cpp new_delete.hpp
	$(CC) -c $(CPPFLAGS) test_new_delete.cpp -o $@

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
