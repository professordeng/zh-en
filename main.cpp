#include <iostream>
#include "Thesaurus.h"

int main() {
	std::string question;
	Thesaurus thesaurus;
	Word word;
	int choice;
	while(1){
		std::cout << "1.���Ҵʻ㣬2.��Ӵʻ㣬3.����ʿ�" << std::endl;
		std::cout << "you choice : " ;
		std::cin >> choice;
		if(choice == 0) break;
		if(choice == 1){
			std::cin >> question;
			std::cout << thesaurus.get_word(question) << std::endl;
		} 
		else if(choice == 2){
			std::cin >> question;
			word.chinese = question;
			std::cin >> word.english;
			thesaurus.add_word(word);
		}
		else if(choice == 3){
			thesaurus.print();
		}
		else{
			std::cout << "�����������������룡" << std::endl;
			// ��������Ǻͻ�������������ѭ�� 
			std::cin.clear();   
			std::cin.sync(); 
		}
	}
	return 0;
}
