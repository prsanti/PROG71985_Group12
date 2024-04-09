#pragma once
#include <stdbool.h>

// PROG71985 - Winter 2024 - Group 12
#define MAXNAME	50
#define MAXINGREDIENT	99
#define MAXINSTRUCTION	500
#define MAXLIST	15
#define MAXRECIPE	10

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

bool loadRoomDataFromFile(RECIPE* r, char* filename);

bool saveRoomDataToFile(RECIPE r[MAXRECIPE], char* filename);
