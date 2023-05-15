#include <stdio.h>

int main(void)
{
	//code

	// create some empty space to make output readable
	printf("\n\n");
	printf("*********************************************************************"
	"*************************");
	printf("\n\n");

	printf("Hello World !!!\n\n");

	int a_sud = 13;
	printf("Integer Decimal value of 'a_sud'     = %d\n", a_sud);
	printf("Integer Octal value of 'a_sud'       = %o\n", a_sud);
	printf("Integer Hexadecimal value of 'a_sud' = %x (Hexadecimal letters in "
		"Lower Case)\n", a_sud);
	printf("Integer Hexadecimal value of 'a_sud' = %X (Hexadecimal letters in "
		"Upper Case)\n\n", a_sud);

	char ch_sud = 'A';
	printf("Character ch_sud = %c\n", ch_sud);
	char str_sud[] = "Astromedicomp's Real Time Rendering (RTR5.0) Batch 2023";
	printf("String str_sud = %s\n\n", str_sud);

	long num_sud = 30121995L;
	printf("Long Integer = %ld\n\n", num_sud);

	unsigned int b_sud = 7;
	printf("Unsigned Integer 'b_sud' = %u\n\n", b_sud);

	float f_num_sud = 3012.1995f;
	printf("Floating Point Number With Just %%f 'f_num_sud' = %f\n", f_num_sud);
	printf("Floating Point Number With %%4.2f 'f_num_sud' = %4.2f\n", f_num_sud);
	printf("Floating Point Number With %%6.5f 'f_num_sud' = %6.5f\n\n", f_num_sud);

	double d_pi_sud = 3.14159265358979323846;
	printf("Double Precision Floating Point Number Without Exponential = %g\n",
		d_pi_sud);
	printf("Double Precision Floating Point Number With Exponential (Lower "
		"Case = %e\n", d_pi_sud);
	printf("Double Precision Floating Point Number With Exponential (Upper "
		"Case = %E\n\n", d_pi_sud);
	printf("Double Hexadecimal Value Of 'd_pi_sud' (Hexadecimal Letters In Lower"
		"Case) = %a\n", d_pi_sud);
	printf("Double Hexadecimal Value Of 'd_pi_sud' (Hexadecimal Letters In Upper"
		"Case) = %A\n\n", d_pi_sud);

	printf("*********************************************************************"
		"*************************");
	printf("\n\n");
	return(0);
}
