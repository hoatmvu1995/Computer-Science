/*Hoat Vu*/
/*Lab 4*/
/*Figure the are aof the top of a cylinder*/
/*and the volume of a cylinder*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define FILE_IN "lab4sample.dat"
#define FILE_IN "lab4.dat"
#define FILE_OUT "lab4.out"

int main(void)
{
	int count = 1;
	double radius, height, area, vol;
	FILE * my_data;
	FILE * data_out;
	
	my_data = fopen(FILE_IN, "r");
	if (my_data == NULL) 
	{
		printf("Error on opening the input file \n");
		exit(EXIT_FAILURE);
	}
	
	data_out = fopen(FILE_OUT, "w");
	if (data_out == NULL) 
	{
		printf("Error on opening the output file \n");
		exit(EXIT_FAILURE);
	}
	
	fprintf(data_out, "Hoat Vu.  Lab 4.\n\n");

	while ((fscanf(my_data, "%lf%lf", &radius, &height)) == 2) 
	{
		area = M_PI * radius * radius;
		vol = M_PI * radius * radius * height;
		
		fprintf(data_out, "\nCylinder %1d", count);
		fprintf(data_out, "\nThe radius is:   %9.3f", radius);
		fprintf(data_out, "\nThe height is:   %9.3f", height);
		fprintf(data_out, "\nThe top area is: %9.3f", area);
		fprintf(data_out, "\nThe volume is:   %9.3f\n", vol);
		count += 1;
	}
	
	fclose(my_data);
	fclose(data_out);
	
	return EXIT_SUCCESS;
}
