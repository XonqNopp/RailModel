#include "corps.h"

// parametre pour les methodes d'integrations numeriques, pour savoir combien on retient de positions/vitesses/accelerations anterieurs
int corps::tailleintegr = 4;
int corps::gettailleintegr() const { return tailleintegr; }

// attirbuer le genre
void corps::setgenre( const startrek& st ) { genre = st; }

// attribuer le vecteur v a la position
void corps::setp( const vecteur3d& v ) { position = v; }

// attribuer le vecteur v a la vitesse
void corps::setv( const vecteur3d& v ) { vitesse = v; }

// attribuer le vecteur v a l'acceleration
void corps::seta( const vecteur3d& v ) { acceleration = v; }

// attribuer m a la masse
void corps::setm( const double& m ) { masse = m; }

// attribuer n au nom
void corps::setn( string n ) { nom = n; }

// attribuer c a la couleur
void corps::setc( const couleur4d& c ) { couleur = c; }

// retourne le genre
startrek corps::getgenre() const { return genre; }

// retourne le genre sous forme de string
string corps::getgenrestr() const
{
	switch( getgenre() ){
		case eto:
			return "etoile";
			break;
		case pla:
			return "planete";
			break;
		case sat:
			return "satellite";
			break;
		case ast:
			return "asteroide";
			break;
		default:
			return "";
			break;
	}
}

// attribue v a la toute la liste des positions anterieures
void corps::cadeauxpos( const vecteur3d& v )
{
	aventpos.clear();
	for( int i( 0 ); i < gettailleintegr(); ++i ){
		aventpos.push_back( v );
	}
}

// attribue v a la derniere position anterieure
void corps::calendrierpos( const vecteur3d& v )
{
	for( int i( 0 ); i < gettailleintegr() - 1; ++i ){
		aventpos[ i ] = aventpos[i + 1 ];
	}
	aventpos[ gettailleintegr() - 1 ] = v;
}

// attribue v a toute la liste des vitesses passees
void corps::cadeauxvit( const vecteur3d& v )
{
	aventvit.clear();
	for( int i( 0 ); i < gettailleintegr(); ++i ){
		aventvit.push_back( v );
	}
}

// attribue v a la derniere vitesse
void corps::calendriervit( const vecteur3d& v )
{
	for( int i( 0 ); i < gettailleintegr() - 1; ++i ){
		aventvit[ i ] = aventvit[ i + 1 ];
	}
	aventvit[ gettailleintegr() - 1 ] = v;
}

// attribue v a toute la liste des accelerations anterieures
void corps::cadeauxacc( const vecteur3d& v )
{
	aventacc.clear();
	for( int i( 0 ); i < gettailleintegr(); ++i ){
		aventacc.push_back( v );
	}
}

// attribue v a la derniere acceleration
void corps::calendrieracc( const vecteur3d& v )
{
	for( int i( 0 ); i < gettailleintegr() - 1; ++i ){
		aventacc[ i ] = aventacc[ i + 1 ];
	}
	aventacc[ gettailleintegr() - 1 ] = v;
}

// renvoie la position
vecteur3d corps::getp() const { return position; }

// renvoie la vitesse
vecteur3d corps::getv() const { return vitesse; }

// renvoie l'acceleration
vecteur3d corps::geta() const { return acceleration; }

// renvoie la masse
double corps::getm() const { return masse; }

// renvoie le nom
string corps::getn() const { return nom; }

// renvoie la couleur (sous format RVB)
couleur4d corps::getc() const { return couleur; }

// renvoie la liste des positions anterieures
vector< vecteur3d > corps::newyearpos() const { return aventpos; }

// renvoie la n-ieme position anterieure
vecteur3d corps::noelpos( const int& n ) const throw( out_of_range )
{
	return aventpos.at( n );
}

// retourne la derniere position
vecteur3d corps::noelposlast() const { return aventpos[ aventpos.size() - 1 ]; }

// renvoie la liste des vitesses anterieures
vector< vecteur3d > corps::newyearvit() const { return aventvit; }

// retourne la n-ieme vitesse anterieure
vecteur3d corps::noelvit( const int& n ) const throw( out_of_range )
{
	return aventvit.at( n );
}

// retourne la liste des accelerations anterieures
vector< vecteur3d > corps::newyearacc() const { return aventacc; }

// renvoie la n-ieme acceleration precedente
vecteur3d corps::noelacc( const int& n ) const throw( out_of_range )
{
	return aventacc.at( n );
}

// teste si le premier corps est semblable au second
bool corps::operator==( const corps& c ) const
{
	return ( ( getgenre() == c.getgenre() ) &&
			 ( getp() == c.getp() ) &&
			 ( getv() == c.getv() ) &&
			 ( geta() == c.geta() ) &&
			 ( getm() == c.getm() ) &&
			 ( getn() == c.getn() ) &&
			 ( getc() == c.getc() ) );
}

// constructeur par defaut
corps::corps()
	:genre( pla ),
	 position( vecteur3d() ),
	 vitesse( vecteur3d() ),
	 acceleration( vecteur3d() ),
	 masse( 0.0 ), nom( "" ),
	 couleur( couleur4d() )
{
	cadeauxpos( getp() );
	cadeauxacc( geta() );
}

// constructeur par valeurs
corps::corps( startrek st,
			  string n,
			  const vecteur3d& p,
			  const vecteur3d& v,
			  const vecteur3d& a,
			  const double& m,
			  const couleur4d& c)
	:genre( st ),
	 nom( n ),
	 position( p ),
	 vitesse( v ),
	 acceleration( a ),
	 masse( m ),
	 couleur( c ),
	 rayon( 0 )
{
	cadeauxpos( getp() );
	cadeauxacc( geta() );
}

// constructeur de copie
corps::corps( const corps& c )
	:genre( c.getgenre() ),
	 nom( c.getn() ),
	 position( c.getp() ),
	 vitesse( c.getv() ),
	 acceleration( c.geta() ),
	 masse( c.getm() ),
	 couleur( c.getc() ),
	 rayon( c.getrayon() ),
	 aventpos( c.newyearpos() ),
	 aventvit( c.newyearvit() ),
	 aventacc( c.newyearacc() )
{
	cadeauxpos( getp() );
	cadeauxacc( geta() );
}

// destructeur
corps::~corps()
{}

// operateur d'affichage
ostream& operator<<( ostream& out, const corps& c )
{
	c.affiche( out );
	return out;
}

// fonction d'affichage
void corps::affiche( ostream& out ) const
{
	out << " ### " << nom << " ###   (" << getgenrestr() << ")" << endl
		<< "   * Position : " << setw( 9 ) << getp() << endl
		<< "   * Vitesse : " << setw( 10 ) << getv() << endl
		<< "   * Acceleration : " << setw( 5 ) << geta() << endl;
	out.setf( ios::showpoint );
	out << "   * Masse : " << setprecision( 3 ) << setw( 18 ) << getm() << endl;
	out.unsetf( ios::showpoint );
	out << "   * Couleur : " << setw( 10 ) << getc() << endl;
}

// operateur de copie
corps& corps::operator=( const corps& c )
{
	setgenre( c.getgenre() );
	setn( c.getn() );
	setp( c.getp() );
	setv( c.getv() );
	seta( c.geta() );
	setm( c.getm() );
	setc( c.getc() );
}


/**** constantes necessaires pour l'affichage dans glut,     ****
 **** parametres de taille des differentes formes affichees. ****/

double corps::RAYON_MIN = 0.01;

double corps::RAYON_MAX = 0.2;

double corps::MASSE_MIN = 1.8375e22;

double corps::MASSE_MAX = 3.9782e30;


// retournent rayon/masse min/max

double corps::getRN() { return RAYON_MIN; }

double corps::getRX() { return RAYON_MAX; }

double corps::getMN() { return MASSE_MIN; }

double corps::getMX() { return MASSE_MAX; }

// dessine le nom dans glut
void corps::dessine( const bool& names ) const
{
	if ( names ) {
		glPushMatrix();
		glColor4d( getc().getr(),
				   getc().getv(),
				   getc().getb(),
				   getc().gett() );
		glRasterPos3d( getp().getx() + 0.02, getp().gety() + 0.02, getp().getz() + 0.02 );
		const char* s( getn().c_str() );
		while (*s) {
			glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, *s );
			s++;
		}
		glPopMatrix();
	}
}

// calcul les interactions entre les corps
vecteur3d corps::interaction( const corps* c, const double& g, const bool& b ) throw( bool )
{
	vecteur3d distancevec( ( c->getp() ) - getp() );
	double distance( distancevec.norme() );
	vecteur3d forcevec;
	double m( getm() * c->getm() );
	if( distance > c->getrayon() + getrayon() ){
		double force( ( m * g ) / pow( distance, 2.0 ) );
		forcevec = force * ( distancevec.unitaire() );
	}else{
		if( b ){
			throw bool( true );//********************************************************************************************************
		}
	}
	return forcevec;
}

// get/set le rayon du corps
double corps::getrayon() const { return rayon; }
void corps::setrayon( const double& r ) { rayon = r; }

// calcul l'attraction sur un corps pour une force donnee
void corps::setattraction( const vecteur3d& f )
{
	seta( ( 1 / getm() ) * f );
}

// met a jour le corps
void corps::mise_a_jour( const double& dt ) throw( bool )
{
	calendrierpos( getp() );
	calendrieracc( geta() );

// Methode d'Euler (qui fonctionne normalement)
	setv( getv() + ( geta() * dt ) );
	setp( getp() + ( getv() * dt ) );

	
	/*
// 1er essai d'integration... 5e ordre:

//	p2 = p1 + p-1 - p-2 + dt^2 * ( 1 / 4 ) * ( 5 * ( a1 + a-1 ) + 2 * a0 )

	setp( noelposlast() + noelpos( 1 ) - noelpos( 0 ) +
		  ( ( dt * dt ) * ( 5 * ( noelacc( 3 ) + noelacc( 1 ) ) ) +
			( 2 * noelacc( 2 ) ) ) );

	:-( Ca fonctionne pas....
	*/
	
	/*
// 2e essai d'integration... 4e ordre

// p2 = p-2 + dt( 8v1 - 4v0 + 8v-1 ) / 3

	setp( noelpos( 0 ) + dt * ( ( 8 * noelvit( 3 ) -
								  4 * noelvit( 2 ) +
								  8 * noelvit( 1 ) ) ) / 3.0 );

    :'( Ca fonctionne pas non plus
	*/

}

// retourne la distance entre 2 corps
double corps::stance( const corps* c ) const
{
	vecteur3d distvec( getp() - c->getp() );
	return distvec.norme();
}

// affiche les orbites dans glut
void corps::orbites() const
{
	glPushMatrix();
	glColor4d( couleur.getr(), couleur.getv(), couleur.getb(), couleur.gett() );
	glBegin(GL_LINES);
	glVertex3d( noelposlast().getx(), noelposlast().gety(), noelposlast().getz() );
	glVertex3d( getp().getx(), getp().gety(), getp().getz() );
	glEnd();
	glPopMatrix();
}

/*** affiche les orbites dans le plan correspondant ***/
void corps::projectionX() const
{
	glPushMatrix();
	glColor4d( couleur.getr(), couleur.getv(), couleur.getb(), couleur.gett() );
	glBegin(GL_LINES);
	glVertex3d( 0.0, noelposlast().gety(), noelposlast().getz() );
	glVertex3d( 0.0, getp().gety(), getp().getz() );
	glEnd();
	glPopMatrix();
}

void corps::projectionY() const
{
	glPushMatrix();
	glColor4d( couleur.getr(), couleur.getv(), couleur.getb(), couleur.gett() );
	glBegin(GL_LINES);
	glVertex3d( noelposlast().getx(), 0.0, noelposlast().getz() );
	glVertex3d( getp().getx(), 0.0, getp().getz() );
	glEnd();
	glPopMatrix();
}

void corps::projectionZ() const
{
	glPushMatrix();
	glColor4d( couleur.getr(), couleur.getv(), couleur.getb(), couleur.gett() );
	glBegin(GL_LINE_STRIP);
	glVertex3d( noelposlast().getx(), noelposlast().gety(), 0.0 );
	glVertex3d( getp().getx(), getp().gety(), 0.0 );
	glEnd();
	glPopMatrix();
}
/*** ...et dans les 3 plans en meme temps ***/
void corps::projection() const
{
	projectionX();
	projectionY();
	projectionZ();
}



