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

all: clr runRailroadCrossing

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


test_RailroadCrossing.exe: RailroadCrossing.obj test_RailroadCrossing.obj ../ModelClass/ModelClass.obj ../Vecteur3D/Vecteur3D.obj

../Vecteur3D/Vecteur3D.obj:   ../Vecteur3D/Vecteur3D.cpp   ../Vecteur3D/Vecteur3D.hpp
../ModelClass/ModelClass.obj: ../ModelClass/ModelClass.cpp ../ModelClass/ModelClass.hpp
RailroadCrossing.obj: RailroadCrossing.cpp RailroadCrossing.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
test_RailroadCrossing.obj: test_RailroadCrossing.cpp RailroadCrossing.hpp ../ModelClass/ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp

clean:
	@rm -fv *.obj *.exe
