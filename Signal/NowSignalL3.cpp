/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Thu 05 Dec 2013 08:52:17 AM CET
 ***** Last modified: Thu 05 Dec 2013 08:55:15 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/
#include "NowSignalL3.hpp"
using namespace std;

NowSignalL3::NowSignalL3(const unsigned int& NewID)
	:NowSignalL(NewID)
{
	InitLEDs(3, 1);
}

NowSignalL3::~NowSignalL3() {}
