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

	printf("a) Add new recipe\n");
	printf("b) Delete existing recipe\n");
	printf("c) Update existing recipe\n");
	printf("d) Display recipe by recipe number\n");
	printf("e) Display range of recipes by recipe numbers\n");
	printf("f) Display all recipes\n");
	printf("f) Search for recipe\n");
	printf("g) Sort recipes alphabetically\n");
	printf("q) Quit\n");

	printf("Enter a character:");

	// convert user input to 0 or 1
	// add space for scanf to avoid whitespace
	int menuChoiceConverted = scanf(" %c", &menuChoice);

	// if non character is inputted return 1
	if (menuChoiceConverted == 0) {
		return 1;
	}

	return menuChoice;
}