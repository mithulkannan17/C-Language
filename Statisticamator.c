/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

#define MIN 0
#define MAX 1

typedef struct LinkedList LinkedList;
struct LinkedList
{
	int data;
	LinkedList *next;
};
LinkedList *head;
LinkedList *tail;

// prototypes for student-implemented functions
int getValidInteger(int lowerBound, int upperBound);
float averageIntegerArray(int values[], int count);
int findExtremeInIntegerArray(int minOrMax, int values[], int count);

// prototypes for Dr. T functions
void buildLinkedListFromString(char string[]);
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer, LinkedList *node);
LinkedList *getNode(char string[], int spaceIndex);
int getNumber();

/*
 * Height Statisticamator Programming Assignment
 */
int main(int argc, char** argv)
{
	char input[MAX_LENGTH];
	fgets(input, MAX_LENGTH, stdin);
	while (input[0] != 'q')
	{
		buildLinkedListFromString(input);

		// START STUDENT CODE
		int count = getValidInteger(1, 100);
		int heights[100];

		for (int i = 0; i < count; i++) {
			heights[i] = getValidInteger(1, 96);
		}

		float average = averageIntegerArray(heights, count);
		int min = findExtremeInIntegerArray(MIN, heights, count);
		int max = findExtremeInIntegerArray(MAX, heights, count);

		printf("%.2f %d %d\n", average, min, max);
		// END STUDENT CODE

		fgets(input, MAX_LENGTH, stdin);
	}

	return 0;
}

// START STUDENT FUNCTION IMPLEMENTATIONS

int getValidInteger(int lowerBound, int upperBound) {
	int num;
	do {
		num = getNumber();
	} while (num < lowerBound || num > upperBound);
	return num;
}

float averageIntegerArray(int values[], int count) {
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += values[i];
	}
	return (float)sum / count;
}

int findExtremeInIntegerArray(int minOrMax, int values[], int count) {
	int extreme = values[0];
	for (int i = 1; i < count; i++) {
		if ((minOrMax == MIN && values[i] < extreme) ||
			(minOrMax == MAX && values[i] > extreme)) {
			extreme = values[i];
		}
	}
	return extreme;
}

// END STUDENT FUNCTION IMPLEMENTATIONS

/*
 * Builds a linked list of input values from provided string
 */
void buildLinkedListFromString(char string[])
{
	int spaceIndex = -1;
	char *result = NULL;
	result = strchr(string, ' ');
	char *stringStart = &string[0];

	while (result != NULL)
	{
		spaceIndex = result - stringStart;

		LinkedList *node = getNode(stringStart, spaceIndex);
		addNodeToList(&head, &tail, node);

		string = &string[0] + spaceIndex + 1;
		result = strchr(string, ' ');
		stringStart = &string[0];
	}

	LinkedList *node = getNode(stringStart, strlen(stringStart));
	addNodeToList(&head, &tail, node);
}

/*
 * Adds a node to the linked list
 */
void addNodeToList(LinkedList **headPointer, LinkedList **tailPointer, LinkedList *node)
{
	if (*headPointer == NULL)
	{
		*headPointer = node;
	}
	else
	{
		(*tailPointer)->next = node;
	}
	*tailPointer = node;
}

/*
 * Gets a node for the linked list
 */
LinkedList *getNode(char string[], int length)
{
	char* intString = malloc((length + 1) * sizeof(char));
	strncpy(intString, string, length);
	intString[length] = '\0';
	int value = atoi(intString);

	free(intString);
	intString = NULL;

	LinkedList *node;
	node = malloc(sizeof(struct LinkedList));
	node->data = value;
	node->next = NULL;
	return node;
}

/*
 * Get a number from the linked list. If the linked
 * list is empty, returns -1
 */
int getNumber()
{
	int value;
	if (head != NULL)
	{
		value = head->data;

		LinkedList *temp = head;
		head = head->next;
		free(temp);
	}
	else
	{
		value = -1;
	}
	return value;
}
