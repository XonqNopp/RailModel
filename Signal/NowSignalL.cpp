/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Wed 04 Dec 2013 08:52:37 AM CET
 ***** Last modified: Thu 05 Dec 2013 09:36:37 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "NowSignalL.hpp"
using namespace std;

NowSignalL::NowSignalL(const unsigned int& NewID)
	:NowSignal(NewID, 4)
{
	SetID(NewID);
}

NowSignalL::~NowSignalL() {}

void NowSignalL::Display(ostream& out) const {
	if(GetL() > 1) {
		out << "     _" << endl;
		out << "    / \\" << endl;
		out << "   /   \\" << endl;
		//
		char ThisColour('x');
		for(unsigned int i(0); i < GetL(); i++) {
			out << "   |";
			if(
			   (GetL() == 2 && i == 1)
			   || (GetL() == 3 && i == 1)
			   || (GetL() == 4 && i == 1)
			  ) {
				ThisColour = 'r';
			} else if(
					  (GetL() == 2 && i == 0)
					  || (GetL() == 3 && i == 0)
					  || (GetL() == 4 && (i == 0 || i == 3))
					 ) {
				ThisColour = 'g';
			} else if(
					  (GetL() == 3 && i == 2)
					  || (GetL() == 4 && i == 2)
					 ) {
				ThisColour = 'y';
			}
			if(GetLEDs(i)) {
				out << "(" << ThisColour << ")";
			} else {
				out << ">" << ThisColour << "<";
			}
			out << "|" << endl;
		}
		out << "   \\   /" << endl;
		out << "    \\ /" << endl;
		out << "      |" << endl;
	} else {
		out << " NowSignalL not defined yet" << endl;
	}
}

void NowSignalL::Draw() const {
	if(GetL() > 1) {
		/* line start at pos (short)
		 *    _
		 *   / \
		 *   |x|  (g)
		 *   |o|  >r<
		 *   \ /
		 *    |
		*/

		// Some coordinates
		double Sqrt2(pow(2, 1.0/2.0));
		Vecteur3D HeightUnit(GetDirection());
		Vecteur3D base(GetPosition() + HeightUnit);
		Vecteur3D HalfWidth(HeightUnit.GetY()/Sqrt2, -HeightUnit.GetX()/Sqrt2, HeightUnit.GetZ());
		Vecteur3D BaseLeft( base + HeightUnit - HalfWidth);
		Vecteur3D BaseRight(base + HeightUnit + HalfWidth);
		// Some colours
		Vecteur3D gray(0.7, 0.7, 0.7);
		Vecteur3D red(1, 0, 0);
		Vecteur3D green(0, 1, 0);
		Vecteur3D yellow(0, 1, 1);
		// Now proceed
		glPushMatrix();
		DrawLine(GetPosition(), base, gray, false);
		DrawLine(base, BaseLeft,  gray, false);
		DrawLine(base, BaseRight, gray, false);
		// Now do the parts
		double OuterRadius(2.0), InnerRadius(1.0);
		int wires(30);
		unsigned int i(0);
		for(i = 1; i <= GetL(); i++) {
			unsigned int j(GetL() - i);//// because top to bottom -> bottom to top
			DrawLine(BaseLeft  + (i-1) * HeightUnit, BaseLeft  + i * HeightUnit, gray, false);
			DrawLine(BaseRight + (i-1) * HeightUnit, BaseRight + i * HeightUnit, gray, false);
			Vecteur3D ThisColour(gray);
			if(
			   (GetL() == 2 && j == 1)
			   || (GetL() == 3 && j == 1)
			   || (GetL() == 4 && j == 1)
			  ) {
				ThisColour = red;
			} else if(
					  (GetL() == 2 && j == 0)
					  || (GetL() == 3 && j == 0)
					  || (GetL() == 4 && (j == 0 || j == 3))
					 ) {
				ThisColour = green;
			} else if(
					  (GetL() == 3 && j == 2)
					  || (GetL() == 4 && j == 2)
					 ) {
				ThisColour = yellow;
			}
			if(GetLEDs(j)) {
				DrawSphere(base + (2*i+1)*HeightUnit, ThisColour, OuterRadius, wires, false);
			} else {
				DrawTorus( base + (2*i+1)*HeightUnit, ThisColour, OuterRadius, InnerRadius, wires, false);
			}
		}
		// end
		DrawLine(BaseLeft +i*HeightUnit, BaseLeft +(i+1)*HeightUnit + HalfWidth, gray, false);
		DrawLine(BaseRight+i*HeightUnit, BaseRight+(i+1)*HeightUnit - HalfWidth, gray, false);
		glPopMatrix();
	}
}
