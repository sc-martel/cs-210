#ifndef PROJECTHREE_TEXT_FILE_PROCESSOR_H_
#define PROJECTHREE_TEXT_FILE_PROCESSOR_H_

#include <map>
#include <string>

using namespace std;

class TextFileProcessor
{
public:
	// Constructors
	TextFileProcessor() : inputFilename(""), outputFilename(""), itemMap() {};
	TextFileProcessor(string t_inputFilename, string t_outputFilename) : inputFilename(t_inputFilename), outputFilename(t_outputFilename), itemMap() {};

	// Accessors
	string getInputFilename() const { return inputFilename; };
	string getOutputFilename() const { return outputFilename; };
	map<string, unsigned int> getItemMap() const { return itemMap; }

	// Mutators
	void setInputFilename(string t_inputFilename) { inputFilename = t_inputFilename; };
	void setOutputFilename(string t_outputFilename) { outputFilename = t_outputFilename; };
	void setItemMap(map<string, unsigned int> t_itemMap) { itemMap = t_itemMap; };

	/** 
	*	This function reads the input file specified by the inputFilename member variable of the TextFileProcessor class
	*	and saves each item and its count to the itemMap map. If the file cannot be opened, an error message is printed
	*/
	void readFile();

	/**
	*	This function writes the data from the itemMap map variable to the output file specified by the class.
	*	It iterates over each item and its corresponding count in the map, and writes it to the output file
	*/
	void backUpFile() const;

	/**
	*	This function prints the key and value pairs of the itemMap, showing the frequency of all items purchased
	*/
	void printItemMap() const;

	/** 
	*	This function prints the key and value pairs of the itemMap in the form of a histogram, showing the frequency of all items purchased
	*/
	void printItemHistogram() const;

	/**
	*	This function allows the user to input a string and the int value of frequency of that string is output
	*/
	void getItemFrequency();

private:
	// File to be read from
	string inputFilename;

	// File to write to
	string outputFilename;
	
	// Map that keeps track count of items 
	map<string, unsigned int> itemMap;

	/**
	*	Creates a new string of the specified n size consisting entirely of the given char c
	*
	*	@param t_n	An unsigned int representing the size of the string
	*	@param t_c	A char that will be repeated n times
	*
	*	@return	    Returns the string of n length repeating char c
	*/
	string nCharString(unsigned int t_n, char t_c) const;

	/**
	*	This function searches the item map for the string t_item and returns the int value of frequency of that item.
	*	If the item is not found -1 is returned.
	* 
	*	@param t_item string of item to be searched
	*	
	*	@return returns the unsigned int value of frequency of t_item
	*/
	unsigned int searchItemMap(string t_item);
};

#endif // PROJECTHREE_TEXT_FILE_PROCESSOR_H_