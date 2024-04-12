#define _CRT_SECURE_NO_WARNINGS
#include "recipe.h"
#include "menu.h"


#define RECIPEFILE "recipes.txt"

int recipenumber;
char searchName[MAXNAME];

// PROG71985 - Winter 2024 - Group 12

int main(void) {
	bool continueProgram = true;
	int startIndex;
	int endIndex;
	while (continueProgram) {

		if (loadDataFromFile(RECIPEFILE) == false) {
			printf("error loading file\n");
			continueProgram = false;
		}

		printWelcome();
		char menuChoice = printMenu();
		if (!isdigit(menuChoice)) {
			printf("Please enter number only.\n");
		}
		else {
			switch (menuChoice) {
			case '1':
				addRecipe();
				if (saveDataToFile(RECIPEFILE))
					printf("Recipe saved.\n");
				else
					return 1;
				break;
			case '2':
				printf("Enter recipe number to delete: ");
				scanf_s("%d", &recipenumber);
				deleteRecipe(recipenumber);
				if (saveDataToFile(RECIPEFILE))
					printf("Recipe saved.\n");
				else
					return 1;
				break;
			case '3':
				printf("Enter recipe number to update: ");
				scanf_s("%d", &recipenumber);
				updateRecipe(recipenumber);
				if (saveDataToFile(RECIPEFILE))
					printf("Recipe saved.\n");
				else
					return 1;
				break;
			case '4':
				printf("Enter recipe number: ");
				scanf_s("%d", &recipenumber);
				displayRecipeByNumber(recipenumber);
				break;
			case '5':
				printf("Enter start index for recipe number (1 or above): ");
				scanf_s("%d", &startIndex);
				if (startIndex < 1) {
					printf("\nInvalid start index it sould be greate than 1\n");
					break;
				}
				printf("Enter last index for recipe number: ");
				scanf_s("%d", &endIndex);
				if (endIndex < startIndex) {
					printf("\nLast Index cannot be less than start index\n");
					break;
				}
				displayRecipeByRange(startIndex, endIndex);
				break;
			case '6':
				displayAllRecipe();
				break;
			case '7':
				searchforRecipe();
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