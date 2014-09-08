/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : 2006-03-01
 ***** Last modified: Wed 04 Dec 2013 12:43:51 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_VECTEUR3D__
#define __CLASS_VECTEUR3D__

#include <iostream>
#include <cmath>

class Vecteur3D {
protected:
	double x;
	double y;
	double z;
public:
	Vecteur3D();
	Vecteur3D(const Vecteur3D& v);
	Vecteur3D(const double& a, const double& b, const double& c);
	virtual ~Vecteur3D();
	void SetX(const double& a);
	void SetY(const double& b);
	void SetZ(const double& c);
	void SetVecteur3D(const double& a, const double& b, const double& c);
	void SetVecteur3D(const Vecteur3D& v);
	double GetX() const;
	double GetY() const;
	double GetZ() const;
	bool operator==(const Vecteur3D& v) const;
	bool operator!=(const Vecteur3D& v) const;
	Vecteur3D operator+(const Vecteur3D& v) const;
	Vecteur3D operator-(const Vecteur3D& v) const;
	Vecteur3D operator-() const;
	double operator*(const Vecteur3D& v) const;
	Vecteur3D operator^(const Vecteur3D& v) const;
	double Norme() const;
	bool operator<(const Vecteur3D& v) const;
	bool operator>(const Vecteur3D& v) const;
	bool operator<=(const Vecteur3D& v) const;
	bool operator>=(const Vecteur3D& v) const;
	const Vecteur3D& operator=(const Vecteur3D& v);
	const Vecteur3D& operator+=(const Vecteur3D& v);
	const Vecteur3D& operator-=(const Vecteur3D& v);
	const Vecteur3D& operator++(int);// needed because error -fpermissive
	Vecteur3D Unit() const;
	void Display(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const Vecteur3D& v);
	friend Vecteur3D operator*(const double& a, const Vecteur3D& v);
	friend Vecteur3D operator*(const Vecteur3D& v, const double& a);
	friend Vecteur3D operator/(const Vecteur3D& v, const double& a);
};

#endif // __CLASS_VECTEUR3D__
