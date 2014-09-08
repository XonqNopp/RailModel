system = $(shell (uname | cut -b 1-6))

ifeq ($(system),Darwin)
 glutdflags =
 glutdlibs = -framework OpenGL -framework GLUT
else
 glutdflags = -L/usr/X11R6/lib/
 glutdlibs = -lglut -lGLU -lGL -lXmu -lXi
endif

LINK.GLUT = g++ $(glutdflags) $(glutdlibs)
mygg = g++

all: clr simulation3dXML

clr:
	clear

simulation3dbis: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o simulation3dbis.o erreurs.o
	@echo " * Building simulation3dbis..."
	@$(LINK.GLUT) -o $@ $^

simulation3dXML: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o erreurs.o parseur.o simulation3dXML.o
	@echo " * Building simulation3dXML..."
	@$(LINK.GLUT) -o $@ $^

simulationP15: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o erreurs.o parseur.o simulationP15.o
	@echo " * Building simulationP15..."
	@$(LINK.GLUT) -o $@ $^

simulationP14: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o simulationP14.o erreurs.o
	@echo " * Building simulationP14..."
	@$(LINK.GLUT) -o $@ $^

testInterfaceGraphique: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o testInterfaceGraphique.o erreurs.o
	@echo " * Building testInterfaceGraphique..."
	@$(LINK.GLUT) -o $@ $^

simulation3dlunes: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o erreurs.o parseur.o simulation3dlunes.o
	@echo " * Building simulation3dlunes..."
	@$(LINK.GLUT) -o $@ $^

simulation3d: GUI.o dessinable.o camera.o vecteur3d.o univers.o corps.o etoile.o planete.o satellite.o asteroide.o couleur4d.o erreurs.o parseur.o simulation3d.o
	@echo " * Building simulation3d..."
	@$(LINK.GLUT) -o $@ $^

simulation3dbis.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h simulation3dbis.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling simulation3dbis.cc..."
	@$(mygg) -c -o $@ simulation3dbis.cc

simulation3dXML.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h simulation3dXML.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling simulation3dXML.cc..."
	@$(mygg) -c -o $@ simulation3dXML.cc

simulationP15.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h simulationP15.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling simulationP15.cc..."
	@$(mygg) -c -o $@ simulationP15.cc

simulationP14.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h simulationP14.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling simulationP14.cc..."
	@$(mygg) -c -o $@ simulationP14.cc

testInterfaceGraphique.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h testInterfaceGraphique.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling testInterfaceGraphique.cc..."
	@$(mygg) -c -o $@ testInterfaceGraphique.cc

simulation3dlunes.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h simulation3dlast.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling simulation3dlunes.cc..."
	@$(mygg) -c -o $@ simulation3dlunes.cc

simulation3d.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.h simulation3d.cc ../univers/univers.h ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling simulation3d.cc..."
	@$(mygg) -c -o $@ simulation3d.cc

dessinable.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../dessinable/dessinable.cc ../dessinable/dessinable.h ../univers/univers.h
	@echo "Compiling dessinable.cc..."
	@$(mygg) -c -o $@ ../dessinable/dessinable.cc

GUI.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h  ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../GUI/GUI.cc ../GUI/GUI.h ../dessinable/dessinable.h ../univers/univers.h ../dessinable/dessinable.h
	@echo "Compiling GUI.cc..."
	@$(mygg) -c -o $@ ../GUI/GUI.cc

camera.o: ../vecteur3d/vecteur3d.h ../revisitedcamera/camera.cc ../revisitedcamera/camera.h
	@echo "Compiling camera.cc..."
	@$(mygg) -c -o $@ ../revisitedcamera/camera.cc

vecteur3d.o: ../vecteur3d/vecteur3d.h ../vecteur3d/vecteur3d.cc
	@echo "Compiling vecteur3d.cc..."
	@$(mygg) -c -o $@ ../vecteur3d/vecteur3d.cc

univers.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h ../univers/univers.h ../univers/univers.cc
	@echo "Compiling univers.cc..."
	@$(mygg) -c -o $@ ../univers/univers.cc

corps.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../corps/corps.h ../corps/corps.cc
	@echo "Compiling corps.cc..."
	@$(mygg) -c -o $@ ../corps/corps.cc

etoile.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../corps/corps.h ../corps/etoile.h ../corps/etoile.cc
	@echo "Compiling etoile.cc..."
	@$(mygg) -c -o $@ ../corps/etoile.cc

planete.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../corps/corps.h ../corps/planete.h ../corps/planete.cc
	@echo "Compiling planete.cc..."
	@$(mygg) -c -o $@ ../corps/planete.cc

satellite.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../corps/corps.h ../corps/satellite.h ../corps/satellite.cc
	@echo "Compiling satellite.cc..."
	@$(mygg) -c -o $@ ../corps/satellite.cc

asteroide.o: ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../corps/corps.h ../corps/asteroide.h ../corps/asteroide.cc
	@echo "Compiling asteroide.cc..."
	@$(mygg) -c -o $@ ../corps/asteroide.cc

couleur4d.o: ../couleur4d/couleur4d.h ../couleur4d/couleur4d.cc
	@echo "Compiling couleur4d.cc..."
	@$(mygg) -c -o $@ ../couleur4d/couleur4d.cc

erreurs.o: ../erreurs/erreurs.h ../erreurs/erreurs.cc
	@echo "Compiling erreurs.cc..."
	@$(mygg) -c -o $@ ../erreurs/erreurs.cc

parseur.o:  ../vecteur3d/vecteur3d.h ../couleur4d/couleur4d.h ../erreurs/erreurs.h ../corps/corps.h ../corps/etoile.h ../corps/planete.h ../corps/satellite.h ../corps/asteroide.h  ../univers/univers.h ../parseur/parseur.h ../parseur/parseur.cc ../GUI/GUI.h ../dessinable/dessinable.h
	@echo "Compiling parseur.cc..."
	@$(mygg) -c -o $@ ../parseur/parseur.cc

clean:
	rm *.o simulation3d simulationP14 simulation3dbis simulationP15 testInterfaceGraphique simulation3dXML



