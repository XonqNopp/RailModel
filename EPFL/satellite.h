#ifndef satellite_h
#define satellite_h

#include "corps.h"

class satellite: public corps
{
private:
	//un satellite est affiche en cube, le rayon sera le cote
	
public:
	satellite();
	satellite( string n,
			   const vecteur3d& p,
			   const vecteur3d& v,
			   const vecteur3d& a,
			   const double& m,
			   const couleur4d& c );
	virtual ~satellite();
	void setm( const double& m );
	void parametre_affichage();
	void dessine( const bool& names ) const;
	void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, const satellite& s );
};

#endif // satellite_h
