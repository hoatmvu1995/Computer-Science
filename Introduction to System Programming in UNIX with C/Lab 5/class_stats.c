#include "lab5.h"

void class_stats(int grades[], int number_of_grades, double *average, int distribution[]) {
	*average = 0;
	int sum = 0;
	int i;
	
	for (i = 0; i < DIST_SIZE; i++) {
		distribution[i] = 0;
	}
	
	i = 0;
	
	for (i = 0; i < number_of_grades; i++) {
		sum = sum + grades[i];
		*average = sum / (i + 1);
		distribution[grades[i]/10] += 1;
	}
}

