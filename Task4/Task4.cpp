// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	int m;
	cout << "Enter size of matrix: " << endl;
	cin >> n;
	cin >> m;
	int** pArray;
	pArray = new int*[n];
	for (int i = 0; i < n; i++)
		pArray[i] = new int[m];
	cout << "Enter elements: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> pArray[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		k = 0;
		for (int j = 0; j < m; j++)
		{
			int a;
			a = pArray[i][0] - 1;
			if (pArray[i][j] > a)
			{
				k = k + 1;
				a = pArray[i][j];
			}
			else
				a = pArray[i][j];
		}
		if (k == m)
			cout << i + 1 << "lane" << endl;
		
	}
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
