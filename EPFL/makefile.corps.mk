ldflags =
ldlibs =

system =$(shell (uname | cut -b 1-6))

ifeq ($(system),Darwin)
 glutdflags =
 glutdlibs = -framework OpenGL -framework GLUT
else
 glutdflags = -L/usr/X11R6/lib/
 glutdlibs = -lglut -lGLU -lGL -lXmu -lXi
endif

link.glut = g++ $(glutdflags) $(glutdlibs)


all: clr testcorps

clr:
	clear

testcorps: testcorps.o corps.o vecteur3d.o couleur4d.o etoile.o planete.o satellite.o asteroide.o erreurs.o
	$(link.glut) -o $@ $^

testcorps.o: corps.h testcorps.cc
	g++ -c -o $@ testcorps.cc

corps.o: corps.h corps.cc
	g++ -c -o $@ corps.cc

couleur4d.o: ../couleur4d/couleur4d.h ../couleur4d/couleur4d.cc
	g++ -c -o $@ ../couleur4d/couleur4d.cc

vecteur3d.o: ../vecteur3d/vecteur3d.h ../vecteur3d/vecteur3d.cc
	g++ -c -o $@ ../vecteur3d/vecteur3d.cc

etoile.o: corps.h etoile.h etoile.cc
	g++ -c -o $@ etoile.cc

planete.o: corps.h planete.h planete.cc
	g++ -c -o $@ planete.cc

satellite.o: corps.h satellite.h satellite.cc
	g++ -c -o $@ satellite.cc

asteroide.o: corps.h asteroide.h asteroide.cc
	g++ -c -o $@ asteroide.cc

erreurs.o: ../erreurs/erreurs.h ../erreurs/erreurs.cc
	g++ -c -o $@ ../erreurs/erreurs.cc

clean:
	rm *.o testcorps testcorps2

