// Dictionary_New.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <string>
#include "Word.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "Dictionary.h"
#include "ExtendedDictionary.h"

// Coded by Akila Fernando
// date : 05/14/2023


using namespace std;
void Dictionary::task6() {
	// create a task6 function in the dictionary so this function can be call in the mainMenu
}
void Dictionary::task5() {
	// create a task5 function in the dictionary so this function can be call in the mainMenu
}
void Dictionary::task4() {
	// create a task4 function in the dictionary so this function can be call in the mainMenu
}

bool Dictionary::sortStruct(const Word* name1, const Word* name2) {

	if (name1->getWord() != name2->getWord())// if the element 1 and element 2 in vector is not equal check which one is the greater 
		return name1->getWord() < name2->getWord();
	return false;
}

void Dictionary::createNewFile() {
	string fileName;
	cout << "Enter the file name that you want to create: ";
	getline(cin, fileName);
	string word;
	sort(dictionary.begin(), dictionary.end(), sortStruct);
	ofstream file(fileName + ".txt");

	if (file) {
		file << "2023-S1 dictionary contains " << dictionary.size() << " words" << endl;
		file << "" << endl;
		for (Word* wordObj : dictionary) {
			file << "<word>" << endl;
			file << wordObj->getWord() << endl;
			file << wordObj->getDefinition() << endl;
			file << wordObj->getType() << endl;
			file << "</word>" << endl;

		}
	}
}
/*This function will get four parameters. such as New word , wordType , and its definition. first this function will check whether the input parameters are empty or not using length module, then it will save the data to the Dictionary using push_back(). to check whether the word is saved in the dictionary again i have used the lambda funtion to check the vector. if the word is in the vector then it will print the message.if not it will print error message. if the word is added to dictionary then this function will pass the vector to create a new file.*/

void Dictionary::updateDictionary(string word, string wordType, string definition) {

	if ((word.length() != 0) && (wordType.length() != 0) && (definition.length() != 0)) { // if the word , wordType , word definition is not empty
		Word* wordInstance = new Word(); // instance
		wordInstance->setWord(word); // set the word inside class word attribute
		wordInstance->setType(wordType);// set the wordType inside class type attribute
		wordInstance->setDefinitions(definition);// set the wordDefinition inside class definition attribute

		//wordInstance = (wordInstance->getWord(),wordInstance->getType(),wordInstance->getDefinition() ); // store the new data in a word object
		dictionary.push_back(wordInstance); // store it in the vector
	}
	auto searchWord = find_if(dictionary.begin(), dictionary.end(), [&](const Word* w) { //check the new word in the vector
		return w->getWord() == (word);
		});

	if (searchWord != dictionary.end()) {
		cout << "The word was saved in the dictionary" << endl; // if the word exist in the vector dictionary the print the  message
		createNewFile();
	}
	else {
		cout << "Word is not saved!!" << endl;
	}

}
/*This function will ask user to enter the definition of new word then it will return the string definition to updateDictionary funtion*/

string Dictionary::getNewDefinition() {

	bool loopCondition = false;
	string definition;

	while (loopCondition != true) {
		cout << "Enter the definition of the word: ";
		getline(cin, definition);

		if (definition.length() == 0) {
			cout << "Please enter the word definition!!" << endl;
			loopCondition = false;
		}
		else
		{
			loopCondition = true;

		}

	}

	return definition;

}
void Dictionary::task3() {
	string findWord;

	string wordType;

	string definition;


	bool loopEnd = false;
	bool loop = false;


	cout << "----------------------------------------------------" << endl;
	cout << "TASK 3: ADD A WORD, TYPE, DEFINITIONS AND SORT AND CREATE A NEW FILE." << endl;
	cout << "----------------------------------------------------" << endl << endl;

	while (loop != true) { // create a while for word validation 

		cout << "Enter the word that you want to add to the Dictinoary: ";
		getline(cin, findWord);
		if (findWord.find(" ") != string::npos) {
			cout << "Invalid! White spaces should not be included." << endl;
			loop = false;
			break;
		}
		else if (findWord.empty()) {
			cout << "No Input!!.You should enter a word." << endl;
			loop = false;

		}
		else if (findWord.find("0") != string::npos) {
			cout << "Invalid! Digit should not be included." << endl;
			loop = false;
		}
		else if (findWord.find("1") != string::npos) {
			cout << "Invalid! Digit should no tbe included." << endl;
			loop = false;
		}
		else if (findWord.find("2") != string::npos) {
			cout << "Invalid! Digit should not be included." << endl;
			loop = false;
		}
		else if (findWord.find("3") != string::npos) {
			cout << "Invalid! Digit should not be included." << endl;
			loop = false;
		}
		else if (findWord.find("4") != string::npos) {
			cout << "Invalid! Digit should not be included." << endl;
			loop = false;
		}
		else if (findWord.find("5") != string::npos) {
			cout << "Invalid! Digit cannot not be included." << endl;
			loop = false;
		}
		else if (findWord.find("6") != string::npos) {
			cout << "Invalid! Digit cannot not be included." << endl;
			loop = false;
		}
		else if (findWord.find("7") != string::npos) {
			cout << "Invalid! Digit cannot not be included." << endl;
			loop = false;
		}
		else if (findWord.find("8") != string::npos) {
			cout << "Invalid! Digit cannot not be included." << endl;
			loop = false;
		}
		else if (findWord.find("9") != string::npos) {
			cout << "Invalid! Digit cannot not be included." << endl;
			loop = false;
		}
		else if (findWord.find(" ") != string::npos) { // checking if the find word contains any white spaces
			cout << "Invalid! White spaces should not be included." << endl;
			loop = false;
		}
		else
		{
			loop = true; // if the find word is valid break the loop
			for (int i = 0; i < findWord.length(); i++) {

				findWord[i] = tolower(findWord[i]); // convert wordName characters into lowercase
			}

			auto searchWord = find_if(dictionary.begin(), dictionary.end(), [&](const Word* w) {
				return w->getWord() == (findWord);
				});

			if (searchWord != dictionary.end()) {
				cout << "Error: word exists, elevated privileges required to edit existing words." << endl; // if the word exist in the vector dictionary the print error message
				
			}
			else {
				cout << "Word is not in the Dictionary, You Good to go!" << endl; // if the word is not in the vector dictionary print the message

				while (loopEnd != true) { // while loop for input validation
					cout << "Enter the Word Type(noun,verb, adverb, adjective, preposition, miscellaneous, proper noun or Noun or verb): ";
					getline(cin, wordType);

					if (wordType.length() > 0) { // check if the wordtype is empty 

						for (int i = 0; i < wordType.length(); i++) {

							wordType[i] = tolower(wordType[i]); // convert wordType characters into lowercase
						}

						if (wordType == "noun") {
							loopEnd = true;
							wordType = "n";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "verb") {
							loopEnd = true;
							wordType = "v";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "adverb") {
							loopEnd = true;
							wordType = "adv";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "adjective") {
							loopEnd = true;
							wordType = "adj";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "preposition") {
							loopEnd = true;
							wordType = "prep";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "miscellaneous") {
							loopEnd = true;
							wordType = "misc";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "proper noun") {
							loopEnd = true;
							wordType = "pn";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else if (wordType == "noun or verb") {
							loopEnd = true;
							wordType = "n_and_v";
							definition = getNewDefinition();
							updateDictionary(findWord, wordType, definition);
						}
						else {
							cout << "Invalid type!! Please Enter the valid type according to given structure." << endl;
							loop = false;
						}

					}
					else {
						cout << "Invalid!! Please Enter the type according to given structure." << endl;
						loop = false;
					}
				}

			}
		}
	}
	mainMenu();
}
void Dictionary::task2() {
	string name; // variable for store the vector elements
	const char Z = 'z'; // assign a variable for character Z 
	cout << endl;
	cout << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "TASK 2: PRINT ALL THE WORDS THAT ARE CONTAIN MORE THAN 3 Z'S" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	for (Word* word : dictionary) { // create a range based for loop for check each element in the dictionary vector 
		name = word->getWord();  // store each element in the name variable

		if (name.find(Z) != string::npos) { // checking letter z in the each element 

			size_t length = name.length();  // assign a variable for length of the word
			int count = 0;  // initialized a variable for hold the number of z in the word 
			for (int i = 0; i < (length); i++) {  // checking the word letters one by one using for loop

				if (name[i] == Z) {      // checking if the name[0] is equal to z if the word letter is equal z then add one to count variable  
					count++;
				}

			}
			if (count >= 3) { // if the count is greater than 3 the print to the screen 
				cout << "The words that are contains more that 3 'z's: " << name << endl;
			}
		}
		

	}
	
	mainMenu();
}
void Dictionary::handleException() {
	try {
		task1();
	}
	catch (runtime_error err) {
		cout << err.what() << endl;
		
	}
	mainMenu();
}
void Dictionary::task1()
{

	string wordName; // create a variable to store user input.
	cout << "----------------------" << endl;
	cout << "TASK 1 : FIND THE WORD " << endl;
	cout << "----------------------" << endl;
	runtime_error error("Word not found!");
	cout << "Enter the word that you want to find: ";
	cin >> wordName;

	


	for (int i = 0; i < wordName.length(); i++) {

		wordName[i] = tolower(wordName[i]); // convert wordName characters into lowercase
	}

	auto searchWord = find_if(dictionary.begin(), dictionary.end(), [&](const Word* w) {
		return w->getWord() == (wordName);
		});

	if (searchWord != dictionary.end()) {
		cout << "Word found!" << endl;
		string word_Name, word_type, word_definition;
		word_Name = (*searchWord)->getWord();// asign vector elements to new variables
		word_type = (*searchWord)->getType();
		word_definition = (*searchWord)->getDefinition();

		Word word(word_Name, word_type, word_definition);
		cout << word;
		
	}
	else {
		throw runtime_error(error);
		
	}
	
}

void Dictionary::mainMenu() {
	int taskNumber = 0; //create a variabale for  option
	bool taskValidation = false; // create a variable for task validation 
	bool stop = false;

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ENTER THE OPTION NUMBER THAT YOU WANT TO PERFORM" << endl;
	cout << "------------------------------------------------" << endl << endl;
	cout << "TASK 1: FIND A WORD, TYPE AND DEFINITIONS." << endl;
	cout << "TASK 2: FIND ALL THE WORDS THAT CONTAINS MORE THAN THREE 'Z'." << endl;
	cout << "TASK 3: ADD A WORD, TYPE, DEFINITION AND SORT AND CREATE A NEW FILE." << endl;  // Task list
	cout << "TASK 4: PRINT ALL THE PALINDROMS." << endl;
	cout << "TASK 5: PRINT ALL THE RHYMING WORDS." << endl;
	cout << "TASK 6: GUESS THE FOURTH WORD" << endl;
	cout << "PRESS NUMBER 7 FOR EXIT!!" << endl;

	do {
		cout << "Enter the option number: "; // User input for task 
		cin >> taskNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!!" << endl;// Error message
		}


		switch (taskNumber)
		{
		case 1:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//task1();
			handleException();
			break;
		case 2:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			task2();
			break;
		case 3:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			task3();
			break;

		case 4:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			task4();

			break;
		case 5:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			task5();
			break;
		case 6:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			task6();
			break;
		case 7:
			cin.clear(); //clear the error flag on cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			for (Word* word : dictionary) {
				delete word;
			}
			dictionary.clear();
			exit(1);
			//stop = true;
			break;
		default:
			cout << "Please enter a valid input from above tasks." << endl;
			break;
		}
	} while (taskNumber < 1 || taskNumber >7);
}

void Dictionary::loadDictionary() // loadDictionary() Load the dictionary
{
	int choice = 0; // variable for user input
	string fileName; // Variable for file name
	while (choice != 1 && choice != 2) { // while loop for choice validation

		cout << "Choose one option (Enter 1 to use default dictionary file or Enter 2 for use a different file): ";
		cin >> choice;

		if (choice == 1) {

			//string filename = "dictionary_2023S1.txt"; //asigning the dictionary_2023S1.txt filename variable
			string begin, name, definitions, type, end;

			cout << "Attempting to read text file...\n";
			ifstream myfile("dictionary_2023S1.txt"); //Opening the file 

			if (myfile.is_open())
			{

				while (!myfile.eof())
				{


					getline(myfile, begin); // Store the <word>
					if (!(begin.substr(0, 2) == "20")) { // ignore the header of the file
						if (!(begin == "")) { //ignore the blank line in the file
							if (begin == "<word>") {
								getline(myfile, name); // store the word
								getline(myfile, definitions); // store the word difinition
								getline(myfile, type); // Store the word type
								getline(myfile, end); // store the </Word>

								//Word* new_Word = new Word(name, type, definitions);

								//dictionary.push_back(new_Word); // store the each element to the back of the vector called Dictionary
								
								if (type == "n") {
									Noun* nounInstance = new Noun(name, type, definitions);
									dictionary.push_back(nounInstance);
									
								}
								else if (type == "v") {
									Verb* verbInstance = new Verb(name, type, definitions);
									dictionary.push_back(verbInstance);
									
								}
								else if (type == "adv") {
									Adverb* adverbInstance = new Adverb(name, type, definitions);
									dictionary.push_back(adverbInstance);
									
								}
								else if (type == "adj") {
									Adjective* adjectiveInstance = new Adjective(name, type, definitions);
									dictionary.push_back(adjectiveInstance);
									dictionary.push_back(new Adjective(name, type, definitions));
								}
								else if (type == "prep") {
									Preposition* prepInstance = new Preposition(name, type, definitions);
									dictionary.push_back(prepInstance);
									
								}
								else if (type == "misc") {
									Miscellaneous* miscInstance = new Miscellaneous(name, type, definitions);
									dictionary.push_back(miscInstance);
									
								}
								else if (type == "pn") {
									ProperNoun* pnInstance = new ProperNoun(name, type, definitions);
									dictionary.push_back(pnInstance);
									
								}
								else if (type == "n_and_v") {
									NounAndVerb* nounandverbInstance = new NounAndVerb(name, type, definitions);
									dictionary.push_back(nounandverbInstance);
									
								}
							}

						}

					}


				}
				myfile.close();
				mainMenu();

			}
			else cout << "NO DICTIONARY LOADED!!" << endl << endl;



		}
		else {

			if (choice == 2) {
				//vector <Word> Dictionary; //A vector to hold all the content from the file


				string begin, name, definitions, type, end;

				cout << "Which file do you want to open: ";
				cin >> fileName;

				fileName = (fileName + ".txt");

				cout << "Attempting to read text file...\n";
				ifstream myfile(fileName);
				if (myfile.is_open())
				{

					while (!myfile.eof())
					{


						getline(myfile, begin); // Store the <word>
						if (!(begin.substr(0, 2) == "20")) { // ignore the header of the file
							if (!(begin == "")) { //ignore the blank line in the file
								if (begin == "<word>") {
									getline(myfile, name); // store the word
									getline(myfile, definitions); // store the word difinition
									getline(myfile, type); // Store the word type
									getline(myfile, end); // store the </Word>

									Word* word = new Word{ name ,type, definitions }; // declare a word for Word struct

									dictionary.push_back(word); // store the each element to the back of the vector called Dictionary
									//ExtendedDictionary derivedDictionary(dictionary);
									
								}

							}

						}


					}
					myfile.close();
					
					mainMenu();

				}
				else cout << "NO DICTIONARY LOADED!!" << endl << endl;




			}
			else {
				cin.clear(); //clear the error flag on cin
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the remaining characters in user input
				cout << "Invalid Input!!" << endl;

			}
		}


	}


}
void Dictionary::wellcome()
{
	cout << "WELLCOME TO THE ENGLISH DICTIONARY IN C++" << endl;
	cout << "--------------------------------------------------" << endl << endl;
	cout << "HELLO EVERYONE!!, THIS DICTIONARY WILL PROVIDE OPTIONS TO FIND THE WORD AND SEARCH THE WORDS AND STORE NEW WORDS. YOU GOOD TO GO!!!" << endl << endl;
	loadDictionary();
}

int main()
{
	
	ExtendedDictionary extendedDictionary;
	
	extendedDictionary.wellcome();
	
	//extendedDictionary.performDictionaryFunc();
	//extendedDictionary.task4();



	return 0;
}
