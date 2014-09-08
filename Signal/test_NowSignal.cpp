/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Thu 14 Nov 2013 12:32:42 PM CET
 ***** Last modified: Wed 04 Dec 2013 08:51:34 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "NowSignal.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	NowSignal NS(1, 0, vector<bool>(3, false));
	NS.DoDebug();

	Path* P = new Path(2001, 2);
	P->DoDebug();

	NS.SetNext(P);

	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.SetUserOpen(2);
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.SetOpen(true);
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.SetUserOpen(6);
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.SetUserOpen(0);
	cout << endl;

	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.OpenFull();
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.Close();
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	cout << endl;

	P->ToggleOpen();

	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.OpenFull();
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	NS.Close();
	cout << " UserOpen: " << NS.GetUserOpen() << endl;
	cout << " Status:   " << NS.Status()      << endl;
	cout << endl;

	return 0;
}
