#pragma once
#include <string>
#include <vector>

namespace TextOperation {
	class text_parser {
	public:
		text_parser(const std::string& path);

	private:
		std::string open_file(const std::string& path);
		void delete_punctuations_mark(std::string& str);
		std::vector<std::string> vocaburary_word;
		void parse_string(const std::string&);
	};
}
