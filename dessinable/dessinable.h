#ifndef dessinable_h
#define dessinable_h

#include "../vecteur3d/vecteur3d.h"
#include "../revisitedcamera/camera.h"
#include "../corps/corps.h"

#include <set>
#include <utility>

class dessinable
{
protected:
	camera leviathan;
	bool timer_on;
	bool allow;
	bool ragnaros_on;
public:
	dessinable();
	dessinable( const camera& c );
	virtual ~dessinable();

	/*** les methodes pour le centrage et la simulation ***/
	bool get_timer_on() const;
	bool get_centrage() const;
	void set_timer_on( const bool& watch );
	void set_centrage( const bool& ragni );
	bool allow_centrage() const;
	void set_allow_centrage( const bool& forbid );
	void check_allow();
	
	/*** les methodes d'univers que nous avons besoin dans le parseur ***/
	virtual long double g() const = 0;
	virtual void dessine() const = 0;
	virtual vecteur3d cdm() = 0;
	virtual void mise_a_jour( const double& dt ) = 0;
	virtual double getpas() const = 0;
	virtual void stance( const double& distancetemps ) const = 0;
	virtual void orbites() const = 0;
	virtual void projectionX() const = 0;
	virtual void projectionY() const = 0;
	virtual void projectionZ() const = 0;
	virtual void projection() const = 0;
	virtual void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, dessinable* d );
	virtual void ajoutcorps( corps* c ) = 0;
	virtual void ajoutcorps( corps& c ) = 0;
	virtual void ajoutcorps( set< corps* >s ) = 0;
	virtual void sets( set< corps* >s ) = 0;
	virtual void settemps( const double& t ) = 0;
	virtual void setpas( const double& p ) = 0;
	virtual double gettemps() const = 0;
	virtual void settempsecoule( const double& t ) = 0;
	virtual double gettempsecoule() const = 0;
	virtual set< corps* >getserie() const = 0;
	virtual int nbcorps() const = 0;
	virtual bool getqqch() const = 0;
	virtual void setqqch( const bool& b ) = 0;
	virtual void findacorps( const string& nom ) const throw( corps* ) = 0;
	virtual set< corps* >::iterator begin() const = 0;
	virtual set< corps* >::iterator end() const = 0;
	virtual bool empty() const = 0;
	virtual pair< string, string >getpaire() const = 0;
	virtual void setpaire( pair< string, string >pp ) = 0;
	virtual void setpaire( const string& oui, const string& nom ) = 0;
	virtual void setpaire( const bool& bb, const string& na ) = 0;
	virtual void destroy() = 0;
	virtual void apocalypse() = 0;
	/********************************************************************/

	/***** les methodes qui concernent la camera *****/
	void setleviathan( const vecteur3d& v1,
							   const vecteur3d& v2,
							   const vecteur3d& v3 );
	camera getleviathan() const;
	void setleviathanpos();
	void setleviathanpos( const vecteur3d& v );
	void setleviathanvis();
	void setleviathanvis( const vecteur3d& v );
	void setleviathanjuju();
	void setleviathanjuju( const vecteur3d& v );
	void setleviathanver();
	void setleviathanex();
	void setleviathanlaser();
	void rotateLeftRight( const long double& w );
	void rotateOverUnder( const long double& w );
	void rotateYourself( const long double& w );
	void straight( const double& x );
	void translatedLeftRight( const double& x );
	void translatedUpDown( const double& x );
	/*************************************************/
};

#endif // dessinable_h
