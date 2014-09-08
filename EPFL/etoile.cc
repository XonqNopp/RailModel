#include "etoile.h"

// nombre de fils qui compose le tore
int etoile::wires = 30;

// constructeur par defaut
etoile::etoile()
	:corps()
{
	setgenre( eto );
	parametre_affichage();
}

// constructeur par valeurs
etoile::etoile( string n,
				const vecteur3d& p,
				const vecteur3d& v,
				const vecteur3d& a,
				const double& m,
				const couleur4d& c )
	:corps( eto, n, p, v, a, m, c )
{
	parametre_affichage();
}

// destructeur
etoile::~etoile()
{}

// change la masse
void etoile::setm( const double& m )
{
	corps::setm( m );
	parametre_affichage();
}

// renvoie le rayon moyen
double etoile::getrayon() const
{
	return ( corps::getrayon() + ( getrayone() - getrayoni() ) );
}

// renvoie le rayon interieur
double etoile::getrayoni() const { return rayon_int; }

// renvoie le rayon exterieur
double etoile::getrayone() const { return rayon_ext; }

// attribue r au rayon interieur
void etoile::setrayoni( const double& r ) { rayon_int = r; }

// attribue r au rayon exterieur
void etoile::setrayone( const double& r ) { rayon_ext = r; }

// renvoie la valeur de l'offset
double etoile::getoffset() const { return offset; }

// attribue nb a l'offset
void etoile::setoffset( const double& nb ) { offset = nb; }

// dessine l'etoile dans l'interface graphique
void etoile::dessine( const bool& names ) const
{
	glPushMatrix();
	glColor4d( getc().getr(),
			   getc().getv(),
			   getc().getb(),
			   getc().gett() );
	glTranslated( getp().getx(),
				  getp().gety(),
				  getp().getz() );
	glutSolidTorus( getrayoni(),
					getrayone(),
					wires,
					wires );
	glPopMatrix();
	corps::dessine( names );
}

// calcul les donnees necessaires pour l'interface graphique
void etoile::parametre_affichage()
{
	setrayon( 5 * ( getRN() + ( ( ( getm() - getMN() ) *
									( getRX() - getRN() ) ) /
									( getMX() - getMN() ) ) ) );
	setoffset( corps::getrayon() / 2 );
	setrayoni( corps::getrayon() - getoffset() );
	setrayone( corps::getrayon() + getoffset() );
}

// fonction d'affichage
void etoile::affiche( ostream& out ) const
{
	corps::affiche( out );
	out << "   * Rayon moyen : " << setw( 8 ) << getrayon() << endl
		<< "   * Rayon interieur : " << setw( 1 )  << getrayoni() << endl
		<< "   * Rayon exterieur : " << setw( 1 ) << getrayone() << endl << endl;
}

// operateur d'affichage
ostream& operator<<( ostream& out, const etoile& e )
{
	e.affiche( out );
	return out;
}
