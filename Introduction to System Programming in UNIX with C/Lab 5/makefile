grades: lab5.o class_stats.o
	gcc lab5.o class_stats.o -o grades -lm

lab5.o: lab5.c lab5.h
	gcc -c lab5.c

class_stats.o: class_stats.c lab5.h
	gcc -c class_stats.c
