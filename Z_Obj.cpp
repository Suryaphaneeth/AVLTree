#include <string>
#include <iostream>
#include <cstdlib>
#include "Z_Obj.hpp"

using namespace std;

Z_Obj::Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo):
            zip(z), city(ct), state(st), abbr(ab), county(cnty), lat(la), lon(lo){
}

bool Z_Obj::operator<(Z_Obj z){
    return (zip < z.zip);
}

ostream& operator<<(ostream& os, const Z_Obj& z){
    os << endl << "Zip: " << z.zip << ", City: " << z.city << ",  State: " << z.state << ", abbr: "
        << z.abbr << ", County: " << z.county << ", latitude: " << z.lat << ", longitude: " 
        << z.lon ;
    return os;
}

