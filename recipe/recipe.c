#define _CRT_SECURE_NO_WARNINGS 
#include "recipe.h"
// PROG71985 - Winter 2024 - Group 12

RECIPE recipe[MAXRECIPES];
int numRecipes = 0;

//Adding a new recipe
void addRecipe() {
    if (numRecipes < MAXRECIPES) {
        printf("Enter recipe name:\n ");
        scanf("%s", recipe[numRecipes].name);
        printf("Enter total number of ingredients:\n ");
        scanf("%d", &recipe[numRecipes].totalIngredients);
        for (int i = 0; i < recipe[numRecipes].totalIngredients; ++i) {
            printf("Enter quantity for ingredient %d:\n ", i + 1);
            scanf("%f", &recipe[numRecipes].ingredientList[i].quantity);
            printf("Enter name of ingredient %d\n: ", i + 1);
            scanf("%s", recipe[numRecipes].ingredientList[i].ingredient);
        }
        printf("Enter total number of steps:\n ");
        scanf("%d", &recipe[numRecipes].totalSteps);
        for (int i = 0; i < recipe[numRecipes].totalSteps; ++i) {
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
void deleteRecipe(int recipenumber) {
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
void updateRecipe(int recipenumber) {
    int recipeindex = -1;
    for (int i = 0; i < numRecipes; ++i) {
        if (recipe[i].recipeNumber == recipenumber) {
            recipeindex = i;
            break;
        }
    }
    if (recipeindex != -1) {
        printf("Enter new recipe name: ");
        scanf("%s", recipe[recipeindex].name);
        printf("Enter total number of ingredients\n: ");
        scanf("%d", &recipe[recipeindex].totalIngredients);
        for (int i = 0; i < recipe[recipeindex].totalIngredients; ++i) {
            printf("Enter quantity for ingredient %d\n: ", i + 1);
            scanf("%f", &recipe[recipeindex].ingredientList[i].quantity);
            printf("Enter name of ingredient %d\n: ", i + 1);
            scanf("%s", recipe[recipeindex].ingredientList[i].ingredient);
        }
        printf("Enter total number of steps\n: ");
        scanf("%d", &recipe[recipeindex].totalSteps);
        for (int i = 0; i < recipe[recipeindex].totalSteps; ++i) {
            printf("Enter instruction for step %d\n: ", i + 1);
            scanf("%s", recipe[recipeindex].stepsList[i].instruction);
        }
        printf("Recipe updated successfully.\n");
    }
    else {
        printf("Recipe not found.\n");
    }
}
