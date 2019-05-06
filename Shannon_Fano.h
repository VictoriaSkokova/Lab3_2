#pragma once
#include "LinkedList.cpp"
#include "Mapp.cpp"
#include <iostream>

using namespace std;
class Shen_Fano_code
{
private:
	string  code, decode_;
	List <char> sort;
	Map < char> Map;

public:
	Shen_Fano_code(string&);
	~Shen_Fano_code() { sort.clear(); Map.clear(); };
	void encode(string &str);
	void decode();
	void get_table();
	bool code_compare_for_test(string check_array, string code);
	string get_code_for_tests() { return code; }
	string get_codes_list_for_tests(size_t index) { return sort.get_code_list(index); }
	char get_alphabet_list_for_tests(size_t index) { return sort.get_alphabet_list(index); }
	size_t get_freq_list_for_tests(size_t index) { return sort.get_freq_list(index); }
	string get_decode_for_tests() { return decode_; }

};
