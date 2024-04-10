#define _CRT_SECURE_NO_WARNINGS
#include "recipe.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include<ctype.h> 


int recipenumber;

// PROG71985 - Winter 2024 - Group 12

int main(void) {
	bool continueProgram = true;

	while (continueProgram) {
		printWelcome();
		char menuChoice = printMenu();
		if (!isdigit(menuChoice)) {
			printf("Please enter number only.\n");
		}
		else {
			switch (menuChoice) {
			case '1':
				addRecipe();
				break;
			case '2':
				printf("Enter recipe number to delete: ");
				scanf_s("%d", &recipenumber);
				deleteRecipe(recipenumber);
				break;
			case '3':
				printf("Enter recipe number to update: ");
				scanf_s("%d", &recipenumber);
				updateRecipe(recipenumber);
				break;
			case '4':
				printf("Enter recipe number: ");
				scanf_s("%d", &recipenumber);
				displayRecipeByNumber(recipenumber);
				break;
			case '5':
				break;
			case '6':
				break;
			case '7':
				break;
			case '8':
				break;
			case '0':
				continueProgram = false;
				break;
			default:
				printf("Please enter Valid Option\n");
				break;
			}
		}
	}

	return 0;
}