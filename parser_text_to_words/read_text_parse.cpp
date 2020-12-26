#include "read_text_parse.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include "GreaterThan.h"


namespace TextOperation{

text_parser::text_parser(const std::string & path) {
	std::string str = open_file( path); 
	delete_punctuations_mark(str);
	std::cout << "Success \n" << std::endl;
	parse_string(str);
	//for (std::string s : vocaburary_word)
	//	std::cout << s << std::endl;
	make_unique(vocaburary_word);
	//print_vector(vocaburary_word);
	int size = count_word_more_than(vocaburary_word);
	std::cout << "Size = " << size << std::endl;
	std::string mass[] = { "a", "A", "and","if","If","or", "And" };
	std::vector<std::string> pattern(mass, mass + 6);
	std::vector<std::string> newStr =  delete_words(vocaburary_word, pattern);
	puts("New string ");
	print_vector(newStr);

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
	

}

void text_parser::make_unique( std::vector<std::string>& vec_str) {
	
	std::vector<std::string>::iterator it;
	it = std::unique(vocaburary_word.begin(), vocaburary_word.end());
	vec_str.erase(it, vec_str.end());

}

void text_parser::parse_string(const std::string& str) {
	using namespace std;
	stringstream stream(str);
	string newStr = "";
	while (stream >> newStr)
		vocaburary_word.push_back(newStr);

}

void text_parser::print_vector(const std::vector<std::string> vec) {
	for (std::string s : vec)
		std::cout << s << std::endl;
}

int text_parser::count_word_more_than(const std::vector<std::string>& vec) {
	int count = std::count_if(vec.begin(), vec.end(), GreaterThan());
	return count;
}

std::vector<std::string>  text_parser::delete_words(std::vector<std::string> str, const std::vector<std::string>& delete_string) {
	using namespace std;
	std::vector<std::string>::const_iterator it = delete_string.begin();
	for (; it != delete_string.end(); it++)
		str.erase(std::remove(str.begin(), str.end(), *it), str.end());
	vector<string> result(str.begin(), str.end());
	return result;
}

}













