#include <iostream>
#include <vector>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;

    return (n * factorial(n - 1));
}

void print(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    print(n - 1);
}

int sumOfNnaturalNumbers(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumOfNnaturalNumbers(n - 1);
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

bool isSorted(int arr[], int n, int i)
{ // n is a size , i= it is the iterator for the array

    // Base Case
    if (i == n - 1)
    {
        return true; // Completiton of the array traversing
    }
    if (arr[i] > arr[i + 1])
    {
        return false;
    }
    isSorted(arr, n, i + 1);
}

int firsOccur(vector<int> arr, int i, int target)
{
    if (i == arr.size())
    {
        return -1;
    }
    if (arr[i] == target)
    {
        return i;
    }

    return firsOccur(arr, i + 1, target);
}

int power(int n, int pow)
{
    if (pow == 0)
    {
        return 1;
    }

    return n * power(n, pow - 1);
}

int pow(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int halfPower = pow(x, n / 2);
    int fullPower = halfPower * halfPower;

    if (n % 2 != 0)
    {
        return x * fullPower;
    }
    return fullPower;
}

int tilingProblem(int n)
{
    // base Case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // // vertical->2x(n-1)
    // int ans1 = tilingProblem(n - 1);
    // // horizontal->2x(n-2)
    // int ans2 = tilingProblem(n - 2);

    return tilingProblem(n - 1) + tilingProblem(n - 2);
}

void removeDuplicates(string str, string ans, int i, int map[26])
{
    // Base case
    if (i == str.size())
    {
        cout << ans;
        return;
    }
    char ch = str[i];
    int mapIdx = (int)(ch - 'a');

    if (map[mapIdx])
    { // if the string is duplicate
        removeDuplicates(str, ans, i + 1, map);
    }
    else
    {
        // if string is not duplicate
        map[mapIdx] = true;
        removeDuplicates(str, ans + str[i], i + 1, map);
    }
}

int friendsPair(int n)
{
    // Base Case
    if (n == 1 || n == 2)
    {
        return n;
    }
    return friendsPair(n - 1) + (n - 1) * friendsPair(n - 2);
}

void BinaryString(int n, int lastplace, string ans)
{
    // Base Case
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    if (lastplace != '1') // matlab ki 0
    {
        // lastplace 1 call function 2 time for 0 nad 1
        BinaryString(n - 1, '0', ans + '0');
        BinaryString(n - 1, '1', ans + '1');
    }
    else
    {
        // lastplace 0 call function 1 time for  0
        BinaryString(n - 1, '0', ans + '0');
    }
}

int binarySearch(vector<int> &arr, int start, int end, int key)
{
    // int start=0,end=arr.size()-1;

    // base Case
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    { // if key is found
        return mid;
    }
    else if (arr[mid] > key)
    { // Search in lower half
        return binarySearch(arr, 0, mid - 1, key);
    }
    else
    { // Search in right half
        return binarySearch(arr, mid + 1, end, key);
    }
}

void findallOccurences(int arr[], int i, int n, int key)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == key)
    {
        cout << i << " ";
    }
    findallOccurences(arr, i + 1, n, key);
}
int main()
{
    // int arr1[5] = {1, 2, 3, 4, 5};
    // int arr2[5] = {1, 2, 4, 3, 5};

    // vector<int> arr = {1, 2, 3, 4, 5, 6};
    string str = "appnnacollege";
    string ans = "";
    int map[26] = {false};
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};

    // vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    // int i = 0;
    // int end = arr.size() - 1;
    int key = 2;
    findallOccurences(arr, 0, n, key);
    // cout    << "The key " << key << " is found at index: " << binarySearch(arr, 0, end, key);

    // removeDuplicates(str, ans, 0, map);
    // cout << friendsPair(4);
    // BinaryString(4, 0, ans);
    // cout << isSorted(arr1, 5, 0);//Sorted:1
    // cout << isSorted(arr2, 5, 0); // Sorted:0
    // cout << firsOccur(arr, 0, 3);
    // cout << pow(2, 10);
    // cout << tilingProblem(5);
    // print(5);
}