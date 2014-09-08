#include "GUI.h"

GUI* TheGUI;
unsigned int temps(0);

dessinable* GUI::GetDessinable() {return TheDessinable;}

  /******************************************************************/
 /* * * * * * * Identificateurs de fenetre et de menus * * * * * * */
/******************************************************************/
int GUI::WindowID = 0;
int GUI::GraphicWindowID = 1;
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
int GUI::GetWindowID() const {return WindowID;}
int GUI::GetGraphicWindowID() const {return GraphicWindowID;}
bool GUI::walkyrie_war() const {return freyja_walkyrie;}
double GUI::gettempsdistance() const {return tempsdistance;}
int GUI::getaffichage() {return visage;}
string GUI::get_follow() const {return follow_on;}
string GUI::get_beonit() const {return beonit_on;}

  /******************************************************************/
 /* * * * * * * Methodes "set" des attributs de GUI  * * * * * * * */
/******************************************************************/
void GUI::sept_walkyries(const bool& war) {freyja_walkyrie = war;}
void GUI::settempsdistance(const double& t) {tempsdistance = t;}
void GUI::expression(const int& i) {visage = i;}
void GUI::set_follow(const string& f) {follow_on = f;}
void GUI::set_beonit(const string& s) {beonit_on = s;}

  /******************************************************************/
 /* * * * * * Ce qu'on a besoin s'il y a des arguments * * * * * * */
/******************************************************************/
void GUI::setni()
{
	forswitch["blabla"  ] = ble;
	forswitch["--start" ] = sim;
	forswitch["--center"] = cen;
	forswitch["--names" ] = hid;
	forswitch["--kill"  ] = apo;
}

GUI::nee GUI::getarg(const string& s) {return forswitch[s];}

void GUI::argum(int argc, char *argv[])
{
	if(argc > 1){
		int k(argc - 1);
		string arg(argv[k]);// le dernier argument
		string arg1(argv[1]);// le premier argument
		if(arg1.substr(1, 1) == "-"){
			if(arg.substr(0, 2) == "--"){
				k = argc;
			}
			for(int i(1); i < k; ++i){
				switch(getarg(argv[i])){
					case hid:
						GetDessinable()->setqqch(true);
						cout << " * Affichage des noms" << endl;
						break;
					case sim:
						GetDessinable()->set_timer_on(true);
						cout << " * Simulation" << endl;
						break;
					case cen:
						GetDessinable()->set_centrage(true);
						cout << " * Centrage sur le centre de masse" << endl;
						break;
					case apo:
						GetDessinable()->apocalypse();
						break;
					default:
						cerr << "L'argument *" << argv[i] << "* n'est pas autorise." << endl;
						break;
				}
			}
		}else{
			if(arg1.substr(0, 1) == "-"){
				for(unsigned int i(1); i < arg1.size(); ++i){
					switch(arg1[i]){
						case 'n':
							GetDessinable()->setqqch(true);
							cout << "* Affichage des noms" << endl;
							break;
						case 's':
							GetDessinable()->set_timer_on(true);
							cout << "* Simulation" << endl;
							break;
						case 'c':
							GetDessinable()->set_centrage(true);
							cout << "* Centrage sur le centre de masse" << endl;
							break;
						case 'k':
							GetDessinable()->apocalypse();
							break;
						default:
							cerr << "L'argument *" << arg1[i] << "* n'est pas autorise." << endl;
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
	:TheDessinable(), freyja_walkyrie(false), follow_on(""), beonit_on(""), visage(1)
{}
/******************************************************************/
GUI::GUI(int argc, char *argv[], dessinable* phoenix)
	:TheDessinable(phoenix), freyja_walkyrie(false), follow_on(""), beonit_on(""), visage(1)
{
	setni();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1270, 995);
	if(*(argv[argc - 1]) != '.' && *(argv[argc - 1]) != '-'){
		WindowID = glutCreateWindow(argv[argc - 1]);
	}else{
		WindowID = glutCreateWindow("Atomos");
	}
	temps = glutGet(GLUT_ELAPSED_TIME);
	createWindowMenu();
	EnLight();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.15, 0.0, 0.0, 0.0);
	argum(argc, argv);
	if (GetDessinable()->get_timer_on()){
		glutTimerFunc(10, RunSimulation, 0);
	}
}
/******************************************************************/
GUI::~GUI() {};
GUI::GUI(const GUI& g)
{}
GUI& GUI::operator=(const GUI& g)
{}

  /******************************************************************/
 /* * * * * * Fonciton qui demarre l'interface graphique * * * * * */
/******************************************************************/
void GUI::Init()
{
	glutDisplayFunc(DrawInGUI);
	glutKeyboardFunc(EventKeyboard);
	glutSpecialFunc(EventKeyboardArrow);
	glutIdleFunc(idle);
	glutReshapeFunc(ResizeWindow);
	glutMainLoop();
}

  /******************************************************************/
 /* * * * * * * * * Menu de la fenetre Principale  * * * * * * * * */
/******************************************************************/
void GUI::createWindowMenu() {

	submenu3 = glutCreateMenu(beoniting);
	glutAddMenuEntry("Aucun...", 0);
	int wr(1);
	for(set< corps* >::iterator i(GetDessinable()->begin()); i != GetDessinable()->end(); ++i) {
		if ((*i)->getgenre() != ast) {
			++wr;
			glutAddMenuEntry((*i)->getn().c_str(), wr);
		}
	}

	submenu2 = glutCreateMenu(following);
	glutAddMenuEntry("Aucun...", 0);
	int j(1);
	for(set< corps* >::iterator i(GetDessinable()->begin()); i != GetDessinable()->end(); ++i) {
		if ((*i)->getgenre() != ast) {
			++j;
			glutAddMenuEntry((*i)->getn().c_str(), j);
		}
	}
	
	submenu = glutCreateMenu(menuSubModifs);
		glutAddMenuEntry("Quitter la Simulation", 0);
		glutAddMenuEntry("Arreter Reprendre la simulation", 1);
		glutAddMenuEntry("Activer Desactiver le centrage", 2);
		glutAddMenuEntry("Activer Desactiver les noms", 3);
		glutAddMenuEntry("Effacer l'affichage courant", 4);

	menu = glutCreateMenu(menuModifs);
		glutAddSubMenu("Simulation", submenu);
		glutAddMenuEntry("Univers", 1);
		glutAddMenuEntry("Orbites Tracees", 2);
		if(GetDessinable()->nbcorps() > 1){
			glutAddMenuEntry("Distance entre deux corps", 7);
		}
		glutAddMenuEntry("Projection sur les plans", 3);
		glutAddMenuEntry("Projection sur le plan des X", 4);
		glutAddMenuEntry("Projection sur le plan des Y", 5);
		glutAddMenuEntry("Projection sur le plan des Z", 6);
		if(getaffichage() == 1){
			glutAddSubMenu("Etre sur...", submenu3);
			glutAddSubMenu("Regarder...", submenu2);
		}
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
/*********** Gere les changements d affichages en changeant le visage de l univers. :) ***********/
void menuModifs(int n) {
switch (n) {
	case 1:
		TheGUI->expression(1);
		TheGUI->EnLight();//**************************** gl.h 281 et suivantes
		TheGUI->GetDessinable()->set_allow_centrage(true);
		break;
	case 2:
		TheGUI->set_follow("");
		TheGUI->set_beonit("");
		TheGUI->clear();
		TheGUI->expression(2);
		TheGUI->DisLight();
		TheGUI->GetDessinable()->set_centrage(false);
		TheGUI->GetDessinable()->set_allow_centrage(false);
		TheGUI->GetDessinable()->check_allow();
		break;
	case 3:
		TheGUI->set_follow("");
		TheGUI->set_beonit("");
		TheGUI->clear();
		TheGUI->expression(3);
		TheGUI->DisLight();
		TheGUI->GetDessinable()->set_centrage(false);
		TheGUI->GetDessinable()->set_allow_centrage(false);
		TheGUI->GetDessinable()->check_allow();
		break;
	case 4:
		TheGUI->set_follow("");
		TheGUI->set_beonit("");
		TheGUI->clear();
		TheGUI->expression(4);
		TheGUI->DisLight();
		TheGUI->GetDessinable()->set_centrage(false);
		TheGUI->GetDessinable()->set_allow_centrage(false);
		TheGUI->GetDessinable()->check_allow();
		break;
	case 5:
		TheGUI->set_follow("");
		TheGUI->set_beonit("");
		TheGUI->clear();
		TheGUI->expression(5);
		TheGUI->DisLight();
		TheGUI->GetDessinable()->set_centrage(false);
		TheGUI->GetDessinable()->set_allow_centrage(false);
		TheGUI->GetDessinable()->check_allow();
		break;
	case 6:
		TheGUI->set_follow("");
		TheGUI->set_beonit("");
		TheGUI->clear();
		TheGUI->expression(6);
		TheGUI->DisLight();
		TheGUI->GetDessinable()->set_centrage(false);
		TheGUI->GetDessinable()->set_allow_centrage(false);
		TheGUI->GetDessinable()->check_allow();
		break;
	/*********** ouvre la fenetre des distances ***********/
	case 7:
		if (!TheGUI->walkyrie_war() && TheGUI->GetDessinable()->nbcorps() > 1) {
			TheGUI->sept_walkyries(true);
			glutInitWindowPosition(800, 256);
			glutInitWindowSize(640, 480);
		
			TheGUI->GraphicWindowID = glutCreateWindow("Atomos - G-Force 199");
			TheGUI->clear();
			glClearColor(0.0, 0.15, 0.15, 0.0);
			TheGUI->settempsdistance(TheGUI->GetDessinable()->gettempsecoule());
			glutIdleFunc(idle);
			glutReshapeFunc(length);
			glutDisplayFunc(distance);
			glutKeyboardFunc(EventKeyboard_bis);
			glutSpecialFunc(EventKeyboardArrow);//**************************************************************************************
			TheGUI->createGraphicWindowIDMenu();
			
			glutSetWindow(TheGUI->GetGraphicWindowID());
			
			TheGUI->exposition();
		}
		break;
	}
}
/************************ Sous-menu du menu principal ************************/
void menuSubModifs(int n) {
switch (n) {
	case 0:
		glutDestroyWindow(TheGUI->GetWindowID());
		exit(0);
		break;
	case 1:
		TheGUI->timer();
		break;
	case 2:
		TheGUI->centrage();
		break;
	case 3:
		TheGUI->HideNames();
		break;
	case 4:
		TheGUI->clear();
		break;
	}
}

void following(int n)
{
	switch(n){
		case 0:
			TheGUI->set_follow("");
			break;
		default:
			int k(1);
			for(set< corps* >::iterator i(TheGUI->GetDessinable()->begin()); i != TheGUI->GetDessinable()->end(); ++i){
				if((*i)->getgenre() != ast){
					++k;
					if(k == n){
						TheGUI->set_follow((*i)->getn());
						break;
					}
				}
			}
			break;
	}
}

void GUI::follow(const string& name)
{
	try{GetDessinable()->findacorps(name);}
	catch(corps* c){
		GetDessinable()->set_centrage(false);
		if(name != get_beonit()){
			GetDessinable()->SetCameraRelativeAim(c->getp());
			GetDessinable()->SetCameraAbsoluteAim();
		}else{
			GetDessinable()->SetCameraAbsoluteAim((c->getv().unitaire()) * GetDessinable()->getleviathan().getrayon());
			GetDessinable()->SetCameraRelativeAim();
		}
	}
}

void beoniting(int n)
{
	switch(n){
		case 0:
			TheGUI->set_beonit("");
			break;
		default:
			int k(1);
			for(set< corps* >::iterator i(TheGUI->GetDessinable()->begin()); i != TheGUI->GetDessinable()->end(); ++i){
				if((*i)->getgenre() != ast){
					++k;
					if(k == n){
						TheGUI->set_beonit((*i)->getn());
						break;
					}
				}
			}
			break;
	}
}

void GUI::beonit(const string& name)
{
	try{GetDessinable()->findacorps(name);}
	catch(corps* c){
		GetDessinable()->SetCameraPosition(c->getp());
		GetDessinable()->SetCameraAbsoluteAim();
	}
}

  /******************************************************************/
 /* * * * * * * *  Menu de la fenetre des distances  * * * * * * * */
/******************************************************************/
void GUI::createGraphicWindowIDMenu()
{
	submenu12 = glutCreateMenu(distanceOneTwo);
	glutAddMenuEntry("Fermer la fenetre", 1);
	glutAddMenuEntry("Quitter la Simulation", 0);
	
	menu1 = glutCreateMenu(distanceOne);
	glutAddSubMenu("Simulation", submenu12);
	int j(1);
	for(set< corps* >::iterator i(TheGUI->GetDessinable()->begin()); i != TheGUI->GetDessinable()->end(); ++i) {
		try{TheGUI->GetDessinable()->findacorps((*i)->getn());}
		catch(corps* boulette) {
			if (boulette->getgenre() != ast) {
				++j;
				glutAddMenuEntry(boulette->getn().c_str(), j);//i est un iterator, pas un int... (?)
			}
		}
	}
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

/****************

Le passage par un int pour identifier le menu aux iterateurs est assez boiteux,
mais on espere que ca va foncitonner... (Expliquer dans le journal?)

****************/

	menu2 = glutCreateMenu(distanceTwo);
	glutAddSubMenu("Simulation", submenu12);
	j = 1;
	for(set< corps* >::iterator i(TheGUI->GetDessinable()->begin()); i != TheGUI->GetDessinable()->end(); ++i) {
		try{TheGUI->GetDessinable()->findacorps((*i)->getn());}
		catch(corps* boulette) {
			if (boulette->getgenre() != ast) {
				++j;
				glutAddMenuEntry(boulette->getn().c_str(), j);//i est un iterator, pas un int... (?)
			}
		}
	}
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
/******************************************************************/
void distanceOneTwo(int n) {
switch (n) {
	case 0:
		glutDestroyWindow(TheGUI->GetGraphicWindowID());
		glutDestroyWindow(TheGUI->GetWindowID());
		exit(0);
		break;
	case 1:
		glutDestroyWindow(TheGUI->GetGraphicWindowID());
		glutDestroyMenu(TheGUI->menu1);
		glutDestroyMenu(TheGUI->menu2);
		TheGUI->sept_walkyries(false);
		#ifdef __APPLE__// en attendant de trouver mieux :-P
		glutSetWindow(TheGUI->GetWindowID());
		#endif
		break;
	}
}
/******************************************************************/
void distanceOne(int n) {
/**********
La, on essaie d esperer que la liste a le meme ordre entre la creation du menu
et la selection du prochain corps sur la liste... C est boiteux, on verra bien...
***********/
	if (n == 0) {
		glutDestroyWindow(TheGUI->GetGraphicWindowID());
		TheGUI->sept_walkyries(false);
	} else {
		int j(1);
		for (set< corps* >::iterator i(TheGUI->GetDessinable()->begin()); i != TheGUI->GetDessinable()->end(); ++i) {
			try{TheGUI->GetDessinable()->findacorps((*i)->getn());}
			catch(corps* boulette) {
				if (boulette->getgenre() != ast) {
					++j;
					if (j == n) {TheGUI->GetDessinable()->setpaire(true , boulette->getn());}
				}
			}
		}
	}
	TheGUI->clear();
	TheGUI->exposition();
}
/******************************************************************/
void distanceTwo(int n) {
	if (n == 0) {
		glutDestroyWindow(TheGUI->GetGraphicWindowID());
		TheGUI->sept_walkyries(false);
	} else {
		int j(1);
		for (set< corps* >::iterator i(TheGUI->GetDessinable()->begin()); i != TheGUI->GetDessinable()->end(); ++i) {
			try{TheGUI->GetDessinable()->findacorps((*i)->getn());}
			catch(corps* boulette) {
				if (boulette->getgenre() != ast) {
					++j;
					if (j == n) {
						TheGUI->GetDessinable()->setpaire(false , boulette->getn());
					}
				}
			}
		}
	}
	TheGUI->clear();
	TheGUI->exposition();
}

  /******************************************************************/
 /* * * * * * Fonctions de dessin dans l interface GLUT. * * * * * */
/******************************************************************/
void DrawInGUI()
{
glLoadIdentity();
TheGUI->LookAt();
switch (TheGUI->getaffichage()) {
	case 1:
		if (TheGUI) {
			TheGUI->clear();
			if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
			if(TheGUI->GetDessinable()) {TheGUI->GetDessinable()->dessine();}
		}
		break;
	case 2:
		if (TheGUI) {
			if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
			if (TheGUI->GetDessinable()) {TheGUI->GetDessinable()->orbites();}
		}
		break;
	case 3:
		if (TheGUI) {
			if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
			if (TheGUI->GetDessinable()) {TheGUI->GetDessinable()->projection();}
		}
		break;
	case 4:
		if (TheGUI) {
			if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
			if (TheGUI->GetDessinable()) {TheGUI->GetDessinable()->projectionX();}
		}
		break;
	case 5:
		if (TheGUI) {
			if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
			if (TheGUI->GetDessinable()) {TheGUI->GetDessinable()->projectionY();}
		}
		break;
	case 6:
		if (TheGUI) {
			if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
			if (TheGUI->GetDessinable()) {TheGUI->GetDessinable()->projectionZ();}
		}
		break;
	}
	glutSwapBuffers();
	TheGUI->exposition();
}
/******************************************************************/
void distance()
{
	if ((TheGUI->GetDessinable()->gettempsecoule() - TheGUI->gettempsdistance()) * 0.05 > 100.0)
	{
		TheGUI->settempsdistance(TheGUI->GetDessinable()->gettempsecoule());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	if (TheGUI) {
		glLoadIdentity();
		gluLookAt(/* a definir */ 100.0, /*TheGUI->gettempsdistance() + */50.0, 30.0,  0.0, /*TheGUI->gettempsdistance() + */50.0, 30.0,  0.0, 0.0, 1.0);
		if (TheGUI->GetDessinable()) {TheGUI->GetDessinable()->stance(TheGUI->gettempsdistance());} //stance prend des arguments...?
		glutSwapBuffers();
	}
	TheGUI->exposition();
}

  /******************************************************************/
 /* * * * * * * * * *  Fonction de simulation  * * * * * * * * * * */
/******************************************************************/
void RunSimulation(int id)
{
	if(TheGUI->GetDessinable()->gettemps() == TheGUI->GetDessinable()->gettempsecoule()){TheGUI->finish();}
	unsigned int now(glutGet(GLUT_ELAPSED_TIME));
	double dt(TheGUI->GetDessinable()->getpas());
	temps = now;
	try {
		TheGUI->GetDessinable()->mise_a_jour(dt);
	}
	catch(bool& b) {
		int i(glutGetWindow());
		glutSetWindow(TheGUI->GetWindowID());
		glutDestroyMenu(TheGUI->submenu2);
		glutDestroyMenu(TheGUI->submenu3);
		glutDestroyMenu(TheGUI->menu);
		glutDestroyMenu(TheGUI->submenu);
		TheGUI->createWindowMenu();
		if (TheGUI->walkyrie_war()) {
			glutSetWindow(TheGUI->GetGraphicWindowID());
			glutDestroyMenu(TheGUI->menu1);
			glutDestroyMenu(TheGUI->menu2);
			glutDestroyMenu(TheGUI->submenu12);
			TheGUI->createGraphicWindowIDMenu();
		}
		glutSetWindow(i);
	}
	if (TheGUI->GetDessinable()->get_centrage()){
		TheGUI->AimAtMassCenter();
	}
	if (TheGUI->GetDessinable()->get_timer_on()){
		glutTimerFunc(10, RunSimulation, 0);
	}
	TheGUI->exposition();
}

  /******************************************************************/
 /* * * * * * * * * * * * * Fonction Idle  * * * * * * * * * * * * */
/******************************************************************/
void idle(void)
{
	TheGUI->exposition();
	if(TheGUI->GetDessinable()->empty()){TheGUI->finish();}
	glutIdleFunc(0);
}

  /******************************************************************/
 /* * * * * * Fonctions de redimentionnement de fenetre  * * * * * */
/******************************************************************/
void ResizeWindow(int largeur, int hauteur)
{
	if (hauteur <= 0) {hauteur = 1;}
	double ratio(largeur);
	ratio /= hauteur;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, largeur, hauteur);
	gluPerspective(45.0, ratio, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	TheGUI->LookAt();
}
/******************************************************************/
void length(int largeur, int hauteur)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (hauteur <= 0) {hauteur = 1;}
	double ratio(largeur);
	ratio /= hauteur;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, largeur, hauteur);
	gluPerspective(45.0, ratio, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(100.0, 50.0, 30.0,  0.0, 50.0, 30.0,  0.0, 0.0, 1.0);
}

    /******************************************************************/
   /* * * * *  -One day my son, all this will belong to you! * * * * */ 
  /* * * * *  -What, the curtains?                          * * * * */
 /* * * * *  © Monty Python, The Quest For The Holy Grail  * * * * */
/******************************************************************/
void GUI::LookAt()
{
	if(get_follow() != ""){
		follow(get_follow());
	}
	if(get_beonit() != ""){
		beonit(get_beonit());
	}
	gluLookAt(GetDessinable()->getleviathan().getpos().getx(),
			   GetDessinable()->getleviathan().getpos().gety(),
			   GetDessinable()->getleviathan().getpos().getz(),
			   GetDessinable()->getleviathan().getvis().getx(),
			   GetDessinable()->getleviathan().getvis().gety(),
			   GetDessinable()->getleviathan().getvis().getz(),
			   GetDessinable()->getleviathan().getver().getx(),
			   GetDessinable()->getleviathan().getver().gety(),
			   GetDessinable()->getleviathan().getver().getz());
}

/********************** Centrage sur le cdm **********************/
void GUI::AimAtMassCenter()
{
	TheGUI->GetDessinable()->SetCameraRelativeAim(TheGUI->GetDessinable()->cdm());
	TheGUI->GetDessinable()->SetCameraAbsoluteAim();
	TheGUI->GetDessinable()->SetCameraRadius();
	TheGUI->GetDessinable()->SetCameraVerticale();
	TheGUI->GetDessinable()->SetCameraEx();
}
/************* Active / Desactive l ecoulement du temps *************/
void GUI::timer() {
	if (GetDessinable()->get_timer_on()) {
		GetDessinable()->set_timer_on(false);
	} else {
		glutTimerFunc(1, RunSimulation, 0);
		GetDessinable()->set_timer_on(true);
		temps = glutGet(GLUT_ELAPSED_TIME);
	}
}
/************* Active / Desactive le centrage sur le cdm *************/
void GUI::centrage() {
	if(TheGUI->getaffichage() == 1){
		TheGUI->GetDessinable()->check_allow();
		if (GetDessinable()->get_centrage() && GetDessinable()->allow_centrage()) {
			GetDessinable()->set_centrage(false);
		} else if(!GetDessinable()->get_centrage() && GetDessinable()->allow_centrage())  {
			GetDessinable()->set_centrage(true);
		}
		TheGUI->clear();
	}
}
/************* Active / Desactive l affichage des noms *************/
void GUI::HideNames() {
	TheGUI->GetDessinable()->setqqch(!TheGUI->GetDessinable()->getqqch());
}
/************* Actualise toutes les fenetres ouvertes *************/
void GUI::exposition() {
	glutPostWindowRedisplay(TheGUI->GetWindowID());
	if (TheGUI->walkyrie_war()) {glutPostWindowRedisplay(TheGUI->GetGraphicWindowID());}
}
/************************ Active la lumiere ************************/
void GUI::DisLight() {
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_COLOR_MATERIAL);
	glutDestroyMenu(menu);
	createWindowMenu();
}
/*********************** Desactive la lumiere ***********************/
void GUI::EnLight() {// la combinaison lighting et colormaterial ne permet plus d'afficher du texte!!!
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_COLOR_MATERIAL);
	//glutDestroyMenu(menu);
	//createWindowMenu();
}
/******************** Afface l affichage courant *********************/
void GUI::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

  /******************************************************************/
 /* * * * * *  Fonctions qui gerent l interface clavier  * * * * * */
/******************************************************************/
void EventKeyboard(unsigned char touche, int souris_x, int souris_y)
{
	int i(0);
	switch (touche) {
		case 't':
			TheGUI -> GetDessinable() -> destroy();
			i = glutGetWindow();
			glutSetWindow(TheGUI -> GetWindowID());
			glutDestroyMenu(TheGUI -> submenu2);
			glutDestroyMenu(TheGUI -> submenu3);
			glutDestroyMenu(TheGUI -> menu);
			TheGUI->createWindowMenu();
			if (TheGUI -> walkyrie_war()) {
				glutSetWindow(TheGUI -> GetGraphicWindowID());
				glutDestroyMenu(TheGUI -> menu1);
				glutDestroyMenu(TheGUI -> menu2);
				glutDestroyMenu(TheGUI -> submenu12);
				TheGUI -> createGraphicWindowIDMenu();
			}
			glutSetWindow(i);
			break;
		case 'z':
			if (TheGUI -> walkyrie_war()) {distanceOneTwo(1);}
			TheGUI -> GetDessinable() -> apocalypse();
			break;
			/*********** Destruction de la fenetre et fin du programme ***********/
		case 27:
		case 'q':
			if (TheGUI->walkyrie_war()) {distanceOneTwo(1);}//**************************
			glutDestroyWindow(TheGUI->GetWindowID());
			exit(0);
			break;
			/*********** Change l affichage courant ***********/
		case 'm':
			if (TheGUI->getaffichage() == 6) {
				menuModifs(1);
			} else {
				menuModifs(TheGUI->getaffichage() + 1);
			}
			break;
			/*********** Nettoye l affichage courant. (Efface tout) ***********/
		case 'n':
			TheGUI->clear();
			break;
			/*********** Demarre ou arrete la simulation en appuiant sur la touche espace ***********/
		case ' ':
			TheGUI->timer();
			break;
			/*********** Active / Desactive le centrage sur le centre de masse ***********/
		case 'c':
			TheGUI->set_follow("");
			TheGUI->centrage();
			break;
		case 'g':
			TheGUI->set_follow("");
			TheGUI->set_beonit("");
			break;
			/*********** Active / Desactive l affichage des noms ***********/
		case 'h':
			TheGUI->HideNames();
			break;
			
			/**** w s a d ****/
			/*********** Rotation autour de la visee ************/
		case 'w':
			TheGUI->GetDessinable()->rotateOverUnder(0.1);
			TheGUI->GetDessinable()->SetCameraRelativeAim();
			TheGUI->clear();
			break;
		case 's':
			TheGUI->GetDessinable()->rotateOverUnder(-0.1);
			TheGUI->GetDessinable()->SetCameraRelativeAim();
			TheGUI->clear();
			break;
		case 'a':
			TheGUI->GetDessinable()->rotateLeftRight(0.1);
			TheGUI->GetDessinable()->SetCameraRelativeAim();
			TheGUI->clear();
			break;
		case 'd':
			TheGUI->GetDessinable()->rotateLeftRight(-0.1);
			TheGUI->GetDessinable()->SetCameraRelativeAim();
			TheGUI->clear();
			break;
			
			/**** +  - ****/
			/*********** Zoom de la camera par rapport a la visee ************/
		case '+':
			if(TheGUI->GetDessinable()->getleviathan().getrayon() > 1) {
				TheGUI->GetDessinable()->straight(-1);
				TheGUI->GetDessinable()->SetCameraPosition();
				TheGUI->clear();
			}
			break;
		case '-':
			TheGUI->GetDessinable()->straight(1);
			TheGUI->GetDessinable()->SetCameraPosition();
			TheGUI->clear();
			break;
			
			/**** x  y ****/
			/*********** Rotation autour de juste ************/
		case 'x':
			TheGUI->GetDessinable()->rotateYourself(-0.1);
			TheGUI->clear();
			break;
		case 'y':
			TheGUI->GetDessinable()->rotateYourself(0.1);
			TheGUI->clear();
			break;
			
			/**** o  p ****/
			/*********** Deplacement de la visee de la camera ************/
		case 'o':
			TheGUI->GetDessinable()->straight(-1);
			TheGUI->GetDessinable()->SetCameraRelativeAim();
			TheGUI->clear();
			break;
		case 'p':
			TheGUI->GetDessinable()->straight(1);
			TheGUI->GetDessinable()->SetCameraRelativeAim();
			TheGUI->clear();
			break;
			
			/**** i k j l ****/
			/*********** Translations de la camera ***********/
		case 'i':
			TheGUI->GetDessinable()->translatedUpDown(1);
			TheGUI->clear();
			break;
		case 'k':
			TheGUI->GetDessinable()->translatedUpDown(-1);
			TheGUI->clear();
			break;
		case 'j':
			TheGUI->GetDessinable()->translatedLeftRight(1);
			TheGUI->clear();
			break;
		case 'l':
			TheGUI->GetDessinable()->translatedLeftRight(-1);
			TheGUI->clear();
			break;
			
			/**** 1 - 6 ****/
			/*********** Change l affichage courant ************/
		case '1':
			TheGUI->expression(1);
			TheGUI->EnLight();
			TheGUI->GetDessinable()->set_allow_centrage(true);
			break;
		case '2':
			TheGUI->clear();
			TheGUI->expression(2);
			TheGUI->DisLight();
			TheGUI->GetDessinable()->set_centrage(false);
			TheGUI->GetDessinable()->set_allow_centrage(false);
			TheGUI->GetDessinable()->check_allow();
			break;
		case '3':
			TheGUI->clear();
			TheGUI->expression(3);
			TheGUI->DisLight();
			TheGUI->GetDessinable()->set_centrage(false);
			TheGUI->GetDessinable()->set_allow_centrage(false);
			TheGUI->GetDessinable()->check_allow();
			break;
		case '4':
			TheGUI->clear();
			TheGUI->expression(4);
			TheGUI->DisLight();
			TheGUI->GetDessinable()->set_centrage(false);
			TheGUI->GetDessinable()->set_allow_centrage(false);
			TheGUI->GetDessinable()->check_allow();
			break;
		case '5':
			TheGUI->clear();
			TheGUI->expression(5);
			TheGUI->DisLight();
			TheGUI->GetDessinable()->set_centrage(false);
			TheGUI->GetDessinable()->set_allow_centrage(false);
			TheGUI->GetDessinable()->check_allow();
			break;
		case '6':
			TheGUI->clear();
			TheGUI->expression(6);
			TheGUI->DisLight();
			TheGUI->GetDessinable()->set_centrage(false);
			TheGUI->GetDessinable()->set_allow_centrage(false);
			TheGUI->GetDessinable()->check_allow();
			break;
			
			/****  7  ****/
			/*********** Ouvre la fenetre des distances ************/
		case '7':
			menuModifs(7);
			break;
		default:
			break;//*************************************************************************************************************
	}
	if (TheGUI->GetDessinable()->get_centrage()){
		TheGUI->AimAtMassCenter();
	}
	TheGUI->exposition();
}
/******************************************************************/
void EventKeyboardArrow(int touche, int souris_x, int souris_y)
{
switch (touche) {

						/**** ^ v < > ****/
	/*********** Rotation autour de la position ************/
	case GLUT_KEY_UP:
		TheGUI->GetDessinable()->rotateOverUnder(0.1);
		TheGUI->GetDessinable()->SetCameraPosition();
		TheGUI->clear();
		break;
	case GLUT_KEY_DOWN:
		TheGUI->GetDessinable()->rotateOverUnder(-0.1);
		TheGUI->GetDessinable()->SetCameraPosition();
		TheGUI->clear();
		break;
	case GLUT_KEY_LEFT:
		TheGUI->GetDessinable()->rotateLeftRight(0.1);
		TheGUI->GetDessinable()->SetCameraPosition();
		TheGUI->clear();
		break;
	case GLUT_KEY_RIGHT:
		TheGUI->GetDessinable()->rotateLeftRight(-0.1);
		TheGUI->GetDessinable()->SetCameraPosition();
		TheGUI->clear();
		break;
	}
if (TheGUI->GetDessinable()->get_centrage()){
		TheGUI->AimAtMassCenter();
	}
	TheGUI->exposition();
}
/******************************************************************/
void EventKeyboard_bis(unsigned char touche, int souris_x, int souris_y)
{
switch (touche) {
	/*********** Ferme la fenetre des distances ************/
	case 'w':
		glutDestroyWindow(TheGUI->GetGraphicWindowID());
		glutDestroyMenu(TheGUI->menu1);
		glutDestroyMenu(TheGUI->menu2);
		TheGUI->sept_walkyries(false);
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
		EventKeyboard(touche, souris_x, souris_y);
		break;
		//*****************************************************************************************************************************************
		
		
		/*
	// *********** Ferme les fenetres et quitte le programme ************
	case 'q':
		glutDestroyWindow(TheGUI->GetGraphicWindowID());
		glutDestroyWindow(TheGUI->GetWindowID());
		exit(0);
		break;
	// *********** Nettoye l affichage courant. (Efface tout) ***********
	case 'n':
		TheGUI->clear();
		break;
	// *********** Demarre ou arrete la simulation en appuiant sur la touche espace ***********
	case ' ':
		TheGUI->timer();
		break;
	// *********** Active / Desactive l affichage des noms ***********
	case 'h':
		TheGUI->HideNames();
		break;*/
	}
	TheGUI->exposition();
}

void GUI::finish()
{
	if (walkyrie_war()) {distanceOneTwo(1);}//******************************************
	DisLight();
	int t(0), delta(200);
	GetDessinable()->SetCamera(vecteur3d(0.0, 0.0, 0.0), vecteur3d(10.0, 0.0, 0.0), vecteur3d(0.0, 0.0, 1.0));
	for(int k(0); k < 4; ++k){
		clear();
		glLoadIdentity();
		LookAt();
		glutPostRedisplay();
		glutSwapBuffers();
		int x(1), y(1);
		if(k == 0){x = 2;}
		else if(k == 3) {y == 2;}
		t =  glutGet(GLUT_ELAPSED_TIME);
		while(glutGet(GLUT_ELAPSED_TIME) < t + (2 * x * delta)){}
		
		/*** Affichage du texte ***/
		
		t = glutGet(GLUT_ELAPSED_TIME);
		clear();
		glLoadIdentity();
		LookAt();
		glPushMatrix();
		glColor4d(1.0, 0.1, 0.0, 1.0);
		glRasterPos3d(GetDessinable()->getleviathan().getvis().getx(),
			GetDessinable()->getleviathan().getvis().gety() + 0.7,
			GetDessinable()->getleviathan().getvis().getz());
		const char* s("GAME OVER!");
		while (*s) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *s);
			s++;
		}
		glPopMatrix();
		glutPostRedisplay();
		glutSwapBuffers();
		while(glutGet(GLUT_ELAPSED_TIME) < t + (3 * y * delta)){}
	}
	EventKeyboard('q', 0, 0);
}

int GUI::strtoint(const string& s)
{
	int ext(1);
	istringstream anubis(s);
	anubis >> ext;
	if(anubis.fail()){
		anubis.clear();
	}
	return ext;
}

