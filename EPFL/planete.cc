#include "planete.h"

// nombre de fils qui dessinent la sphere
int planete::wires = 30; // A MODFIER!!! ( fct du rayon )

// constructeur par defaut
planete::planete()
	:corps()
{
	setgenre( pla );
	parametre_affichage();
}

// constructeur par valeurs
planete::planete( string n,
				  const vecteur3d& p,
				  const vecteur3d& v,
				  const vecteur3d& a,
				  const double& m,
				  const couleur4d& c )
	:corps( pla, n, p, v, a, m, c )
{
	parametre_affichage();
}

// destructeur
planete::~planete()
{}

// change la masse
void planete::setm( const double& m )
{
	corps::setm( m );
	parametre_affichage();
}

// dessine la planete dans l'interface graphique
void planete::dessine( const bool& names ) const
{
	glPushMatrix();
	glColor4d( getc().getr(),
			   getc().getv(),
			   getc().getb(),
			   getc().gett() );
	glTranslated( getp().getx(),
				  getp().gety(),
				  getp().getz() );
	glutSolidSphere( getrayon(),
					 wires,
					 wires );
	glPopMatrix();
	corps::dessine( names );
}

// calcul les parametres necessaires a l'interface graphique
void planete::parametre_affichage()
{
	rayon = 5 * ( RAYON_MIN + ( ( ( getm() - MASSE_MIN ) *
							 ( RAYON_MAX - RAYON_MIN ) ) /
						   ( MASSE_MAX - MASSE_MIN ) ) );
}

// fonction d'affichage
void planete::affiche( ostream& out ) const
{
	corps::affiche( out );
	out << "   * Rayon : " << setw( 14 ) << rayon << endl << endl;
}

// operateur d'affichage
ostream& operator<<( ostream& out, const planete& p )
{
	p.affiche( out );
	return out;
}
