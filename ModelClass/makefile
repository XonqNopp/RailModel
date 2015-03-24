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
CXXFLAGS=-Wall -O3
GLUTflags=
ifeq ($(shell (uname | cut -b 1-6)),Darwin)
 GLUTlibs=-framework OpenGL -framework GLUT
else
 #GLUTflags=-L/usr/X11R6/lib
 GLUTflags=-L/usr/lib/nvidia-331-updates
 GLUTlibs=-lglut -lGLU -lGL# -lXmu -lXi
endif

all: clr runModelClass

clr:
	@echo
	@clear

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


test_ModelClass.exe: ModelClass.obj test_ModelClass.obj ../Vecteur3D/Vecteur3D.obj

ModelClass.obj: ModelClass.cpp ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp
../Vecteur3D/Vecteur3D.obj: ../Vecteur3D/Vecteur3D.cpp ../Vecteur3D/Vecteur3D.hpp
test_ModelClass.obj: test_ModelClass.cpp ModelClass.hpp ../Vecteur3D/Vecteur3D.hpp

clean:
	@rm -fv *.obj *.exe
