/*
Author: Brandon Lee Villagomez
Class: CS 210 Project Three: Grocery Tracking program for "Corner Grocer"
Date: Completed February 19, 2025
Purpose: The purpose of the grocery tracker app is to allow Corner Grocer to analyze and track their grocery item data.
It provides a user interface and displays a menu with options from 1 through 4

"Option 1" allows the user to see how many times an item is on a list.
"Option 2" allows the user to see a list of all items in the file along with the frequency number.
"Option 3" allows the user to see a list of all items in the file along with an asterisk histogram number.
"Option 4" allows the user to exit the program.
*/

#include <iostream>
#include "Tracker.h"
using namespace std;

int main() {
    Tracker cornerGrocer; // Creates an instance of Tracker class
    cornerGrocer.loadFile("CS210_Project_Three_Input_File.txt"); // Load data from input file

    int option = 0; // Initialize option to avoid uninitialized variable error

    // Program loops until user enters "4" 
    while (option != 4) {
        // Displays menu, prompts user to input an option, then stores input
        cornerGrocer.displayMenu();
        cout << "Enter an option: ";
        cin >> option;

        // Handles what to do based on what option user chose
        switch (option) {
            // If user chose 1, search for item in the file
        case 1: {
            string searchItem;
            cout << "Enter the item name: ";
            cin.ignore(); // Ignore leftover newline
            getline(cin, searchItem); // Read entire line to handle multi-word items
            cornerGrocer.searchItem(searchItem);
            break;
        }
              // If user chose 2, print frequency list
        case 2: {
            cornerGrocer.printFrequencyList();
            break;
        }
              // If user chose 3, print frequency histogram
        case 3: {
            cornerGrocer.printFrequencyHistogram();
            break;
        }
              // If user chose 4, end the program
        case 4:
            cout << "Program finished" << endl;
            break; // Ends the program
            // If user enters a number not from 1 - 4, display error message
        default:
            cout << "Not a valid choice" << endl;
        }
    }

    // Save item frequencies into an output file
    cornerGrocer.saveFile("frequency.dat");

    return 0;
}
