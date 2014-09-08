#ifndef __ARGVC__
#define __ARGVC__

/*** Needs:
 * #include <string>
 * #include <sstream>
 */

template<class CL>
CL argvc(const unsigned int& i, char* av[])
{
	std::string s("");
	s = av[i];
	CL ext;
	std::istringstream icecream(s);
	icecream >> ext;
	return ext;
}

template<class to>
to FromStr(const std::string& strinput)
{
	std::istringstream icecream(strinput);
	to ext;
	icecream >> ext;
	return ext;
}

template<class from>
std::string ToStr(const from& a)
{
	std::ostringstream back;
	back << a;
	return back.str();
}

#endif // __ARGVC__
