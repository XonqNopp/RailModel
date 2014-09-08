/******************************************************
 ***** Code written and maintained by Gael INDUNI *****
 ***** Created      : Fri 25 Oct 2013 02:33:29 PM CEST
 ***** Last modified: Wed 04 Dec 2013 08:51:37 AM CET
 ***** Version: 0.01
 *****
 * TODO:
 *
 ******************************************************/

#ifndef __CLASS_TRAIN__
#define __CLASS_TRAIN__

#include "../ModelClass/ModelClass.hpp"

class Train: public ModelClass {
protected:
	bool Direction;
	unsigned double Speed;
	unsigned double MaximumSpeed;
	double Acceleration;
	bool Lights;
	bool Horn;
	bool Webcam();

	unsigned int Path;
	Vecteur3D Position;
	bool DisplayWebcam();
public:
	Train();
	~Train();
	bool GetDirection() const;
	unsigned double GetSpeed() const;
	unsigned double GetMaximumSpeed() const;
	double GetAcceleration() const;
	bool GetLights() const;
	bool GetHorn() const;
	bool GetWebcam() const;
	unsigned int GetPath() const;
	Vecteur3D GetPosition() const;
	bool GetDisplayWebcam() const;

	void SetDirection(const bool& NewDirection);
	void SetSpeed(const unsigned double& NewSpeed);
	void SetMaximumSpeed(const unsigned double& NewMaximumSpeed);
	void SetAcceleration(const double& NewAcceleration);
	void SetLights(const bool& NewLights);
	void SetHorn(const bool& NewHorn);
	void SetWebcam(const bool& NewWebcam);
	void SetPath(const unsigned int& NewPath);
	void SetPosition(const Vecteur3D& NewPosition);
	void SetDisplayWebcam(const bool& NewDisplayWebcam);

	void ComputeSpeed();// a<0 and v==0 -> a=0
	void ReverseWay();
	void EmergencyStop();
	void StopBeforePoint(const unsigned double& Distance);// using MRUA equations
	void ToggleLights();
	void ToggleHorn();
	void Horny();// program with sleeps
	void HasWebcam();
	void WebcamDisabled();
	void ToggleDisplayWebcam();
};

#endif // __CLASS_TRAIN__
