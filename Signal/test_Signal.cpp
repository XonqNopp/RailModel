/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Wed 13 Nov 2013 07:18:06 AM CET
 ***** Last modified: Wed 11 Dec 2013 04:30:41 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "Signal.hpp"
//#include "../Path/PartialPath.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	Signal S(1, 0);
	S.DoDebug();
	cout << endl;

	//// InitLEDs
	cout << " L = " << S.GetL() << endl;
	S.InitLEDs(3, 3);
	cout << " L = " << S.GetL() << endl;
	try{
		S.InitLEDs(3, 3);
	} catch(const runtime_error& re) {
		cerr << " Could not run InitLEDs twice" << endl;
		cerr << "   Exception: " << re.what() << endl;
	}
	cout << endl;

	//// Position, Direction
	cout << " Position : " << S.GetPosition() << endl;
	cout << " Direction: " << S.GetDirection() << endl;
	cout << endl;

	S.SetPosition(1, 2, 3);
	S.SetDirection(Vecteur3D(4, 5, 6));
	cout << endl;

	cout << " Position : " << S.GetPosition() << endl;
	cout << " Direction: " << S.GetDirection() << endl;
	cout << endl;

	//// GetLEDs(i)
	for(unsigned int i(0); i < S.GetLEDs().size(); i++) {
		cout << " GetLEDs(" << i << ")   = " << S.GetLEDs(i) << endl;
	}
	cout << endl;

	//// GetLEDs()[i]
	for(unsigned int i(0); i < S.GetLEDs().size(); i++) {
		cout << " GetLEDs()[" << i << "] = " << S.GetLEDs()[i] << endl;
	}
	cout << endl;

	//// SetLEDs()
	vector<bool> s(4, false);
	s[2] = true;
	try{
		S.SetLEDs(s);
		cout << " Set new LEDs of different size" << endl;
	} catch(const out_of_range& oor) {
		cerr << " Could not set new LEDs of different size" << endl;
		cerr << "   Exception: " << oor.what() << endl;
	}

	s.resize(3);
	S.SetLEDs(s);
	// with text
	S.SetLED(0, true);
	// with text

	cout << endl;

	//// GetLEDs(oor)
	try{
		cout << " Trying to access forbidden index: " << S.GetLEDs(35) << endl;
	} catch(const out_of_range& oor) {
		cerr << " Could not access to forbidden element" << endl;
		cerr << "   Exception: " << oor.what() << endl;
	}
	cout << endl;

	//// Next
	Path* P = new Path(7, 0);
	S.SetNext(P);

	cout << " Path #" << S.GetNext()->GetID() << endl;
	//cout << " PathOpen(): " << S.PathOpen() << endl;
	//cout << " NextSignal(): " << S.NextSignal() << endl;
	cout << endl;

	S.Xmas();
	cout << endl;

	S.Test();
	cout << endl;

	delete P;

	return 0;
}
