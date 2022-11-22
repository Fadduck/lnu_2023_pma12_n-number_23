// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
#include <string> 
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	string word1;
	int pos1 = s.find(" ", 0);
	if (pos1 == -1)
		pos1 = s.find(".", 0);
	word1 = s.substr(0, pos1);

	int pos2;
	string word2;
	int slength = s.length();
	pos2 = s.rfind(" ", slength);
	word2 = s.substr(pos2 + 1, slength - pos2 - 2);

	string smid;
	smid = s.substr(pos1, slength - word1.length() - word2.length() - 1);

	if (smid != ".")
		s = word2 + smid + word1 + '.';
	cout << s << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
