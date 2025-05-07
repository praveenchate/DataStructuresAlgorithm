#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void countingSort(int arr[], int n)
{
    int freq[100000];
    int minVal = INT16_MAX;
    int maxVal = INT16_MIN;

    for (int i = 0; i < n; i++)
    {
        // frequency(arr[i])++;
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    // cout << maxVal << " " << minVal;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = minVal, j = 0; i <= maxVal; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << freq[i] << " ";
    // }
}
void bubbleSort(int *arr, int n)
{
    // Descending Order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // for (int i = n - 1; i >= 0; i++)
    // {
    //     for (int j = 0; j <= i - 1; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             swap(arr[j], arr[j + 1]);
    //         }
    //     }
    // }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i; j < n; j++)
        {
            if (arr[minIdx] < arr[j])
            {
                minIdx = j;
            }
        }
        swap(arr[minIdx], arr[i]);
    }
}

void InsertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{
    // int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    // int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int arr[] = {3, 2};
    // return 0;
    int n = sizeof(arr) / sizeof(int);
    // cout << n;
    // countingSort(arr, n);
    // bubbleSort(arr, n);
    InsertionSort(arr, n);
    printArr(arr, n);
}
