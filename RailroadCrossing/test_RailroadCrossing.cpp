/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Thu 07 Nov 2013 12:17:38 PM CET
 ***** Last modified: Wed 04 Dec 2013 08:51:06 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "RailroadCrossing.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	RailroadCrossing RC(1);
	RC.DoDebug();
	vector<bool> GS(2);
	cout << " ID = " << RC.GetID() << endl;
	cout << " Open = " << RC.GetOpen() << endl;
	cout << " State = " << RC.GetState() << endl;
	cout << " Position = " << RC.GetPosition() << endl;
	cout << " Direction = " << RC.GetDirection() << endl;
	RC.SetOpen(false);
	RC.SetState(true);
	RC.SetPosition(Vecteur3D(1, 2, 3));
	RC.SetDirection(4, 5, 6);
	cout << endl;
	cout << " Open = " << RC.GetOpen() << endl;
	cout << " State = " << RC.GetState() << endl;
	cout << " Position = " << RC.GetPosition() << endl;
	cout << " Direction = " << RC.GetDirection() << endl;
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	cout << endl;

	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	RC.ToggleState();
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	RC.ToggleState();
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	cout << " Open = " << RC.GetOpen() << endl;
	RC.SetOpen(true);
	cout << " Open = " << RC.GetOpen() << endl;

	cout << endl;
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	RC.ToggleOpen();
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	RC.ToggleState();
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	RC.ToggleState();
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	RC.ToggleOpen();
	cout << " LEDs = (" << RC.GetLED1() << ", " << RC.GetLED2() << ")" << endl;
	cout << endl;

	cout << " Display:" << endl;
	RC.Display(cout);

	cout << " ostream:" << endl;
	cout << RC << endl;
	RC.SetOpen(false);
	cout << RC << endl;
	RC.SetOpen(true);
	cout << RC << endl;
	cout << endl;

	RC.ToggleOpen();
	cout << RC << endl;
	RC.ToggleState();
	cout << RC << endl;
	RC.ToggleState();
	cout << RC << endl;
	RC.ToggleState();
	cout << RC << endl;
	RC.ToggleOpen();
	cout << RC << endl;
	RC.Run();
	return 0;
}
