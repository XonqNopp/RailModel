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

all: clr runVecteur3D

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
	$(CXX) $(CXXFLAGS) -o $@ $^


test_Vecteur3D.exe: Vecteur3D.obj test_Vecteur3D.obj

Vecteur3D.obj:      Vecteur3D.cpp      Vecteur3D.hpp
test_Vecteur3D.obj: test_Vecteur3D.cpp Vecteur3D.hpp

clean:
	@rm -fv *.obj *.exe
