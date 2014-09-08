/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Mon 09 Dec 2013 12:37:22 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 * exception throw
 * virtual destructor
 * constructor of subclass
 * method redefinie subclass (virtual?)
 *
 ******************************************************/

#ifndef __CLASS_AIGUILLAGE__
#define __CLASS_AIGUILLAGE__

#include "Path.hpp"

class Aiguillage: public Path {
// can be open or closed (can be automatically closed if not in position from)
protected:
	bool State;// 0 straight B1-A1, 1 cross B1(B2 if any)-A2
	Path* PathBefore2;// 0 if not used
	Path* PathAfter2;
	Aiguillage* Twin;
	// For GUI display:
	Vecteur3D PosStart2;// (0 0 0) means never used; used when cross (state 1)
	Vecteur3D PosStop2;// used when cross (state 1)
public:
	Aiguillage(const unsigned int& NewID);
	~Aiguillage();
	bool GetState() const;
	Path* GetBefore2() const;
	Path* GetAfter2() const;
	Vecteur3D GetStart2() const;
	Vecteur3D GetStop2() const;
	Aiguillage* GetTwin() const;
	void SetState(const bool& NewState);
	void SetBefore2(Path* NewBefore2);
	void SetAfter2(Path* NewAfter2);
	void SetStart2(const Vecteur3D& Start2);
	void SetStop2(const Vecteur3D& Stop2);
	void SetStart2(const double& x, const double& y, const double& z);
	void SetStop2(const double& x, const double& y, const double& z);
	void SetTwin(Aiguillage* NewTwin);
	void Display(std::ostream& out) const;
	/*** Now methods we need for the model ***/
	void ToggleState();
	Path* GetActivePathBefore() const;
	Path* GetActivePathAfter() const;
	Path* GetInactivePathBefore() const;
	Path* GetInactivePathAfter() const;
	bool NowOpen(const unsigned int& PathFrom, const unsigned int& PathTo) const;
	bool NowState(const unsigned int& PathFrom, const unsigned int& PathTo) const;
	Path* GetNext(const unsigned int& PreviousPath) const throw(std::out_of_range);
};

#endif // __CLASS_AIGUILLAGE__
