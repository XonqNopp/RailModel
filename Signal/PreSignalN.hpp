/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:29 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_PRESIGNALN__
#define __CLASS_PRESIGNALN__

#include "PreSignal.hpp"

class PreSignalN: public PreSignal {
// only acts depending on path and next signal
// 3 LEDs with digital speed
// make state 1/0/0 y/g/speed
public:
	PreSignalN(const unsigned int& NewID);
	virtual ~PreSignalN();
	void SetID(const unsigned int& NewID);
};

#endif // __CLASS_PRESIGNALN__
