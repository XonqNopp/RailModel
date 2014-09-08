/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : 2006-03-01
 ***** Last modified: Wed 04 Dec 2013 12:46:25 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#include "Vecteur3D.hpp"
using namespace std;

// constructeur par defaut
Vecteur3D::Vecteur3D()
	:x(0), y(0), z(0)
{}

// constructeur de copie
Vecteur3D::Vecteur3D(const Vecteur3D& v)
	: x(v.GetX()), y(v.GetY()), z(v.GetZ())
{}

// constructeur par 3 valeurs donnees
Vecteur3D::Vecteur3D(const double& a, const double& b, const double& c)
	: x(a), y(b), z(c)
{}

// destructeur
Vecteur3D::~Vecteur3D() {}

// attribution d'une valeur à x
void Vecteur3D::SetX(const double& a) {x = a;}

// attribution d'une valeur à y
void Vecteur3D::SetY(const double& b) {y = b;}

// attribution d'une valeur à z
void Vecteur3D::SetZ(const double& c) {z = c;}

// attribution de 3 valeurs à un Vecteur3D
void Vecteur3D::SetVecteur3D(const double& a, const double& b, const double& c) {
	SetX(a);
	SetY(b);
	SetZ(c);
}

// attribution d'un Vecteur3D à un Vecteur3D
void Vecteur3D::SetVecteur3D(const Vecteur3D& v) {
	SetX(v.GetX());
	SetY(v.GetY());
	SetZ(v.GetZ());
}

// donne la valeur x
double Vecteur3D::GetX() const {return x;}

// donne la valeur y
double Vecteur3D::GetY() const {return y;}

// donne la valeur z
double Vecteur3D::GetZ() const {return z;}

// l'operateur == teste si le premier Vecteur3D est identique au second
bool Vecteur3D::operator==(const Vecteur3D& v) const {
	return ((GetX() == v.GetX()) &&
			 (GetY() == v.GetY()) &&
			 (GetZ() == v.GetZ()));
}

// l'operateur != renvoie teste si les 2 vecteurs sont differents
bool Vecteur3D::operator!=(const Vecteur3D& v) const {
	return ((GetX() != v.GetX()) &&
			 (GetY() != v.GetY()) &&
			 (GetZ() != v.GetZ()));
}

// l'operateur + renvoie la somme de chacune des composantes de 2 Vecteur3D donnes
Vecteur3D Vecteur3D::operator+(const Vecteur3D& v) const {
	return Vecteur3D(GetX() + v.GetX(), GetY() + v.GetY(), GetZ() + v.GetZ());
}

// l'operateur - renvoie la différence entre chacune des composantes de 2 Vecteur3D donnes
Vecteur3D Vecteur3D::operator-(const Vecteur3D& v) const {
	return Vecteur3D(GetX() - v.GetX(), GetY() - v.GetY(), GetZ() - v.GetZ());
}

// l'operateur - sans argument apres renvoie l'oppose du Vecteur3D donné
Vecteur3D Vecteur3D::operator-() const {
	return Vecteur3D(-GetX(), -GetY(), -GetZ());
}

// l'operateur du produit scalaire
double Vecteur3D::operator*(const Vecteur3D& v) const {
	return ((GetX() * v.GetX()) + (GetY() * v.GetY()) + (GetZ() * v.GetZ()));
}

// l'operateur du produit vectoriel
Vecteur3D Vecteur3D::operator^(const Vecteur3D& v) const {
	Vecteur3D r;
	r.SetX((GetY() * v.GetZ()) - (GetZ() * v.GetY()));
	r.SetY((GetZ() * v.GetX()) - (GetX() * v.GetZ()));
	r.SetZ((GetX() * v.GetY()) - (GetY() * v.GetX()));
	return r;
}

// renvoie la norme d'un Vecteur3D
double Vecteur3D::Norme() const {
	return (pow((GetX() * GetX()) + (GetY() * GetY()) + (GetZ() * GetZ()), 1.0/2.0));
}

// l'operateur < teste si le premier Vecteur3D est plus petit que le second
bool Vecteur3D::operator<(const Vecteur3D& v) const {return (Norme() < v.Norme());}

// l'operateur > teste si le premier Vecteur3D est plus grand que le second
bool Vecteur3D::operator>(const Vecteur3D& v) const {return (Norme() > v.Norme());}

// l'operateur <= teste si le premier Vecteur3D est plus petit ou egal au le second
bool Vecteur3D::operator<=(const Vecteur3D& v) const {return (Norme() <= v.Norme());}

// l'operateur >= teste si le premier Vecteur3D est plus grand ou egal au le second
bool Vecteur3D::operator>=(const Vecteur3D& v) const {return (Norme() >= v.Norme());}

// l'operateur = met le 2e Vecteur3D donné dans le premier
const Vecteur3D& Vecteur3D::operator=(const Vecteur3D& v) {
	if(this != &v) {
		SetX(v.GetX());
		SetY(v.GetY());
		SetZ(v.GetZ());
	}
	return *this;
}

// l'operateur += renvoie le premier Vecteur3D augmenté du second
const Vecteur3D& Vecteur3D::operator+=(const Vecteur3D& v) {
	SetX(GetX() + v.GetX());
	SetY(GetY() + v.GetY());
	SetZ(GetZ() + v.GetZ());
	return *this;
}

// l'operateur -= renvoie le premier vectuer3d soustrait du second
const Vecteur3D& Vecteur3D::operator-=(const Vecteur3D& v) {
	SetX(GetX() - v.GetX());
	SetY(GetY() - v.GetY());
	SetZ(GetZ() - v.GetZ());
	return *this;
}

// l'operateur ++ met le Vecteur3D incrémenté de 1 dans les 3 directions
const Vecteur3D& Vecteur3D::operator++(int) {
	SetX(GetX() + 1);
	SetY(GetY() + 1);
	SetZ(GetZ() + 1);
	return *this;
}

// renvoie le vecteur unitaire dans le sens de celui donne
Vecteur3D Vecteur3D::Unit() const {
	Vecteur3D r;
	if(Norme() > 0) {
		r.SetX(GetX() / Norme());
		r.SetY(GetY() / Norme());
		r.SetZ(GetZ() / Norme());
	}
	return r;
}

// la fonction d'affichage
void Vecteur3D::Display(std::ostream& out) const {
	out << "(" << GetX() << ", " << GetY() << ", " << GetZ() << ")";
}

// l'operateur << affiche le Vecteur3D
std::ostream& operator<<(std::ostream& out, const Vecteur3D& v) {
	v.Display(out);
	return out;
}

// l'operateur de multiplication par un scalaire
Vecteur3D operator*(const double& a, const Vecteur3D& v) {
	return Vecteur3D(a * v.GetX(), a * v.GetY(), a * v.GetZ());
}

// la meme chose, mais pour que l'operateur * soit commutatif
Vecteur3D operator*(const Vecteur3D& v, const double& a) {
	return Vecteur3D(a * v.GetX(), a * v.GetY(), a * v.GetZ());
}

// l'operateur de division par un scalaire
Vecteur3D operator/(const Vecteur3D& v, const double& a) {
	return Vecteur3D(v.GetX() / a, v.GetY() / a, v.GetZ() / a);
}
