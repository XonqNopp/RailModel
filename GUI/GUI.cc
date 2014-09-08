#include "GUI.h"

GUI* shiva;
unsigned int temps(0);

dessinable* GUI::ragnaros() { return ifrit; }

  /******************************************************************/
 /* * * * * * * Identificateurs de fenetre et de menus * * * * * * */
/******************************************************************/
int GUI::odin = 0;
int GUI::freyja = 1;
int GUI::menu = 0;
int GUI::submenu = 10;
int GUI::menu1 = 1;
int GUI::submenu12 = 12;
int GUI::menu2 = 2;
int GUI::submenu2 = 13;
int GUI::submenu3 = 14;

  /******************************************************************/
 /* * * * * * * * Methodes "get" des attributs de GUI  * * * * * * */
/******************************************************************/
int GUI::midgard() const { return odin; }
int GUI::walkyrie() const { return freyja; }
bool GUI::walkyrie_war() const { return freyja_walkyrie; }
double GUI::gettempsdistance() const { return tempsdistance; }
int GUI::getaffichage() { return visage; }
//bool GUI::get_timer_on() const { return timer_on; }
//bool GUI::get_centrage() const { return ragnaros_on; }
string GUI::get_follow() const { return follow_on; }
string GUI::get_beonit() const { return beonit_on; }

  /******************************************************************/
 /* * * * * * * Methodes "set" des attributs de GUI  * * * * * * * */
/******************************************************************/
void GUI::sept_walkyries( const bool& war ) { freyja_walkyrie = war; }
void GUI::settempsdistance( const double& t ) { tempsdistance = t; }
void GUI::expression( const int& i ) { visage = i; }
//void GUI::set_timer_on( const bool& watch ) { timer_on = watch; }
//void GUI::set_centrage( const bool& ragni ) { ragnaros_on = ragni; }
void GUI::set_follow( const string& f ) { follow_on = f; }
void GUI::set_beonit( const string& s ) { beonit_on = s; }

  /******************************************************************/
 /* * * * * * Ce qu'on a besoin s'il y a des arguments * * * * * * */
/******************************************************************/
void GUI::setni()
{
	forswitch[ "blabla" ] = ble;
	forswitch[ "--start" ] = sim;
	forswitch[ "--center" ] = cen;
	forswitch[ "--names" ] = hid;
	forswitch[ "--kill" ] = apo;
}

GUI::nee GUI::getarg( const string& s ) { return forswitch[ s ]; }

void GUI::argum( int argc, char *argv[] )
{
	if( argc > 1 ){
		int k( argc - 1 );
		string arg( argv[ k ] );// le dernier argument
		string arg1( argv[ 1 ] );// le premier argument
		if( arg1.substr( 1, 1 ) == "-"){
			if( arg.substr( 0, 2 ) == "--" ){
				k = argc;
			}
			for( int i( 1 ); i < k; ++i ){
				switch( getarg( argv[ i ] ) ){
					case hid:
						ragnaros()->setqqch( true );
						cout << " * Affichage des noms" << endl;
						break;
					case sim:
						ragnaros()->set_timer_on( true );
						cout << " * Simulation" << endl;
						break;
					case cen:
						ragnaros()->set_centrage( true );
						cout << " * Centrage sur le centre de masse" << endl;
						break;
					case apo:
						ragnaros()->apocalypse();
						break;
					default:
						cerr << "L'argument *" << argv[ i ] << "* n'est pas autorise." << endl;
						break;
				}
			}
		}else{
			if( arg1.substr( 0, 1 ) == "-" ){
				for( unsigned int i( 1 ); i < arg1.size(); ++i ){
					switch( arg1[ i ] ){
						case 'n':
							ragnaros()->setqqch( true );
							cout << "* Affichage des noms" << endl;
							break;
						case 's':
							ragnaros()->set_timer_on( true );
							cout << "* Simulation" << endl;
							break;
						case 'c':
							ragnaros()->set_centrage( true );
							cout << "* Centrage sur le centre de masse" << endl;
							break;
						case 'k':
							ragnaros()->apocalypse();
							break;
						default:
							cerr << "L'argument *" << arg1[ i ] << "* n'est pas autorise." << endl;
							break;
					}
				}
			}
		}
	}
}



  /******************************************************************/
 /* * * * Constructeur/Destructeur de l'interface graphique  * * * */
/******************************************************************/
GUI::GUI()
	:ifrit(),/* timer_on( false ), ragnaros_on( false ),*/
	freyja_walkyrie( false ), follow_on( "" ), beonit_on( "" ), visage( 1 )
{}
/******************************************************************/
GUI::GUI(int argc, char *argv[], dessinable* phoenix)
	:ifrit( phoenix ),/* timer_on( false ), ragnaros_on( false ),*/
	freyja_walkyrie( false ), follow_on( "" ), beonit_on( "" ), visage( 1 )
{
	setni();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize( 1270, 995 );
	if( *( argv[ argc - 1 ] ) != '.' && *( argv[ argc - 1 ] ) != '-' ){
		odin = glutCreateWindow( argv[ argc - 1 ] );
	}else{
		odin = glutCreateWindow( "Atomos" );
	}
	temps = glutGet( GLUT_ELAPSED_TIME );
	createOdinMenu();
	EnLight();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor( 0.15, 0.0, 0.0, 0.0 );
	argum( argc, argv );
	if ( ragnaros()->get_timer_on() ){
		glutTimerFunc( 10, chronos, 0);
	}
}
/******************************************************************/
GUI::~GUI() {};
GUI::GUI( const GUI& g )
{}
GUI& GUI::operator=( const GUI& g )
{}

  /******************************************************************/
 /* * * * * * Fonciton qui demarre l'interface graphique * * * * * */
/******************************************************************/
void GUI::demarre()
{
	glutDisplayFunc(draw_ice);
	glutKeyboardFunc(leviathan_sea);
	glutSpecialFunc(leviathan_ocean);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape_fire);
	glutMainLoop();
}

  /******************************************************************/
 /* * * * * * * * * Menu de la fenetre Principale  * * * * * * * * */
/******************************************************************/
void GUI::createOdinMenu() {

	submenu3 = glutCreateMenu( beoniting );
	glutAddMenuEntry( "Aucun...", 0 );
	int wr( 1 );
	for( set< corps* >::iterator i( ragnaros()->begin() ); i != ragnaros()->end(); ++i ) {
		if ( ( *i )->getgenre() != ast ) {
			++wr;
			glutAddMenuEntry( ( *i )->getn().c_str(), wr );
		}
	}

	submenu2 = glutCreateMenu( following );
	glutAddMenuEntry( "Aucun...", 0 );
	int j( 1 );
	for( set< corps* >::iterator i( ragnaros()->begin() ); i != ragnaros()->end(); ++i ) {
		if ( ( *i )->getgenre() != ast ) {
			++j;
			glutAddMenuEntry( ( *i )->getn().c_str(), j );
		}
	}
	
	submenu = glutCreateMenu(menuSubModifs);
		glutAddMenuEntry( "Quitter la Simulation", 0 );
		glutAddMenuEntry( "Arreter Reprendre la simulation", 1 );
		glutAddMenuEntry( "Activer Desactiver le centrage", 2 );
		glutAddMenuEntry( "Activer Desactiver les noms", 3 );
		glutAddMenuEntry( "Effacer l'affichage courant", 4 );

	menu = glutCreateMenu(menuModifs);
		glutAddSubMenu( "Simulation", submenu );
		glutAddMenuEntry( "Univers", 1 );
		glutAddMenuEntry( "Orbites Tracees", 2 );
		if( ragnaros()->nbcorps() > 1 ){
			glutAddMenuEntry( "Distance entre deux corps", 7 );
		}
		glutAddMenuEntry( "Projection sur les plans", 3 );
		glutAddMenuEntry( "Projection sur le plan des X", 4 );
		glutAddMenuEntry( "Projection sur le plan des Y", 5 );
		glutAddMenuEntry( "Projection sur le plan des Z", 6 );
		if( getaffichage() == 1 ){
			glutAddSubMenu( "Etre sur...", submenu3 );
			glutAddSubMenu( "Regarder...", submenu2 );
		}
	glutAttachMenu( GLUT_RIGHT_BUTTON );
}
/*********** Gere les changements d affichages en changeant le visage de l univers. :) ***********/
void menuModifs( int n ) {
switch (n) {
	case 1:
		shiva->expression( 1 );
		shiva->EnLight();//**************************** gl.h 281 et suivantes
		shiva->ragnaros()->set_allow_centrage( true );
		break;
	case 2:
		shiva->set_follow( "" );
		shiva->set_beonit( "" );
		shiva->clear();
		shiva->expression( 2 );
		shiva->DisLight();
		shiva->ragnaros()->set_centrage( false );
		shiva->ragnaros()->set_allow_centrage( false );
		shiva->ragnaros()->check_allow();
		break;
	case 3:
		shiva->set_follow( "" );
		shiva->set_beonit( "" );
		shiva->clear();
		shiva->expression( 3 );
		shiva->DisLight();
		shiva->ragnaros()->set_centrage( false );
		shiva->ragnaros()->set_allow_centrage( false );
		shiva->ragnaros()->check_allow();
		break;
	case 4:
		shiva->set_follow( "" );
		shiva->set_beonit( "" );
		shiva->clear();
		shiva->expression( 4 );
		shiva->DisLight();
		shiva->ragnaros()->set_centrage( false );
		shiva->ragnaros()->set_allow_centrage( false );
		shiva->ragnaros()->check_allow();
		break;
	case 5:
		shiva->set_follow( "" );
		shiva->set_beonit( "" );
		shiva->clear();
		shiva->expression( 5 );
		shiva->DisLight();
		shiva->ragnaros()->set_centrage( false );
		shiva->ragnaros()->set_allow_centrage( false );
		shiva->ragnaros()->check_allow();
		break;
	case 6:
		shiva->set_follow( "" );
		shiva->set_beonit( "" );
		shiva->clear();
		shiva->expression( 6 );
		shiva->DisLight();
		shiva->ragnaros()->set_centrage( false );
		shiva->ragnaros()->set_allow_centrage( false );
		shiva->ragnaros()->check_allow();
		break;
	/*********** ouvre la fenetre des distances ***********/
	case 7:
		if ( !shiva->walkyrie_war() && shiva->ragnaros()->nbcorps() > 1 ) {
			shiva->sept_walkyries( true );
			glutInitWindowPosition( 800, 256 );
			glutInitWindowSize( 640, 480 );
		
			shiva->freyja = glutCreateWindow( "Atomos - G-Force 199" );
			shiva->clear();
			glClearColor(0.0, 0.15, 0.15, 0.0);
			shiva->settempsdistance( shiva->ragnaros()->gettempsecoule() );
			glutIdleFunc(idle);
			glutReshapeFunc(length);
			glutDisplayFunc(distance);
			glutKeyboardFunc(leviathan_pond);
			glutSpecialFunc( leviathan_ocean );//**************************************************************************************
			shiva->createFreyjaMenu();
			
			glutSetWindow( shiva->walkyrie() );
			
			shiva->exposition();
		}
		break;
	}
}
/************************ Sous-menu du menu principal ************************/
void menuSubModifs( int n ) {
switch ( n ) {
	case 0:
		glutDestroyWindow(shiva->midgard());
		exit(0);
		break;
	case 1:
		shiva->timer();
		break;
	case 2:
		shiva->centrage();
		break;
	case 3:
		shiva->HideNames();
		break;
	case 4:
		shiva->clear();
		break;
	}
}

void following( int n )
{
	switch( n ){
		case 0:
			shiva->set_follow( "" );
			break;
		default:
			int k( 1 );
			for( set< corps* >::iterator i( shiva->ragnaros()->begin() ); i != shiva->ragnaros()->end(); ++i ){
				if( ( *i )->getgenre() != ast ){
					++k;
					if( k == n ){
						shiva->set_follow( ( *i )->getn() );
						break;
					}
				}
			}
			break;
	}
}

void GUI::follow( const string& name )
{
	try{ ragnaros()->findacorps( name ); }
	catch( corps* c ){
		ragnaros()->set_centrage( false );
		if( name != get_beonit() ){
			ragnaros()->setleviathanvis( c->getp() );
			ragnaros()->setleviathanjuju();
		}else{
			ragnaros()->setleviathanjuju( ( c->getv().unitaire() ) * ragnaros()->getleviathan().getrayon() );
			ragnaros()->setleviathanvis();
		}
	}
}

void beoniting( int n )
{
	switch( n ){
		case 0:
			shiva->set_beonit( "" );
			break;
		default:
			int k( 1 );
			for( set< corps* >::iterator i( shiva->ragnaros()->begin() ); i != shiva->ragnaros()->end(); ++i ){
				if( ( *i )->getgenre() != ast ){
					++k;
					if( k == n ){
						shiva->set_beonit( ( *i )->getn() );
						break;
					}
				}
			}
			break;
	}
}

void GUI::beonit( const string& name )
{
	try{ ragnaros()->findacorps( name ); }
	catch( corps* c ){
		ragnaros()->setleviathanpos( c->getp() );
		ragnaros()->setleviathanjuju();
	}
}

  /******************************************************************/
 /* * * * * * * *  Menu de la fenetre des distances  * * * * * * * */
/******************************************************************/
void GUI::createFreyjaMenu()
{
	submenu12 = glutCreateMenu(distanceOneTwo);
	glutAddMenuEntry( "Fermer la fenetre", 1 );
	glutAddMenuEntry( "Quitter la Simulation", 0 );
	
	menu1 = glutCreateMenu(distanceOne);
	glutAddSubMenu( "Simulation", submenu12 );
	int j(1);
	for( set< corps* >::iterator i( shiva->ragnaros()->begin() ); i != shiva->ragnaros()->end(); ++i ) {
		try{ shiva->ragnaros()->findacorps( ( *i )->getn() ); }
		catch( corps* boulette ) {
			if ( boulette->getgenre() != ast ) {
				++j;
				glutAddMenuEntry( boulette->getn().c_str(), j); //i est un iterator, pas un int... ( ? )
			}
		}
	}
	glutAttachMenu( GLUT_MIDDLE_BUTTON );

/****************

Le passage par un int pour identifier le menu aux iterateurs est assez boiteux,
mais on espere que ca va foncitonner... (Expliquer dans le journal?)

****************/

	menu2 = glutCreateMenu(distanceTwo);
	glutAddSubMenu( "Simulation", submenu12 );
	j = 1;
	for( set< corps* >::iterator i( shiva->ragnaros()->begin() ); i != shiva->ragnaros()->end(); ++i ) {
		try{ shiva->ragnaros()->findacorps( ( *i )->getn() ); }
		catch( corps* boulette ) {
			if ( boulette->getgenre() != ast ) {
				++j;
				glutAddMenuEntry( boulette->getn().c_str(), j ); //i est un iterator, pas un int... ( ? )
			}
		}
	}
	glutAttachMenu( GLUT_RIGHT_BUTTON );
}
/******************************************************************/
void distanceOneTwo( int n ) {
switch ( n ) {
	case 0:
		glutDestroyWindow( shiva->walkyrie() );
		glutDestroyWindow( shiva->midgard() );
		exit( 0 );
		break;
	case 1:
		glutDestroyWindow( shiva->walkyrie() );
		glutDestroyMenu( shiva->menu1 );
		glutDestroyMenu( shiva->menu2 );
		shiva->sept_walkyries( false );
		#ifdef __APPLE__// en attendant de trouver mieux :-P
		glutSetWindow( shiva->midgard() );
		#endif
		break;
	}
}
/******************************************************************/
void distanceOne( int n ) {
/**********
La, on essaie d esperer que la liste a le meme ordre entre la creation du menu
et la selection du prochain corps sur la liste... C est boiteux, on verra bien...
***********/
	if ( n == 0 ) {
		glutDestroyWindow(shiva->walkyrie());
		shiva->sept_walkyries( false );
	} else {
		int j(1);
		for ( set< corps* >::iterator i( shiva->ragnaros()->begin() ); i != shiva->ragnaros()->end(); ++i ) {
			try{ shiva->ragnaros()->findacorps( ( *i )->getn() ); }
			catch( corps* boulette ) {
				if ( boulette->getgenre() != ast ) {
					++j;
					if ( j == n ) { shiva->ragnaros()->setpaire( true , boulette->getn() ); }
				}
			}
		}
	}
	shiva->clear();
	shiva->exposition();
}
/******************************************************************/
void distanceTwo( int n ) {
	if ( n == 0 ) { glutDestroyWindow(shiva->walkyrie()); shiva->sept_walkyries( false ); } else {
		int j(1);
		for ( set< corps* >::iterator i( shiva->ragnaros()->begin() ); i != shiva->ragnaros()->end(); ++i ) {
			try{ shiva->ragnaros()->findacorps( ( *i )->getn() ); }
			catch( corps* boulette ) {
				if ( boulette->getgenre() != ast ) {
					++j;
					if ( j == n ) { shiva->ragnaros()->setpaire( false , boulette->getn() ); }
				}
			}
		}
	}
	shiva->clear();
	shiva->exposition();
}

  /******************************************************************/
 /* * * * * * Fonctions de dessin dans l interface GLUT. * * * * * */
/******************************************************************/
void draw_ice()
{
glLoadIdentity();
shiva->curtains();
switch (shiva->getaffichage()) {
	case 1:
		if (shiva) {
			shiva->clear();
			if( shiva->ragnaros()->empty() ){ shiva->finish(); }
			if( shiva->ragnaros() ) { shiva->ragnaros()->dessine(); }
		}
		break;
	case 2:
		if (shiva) {
			if( shiva->ragnaros()->empty() ){ shiva->finish(); }
			if (shiva->ragnaros()) { shiva->ragnaros()->orbites(); }
		}
		break;
	case 3:
		if (shiva) {
			if( shiva->ragnaros()->empty() ){ shiva->finish(); }
			if (shiva->ragnaros()) { shiva->ragnaros()->projection(); }
		}
		break;
	case 4:
		if (shiva) {
			if( shiva->ragnaros()->empty() ){ shiva->finish(); }
			if (shiva->ragnaros()) { shiva->ragnaros()->projectionX(); }
		}
		break;
	case 5:
		if (shiva) {
			if( shiva->ragnaros()->empty() ){ shiva->finish(); }
			if (shiva->ragnaros()) { shiva->ragnaros()->projectionY(); }
		}
		break;
	case 6:
		if (shiva) {
			if( shiva->ragnaros()->empty() ){ shiva->finish(); }
			if (shiva->ragnaros()) { shiva->ragnaros()->projectionZ(); }
		}
		break;
	}
	glutSwapBuffers();
	shiva->exposition();
}
/******************************************************************/
void distance()
{
	if ( ( shiva->ragnaros()->gettempsecoule() - shiva->gettempsdistance() ) * 0.05 > 100.0 )
	{
		shiva->settempsdistance( shiva->ragnaros()->gettempsecoule() );
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	}
	if (shiva) {
		glLoadIdentity();
		gluLookAt( /* a definir */ 100.0, /*shiva->gettempsdistance() + */50.0, 30.0,  0.0, /*shiva->gettempsdistance() + */50.0, 30.0,  0.0, 0.0, 1.0 );
		if (shiva->ragnaros()) { shiva->ragnaros()->stance( shiva->gettempsdistance() ); } //stance prend des arguments...?
		glutSwapBuffers();
	}
	shiva->exposition();
}

  /******************************************************************/
 /* * * * * * * * * *  Fonction de simulation  * * * * * * * * * * */
/******************************************************************/
void chronos( int id )
{
	if( shiva->ragnaros()->gettemps() == shiva->ragnaros()->gettempsecoule() ){ shiva->finish(); }
	unsigned int now( glutGet( GLUT_ELAPSED_TIME ) );
	double dt( shiva->ragnaros()->getpas() );
	temps = now;
	try {
		shiva->ragnaros()->mise_a_jour( dt );
	}
	catch( bool& b ) {
		int i( glutGetWindow() );
		glutSetWindow( shiva->midgard() );
		glutDestroyMenu( shiva->submenu2 );
		glutDestroyMenu( shiva->submenu3 );
		glutDestroyMenu( shiva->menu );
		glutDestroyMenu( shiva->submenu );
		shiva->createOdinMenu();
		if ( shiva->walkyrie_war() ) {
			glutSetWindow( shiva->walkyrie() );
			glutDestroyMenu( shiva->menu1 );
			glutDestroyMenu( shiva->menu2 );
			glutDestroyMenu( shiva->submenu12 );
			shiva->createFreyjaMenu();
		}
		glutSetWindow( i );
	}
	if ( shiva->ragnaros()->get_centrage() ){
		shiva->lobotomy();
	}
	if ( shiva->ragnaros()->get_timer_on() ){
		glutTimerFunc( 10, chronos, 0);
	}
	shiva->exposition();
}

  /******************************************************************/
 /* * * * * * * * * * * * * Fonction Idle  * * * * * * * * * * * * */
/******************************************************************/
void idle(void)
{
	shiva->exposition();
	if( shiva->ragnaros()->empty() ){ shiva->finish(); }
	glutIdleFunc(0);
}

  /******************************************************************/
 /* * * * * * Fonctions de redimentionnement de fenetre  * * * * * */
/******************************************************************/
void reshape_fire(int largeur, int hauteur)
{
	if (hauteur <= 0) { hauteur = 1; }
	double ratio(largeur);
	ratio /= hauteur;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, largeur, hauteur);
	gluPerspective(45.0, ratio, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	shiva->curtains();
}
/******************************************************************/
void length(int largeur, int hauteur)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	if (hauteur <= 0) { hauteur = 1; }
	double ratio(largeur);
	ratio /= hauteur;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, largeur, hauteur);
	gluPerspective(45.0, ratio, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( 100.0, 50.0, 30.0,  0.0, 50.0, 30.0,  0.0, 0.0, 1.0 );
}

    /******************************************************************/
   /* * * * *  -One day my son, all this will belong to you! * * * * */ 
  /* * * * *  -What, the curtains?                          * * * * */
 /* * * * *  © Monty Python, The Quest For The Holy Grail  * * * * */
/******************************************************************/
void GUI::curtains()
{
	if( get_follow() != "" ){
		follow( get_follow() );
	}
	if( get_beonit() != "" ){
		beonit( get_beonit() );
	}
	gluLookAt( ragnaros()->getleviathan().getpos().getx(),
			   ragnaros()->getleviathan().getpos().gety(),
			   ragnaros()->getleviathan().getpos().getz(),
			   ragnaros()->getleviathan().getvis().getx(),
			   ragnaros()->getleviathan().getvis().gety(),
			   ragnaros()->getleviathan().getvis().getz(),
			   ragnaros()->getleviathan().getver().getx(),
			   ragnaros()->getleviathan().getver().gety(),
			   ragnaros()->getleviathan().getver().getz() );
}

/********************** Centrage sur le cdm **********************/
void GUI::lobotomy()
{
	shiva->ragnaros()->setleviathanvis( shiva->ragnaros()->cdm() );
	shiva->ragnaros()->setleviathanjuju();
	shiva->ragnaros()->setleviathanlaser();
	shiva->ragnaros()->setleviathanver();
	shiva->ragnaros()->setleviathanex();
}
/************* Active / Desactive l ecoulement du temps *************/
void GUI::timer() {
	if ( ragnaros()->get_timer_on() ) {
		ragnaros()->set_timer_on( false );
	} else {
		glutTimerFunc( 1, chronos, 0);
		ragnaros()->set_timer_on( true );
		temps = glutGet( GLUT_ELAPSED_TIME );
	}
}
/************* Active / Desactive le centrage sur le cdm *************/
void GUI::centrage() {
	if( shiva->getaffichage() == 1 ){
		shiva->ragnaros()->check_allow();
		if ( ragnaros()->get_centrage() && ragnaros()->allow_centrage() ) {
			ragnaros()->set_centrage( false );
		} else if( !ragnaros()->get_centrage() && ragnaros()->allow_centrage() )  {
			ragnaros()->set_centrage( true );
		}
		shiva->clear();
	}
}
/************* Active / Desactive l affichage des noms *************/
void GUI::HideNames() {
	shiva->ragnaros()->setqqch( !shiva->ragnaros()->getqqch() );
}
/************* Actualise toutes les fenetres ouvertes *************/
void GUI::exposition() {
	glutPostWindowRedisplay( shiva->midgard() );
	if ( shiva->walkyrie_war() ) { glutPostWindowRedisplay( shiva->walkyrie() ); }
}
/************************ Active la lumiere ************************/
void GUI::DisLight() {
	glDisable( GL_LIGHTING );
	glDisable( GL_LIGHT0 );
	glDisable( GL_COLOR_MATERIAL );
	glutDestroyMenu( menu );
	createOdinMenu();
}
/*********************** Desactive la lumiere ***********************/
void GUI::EnLight() {// la combinaison lighting et colormaterial ne permet plus d'afficher du texte!!!
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );
	glEnable( GL_COLOR_MATERIAL );
	glutDestroyMenu( menu );
	createOdinMenu();
}
/******************** Afface l affichage courant *********************/
void GUI::clear() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

  /******************************************************************/
 /* * * * * *  Fonctions qui gerent l interface clavier  * * * * * */
/******************************************************************/
void leviathan_sea( unsigned char touche, int souris_x, int souris_y )
{
	int i( 0 );
	switch ( touche ) {
		case 't':
			shiva -> ragnaros() -> destroy();
			i = glutGetWindow();
			glutSetWindow( shiva -> midgard() );
			glutDestroyMenu( shiva -> submenu2 );
			glutDestroyMenu( shiva -> submenu3 );
			glutDestroyMenu( shiva -> menu );
			shiva->createOdinMenu();
			if ( shiva -> walkyrie_war() ) {
				glutSetWindow( shiva -> walkyrie() );
				glutDestroyMenu( shiva -> menu1 );
				glutDestroyMenu( shiva -> menu2 );
				glutDestroyMenu( shiva -> submenu12 );
				shiva -> createFreyjaMenu();
			}
			glutSetWindow( i );
			break;
		case 'z':
			if ( shiva -> walkyrie_war() ) { distanceOneTwo( 1 ); }
			shiva -> ragnaros() -> apocalypse();
			break;
			/*********** Destruction de la fenetre et fin du programme ***********/
		case 27:
		case 'q':
			if ( shiva->walkyrie_war() ) { distanceOneTwo( 1 ); }//***************************************************************************************************
			glutDestroyWindow(shiva->midgard());
			exit(0);
			break;
			/*********** Change l affichage courant ***********/
		case 'm':
			if (shiva->getaffichage() == 6) {
				menuModifs( 1 );
			} else {
				menuModifs(shiva->getaffichage() + 1);
			}
			break;
			/*********** Nettoye l affichage courant. (Efface tout) ***********/
		case 'n':
			shiva->clear();
			break;
			/*********** Demarre ou arrete la simulation en appuiant sur la touche espace ***********/
		case ' ':
			shiva->timer();
			break;
			/*********** Active / Desactive le centrage sur le centre de masse ***********/
		case 'c':
			shiva->set_follow( "" );
			shiva->centrage();
			break;
		case 'g':
			shiva->set_follow( "" );
			shiva->set_beonit( "" );
			break;
			/*********** Active / Desactive l affichage des noms ***********/
		case 'h':
			shiva->HideNames();
			break;
			
			/**** w s a d ****/
			/*********** Rotation autour de la visee ************/
		case 'w':
			shiva->ragnaros()->rotateOverUnder( 0.1 );
			shiva->ragnaros()->setleviathanvis();
			shiva->clear();
			break;
		case 's':
			shiva->ragnaros()->rotateOverUnder( -0.1 );
			shiva->ragnaros()->setleviathanvis();
			shiva->clear();
			break;
		case 'a':
			shiva->ragnaros()->rotateLeftRight( 0.1 );
			shiva->ragnaros()->setleviathanvis();
			shiva->clear();
			break;
		case 'd':
			shiva->ragnaros()->rotateLeftRight( -0.1 );
			shiva->ragnaros()->setleviathanvis();
			shiva->clear();
			break;
			
			/**** +  - ****/
			/*********** Zoom de la camera par rapport a la visee ************/
		case '+':
			if( shiva->ragnaros()->getleviathan().getrayon() > 1 ) {
				shiva->ragnaros()->straight( -1 );
				shiva->ragnaros()->setleviathanpos();
				shiva->clear();
			}
			break;
		case '-':
			shiva->ragnaros()->straight( 1 );
			shiva->ragnaros()->setleviathanpos();
			shiva->clear();
			break;
			
			/**** x  y ****/
			/*********** Rotation autour de juste ************/
		case 'x':
			shiva->ragnaros()->rotateYourself( -0.1 );
			shiva->clear();
			break;
		case 'y':
			shiva->ragnaros()->rotateYourself( 0.1 );
			shiva->clear();
			break;
			
			/**** o  p ****/
			/*********** Deplacement de la visee de la camera ************/
		case 'o':
			shiva->ragnaros()->straight( -1 );
			shiva->ragnaros()->setleviathanvis();
			shiva->clear();
			break;
		case 'p':
			shiva->ragnaros()->straight( 1 );
			shiva->ragnaros()->setleviathanvis();
			shiva->clear();
			break;
			
			/**** i k j l ****/
			/*********** Translations de la camera ***********/
		case 'i':
			shiva->ragnaros()->translatedUpDown( 1 );
			shiva->clear();
			break;
		case 'k':
			shiva->ragnaros()->translatedUpDown( -1 );
			shiva->clear();
			break;
		case 'j':
			shiva->ragnaros()->translatedLeftRight( 1 );
			shiva->clear();
			break;
		case 'l':
			shiva->ragnaros()->translatedLeftRight( -1 );
			shiva->clear();
			break;
			
			/**** 1 - 6 ****/
			/*********** Change l affichage courant ************/
		case '1':
			shiva->expression( 1 );
			shiva->EnLight();
			shiva->ragnaros()->set_allow_centrage( true );
			break;
		case '2':
			shiva->clear();
			shiva->expression( 2 );
			shiva->DisLight();
			shiva->ragnaros()->set_centrage( false );
			shiva->ragnaros()->set_allow_centrage( false );
			shiva->ragnaros()->check_allow();
			break;
		case '3':
			shiva->clear();
			shiva->expression( 3 );
			shiva->DisLight();
			shiva->ragnaros()->set_centrage( false );
			shiva->ragnaros()->set_allow_centrage( false );
			shiva->ragnaros()->check_allow();
			break;
		case '4':
			shiva->clear();
			shiva->expression( 4 );
			shiva->DisLight();
			shiva->ragnaros()->set_centrage( false );
			shiva->ragnaros()->set_allow_centrage( false );
			shiva->ragnaros()->check_allow();
			break;
		case '5':
			shiva->clear();
			shiva->expression( 5 );
			shiva->DisLight();
			shiva->ragnaros()->set_centrage( false );
			shiva->ragnaros()->set_allow_centrage( false );
			shiva->ragnaros()->check_allow();
			break;
		case '6':
			shiva->clear();
			shiva->expression( 6 );
			shiva->DisLight();
			shiva->ragnaros()->set_centrage( false );
			shiva->ragnaros()->set_allow_centrage( false );
			shiva->ragnaros()->check_allow();
			break;
			
			/****  7  ****/
			/*********** Ouvre la fenetre des distances ************/
		case '7':
			menuModifs( 7 );
			break;
		default:
			break;//*************************************************************************************************************
	}
	if ( shiva->ragnaros()->get_centrage() ){
		shiva->lobotomy();
	}
	shiva->exposition();
}
/******************************************************************/
void leviathan_ocean(int touche, int souris_x, int souris_y)
{
switch (touche) {

						/**** ^ v < > ****/
	/*********** Rotation autour de la position ************/
	case GLUT_KEY_UP:
		shiva->ragnaros()->rotateOverUnder( 0.1 );
		shiva->ragnaros()->setleviathanpos();
		shiva->clear();
		break;
	case GLUT_KEY_DOWN:
		shiva->ragnaros()->rotateOverUnder( -0.1 );
		shiva->ragnaros()->setleviathanpos();
		shiva->clear();
		break;
	case GLUT_KEY_LEFT:
		shiva->ragnaros()->rotateLeftRight( 0.1 );
		shiva->ragnaros()->setleviathanpos();
		shiva->clear();
		break;
	case GLUT_KEY_RIGHT:
		shiva->ragnaros()->rotateLeftRight( -0.1 );
		shiva->ragnaros()->setleviathanpos();
		shiva->clear();
		break;
	}
if ( shiva->ragnaros()->get_centrage() ){
		shiva->lobotomy();
	}
	shiva->exposition();
}
/******************************************************************/
void leviathan_pond( unsigned char touche, int souris_x, int souris_y )
{
switch ( touche ) {
	/*********** Ferme la fenetre des distances ************/
	case 'w':
		glutDestroyWindow( shiva->walkyrie() );
		glutDestroyMenu( shiva->menu1 );
		glutDestroyMenu( shiva->menu2 );
		shiva->sept_walkyries( false );
		break;
	case 'a':
	case 's':
	case 'd':
	case 'm':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
		break;
	default:
		leviathan_sea( touche, souris_x, souris_y );
		break;
		//*****************************************************************************************************************************************
		
		
		/*
	// *********** Ferme les fenetres et quitte le programme ************
	case 'q':
		glutDestroyWindow( shiva->walkyrie() );
		glutDestroyWindow( shiva->midgard() );
		exit( 0 );
		break;
	// *********** Nettoye l affichage courant. (Efface tout) ***********
	case 'n':
		shiva->clear();
		break;
	// *********** Demarre ou arrete la simulation en appuiant sur la touche espace ***********
	case ' ':
		shiva->timer();
		break;
	// *********** Active / Desactive l affichage des noms ***********
	case 'h':
		shiva->HideNames();
		break;*/
	}
	shiva->exposition();
}

void GUI::finish()
{
	if ( walkyrie_war() ) { distanceOneTwo( 1 ); }//***************************************************************************************************
	DisLight();
	int t( 0 ), delta( 200 );
	ragnaros()->setleviathan( vecteur3d( 0.0, 0.0, 0.0 ), vecteur3d( 10.0, 0.0, 0.0 ), vecteur3d( 0.0, 0.0, 1.0 ) );
	for( int k( 0 ); k < 4; ++k ){
		clear();
		glLoadIdentity();
		curtains();
		glutPostRedisplay();
		glutSwapBuffers();
		int x( 1 ), y( 1 );
		if( k == 0 ){ x = 2; }
		else if( k == 3 ) { y == 2; }
		t =  glutGet( GLUT_ELAPSED_TIME );
		while( glutGet( GLUT_ELAPSED_TIME ) < t + ( 2 * x * delta ) ){}
		
		/*** Affichage du texte ***/
		
		t = glutGet( GLUT_ELAPSED_TIME );
		clear();
		glLoadIdentity();
		curtains();
		glPushMatrix();
		glColor4d( 1.0, 0.1, 0.0, 1.0 );
		glRasterPos3d( ragnaros()->getleviathan().getvis().getx(),
			ragnaros()->getleviathan().getvis().gety() + 0.7,
			ragnaros()->getleviathan().getvis().getz() );
		const char* s( "GAME OVER!" );
		while (*s) {
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *s );
			s++;
		}
		glPopMatrix();
		glutPostRedisplay();
		glutSwapBuffers();
		while( glutGet( GLUT_ELAPSED_TIME ) < t + ( 3 * y * delta ) ){}
	}
	leviathan_sea( 'q', 0, 0 );
}

int GUI::strtoint( const string& s )
{
	int ext( 1 );
	istringstream anubis( s );
	anubis >> ext;
	if( anubis.fail() ){
		anubis.clear();
	}
	return ext;
}

