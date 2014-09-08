/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Thu 05 Dec 2013 08:54:13 AM CET
 ***** Last modified: Thu 05 Dec 2013 08:54:13 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "NowSignalL4.hpp"
using namespace std;

NowSignalL4::NowSignalL4(const unsigned int& NewID)
	:NowSignalL(NewID)
{
	InitLEDs(4, 1);
}

NowSignalL4::~NowSignalL4() {}
