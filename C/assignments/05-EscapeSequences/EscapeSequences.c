#include <stdio.h>

int main(void)
{
	//code
	
	//create empty space to make program output readable
	printf("\n\n");
	printf("Going On To Next Line...Using \\n Escape Sequence\n\n");
	printf("Demonstrating \t Horizontal \t Tab \t Using \\t Escape Sequence"
		" !!!\n\n");
	printf("\"This is a Double Quoted Output\" Done Using \\\" \\\" Escape "
		"Sequence\n\n");
	printf("\'This is a Single Quoted Output\' Done Using \\\' \\\' Escape "
		"Sequence\n\n");
	printf("BACKSPACE Turned To BACKSPACE\b Using Escape Sequence \\b\n\n");

	printf("\r Demonstrating Carriage Return Using \\r Escape Sequence \n");
	printf("Demonstrating \r Carriage Return Using \\r Escape Sequence \n");
	printf("Demonstrating Carriage \r Return Using \\r Escape Sequence \n\n");

	// 0x41 Is The Hexadecimal Code For Letter 'A'. 'xhh' Is The Place-holder For 'x'
	// Followed By 2 digits (hh), altogether forming a Hexadecimal Number.
	printf("Demonstrating \x41 Using \\xhh Escape Sequence\n\n"); 

	// 102 Is The Octal Code For Letter 'B'. 'ooo' Is The Place-holder For 3 Digits Forming
	// An Octal Number
	printf("Demonstrating \102 Using \\ooo Escape Sequence\n\n");
	

	printf("Demonstrating My Name \'\x53\x48\x41\x52\x41\x44\' Using \\xhh Escape Sequence\n\n");
	
	printf("Demonstrating My Name \'\123\110\101\122\101\104\' Using \\ooo Escape Sequence\n\n");
	
	return(0);
}
