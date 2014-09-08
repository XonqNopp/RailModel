/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:04 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_RAILROADCROSSING__
#define __CLASS_RAILROADCROSSING__

#include <vector>
#include "../Vecteur3D/Vecteur3D.hpp"
#include "../ModelClass/ModelClass.hpp"

class RailroadCrossing: public ModelClass {
protected:
	bool State;// false is left, true is right
	// When open is false, state should be (1,0) alternating (0,1) (who manages sleep?)
	Vecteur3D Position;
	Vecteur3D Direction;
public:
	RailroadCrossing(const unsigned int& NewID);
	virtual ~RailroadCrossing();
	bool GetState() const;
	Vecteur3D GetPosition() const;
	Vecteur3D GetDirection() const;
	void SetState(const bool& NewState);
	void SetPosition(const Vecteur3D& NewPosition);
	void SetDirection(const Vecteur3D& NewDirection);
	void SetPosition(const double& x, const double& y, const double& z);
	void SetDirection(const double& x, const double& y, const double& z);
	void Display(std::ostream& out) const;
	void Draw() const;
	/*** model-related ***/
	bool GetLED1() const;
	bool GetLED2() const;
	void SetLED1(const bool& s1);
	void SetLED2(const bool& s2);
	void ToggleState();
	void Run();
};

#endif // __CLASS_RAILROADCROSSING__
