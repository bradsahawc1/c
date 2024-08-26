/* Cameron Bradshaw */
/*
This program takes two arrays and sorts them using the bubble and selection sort algorithms. The program accesses the arrays by the use of pointers.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//Bubble sort
void sort1(int *list, int n) {
    int sorted = 0;
    int k = n;

    // sorted becomes 1, when all elements become sorted
    while (!sorted) {
        sorted = 1;
        int* a;
        for (a = list; a < list + k; a++) {              //This iterates through every value of the array using the size indicated. Every loop it then tests the two pointers a and b to
            if (*a > *a + 1) {                     //see which is smaller if the value that comes before in the array (a) is smaller than the other then it switches the two values
                sorted = 0;                    //it also makes the sorted value false or 0 so that when it is finished in the loop it will go through again to check if there
                                               //are more values that need to switched so that it is completely in order
                // Swap elements
                int temp = *a;
                *a = *a + 1;
                *a + 1 = temp;
            }
            k--;
        }
    }
}

//Selection sort
void sort2(int* list, int n) {
    int i, j, minPosition;
    int* a, * b;

    // Run loop from 0 to (n-1)
    for (i = 0; i < n - 1; i++) {                        //This set of loops iterates through the array and basically goes value by value to find out which one is the smallest value
        minPosition = i;                                 //once it figures that out it then switches that value for the value at the front. Because i keeps increasing as it goes it
        for (j = i + 1; j < n; j++) {                    //will eventually find a spot for every value in the array that will put it in order
            a = list + j;
            b = list + minPosition;
            if (*a < *b) {
                minPosition = j;
            }
        }

        // Swap elements
        a = list + i;
        b = list + minPosition;
        int temp = *b;
        *b = *a;
        *a = temp;
    }
}

//Function to print the arrays
print(int* list, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int* a = list + i;
        printf_s("%d ", *a);
    }
    printf("\n");
}

void main() {
	int array1[] = { 99, 98, 97, 96, 95, 94, 93, 92, 91, 89, 88, 87, 86, 85, 84, 83, 82, 81, 79, 78, 77, 76, 75, 74, 73, 72, 71, 69, 68, 67 };
	int array2[] = { 99, 98, 97, 96, 95, 94, 93, 92, 91, 89, 88, 87, 86, 85, 84, 83, 82, 81, 79, 78, 77, 76, 75, 74, 73, 72, 71, 69, 68, 67 };
	int n = 30;
    sort1(array1, n);
	print(array1, n);
	sort2(array2, n);
	print(array2, n);
	scanf_s("%d", &n);
}

/*
20 21 30 31 35 39 40 43 45 60 62 64 70 71 74 75 76 80 82 88
20 21 30 31 35 39 40 43 45 60 62 64 70 71 74 75 76 80 82 88

67 68 69 71 72 73 74 75 76 77 78 79 81 82 83 84 85 86 87 88 89 91 92 93 94 95 96 97 98 99
67 68 69 71 72 73 74 75 76 77 78 79 81 82 83 84 85 86 87 88 89 91 92 93 94 95 96 97 98 99
*/