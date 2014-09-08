#ifndef corps_h
#define corps_h

#include "../vecteur3d/vecteur3d.h"
#include "../couleur4d/couleur4d.h"
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>

// On inclut les librairies glut Linux et Mac OS X pour les fonctions de dessin des sous-classes
#ifdef __APPLE__
    #include <GLUT/glut.h>   /* pour Mac OS X */
#else
   #include <GL/glut.h>     /* pour les autres systemes */
#endif

#ifndef star
#define star
enum startrek { alleluia, eto, pla, sat, ast };
#endif // star

class corps
{
protected:
	startrek genre;
	string nom;
	vecteur3d position;
	vecteur3d vitesse;
	vecteur3d acceleration;
	double masse;
	couleur4d couleur;
	static double RAYON_MIN;
	static double RAYON_MAX;
	static double MASSE_MIN;
	static double MASSE_MAX;
	double rayon;
	// ce qu'on a besoin pour les calculs des positions:
	vector< vecteur3d >aventpos;//memorise les positions precedentes
	vector< vecteur3d >aventvit;//memorise les vitesses precedentes
	vector< vecteur3d >aventacc;//memorise les accelerations anterieures
	static int tailleintegr;
public:
	int gettailleintegr() const;
	void setgenre( const startrek& st );
	void setp( const vecteur3d& v );
	void setv( const vecteur3d& v );
	void seta( const vecteur3d& v );
	virtual void setm( const double& m );
	void setn( string n );
	void setc( const couleur4d& c );
	startrek getgenre() const;
	string getgenrestr() const;
	void cadeauxpos( const vecteur3d& v );
	void calendrierpos( const vecteur3d& v );
	void cadeauxvit( const vecteur3d& v );
	void calendriervit( const vecteur3d& v );
	void cadeauxacc( const vecteur3d& v );
	void calendrieracc( const vecteur3d& v );
	vecteur3d getp() const;
	vecteur3d getv() const;
	vecteur3d geta() const;
	double getm() const;
	string getn() const;
	couleur4d getc() const;
	vector< vecteur3d > newyearpos() const;
	vector< vecteur3d > newyearvit() const;
	vector< vecteur3d > newyearacc() const;
	vecteur3d noelpos( const int& n ) const throw( out_of_range );
	vecteur3d noelposlast() const;
	vecteur3d noelvit( const int& n ) const throw( out_of_range );
	vecteur3d noelacc( const int& n ) const throw( out_of_range );
	bool operator==( const corps& c ) const;
	corps();
	corps( startrek st,
		   string n,
		   const vecteur3d& p,
		   const vecteur3d& v,
		   const vecteur3d& a,
		   const double& m,
		   const couleur4d& c);
	corps( const corps& c );
	virtual ~corps();
	friend ostream& operator<<( ostream& out, const corps& c );
	virtual void affiche( ostream& out ) const;
	corps& operator=( const corps& c );
	double getRN();
	double getRX();
	double getMN();
	double getMX();
	virtual void parametre_affichage() = 0;
	virtual void dessine( const bool& names ) const;
	virtual double getrayon() const;
	virtual void setrayon( const double& r );
	virtual vecteur3d interaction( const corps* c,
								   const double& g,
								   const bool& b ) throw( bool );
	void setattraction( const vecteur3d& f );
	virtual void mise_a_jour( const double& dt ) throw( bool );
	double stance( const corps* c ) const;
	void orbites() const;
	void projectionX() const;
	void projectionY() const;
	void projectionZ() const;
	void projection() const;
};

	
#endif // corps_h
