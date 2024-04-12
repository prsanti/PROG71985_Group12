#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> 

// PROG71985 - Winter 2024 - Group 12
#define MAXNAME	50
#define MAXINGREDIENT	99
#define MAXINSTRUCTION	500
#define MAXLIST	15
#define MAXRECIPES 10
#define BUFFER_SIZE 2
typedef struct ingredients {
	float quantity;
	char ingredient[MAXINGREDIENT];
} INGREDIENTS;

typedef struct steps {
	int step;
	char instruction[MAXINSTRUCTION];
} STEPS;

typedef struct recipe {
	int recipeNumber;
	char name[MAXNAME];
	int totalIngredients;
	INGREDIENTS ingredientList[MAXLIST];
	int totalSteps;
	STEPS stepsList[MAXLIST];
} RECIPE;

void addRecipe();
void deleteRecipe(int recipeNumber);
void updateRecipe(int recipenumber);
void displayRecipe(struct RECIPE* recipe);
void displayRecipeByNumber(int recipenumber);
void displayRecipeByRange(int startIndex, int endIndex);
void displayAllRecipe();
void ignoreKeyPress();
void searchforRecipe();
void populateEmptyFile(FILE* fp);
bool loadDataFromFile(char* filename);
bool saveDataToFile(char* filename);
void printRecipe(RECIPE r);
void printAllRecipes(void);