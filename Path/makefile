#################################################
## Makefile written and maintained by Gael Induni
## Memo
## $@: target
## $^: all dependencies
## $?: all dependencies more recent than target
## $+: same but keeping duplicates
## $<: first dependence
##
## TODO:
##
#################################################

CXX=g++
#CXXFLAGS=
CXXFLAGS=-Wall -O3
GLUTflags=
ifeq ($(shell (uname | cut -b 1-6)),Darwin)
 GLUTlibs=-framework OpenGL -framework GLUT
else
 #GLUTflags=-L/usr/X11R6/lib
 GLUTflags=-L/usr/lib/nvidia-331-updates
 GLUTlibs=-lglut -lGLU -lGL# -lXmu -lXi
endif

all: clr runPath runPartialPath runAiguillage

clr:
	@clear
	@echo

run%: test_%.exe
	@echo
	@echo " => Running $<..."
	@echo
	@./$<
	@echo

%.obj:
	@echo " Compiling $@..."
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

test_%.exe:
	@echo
	@echo "   Building $@..."
	$(CXX) $(CXXFLAGS) $(GLUTflags) -o $@ $^ $(GLUTlibs)


test_Path.exe: Path.obj test_Path.obj ../ModelClass/ModelClass.obj ../Vecteur3D/Vecteur3D.obj
test_PartialPath.exe: PartialPath.obj test_PartialPath.obj Path.obj ../ModelClass/ModelClass.obj ../Vecteur3D/Vecteur3D.obj ../RailroadCrossing/RailroadCrossing.obj ../Signal/Signal.obj ../Signal/NowSignal.obj
test_Aiguillage.exe: Aiguillage.obj test_Aiguillage.obj Path.obj ../ModelClass/ModelClass.obj ../Vecteur3D/Vecteur3D.obj

../Vecteur3D/Vecteur3D.obj:   ../Vecteur3D/Vecteur3D.cpp   ../Vecteur3D/Vecteur3D.hpp
../ModelClass/ModelClass.obj: ../ModelClass/ModelClass.cpp ../ModelClass/ModelClass.hpp
../RailroadCrossing/RailroadCrossing.obj: ../RailroadCrossing/RailroadCrossing.cpp ../RailroadCrossing/RailroadCrossing.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
../Signal/Signal.obj: ../Signal/Signal.cpp ../Signal/Signal.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
../Signal/NowSignal.obj: ../Signal/NowSignal.cpp ../Signal/NowSignal.hpp ../Signal/Signal.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
Path.obj: Path.cpp Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
PartialPath.obj: PartialPath.cpp PartialPath.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp ../RailroadCrossing/RailroadCrossing.hpp ../Signal/Signal.hpp ../Signal/NowSignal.hpp
Aiguillage.obj: Aiguillage.cpp Aiguillage.hpp Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
test_Path.obj: test_Path.cpp Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
test_PartialPath.obj: test_PartialPath.cpp PartialPath.hpp Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp ../RailroadCrossing/RailroadCrossing.hpp ../Signal/Signal.hpp ../Signal/NowSignal.hpp
test_Aiguillage.obj: test_Aiguillage.cpp Aiguillage.hpp Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp

clean:
	@rm -fv *.obj *.exe
