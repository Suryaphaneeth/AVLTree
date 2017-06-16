#include <iostream>
#include <string>

using namespace std;

class Z_Obj{
    private:
        int zip;
        string state;
        string city;
        string county;
        string abbr;
        float lat;
        float lon;
    public:
        Z_Obj(int z, string ct, string st, string ab, string cnty, float la, float lo):
            zip(z), city(ct), state(st), abbr(ab), county(cnty), lat(la), lon(lo){}
        bool operator< (Z_Obj zip2);
    	friend ostream& operator<<(ostream& os, const Z_Obj& z);
    	int* findZip();
};

bool Z_Obj::operator< (Z_Obj zip2){
    return (zip < zip2.zip);
}

ostream& operator<<(ostream& os, const Z_Obj& z){
    os << endl << "Zip: " << z.zip << ", City: " << z.city << ",  State: " << z.state << ", abbr: "
        << z.abbr << ", County: " << z.county << ", latitude: " << z.lat << ", longitude: " 
        << z.lon ;
    return os;
}

int* Z_Obj::findZip(){
    if(zip != 0)
        return &zip;
}

int main(){
    Z_Obj *onj = new Z_Obj(28177, "Waxhaw", "NC", "NC", "Charlotte", 2.22, 3.33 );
    Z_Obj *onj2 = new Z_Obj(28173, "Waxhaw", "NC", "NC", "Charlotte", 2.22, 3.33 );
    if(*onj2 < *onj)
        cout << *onj << endl;
    int* surya = onj -> findZip();
    cout << onj << endl;
    return 0;
}