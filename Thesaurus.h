#ifndef Thesaurus_h
#define Thesaurus_h

#include <iostream>
#include <fstream>
#include <map>
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
	char line[101];
	std::ifstream fin(filename.c_str());
	while(fin.getline(line, 100))
		std::cout << line << std::endl;
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

Thesaurus::~Thesaurus(){
	std::ofstream fout(filename.c_str());
	std::map<std::string, Word>::iterator it;
	for(it = c2e.begin(); it != c2e.end(); it ++){
		fout << "- ";
		fout << it->second.chinese << std::endl;
		fout << it->second.english << std::endl;
	}
}

#endif

