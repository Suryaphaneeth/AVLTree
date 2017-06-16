#include <stdlib.h>
#include <string>
#include "ZDatabase.hpp"
using namespace std;


int main() {
	//string g = "zipcodes.txt";  The full file – after you have everything 
	// working
	string h = "ziptestfile.txt";  // for testing purposes
	cout <<"BINARY SEARCH TREE:" << endl<<"__________________________" <<endl;
	ZDatabase *zdb = new ZDatabase(h,false);
	cout <<endl<<"AVL TREE:" << endl<<"__________________________" <<endl;
	ZDatabase *zdb2 = new ZDatabase(h,true);
	return 0;
}
