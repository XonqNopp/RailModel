/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:18 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_NOWSIGNALL3__
#define __CLASS_NOWSIGNALL3__

#include "NowSignalL.hpp"

class NowSignalL3: public NowSignalL {
// only acts as user says
// has 3 LEDs top to bottom: gry
// make state 0/1/0 (1=on, 0=off, this is red by default)
public:
	NowSignalL3(const unsigned int& NewID);
	virtual ~NowSignalL3();
	void OpenHalf();
};

#endif // __CLASS_NOWSIGNALL3__
