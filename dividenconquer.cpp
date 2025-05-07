#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei)
{
    int i = si;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    // for the left over elements in the left and right half
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }

    // now copy these elements to the original array
    for (int idx = si, x = 0; idx <= ei; idx++)
    {
        arr[idx] = temp[x++]; // copying the elements from temp array to original array
    }
}

void mergeSort(int arr[], int si, int ei)
{
    // Base Case
    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;

    mergeSort(arr, mid + 1, ei); // left half
    mergeSort(arr, si, mid);     // Right half

    merge(arr, si, mid, ei); // conquer
}

int partition(int arr[], int si, int ei)
{
    int i = si - 1;
    int pivot = arr[ei];
    for (int j = si; j < ei; j++)
    {
        if (pivot > arr[j])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void QuickSort(int arr[], int si, int ei)
{
    // base Case
    if (si >= ei)
    {
        return;
    }

    int pivotIdx = partition(arr, si, ei);
    QuickSort(arr, si, pivotIdx - 1); // Left half
    QuickSort(arr, pivotIdx + 1, ei); // Right half
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search(int arr[], int si, int ei, int tar)
{
    // Base Case
    if (si > ei)
    {
        return -1;
    }
    // Calculate mid
    int mid = si + (ei - si) / 2;

    // if we find mid as target
    if (arr[mid] == tar)
    {
        return mid;
    }

    // check where mid lies
    if (arr[si] <= arr[mid])
    {
        // Line1
        if (arr[si] <= tar && tar <= arr[mid])
        {
            return search(arr, si, mid - 1, tar);
        }
        else
        {
            return search(arr, mid + 1, ei, tar);
        }
    }
    else
    {
        // Line2
        if (arr[mid] <= tar && tar <= arr[ei])
        {
            return search(arr, mid + 1, ei, tar);
        }
        else
        {
            return search(arr, si, mid - 1, tar);
        }
    }
}

int main()
{
    // int arr[6] = {6, 3, 7, 5, 2, 4};
    // int n = 6;
    // mergeSort(arr, 0, n - 1);
    // QuickSort(arr, 0, n - 1);
    // printArr(arr, n);
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;
    cout << "idx: " << search(arr, 0, n - 1, 4) << endl;
}