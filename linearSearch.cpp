#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int binarysearch(int *arr, int n, int key)
{
    int st = 0, end = n - 1;

    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            // 1st half search
            end = mid - 1;
        }
        else
        {
            // 2nd half search
            st = mid + 1;
        }
    }
    return -1;
}
//*arr
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(int);
    cout << binarysearch(arr, n, 16);
    // cout << *(arr + 2);

    // cout << linearSearch(arr, n, 20);
    // Reverse array
    // int copyArr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     int j = n - i - 1;
    //     copyArr[i] = arr[j];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = copyArr[i];
    // }
    // printArr(arr, n);
    // int start = 0, end = n - 1;
    // while (start < end)
    // {
    //     // swap(arr[start], arr[end]);
    //     int temp = arr[start];
    //     arr[start] = arr[end];
    //     arr[end] = temp;
    //     start++;
    //     end--;
    // }
    // printArr(arr, n);
    return 0;
}
