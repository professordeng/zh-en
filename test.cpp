#include <iostream>
#include <fstream>

int main(){
	std::ifstream fin("thesaurus.md");
	std::string word;
	char line[101];
	if(fin.fail()){
		std::cout << "thesaurus.md no exist!" << std::endl;
		exit(1);
	}
	fin >> word;               // read a word
	std::cout << word << std::endl;  
	fin.getline(line, 100);    // read a line until length 100
	std::cout << line << std::endl;  
	fin.close();
	return 0;
}
