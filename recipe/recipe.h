#pragma once

// PROG71985 - Winter 2024 - Group 12s
#define MAXNAME	50
#define MAXINGREDIENT	99
#define MAXINSTRUCTION	500
#define MAXLIST	15

typedef struct recipe {
	int recipeNumber;
	char name[MAXNAME];
	INGREDIENTS ingredientList[MAXLIST];
	STEPS stepsList[MAXLIST];
} RECIPE;

typedef struct ingredients {
	float quantity;
	char ingredient[MAXINGREDIENT];
} INGREDIENTS;

typedef struct steps {
	int step;
	char instruction[MAXINSTRUCTION];
} STEPS;