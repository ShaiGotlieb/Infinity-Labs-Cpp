CC=g++
CPPFLAGS=-pedantic -Wall -Wextra
SRCS = surpriser.cpp test_surprise.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: gdp
gdp: CPPFLAGS += -std=c++98 -g
gdp: all

.PHONY: all
all: a.out
a.out: surpriser.o test_surprise.o PrintSurprise.o PrintEcho.o FileSurprise.o
	$(CC) ${CPPFLAGS} $^ -o $@
surpriser.o: surpriser.cpp surpriser.hpp
	$(CC) -c $(CPPFLAGS) surpriser.cpp -o $@
PrintSurprise.o: PrintSurprise.cpp PrintSurprise.hpp
	$(CC) -c $(CPPFLAGS) PrintSurprise.cpp -o $@
PrintEcho.o: PrintEcho.cpp PrintEcho.hpp
	$(CC) -c $(CPPFLAGS) PrintEcho.cpp -o $@
FileSurprise.o: FileSurprise.cpp FileSurprise.hpp
	$(CC) -c $(CPPFLAGS) FileSurprise.cpp -o $@
test_surprise.o: test_surprise.cpp surpriser.hpp PrintSurprise.hpp PrintEcho.hpp FileSurprise.hpp ~/git/fs_cpp/utils/test.hpp
	$(CC) -c $(CPPFLAGS) -I ~/git/fs_cpp/utils/ test_surprise.cpp -o $@

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
	rm -f *.o *.txt
