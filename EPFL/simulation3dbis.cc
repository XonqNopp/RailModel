#include "../GUI/GUI.h"

//reprend shiva, definie dans GUI.cc
extern GUI* shiva;

int main( int argc, char *argv[] )
{
	univers dorigny;
	dorigny.ajoutcorps( new asteroide( "as",
									   vecteur3d(),
									   vecteur3d(),
									   vecteur3d(),
									   1e10,
									   couleur4d(),
									   1,
									   10 ) );
	dorigny.ajoutcorps( new asteroide( "dg",
									   vecteur3d( 2.0, 0.0, 0.0 ),
									   vecteur3d(),
									   vecteur3d(),
									   1e8,
									   couleur4d(),
									   2, 25 ) );
	

/*
	dorigny.ajoutcorps( new etoile( "Soleil",
									vecteur3d( 0.0, 0.0, 0.0 ),
									vecteur3d( 0.0, 0.0, 0.0 ),
									vecteur3d( 0.0, 0.0, 0.0 ),
									1e10,
									couleur4d( 1.0, 1.0, 0.0, 1.0 ) ) );

	dorigny.ajoutcorps( new planete( "Terre",
									 vecteur3d( 2.0, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.5, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 2e6,
									 couleur4d( 0.0, 0.5, 1.0, 1.0 ) ) );
	
	dorigny.ajoutcorps( new satellite( "Lune",
									   vecteur3d( 2.2, 0.0, 0.0 ),
									   vecteur3d( 0.2, 0.5, 0.0 ),
									   vecteur3d( 0.0, 0.0, 0.0 ),
									   1e4,
									   couleur4d( 1.0, 1.0, 1.0, 1.0 ) ) );

	dorigny.ajoutcorps( new planete( "Mercure",
									 vecteur3d( 0.0, 1.5, 0.0 ),
									 vecteur3d( 0.7, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 8e4,
									 couleur4d( 0.7, 0.7, 0.7, 1.0 ) ) );

	dorigny.ajoutcorps( new planete( "Venus",
									 vecteur3d( 0.0, -1.5, 0.0 ),
									 vecteur3d( 0.7, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 1e5,
									 couleur4d( 1.0, 1.0, 1.0, 1.0 ) ) );

	dorigny.ajoutcorps( new planete( "Mars",
									 vecteur3d( -3.0, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.5, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 1e6,
									 couleur4d( 1.0, 0.0, 0.0, 1.0 ) ) );

	dorigny.ajoutcorps( new planete( "Jupiter",
									 vecteur3d( 4.0 * sqrt( 2.0 ),
												4.0 * sqrt( 2.0 ),
												0.0 ),
									 vecteur3d( 0.2, 0.1, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 2e8,
									 couleur4d( 0.7, 0.5, 0.3, 1.0 ) ) );

	dorigny.ajoutcorps( new planete( "Saturne sans ses anneaux",
									 vecteur3d( 0.0, 9.0, 0.0 ),
									 vecteur3d( 0.2, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 1e8,
									 couleur4d( 0.8, 0.6, 0.4, 1.0 ) ) );
	*/
	shiva = new GUI( argc, argv, &dorigny );
	shiva->demarre();
	
	return 0;
}

