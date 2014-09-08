/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Mon 04 Nov 2013 02:23:10 PM CET
 ***** Last modified: Tue 10 Dec 2013 08:14:26 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#include "PartialPath.hpp"
using namespace std;

PartialPath::PartialPath(const unsigned int& NewID)
	:Path(NewID, 1), Crossing(0)//, SignalBefore(0), SignalAfter(0)
{
	SetID(NewID);
}

PartialPath::PartialPath(const unsigned int& NewID, const Vecteur3D& Start, const Vecteur3D& Stop)
	:Path(NewID, 1), Crossing(0)//, SignalBefore(0), SignalAfter(0)
{
	SetID(NewID);
	SetStart1(Start);
	SetStop1(Stop);
}

PartialPath::~PartialPath() {}

RailroadCrossing* PartialPath::GetCrossing() const {return Crossing;}
/*
NowSignal* PartialPath::GetSignalBefore() const {return SignalBefore;}
NowSignal* PartialPath::GetSignalAfter() const {return SignalAfter;}
*/

void PartialPath::SetCrossing(RailroadCrossing* NewCrossing) {
	DebugPrint("PartialPath", "SetCrossing setting #" + ToStr(NewCrossing->GetID()));
	Crossing = NewCrossing;
}

/*
void PartialPath::SetSignalBefore(NowSignal* SB){
	unsigned int ID(0);
	if(SB) {ID = SB->GetID();}
	DebugPrint("PartialPath", "SetSignalBefore(" + ToStr(ID) + ")");
	SignalBefore = SB;
}

void PartialPath::SetSignalAfter(NowSignal* SA){
	unsigned int ID(0);
	if(SA) {ID = SA->GetID();}
	DebugPrint("PartialPath", "SetSignalAfter(" + ToStr(ID) + ")");
	SignalAfter = SA;
}
*/

void PartialPath::Display(ostream& out) const {
	out << endl;
	out << " PartialPath #" << GetID() << endl;
	out << " ";
	/*
	if(GetSignalBefore()) {out << "s";}
	*/
	out << "---";
	if(GetBusy()) {
		out << "xxxxxxx";
	} else {
		out << "--";
		if(GetOpen()) {
			out << "---";
		} else {
			out << " | ";
		}
		out << "--";
	}
	out << "---" << endl;
	/*
	if(GetSignalAfter()) {out << "s";}
	*/
	out << endl;
}

void PartialPath::Draw() const {
	Vecteur3D white(1, 1, 1), red(1, 0, 0), green(0, 1, 0), blue(0, 0, 1);
	//// Open       blue
	//// SignalOpen green
	//// Busy       red
	//// Nothing    white
	// Maybe make end with a touch of another color to distinguish the different paths
	// Maybe do this in parent class Path because also aiguillage
	Vecteur3D colour(white);
	if(GetBusy()) {
		colour = red;
	} else {
		if(GetOpen()) {
			/*
			if(GetSignalOpen()) {
				colour = green;
			} else {
			*/
				colour = blue;
				/*
			}
			*/
		}
	}
	DrawLine(PosStart1, PosStop1, colour);
}

void PartialPath::ConfirmOpen() {
	DebugPrint("PartialPath", "ConfirmOpen()");
	Path::ConfirmOpen();
	if(GetCrossing()) {
		GetCrossing()->SetOpen(!GetSignalOpen());// path confirmed open, crossing closed
	}
}

void PartialPath::CancelConfirm() {
	DebugPrint("PartialPath", "CancelConfirm()");
	Path::CancelConfirm();
	if(GetCrossing()) {
		GetCrossing()->SetOpen(!GetSignalOpen());// path canceled open, crossing open
	}
}

void PartialPath::TrainLeaves() {
	DebugPrint("PartialPath", "TrainLeaves()");
	Path::TrainLeaves();
	if(GetCrossing()) {
		GetCrossing()->SetOpen(true);
	}
}

/*
NowSignal* PartialPath::GetNextSignal(const unsigned int& PreviousPath) const {
	DebugPrint("PartialPath", "GetNextSignal(" + ToStr(PreviousPath) + ")");
	if(PreviousPath == 0) {throw out_of_range("Cannot ask for ID 0");}
	unsigned int PatBef(0);
	unsigned int PatAft(0);
	if(GetBefore1()) {PatBef = GetBefore1()->GetID();}
	if(GetAfter1())  {PatAft = GetAfter1()->GetID(); }
	if(PreviousPath == PatBef) {
		return GetSignalAfter();
	} else if(PreviousPath == PatAft) {
		return GetSignalBefore();
	} else {
		string ex("Path #" + ToStr(GetID()));
		if(PatBef && PatAft) {
			ex += " is between #" + ToStr(PatBef) + " and #" + ToStr(PatAft);
		} else if(PatBef) {
			ex += " is only linked to #" + ToStr(PatBef) + " before";
		} else if(PatAft) {
			ex += " is only linked to #" + ToStr(PatAft) + " after";
		} else {
			ex += " has no neighbour path";
		}
		throw out_of_range(ex);
	}
}
*/
