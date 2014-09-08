/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Tue 12 Nov 2013 12:33:51 PM CET
 ***** Last modified: Wed 11 Dec 2013 04:22:04 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "Signal.hpp"
using namespace std;

Signal::Signal(const unsigned int& NewID, const unsigned int& NewKind)
	:ModelClass(NewID, NewKind), L(0), Next(0), Position(Vecteur3D()), Direction(Vecteur3D())
{
	SetID(NewID);
}

Signal::~Signal() {}

void Signal::InitLEDs(const unsigned int& NewL, const unsigned int& RedIdx) throw(out_of_range, runtime_error) {
	DebugPrint("Signal", "InitLEDs(" + ToStr(NewL) + ", " + ToStr(RedIdx) + ")");
	//// Check if already init
	if(GetL() > 0) {
		throw runtime_error("LEDs already defined, use SetLEDs to change their statuses");
	}
	//// Check if NewL large enough
	if(NewL < 2) {
		throw out_of_range("Must have at least 2 LEDs, " + ToStr(NewL) + " not valid");
	}
	//// Proceed
	LEDs = vector<bool>(NewL, false);
	L = NewL;
	//// Check which one is red
	unsigned int ThisRed(RedIdx);
	if(ThisRed >= GetL()) {
		DebugPrint("Signal", "InitLEDs RedIdx=" + ToStr(ThisRed) + " out of range, using default 1");
		ThisRed = 1;
		//throw out_of_range("RedIdx=" + ToStr(RedIdx) + " not in range 0.." + ToStr(GetL()-1));
	}
	LEDs[ThisRed] = true;
}

unsigned int Signal::GetL()    const {return L;}
vector<bool> Signal::GetLEDs() const {return LEDs;}

bool Signal::GetLEDs(const unsigned int& idx) const throw(out_of_range) {
	if(idx >= GetLEDs().size()) {
		throw out_of_range("LEDs[0..." + ToStr(GetLEDs().size()-1) + "], index " + ToStr(idx) + " is not valid");
	}
	return GetLEDs()[idx];
}

Path* Signal::GetNext()          const {return Next;}
Vecteur3D Signal::GetPosition()  const {return Position;}
Vecteur3D Signal::GetDirection() const {return Direction;}

void Signal::SetLEDs(const vector<bool>& NewLEDs) throw(out_of_range) {
	DebugPrint("Signal", "SetLEDs()");// + ToStr(NewLEDs) + ")");
	if(NewLEDs.size() != GetL()) {
		throw out_of_range("NewLEDs is not valid: size is " + ToStr(NewLEDs.size()) + ", can only be " + ToStr(GetL()));
	}
	LEDs = NewLEDs;
}

void Signal::SetLED(const unsigned int& idx, const bool& NewVal) throw(out_of_range) {
	DebugPrint("Signal", "SetLED(" + ToStr(idx) + ", " + ToStr(NewVal) + ")");
	if(idx >= GetL()) {
		throw out_of_range("idx=" + ToStr(idx) + " not valid, must be < " + ToStr(GetL()));
	}
	LEDs[idx] = NewVal;
}

void Signal::SetNext(Path* NewNext) {
	unsigned int ID(0);
	if(NewNext) {ID = NewNext->GetID();}
	DebugPrint("Signal", "SetNext(" + ToStr(ID) + ")");
	Next = NewNext;
}

void Signal::SetPosition(const Vecteur3D& NewPosition) {
	DebugPrint("Signal", "SetPosition(" + ToStr(NewPosition) + ")");
	Position = NewPosition;
}

void Signal::SetDirection(const Vecteur3D& NewDirection) {
	DebugPrint("Signal", "SetDirection(" + ToStr(NewDirection) + ")");
	Direction = NewDirection.Unit();
}

void Signal::SetPosition(const double& x, const double& y, const double& z) {
	DebugPrint("Signal", "SetPosition(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	Position = Vecteur3D(x, y, z);
}

void Signal::SetDirection(const double& x, const double& y, const double& z) {
	DebugPrint("Signal", "SetDirection(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	Direction = Vecteur3D(x, y, z).Unit();
}

/*
bool Signal::NextSignal() const {
	DebugPrint("Signal", "NextSignal()");
	ModelClass* NextPath(GetNext());
	DebugPrint("Signal", "NextSignal() next=" + ToStr(NextPath->GetID()));
	unsigned int ThisID(GetID());
	DebugPrint("Signal", "NextSignal() ThisID=" + ToStr(ThisID));
	unsigned int OldID(0);
	bool run(true);
	bool back(NextPath->PathOpen());
	while(run) {
		if(NextPath->GetNextSignal(ThisID)) {
			if(NextPath->GetNextSignal(ThisID)->GetKind() < 4) {
				OldID = ThisID;
				ThisID = NextPath->GetID();
				NextPath = NextPath->GetNextSignal(OldID);
				back = back && NextPath->PathOpen();
				if(NextPath == 0) {
					run = false;
				}
			} else {
				//// Signal caught
				NextPath = NextPath->GetNextSignal(ThisID);
				back = back && NextPath->Status();
				run = false;
			}
		} else {
			run = false;
		}
	}
	return back;
}

bool Signal::PathOpen() const {
	DebugPrint("Signal", "PathOpen()");
	//const ModelClass* NextPath(this);
	ModelClass* NextPath(GetNext());
	unsigned int ThisID(GetID());
	unsigned int OldID(0);
	bool run(true);
	bool back(true);
	while(run) {
		//DebugPrint("Signal", "PathOpen() OldID=" + ToStr(OldID) + ", ThisID=" + ToStr(ThisID));
		// open
		back = back && NextPath->GetOpen();
		//DebugPrint("Signal", "PathOpen() back=" + ToStr(back));
		if(!back) {run = false; break;}// need to break to prevent bugs when finishing cycle
		// look for next
		if(NextPath->GetNextSignal(ThisID)) {
			if(NextPath->GetNextSignal(ThisID)->GetKind() < 4) {
				OldID = ThisID;
				ThisID = NextPath->GetID();
				NextPath = NextPath->GetNextSignal(OldID);
				if(NextPath == 0) {run = false;}
			} else {
				run = false;
			}
		} else {
			run = false;
		}
	}
	return back;
}
*/

void Signal::Xmas() {
	DebugPrint("Signal", "Xmas()");
	DebugPrint("Signal", "Xmas() not done yet");
}

void Signal::Test() {
	DebugPrint("Signal", "Test()");
	DebugPrint("Signal", "Test() not done yet");
}
