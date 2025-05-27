/*
 * File:   main.c
 * Author: <your name here>
 */

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct Vector Vector;
struct Vector
{
	float x;
	float y;
	float z;
};

typedef struct MoveInfo MoveInfo;
struct MoveInfo
{
	Vector velocity;
	float duration;
};

// prototypes for suggested student-implemented functions
int countInputFileLines(char inputFileName[]);
void getPointFromString(char string[], Vector *point);
void getMoveInfoBetweenPoints(MoveInfo *moveInfo, Vector firstPoint, Vector secondPoint);

/*
 * I, Robot Programming Assignment
 */
int main(int argc, char** argv)
{
	// IMPORTANT: Only add code in the section
	// indicated below. The code I've provided
	// makes your solution work with the 
	// automated grader on Coursera
	char rawFileName[MAX_LENGTH];
	fgets(rawFileName, MAX_LENGTH, stdin);
	while (rawFileName[0] != 'q')
	{		
		int stringEndIndex = -1;
		char *result = NULL;
		char *stringStart = &rawFileName[0];

		// handle Windows, MacOS, and Linux
		// check for carriage return
		result = strchr(rawFileName, '\r');
		if (result == NULL)
		{
			// no carriage return found, so find new line
			result = strchr(rawFileName, '\n');
		}

		stringEndIndex = result - stringStart;
		char* inputFileName = malloc((stringEndIndex + 1) * sizeof(char));
		strncpy(inputFileName, rawFileName, stringEndIndex);
		inputFileName[stringEndIndex] = '\0';

		// Add your code between this comment
		// and the comment below. You can of
		// course add more space between the
		// comments as needed

		int numPoints = countInputFileLines(inputFileName);
		if (numPoints < 2) {
			// Not enough points to calculate movement
			printf("Error: not enough points.\n");
			free(inputFileName);
			fgets(rawFileName, MAX_LENGTH, stdin);
			continue;
		}

		FILE* fp = fopen(inputFileName, "r");
		if (fp == NULL) {
			printf("Error: could not open file.\n");
			free(inputFileName);
			fgets(rawFileName, MAX_LENGTH, stdin);
			continue;
		}

		Vector* points = malloc(sizeof(Vector) * numPoints);
		char line[100];
		for (int i = 0; i < numPoints; i++) {
			fgets(line, sizeof(line), fp);
			getPointFromString(line, &points[i]);
		}
		fclose(fp);

		MoveInfo* moves = malloc(sizeof(MoveInfo) * (numPoints - 1));
		float totalDuration = 0.0;

		for (int i = 0; i < numPoints - 1; i++) {
			getMoveInfoBetweenPoints(&moves[i], points[i], points[i + 1]);
			totalDuration += moves[i].duration;
			printf("%.2f,%.2f,%.2f,%.2f", moves[i].velocity.x,
				moves[i].velocity.y,
				moves[i].velocity.z,
				moves[i].duration);
			if (i != numPoints - 2) {
				printf(" ");
			}
		}

		printf(" %.2f\n", totalDuration);

		free(points);
		free(moves);
		
		// Don't add or modify any code below
		// this comment except as indicated below
		free(inputFileName);
		inputFileName = NULL;
		fgets(rawFileName, MAX_LENGTH, stdin);
	}

	return 0;
}

// Add your function implementations between this 
// comment and the comment below. You can of course 
// add more space between the comments as needed

int countInputFileLines(char inputFileName[]) {
	FILE* fp = fopen(inputFileName, "r");
	if (fp == NULL) return -1;

	int count = 0;
	char line[100];
	while (fgets(line, sizeof(line), fp)) {
		count++;
	}
	fclose(fp);
	return count;
}

void getPointFromString(char string[], Vector* point) {
	char* token = strtok(string, ",");
	point->x = atof(token);
	token = strtok(NULL, ",");
	point->y = atof(token);
	token = strtok(NULL, ",");
	point->z = atof(token);
}

void getMoveInfoBetweenPoints(MoveInfo* moveInfo, Vector firstPoint, Vector secondPoint) {
	float dx = secondPoint.x - firstPoint.x;
	float dy = secondPoint.y - firstPoint.y;
	float dz = secondPoint.z - firstPoint.z;

	float distance = sqrt(dx * dx + dy * dy + dz * dz);
	moveInfo->duration = distance;

	if (distance != 0.0f) {
		moveInfo->velocity.x = dx / distance;
		moveInfo->velocity.y = dy / distance;
		moveInfo->velocity.z = dz / distance;
	}
	else {
		moveInfo->velocity.x = 0.0f;
		moveInfo->velocity.y = 0.0f;
		moveInfo->velocity.z = 0.0f;
	}
}

// Don't add or modify any code below this comment
