#pragma once
/*
The purpose of the Tracker.h file is to declare the Tracker class
and its member functions and private data member.
*/

#include <string>
#include <unordered_map> // Using unordered_map for performance
using namespace std;

class Tracker {
public:
    Tracker(); // Constructor to initialize tracker
    void loadFile(const string& filename); // Used to load data from a file into tracker
    void displayMenu();          // Used to display menu options
    void searchItem(const string& item); // Search and output the item frequencies
    void printFrequencyList();           // Prints the item frequency list
    void printFrequencyHistogram(); // Print histogram of the item frequencies
    void saveFile(const string& filename); // Saves item frequencies into a file

private:
    unordered_map<string, int> trackerData; // Private member variable to store frequencies of items
};
