#include "Vecteur3D.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	Vecteur3D v1;
	cout << " v1 = " << v1 << " empty" << endl;
	v1.SetX(2);
	cout << " v1 = " << v1 << " x" << endl;
	v1.SetY(5);
	cout << " v1 = " << v1 << " y" << endl;
	v1.SetZ(3);
	cout << " v1 = " << v1 << " z" << endl;
	v1.SetVecteur3D(10, 9, 8);
	cout << " v1 = " << v1 << " all" << endl;
	Vecteur3D v2(v1);
	cout << " v2 = " << v2 << " == v1" << endl;
	Vecteur3D v3(1, 2, 3);
	cout << " v3 = " << v3 << endl;
	v2.SetVecteur3D(v3);
	cout << " v2 = " << v2 << " == v3" << endl;
	cout << " v1(x) = " << v1.GetX() << endl;
	cout << " v2(y) = " << v2.GetY() << endl;
	cout << " v3(z) = " << v3.GetZ() << endl;
	if(v1 != v2) {
		cout << " v1 != v2" << endl;
	} else {
		cerr << " operator!= not working" << endl;
	}
	if(v2 == v3) {
		cout << " v2 == v3" << endl;
	} else {
		cerr << " operator== not working" << endl;
	}
	cout << " v1 + v2 = " << (v1 + v2) << endl;
	cout << " v1 - v2 = " << (v1 - v2) << endl;
	cout << " -v1 = "     << (-v1)     << endl;
	cout << " v1 * v2 = " << (v1 * v2) << " scalar" << endl;
	cout << " v1 ^ v2 = " << (v1 ^ v2) << " vectorial" << endl;
	cout << " |v1| = "    << v1.Norme() << endl;
	cout << " |v2| = "    << v2.Norme() << endl;
	cout << " |v3| = "    << v3.Norme() << endl;
	if(v1 > v2) {
		cout << " v1 > v2" << endl;
	} else {
		cerr << " operator> not working" << endl;
	}
	if(v2 < v1) {
		cout << " v2 < v1" << endl;
	} else {
		cerr << " operator< not working" << endl;
	}
	if(v1 >= v2 && v2 >= v3) {
		cout << " v1 >= v2 && v2 >= v3" << endl;
	} else {
		cerr << " operator>= not working" << endl;
	}
	if(v2 <= v1 && v2 <= v3) {
		cout << " v2 <= v1 && v2 <= v3" << endl;
	} else {
		cerr << " operator<= not working" << endl;
	}
	cout << " v3 = " << v3 << endl;
	v3 = v1;
	cout << " v3 = " << v3 << " = v1" << endl;
	v3 += v2;
	cout << " v3 = " << v3 << " = v1 + v2" << endl;
	v3 -= v2;
	cout << " v3 = " << v3 << " = v1" << endl;
	v3++;
	cout << " v3 = " << v3 << " = v3++" << endl;
	Vecteur3D v4(v3.Unit());
	cout << " |v4| = " << v4.Norme() << ", v4 = " << v4 << " = v3 / |v3|" << endl;
	cout << " v3 = " << flush;
	Vecteur3D v5;
	cout << " v5 = " << v5 << ", |v5| = " << v5.Norme() << endl;
	cout << " v5.Unit() = " << v5.Unit() << endl;
	v3.Display(cout);
	cout << endl;
	cout << " 2 * v3 = " << (2 * v3) << endl;
	cout << " v3 * 2 = " << (v3 * 2) << endl;
	cout << " v3 / 2 = " << (v3 / 2.0) << endl;

	return 0;
}
