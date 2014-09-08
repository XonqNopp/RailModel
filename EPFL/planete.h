#ifndef planete_h
#define planete_h

#include "corps.h"

class planete: public corps 
{
private:
	//une planete est afichee par une sphere, nous avons son rayon
	static int wires;
	
	
public:
	planete();
	planete( string n,
			 const vecteur3d& p,
			 const vecteur3d& v,
			 const vecteur3d& a,
			 const double& m,
			 const couleur4d& c );
	virtual ~planete();
	void setm( const double& m );
	void parametre_affichage();
	void dessine( const bool& names ) const;
	friend ostream& operator<<( ostream& out, const planete& p );
	void affiche( ostream& out ) const;
};

#endif // planete_h
