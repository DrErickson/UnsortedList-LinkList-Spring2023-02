// Test driver
#include <iostream>
#include <fstream>
#include <string>

#include "UnsortedList.h"

using namespace std;
void PrintList(ofstream& outFile, UnsortedList<int>& list);

int main()
{
	ifstream inFile;       // file containing operations
	ofstream outFile;      // file containing output
	string inFileName;     // input file external name
	string outFileName;    // output file external name
	string outputLabel;
	string command;        // operation to be executed

	int number;
	int item;
	UnsortedList<int> list;

	bool found;

	// Prompt for file names, read file names, and prepare files
	cout << "Enter name of input command file: ";
	cin >> inFileName;
	inFile.open(inFileName);

	cout << "Enter name of output file: ";
	cin >> outFileName;
	outFile.open(outFileName);

	if (!inFile)
	{
		cout << "File not found." << endl;
		exit(2);
	}

	inFile >> command;
	//cin >> command;  // use cin instead of inFile if you want to do command line testing instead

	int numCommands = 0;
	while (command != "Quit")
	{
		//cout << "Command: " << command;
		if (command == "AddItem")
		{
			inFile >> item;
			//cin >> item;
			list.AddItem(item);
            		cout << item;
            		cout << " added to list." << endl;
			outFile << item;
			outFile << " added to list." << endl;
		}
		else if (command == "DeleteItem")
		{
			inFile >> item;
			//cin >> item;
			list.DeleteItem(item);
           		cout << item;
            		cout << " is deleted." << endl;
			outFile << item;
			outFile << " is deleted." << endl;
		}
		else if (command == "Contains")
		{
			inFile >> item;
			//cin >> item;
			if (list.Contains(item)) {
				cout << item << " found in list." << endl;
				outFile << item << " found in list." << endl;
			}
			else {
				cout << item << " not in list." << endl;
				outFile << item << " not in list." << endl;
			}
		}
		else if (command == "GetLength") {
            		cout << "Length is " << list.GetLength() << endl;
			outFile << "Length is " << list.GetLength() << endl;
		}
		else if (command == "IsFull") {
			if (list.IsFull()) {
				cout << "List is full." << endl;
				outFile << "List is full." << endl;
            } else {
                cout << "List is not full." << endl;
                outFile << "List is not full." << endl;
            }
		}
		else if (command == "MakeEmpty") {
			out << "Make list empty." << endl;
			outFile << "Make list empty." << endl;
			list.MakeEmpty();
		}
		else if (command == "PrintList") {
			PrintList(outFile, list);
		}
		else {
			cout << " Command not recognized." << endl;
		}
		numCommands++;
		
		inFile >> command;
		//cin >> command;
	};

	cout << "Quit" << endl << "Testing completed." << endl;
	inFile.close();
	outFile.close();
	return 0;
};


void PrintList(ofstream& dataFile, UnsortedList<int>& list)
// Pre:  list has been initialized.      
//       dataFile is open for writing.   
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.         
{
	int length;
	int item;
	dataFile << "PrintList" << endl;
	cout << "PrintList: ";

	list.ResetIterator();	         // Sets currentPos to head
	length = list.GetLength();
	if (length == 0)
		dataFile << "List is empty.";
	else
		for (int counter = 0; counter < list.GetLength(); counter++)
		{
			item = list.GetNextItem();
			dataFile << item << " ";
			cout << item << " ";
		}
	dataFile << endl;
	cout << endl;
}
