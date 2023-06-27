#include <iostream>
using namespace std;

int main()
{
    int n;
    int k;
    cout << "Enter n for Matrix: " << endl;
    cin >> n;
    cout << "Enter size of frame: " << endl;
    cin >> k;
    int** pArray;
    pArray = new int* [n];

    for (int i = 0; i < n; i++)
    {
        pArray[i] = new int[n];
    }

    cout << "Enter elements of matrix: " << endl;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> pArray[i][j];
        }
    }

    cout << "Matrix: " << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << pArray[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Integers that are not in frame position are: ";
    for (int i = k; i < n - k; i++)
    {
        for (int j = k; j < n - k; j++)
        {
            cout << pArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
