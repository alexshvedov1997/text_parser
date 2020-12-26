#pragma once
#include <string>
class GreaterThan {
public:
	GreaterThan(int value = 6) :_val(value){}
	bool operator()(const std::string & str){
		return str.size() > _val;
	}
private:
	int _val;
};
