/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Wed 06 Nov 2013 07:17:05 AM CET
 ***** Last modified: Mon 09 Dec 2013 12:23:12 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "Path.hpp"
using namespace std;

Path::Path(const unsigned int& NewID, const unsigned int& NewKind)
	:ModelClass(NewID, NewKind), SignalOpen(false), Busy(false), PathBefore1(0), PathAfter1(0), PosStart1(Vecteur3D()), PosStop1(Vecteur3D())
{}

Path::~Path() {}

bool Path::GetSignalOpen() const {return SignalOpen;}
bool Path::GetBusy() const {return Busy;}
Path* Path::GetBefore1() const {return PathBefore1;}
Path* Path::GetAfter1() const {return PathAfter1;}
Vecteur3D Path::GetStart1() const {return PosStart1;}
Vecteur3D Path::GetStop1() const {return PosStop1;}

void Path::SetSignalOpen(const bool& NewSignalOpen) {
	DebugPrint("Path", "SetSignalOpen(" + ToStr(NewSignalOpen) + ")");
	SignalOpen = NewSignalOpen;
}

void Path::SetBusy(const bool& NewBusy){
	DebugPrint("Path", "SetBusy(" + ToStr(NewBusy) + ")");
	Busy = NewBusy;
}

void Path::SetBefore1(Path* NewBefore1){
	unsigned int ID(0);
	if(NewBefore1) {ID = NewBefore1->GetID();}
	DebugPrint("Path", "SetBefore1(" + ToStr(ID) + ")");
	PathBefore1 = NewBefore1;
}

void Path::SetAfter1(Path* NewAfter1){
	unsigned int ID(0);
	if(NewAfter1) {ID = NewAfter1->GetID();}
	DebugPrint("Path", "SetAfter1(" + ToStr(ID) + ")");
	PathAfter1 = NewAfter1;
}

void Path::SetStart1(const Vecteur3D& NewStart1){
	DebugPrint("Path", "SetStart1(" + ToStr(NewStart1) + ")");
	PosStart1 = NewStart1;
}

void Path::SetStart1(const double& x, const double& y, const double& z){
	DebugPrint("Path", "SetStart1(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	PosStart1 = Vecteur3D(x, y, z);
}

void Path::SetStop1(const Vecteur3D& NewStop1){
	DebugPrint("Path", "SetStop1(" + ToStr(NewStop1) + ")");
	PosStop1 = NewStop1;
}

void Path::SetStop1(const double& x, const double& y, const double& z){
	DebugPrint("Path", "SetStop1(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	PosStop1 = Vecteur3D(x, y, z);
}


void Path::MakeOpen(const bool& NewOpen) {
	DebugPrint("Path", "MakeOpen(" + ToStr(NewOpen) + ")");
	if(!GetBusy() && !PathOpen()) {
		/*** Can not toggle open if already busy or if confirmed ***/
		SetOpen(NewOpen);
	}
}

void Path::ToggleOpen() {
	DebugPrint("Path", "ToggleOpen()");
	MakeOpen(!GetOpen());
}

bool Path::ConfirmOpen() {
	DebugPrint("Path", "ConfirmOpen()");
	if(GetOpen()) {
		SetSignalOpen(true);
	}
	return GetSignalOpen();
}

bool Path::CancelConfirm() {
	DebugPrint("Path", "CancelConfirm()");
	SetSignalOpen(false);
	return GetSignalOpen();// ???
}

bool Path::PathOpen() const {return GetOpen() && GetSignalOpen();}

void Path::TrainEnters() {
	DebugPrint("Path", "TrainEnters()");
	if(PathOpen()) {
		SetSignalOpen(false);
		SetOpen(false);
		SetBusy(true);
	}
}

void Path::TrainLeaves() {
	DebugPrint("Path", "TrainLeaves()");
	SetBusy(false);
}

Path* Path::GetNext(const unsigned int& PreviousPath) const throw(out_of_range) {
	DebugPrint("Path", "GetNext(" + ToStr(PreviousPath) + ")");
	if(PreviousPath == 0) {throw out_of_range("Cannot ask for ID 0");}
	unsigned int PatBef(0);
	unsigned int PatAft(0);
	if(GetBefore1()) {PatBef = GetBefore1()->GetID();}
	if(GetAfter1())  {PatAft = GetAfter1()->GetID(); }
	if(PreviousPath == PatBef) {
		return GetAfter1();
	} else if(PreviousPath == PatAft) {
		return GetBefore1();
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
