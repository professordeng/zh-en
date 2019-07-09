#ifndef Thesaurus_h
#define Thesaurus_h

#include <iostream>
#include <map>
#include <fstream>
#include "Word.h"

class Thesaurus{
private:
	int words_number;
	std::string filename;
	std::map<std::string, Word> c2e;
	std::map<std::string, Word> e2c;
	
public:
	Thesaurus();
	bool add_word(Word);       
	Word get_word(std::string);
	void print();
	~Thesaurus();
};

Thesaurus::Thesaurus() 
	: words_number(0), filename("thesaurus.md") {
	
}

bool Thesaurus::add_word(Word word){
	c2e[word.chinese] = word;
	e2c[word.english] = word;	
	return true;
}

Word Thesaurus::get_word(std::string key){
	return c2e[key];
}

void Thesaurus::print(){
	std::map<std::string, Word>::iterator it;
	for(it = c2e.begin(); it != c2e.end(); it ++){
		it->second.print();
	}
}

Thesaurus::~Thesaurus(){}

#endif

