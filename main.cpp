#include <iostream>
#include "Thesaurus.h"

int main() {
	Thesaurus thesaurus;
	Word word("����", "happy"); 
	thesaurus.add_word(word);
	word.set_word("����", "trash");
	thesaurus.add_word(word);
	thesaurus.print(); 
	return 0;
}
