/* Cameron Bradshaw */
/* Homework 5 */
/*
This program goes through every number from 2 to 100. For each value it multiplies the value by 6 and adds 1 to that result for the first part.
For the second part of the program, it multiplies the value by 6 and then subtracts 1. The program then checks each result to see if they result in a prime #.  
It does this by checking every number it can be divisible by, until it reaches 1. If both numbers are prime then you print it out. It does this using Intel
assembly code mixed with minor amounts of c code.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	//These are the variables used in the program. i is the current number, max is the maximum value 100, and temp is a temporary storage place for the calculated number
	int i, max, temp;
	i = 2;
	max = 100;

	__asm {
						mov ebx, i
		top:			cmp ebx, max //this is the start of the loop that checks if ebx (which is the current number) is equal to 100
						jge out5 //if so, then it will exit the program
						mov eax, ebx
						imul eax, 6 //multiply the current number by 6, then it adds 1 to it
						add eax, 1
						mov ecx, eax //store the number into ecx for the loop that checks to see if it is a prime number
						sub ecx, 1
						mov temp, eax //it also stores the value in the temp variable for later referencing
		primecheck1 :	cmp ecx, 1 //this loop checks to see if the number is prime; it does so by taking the number and dividing it by all numbers less than it
						je out2 //if the number has a value where the remainder is 0 (other than 1), then it is not a prime number
						mov eax, temp
						mov edx, 0
						div ecx
						cmp edx, 0 //checks the remainder and if it is not prime then it jumps to out4, where it checks the next number
						je out4
						sub ecx, 1
						jmp primecheck1
		out2:			mov eax, ebx //this part checks i*6-1
						imul eax, 6
						sub eax, 1
						mov ecx, eax
						sub ecx, 1
						mov temp, eax
		primecheck2 :	cmp ecx, 1
						je out3
						mov eax, temp
						mov edx, 0
						div ecx
						cmp edx, 0
						je out4
						sub ecx, 1
						jmp primecheck2
		out3:			mov i, ebx //when both are confirmed prime it then stores the current number into i so that it can be printed out
	}

	printf_s("%d ", i);

	__asm {
		out4:			add ebx, 1 //goes to the next value in the loop then goes back up to the top
						jmp top
		out5:			nop
	}
}

/*
2 3 5 7 10 12 17 18 23 25 30 32 33 38 40 45 47 52 58 70 72 77 87 95
*/