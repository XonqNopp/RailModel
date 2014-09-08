/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Tue 05 Nov 2013 11:22:34 AM CET
 ***** Last modified: Mon 09 Dec 2013 01:36:13 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#include "Aiguillage.hpp"
using namespace std;

Aiguillage::Aiguillage(const unsigned int& NewID)
	:Path(NewID, 2), State(0), PathBefore2(0), PathAfter2(0), Twin(0), PosStart2(Vecteur3D()), PosStop2(Vecteur3D())
{
	SetID(NewID);
}

Aiguillage::~Aiguillage() {}


bool Aiguillage::GetState() const {return State;}
Path* Aiguillage::GetBefore2() const {return PathBefore2;}
Path* Aiguillage::GetAfter2() const {return PathAfter2;}
Aiguillage* Aiguillage::GetTwin() const {return Twin;}
Vecteur3D Aiguillage::GetStart2() const {return PosStart2;}
Vecteur3D Aiguillage::GetStop2() const {return PosStop2;}

void Aiguillage::SetState(const bool& NewState) {
	DebugPrint("Aiguillage", "SetState(" + ToStr(NewState) + ")");
	State = NewState;
}

void Aiguillage::SetBefore2(Path* NewBefore2) {
	unsigned int ID(0);
	if(NewBefore2) {ID = NewBefore2->GetID();}
	DebugPrint("Aiguillage", "SetBefore2(" + ToStr(ID) + ")");
	PathBefore2 = NewBefore2;
}

void Aiguillage::SetAfter2(Path* NewAfter2) {
	unsigned int ID(0);
	if(NewAfter2) {ID = NewAfter2->GetID();}
	DebugPrint("Aiguillage", "SetAfter2(" + ToStr(ID) + ")");
	PathAfter2 = NewAfter2;
}

void Aiguillage::SetTwin(Aiguillage* NewTwin) {
	unsigned int ID(0);
	if(NewTwin) {ID = NewTwin->GetID();}
	DebugPrint("Aiguillage", "SetTwin aiguillage #" + ToStr(ID));
	Twin = NewTwin;
}

void Aiguillage::SetStart2(const Vecteur3D& Start2) {
	DebugPrint("Aiguillage", "SetStart2(" + ToStr(Start2) + ")");
	PosStart2 = Start2;
}

void Aiguillage::SetStop2(const Vecteur3D& Stop2) {
	DebugPrint("Aiguillage", "SetStop2(" + ToStr(Stop2) + ")");
	PosStop2 = Stop2;
}

void Aiguillage::SetStart2(const double& x, const double& y, const double& z) {
	DebugPrint("Aiguillage", "SetStart2(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	PosStart2 = Vecteur3D(x, y, z);
}

void Aiguillage::SetStop2(const double& x, const double& y, const double& z) {
	DebugPrint("Aiguillage", "SetStop2(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	PosStop2 = Vecteur3D(x, y, z);
}

void Aiguillage::Display(std::ostream& out) const {
	out << endl;
	out << " Aiguillage #" << GetID() << endl;
	if(GetBefore2() == 0) {
		out << "  " << GetAfter2()->GetID() << endl;
		out << "     " << GetAfter1()->GetID() << endl;
		out << "  \\  |" << endl;
		out << "   \\ |" << endl;
		if(GetState()) {
			out << "    \\ " << endl;
			out << "     \\" << endl;
		} else {
			out << "     |" << endl;
			out << "     |" << endl;
		}
		if(PathOpen()) {
			out << "     |" << endl;
		} else if(GetOpen()) {
			out << "     -" << endl;
		} else {
			out << "    ---" << endl;
		}
		out << "     |" << endl;
		out << "     |" << endl;
		out << "     " << GetBefore1()->GetID() << endl;
	} else {
		out << "  " << GetAfter2()->GetID() << endl;
		out << "        " << GetAfter1()->GetID() << endl;
		out << "  \\     /" << endl;
		out << "   \\   /"  << endl;
		if(GetState()) {
			out << "    | |" << endl;
			if(PathOpen()) {
				out << "    | |" << endl;
			} else if(GetOpen()) {
				out << "    - -" << endl;
			} else {
				out << "    ---" << endl;
			}
			out << "    | |" << endl;
		} else {
			out << "    \\ /" << endl;
			if(PathOpen()) {
				out << "     x" << endl;
			} else if(GetOpen()) {
				out << "     -" << endl;
			} else {
				out << "    ---" << endl;
			}
			out << "    / \\" << endl;
		}
		out << "   /   \\"  << endl;
		out << "  /     \\" << endl;
		out << "  " << GetBefore1()->GetID() << endl;
		out << "        " << GetBefore2()->GetID() << endl;
	}
}


void Aiguillage::ToggleState() {
	DebugPrint("Aiguillage", "ToggleState()");
	/*** can toggle only if not ready for or occupied by train ***/
	if(!GetOpen() && !GetBusy()) {
		if(GetTwin()) {
			if(!GetTwin()->GetOpen() && !GetTwin()->GetBusy()) {
				SetState(!GetState());
				GetTwin()->SetState(!GetTwin()->GetState());
			}
		} else {
			SetState(!GetState());
		}
	}
}

Path* Aiguillage::GetActivePathBefore() const {
	DebugPrint("Aiguillage", "GetActivePathBefore()");
	return (GetBefore2() && GetState()) ? GetBefore2() : GetBefore1();
}

Path* Aiguillage::GetActivePathAfter() const {
	DebugPrint("Aiguillage", "GetActivePathAfter()");
	return GetState() ? GetAfter2() : GetAfter1();
}

Path* Aiguillage::GetInactivePathBefore() const {
	DebugPrint("Aiguillage", "GetInactivePathBefore()");
	return GetBefore2() ? (GetState() ? GetBefore1() : GetBefore2()) : 0;
}

Path* Aiguillage::GetInactivePathAfter() const {
	return GetState() ? GetAfter1() : GetAfter2();
}

bool Aiguillage::NowOpen(const unsigned int& PathFrom, const unsigned int& PathTo) const {
	DebugPrint("Aiguillage", "NowOpen(" + ToStr(PathFrom) + ", " + ToStr(PathTo) + ")");
	return (
			PathOpen()
			&& (PathFrom == GetActivePathBefore()->GetID())
			&& (PathTo == GetActivePathAfter()->GetID())
			);
}

bool Aiguillage::NowState(const unsigned int& PathFrom, const unsigned int& PathTo) const {
	DebugPrint("Aiguillage", "NowState(" + ToStr(PathFrom) + ", " + ToStr(PathTo) + ")");
	return NowOpen(PathFrom, PathTo) && !GetBusy();
}

Path* Aiguillage::GetNext(const unsigned int& PreviousPath) const throw(out_of_range) {
	DebugPrint("Aiguillage", "GetNext(" + ToStr(PreviousPath) + ")");
	if(PreviousPath == 0) {throw out_of_range("Cannot ask for ID 0");}

	unsigned int PatBefA(0);
	unsigned int PatAftA(0);
	unsigned int PatBefI(0);
	unsigned int PatAftI(0);
	if(GetActivePathBefore()) {PatBefA = GetActivePathBefore()->GetID();}
	if(GetActivePathAfter())  {PatAftA = GetActivePathAfter()->GetID(); }
	if(GetInactivePathBefore()) {PatBefI = GetInactivePathBefore()->GetID();}
	if(GetInactivePathAfter())  {PatAftI = GetInactivePathAfter()->GetID(); }
	if(PreviousPath == PatBefA) {
		return GetActivePathAfter();
	} else if(PreviousPath == PatAftA) {
		return GetActivePathBefore();
	} else if(PreviousPath == PatBefI || PreviousPath == PatAftI) {
		return 0;
	} else {
		string ex("Path #" + ToStr(GetID()) + " is between #" + ToStr(PatBefA) + " ");
		if(PatBefI) {
			ex += "(or #" + ToStr(GetBefore2()->GetID()) + ") ";
		}
		ex += "and #" + ToStr(PatAftA) + " (or #" + ToStr(PatAftI) + ")";
		throw out_of_range(ex);
	}
}
