#include <iostream>
using namespace std;

void printSubArrays(int *arr, int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            // cout << "(" << start << ',' << end << ") ";
            for (int k = start; k <= end; k++)
            {
                cout << arr[k];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int maxSubArraySum1(int *arr, int n)
{
    int maxSum = INT16_MIN;
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int k = start; k <= end; k++)
            {
                currSum += arr[k];
            }
            // cout << currSum << ", ";
            maxSum = max(maxSum, currSum);
        }
        // cout << endl;
    }
    return maxSum;
}

int maxSubArraySum2(int *arr, int n)
{
    int maxSum = INT16_MIN;
    for (int start = 0; start < n; start++)
    {
        int currSum = 0;

        for (int end = start; end < n; end++)
        {
            // cout << currSum << ", ";
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
        // cout << endl;
    }
    return maxSum;
}

int kadanesAlgo(int *arr, int n)
{
    int currSum = 0;
    int maxSum = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return maxSum;
}

void returnmaxProduct(int *arr, int n)
{
    int maxProd = INT16_MIN;
    int currProd = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         int currProd = 1;
    //         for (int k = i; k <= j; k++)
    //         {
    //             maxProd = max(maxProd, currProd);
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        currProd *= arr[i];
        maxProd = max(maxProd, currProd);
        if (currProd == 0)
        {
            currProd = 1;
        }
    }
    cout << maxProd;
}

int main()
{
    int arr[4] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(int);
    // cout << n;
    // printSubArrays(arr, n);
    returnmaxProduct(arr, n);
}
