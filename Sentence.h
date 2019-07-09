#ifndef Sentence_h
#define Sentence_h

#include <iostream>

class Sentence {
public:
	std::string question;
	std::string answer;
	
	Sentence(std::string);
	~Sentence();
};

#endif 
