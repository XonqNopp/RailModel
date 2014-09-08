#ifndef etoile_h
#define etoile_h

#include "corps.h"

class etoile: public corps
{
private:
	// L'etoile est affichee par un tore, nous avons donc besoin de 2 rayons
	double rayon_ext;
	double rayon_int;
	double offset;
	static int wires;
public:
	etoile();
	etoile( string n,
			const vecteur3d& p,
			const vecteur3d& v,
			const vecteur3d& a,
			const double& m,
			const couleur4d& c );
	virtual ~etoile();
	void setm( const double& m );
	double getrayon() const;
	double getrayoni() const;
	double getrayone() const;
	void setrayoni( const double& r );
	void setrayone( const double& r );
	double getoffset() const;
	void setoffset( const double& nb );
	void parametre_affichage();
	void dessine( const bool& names ) const;
	friend ostream& operator<<( ostream& out, const etoile& e );
	void affiche( ostream& out ) const;
};


#endif // etoile_h
