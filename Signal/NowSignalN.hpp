/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:25 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_NOWSIGNALN__
#define __CLASS_NOWSIGNALN__

#include "NowSignal.hpp"

class NowSignalN: public NowSignal {
// acts on user and depending on path and next signal
// 3 LEDs with digital speed
// make state 1/0/0/0 r/y/g/speed
public:
	NowSignalN(const unsigned int& NewID);
	virtual ~NowSignalN();
	void SetID(const unsigned int& NewID);
};

#endif // __CLASS_NOWSIGNALN__
