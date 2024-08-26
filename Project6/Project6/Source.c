/* Cameron Bradshaw*/
/* Homework 6 */
/*
This program uses a combination of c code and Intel assembly code to encript a string message. The way it does this is by taking a key of
numbers one for every each bit of a given character read using ASCII. Then it takes the string as an array of characters and for each character
it finds out which bits in ASCII are 1's. Then it takes the corrosponding values from the key and adds them together to make a sum. Then the
character and the sum are printed out.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int key[] = { 2, 5, 8, 19, 40, 79, 162 }; //the key of numbers
	char message[] = "Frank_Zappa Rocks$"; //the message to encript
	int sum = 0; //this is where the sum value ends up for each character
	int i = 0; //i and j are values used to iterate through the arrays
	int j = 0;

	__asm {
		top:	mov ebx, j //this is the beginning of the loop which goes through every character in the message
		top3:	mov al, message[ebx]
				cmp al, '\0' //this tests to see if the current character has reached the end of the message
				je adone //if so then it goes to the end
				mov ecx, 0 //if not then it comes to here where it loops to find if the ASCII values from 0 to 6 are 1's or 0's
				mov edx, 6
				sub edx, i
				mov ecx, edx
				cmp ecx, 0 //this tests if we need to shift to the right any bits. If so it goes to top2
				je around //if it doesn't need to be shifted then it it skips to around
		top2:	shr al, 1 //top2 takes the value gotten from above to right shift the character until the bit we want to look at is the first bit
				loop top2
		around:	and al, 00000001b //from here we check if the bit on the right is 1 or 0
				cmp al, 1
				jne bot1 //if it is 0 then you skip down to bot1 where it goes through the loop again
				mov edx, i //otherwise it takes the value and proceeds to find it in the key and then it adds it to the sum
				imul edx, 4 
				mov eax, sum
				add eax, key[edx]
				mov sum, eax
		bot1:	add i, 1 //here it resets i and then checks to see if it has gone through every bit in the character.
				cmp i, 7 //if so then it continues down to print it out if not then it goes back to top3 where it does it again with i incremented
				jl top3
	}

	printf_s("%c   %d\n", message[j], sum);

	__asm {
				add j, 1 //this resets the variables so that they can be used again then jumps to top to start over again with j being incremented
				mov i, 0
				mov sum, 0
				jmp top
		adone:	nop
	}
}

/*
H   21
e   209
l   66
l   66
o   307
	5
W   291
o   307
r   94
l   66
d   47
!   167
*/

/*
F   121
r   94
a   169
n   145
k   267
_   310
Z   108
a   169
p   15
p   15
a   169
	5
R   89
o   307
c   248
k   267
s   256
$   45
*/