CC=g++
CPPFLAGS=-pedantic -Wall -Wextra
SRCS = stack.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: gdp
gdp: CPPFLAGS += -std=c++98 -g
gdp: all

.PHONY: all
all: a.out
a.out: stack.o test_stack.o ~/git/fs_cpp/string/string.o
	$(CC) ${CPPFLAGS} $^ -o $@
stack.o: stack.cpp stack.hpp
	$(CC) -c $(CPPFLAGS) stack.cpp -o $@
test_stack.o: test_stack.cpp stack.hpp ~/git/fs_cpp/utils/test.hpp 
	$(CC) -c $(CPPFLAGS) -I ~/git/fs_cpp/utils/ -I ~/git/fs_cpp/string test_stack.cpp -o $@

.PHONY: gc11
gc11: CC += -std=c++11 -Werror
gc11: all

.PHONY: gd11
gd11: CC += -std=c++11 -Werror -g
gd11: all

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
