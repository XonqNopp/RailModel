/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 11 Dec 2013 04:20:33 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_SIGNAL__
#define __CLASS_SIGNAL__

#include <vector>
#include "../ModelClass/ModelClass.hpp"
#include "../Path/Path.hpp"

class Signal: public ModelClass {
protected:
	unsigned int L;//// Length of LEDs (cannot be changed after init)
	std::vector<bool> LEDs;//// LEDs, resize at init
	Path* Next;
	//// For GUI display:
	Vecteur3D Position;
	Vecteur3D Direction;
public:
	Signal(const unsigned int& NewID, const unsigned int& NewKind);
	virtual ~Signal();
	void InitLEDs(const unsigned int& NewL, const unsigned int& RedIdx) throw(std::out_of_range, std::runtime_error);
	std::vector<bool> GetLEDs() const;
	unsigned int GetL() const;
	bool GetLEDs(const unsigned int& idx) const throw(std::out_of_range);
	Path* GetNext() const;
	Vecteur3D GetPosition() const;
	Vecteur3D GetDirection() const;
	void SetLEDs(const std::vector<bool>& NewLEDs) throw(std::out_of_range);
	void SetLED(const unsigned int& idx, const bool& NewVal) throw(std::out_of_range);
	void SetNext(Path* NewNext);
	void SetPosition(const Vecteur3D& NewPosition);
	void SetDirection(const Vecteur3D& NewDirection);
	void SetPosition(const double& x, const double& y, const double& z);
	void SetDirection(const double& x, const double& y, const double& z);
	/*** model-related ***/
	void Xmas();//// toggle all LED to random on-off with a sleep
	void Test();//// toggle all LED to on (if already, should return to all red)
};

#endif // __CLASS_SIGNAL__
