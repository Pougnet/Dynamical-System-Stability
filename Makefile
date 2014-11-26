#all: integrator analyzer

#anaylzer: analyzer.o sorter.o
#	icc analyzer.o sorter.o -o analyzer

#integrator: integrator.o odes.o
#	icc integrator.o odes.o -o integrator
slnfinder: slnfinder.o analyzer.o integrator.o sorter.o odes.o
	icc slnfinder.o analyzer.o integrator.o sorter.o odes.o -o slnfinder

slnfinder.o: slnfinder.c analyzer.h integrator.h
	icc -c slnfinder.c

integrator.o: integrator.c odes.h
	icc -c integrator.c

analyzer.o: analyzer.c sorter.h
	icc -c analyzer.c

odes.o: odes.c
	icc -c odes.c

sorter.o: sorter.c
	icc -c sorter.c
