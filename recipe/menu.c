#include "menu.h"
#include <stdio.h>

// PROG71985 - Winter 2024 - Group 12

void printWelcome() {
	printf(" **********************\n");
	printf("**     Welcome to     **\n");
	printf("**    Recipe Maker    **\n");
	printf(" **********************\n");
}

char printMenu() {
	char menuChoice;

	printf("1. Add new recipe\n");
	printf("2. Delete existing recipe\n");
	printf("3. Update existing recipe\n");
	printf("4. Display recipe by recipe number\n");
	printf("5. Display range of recipes by recipe numbers\n");
	printf("6. Display all recipes\n");
	printf("7. Search for recipe\n");
	printf("8. Sort recipes alphabetically\n");
	printf("0. Quit\n");

	printf("Enter your choice (1-8):\n");

	// convert user input to 0 or 1
	// add space for scanf to avoid whitespace
	int menuChoiceConverted = scanf(" %c", &menuChoice);

	// if non character is inputted return 1
	if (menuChoiceConverted == 0) {
		return 1;
	}

	return menuChoice;
}