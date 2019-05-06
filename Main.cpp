#include "Shannon_Fano.h"
#include <iostream>
#include <conio.h>

using namespace std;
void main()
{
	string quote = "Tout passe, tout casse, tout lasse";
	Shen_Fano_code cipher(quote);
	cout << "Line after coding:" << "\n";
	cipher.encode(quote);
	cout << "Line after decoding:" << "\n";
	cipher.decode();
	cout << "Table of codes:" << "\n";
	cipher.get_table();
	system("pause");
}