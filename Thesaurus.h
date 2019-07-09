#ifndef Thesaurus_h
#define Thesaurus_h

#include <iostream>
#include <fstream>
#include <map>
#include <string.h>
#include "Word.h"

class Thesaurus{
public:
	int words_number;
	std::string filename;
	std::map<std::string, Word> c2e;
	std::map<std::string, Word> e2c;
	
	Thesaurus();
	bool add_word(Word);       
	std::string get_word(std::string);
	bool delete_word(std::string);
	void print();
	~Thesaurus();
};

Thesaurus::Thesaurus() : words_number(0), filename("thesaurus.md") {
	char line[101];
	std::ifstream fin(filename.c_str());
	Word word;
	while(fin.getline(line, 100)){
		if(line[0] = '-'){
			strcpy(line, &line[2]);
			word.chinese = line;
			fin.getline(line, 100);
			word.english = line;
			c2e[word.chinese] = word;
		}
	}
}

bool Thesaurus::add_word(Word word){
	c2e[word.chinese] = word;
	e2c[word.english] = word;	
	return true;
}

std::string Thesaurus::get_word(std::string key){
	if (c2e.find(key) != c2e.end())
		return c2e[key].english;
	return "null";
}

bool Thesaurus::delete_word(std::string key){
	std::map<std::string, Word>::iterator it;
	if((it = c2e.find(key)) != c2e.end()){
		c2e.erase(it);
		return true;
	}
	return false;
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

