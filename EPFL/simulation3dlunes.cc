#include "../GUI/GUI.h"

// programme de test pour voir si ce sont les satellites qui ne peuvent pas etre affiches ou si l'erreur se trouve ailleurs...

//reprend shiva, definie dans GUI.cc
extern GUI* shiva;

int main( int argc, char *argv[] )
{
	univers dorigny;
	dorigny.ajoutcorps( new etoile( "Soleil",
									vecteur3d( 0.0, 0.0, 0.0 ),
									vecteur3d( 0.0, 0.0, 0.0 ),
									vecteur3d( 0.0, 0.0, 0.0 ),
									1e9,
									couleur4d( 1.0, 1.0, 0.0, 1.0 ) ) );
	
	dorigny.ajoutcorps( new planete( "Terre",
									 vecteur3d( 5.0, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.1, 0.05 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 1e6,
									 couleur4d( 0.0, 0.5, 1.0, 1.0 ) ) );
	
	dorigny.ajoutcorps( new satellite( "Lune",
									   vecteur3d( 5.0, 0.0, 0.2 ),
									   vecteur3d( 0.05, 0.1, 0.0 ),
									   vecteur3d( 0.0, 0.0, 0.0 ),
									   1e3,
									   couleur4d( 1.0, 1.0, 1.0, 1.0 ) ) );
	dorigny.ajoutcorps( new satellite( "Lune2",
									   vecteur3d( 5.0, 5.0, 0.2 ),
									   vecteur3d( -0.05, 0.0, -0.05 ),
									   vecteur3d( 0.0, 0.0, 0.0 ),
									   1e3,
									   couleur4d( 0.0, 1.0, 0.0, 1.0 ) ) );
	dorigny.ajoutcorps( new satellite( "Lune3",
									   vecteur3d( 0.0, -2.0, 5.2 ),
									   vecteur3d( -0.05, 0.1, -0.1 ),
									   vecteur3d( 0.0, 0.0, 0.0 ),
									   5e2,
									   couleur4d( 1.0, 0.0, 0.0, 1.0 ) ) );
	shiva = new GUI( argc, argv, &dorigny );
	shiva->demarre();
	return 0;
}
