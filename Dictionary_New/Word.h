#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef WORD_H
#define WORD_H


class Word { // created a class called word
	 friend ostream& operator <<(ostream&, const Word&);
private:
	string word;  // variables of the class
	string type;
	string definition;
	vector<Word>anagrams;

public:
	Word(string, string, string) ;
	// funtion members
	//Word(const string& w) : word(w) {}
	Word() {} // creating a constructor
	 //void prinDefinitions(); 
	 void setWord(string);
	 void setType(string);
	 void setDefinitions(string);
	 const string& getWord()const;
	 const string& getType()const;
	 const string& getDefinition()const;
};
//constructor
Word::Word(string Word, string Type, string Definition){
	this->word = Word;
	this->type = Type;
	this->definition = Definition;

}

ostream& operator<<(ostream& out, const Word& word) { // print word name and word type and word definition
	out << "Word Name: " << word.word << endl;
	if (word.type == "n") {
		out << "Word Type: " << "[noun]" << endl;
	}
	else if (word.type == "v") {
		out << "Word Type: " << "[verb]" << endl;
	}
	else if (word.type == "adv") {
		out << "Word Type: " << "[adverb]" << endl;
	}
	else if (word.type == "adj") {
		out << "Word Type: " << "[adjective]" << endl;
	}
	else if (word.type == "prep") {
		out << "Word Type: " << "[preposition]" << endl;
	}
	else if (word.type == "misc") {
		out << "Word Type: " << "[miscellaneous]" << endl;
	}
	else if (word.type == "pn") {
		out << "Word Type: " << "[proper noun]" << endl;
	}
	else if (word.type == "n_and_v") {
		out << "Word Type: " << "[noun and verb]" << endl;
	}
	out << "Word Definition: " << word.definition << endl;
	return out;
}

void Word::setWord(string set_word) { // set getter and setters for word class
	word = set_word;
}

void Word::setType(string set_type) {
	type = set_type;
}
void Word::setDefinitions(string set_definition) {
	definition = set_definition;
}
const string& Word::getWord() const  {
	return word;
}

const string& Word::getType()const {
	return type;

}
const string& Word::getDefinition()const{
	return definition;
}

class Noun : public Word {
public:
	Noun(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		
	}
	
};

class Verb : public Word {
public:
	Verb(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		
	}
	
};
class Adverb : public Word {
public:
	Adverb(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		
	}
	
};
class Adjective: public Word {
public:
	Adjective(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		// Additional initialization for Verb class
	}
	// ...
};
class Preposition: public Word {
public:
	Preposition(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		// Additional initialization for Verb class
	}
	// ...
};
class Miscellaneous : public Word {
public:
	Miscellaneous(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		// Additional initialization for Verb class
	}
	// ...
};
class ProperNoun : public Word {
public:
	ProperNoun(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		// Additional initialization for Verb class
	}
	// ...
};
class NounAndVerb : public Word {
public:
	NounAndVerb(const string& word, const string& type, const string& definition) : Word(word, type, definition) {
		// Additional initialization for Verb class
	}
	// ...
};



#endif // !WORD_H