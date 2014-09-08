/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Wed 06 Nov 2013 07:27:42 AM CET
 ***** Last modified: Mon 09 Dec 2013 01:19:47 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "Path.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	Path P(1, 1);
	P.DoDebug();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.SetOpen(true);
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.SetBusy(true);
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.SetSignalOpen(true);
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	cout << endl;

	unsigned int IDbefore1(0), IDafter1(0);
	if(P.GetBefore1()) {IDbefore1 = P.GetBefore1()->GetID();}
	if(P.GetAfter1())  {IDafter1  = P.GetAfter1()->GetID();}
	cout << " Before1 = " << IDbefore1 << endl;
	cout << " After1  = " << IDafter1<< endl;
	cout << " Start1  = " << P.GetStart1() << endl;
	cout << " Stop1   = " << P.GetStop1() << endl;

	Path* P1 = new Path(11, 1);
	P1->DoDebug();
	Path* P2 = new Path(12, 1);
	P2->DoDebug();

	P.SetBusy(false);
	P.SetSignalOpen(false);
	P.SetBefore1(P1);
	P.SetAfter1(P2);
	P.SetStart1(Vecteur3D(1, 2, 3));
	P.SetStop1(4, 5, 6);
	cout << endl;

	IDbefore1 = 0;
	IDafter1  = 0;
	if(P.GetBefore1()) {IDbefore1 = P.GetBefore1()->GetID();}
	if(P.GetAfter1())  {IDafter1  = P.GetAfter1()->GetID();}
	cout << " Before1 = " << IDbefore1 << endl;
	cout << " After1  = " << IDafter1<< endl;
	cout << " Start1  = " << P.GetStart1() << endl;
	cout << " Stop1   = " << P.GetStop1() << endl;
	cout << endl;

	P.ToggleOpen();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.ToggleOpen();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.ConfirmOpen();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.CancelConfirm();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.ConfirmOpen();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.TrainEnters();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	P.TrainLeaves();
	cout << " Open       = " << P.GetOpen() << endl;
	cout << " SignalOpen = " << P.GetSignalOpen() << endl;
	cout << " Busy       = " << P.GetBusy() << endl;
	cout << endl;

	cout << " Next from before: " << P.GetNext(11) << endl;
	cout << " Next from after : " << P.GetNext(12) << endl;

	delete P1;
	delete P2;

	return 0;
}
