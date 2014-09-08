.PHONY: all ModelClass Path RailroadCrossing Signal Train dessinable GUI

all: ModelClass Path RailroadCrossing
	#Signal Train

ModelClass:
	@cd ModelClass && make

Path:
	@cd Path && make

RailroadCrossing:
	@cd RailroadCrossing && make

Signal:
	@cd Signal && make

Train:
	@cd Train && make
