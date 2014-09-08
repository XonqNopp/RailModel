#include "satellite.h"

// constructeur par defaut
satellite::satellite()
	:corps()
{
	setgenre( sat );
	parametre_affichage();
}

// constructeur par valeurs
satellite::satellite( string n,
					  const vecteur3d& p,
					  const vecteur3d& v,
					  const vecteur3d& a,
					  const double& m,
					  const couleur4d& c )
	:corps( sat, n, p, v, a, m, c )
{
	parametre_affichage();
}

// destructeur
satellite::~satellite()
{}

// change la masse
void satellite::setm( const double& m )
{
	corps::setm( m );
	parametre_affichage();
}

// dessine le satellite dans l'interface graphique
void satellite::dessine( const bool& names ) const
{
	glPushMatrix();
	glColor4d( getc().getr(),
			   getc().getv(),
			   getc().getb(),
			   getc().gett() );
	glTranslated( getp().getx(),
				  getp().gety(),
				  getp().getz() );
	glutSolidCube( getrayon() );
	glPopMatrix();
	corps::dessine( names );
}

// calcul les parametres necessaires a l'interface graphique
void satellite::parametre_affichage()
{
	setrayon( 2.5 * 2 * ( RAYON_MIN + ( ( ( getm() - MASSE_MIN ) *
										  ( RAYON_MAX - RAYON_MIN ) ) /
										( MASSE_MAX - MASSE_MIN ) ) ) );
}

// fonction d'affichage
void satellite::affiche( ostream& out ) const
{
	corps::affiche( out );
	out << "   * Cote : " << setw( 15 ) << getrayon() << endl << endl;
}

// operateur d'affichage
ostream& operator<<( ostream& out, const satellite& s )
{
	s.affiche( out );
	return out;
}
