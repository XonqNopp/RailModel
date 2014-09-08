#ifndef asteroide_h
#define asteroide_h

#include "corps.h"

class asteroide: public corps
{
private:
	static int wires;
public:
	asteroide();
	asteroide( const string& n,
			   const vecteur3d& pos,
			   const vecteur3d& vit,
			   const vecteur3d& acc,
			   const double& masse,
			   const couleur4d& coul);
	virtual ~asteroide();
	void setm( const double& m );
	friend ostream& operator<<( ostream& out, const asteroide& a );
	void affiche( ostream& out ) const;
	void parametre_affichage();
	void dessine( const bool& names ) const;
	void mise_a_jour( const double& dt ) throw( bool );
	vecteur3d interaction( const corps* c, const double& g, const bool& b ) throw( bool );
};

#endif // asteroide_h
