/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Mon 04 Nov 2013 01:29:14 PM CET
 ***** Last modified: Wed 04 Dec 2013 08:51:27 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_PRESIGNAL__
#define __CLASS_PRESIGNAL__

#include "Signal.hpp"

class PreSignal: public Signal {
// only acts depending on path and next signal
//protected:
public:
	PreSignal(const unsigned int& NewID);
	virtual ~PreSignal();
	void SetID(const unsigned int& NewID);
};

#endif // __CLASS_PRESIGNAL__
