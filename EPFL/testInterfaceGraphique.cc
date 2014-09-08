#include "../GUI/GUI.h"
//#include "../camera/camera.h"

using namespace std;

//void clavier (unsigned char touche, int souris_x, int souris_y);

//reprend shiva, dfinie dans GUI.cc
extern GUI* shiva;

univers dorigny;


int main( int argc, char *argv[] )
{
	dorigny.ajoutcorps( new etoile( "Soleil",
									vecteur3d( 0.0, 0.0, 0.0 ),
									vecteur3d( 0.0, 0.0, 0.0 ),
									vecteur3d( 0.0, 0.0, 0.0 ),
									1e11,
									couleur4d( 1.0, 1.0, 0.0, 1.0 ) ) );
	
	dorigny.ajoutcorps( new planete( "Terre",
									 vecteur3d( 0.0, 5.0, 0.0 ),
									 vecteur3d( 1.0, 0.0, 0.0 ),
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 3e9,
									 couleur4d( 0.0, 0.5, 1.0, 1.0 ) ) );
	
	dorigny.ajoutcorps( new satellite( "Lune",
									   vecteur3d( 0.0, 5.3, 0.0 ),
									   vecteur3d( 1.0, 0.3, 0.0 ),
									   vecteur3d( 0.0, 0.0, 0.0 ),
									   1e4,
									   couleur4d( 1.0, 1.0, 1.0, 1.0 ) ) );
	
	
	shiva = new GUI( argc, argv, &dorigny );
	shiva->demarre();
	
	return 0;
}
