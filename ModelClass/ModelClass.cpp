/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Fri 06 Dec 2013 08:43:19 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#include "ModelClass.hpp"
using namespace std;


const unsigned int ModelClass::IDoffsets[9] = {
	1,//    default
	1000,// PartialPath
	2000,// Aiguillage
	3000,// RailroadCrossing
	4000,// NowSignalL
	5000,// PreSignalL
	6000,// NowSignalN
	7000//  PreSignalN
};

ModelClass::ModelClass()
	:ID(0), Kind(0), debug(true), Open(false)
{
	DebugPrint("ModelClass", "ModelClass() using default constructor *NOT DESIGNED*");
}

ModelClass::ModelClass(const ModelClass& MC)
	:ID(MC.GetID()), Kind(MC.GetKind()), debug(MC.GetDebug()), Open(MC.GetOpen())
{}

ModelClass::ModelClass(ModelClass* MC)
	:ID(MC->GetID()), Kind(MC->GetKind()), debug(MC->GetDebug()), Open(MC->GetOpen())
{}

ModelClass::ModelClass(const unsigned int& NewID, const unsigned int& NewKind)
	:ID(NewID), Kind(NewKind), debug(false), Open(false)
{}

ModelClass::~ModelClass() {}


unsigned int ModelClass::GetID() const {return ID;}
unsigned int ModelClass::GetKind() const {return Kind;}

void ModelClass::SetID(const unsigned int& NewID) throw(out_of_range) {
	if(NewID >= GetModulo()) {
		throw out_of_range("ID must be less than " + ToStr(GetModulo()));
	}
	ID = GetIDoffset() + NewID;
}

bool ModelClass::GetDebug() const {return debug;}
void ModelClass::SetDebug(const bool& NewDebug) {debug = NewDebug;}
bool ModelClass::GetOpen() const {return Open;}

void ModelClass::SetOpen(const bool& NewOpen) {
	DebugPrint("ModelClass", "SetOpen(" + ToStr(NewOpen) + ")");
	Open = NewOpen;
}

void ModelClass::ToggleOpen()     {SetOpen(!GetOpen());}

bool ModelClass::PathOpen() const {
	DebugPrint("ModelClass", "PathOpen()");
	return GetOpen();
}


void ModelClass::DoDebug(const bool& NewDebug) {
	DebugPrint("ModelClass", "DoDebug stopping debug mode");
	SetDebug(NewDebug);
	DebugPrint("ModelClass", "DoDebug debug mode on");
	DebugPrint("ModelClass", "DoDebug kind    =" + ToStr(GetKind()));
	DebugPrint("ModelClass", "DoDebug IDoffset=" + ToStr(GetIDoffset()));
	DebugPrint("ModelClass", "DoDebug modulo  =" + ToStr(GetModulo()));
}

void ModelClass::DoDebug() {DoDebug(true);}

void ModelClass::DebugPrint(const string& ThisClass, const string& Str) const {
	if(GetDebug()) {
		cerr << " " << typeid(*this).name() << GetID() << flush;
		if(ThisClass != "") {
			cerr << "->" << ThisClass << "::" << flush;
		} else {
			cerr << "  " << flush;
		}
		cerr << Str << endl;
	}
}



unsigned int ModelClass::GetIDoffset() const {return IDoffsets[GetKind()];}
unsigned int ModelClass::GetModulo() const {
	return GetIDoffset() % 1000 == 0 ? 1000 : (GetIDoffset() % 100 == 0 ? 100 : 10);
}



void ModelClass::Display(ostream& out) const {
	out << " ModelClass ID=" << GetID();
	out << " Kind=" << GetKind();
	out << " Open=" << GetOpen();
	if(GetDebug()) {
		out << " (debug mode)";
	}
}

ostream& operator<<(ostream& out, const ModelClass& MC) {
	MC.Display(out);
	return out;
}

ostream& operator<<(ostream& out, ModelClass* MC) {
	MC->Display(out);
	return out;
}

//// These are only because we want to compute next signal
ModelClass* ModelClass::GetNextSignal(const unsigned int& PreviousPath) const {return 0;}
bool ModelClass::Status() const {return false;}
void ModelClass::Draw() const {DebugPrint("ModelClass", "Draw()");}

void ModelClass::DrawText(const string& text, const Vecteur3D& position, const Vecteur3D& colour, const bool& Complete) const {
	DebugPrint("ModelClass", "DrawText(" + text + ", " + ToStr(position) + ", " + ToStr(colour) + ", " + ToStr(Complete) + ")");
	if(Complete) {
		glPushMatrix();
	}
	glColor4d(colour.GetX(), colour.GetY(), colour.GetZ(), 1.0);
	glRasterPos3d(position.GetX(), position.GetY(), position.GetZ());
	const char* s(text.c_str());
	while(*s) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s);
		s++;
	}
	if(Complete) {
		glPopMatrix();
	}
}

void ModelClass::DrawText(const string& text, const Vecteur3D& position, const Vecteur3D& colour) const {
	DrawText(text, position, colour, true);
}

void ModelClass::DrawLine(const Vecteur3D& start, const Vecteur3D& end, const Vecteur3D& colour, const bool& Complete) const {
	DebugPrint("ModelClass", "DrawLine(" + ToStr(start) + ", " + ToStr(end) + ", " + ToStr(colour) + ", " + ToStr(Complete) + ")");
	if(Complete) {
		glPushMatrix();
	}
	glColor4d(colour.GetX(), colour.GetY(), colour.GetZ(), 1.0);
	glBegin(GL_LINES);
	glVertex3d(start.GetX(), start.GetY(), start.GetZ());
	glVertex3d(end.GetX(),   end.GetY(),   end.GetZ());
	glEnd();
	if(Complete) {
		glPopMatrix();
	}
}

void ModelClass::DrawLine(const Vecteur3D& start, const Vecteur3D& end, const Vecteur3D& colour) const {
	DrawLine(start, end, colour, true);
}

void ModelClass::DrawTorus(const Vecteur3D& position, const Vecteur3D& colour, const double& OuterRadius, const double& InnerRadius, const int& wires, const bool& Complete) const {
	if(Complete) {
		glPushMatrix();
	}
	glColor4d(colour.GetX(), colour.GetY(), colour.GetZ(), 1.0);
	glTranslated(position.GetX(), position.GetY(), position.GetZ());
	glutSolidTorus(InnerRadius, OuterRadius, wires, wires);
	if(Complete) {
		glPopMatrix();
	}
}

void ModelClass::DrawTorus(const Vecteur3D& position, const Vecteur3D& colour, const double& OuterRadius, const double& InnerRadius, const int& wires) const {
	DrawTorus(position, colour, OuterRadius, InnerRadius, wires, true);
}

void ModelClass::DrawSphere(const Vecteur3D& position, const Vecteur3D& colour, const double& Radius, const int& wires, const bool& Complete) const {
	if(Complete) {
		glPushMatrix();
	}
	glColor4d(colour.GetX(), colour.GetY(), colour.GetZ(), 1.0);
	glTranslated(position.GetX(), position.GetY(), position.GetZ());
	glutSolidSphere(Radius, wires, wires);
	if(Complete) {
		glPopMatrix();
	}
}

void ModelClass::DrawSphere(const Vecteur3D& position, const Vecteur3D& colour, const double& Radius, const int& wires) const {
	DrawSphere(position, colour, Radius, wires, true);
}
