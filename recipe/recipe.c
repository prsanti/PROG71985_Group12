#include "recipe.h"
#include <stdlib.h>
#include <stdio.h>
// PROG71985 - Winter 2024 - Group 12s

void populateEmptyFile(FILE* fp) {
	for (int i = 1; i <= MAXRECIPE; i++) {
		// recipe number
		fprintf(fp, "%d\n", i);
		// recipe name
		fprintf(fp, "%s\n", "");
		// total ingredients
		fprintf(fp, "%d\n", 0);
		// total steps
		fprintf(fp, "%d\n", 0);
	}
}

bool loadRoomDataFromFile(RECIPE* r, char* filename) {
	FILE* fp = fopen(filename, "r");

	// if file does not exist create a new one
	if (fp == NULL) {
		printf("%s not found, creating a new file\n", filename);
		fp = fopen(filename, "w");

		if (fp == NULL) {
			fprintf(stderr, "error creating new file\n");
			return false;
		}

		// populate empty file
		populateEmptyFile(fp);
		// need to flush buffer to populate
		fflush(fp);
	}

	// open existing or new file
	fp = fopen(filename, "r");

	if (fp == NULL) {
		fprintf(stderr, "error opening file for read\n");
		return false;
	}

	int id;
	char name[MAXNAME];
	int numOfIngredients;
	INGREDIENTS ingredientList[MAXLIST];
	int numOfSteps;
	STEPS stepsList[MAXLIST];

	int i = 0;

	while (i < MAXRECIPE) {
		// read first line of id
		int recipeId = fscanf(fp, "%d", &id);

		// read next line after id (need to test)
		fgetc(fp);

		// read first name line
		fgets(name, MAXNAME, fp);
		// replace last character from '\n' to '\0'
		name[strlen(name) - 1] = '\0';

		int totalIngredients = fscanf(fp, "%d", &numOfIngredients);
		// read next line after total ingredients (need to test)
		fgetc(fp);

		// need to wait...
		//for (int i = 0; i < totalIngredients; i++) {
		//	float quantity = fscanf(fp, "%d", &id);
		//}

		// create recipe struct with function...
		i++;
	}

	fclose(fp);

	return true;
}

bool saveRoomDataToFile(RECIPE r[MAXRECIPE], char* filename) {
	FILE* fp = fopen(filename, "w");

	if (fp == NULL) {
		fprintf(stderr, "error writing to file\n");
		return false;
	}

	// get total recipes (need to test still)
	int totalRecipes = sizeof(r);

	// loop through each recipe and write to file
	for (int i = 0; i < totalRecipes; i++) {
		fprintf(fp, "%d\n", r[i].recipeNumber);
		fprintf(fp, "%s\n", r[i].name);
		fprintf(fp, "%d\n", r[i].totalIngredients);
		int currentTotalIngredients = r[i].totalIngredients;
		for (int j = 0; j < currentTotalIngredients; j++) {
			fprintf(fp, "%0.2f\n", r[i].ingredientList[j].quantity);
			fprintf(fp, "%s\n", r[i].ingredientList[j].ingredient);
		}
		fprintf(fp, "%d\n", r[i].totalSteps);
		for (int k = 0; k < currentTotalIngredients; k++) {
			fprintf(fp, "%d\n", r[i].stepsList[k].step);
			fprintf(fp, "%s\n", r[i].stepsList[k].instruction);
		}
	}

	fclose(fp);

	return true;
}