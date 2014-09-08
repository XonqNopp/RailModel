/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Tue 05 Nov 2013 12:29:19 PM CET
 ***** Last modified: Mon 09 Dec 2013 01:15:10 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "Aiguillage.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	Aiguillage A(1);
	A.DoDebug();
	cout << " Aiguillage kind: " << A.GetKind() << endl;
	cout << " ID offset: "       << A.GetIDoffset() << endl;
	cout << " ID = " << A.GetID() << endl;
	cout << " State      = " << A.GetState()      << endl;
	cout << " Open       = " << A.GetOpen()       << endl;
	A.SetID(42);
	cout << " ID = " << A.GetID() << endl;
	cout << endl;

	Path* P1 = new Path(11, 1);
	Path* P2 = new Path(12, 1);
	Path* P3 = new Path(13, 1);
	Path* P4 = new Path(14, 1);
	P1->DoDebug();
	P2->DoDebug();
	P3->DoDebug();
	P4->DoDebug();

	A.SetBefore1(P1);
	A.SetAfter1(P2);
	A.SetAfter2(P3);
	A.SetStart1(Vecteur3D(1, 2, 3));
	A.SetStart2(3, 2, 1);
	A.SetStop1(4, 5, 6);
	A.SetStop2(Vecteur3D(6, 5, 4));
	cout << " PathBefore1 = " << A.GetBefore1()->GetID() << endl;
	unsigned int IDbefore2(0);
	if(A.GetBefore2()) {IDbefore2 = A.GetBefore2()->GetID();}
	cout << " PathBefore2 = " << IDbefore2 << endl;
	cout << " PathAfter1  = " << A.GetAfter1()->GetID() << endl;
	cout << " PathAfter2  = " << A.GetAfter2()->GetID() << endl;
	cout << " Start1 = " << A.GetStart1() << endl;
	cout << " Start2 = " << A.GetStart2() << endl;
	cout << " Stop1  = " << A.GetStop1() << endl;
	cout << " Stop2  = " << A.GetStop2() << endl;
	cout << " State      = " << A.GetState() << endl;
	cout << " Open       = " << A.GetOpen()  << endl;
	cout << " SignalOpen = " << A.GetSignalOpen() << endl;
	A.SetState(true);
	A.SetOpen(true);
	A.SetSignalOpen(true);
	cout << " State      = " << A.GetState() << endl;
	cout << " Open       = " << A.GetOpen()  << endl;
	cout << " SignalOpen = " << A.GetSignalOpen() << endl;
	A.SetState(false);
	A.SetOpen(false);
	A.SetSignalOpen(false);
	cout << endl;

	cout << " Active path before: " << A.GetActivePathBefore()->GetID() << endl;
	cout << " Active path after : " << A.GetActivePathAfter()->GetID() << endl;
	cout << endl;

	cout << " NowOpen(11, 12) : " << A.NowOpen(11, 12)  << endl;
	A.ToggleOpen();
	cout << " NowOpen(11, 12) : " << A.NowOpen(11, 12)  << endl;
	A.ConfirmOpen();
	cout << " NowOpen(11, 12) : " << A.NowOpen(11, 12)  << endl;
	A.CancelConfirm();
	cout << " NowOpen(11, 12) : " << A.NowOpen(11, 12)  << endl;
	A.ToggleOpen();
	cout << " NowOpen(11, 12) : " << A.NowOpen(11, 12)  << endl;
	cout << endl;


	cout << " NowState(11, 12)  : " << A.NowState(11, 12) << endl;
	unsigned int Next11(0), Next13(0);
	Next11 = 0;
	Next13 = 0;
	if(A.GetNext(11)) {Next11 = A.GetNext(11)->GetID();}
	if(A.GetNext(13)) {Next13 = A.GetNext(13)->GetID();}
	cout << " GetNext(11): " << Next11 << endl;
	cout << " GetNext(13): " << Next13 << endl;
	A.ToggleState();

	cout << " NowState(11, 12)  : " << A.NowState(11, 12) << endl;
	Next11 = 0;
	Next13 = 0;
	if(A.GetNext(11)) {Next11 = A.GetNext(11)->GetID();}
	if(A.GetNext(13)) {Next13 = A.GetNext(13)->GetID();}
	cout << " GetNext(11): " << Next11 << endl;
	cout << " GetNext(13): " << Next13 << endl;
	A.ToggleState();
	A.ToggleOpen();

	cout << " NowState(11, 12)  : " << A.NowState(11, 12) << endl;
	Next11 = 0;
	Next13 = 0;
	if(A.GetNext(11)) {Next11 = A.GetNext(11)->GetID();}
	if(A.GetNext(13)) {Next13 = A.GetNext(13)->GetID();}
	cout << " GetNext(11): " << Next11 << endl;
	cout << " GetNext(13): " << Next13 << endl;

	A.ConfirmOpen();
	cout << " NowState(11, 12)  : " << A.NowState(11, 12) << endl;
	Next11 = 0;
	Next13 = 0;
	if(A.GetNext(11)) {Next11 = A.GetNext(11)->GetID();}
	if(A.GetNext(13)) {Next13 = A.GetNext(13)->GetID();}
	cout << " GetNext(11): " << Next11 << endl;
	cout << " GetNext(13): " << Next13 << endl;

	A.CancelConfirm();
	cout << " NowState(11, 12)  : " << A.NowState(11, 12) << endl;
	Next11 = 0;
	Next13 = 0;
	if(A.GetNext(11)) {Next11 = A.GetNext(11)->GetID();}
	if(A.GetNext(13)) {Next13 = A.GetNext(13)->GetID();}
	cout << " GetNext(11): " << Next11 << endl;
	cout << " GetNext(13): " << Next13 << endl;
	cout << endl;
	A.ToggleOpen();


	cout << A << endl;
	A.ToggleState();
	cout << A << endl;
	A.ToggleOpen();
	cout << A << endl;
	A.ToggleState();
	cout << A << endl;
	A.ConfirmOpen();
	cout << A << endl;
	A.CancelConfirm();
	cout << A << endl;
	A.ToggleOpen();
	cout << A << endl;
	A.ToggleState();
	cout << A << endl;
	A.ToggleOpen();
	cout << A << endl;
	cout << endl;

	A.SetBefore2(P4);
	cout << " PathBefore2 = " << A.GetBefore2()->GetID() << endl;
	cout << A << endl;
	A.ToggleState();
	cout << A << endl;
	A.ConfirmOpen();
	cout << A << endl;
	A.CancelConfirm();
	cout << A << endl;
	A.ToggleOpen();
	cout << A << endl;
	A.ToggleState();
	cout << A << endl;
	A.ToggleOpen();
	cout << A << endl;
	A.ToggleState();
	cout << A << endl;
	A.ToggleOpen();
	cout << A << endl;
	cout << endl;

	A.SetBefore2(0);

	Aiguillage A2(2);
	A2.DoDebug();

	A.SetTwin(&A2);
	cout << " ThisState=" << A.GetState() << " TwinState=" << A.GetTwin()->GetState() << endl;
	A.ToggleState();
	cout << " ThisState=" << A.GetState() << " TwinState=" << A.GetTwin()->GetState() << endl;
	A.ToggleState();
	cout << " ThisState=" << A.GetState() << " TwinState=" << A.GetTwin()->GetState() << endl;

	delete P1;
	delete P2;
	delete P3;
	delete P4;

	return 0;
}
