#include <iostream>
using namespace std;

void changeA(int *ptr)
{
    *ptr = 20;
    cout << *ptr << endl;
}

int main()
{
    // int a = 10;
    // int *ptr = &a;
    // changeA(ptr);
    // cout << a << endl;
    // cout << ptr << endl;
    // cout << &a << endl;
    // cout << *ptr << endl;
    // cout << *(&a) << endl;

    // *ptr = 20;
    // int &b = a;
    // b = 30;
    // cout << &b << endl
    //      << &a << endl;

    // int *ptr = &a;
    // cout << ptr << endl;
    // cout << *ptr;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    // printArr(arr, n);
}
