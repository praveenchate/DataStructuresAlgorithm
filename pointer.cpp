#include <iostream>
using namespace std;

void printArr(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        // cout << *(ptr + i) << endl;
        cout << *ptr << endl;
        ptr = ptr + 1;
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5};
    int *ptr1 = arr;
    int *ptr2 = ptr1 + 3;

    cout << (ptr2 == ptr1);

    int n = sizeof(arr) / sizeof(int);
    // printArr(arr, n);
}