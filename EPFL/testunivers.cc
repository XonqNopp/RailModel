#include "univers.h"

int main()
{
	set< corps* >s;
	couleur4d c0( 1.0, 1.0, 1.0, 1.0 );
	
	double a, b, c;
	a = 5.0;
	b = a / sqrt( 3.0 );
	c = 2.0 * b;
	
	vecteur3d v0;
	vecteur3d v1( 0.0, c, 0.0 );
	vecteur3d v2( -a, -b, 0.0 );
	vecteur3d v3( a, -b, 0.0 );
	
    s.insert( new etoile( "Soleil", v1, v0, v0, 1e10, c0 ) );
	s.insert( new planete( "Terre", v2, v0, v0, 1e10, c0 ) );
	s.insert( new satellite( "Lune", v3, v0, v0, 1e10, c0 ) );
/*
	etoile* c1( &soleil );
	planete* c2( &terre );
	satellite* c3( &lune );

	s.insert( c1 );
	s.insert( c2 );
	s.insert( c3 );
*/
	univers u( s, 365, 0, 1 );
/*	
	cout << u.cdm() << endl;
	u.mise_a_jour();
	cout << u.cdm() << endl;
*/	
//	while( lune.getp().getx() < 5 ){


	cout << u << endl;
	u.mise_a_jour( 1.0 );
	cout << u << endl;
	
	

//		u.mise_a_jour();
//	}
	
//	cout << u << endl;
	



	
/*	univers u2( s, 300, 10 );
	s.push_back( c3 );
	univers u4( s, 100, 1 );
	cout << u2 << endl;
	cout << u4 << endl;
	u4.supprimecorps();
	cout << u4 << endl;
	
	cout << u4.cdm();

	u4 = u2;
	cout << u4 << endl;
*/	
	
	return 0;
}
