#include <stdio.h>

int main(void)
{
	//code

	// make some empty space on the console to make the program output readable
	printf("\n\n");

	// print sizes of different integral data types
	printf("Size of 'int'           = %ld bytes\n", sizeof(int));
	printf("Size of 'unsigned int'  = %ld bytes\n", sizeof(unsigned int));
	printf("Size of 'long'          = %ld bytes\n", sizeof(long));
	printf("Size of 'long long'     = %ld bytes\n", sizeof(long long));

	// print sizes of different floating point data types
	printf("Size of 'float'         = %ld bytes\n", sizeof(float));
	printf("Size of 'double'        = %ld bytes\n", sizeof(double));
	printf("Size of 'long double'   = %zu bytes\n", sizeof(long double));

	// make some empty space on the console to make the program output readable
	printf("\n\n");

	return(0);
}
