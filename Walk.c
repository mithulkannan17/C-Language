/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

/*
 * Walking the Walk Programming Assignment
 */
int main(int argc, char** argv)
{
	// IMPORTANT: Only add code in the section
	// indicated below. The code I've provided
	// makes your solution work with the 
	// automated grader on Coursera
	char input[MAX_LENGTH];
	fgets(input, MAX_LENGTH, stdin);
	while (input[0] != 'q')
	{
		int n = atoi(input);

		// Add your code between this comment
		// and the comment below. You can of
		// course add more space between the
		// comments as needed

		int* array = (int*)malloc(n * sizeof(int));
		if (array == NULL) {
			return 1; // Allocation failed
		}

		int* ptr = array;
		int i;

		// Set values using pointer
		for (i = 0; i < n; i++) {
			*(ptr + i) = i;
		}

		// Print values
		for (i = 0; i < n; i++) {
			printf("%d ", *(ptr + i));
		}

		// Calculate sum
		int sum = 0;
		for (i = 0; i < n; i++) {
			sum += *(ptr + i);
		}

		printf("%d\n", sum);

		free(array);
		array = NULL;

		// Don't add or modify any code below
		// this comment
		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}
