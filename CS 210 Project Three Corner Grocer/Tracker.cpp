/*
The purpose of the Tracker.cpp file is to define the member functions of the Tracker class.
It is designed to load data from a file, track the frequency of the grocery items, display lists,
allow users to input an option from a displayed menu, and save data into a file.
*/

#include "Tracker.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm> // Needed for string transformation
using namespace std;

Tracker::Tracker() {} // Constructor to initialize Tracker object

// Function to open a file and read the data
void Tracker::loadFile(const string& filename) {
    ifstream inputFile(filename); // Load data from file into trackerData

    // Check if file opens successfully
    if (!inputFile) {
        cerr << "Error: Could not open " << filename << endl;
        exit(1);
    }

    string item;
    // Reads item data from file
    while (inputFile >> item) {
        transform(item.begin(), item.end(), item.begin(), ::tolower); // Convert to lowercase
        trackerData[item]++; // Increment count of the item in the tracker
    }

    inputFile.close(); // Close input file
}

// Function to display menu. Prompt user to select an option.
void Tracker::displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Search for an item" << endl;
    cout << "2. Print item frequency list" << endl;
    cout << "3. Print item frequency histogram" << endl;
    cout << "4. Exit" << endl;
}

// Function to search for an item in the tracker
void Tracker::searchItem(const string& item) {
    string searchKey = item;
    transform(searchKey.begin(), searchKey.end(), searchKey.begin(), ::tolower); // Convert to lowercase

    if (trackerData.find(searchKey) != trackerData.end()) {
        cout << searchKey << ": " << trackerData[searchKey] << endl;
    }
    else {
        cout << "Item not found." << endl;
    }
}

// Function to search and print the item frequency list
void Tracker::printFrequencyList() {
    cout << "Item Frequency List:" << endl;
    // Iterates through the tracker and prints frequencies
    for (const auto& pair : trackerData) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Function to output histogram of item using asterisks
void Tracker::printFrequencyHistogram() {
    cout << "Item Frequency Histogram:" << endl;
    // Iterates through the tracker and prints frequency histograms
    for (const auto& pair : trackerData) {
        cout << pair.first << " ";
        // Loop to print asterisks according to item amount
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to save the item frequencies to a file
void Tracker::saveFile(const string& filename) {
    ofstream outputFile(filename); // Opens file for file writing

    // Check if file opens successfully
    if (!outputFile) {
        cerr << "Error: Could not open " << filename << endl;
        return;
    }

    // Iterates through the tracker and writes item frequencies into the output file
    for (const auto& pair : trackerData) {
        outputFile << pair.first << " " << pair.second << endl;
    }
    outputFile.close(); // Closes output file.
}

