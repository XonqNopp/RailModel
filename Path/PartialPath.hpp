/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Tue 10 Dec 2013 08:11:18 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 * exception throw
 * virtual destructor
 * constructor of subclass
 * method redefinie subclass (virtual?)
 *
 ******************************************************/

#ifndef __CLASS_PARTIALPATH__
#define __CLASS_PARTIALPATH__

#include "../RailroadCrossing/RailroadCrossing.hpp"
//#include "../Signal/NowSignal.hpp"
#include "Path.hpp"

class PartialPath: public Path {
protected:
	RailroadCrossing* Crossing;// Crossing on path (points on nothing if none)
	//NowSignal* SignalBefore;// signal before (0=none)
	//NowSignal* SignalAfter;//  signal after  (0=none)
public:
	PartialPath(const unsigned int& NewID);
	PartialPath(const unsigned int& NewID, const Vecteur3D& Start, const Vecteur3D& Stop);
	virtual ~PartialPath();
	RailroadCrossing* GetCrossing() const;
	//NowSignal* GetSignalBefore() const;
	//NowSignal* GetSignalAfter()  const;
	void SetCrossing(RailroadCrossing* NewCrossing);
	//void SetSignalBefore(NowSignal* SB);
	//void SetSignalAfter(NowSignal* SA);
	void Display(std::ostream& out) const;
	void Draw() const;
	/*** model-related ***/
	void ConfirmOpen();
	void CancelConfirm();
	void TrainLeaves();
	//NowSignal* GetNextSignal(const unsigned int& PreviousPath) const;
};

#endif // __CLASS_PARTIALPATH__
