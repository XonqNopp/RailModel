/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Mon 04 Nov 2013 01:24:05 PM CET
 ***** Last modified: Thu 05 Dec 2013 08:38:16 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_NOWSIGNAL__
#define __CLASS_NOWSIGNAL__

#include "Signal.hpp"

class NowSignal: public Signal {
// acts on user and depending on path (and next signal if N)
protected:
	unsigned int UserOpen;// 0 is close, 9 is full open, can be 2 (quarter), 5 (half)
	//// Values for user open
	unsigned int ValueFullOpen()    const;
	unsigned int ValueHalfOpen()    const;
	unsigned int ValueThirdOpen()   const;
	unsigned int ValueQuarterOpen() const;
	unsigned int ValueClose()       const;
public:
	NowSignal(const unsigned int& NewID, const unsigned int& NewKind);
	virtual ~NowSignal();
	unsigned int GetUserOpen() const;
	void SetUserOpen(const unsigned int& NewUserOpen);
	void OpenFull();
	void Close();
	bool Status() const;
	//// LEDs (top to bottom)
	bool GetLED1() const;
	bool GetLED2() const;
};

#endif // __CLASS_NOWSIGNAL__
