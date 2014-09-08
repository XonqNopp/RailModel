/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Wed 13 Nov 2013 12:47:04 PM CET
 ***** Last modified: Thu 05 Dec 2013 08:37:56 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "NowSignal.hpp"
using namespace std;

NowSignal::NowSignal(const unsigned int& NewID, const unsigned int& NewKind)
	:Signal(NewID, NewKind), UserOpen(0)
{}

NowSignal::~NowSignal() {}

unsigned int NowSignal::ValueFullOpen()    const {return 9;}
unsigned int NowSignal::ValueHalfOpen()    const {return 5;}
unsigned int NowSignal::ValueThirdOpen()   const {return 3;}
unsigned int NowSignal::ValueQuarterOpen() const {return 2;}
unsigned int NowSignal::ValueClose()       const {return 0;}

unsigned int NowSignal::GetUserOpen() const {return UserOpen;}
void NowSignal::SetUserOpen(const unsigned int& NewUserOpen) {UserOpen = NewUserOpen;}

void NowSignal::OpenFull() {
	DebugPrint("NowSignal", "OpenFull()");
	SetUserOpen(ValueFullOpen());
}

void NowSignal::Close() {
	DebugPrint("NowSignal", "Close()");
	SetUserOpen(ValueClose());
}

bool NowSignal::Status() const {
	DebugPrint("NowSignal", "Status()");
	return GetUserOpen() & PathOpen();
}

bool NowSignal::GetLED1() const {return GetLEDs(0);}
bool NowSignal::GetLED2() const {return GetLEDs(1);}
