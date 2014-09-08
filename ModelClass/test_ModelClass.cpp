/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Mon 04 Nov 2013 02:37:28 PM CET
 ***** Last modified: Wed 04 Dec 2013 01:07:59 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include <typeinfo>
#include "ModelClass.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	ModelClass MC(1, 0);
	MC.DoDebug();
	MC.DoDebug(false);
	MC.DoDebug(true);
	MC.DebugPrint("", "5th line, all OK");
	cout << endl;

	cout << " Kind = " << MC.GetKind() << endl;
	cout << " ID = " << MC.GetID() << endl;
	MC.SetID(7);
	cout << " ID = " << MC.GetID() << endl;
	cout << " GetIDoffset = " << MC.GetIDoffset() << endl;
	cout << " GetModulo   = " << MC.GetModulo()   << endl;
	unsigned int BadID(25000);
	try {
		MC.SetID(BadID);
	} catch(const std::out_of_range& oor) {
		cerr << " ID " << ToStr(BadID) << " not valid, correct handling" << endl;
		cerr << "   Exception: " << oor.what() << endl;
	}
	cout << endl;

	cout << " Open: " << MC.GetOpen() << endl;
	MC.SetOpen(true);
	cout << " Open: " << MC.GetOpen() << endl;
	MC.SetOpen(false);
	cout << endl;

	cout << " Display: " << flush;
	MC.Display(cout);
	cout << endl;

	cout << " ostream:" << endl;
	cout << MC << endl;
	MC.ToggleOpen();
	cout << MC << endl;
	cout << endl;

	ModelClass* MCp = new ModelClass(1, 0);
	cout << MCp << endl;
	cout << endl;

	ModelClass MC2;
	ModelClass MC3(MC);
	ModelClass MC4(MCp);
	ModelClass MC5();

	cout << " MC2     : " << MC2 << endl;
	cout << " MC3(MC) : " << MC3 << endl;
	cout << " MC4(MCp): " << MC4 << endl;
	cout << " MC5()   : " << MC5 << endl;
	cout << " MC4 type: " << typeid(MC4).name() << endl;
	cout << " MC5 type: " << typeid(MC5).name() << endl;

	delete MCp;
	return 0;
}
