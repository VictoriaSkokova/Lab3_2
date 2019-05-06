#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab3/Shannon_Fano.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Fano
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(encode_test_numbers)
		{
			string stri = "1234";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check = "10000111";
			Assert::AreEqual(check, str.get_code_for_tests());
		}

		TEST_METHOD(encode_test_quote)
		{
			string stri = "Tout passe, tout casse, tout lasse";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check = "1110111001000110101110010110000101011010100111100100011010111101011000010101101010011110010001101011111101100001010";
			Assert::AreEqual(check, str.get_code_for_tests());
		}

		TEST_METHOD(encode_test_two_words)
		{

			string stri = "aaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbb";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check = "1111111111111111100000000000000000000";
			Assert::AreEqual(check, str.get_code_for_tests());
		}


		TEST_METHOD(decode_test_numbers)
		{
			string stri = "1234";
			Shen_Fano_code str(stri);
			str.encode(stri);
			str.decode();
			Assert::AreEqual(stri, str.get_decode_for_tests());
		}

		TEST_METHOD(decode_test_quote)
		{
			string stri = "Tout passe, tout casse, tout lasse";
			Shen_Fano_code str(stri);
			str.encode(stri);
			str.decode();
			Assert::AreEqual(stri, str.get_decode_for_tests());
		}

		TEST_METHOD(decode_test_two_words)
		{

			string stri = "aaaaaaaaaaaaaaaaaabbbbbbbbbbbbb";
			Shen_Fano_code str(stri);
			str.encode(stri);
			str.decode();
			Assert::AreEqual(stri, str.get_decode_for_tests());
		}



		TEST_METHOD(test_quote_codes)
		{
			string stri = "Tout passe, tout casse, tout lasse";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check[12] = { "00", "010", "011","100","1010","1011","1100", "1101", "11100", "11101", "11110", "11111" };
			for (size_t i = 0; i < 12; i++) {
				Assert::AreEqual(check[i], str.get_codes_list_for_tests(i));
			}
		}

		TEST_METHOD(test_numb_codes)
		{

			string stri = "1234";
			Shen_Fano_code str(stri);
			str.encode(stri);
			string check[4] = { "00", "01", "10", "11" };
			for (size_t i = 0; i < 4; i++) {
				Assert::AreEqual(check[i], str.get_codes_list_for_tests(i));
			}
		}

		TEST_METHOD(test_frequency_for_same_frequency)
		{

			string stri = "Help";
			Shen_Fano_code str(stri);
			str.encode(stri);
			size_t check[4] = { 1, 1, 1, 1};
			for (size_t i = 0; i < 3; i++) {
				Assert::AreEqual(check[i], str.get_freq_list_for_tests(i));
			}
		}


		TEST_METHOD(test_frequency_for_different_frequency)
		{

			string stri = "pomogite pojaluista";
			Shen_Fano_code str(stri);
			str.encode(stri);
			size_t check[13] = { 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
			for (size_t i = 0; i < 12; i++) {
				Assert::AreEqual(check[i], str.get_freq_list_for_tests(i));
			}
		}

		TEST_METHOD(test_quote_alphabet)
		{
			string stri = "Tout passe, tout casse, tout lasse";
			Shen_Fano_code str(stri);
			str.encode(stri);
			char check[12] = { 's', ' ', 't', 'u', 'e' ,'a', 'o', ',', 'p', 'T', 'c', 'l' };
			for (size_t i = 0; i < 2; i++) {
				Assert::AreEqual(check[i], str.get_alphabet_list_for_tests(i));
			}
		}

		TEST_METHOD(test_numb_alphabet)
		{

			string stri = "1234";
			Shen_Fano_code str(stri);
			str.encode(stri);
			char check[4] = { '2', '3', '1', '4' };
			for (size_t i = 0; i < 4; i++) {
				Assert::AreEqual(check[i], str.get_alphabet_list_for_tests(i));
			}
		}
	};
}