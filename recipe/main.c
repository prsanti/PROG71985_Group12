#define _CRT_SECURE_NO_WARNINGS
#include "recipe.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>


int recipenumber;

// PROG71985 - Winter 2024 - Group 12

int main(void) {
	bool continueProgram = true;

	while (continueProgram) {
		printWelcome();
		char menuChoice = printMenu();

		switch (menuChoice) {
		case 'a':
			addRecipe();
			break;
		case 'b':
			printf("Enter recipe number to delete: ");
			scanf_s("%d", &recipenumber);
			deleteRecipe(recipenumber);
			break;
		case 'c':
			printf("Enter recipe number to update: ");
			scanf_s("%d", &recipenumber);
			updateRecipe(recipenumber);
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