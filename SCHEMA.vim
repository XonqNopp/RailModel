GUI
 :
 :
dessinable
 |    clic gauche = Path::ToggleOpen
 |    clic droite = Path::Aiguillage::ToggleState
 |    clic milieu = NowSignal::Menu (ou roulette souris?)
 |
CompleteModel = univers herite de dessinable
 :
 :      .............<...... OpenGL
 :      :
ModelClass    = corps
 |
 |_____________________________________________________________
 |                         |                                  |
 |                         |                                  |
RailroadCrossing         Path....................<->...     Signal
 :                _________|_________       : :       :    ___|_________________
 :                |                 |       : :       :    |                   |
 :....<->.....PartialPath      Aiguillage   : :       :.NowSignal         ..PreSignal
                                            : :     _______|_____         :    |     
                                            : :     |           |         :   N,L
                                            : :  NowSignalL  NowSignalN   :
                                            : :     |         :           :
                                            : :   2,3,4       :           :
                                            : :...........<<..:           :
                                            :.............<<..............:
