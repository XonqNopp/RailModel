system = $(shell (uname | cut -b 1-6))

ifeq ($(system),Darwin)
 glutdflags =
 glutdlibs = -framework OpenGL -framework GLUT
else
 glutdflags = -L/usr/X11R6/lib/
 glutdlibs = -lglut -lGLU -lGL# -lXmu -lXi
endif

LINK.GLUT = g++ $(ALLWG) $(WEFF)  $(glutdflags) $(glutdlibs)

all: clr simulation3d

clr:
	clear

test_lib: test_lib.exe
	./$@.exe

test_lib.exe: test_lib.cpp
	g++ $(ALLWG) $(WEFF) $(glutdflags) -o $@ $^ $(glutdlibs)







simulation3d: simulation3d.o GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o couleur4d.o
	$(LINK.GLUT) -o $@ $^

simulation3d.o: GUI.h ../znugdu/simulation3d.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../znugdu/simulation3d.cc

dessinable.o: ../dessinable/dessinable.cc ../dessinable/dessinable.h
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../dessinable/dessinable.cc

GUI.o: GUI.cc GUI.h ../dessinable/dessinable.h
	g++ $(ALLWG) $(WEFF)  -c -o $@ GUI.cc

camera.o: ../camera/camera.cc ../camera/camera.h
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../camera/camera.cc

vecteur3d.o: ../vecteur3d/vecteur3d.h ../vecteur3d/vecteur3d.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../vecteur3d/vecteur3d.cc

univers.o: ../univers/univers.h ../univers/univers.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../univers/univers.cc

corps.o: ../corps/corps.h ../corps/corps.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../corps/corps.cc

etoile.o: ../corps/corps.h ../corps/etoile.h ../corps/etoile.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../corps/etoile.cc

planete.o: ../corps/corps.h ../corps/planete.h ../corps/planete.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../corps/planete.cc

satellite.o: ../corps/corps.h ../corps/satellite.h ../corps/satellite.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../corps/satellite.cc

couleur4d.o: ../couleur4d/couleur4d.h ../couleur4d/couleur4d.cc
	g++ $(ALLWG) $(WEFF)  -c -o $@ ../couleur4d/couleur4d.cc

clean:
	rm *.o simulation3d
