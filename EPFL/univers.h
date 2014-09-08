#ifndef univers_h
#define univers_h

#include "../dessinable/dessinable.h"

#include "../corps/etoile.h"
#include "../corps/planete.h"
#include "../corps/satellite.h"
#include "../corps/asteroide.h"

#include <sstream>
#include <ctime>

class univers: public dessinable
{
	// les 2 methodes taboues des pointeurs
private:
	univers( const univers& u );
	univers& operator=( const univers& u );
protected:
	set< corps* >serie;
	double temps;
	double tempsecoule;
	double pas;
	static long double cg;
	bool names;
	pair< string, string >lesdeuxcorps;
public:
	univers();
	univers( const camera& c,
			 set< corps* >s,
			 const double& t,
			 const double& te,
			 const double& p );
	univers( set< corps* >s,
			 const double& t,
			 const double& te,
			 const double& p );
	virtual ~univers();
	void deepcopy( const univers& u );
	void sets( set< corps* >s );
	void settemps( const double& t );
	void settempsecoule( const double& t );
	void setpas( const double& p );
	set< corps* >getserie() const;
	int nbcorps() const;
	set< corps* >::iterator begin() const;
	set< corps* >::iterator end() const;
	bool empty() const;
	void insert( corps* c );
	void erase( corps* c );
	double gettemps() const;
	double gettempsecoule() const;
	double getpas() const;
	long double g() const;
	bool operator==( const univers& u );
	void affiche( ostream& out ) const;
	friend ostream& operator<<( ostream& out, const univers& u );
	void ajoutcorps( corps* c );
	void ajoutcorps( corps& c );
	void ajoutcorps( set< corps* >s );
	void supprimeuncorps( corps* c );
	void supprimelescorps();
	vecteur3d cdm();
	void dessine() const;
	bool getqqch() const;
	void setqqch( const bool& b );
	void mise_a_jour( const double& dt ) throw( bool );
	void crash( corps* c1, corps* c2 ) throw( vector< string > );
	string createasteroides( corps* c, const vecteur3d& vit2 );
	void stance( const double& distancetemps ) const;
	void orbites() const;
	void projectionX() const;
	void projectionY() const;
	void projectionZ() const;
	void projection() const;
	void findacorps( const string& nom ) const throw( corps* );
	pair< string, string >getpaire() const;
	void setpaire( pair< string, string >pp );
	void setpaire( const string& oui, const string& nom );
	void setpaire( const bool& b, const string& na );
	string intostri( const int& i ) const;
	string dbltostr( const double& d ) const;
	void destroy();
	void apocalypse();
};

	
#endif // univers_h

