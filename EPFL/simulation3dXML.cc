#include "../GUI/GUI.h"
#include "../parseur/parseur.h"

//reprend shiva, definie dans GUI.cc
extern GUI* shiva;

int main( int argc, char *argv[] )
{
	parseur dorigny( argc, argv );
	try{
		shiva = new GUI( argc, argv, dorigny.extraire() );
	}
	catch( erreurs& er ){
		if( !er.getbool() ){
			cerr << endl << endl
				 << "   ***# PROGRAMME INTERROMPU #***"
				 << endl << endl
				 << " -> " << er.getmsg() << endl << endl;
			return 0;
		}
	}
	shiva->demarre();
	return 0;
}

