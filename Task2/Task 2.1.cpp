// Task 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, h, k ;
	int number, dobutok;
	k = 0;
	number = 0;
	dobutok = 1;
	cout << "Enter a " << endl;
	cin >> a ;
	cout << "Enter b " << endl;
	cin >> b ;
	cout << "Enter h " << endl;
	cin >> h;

	for (float x = a; x <= b; x += h)
	{
		float y = cos(x) - 1;
		cout << x << "\t" << y << "\t" << k << endl;
		if (y > 0)
		{
			dobutok *= y;
			number += 1;
		}
	}
				
		cout <<"Number of igrikov " << number << endl;
		cout <<"Dobutok cifr " << dobutok << endl;
	
	return 0;
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
