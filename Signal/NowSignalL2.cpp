/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Thu 05 Dec 2013 08:51:03 AM CET
 ***** Last modified: Thu 05 Dec 2013 08:52:32 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "NowSignalL2.hpp"
using namespace std;

NowSignalL2::NowSignalL2(const unsigned int& NewID)
	:NowSignalL(NewID)
{
	InitLEDs(2, 1);
}

NowSignalL2::~NowSignalL2() {}
