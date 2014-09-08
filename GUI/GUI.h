#ifndef GUI_h
#define GUI_h

#include "../univers/univers.h" // pour notre projet
#include "../dessinable/dessinable.h" // de toute facon
//#include "../GLUI/glui.h"
#include <map>
#include <sstream>

// Les friend doivent etre declarees en dehors de la classe!
void menuModifs( int n );
void menuSubModifs( int n );
void following( int n );
void beoniting( int n );
void distanceOneTwo( int n );
void distanceOne( int n );
void distanceTwo( int n );
void draw_ice();
void distance();
void idle(void);
void reshape_fire(int largeur, int hauteur);
void length( int largeur, int hauteur );
void chronos(int id);
void leviathan_sea( unsigned char touche, int souris_x, int souris_y );
void leviathan_ocean( int touche, int souris_x, int souris_y );
void leviathan_pond( unsigned char touche, int souris_x, int souris_y );

// La classe GUI
class GUI
{
private:
	dessinable* ifrit;
	static int odin;
	int visage;
	//bool timer_on;
	//bool ragnaros_on;
	string follow_on;
	string beonit_on;
	static int freyja;
	bool freyja_walkyrie;
	static int menu;
	static int submenu;
	static int menu1;
	static int submenu12;
	static int menu2;
	static int submenu2;
	static int submenu3;
	double tempsdistance;
	enum nee { ble, sim, cen, hid, apo };
	map< string, nee >forswitch;
public:
	dessinable* ragnaros();
	
	int midgard() const;
	int walkyrie() const;
	bool walkyrie_war() const;
	int getaffichage();
	//bool get_timer_on() const;
	//bool get_centrage() const;
	string get_follow() const;
	string get_beonit() const;
	double gettempsdistance() const;
	
	void sept_walkyries( const bool& war );
	void settempsdistance( const double& t );
	void expression( const int& i );
	//void set_timer_on( const bool& wathc );
	//void set_centrage( const bool& ragni );
	void set_follow( const string& f );
	void set_beonit( const string& s );
	
	GUI();
	GUI(int argc, char *argv[], dessinable* phoenix);
	~GUI();
	GUI( const GUI& g );
	GUI& operator=( const GUI& g );
	
	void setni();
	nee getarg( const string& s );
	void argum( int argc, char *argv[] );
	
	void demarre();
	
	void createOdinMenu();
	friend void menuModifs( int n );
	friend void menuSubModifs( int n );
	friend void following( int n );
	void follow( const string& name );
	friend void beoniting( int n );
	void beonit( const string& name );
	
	void createFreyjaMenu();
	friend void distanceOneTwo( int n );
	friend void distanceOne( int n );
	friend void distanceTwo( int n );
	
	friend void draw_ice();
	friend void distance();
	
	friend void idle(void);
	
	friend void reshape_fire(int largeur, int hauteur);
	friend void length( int largeur, int hauteur );

	friend void chronos(int id);
	
	void curtains();
	void lobotomy();
	void timer();
	void centrage();
	void HideNames();
	void exposition();
	void DisLight();
	void EnLight();
	void clear();
	
	friend void leviathan_sea( unsigned char touche, int souris_x, int souris_y );
	friend void leviathan_ocean( int touche, int souris_x, int souris_y );
	friend void leviathan_pond( unsigned char touche, int souris_x, int souris_y );
	void finish();
	int strtoint( const string& s );
};

#endif // GUI_h
