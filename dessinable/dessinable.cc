#include "dessinable.h"

// le constructeur par defaut (pas de constructeur de copie)
dessinable::dessinable()
	:leviathan( camera() ), timer_on( false ), ragnaros_on( false ), allow( true )
{}

// le constructeur par valeurs
dessinable::dessinable( const camera& c )
	:leviathan( c ), timer_on( false ), ragnaros_on( false ), allow( true )
{}

// le destructeur
dessinable::~dessinable()
{}

bool dessinable::get_timer_on() const { return timer_on; }
bool dessinable::get_centrage() const { return ragnaros_on; }
void dessinable::set_timer_on( const bool& watch ) { timer_on = watch; }
void dessinable::set_centrage( const bool& ragni ) { ragnaros_on = ragni; }
bool dessinable::allow_centrage() const { return allow; }
void dessinable::set_allow_centrage( const bool& forbid ) { allow = forbid; }
void dessinable::check_allow() {
	if( allow_centrage() == false ) {
		set_centrage( false );
	}
}

// la fonction d'affichage
void dessinable::affiche( ostream& out ) const
{
	out << "# La camera : " << endl << getleviathan() << endl;
}

// l'operateur d'affichage
ostream& operator<<( ostream& out, dessinable* d )
{
	d->affiche( out );
	return out;
}

// attribue les valeurs de v1, v2, v3 a la camera
void dessinable::setleviathan( const vecteur3d& v1,
							   const vecteur3d& v2,
							   const vecteur3d& v3 )
{
	leviathan.setpos( v1 );
	leviathan.setvis( v2 );
	leviathan.setver( v3 );
}

// retourne la camera
camera dessinable::getleviathan() const { return leviathan; }


  /*******************************************************************************/
 /******* * * les fonctions specifiques aux mouvements de la camera * * *********/
/*******************************************************************************/
void dessinable::setleviathanpos() { leviathan.setpos(); }
void dessinable::setleviathanpos( const vecteur3d& v ) { leviathan.setpos( v ); }
void dessinable::setleviathanvis() { leviathan.setvis(); }
void dessinable::setleviathanvis( const vecteur3d& v ) { leviathan.setvis( v ); }
void dessinable::setleviathanjuju() { leviathan.juju(); }
void dessinable::setleviathanjuju( const vecteur3d& v ) { leviathan.juju( v ); }
void dessinable::setleviathanver() { leviathan.setver(); }
void dessinable::setleviathanex() { leviathan.setex(); }
void dessinable::setleviathanlaser() { leviathan.laser(); }
void dessinable::rotateLeftRight( const long double& w ) { leviathan.rotateLeftRight( w ); }
void dessinable::rotateOverUnder( const long double& w ) { leviathan.rotateOverUnder( w ); }
void dessinable::rotateYourself( const long double& w ) { leviathan.rotateYourself( w ); }
void dessinable::straight( const double& x ) { leviathan.straight( x ); }
void dessinable::translatedLeftRight( const double& x ) { leviathan.translatedLeftRight( x ); }
void dessinable::translatedUpDown( const double& x ) { leviathan.translatedUpDown( x ); }
/********************************************************************************/
