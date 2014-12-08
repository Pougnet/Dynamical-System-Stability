slnfinder: slnfinder.o analyzer.o integrator.o sorter.o odes.o
	gcc slnfinder.o analyzer.o integrator.o sorter.o odes.o -o slnfinder

slnfinder.o: slnfinder.c analyzer.o integrator.o
	gcc -c slnfinder.c

integrator.o: integrator.c odes.h
	gcc -c integrator.c

analyzer.o: analyzer.c sorter.h
	gcc -c analyzer.c

odes.o: odes.c
	gcc -c odes.c

sorter.o: sorter.c
	gcc -c sorter.c
