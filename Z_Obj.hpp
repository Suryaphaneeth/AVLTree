#ifndef Z_OBJ_HPP_
#define Z_OBJ_HPP_

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Z_Obj {
	friend class ZNode;
	friend class AVLTree;
	friend class ZDatabase;
	int zip;
	string city;
	string state;
	string abbr;
	string county;
	float lat;
	float lon;
public:
	Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo);
//	void printZ();
	friend ostream& operator<<(ostream& os, const Z_Obj& z);
//	If you want to override << so you can just use cout to print your Z_Objs.
    bool operator< (Z_Obj z);
//	bool lessThan(Z_Obj *z);
};

#endif /* Z_OBJ_HPP_ */