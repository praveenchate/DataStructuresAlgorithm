#include <iostream>
using namespace std;

void calcSeven(int num[][3], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 7)
            {
                sum += 1;
            }
        }
    }
    cout << sum << endl;
}

int calcSum2ndRow(int nums[][3], int m)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum += nums[1][j];
    }

    return sum;
}

void transponseMatrix(int mat[][3], int n, int m)
{
    int trans[3][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            trans[i][j] = mat[j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
}

void print2dArr(int num[][2], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    // int arr[2][3] = {{4, 7, 8}, {8, 8, 7}};
    // calcSeven(arr, 2, 3);
    int nums[3][3] = {{1, 2, 3},
                      {4, 5, 6}};
    transponseMatrix(nums, 3, 3);
    // print2dArr(nums, 3, );

    return 0;
}
