#define CRT_SECURE_NO_WARNINGS
#include "recipe.h"
#include <string.h>

// PROG71985 - Winter 2024 - Group 12

RECIPE recipe[MAXRECIPES];
int numRecipes = 0;

//Adding a new recipe
void addRecipe() {
    if (numRecipes < MAXRECIPES) {
        char recipeName[MAXNAME];
        //User asks for input (enter the recipe name)
        printf("Enter recipe name:\n ");
        ignoreKeyPress(2);
        fgets(recipeName, sizeof(recipeName), stdin);
        // Remove the newline character 
        recipeName[strcspn(recipeName, "\n")] = '\0';
        strcpy(recipe[numRecipes].name, recipeName);
        printf("Enter total number of ingredients:\n ");
        scanf("%d", &recipe[numRecipes].totalIngredients);
        for (int i = 0; i < recipe[numRecipes].totalIngredients; ++i) {
            char ingredient[MAXINGREDIENT];
            printf("Enter quantity for ingredient %d:\n ", i + 1);
            scanf("%f", &recipe[numRecipes].ingredientList[i].quantity);
            printf("Enter name of ingredient %d:\n ", i + 1);
            ignoreKeyPress(2);
            fgets(ingredient, MAXINGREDIENT, stdin);
            ingredient[strcspn(ingredient, "\n")] = '\0';
            strcpy(recipe[numRecipes].ingredientList[i].ingredient, ingredient);
        }
        printf("Enter total number of steps:\n ");
        scanf("%d", &recipe[numRecipes].totalSteps);
        ignoreKeyPress(2);
        for (int i = 0; i < recipe[numRecipes].totalSteps; ++i) {
            int stepNumber = i + 1;
            char instruction[MAXINSTRUCTION];
            recipe[numRecipes].stepsList[i].step = stepNumber;
            printf("Enter instruction for step %d:\n ", stepNumber);
            ignoreKeyPress(1);
            fgets(instruction, MAXINSTRUCTION, stdin);
            instruction[strcspn(instruction, "\n")] = '\0';
            strcpy(recipe[numRecipes].stepsList[i].instruction, instruction);
        }
        recipe[numRecipes].recipeNumber = numRecipes + 1;
        numRecipes++;
        printf("\n*************** Recipe added successfully **************\n");
    }
    else {
        printf("Cannot add more recipes. Recipe limit reached.\n");
    }
}



//Deleting a recipe
void deleteRecipe(int recipenumber) {
    int recipeindex = -1;
    for (int i = 0; i < numRecipes; ++i) {
        if (recipe[i].recipeNumber == recipenumber) {
            recipeindex = i;
            break;
        }
    }
    // Check if the recipe to be deleted was found
    if (recipeindex != -1) {
        for (int i = recipeindex; i < numRecipes - 1; ++i) {
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
    // Find the index of the recipe to be updated
    for (int i = 0; i < numRecipes; ++i) {
        if (recipe[i].recipeNumber == recipenumber) {
            recipeindex = i;
            break;
        }
    }
    if (recipeindex != -1) {
        printf("Enter new recipe name:\n ");
        ignoreKeyPress(2);
        fgets(recipe[recipeindex].name, sizeof(recipe[recipeindex].name), stdin);
        recipe[recipeindex].name[strcspn(recipe[recipeindex].name, "\n")] = '\0';

        printf("Enter total number of ingredients:\n");
        scanf("%d", &recipe[recipeindex].totalIngredients);
        ignoreKeyPress(2);
        // Input validation for total number of ingredients
        if (recipe[recipeindex].totalIngredients <= 0 || recipe[recipeindex].totalIngredients > MAXLIST) {
            printf("Invalid number of ingredients.\n");
            return;
        }
        for (int i = 0; i < recipe[recipeindex].totalIngredients; ++i) {
            printf("Enter quantity for ingredient %d:\n", i + 1);
            scanf("%f", &recipe[recipeindex].ingredientList[i].quantity);
            printf("Enter name of ingredient %d:\n ", i + 1);
            ignoreKeyPress(2);
            fgets(recipe[recipeindex].ingredientList[i].ingredient, sizeof(recipe[recipeindex].ingredientList[i].ingredient), stdin);
            recipe[recipeindex].ingredientList[i].ingredient[strcspn(recipe[recipeindex].ingredientList[i].ingredient, "\n")] = '\0';
        }

        printf("Enter total number of steps:\n ");
        scanf("%d", &recipe[recipeindex].totalSteps);
        ignoreKeyPress(2);
        // Input validation for total steps of a recipe
        if (recipe[recipeindex].totalSteps <= 0 || recipe[recipeindex].totalSteps > MAXLIST) {
            printf("Invalid number of steps.\n");
            return;
        }
        for (int i = 0; i < recipe[recipeindex].totalSteps; ++i) {
            printf("Enter instruction for step %d:\n ", i + 1);
            ignoreKeyPress(2);
            fgets(recipe[recipeindex].stepsList[i].instruction, sizeof(recipe[recipeindex].stepsList[i].instruction), stdin);
            recipe[recipeindex].stepsList[i].instruction[strcspn(recipe[recipeindex].stepsList[i].instruction, "\n")] = '\0';
        }
        printf("Recipe updated successfully.\n");
    }
    else {
        printf("Recipe not found.\n");
    }
}

// displaying the recipe for the entered recipe number
void displayRecipeByNumber(int recipenumber) {
    bool receipeFound = false;
    for (int i = 0; i < numRecipes; ++i) {
        if (recipe[i].recipeNumber == recipenumber) {
            receipeFound = true;
            displayRecipe(&recipe[i]);
            break;
        }
    }
    if (!receipeFound) {
        printf("\n********** Recipe number : %d not found **********\n", recipenumber);
    }

}
// displaying Recipe 
void displayRecipe(RECIPE* rcp) {
    printf("\n################## Receipe Number : %d ##################\n\n", rcp->recipeNumber);
    
    printf("Receipe Name : %s \n", rcp->name);
    
    printf("\n============= Receipe ingredients ===============\n");
    for (int i = 0;i < rcp->totalIngredients; i++) {
        INGREDIENTS ingredient = rcp->ingredientList[i];
        printf("\nIngredient Number : %d\n", (i + 1));
        printf("-- Ingredient Quantity : %f\n", ingredient.quantity);
        printf("-- Ingredient Name : %s", ingredient.ingredient);
    }
    printf("\n================ Receipe Steps ==================\n");
    for (int i = 0;i < rcp->totalSteps; i++) {
        STEPS step = rcp->stepsList[i];
        printf("-- Step %d : %s \n", step.step, step.instruction);
    }
    printf("#########################################################\n");
}

// displaying all recipe records 
void displayAllRecipe() {
    if (numRecipes > 0) {
        printf("\n********** Total Recipes Found : %d **********\n", numRecipes );
        for (int i = 0; i < numRecipes; ++i) {
            displayRecipe(&recipe[i]);
        }
    }
    else {
        printf("\n********** No Recipes Found **********\n");
    }
}

// display all recipes for a given range                                    
void displayRecipeByRange(int startIndex, int endIndex) {
    bool receipeFound = false;
    //adjusting the start index 
    int start = (startIndex - 1);
    // calculating the size of recipe records based on endIndex
    int size = ((endIndex < numRecipes) ? endIndex : numRecipes);
    // Loop is not required if range is only one
    if (size == 1) {
        if (&recipe[start].totalSteps > 0) {
            displayRecipe(&recipe[start]);
            receipeFound = true;
        }
    }
    else {
        for (int i = start; i < (size); ++i) {
            if (&recipe[i].totalSteps > 0) {
                receipeFound = true;
                displayRecipe(&recipe[i]);
            }
        }
    }
    if (!receipeFound) {
        printf("\n********** No Receipes found for Given Range **********\n");
    }
}

void ignoreKeyPress(int bufferSize) {
    char buffer[BUFFER_SIZE];
    fgets(buffer, bufferSize, stdin); // To ignore enter key press
}


//Searching for a recipe by name or ingredient
void searchforRecipe() {
    char searchTerm[MAXNAME];
    printf("Enter recipe name or ingredient to search:\n");
    ignoreKeyPress(2);
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';

    bool recipeFound = false;
    for (int i = 0; i < numRecipes; ++i) {

        // Checking if the recipe name matches the search
        if (strstr(recipe[i].name, searchTerm) != NULL) {
            displayRecipe(&recipe[i]);
            recipeFound = true;
        }
        else {
            // Checking if any ingredient matches the search 
            for (int j = 0; j < recipe[i].totalIngredients; ++j) {
                if (strstr(recipe[i].ingredientList[j].ingredient, searchTerm) != NULL) {
                    displayRecipe(&recipe[i]);
                    recipeFound = true;
                    break;
                }
            }
        }
    }

    if (!recipeFound) {
        printf("No recipes found matching with your search.\n");
    }
}

// load data from file
bool loadDataFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");

    // if file does not exist create a new one
    if (fp == NULL) {
        printf("%s not found, creating a new file\n", filename);
        fp = fopen(filename, "w");

        // set global variable to 0...
        numRecipes = 0;

        if (fp == NULL) {
            fprintf(stderr, "error creating new file\n");
            return false;
        }
        
        // end the create file process
        return true;
    }

    // open existing
    fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "error opening file for read\n");
        return false;
    }


    char name[MAXNAME];
    int numOfIngredients;
    INGREDIENTS ingredients[MAXLIST];
    int numOfSteps;
    STEPS steps[MAXLIST];

    int i = 0;

    // only loop if it can read an id and set that number to the recipe id
    while (fscanf(fp, "%d", &recipe[numRecipes].recipeNumber) > 0) {
        //scanVal: gets returned Value from fscan - 0 = Fail, 1 = Successful
        int scanVal;
        // read next line after id
        fgetc(fp);

        // read first name line
        fgets(name, MAXNAME, fp);

        // update global variable count...
        numRecipes++;

        // replace last character from '\n' to '\0'
        name[strlen(name) - 1] = '\0';
        // set array element to read name
        strncpy(recipe[i].name, name, MAXNAME);

        scanVal = fscanf(fp, "%d", &numOfIngredients);
        // set array element to read total ingredients
        recipe[i].totalIngredients = numOfIngredients;

        for (int j = 0; j < numOfIngredients; j++) {
            // read quantity 
            scanVal = fscanf(fp, "%f", &ingredients[j].quantity);
            // set array element to quantity read
            recipe[i].ingredientList[j].quantity = ingredients[j].quantity;
            // read line after quantity
            fgetc(fp);

            // read ingredient name
            fgets(ingredients[j].ingredient, MAXINGREDIENT, fp);
            // replace last character from '\n' to '\0'
            ingredients[j].ingredient[strlen(ingredients[j].ingredient) - 1] = '\0';
           
            // set array element to ingredient read
            strncpy(recipe[i].ingredientList[j].ingredient, ingredients[j].ingredient, MAXINGREDIENT);
        }
        
        scanVal = fscanf(fp, "%d", &numOfSteps);
        // set array element to read total steps
        recipe[i].totalSteps = numOfSteps;

        // read char after total steps
        fgetc(fp);

        for (int j = 0; j < numOfSteps; j++) {
            // read step number
            scanVal = fscanf(fp, "%d", &steps[j].step);
            int step = j + 1;
            // set recipe step number
            recipe[i].stepsList[j].step = j + 1;

            // read next line after num of steps
            fgetc(fp);

            // read instruction
            fgets(steps[j].instruction, MAXINSTRUCTION, fp);
            // replace last character from '\n' to '\0'
            steps[j].instruction[strlen(steps[j].instruction) - 1] = '\0';

            // set instruction to step number
            strncpy(recipe[i].stepsList[j].instruction, steps[j].instruction, MAXINSTRUCTION);
            
        }

        i++;
    }

    fclose(fp);

    return true;
}

// save recipe to file
bool saveDataToFile(char* filename) {
    FILE* fp = fopen(filename, "w");

    if (fp == NULL) {
        fprintf(stderr, "error writing to file\n");
        return false;
    }

    // loop through each recipe and write to file
    for (int i = 0; i < numRecipes; i++) {
        RECIPE recp = recipe[i];
        fprintf(fp, "%d\n", recp.recipeNumber);

        fprintf(fp, "%s\n", recp.name);
        int currentTotalIngredients = recp.totalIngredients;
        fprintf(fp, "%d\n", currentTotalIngredients);

        for (int j = 0; j < currentTotalIngredients; j++) {
            INGREDIENTS ingredient = recp.ingredientList[j];
            fprintf(fp, "%0.2f\n", ingredient.quantity);
            fprintf(fp, "%s\n", ingredient.ingredient);
        }
        int currentTotalSteps = recp.totalSteps;
        fprintf(fp, "%d\n", currentTotalSteps);
        for (int k = 0; k < currentTotalSteps; k++) {
            STEPS step = recp.stepsList[k];
            fprintf(fp, "%d\n", step.step);
            fprintf(fp, "%s\n", step.instruction);
        }
    }

    fclose(fp);

    return true;
}

// for testing - print recipe
void printRecipe(RECIPE r) {
    printf("---------------------------------------------\n");
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
    printf("---------------------------------------------\n");
}

// for testing - print all recipes
void printAllRecipes() {
    for (int i = 0; i < numRecipes; i++) {
        printRecipe(recipe[i]);
    }
}