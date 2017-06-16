#ifndef ZDATABASE_HPP_
#define ZDATABASE_HPP_

#include "Z_Obj.hpp"
#include "ZNode.hpp"
#include "AVLTree.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class ZDatabase {
	string ifile;
	string ofile;
	AVLTree *ztree;
public:
	ZDatabase(string filename, bool flag);
	void readFile();
	void getZips();
};


#endif /* ZDATABASE_HPP_ */
