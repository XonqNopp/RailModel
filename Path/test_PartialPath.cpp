/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Mon 04 Nov 2013 03:47:31 PM CET
 ***** Last modified: Mon 09 Dec 2013 01:27:30 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "PartialPath.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	PartialPath PP(1);
	PP.DoDebug();
	cout << " ID = " << PP.GetID() << endl;
	PP.SetID(25);
	cout << " ID = " << PP.GetID() << endl;
	PartialPath PP2(18, Vecteur3D(1, 2, 3), Vecteur3D(4, 5, 6));
	PP2.DoDebug();
	cout << " PP2 from " << PP2.GetStart1() << " to " << PP2.GetStop1() << endl;
	PartialPath* PP3 = new PartialPath(11);
	PP3->DoDebug();

	PP.SetBefore1(&PP2);
	PP.SetAfter1(PP3);

	RailroadCrossing* RCin = new RailroadCrossing(1);
	RCin->DoDebug();
	//NowSignal* NS = new NowSignal(3, 0);
	//NS->DoDebug();

	PP.SetCrossing(RCin);
	cout << " Crossing:" << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;
	
	PP.Display(cout);
	cout << endl;
	
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.ToggleOpen();// path open
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.ConfirmOpen();
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.CancelConfirm();
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.ToggleOpen();// path closed
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.ToggleOpen();// path open
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.ConfirmOpen();
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.TrainEnters();// path busy
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	PP.TrainLeaves();// path closed
	cout << PP << endl;
	cout << PP.GetCrossing() << endl;
	cout << endl;

	Path* Next(0);
	unsigned int NextID(0);
	Next = PP.GetNext(PP2.GetID());
	NextID = 0;
	if(Next) {NextID = Next->GetID();}
	cout << " GetNext(" << PP2.GetID() << "): " << NextID << endl;
	Next = PP.GetNext(PP3->GetID());
	NextID = 0;
	if(Next) {NextID = Next->GetID();}
	cout << " GetNext(" << PP3->GetID() << "): " << NextID << endl;
	PP.SetAfter1(0);
	Next = PP.GetNext(PP2.GetID());
	NextID = 0;
	if(Next) {NextID = Next->GetID();}
	cout << " GetNext(" << PP2.GetID() << "): " << NextID << endl;
	try {
		Next = PP.GetNext(PP3->GetID());
		cout << " GetNext(" << PP3->GetID() << ") worked but should not have..." << endl;
	} catch(const out_of_range& oor) {
		cerr << " Unable to ask GetNext(" << PP3->GetID() << ")" << endl;
		cerr << "   Exception: " << oor.what() << endl;
	}
	cout << endl;

	cerr << " * TEST NOT FINISHED NowSignal not tested" << endl;
	/*
	PP.SetSignalBefore(NS);
	Next = PP.GetNext(1);
	NextID = 0;
	if(Next) {NextID = Next->GetID();}
	cout << " GetNext(1): " << NextID << endl;
	Next = PP.GetNext(PP2.GetID());
	NextID = 0;
	if(Next) {NextID = Next->GetID();}
	cout << " GetNext(" << PP2.GetID() << "): " << NextID << endl;
	Next = PP.GetNext(PP3->GetID());
	NextID = 0;
	if(Next) {NextID = Next->GetID();}
	cout << " GetNext(" << PP3->GetID() << "): " << NextID << endl;
	cout << endl;
	*/

	delete RCin;
	//delete NS;
	delete PP3;

	return 0;
}
