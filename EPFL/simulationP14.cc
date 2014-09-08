#include "../univers/univers.h"

int main( int argc, char *argv[] )
{
	univers dorigny;
	double a, b, c, fac;
	a = 5.0;
	b = a / sqrt( 3.0 );
	c = 2.0 * b;

	fac = 0.00;
	vecteur3d vs( c, 0.0, 0.0 );
	vecteur3d vt( -b, c, 0.0 );
	vecteur3d vl( -b, -c, 0.0 );

	vs = fac * vs;
	vt = fac * vt;
	vl = fac * vl;

	
	dorigny.ajoutcorps( new etoile( "Soleil",
									vecteur3d( 0.0, c, 0.0 ),
									vs,
									vecteur3d( 0.0, 0.0, 0.0 ),
									1e8,
									couleur4d( 1.0, 1.0, 0.0, 1.0 ) ) );
/*	
	dorigny.ajoutcorps( new planete( "Terre",
									 vecteur3d( -a, -b, 0.0 ),
									 vt,
									 vecteur3d( 0.0, 0.0, 0.0 ),
									 1e8,
									 couleur4d( 0.0, 0.5, 1.0, 1.0 ) ) );
	
	dorigny.ajoutcorps( new satellite( "Lune",
									   vecteur3d( a, -b, 0.0 ),
									   vl,
									   vecteur3d( 0.0, 0.0, 0.0 ),
									   1e8,
									   couleur4d( 1.0, 1.0, 1.0, 1.0 ) ) );
*/
	cout << endl << endl << " -- Initialisation --" << endl << dorigny;
	for( int i( 0 ); i < 1; ++i ){
		dorigny.mise_a_jour(1.0);
		cout << "  -- Iteration " << i + 1 << " --" << endl << dorigny;
	}
	return 0;
}
