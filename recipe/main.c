#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>

// PROG71985 - Winter 2024 - Group 12

int main(void) {
	bool continueProgram = true;

	while (continueProgram) {
		printWelcome();
		char menuChoice = printMenu();

		switch (menuChoice) {
		case 'a':
			break;
		case 'b':
			break;
		case 'c':
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