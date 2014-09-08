#include "corps.h"

#include "etoile.h"
#include "planete.h"
#include "satellite.h"
#include "asteroide.h"


int main()
{
	vecteur3d v0;
	vecteur3d pt( 1.4745e11, 0, 0 );
	vecteur3d vt( 0, 3.04e4, 0 );
	vecteur3d pl( 1.47832e11, 0, 3.44e7 );
	vecteur3d vl( 0, 1.023e3, 0 );
	couleur4d c;
	

	asteroide c1( "Blah", v0, v0, v0, 1e30, c );
/*	
	etoile c1( "Soleil", v0, v0, v0, 1.9891e31,
			   couleur4d( 0.7, 1.0, 0.1, 1.0 ) );
	planete c2( "Terre", pt, vt, v0, 5.973e24 ,
				couleur4d( 1.0, 0.5, 0.0, 1.0 ) ) ;
	satellite c3( "Lune", pl, vl, v0, 7.35e16,
				  couleur4d( 0.1, 0.2, 0.3, 1.0 ) );
*/
//	cout << c1 << endl;
/*	soleil.parametre_affichage();
 *	cout << soleil.getrayon() << endl << soleil.getrayoni() << endl << soleil.getrayone() << endl << endl;
 *	return 0;
 */
	
//	corps c4;
//	corps c5( c2 );
	
/*	cout << c1 << c2 << c3 << c4;
 *	if( c1 == c2 ){
 *		cout << "c1 == c2 " << flush;
 *	}else if( c2 == c5 ){
 *		cout << "c2 == c5" << flush;
 *	}
 *	cout << endl << endl;
 *
 *	cout << "Soleil : " << c1 << endl << c1.getrayon() << endl << endl
 *		 << "Terre : " << c2 << endl << c2.getrayon() << endl << endl
 *		 << "Lune : " << c3 << endl << c3.getcote() << endl << endl << endl;
 */	

	cout << c1 << endl;// << c2 << endl << c3 << endl << endl;
	
	return 0;
}
