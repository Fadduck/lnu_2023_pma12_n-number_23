#include <iostream>
using namespace std;
int createsquarematrix_getnormofmatrix(int n)
{
    int** pArray;
    pArray = new int* [n];
    int* fArray;
    fArray = new int[n];
    for (int i = 0; i < n; i++)
    {
        pArray[i] = new int[n];
    }
    cout << "Enter elements " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> pArray[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << pArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        fArray[i] = 0;
    }
    int k = -1;
    for (int i = 0; i < n; i++)
    {
        k += 1;
        for (int j = 0; j < n; j++)
        {
            fArray[k] += pArray[i][j];
        }
    }
    int max = fArray[0];
    for (int i = 0; i < n; i++)
    {
        if (fArray[k] > max)
        {
            max = fArray[k];
        }
    }
    cout << "Norm of matrix is: " << max;
    return max;
}
int main()
{
    int n;
    cout << "Enter n for matrix1" << endl;
    cin >> n;
    int norm1 = createsquarematrix_getnormofmatrix(n);
    cout << endl;
    int m;
    cout << "Enter n for matrix2" << endl;
    cin >> m;
    int norm2 = createsquarematrix_getnormofmatrix(m);
    cout << endl;
    if (norm1 > norm2)
    {
        cout << "Norm of matrix1 is bigger than norm of matrix2";
    }
    if (norm2 > norm1)
    {
        cout << "Norm of matrix2 is bigger than norm of matrix1";
    }
    if (norm2 == norm1)
    {
        cout << "Norm of matrix1 is equal to norm of matrix2";
    }
}


