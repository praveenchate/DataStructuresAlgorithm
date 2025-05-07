#include <iostream>
using namespace std;

void spiralMatrix(int matrix[][4], int n, int m)
{
    int srow = 0, scol = 0;
    int erow = n - 1, ecol = m - 1;

    while (srow <= erow && scol <= ecol)
    {
        // top
        for (int j = scol; j <= ecol; j++)
        {
            cout << matrix[srow][j] << " ";
        }

        // right
        for (int i = srow + 1; i <= erow; i++)
        {
            cout << matrix[i][ecol] << " ";
        }

        // bottom
        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
            {
                break;
            }
            cout << matrix[erow][j] << " ";
        }

        // left
        for (int i = erow - 1; i >= srow + 1; i--)
        {
            if (scol == ecol)
            {
                break;
            }

            cout << matrix[i][scol] << " ";
        }

        srow++;
        scol++;
        erow--;
        ecol--;
    }
    cout << endl;
}

void diagonalSum(int matrix[][4], int n)
{
    int sum = 0;
    // O(Nsquare)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == j)
    //         {
    //             sum += matrix[i][j];
    //         }
    //         else if (j == n - i - 1)
    //         {
    //             sum += matrix[i][j];
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        if (i != n - i - 1)
        {
            sum += matrix[i][n - i - 1];
        }
    }
    cout << sum << endl;
}

bool searchSorted2DMatrix(int mat[][4], int n, int m, int key)
{
    // O(n+m)
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (key == mat[i][j])
        {
            cout << "Key found at cell (" << i << "," << j << ").";
            return true;
        }
        else if (mat[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "Key not found.";
    return false;
}

bool searchSorted2DMatrix1(int mat[][4], int n, int m, int key)
{
    // O(n+m)
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (key == mat[i][j])
        {
            cout << "Key found at cell (" << i << "," << j << ").";
            return true;
        }
        else if (mat[i][j] < key)
        {
            j++;
        }
        else
        {
            i--;
        }
    }
    cout << "Key not found.";
    return false;
}

int main()
{
    // int matrix[4][4] = {{1, 2, 3, 4},
    //                     {5, 6, 7, 8},
    //                     {9, 10, 11, 12},
    //                     {13, 14, 15, 16}};

    // // spiralMatrix(matrix, 4, 4);

    // diagonalSum(matrix, 4);
    // int matrix1[4][4] = {{1, 2, 3, 4},
    //                      {5, 6, 7, 8},
    //                      {9, 10, 11, 12}};
    // // spiralMatrix(matrix1, 3, 4);

    int matrix[4][4] = {{10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50}};
    searchSorted2DMatrix1(matrix, 4, 4, 35);
    return 0;
}