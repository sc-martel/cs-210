#include <iostream>
#include <fstream>
#include <map>

#include "TextFileProcessor.h"



void TextFileProcessor::readFile()  {
	
	// Input file stream
	ifstream inFS;

	// Holds current item read from file
	string item;

	// Open in File
	inFS.open(inputFilename);

	// Output error if fail to open input file, 
	// Else read the file and count the occurrence of each item and save to the item map
	if (!inFS.is_open()) {
		cout << "Could not open file " << inputFilename << endl;
	}
	else {

		// Read each item from the file and increment the count of that item in the itemMap
		while (inFS >> item) {
			itemMap[item]++;
		}
	}
}

void TextFileProcessor::backUpFile() const {

	// Output file stream
	ofstream outFS;

	// Open out file
	outFS.open(outputFilename);

	// Output error if fail to open file output file
	// Else write the data from itemMap to the backup output file
	if (!outFS.is_open()) {
		cout << "Could not open file " << outputFilename << endl;
	}
	else {
		// Iterate over the map and write each key value pair to the output file
		for (const pair<string, unsigned int>& kv : itemMap) {
			outFS << kv.first << ": " << kv.second << endl;
		}
	}
}

void TextFileProcessor::printItemMap() const {

	cout << endl << "Item Frequency List" << endl;

	// Iterate over the map and print each key value pair
	for (const pair<string, unsigned int>& kv : itemMap) {
		cout << kv.first << " " << kv.second << endl;
	}
}

void TextFileProcessor::printItemHistogram() const {

	cout << endl << "Item Frequency Histogram" << endl;

	// Iterate over the map and print each key value pair and print item name and count as a histogram
	for (const pair<string, unsigned int>& kv : itemMap) {
		cout << kv.first << " " << this->nCharString(kv.second, '*') << endl;
	}
}

void TextFileProcessor::getItemFrequency() {

	string item;
	unsigned int frequency;

	cout << "Enter item to search: ";
	cin >> item;

	frequency = this->searchItemMap(item);

	if (frequency == -1) {
		cout << item << " is not on the list." << endl;
	}
	else {
		cout << "Frequency: " << frequency << endl;
	}
}

unsigned int TextFileProcessor::searchItemMap(string t_item) {

	map<string, unsigned int>::iterator it;
	int value = -1;

	for (it = itemMap.begin(); it != itemMap.end(); it++) {
		if (it->first == t_item) {
			value = it->second;
			break;
		}
	}

	return value;
}

string TextFileProcessor::nCharString(unsigned int t_n, char t_c) const {

	// Create a string of size chars c
	string result = string(t_n, t_c);

	return result;
}
