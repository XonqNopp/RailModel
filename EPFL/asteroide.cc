#include "asteroide.h"

int asteroide::wires = 30;

/*** les constructeurs ***/
asteroide::asteroide()
	:corps()
{
	setgenre( ast );
	parametre_affichage();
}

asteroide::asteroide( const string& n,
					  const vecteur3d& pos,
					  const vecteur3d& vit,
					  const vecteur3d& acc,
					  const double& masse,
					  const couleur4d& coul )
	:corps( ast, n, pos, vit, acc, masse, coul )
{
	parametre_affichage();
}

/*** le destructeur ***/
asteroide::~asteroide()
{}

// change la masse
void asteroide::setm( const double& m )
{
	corps::setm( m );
	parametre_affichage();
}

// operateur d'affichage
ostream& operator<<( ostream& out, const asteroide& a )
{
	a.affiche( out );
	return out;
}

// fonction d'affichage
void asteroide::affiche( ostream& out ) const
{
	corps::affiche( out );
	out << "   * Rayon : " << setw( 13 ) << getrayon() << endl;
}

// calcul les parametres necessaires a l'interface graphique
void asteroide::parametre_affichage()
{
	// Modifier le facteur
	rayon = ( 4.0 / 9.0 ) * ( RAYON_MIN + ( ( ( getm() - MASSE_MIN ) *
										  ( RAYON_MAX - RAYON_MIN ) ) /
										( MASSE_MAX - MASSE_MIN ) ) );
}

// dessine l'asteroide dans glut
void asteroide::dessine( const bool& names ) const
{
	glPushMatrix();
	glColor4d( getc().getr(),
			   getc().getv(),
			   getc().getb(),
			   getc().gett() );
	glTranslated( getp().getx(),
				  getp().gety(),
				  getp().getz() );
	glutSolidSphere( 1.7 * getrayon(),
					 wires,
					 wires );
	glPopMatrix();
}

// met a jour l'asteroide
void asteroide::mise_a_jour( const double& dt ) throw( bool )
{
	if( getm() < 1 ){
		throw bool( true );
	}else{
		setm( getm() / 1.07 );
		corps::mise_a_jour( dt );
	}
}

// calcul les interactions entre les corps
vecteur3d asteroide::interaction( const corps* c, const double& g, const bool& b ) throw( bool )
{
	vecteur3d forcevec;
	if( b ){
		vecteur3d distancevec( ( c->getp() ) - getp() );
		double distance( distancevec.norme() );
		if( ( getgenre() == ast && c->getgenre() == eto ) ){
			if( distance <= getrayon() + 2.0 * c->getrayon() ){
				throw bool( true );
			}
		}else if( ( getgenre() == eto && c->getgenre() == ast ) ){
			if( distance <=  c->getrayon() + 2.0 * getrayon() ){
				throw bool( true );
			}
		}else{
			if( distance <= c->getrayon() + getrayon() ){
				throw bool( true );
			}
		}
		double m( getm() * c->getm() );
		double force( ( m * g ) / pow( distance, 2 ) );
		forcevec = force * ( distancevec.unitaire() );
	}
	return forcevec;
}

