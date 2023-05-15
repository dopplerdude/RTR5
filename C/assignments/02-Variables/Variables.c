#include <stdio.h>

int main(void)
{
	// local variable declarations
	int i_sud = 5;
	float f_sud = 3.9f;
	double d_sud = 8.041997;
	char c_sud = 'A';

	//code
	// Print two new lines
	printf("\n\n");

	printf("i_sud = %d\n", i_sud);
	printf("f_sud = %f\n", f_sud);
	printf("d_sud = %lf\n", d_sud);
	printf("c_sud = %c\n", c_sud);

	// Print two new lines
	printf("\n\n");

	// Change the values of the variables
	// and then print them to the console
	i_sud = 43;
	f_sud = 6.54f;
	d_sud = 26.1294;
	c_sud = 'P';
	
	printf("i_sud = %d\n", i_sud);
	printf("f_sud = %f\n", f_sud);
	printf("d_sud = %g\n", d_sud);
	printf("c_sud = %c\n", c_sud);

	// print two new lines
	printf("\n\n");

	return(0);
}
