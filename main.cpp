#include <iostream>
#include "Thesaurus.h"

int main() {
	Thesaurus thesaurus;
	Word word("¿ªÐÄ", "happy"); 
	thesaurus.add_word(word);
	word.set_word("À¬»ø", "trash");
	thesaurus.add_word(word);
	thesaurus.print(); 
	return 0;
}
