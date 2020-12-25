#include "read_text_parse.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>


namespace TextOperation{

text_parser::text_parser(const std::string & path) {
	std::string str = open_file( path); 
	delete_punctuations_mark(str);
	std::cout << "Success \n" << std::endl;
	parse_string(str);
	for (std::string s : vocaburary_word)
		std::cout << s << std::endl;
}

std::string text_parser::open_file(const std::string& path) {
	std::ifstream file;
	file.open(path, std::ios_base::in | std::ios_base::binary);
	if (!file.is_open()) {
		std::cerr << "Can't open file name = " << path << std::endl;
		return NULL;
	}
	std::stringstream str;
	str << file.rdbuf();
	return str.str();
 }

void text_parser::delete_punctuations_mark( std::string& str) {
	using std::string;
	char str_punc[] = { '.',',','!', '!', ':', '?' };
	//std::vector<std::string> remove_words(str_punc, str_punc + 5);
	//std::vector<std::string>::iterator it = remove_words.begin();
	
	for (int i = 0; i < (strlen(str_punc) -1) ; i++) {
		remove(str.begin(), str.end(), str_punc[i] );
	}
	size_t pos = 0;
	
	while ((pos =  str.find_first_of("\n", pos)) <= str.length()) {
		str.insert(pos+1, " ");
		 pos++;
	}

	remove(str.begin(), str.end(), '\n');
	remove(str.begin(), str.end(), '\r');
	std::cout << str << std::endl;

}

void text_parser::parse_string(const std::string& str) {
	using namespace std;
	stringstream stream(str);
	string newStr = NULL;
	while (stream >> newStr)
		vocaburary_word.push_back(newStr);
}
}











