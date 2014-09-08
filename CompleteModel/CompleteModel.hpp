/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 11 Dec 2013 04:50:29 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_COMPLETEMODEL__
#define __CLASS_COMPLETEMODEL__


#define VERSION 0.01

#include "../Path/Path.hpp"
#include "../Path/PartialPath.hpp"
#include "../Path/Aiguillage.hpp"
#include "../RailroadCrossing/RailroadCrossing.hpp"
#include "../Signal/Signal.hpp"
#include "../Signal/NowSignalL2.hpp"
#include "../Signal/NowSignalL3.hpp"
#include "../Signal/NowSignalL4.hpp"
#include "../Signal/PreSignalL.hpp"
//#include "../Signal/NowSignalN.hpp"
//#include "../Signal/PreSignalN.hpp"

//#include <thread>

class CompleteModel: public Dessinable {
protected:
	std::vector<Signal*>          Sigs;
	std::vector<PartialPath*>     PPaths;
	std::vector<RailroadCrossing> Crossings;
	std::vector<Aiguillage>       Aiguilles;
	bool IsRunning;// use this to quit
public:
	CompleteModel();// :set IsRunning to true {srand(time(0)); set all; all red; train stop;}
	CompleteModel(const CompleteModel& CM);// must implement copy constructor
	CompleteModel(CompleteModel* CM);// must implement copy constructor
	~CompleteModel();
	const CompleteModel& operator=(const CompleteModel& CM);// if(this != &CM) return *this
	//CompleteModel* Clone() const {return new CompleteModel(*this);}// ModeClass::Clone()
	void DoDebug();// make 'em all
	void DoDebug(const bool& dbg);
	void AddPreSignalL();
	void AddNowSignalL();
	void AddPreSignalN();
	void AddNowSignalN();
	void AddAiguiallge();
	void AddCrossing();
	void AddPartialPath();
	void Run();// make all in here also sleep
	void Quit();// set IsRunning to false
	void Xmas() const;// make all stop then play LEDs
	void Test() const;// make all LEDs on (or set em back to red)
};

#endif // __CLASS_COMPLETEMODEL__
