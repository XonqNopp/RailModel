/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Fri 06 Dec 2013 08:42:40 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 * exception throw
 * virtual destructor
 * method redefinie subclass (virtual?)
 *
 ******************************************************/

#ifndef __CLASS_MODELCLASS__
#define __CLASS_MODELCLASS__

#include <iostream>
#include <sstream>
#include <string>
//#include <ctime>
#include <stdexcept>
#include <typeinfo>
//#include <thread>
#include "../utils/argvc.hpp"
#include "../Vecteur3D/Vecteur3D.hpp"

#ifdef __APPLE__
	#include <GLUT/glut.h>   /* for Mac OS X */
#else
	#include <GL/glut.h>     /* for UNIX */
#endif

// alpha = 1.0 (no transparency)

class ModelClass {
protected:
	unsigned int ID;
	unsigned int Kind;
	static const unsigned int IDoffsets[9];
	bool debug;
	bool Open;
public:
	ModelClass();
	ModelClass(const ModelClass& MC);
	ModelClass(ModelClass* MC);
	ModelClass(const unsigned int& NewID, const unsigned int& NewKind);
	virtual ~ModelClass();

	unsigned int GetID() const;
	unsigned int GetKind() const;
	void SetID(const unsigned int& NewID) throw(std::out_of_range);
	bool GetDebug() const;
	void SetDebug(const bool& NewDebug);
	bool GetOpen() const;
	void SetOpen(const bool& NewOpen);
	virtual void ToggleOpen();
	virtual bool PathOpen() const;

	void DoDebug(const bool& NewDebug);
	void DoDebug();
	void DebugPrint(const std::string& Class, const std::string& str) const;

	unsigned int GetIDoffset() const;
	unsigned int GetModulo() const;

	virtual void Display(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const ModelClass& MC);
	friend std::ostream& operator<<(std::ostream& out, ModelClass* MC);

	virtual ModelClass* GetNextSignal(const unsigned int& PreviousPath) const;
	virtual bool Status() const;
	virtual void Draw() const;
	void DrawText(const std::string& text, const Vecteur3D& position, const Vecteur3D& colour, const bool& Complete) const;
	void DrawText(const std::string& text, const Vecteur3D& position, const Vecteur3D& colour) const;
	void DrawLine(const Vecteur3D& start, const Vecteur3D& end, const Vecteur3D& colour, const bool& Complete) const;
	void DrawLine(const Vecteur3D& start, const Vecteur3D& end, const Vecteur3D& colour) const;
	void DrawTorus(const Vecteur3D& position, const Vecteur3D& colour, const double& OuterRadius, const double& InnerRadius, const int& wires, const bool& Complete) const;
	void DrawTorus(const Vecteur3D& position, const Vecteur3D& colour, const double& OuterRadius, const double& InnerRadius, const int& wires) const;
	void DrawSphere(const Vecteur3D& position, const Vecteur3D& colour, const double& Radius, const int& wires, const bool& Complete) const;
	void DrawSphere(const Vecteur3D& position, const Vecteur3D& colour, const double& Radius, const int& wires) const;
};

#endif // __CLASS_MODELCLASS__
