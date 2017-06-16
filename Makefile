all: avlout

avlout: AVLTree.o Main.o Z_Obj.o ZDatabase.o ZNode.o 
	g++  -g AVLTree.o Main.o Z_Obj.o ZDatabase.o ZNode.o -std=c++11 -o avlout

Main.o: Main.cpp
	g++ -g -c -std=c++11 Main.cpp
	
AVLTree.o: AVLTree.cpp
	g++ -g -c -std=c++11 AVLTree.cpp


Z_Obj.o: Z_Obj.cpp
	g++ -g -c -std=c++11 Z_Obj.cpp
	
ZDatabase.o: ZDatabase.cpp
	g++ -g -c -std=c++11 ZDatabase.cpp
	
ZNode.o: ZNode.cpp
	g++ -g -c -std=c++11 ZNode.cpp
	

clean:
	rm *.o avlout