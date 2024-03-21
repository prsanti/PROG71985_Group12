#pragma once

// PROG71985 - Winter 2024 - Group 12s
#define MAXNAME	50

typedef struct recipe {
	int recipeNumber;
	char name[MAXNAME];
	struct {
		char ingredients[MAXNAME];
		int amount;
	};

	// steps

} RECIPE;