/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:21 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_NOWSIGNALL4__
#define __CLASS_NOWSIGNALL4__

#include "NowSignalL.hpp"

class NowSignalL4: public NowSignalL {
// only acts as user says
// has 4 LEDs top to bottom: gryg
// make state 0/1/0/0 (1=on, 0=off, this is red by default)
public:
	NowSignalL4(const unsigned int& NewID);
	virtual ~NowSignalL4();
	void OpenHalf();
	void OpenQuarter();
};

#endif // __CLASS_NOWSIGNALL4__
