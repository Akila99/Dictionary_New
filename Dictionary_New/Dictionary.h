#pragma once
#include <iostream>
#include <string>
#include "Word.h"
#include <vector>

using namespace std;

#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary { // cretaing class called Dictionary

public:

	virtual void wellcome(); // member function of the Dictionary class 
	virtual void loadDictionary(); // every functions are virtual because eventhough functions are implemented in DIctionary class functions running under Extended DIctionary
	virtual void mainMenu();
	virtual void task1();
	virtual void handleException();
	virtual void task2();
	virtual void task3();
	virtual string getNewDefinition();
	virtual void createNewFile();
	virtual void task4();
	virtual void task5();
	virtual void task6();
	//virtual void task7() {
	

	//}
protected: // these two functiona and vector is protected because it can be access by dictionary subclass 
	vector <Word*> dictionary;
	void  updateDictionary(string, string, string);
	static bool sortStruct(const Word* name1, const Word* name2);
	
};







#endif