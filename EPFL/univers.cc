#include "univers.h"

// constructeur de copie qui ne fait rien (en commentaires, ce que nous pensons qu'il faudrait ecrire pour que cela fonctionne si on en avait besoin)
univers::univers( const univers& u )
//	:temps( u.gettemps() ), tempsecoule( u.gettempsecoule() ), pas( u.getpas() ), names( u.getqqch() ), lesdeuxcorps( u.getpaire() )
{
//	deepcopy( u );
}

// operateur de copie qui ne fait rien (meme cas que le constructeur de copie)
univers& univers::operator=( const univers& u )
{
//	deepcopy( u );
}

void univers::deepcopy( const univers& u )
{
// A REVOIR: Constructeur de copie de sous-corps par un pointeur sur un corps
/*	for( set< corps* >::iterator i( u.begin() ); i != u.end(); ++i ){
		switch( ( *i )->getgenre() ){
			case eto:
				ajoutcorps( new etoile( *i ) );
				break;
			case pla:
				ajoutcorps( new planete( *i ) );
				break;
			case sat:
				ajoutcorps( new satellite( *i ) );
				break;
			case ast:
				ajoutcorps( new asteroide( *i ) );
				break;
			default:
				break;
		}
	}*/
}

// constructeur par defaut
univers::univers()
	:dessinable(),
	 serie( set< corps* >() ),
	 temps( 365 ),
	 tempsecoule( 0 ),
	 pas( 1 ),
	 names( false )
{
	srand( time( 0 ) );
}

// constructeur par valeur
univers::univers( const camera& c,
				  set< corps* >s,
				  const double& t,
				  const double& te,
				  const double& p )
	:dessinable( c ),
	 serie( s ),
	 temps( t ),
	 tempsecoule( te ),
	 pas( p ),
	 names( false )
{
	srand( time( 0 ) );
}

// constructeur par valeurs, mais sans la camera
univers::univers( set< corps* >s,
				  const double& t,
				  const double& te,
				  const double& p )
	:dessinable(), serie( s ), temps( t ), tempsecoule( te ), pas( p ), names( false )
{}

// destructeur
univers::~univers()
{
	supprimelescorps();
}

// initialisation de l'attribut statique pour la constante de gravitation universelle
long double univers::cg = 6.67259e-11;

// attribue s à la serie de corps
void univers::sets( set< corps* >s) { serie = s; }

// attribue t au temps
void univers::settemps( const double& t ) { temps = t; }

void univers::settempsecoule( const double& t ) { tempsecoule = t; }

// attribue p au pas
void univers::setpas( const double& p ) { pas = p; }

// renvoie la serie de corps
set< corps* >univers::getserie() const { return serie; }

// retourne le nombre de corps qui ne sont pas des asteroides
int univers::nbcorps() const
{
	int k( 0 );
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		if( ( *i )->getgenre() != ast ) { ++k; }
	}
	return k;
}

// les iterateurs de debut et de fin de la serie de corps
set< corps* >::iterator univers::begin() const { return serie.begin(); }
set< corps* >::iterator univers::end() const { return serie.end(); }

// fonction pour la serie de corps
bool univers::empty() const { return getserie().empty(); }
void univers::insert( corps* c ) { serie.insert( c ); }
void univers::erase( corps* c ) { serie.erase( c ); }

// renvoie le temps
double univers::gettemps() const { return temps; }

// renvoie le temps ecoule
double univers::gettempsecoule() const { return tempsecoule; }

// renvoie le pas
double univers::getpas() const { return pas; }

// renvoie g
long double univers::g() const { return cg; }

// teste l'egalite
bool univers::operator==( const univers& u )
{
	return ( ( getserie() == u.getserie() ) &&
			 ( gettempsecoule() == u.gettempsecoule() ) &&
			 ( gettemps() == u.gettemps() ) &&
			 ( getpas() == u.getpas() ) );
}

// fonction d'affichage
void univers::affiche( ostream& out ) const
{
	dessinable::affiche( out );
	out << "Cet univers a pour caracteristiques globales :" << endl
		<< "  - Temps : " << setw( 4 ) << gettemps() << endl
		<< "  - Temps actuel : " << setw( 2 ) << gettempsecoule() << endl
		<< "  - Pas : " << setw( 6 ) << getpas() << endl;
	if ( serie.size() != 0 ){
		out << "et contient les " << serie.size()
			<< " corps suivants :" << endl << endl;
		int k( 0 );
		for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
			++k;
			out << " Corps " << k << " :" << endl
				<< *( *i );
		}
	}else{
		out << "Cet univers ne contient aucun corps." << endl;
	}
}

// operateur d'affichage
ostream& operator<<( ostream& out, const univers& u )
{
	u.affiche( out );
	return out;
}

// ajoute un pointeur sur un corps depuis un pointeur sur un corps
void univers::ajoutcorps( corps* c )
{
	insert( c );
}

// ajoute un pointeur sur un corps depuis un corps
void univers::ajoutcorps( corps& c )
{
	insert( &c );
}

// ajoute une liste de corps
void univers::ajoutcorps( set< corps* >s )
{
	for( set< corps* >::iterator i( s.begin() ); i != s.end(); ++i ){
		insert( *i );
	}
}

// supprime un corps de l'univers
void univers::supprimeuncorps( corps* c )
{
	erase( c );
	delete c;
}

// supprime tous les corps de l'univers
void univers::supprimelescorps()
{
	set< corps* >copie( getserie() );
	for( set< corps* >::iterator i( copie.begin() ); i != copie.end(); ++i ){
		corps* eraser( *i );
		erase( *i );
		delete eraser;
	}
}

// Renvoie les coordonnees du centre de masse de l'univers
vecteur3d univers::cdm()
{
	vecteur3d v;
	double m( 0 );
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		v += ( ( ( *i )->getm() ) * ( ( *i )->getp() ) );
		m += ( *i )->getm();
	}
	if( m == 0 ){
		return v;
	}else{
		return ( ( 1 / m ) * v );
	}
}

// dessine l'univers dans glut
void univers::dessine() const
{
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		( *i )->dessine( getqqch() );
	}
}

// get/set le booleen qui determine l'affichage des noms dans glut
bool univers::getqqch() const { return names; }
void univers::setqqch( const bool& b ) { names = b; }

//dessine le graphique en fonction du temps de la distance entre deux plantes.
void univers::stance( const double& distancetemps ) const
{
	glPushMatrix();
	glColor4d( 0.0, 0.6, 0.1, 1.0 );
	glBegin( GL_LINES );
	glVertex3d( 0.0, (gettempsecoule() - distancetemps) * 0.05, 0.0 );
	try{
		findacorps( getpaire().first );
	}
	catch( corps* first ){
		try{
			findacorps( getpaire().second );
		}
		catch( corps* second ){	
			glVertex3d( 0.0, (gettempsecoule() - distancetemps) * 0.05,
						first->stance( second ) );
		}
	}
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glColor4d( 0.0, 0.2, 0.6, 1.0 );
	glBegin( GL_LINE_STRIP );
	glVertex3d( 0.0, 100.0, 30.0 );
	glVertex3d( 0.0, 100.0, 0.0 );
	glVertex3d( 0.0, 0.0, 0.0 );
	glVertex3d( 0.0, 0.0, 30.0 );
	glEnd();
	glPopMatrix();
	
	
	try{
		findacorps( getpaire().first );
	}
	catch( corps* first ){
		if ( getqqch() ) {
			glPushMatrix();
			glColor4d( first->getc().getr(),
					   first->getc().getv(),
					   first->getc().getb(),
					   first->getc().gett() );
			glRasterPos3d( 0.0, 10.0, 60.0 );
			const char* s( first->getn().c_str() );
			while (*s) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s);
				s++; }
			glPopMatrix();
		}
	}
	try{
		findacorps( getpaire().second );
	}
	catch( corps* second ){
		if ( getqqch() ) {
			glPushMatrix();
			glColor4d( second->getc().getr(),
					   second->getc().getv(),
					   second->getc().getb(),
					   second->getc().gett() );
			glRasterPos3d( 0.0, 60.0, 60.0 );
			const char* s( second->getn().c_str() );
			while (*s) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s);
				s++; }
			glPopMatrix();
		}
	}
}

//dessine les orbites en 3D des planetes dans l univers.
void univers::orbites() const
{
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		( *i )->orbites();
	}
}

//dessine les projections des orbites dans glut sur le plan YZ
void univers::projectionX() const
{
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		( *i )->projectionX();
	}
}

//dessine les projections des orbites dans glut sur le plan XZ
void univers::projectionY() const
{
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		( *i )->projectionY();
	}
}

//dessine les projections des orbites dans glut sur le plan XY
void univers::projectionZ() const
{
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		( *i )->projectionZ();
	}
}

//dessine les projections des orbites sur les 3 plans en meme temps
void univers::projection() const
{
	projectionX();
	projectionY();
	projectionZ();
}

// mise a jour de l'univers
void univers::mise_a_jour( const double& dt ) throw( bool )
{
	vector< pair< string, string > >tocrash;
	set< string >toerase;
	int thrower( 0 );
	double delta( dt / 10.0 );
	settempsecoule( gettempsecoule() + dt );
	vecteur3d forces;
	for( set< corps* >::iterator i( begin() );
		 i != end(); ++i ){
		forces = vecteur3d( 0.0, 0.0, 0.0 );
		for( set< corps* >::iterator j( begin() ); j != end(); ++j ){
			if( *i != *j ){
				try{
					forces += ( *i )->interaction( *j, g(), true );
				}
				catch( bool& er ){
					forces += ( *i )->interaction( *j, g(), false );
					bool pasencore( true );
					for( unsigned int k( 0 ); k < tocrash.size(); ++k ){
						if( ( *i )->getn() == tocrash[ k ].first ){
							if( ( *j )->getn() == tocrash[ k ].second ){
								pasencore = false;
							}
						}else if( ( *i )->getn() == tocrash[ k ].second ){
							if( ( *j )->getn() == tocrash[ k ].first ){
								pasencore = false;
							}
						}
					}
					if( pasencore ){
						pair< string, string >crashing( ( *i )->getn(), ( *j )->getn() );
						tocrash.push_back( crashing );
					}
				}
			}
		}
		( *i )->setattraction( forces );
		try{
			( *i )->mise_a_jour( delta );
		}
		catch( bool& er ){
			toerase.insert( ( *i )->getn() );
		}
	}
	for( unsigned int i( 0 ); i < tocrash.size(); ++i ){
		try{
			findacorps( tocrash[ i ].first );
		}
		catch( corps* c1 ){
			try{
				findacorps( tocrash[ i ].second );
			}
			catch( corps* c2 ){
				try{
					crash( c1, c2 );
				}
				catch( vector< string >& vs ){
					for( unsigned int k( 0 ); k < vs.size(); ++k ){
						try{
							findacorps( vs[ k ] );
						}
						catch( corps* c ){
							toerase.insert( c->getn() );
						}
					}
				}
			}
		}
	}
	for( set< string >::iterator i( toerase.begin() ); i != toerase.end(); ++i ){
//		corps* c;
		try{
			findacorps( *i );
		}
		catch( corps* c ){
			if ( c->getgenre() == ast ) { ++thrower; }
			supprimeuncorps( c );
		}
	}
	if ( toerase.size() - thrower != 0 ) {
		throw bool(true);
	}	
}

// fonction qui gere les crash entre corps
void univers::crash( corps* c1, corps* c2 ) throw( vector< string > )
{
	vector< string >courrier;
//ce qu'on enverra avec les noms des corps a detruire
	if( c1->getgenre() == ast && c2->getgenre() != ast ){
		courrier.push_back( c1->getn() );
		throw courrier;
	}else if( c1->getgenre() != ast && c2->getgenre() == ast ){
		courrier.push_back( c2->getn() );
		throw courrier;
	}else if( c1->getgenre() == ast && c2->getgenre() == ast ){
		courrier.push_back( c1->getn() );
		courrier.push_back( c2->getn() );
		throw courrier;
	}else{
		if( c1->getgenre() == eto && c2->getgenre() != eto ){
			c1->setm( c1->getm() + c2->getm() );
			courrier.push_back( c2->getn() );
			throw courrier;
		}else if( c1->getgenre() != eto && c2->getgenre() == eto ){
			c2->setm( c1->getm() + c2->getm() );
			courrier.push_back( c1->getn() );
			throw courrier;
		}else{
			if( ( 5.0 * c1->getm() > 4.0 * c2->getm() ) &&
				( 4.0 * c1->getm() < 5.0 * c2->getm() ) ){
				string r1( createasteroides( c1, c2->getv() ) );
				string r2( createasteroides( c2, c1->getv() ) );
				courrier.push_back( r1 );
				courrier.push_back( r2 );
				throw courrier;
			}else if( 4.0 * c2->getm() > 5.0 * c1->getm() ) {
				string retour1( createasteroides( c1, c2->getv() ) );
				c2->setv( ( ( ( c1->getv() ) * ( c1->getm() ) ) + ( ( c2->getv() ) * ( c2->getm() ) ) ) / ( c2->getm() ) );
				courrier.push_back( retour1 );
				throw courrier;
			}else if( 4.0 * c1->getm() > 5.0 * c2->getm() ){
				string retour2( createasteroides( c2, c1->getv() ) );
				c1->setv( ( ( ( c1->getv() ) * ( c1->getm() ) ) + ( ( c2->getv() ) * ( c2->getm() ) ) ) / ( c1->getm() ) );
				courrier.push_back( retour2 );
				throw courrier;
			}
		}
	}
}

// fonction qui cree des asteroides lors d'un crash (un nombre aleatoire proprotionnel a la masse du corps detruit)
string univers::createasteroides( corps* c, const vecteur3d& vit2 )
{
	int alea( 0 );
	alea =  static_cast< int >( 10 * log( c->getm() ) );
	int toire( alea - ( rand()%alea ) );
	vecteur3d v0;
	double masse( c->getm() / ( alea ) );
	for( int i( 0 ); i < toire; ++i ){
		double mass( masse * ( 0.1 + ( 1.8 * ( rand() / ( 1.0 * RAND_MAX ) ) ) ) );
		vecteur3d v( rand() * pow( -1.0, rand()%2 ),
					 rand() * pow( -1.0, rand()%2 ),
					 rand() * pow( -1.0, rand()%2 ) );
		v = ( ( ( 2.0 ) * c->getrayon() +
				( ( 4.0 ) * ( rand() / ( 1.0 * RAND_MAX ) ) *
				  ( c->getrayon() ) ) ) * ( v.unitaire() ) );
		vecteur3d deltav( c->getv() + vit2 + ( v ) );
		vecteur3d pos( c->getp() + ( ( 1.0 / 5.0 ) * deltav.unitaire() ) );
		couleur4d co( c->getc() );
		string nom( "*-" + c->getn() + " #" + intostri( i + 1 ) + "-*" );
		ajoutcorps( new asteroide( nom, pos, deltav,
								   v0, mass, co ) );
		try{
			findacorps( nom );
		}
		catch( corps* cr ){
			cr->calendrierpos( c->noelpos( c->gettailleintegr() - 1 ) );
		}
	}
	return c->getn();
}

// lance un corps s'il se trouve dans la liste de l'univers
void univers::findacorps( const string& nom ) const throw( corps* )
{
	corps* c;
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		if( ( *i )->getn() == nom ){
			throw *i;
			break;
		}
	}
}

//Soccupent de la paire de corps presents dans la methode de distance.
pair< string, string > univers::getpaire() const { return lesdeuxcorps; }
void univers::setpaire( pair< string, string > pp ) { lesdeuxcorps = pp; }
void univers::setpaire( const string& oui, const string& nom )
{
	lesdeuxcorps.first = oui;
	lesdeuxcorps.second = nom;
}
void univers::setpaire( const bool& bb, const string& na )
{
	if ( bb ){
		lesdeuxcorps.first = na;
	}else{
		lesdeuxcorps.second = na;
	}
}

// convertit un entier en string
string univers::intostri( const int& i ) const
{
	ostringstream s;
	s << i;
	return s.str();
}

// convertit un nombre rationnel en string
string univers::dbltostr( const double& d ) const
{
	ostringstream s;
	s << d;
	return s.str();
}

// detruit un corps au hasard (sauf les asteroides)
void univers::destroy()
{
	int nbast( 0 );
	for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
		if( ( *i )->getgenre() == ast ) { ++nbast; }
	}
	int taille( getserie().size() - nbast );
	if( taille > 0 ){
		int r( rand()%taille );
		int k( -1 );
		for( set< corps* >::iterator i( begin() ); i != end(); ++i ){
			if( ( *i )->getgenre() != ast ){
				++k;
				if( k == r ){
					createasteroides( *i, vecteur3d() );
					corps* c( *i );
					supprimeuncorps( *i );
					break;
				}
			}
		}
	}
}

// detruit l'univers
void univers::apocalypse()
{
	int nb;
	do{
		destroy();
	}while( nbcorps() != 0 );
}
