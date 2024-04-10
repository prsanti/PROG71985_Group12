#define _CRT_SECURE_NO_WARNINGS 
#include "recipe.h"
// PROG71985 - Winter 2024 - Group 12

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int numRecipes = 0;

//Adding a new recipe
void addRecipe(RECIPE recipe[]) {
    if (numRecipes < MAXRECIPES) {
        printf("Enter recipe name:\n ");
        scanf("%s", recipe[numRecipes].name);
        printf("Enter total number of ingredients:\n ");
        scanf("%d", &recipe[numRecipes].totalIngredients);
        for (int i = 0; i < recipe[numRecipes].totalIngredients; ++i) {
            printf("Enter quantity for ingredient %d:\n ", i + 1);
            scanf("%f", &recipe[numRecipes].ingredientList[i].quantity);
            printf("Enter name of ingredient %d:\n ", i + 1);
            scanf("%s", recipe[numRecipes].ingredientList[i].ingredient);
        }
        printf("Enter total number of steps:\n ");
        scanf("%d", &recipe[numRecipes].totalSteps);
        for (int i = 0; i < recipe[numRecipes].totalSteps; ++i) {
			recipe[numRecipes].stepsList[i].step = i + 1;
            printf("Enter instruction for step %d:\n ", i + 1);
            scanf("%s", recipe[numRecipes].stepsList[i].instruction);
        }
        recipe[numRecipes].recipeNumber = numRecipes + 1;
        numRecipes++;
        printf("Recipe added successfully.\n");
    }
    else {
        printf("Cannot add more recipes. Recipe limit reached.\n");
    }
}


//Deleting a recipe
void deleteRecipe(RECIPE recipe[], int recipenumber) {
    int index = -1;
    for (int i = 0; i < numRecipes; ++i) {
        if (recipe[i].recipeNumber == recipenumber) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < numRecipes - 1; ++i) {
            recipe[i] = recipe[i + 1];
        }
        numRecipes--;
        printf("Recipe deleted successfully.\n");
    }
    else {
        printf("Recipe not found.\n");
    }
}
//Updating a recipe
void updateRecipe(RECIPE recipe[], int recipenumber) {
    int recipeindex = -1;
    for (int i = 0; i < numRecipes; ++i) {
        if (recipe[i].recipeNumber == recipenumber) {
            recipeindex = i;
            break;
        }
    }
    if (recipeindex != -1) {
        printf("Enter new recipe name:\n ");
        scanf("%s", recipe[recipeindex].name);
        printf("Enter total number of ingredients:\n");
        scanf("%d", &recipe[recipeindex].totalIngredients);
        for (int i = 0; i < recipe[recipeindex].totalIngredients; ++i) {
            printf("Enter quantity for ingredient %d:\n", i + 1);
            scanf("%f", &recipe[recipeindex].ingredientList[i].quantity);
            printf("Enter name of ingredient %d:\n ", i + 1);
            scanf("%s", recipe[recipeindex].ingredientList[i].ingredient);
        }
        printf("Enter total number of steps:\n ");
        scanf("%d", &recipe[recipeindex].totalSteps);
        for (int i = 0; i < recipe[recipeindex].totalSteps; ++i) {
            printf("Enter instruction for step %d:\n ", i + 1);
            scanf("%s", recipe[recipeindex].stepsList[i].instruction);
        }
        printf("Recipe updated successfully.\n");
    }
    else {
        printf("Recipe not found.\n");
    }
}


void populateEmptyFile(FILE* fp) {
	for (int i = 1; i <= MAXRECIPES; i++) {
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

// DOESNT WORK YET
bool loadDataFromFile(RECIPE r[], char* filename) {
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
	INGREDIENTS ingredients[MAXLIST];
	int numOfSteps;
	STEPS steps[MAXLIST];

	int i = 0;

	while (i < MAXRECIPES) {
		// read first line of id
		int recipeId = fscanf(fp, "%d", &id);
		// set array element to read data
		r[i].recipeNumber = recipeId;

		// read next line after id (need to test)
		fgetc(fp);

		// read first name line
		fgets(name, MAXNAME, fp);
		// replace last character from '\n' to '\0'
		name[strlen(name) - 1] = '\0';
		// set array element to read name
		strncpy(r[i].name, name, MAXNAME);

		int totalIngredients = fscanf(fp, "%d", &numOfIngredients);
		// set array element to read total ingredients
		r[i].totalIngredients = totalIngredients;

		// check if there are ingredients
		//if (totalIngredients > 0) {
		//	for (int j = 0; j < totalIngredients; j++) {
		//		// read quantity
		//		ingredients[j].quantity = fscanf(fp, "%f", &ingredients[j].quantity);
		//		printf("quantity: %f\n", ingredients[j].quantity);
		//		// set array element to quantity read
		//		r[i].ingredientList[j].quantity = ingredients[j].quantity;

		//		// read ingredient name
		//		fgets(ingredients[j].ingredient, MAXINGREDIENT, fp);
		//		// set array element to ingredient read
		//		strncpy(r[i].ingredientList[j].ingredient, ingredients[j].ingredient, MAXINGREDIENT);
		//	}
		//}
		
		for (int j = 0; j < MAXLIST; j++) {
			if (j + 1 <= totalIngredients) {
				// read quantity
				ingredients[j].quantity = fscanf(fp, "%f", &ingredients[j].quantity);
				printf("quantity: %f\n", ingredients[j].quantity);
				// set array element to quantity read
				r[i].ingredientList[j].quantity = ingredients[j].quantity;

				// read ingredient name
				fgets(ingredients[j].ingredient, MAXINGREDIENT, fp);
				// set array element to ingredient read
				strncpy(r[i].ingredientList[j].ingredient, ingredients[j].ingredient, MAXINGREDIENT);
			}
		}
		

		// read next line after total ingredients
		fgetc(fp);

		int totalSteps = fscanf(fp, "%d", &numOfSteps);
		//if (totalSteps > 0) {
		//	for (int j = 0; j < totalSteps; j++) {
		//		steps[j].step = fscanf(fp, "%d", &steps[j].step);
		//		fgets(steps[j].instruction, MAXINSTRUCTION, fp);
		//	}
		//}

		for (int j = 0; j < MAXLIST; j++) {
			if (j + 1 <= totalSteps) {
				steps[j].step = fscanf(fp, "%d", &steps[j].step);
				fgets(steps[j].instruction, MAXINSTRUCTION, fp);
			}
		}

		i++;
	}

	fclose(fp);

	return true;
}

bool saveDataToFile(RECIPE r[], char* filename) {
	FILE* fp = fopen(filename, "w");

	if (fp == NULL) {
		fprintf(stderr, "error writing to file\n");
		return false;
	}

	// loop through each recipe and write to file
	for (int i = 0; i < MAXRECIPES; i++) {
		fprintf(fp, "%d\n", r[i].recipeNumber);

		fprintf(fp, "%s\n", r[i].name);
		fprintf(fp, "%d\n", r[i].totalIngredients);
		int currentTotalIngredients = r[i].totalIngredients;
		for (int j = 0; j < currentTotalIngredients; j++) {
			fprintf(fp, "%0.2f\n", r[i].ingredientList[j].quantity);
			fprintf(fp, "%s\n", r[i].ingredientList[j].ingredient);
		}
		int currentTotalSteps = r[i].totalSteps;
		fprintf(fp, "%d\n", r[i].totalSteps);
		for (int k = 0; k < currentTotalSteps; k++) {
			fprintf(fp, "%d\n", r[i].stepsList[k].step);
			fprintf(fp, "%s\n", r[i].stepsList[k].instruction);
		}

	}

	fclose(fp);

	return true;
}

// for testing
void printRecipe(RECIPE r) {
	printf("recipe num: %d\n", r.recipeNumber);
	printf("name: %s\n", r.name);
	printf("total ingredients: %d\n", r.totalIngredients);
	for (int i = 0; i < r.totalIngredients; i++) {
		printf("quantity: %0.2f\n", r.ingredientList[i].quantity);
		printf("ingredient: %s\n", r.ingredientList[i].ingredient);
	}
	printf("total steps: %d\n", r.totalSteps);
	for (int i = 0; i < r.totalSteps; i++) {
		printf("step: %d\n", r.stepsList[i].step);
		printf("instructions: %s\n", r.stepsList[i].instruction);
	}
}