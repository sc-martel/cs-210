#include <iostream>
#include "TextFileProcessor.h"

using namespace std;

/**
*	This program analyzes text records of items purchased throughout the day.
*	The user has the option to search the record for frequency of a specific item,
*	print the item and item frequency of the entire record, or print the item and
*	item frequency of the entire record in histogram form.
* 
*	Author: Scott Martel
*	Date: 04/15/2023
* 
*/

// Name of file to be read from
const string IN_FILE = "CS210_Project_Three_Input_File.txt";

// Name of file to be output to
const string OUT_FILE = "frequency.dat";

// Function declarations
void displayMenu();
int getUserInput();
void processUserInput(TextFileProcessor& t_textFileProcessor, int t_input);

int main() {

	TextFileProcessor textFileProcessor(IN_FILE, OUT_FILE);

	// Read from the input file and write the item name and item frequency to the item map
	textFileProcessor.readFile();

	// Back up the data from item map consisting of item name and item frequency to the output file
	textFileProcessor.backUpFile();

	while (true) {

		displayMenu();

		int userInput = getUserInput();

		// If userInput is 4 exit the program
		if (userInput == 4) {
			cout << "Exiting program." << endl;
			break;
		}

		processUserInput(textFileProcessor, userInput);
	}
	
	return 0;
}

/**
*	Displays the options menu
*/
void displayMenu() {
	cout << "|--------------------------- Main Menu -------------------------|" << endl
		<< "| 1. View frequency of a specific item.                         |" << endl
		<< "| 2. Print list of items with the frequency of their purchases. |" << endl
		<< "| 3. Print histogram of item frequencies.                       |" << endl
		<< "| 4. Exit program.                                              |" << endl
		<< "|---------------------------------------------------------------|" << endl;
}

/**
*	Gets the user menu option input, validates input to make sure value is between 1 and 4
* 
*	@return returns the validated user input menu option int
*/
int getUserInput() {

	int userInput;
	do {
		cout << "Choose an option between 1 and 4: ";
		cin >> userInput;
	} while (userInput < 1 || userInput > 4);

	return userInput;
}

/**
*	Processes the user menu option either Search for frequency of a specific item,
*	Print list of items with the frequency of their purchases, or
*	Print histogram of item frequencies. 
* 
*	@param t_textFileProcessor The TextFileProcessor object used to execute the action.
*	@param t_input The integer input provided by the user.
*	
*/
void processUserInput(TextFileProcessor& t_textFileProcessor, int t_input) {

	switch (t_input) {
	case 1:											// Search for frequency of a specific item
		t_textFileProcessor.getItemFrequency();
		cout << endl;
		break;
	case 2:											// Print list of items with the frequency of their purchases
		t_textFileProcessor.printItemMap();
		cout << endl;
		break;
	case 3:											// Print histogram of item frequencies. 
		t_textFileProcessor.printItemHistogram();
		cout << endl;
		break;
	default:										// Invalid input, do nothing
		break;
	}
}