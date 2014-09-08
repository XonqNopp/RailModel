ldflags =
ldlibs =

system = $(shell (uname | cut -b 1-6))

ifeq ($(system),Darwin)
 glutdflags =
 glutdlibs = -framework OpenGL -framework GLUT
else
 glutdflags = -L/usr/X11R6/lib/
 glutdlibs = -lglut -lGLU -lGL -lXmu -lXi
endif

link.glut = g++ $(glutdflags) $(glutdlibs)

all: clr testunivers

clr:
	clear

testunivers: testunivers.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o vecteur3d.o couleur4d.o erreurs.o dessinable.o camera.o
	$(link.glut) -o $@ $^

testunivers.o: univers.h testunivers.cc
	g++ -c -o $@ testunivers.cc

univers.o: univers.h univers.cc
	g++ -c -o $@ univers.cc

corps.o: ../corps/corps.h ../corps/corps.cc
	g++ -c -o $@ ../corps/corps.cc

etoile.o: ../corps/corps.h ../corps/etoile.h ../corps/etoile.cc
	g++ -c -o $@ ../corps/etoile.cc

planete.o: ../corps/corps.h ../corps/planete.h ../corps/planete.cc
	g++ -c -o $@ ../corps/planete.cc

satellite.o: ../corps/corps.h ../corps/satellite.h ../corps/satellite.cc
	g++ -c -o $@ ../corps/satellite.cc

asteroide.o: ../corps/corps.h ../corps/asteroide.h ../corps/asteroide.cc
	g++ -c -o $@ ../corps/asteroide.cc

vecteur3d.o: ../vecteur3d/vecteur3d.h ../vecteur3d/vecteur3d.cc
	g++ -c -o $@ ../vecteur3d/vecteur3d.cc

couleur4d.o: ../couleur4d/couleur4d.h ../couleur4d/couleur4d.cc
	g++ -c -o $@ ../couleur4d/couleur4d.cc

erreurs.o: ../erreurs/erreurs.h ../erreurs/erreurs.cc
	g++ -c -o $@ ../erreurs/erreurs.cc

dessinable.o: ../dessinable/dessinable.h ../dessinable/dessinable.cc
	g++ -c -o $@ ../dessinable/dessinable.cc

camera.o: ../revisitedcamera/camera.h ../revisitedcamera/camera.cc
	g++ -c -o $@ ../revisitedcamera/camera.cc

clean:
	rm *.o testunivers
