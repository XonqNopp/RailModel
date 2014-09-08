/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Tue 05 Nov 2013 03:18:28 PM CET
 ***** Last modified: Mon 09 Dec 2013 12:23:31 PM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_PATH__
#define __CLASS_PATH__

#include "../Vecteur3D/Vecteur3D.hpp"
#include "../ModelClass/ModelClass.hpp"

class Path: public ModelClass {
// can be open or closed
protected:
	bool SignalOpen;
	bool Busy;
	Path* PathBefore1;//  path before
	Path* PathAfter1;//   path after
	// For GUI display:
	Vecteur3D PosStart1;
	Vecteur3D PosStop1;
public:
	Path(const unsigned int& NewID, const unsigned int& NewKind);
	virtual ~Path();
	bool GetSignalOpen()      const;
	bool GetBusy()            const;
	Path* GetBefore1() const;
	Path* GetAfter1()  const;
	Vecteur3D GetStart1()     const;
	Vecteur3D GetStop1()      const;
	void SetSignalOpen(const bool& NewSignalOpen);
	void SetBusy(const bool& NewBusy);
	void SetBefore1(Path* NewBefore1);
	void SetAfter1(Path* NewAfter1);
	void SetStart1(const Vecteur3D& NewStart1);
	void SetStart1(const double& x, const double& y, const double& z);
	void SetStop1(const Vecteur3D& NewStop1);
	void SetStop1(const double& x, const double& y, const double& z);
	/*** model-related ***/
	void MakeOpen(const bool& NewOpen);
	void ToggleOpen();
	bool ConfirmOpen();
	bool CancelConfirm();
	bool PathOpen() const;
	void TrainEnters();
	void TrainLeaves();
	virtual Path* GetNext(const unsigned int& PreviousPath) const throw(std::out_of_range);
};

#endif // __CLASS_PATH__
