/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Thu 05 Dec 2013 09:20:52 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_NOWSIGNALL__
#define __CLASS_NOWSIGNALL__

#include "NowSignal.hpp"

class NowSignalL: public NowSignal {
// only acts as user says
// has x LEDs top to bottom: gr
// make state 0/1 (1=on, 0=off, this is red by default)
public:
	NowSignalL(const unsigned int& NewID);// has own kind
	virtual ~NowSignalL();
	virtual void Display(std::ostream& out) const;
	virtual void Draw() const;
};

#endif // __CLASS_NOWSIGNALL__
