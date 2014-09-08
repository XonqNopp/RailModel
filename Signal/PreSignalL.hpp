/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Thu 05 Dec 2013 07:58:00 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_PRESIGNALL__
#define __CLASS_PRESIGNALL__

#include "PreSignal.hpp"

class PreSignalL: public PreSignal {
// only acts depending on path and next signal
// has 4 LEDs in square top:yy bottom:gg
// ________
// | o  o |
// |    x |
// | x    |
// |______|
// make state 1/1/0/0 closed
public:
	PreSignalL(const unsigned int& NewID);
	virtual ~PreSignalL();
	void SetID(const unsigned int& NewID);
};

#endif // __CLASS_PRESIGNALL__
