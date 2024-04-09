#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "recipe.h"
#include <stdio.h>
#include <stdbool.h>

// PROG71985 - Winter 2024 - Group 12

#define RECIPEFILE "recipes.txt"

int main(void) {
	bool continueProgram = true;

	while (continueProgram) {
		// intialize recipe array
		RECIPE recipes[MAXRECIPE];
		// load room data from file
		if (loadRoomDataFromFile(recipes, RECIPEFILE) != 1) {
			printf("error loading file\n");
			continueProgram = false;
		}

		printWelcome();

		char menuChoice = printMenu();

		switch (menuChoice) {
		case 'a':
			break;
		case 'b':	
			break;
		case 'c':
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