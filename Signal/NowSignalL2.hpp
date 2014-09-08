/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:14 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_NOWSIGNALL2__
#define __CLASS_NOWSIGNALL2__

#include "NowSignalL.hpp"

class NowSignalL2: public NowSignalL {
// only acts as user says
// has 2 LEDs top to bottom: gr
// make state 0/1 (1=on, 0=off, this is red by default)
public:
	NowSignalL2(const unsigned int& NewID);
	virtual ~NowSignalL2();
};

#endif // __CLASS_NOWSIGNALL2__
