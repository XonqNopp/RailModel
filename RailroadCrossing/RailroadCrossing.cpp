/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Wed 06 Nov 2013 03:29:21 PM CET
 ***** Last modified: Wed 04 Dec 2013 04:58:17 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "RailroadCrossing.hpp"
using namespace std;

RailroadCrossing::RailroadCrossing(const unsigned int& NewID)
	:ModelClass(NewID, 3), State(false), Position(Vecteur3D()), Direction(Vecteur3D())
{
	SetID(NewID);
	SetOpen(true);
}

RailroadCrossing::~RailroadCrossing() {}

bool RailroadCrossing::GetState() const {return State;}
Vecteur3D RailroadCrossing::GetPosition() const {return Position;}
Vecteur3D RailroadCrossing::GetDirection() const {return Direction;}

void RailroadCrossing::SetState(const bool& NewState) {
	DebugPrint("RailroadCrossing", "SetState(" + ToStr(NewState) + ")");
	State = NewState;
}

void RailroadCrossing::SetPosition(const Vecteur3D& NewPosition) {
	DebugPrint("RailroadCrossing", "SetPosition" + ToStr(NewPosition));
	Position = NewPosition;
}

void RailroadCrossing::SetDirection(const Vecteur3D& NewDirection) {
	DebugPrint("RailroadCrossing", "SetDirection" + ToStr(NewDirection));
	Direction = NewDirection.Unit();// direction is unitary
}

void RailroadCrossing::SetPosition(const double& x, const double& y, const double& z) {
	DebugPrint("RailroadCrossing", "SetPosition(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	Position = Vecteur3D(x, y, z);
}

void RailroadCrossing::SetDirection(const double& x, const double& y, const double& z) {
	DebugPrint("RailroadCrossing", "SetDirection(" + ToStr(x) + ", " + ToStr(y) + ", " + ToStr(z) + ")");
	Direction = Vecteur3D(x, y, z).Unit();
}

void RailroadCrossing::Display(ostream& out) const {
	out << endl;
	out << " RailroadCrossing #" << GetID() << endl;
	if(GetOpen()) {
		out << "      ^" << endl;
	} else {
		out << "      _" << endl;
	}
	out << "     / \\" << endl;
	out << "    /   \\" << endl;
	out << "   /     \\" << endl;
	if(GetOpen()) {
		out << "  / X   X \\" << endl;
	} else {
		out << "  / ";
		if(GetLED1()) {
			out << "O";
		} else {
			out << "X";
		}
		out << "   ";
		if(GetLED2()) {
			out << "O";
		} else {
			out << "X";
		}
		out << " \\" << endl;
	}
	out << " /_________\\" << endl;
	out << endl;
}

void RailroadCrossing::Draw() const {
	DebugPrint("RailroadCrossing", "Draw()");
	Vecteur3D Left, Right, Top, PosLED1, PosLED2;
	Vecteur3D OrthoDir(GetDirection().GetY(), -GetDirection().GetX(), GetDirection().GetZ());
	Top     = GetPosition() + GetDirection();
	Left    = GetPosition() - OrthoDir;
	Right   = GetPosition() + OrthoDir;
	PosLED1 = GetPosition() - OrthoDir/2 + GetDirection()/3;
	PosLED2 = GetPosition() + OrthoDir/2 + GetDirection()/3;
	double inner_radius(1), outer_radius(2), wires(30);
	DebugPrint("RailroadCrossing", "Draw Top    =" + ToStr(Top));
	DebugPrint("RailroadCrossing", "Draw Left   =" + ToStr(Left));
	DebugPrint("RailroadCrossing", "Draw Right  =" + ToStr(Right));
	DebugPrint("RailroadCrossing", "Draw PosLED1=" + ToStr(PosLED1));
	DebugPrint("RailroadCrossing", "Draw PosLED2=" + ToStr(PosLED2));
	Vecteur3D gray(0.8, 0.8, 0.8), red(1, 0, 0);
	glPushMatrix();
	//// Check if need to do the push-pop many times or if this works
	DrawLine(Left, Right, gray, false);
	DrawLine(Left, Top, gray, false);
	DrawLine(Top, Right, gray, false);
	if(GetLED1()) {
		DrawSphere(PosLED1, red, outer_radius, wires, false);
	} else {
		DrawTorus(PosLED1, red, outer_radius, inner_radius, wires, false);
	}
	if(GetLED2()) {
		DrawSphere(PosLED2, red, outer_radius, wires, false);
	} else {
		DrawTorus(PosLED2, red, outer_radius, inner_radius, wires, false);
	}
	glPopMatrix();
}

bool RailroadCrossing::GetLED1() const {return !GetOpen() && !GetState();}
bool RailroadCrossing::GetLED2() const {return !GetOpen() &&  GetState();}

void RailroadCrossing::ToggleState() {
	DebugPrint("RailroadCrossing", "ToggleState()");
	SetState(!GetState());
}

void RailroadCrossing::Run() {
	DebugPrint("RailroadCrossing", "Run()");
	// sleep, toggle state
	DebugPrint("RailroadCrossing", "Run: not yet implemented");
	// must make a while IsRunning or smth
	/*
	while(!GetOpen()) {
		ToggleState();
		usleep(5000000);
	}
	*/
}
