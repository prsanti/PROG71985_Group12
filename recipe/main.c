#define _CRT_SECURE_NO_WARNINGS
#include "recipe.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>

// PROG71985 - Winter 2024 - Group 12

#define RECIPEFILE "recipes.txt"

int main(void) {
	bool continueProgram = true;

	while (continueProgram) {
		// initialize recipe array
		RECIPE recipes[MAXRECIPES];

		if (loadDataFromFile(recipes, RECIPEFILE) == false) {
			printf("error loading file\n");
			continueProgram = false;
		}

		for (int i = 0; i < MAXRECIPES; i++) {
			printRecipe(recipes[i]);
		}

		int recipenumber;

		printWelcome();

		char menuChoice = printMenu();

		switch (menuChoice) {
		case 'a':
			addRecipe(recipes);
			saveDataToFile(recipes, RECIPEFILE);
			break;
		case 'b':
			printf("Enter recipe number to delete: ");
			scanf_s("%d", &recipenumber);
			deleteRecipe(recipes, recipenumber);
			saveDataToFile(recipes, RECIPEFILE);
			break;
		case 'c':
			printf("Enter recipe number to update: ");
			scanf_s("%d", &recipenumber);
			updateRecipe(recipes, recipenumber);
			saveDataToFile(recipes, RECIPEFILE);
			break;
		case 'd':
			break;
		case 'e':
			break;
		case 'f':
			break;
		case 'g':
			break;
		case 'q':
			continueProgram = false;
			break;
		default:
			break;
		}
	}

	return 0;
}