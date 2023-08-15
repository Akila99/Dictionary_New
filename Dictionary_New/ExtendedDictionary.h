#pragma once
#include <iostream>

#include <string>
#include "Word.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "Dictionary.h"
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef EXTENDERDICTIONARY_H
#define EXTENDERDICTIONARY_H



class ExtendedDictionary : public Dictionary {
private:
	
	
public:
	ExtendedDictionary() {}
	
	
	void performDictionaryFunc() { // performing the dictionary funtions
		wellcome();
		loadDictionary();
		mainMenu();
		task1();
		handleException();
		task2();
		task3();
		getNewDefinition();
		createNewFile();
		task4(); 
		task5();
		task6();
		
		//task7();
	}
	//Newly created extendedDictionary function
	void task4();
	bool checkPalindromes(string);
	void task5();
	bool checkWhiteSpaceOrDigit(string);
	bool checkRhyminWord(string, string);
	void task6();
	void setScore(int);

	
};
void ExtendedDictionary::task4() {
	cout << endl << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "TASK 4: PRINT ALL THE PALINDROMS" << endl;
	cout << "----------------------------------------------------" << endl << endl;
	cout << "|PALIDROMS WORDS|" << endl << endl;
	for (const Word* word : dictionary) { // looping vector elements 
		if (checkPalindromes(word->getWord())) { // passing the word to check for palidromes (this function will return true or false). if the word is palindroms word is printed
			cout << "'" << word->getWord() << "'" << " is a palindrome." << endl;
		}
	}
	system("pause");
	mainMenu();
}
bool ExtendedDictionary::checkPalindromes(string word) {
	for (int i = 0; i < word.length() / 2; i++) { // creating a loop for check word , this loop is only runs half of the word
		if (word[i] != word[word.length() - i - 1]) { // this condition is checking whether the fisrt letter [ index i] equal with last letter of the word, 
			return false; // if the word is not a palindromes return false
		}
	}
	return true; // else word is palindroms
}
bool ExtendedDictionary::checkWhiteSpaceOrDigit(string word) {
	for (char i : word) { // for loop for check word characters one by one
		if (isspace(i) || isdigit(i)) {  // condition for check whether the charter is number or a whitespace.
			return true; // if white space or number are included return tru
		}
	}
	return false; //else  return false
}
void ExtendedDictionary::task5() {
	string userInputword; // create variable for store the user input
	bool inputValidation = false; // create a variable for input validation
	bool rhyminWord = false; // create variable for check rhyminwords

	cout << endl << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "TASK 5: PRINT THE RHYMING WORDS" << endl;
	cout << "----------------------------------------------------" << endl << endl;
	do {
		cout << "Enter a word for find the rhyming words: ";
		getline(cin, userInputword);

		if (checkWhiteSpaceOrDigit(userInputword)) { // checking the user input for validation
			cout << "Invalid! WHitespaces and numbers should not be included." << endl;
			inputValidation = false;
		}
		else if (userInputword.empty()) { // if the userInput is empty give error message
			cout << "Please enter a word!!" << endl;
			inputValidation = false;
		}
		else {
			inputValidation = true; // if the above userInput is valid


			cout << "|Rhyming Words|" << endl << endl;
			for (Word* word :  dictionary) { // for loop for output the vector elements
				if (checkRhyminWord(word->getWord(), userInputword)) { // checking whether userInput or current word is rhyminword

					cout << word->getWord() << " is a rhyming word." << endl; // if above condition is true output the value
					rhyminWord = true; 
				}

			}
			if (!rhyminWord) { // if there is no rhyming word matching to user input print the message
				cout << "No rhyming words found" << endl;
			}

		}


	} while (!inputValidation); // do while controller

	system("pause");
	mainMenu();
}
bool ExtendedDictionary::checkRhyminWord(string word_Name, string userInput) {// passing parameter word and the userInput
	if (word_Name.length() >= 3 && userInput.length() >= 3) { // checking whether the word length and userInput word length is greater than 3 
		string lastThreeCharacters1 = word_Name.substr(word_Name.length() - 3); // strore the word last three letters 
		string lastThreeCharacters2 = userInput.substr(userInput.length() - 3); // store the userInput last three letters using substr
		if (lastThreeCharacters1 == lastThreeCharacters2) { // if the characters are equal  return true
			return true; 
		}

	}
	return false;
}

void ExtendedDictionary::task6() {
	
	string startTheGameInput; 
	bool inputValidation = false;
	bool loop = false;
	int highest_Score = 0;
	cout << endl << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "TASK 6: GUESS THE FOURTH WORD" << endl;
	cout << "----------------------------------------------------" << endl << endl;

	cout << "Wellcome to the guess the forth game." << endl;
	cout << "Game Instructions" << endl;
	cout << "-----------------" << endl;
	cout << "1. The word and definition will be display to the console. " << endl;
	cout << "2. You need to guess the fourth word of the definition. " << endl;
	cout << "3. if your guess is correct then you will get 10 score." << endl;
	cout << "4. if your guess is incorrect then you will be out of the game" << endl;
	cout << "                      GOOD LUCK!!!                            " << endl;

	cout << " CURRENT HIGHEST SCORE: " << highest_Score << endl << endl;

	do {
		cout << "Do you want to start the game(y or n): ";
		getline(cin, startTheGameInput);
		for (char c : startTheGameInput) {
			c = tolower(c);
		}
		if (checkWhiteSpaceOrDigit(startTheGameInput)) {
			cout << "Invalid! WHitespaces and numbers should not be included." << endl;
			inputValidation = false;
		}
		else if (startTheGameInput.empty()) {
			cout << "Please enter (y or n)!!" << endl;
			inputValidation = false;
		}
		else if (startTheGameInput.length() > 1) {
			cout << "Please enter (y or n)!!" << endl;
			inputValidation = false;
		}
		else if (startTheGameInput == "y") {
			inputValidation = true;
			//int randomIndex = rand() % dictionary.size();

			
		}


	} while (!inputValidation);

	mainMenu();

}
/*
bool ExtendedDictionary::countWhiteSpaces(string definition) {
	int whiteSpacesCount = 0;
	for (char i : definition) {
		if (isspace(i)) {
			whiteSpacesCount++;

		}
	}
	if (whiteSpacesCount > 4) {
		return true;
	}
	return false;
}*/

/*
void ExtendedDictionary::setScore(int score) {
	highest_Score = score;
}
int ExtendedDictionary::getScore() {
	return highest_Score;
}*/

#endif