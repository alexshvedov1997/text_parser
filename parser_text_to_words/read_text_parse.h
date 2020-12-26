#pragma once
#include <string>
#include <vector>

namespace TextOperation {
	class text_parser {
	public:
		text_parser(const std::string& path);
		void make_unique( std::vector<std::string> & str);
		void print_vector(const std::vector<std::string> vec);
		int count_word_more_than(const std::vector<std::string>& vec);
		std::vector<std::string> delete_words(std::vector<std::string> str, const std::vector<std::string>&);
	private:
		std::string open_file(const std::string& path);
		void delete_punctuations_mark(std::string& str);
		std::vector<std::string> vocaburary_word;
		void parse_string(const std::string&);
	};
}
