*priority*
add MaximumSpeed to path (default 0)
add CremaillereRequired to path (default false)
NowSignal has method that checks path open as far as nowsignal found or end of path
PreSignal    has method that checks next nowsignal
NowSignalNNN has method that checks next nowsignal if any
(protoype in super class be not implemented in super class because needs subclasses)

Signal
finish PartialPath with NowSignal
test PartialPath
Train
CompleteModel
DessinableNew
GUInew
(Now|Pre)SignalN

*ideas*
- signal needs to know if path is open, and what is nextsignal->NowState()
- signal open by user blocks paths open until train leaves (ConfirmOpen)
- partialpath has Signal* SignalBefore/After
- aiguillage::GUI_ChooseLeftRight called on SetAfter1/2

*DONE*
- ModelClass
- RailroadCrossing
- Path, PartialPath, Aiguillage
- Signal
