EXENAME = hockeyPool
OBJS = main.o linked_list.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lpthread -lm

all : &(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

linked_list.o : linked_list.h linked_list.cpp
	${CXX} ${CXXFLAGS} -c linked_list.cpp

main.o: linked_list.h linked_list.cpp
	$(CXX) $(CXXFLAGS) main.cpp 

main: main.o linked_list.o
	${CC} ${CFLAGS} -o main main.o linked_list.o

clean: 
	${RM} *.o main