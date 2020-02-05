linkedList: main.o linked_list.o Executive.o node.o
	g++ -g -std=c++11 -Wall main.o Executive.o linked_list.o node.o -o linkedList

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

node.o: node.h node.cpp
	g++ -g -std=c++11 -Wall -c node.cpp

linked_list.o: linked_list.cpp node.h
	g++ -g -std=c++11 -Wall -c linked_list.cpp

Executive.o: Executive.cpp linked_list.h node.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

clean:
	rm *.o linkedList
