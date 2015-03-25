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
DEPobj=Signal.obj ../Path/Path.obj ../ModelClass/ModelClass.obj ../Vecteur3D/Vecteur3D.obj
DEPhpp=Signal.hpp ../Path/Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp

all: clr runSignal runNowSignal runNowSignalL runNowSignalL2 runNowSignalL3 runNowSignalL4 runPreSignal runPreSignalL
	#NowSignalN PreSignalN

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


test_Signal.exe: test_Signal.obj ../Path/PartialPath.obj $(DEPobj)
test_NowSignal.exe: NowSignal.obj test_NowSignal.obj $(DEPobj)
test_NowSignalN.exe: NowSignalN.obj test_NowSignalN.obj $(DEPobj)
test_NowSignalL.exe: NowSignalL.obj test_NowSignalL.obj $(DEPobj)
test_NowSignalL2.exe: NowSignalL2.obj test_NowSignalL2.obj NowSignalL.obj $(DEPobj)
test_NowSignalL3.exe: NowSignalL3.obj test_NowSignalL3.obj NowSignalL.obj $(DEPobj)
test_NowSignalL4.exe: NowSignalL4.obj test_NowSignalL4.obj NowSignalL.obj $(DEPobj)
test_PreSignal.exe: PreSignal.obj test_PreSignal.obj $(DEPobj)
test_PreSignalN.exe: PreSignalN.obj test_PreSignalN.obj $(DEPobj)
test_PreSignalL.exe: PreSignalL.obj test_PreSignalL.obj ../Path/PartialPath.obj $(DEPobj)

../Vecteur3D/Vecteur3D.obj:   ../Vecteur3D/Vecteur3D.cpp   ../Vecteur3D/Vecteur3D.hpp
../ModelClass/ModelClass.obj: ../ModelClass/ModelClass.cpp ../ModelClass/ModelClass.hpp
../Path/PartialPath.obj: ../Path/PartialPath.cpp ../Path/PartialPath.hpp ../Path/Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
../Path/Path.obj: ../Path/Path.cpp ../Path/Path.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
Signal.obj: Signal.cpp $(DEPhpp)
NowSignal.obj: NowSignal.cpp NowSignal.hpp $(DEPhpp)
NowSignalN.obj: NowSignalN.cpp NowSignalN.hpp $(DEPhpp)
NowSignalL.obj: NowSignalL.cpp NowSignalL.hpp $(DEPhpp)
NowSignalL2.obj: NowSignalL2.cpp NowSignalL2.hpp NowSignalL.hpp $(DEPhpp)
NowSignalL3.obj: NowSignalL3.cpp NowSignalL3.hpp NowSignalL.hpp $(DEPhpp)
NowSignalL4.obj: NowSignalL4.cpp NowSignalL4.hpp NowSignalL.hpp $(DEPhpp)
PreSignal.obj: PreSignal.cpp PreSignal.hpp $(DEPhpp)
PreSignalN.obj: PreSignalN.cpp PreSignalN.hpp $(DEPhpp)
PreSignalL.obj: PreSignalL.cpp PreSignalL.hpp $(DEPhpp)
test_Signal.obj: test_Signal.cpp ../Path/PartialPath.hpp $(DEPhpp)
test_NowSignal.obj: test_NowSignal.cpp NowSignal.hpp $(DEPhpp)
test_NowSignalN.obj: test_NowSignalN.cpp NowSignalN.hpp $(DEPhpp)
test_NowSignalL.obj: test_NowSignalL.cpp NowSignalL.hpp $(DEPhpp)
test_NowSignalL2.obj: test_NowSignalL2.cpp NowSignalL2.hpp NowSignalL.hpp $(DEPhpp)
test_NowSignalL3.obj: test_NowSignalL3.cpp NowSignalL3.hpp NowSignalL.hpp $(DEPhpp)
test_NowSignalL4.obj: test_NowSignalL4.cpp NowSignalL4.hpp NowSignalL.hpp $(DEPhpp)
test_PreSignal.obj: test_PreSignal.cpp PreSignal.hpp $(DEPhpp)
test_PreSignalN.obj: test_PreSignalN.cpp PreSignalN.hpp $(DEPhpp)
test_PreSignalL.obj: test_PreSignalL.cpp PreSignalL.hpp ../Path/PartialPath.hpp $(DEPhpp)

clean:
	@rm -fv *.obj *.exe
