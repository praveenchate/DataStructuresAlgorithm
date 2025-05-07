#include <iostream>
#include <vector>
using namespace std;

void printName(int i, int n)
{
    // Base case
    if (i > n)
    {
        return;
    }
    cout << "Xhate" << endl;
    printName(i + 1, n);
}

void printLinear(int i, int n)
{
    // Base Case
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    printLinear(i + 1, n);
}

void descendingOrder(int i, int n)
{
    // Base case
    if (i < 1)
    {
        return;
    }
    cout << i << endl;
    descendingOrder(i - 1, n);
}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

void reverseArr(int arr[], int i, int n)
{
    // Base case
    if (i >= n / 2)
        return;

    swap(arr[i], arr[n - 1 - i]);
    reverseArr(arr, i + 1, n);
}

bool checkPalindrome(string s, int i, int n)
{
    // Base Case
    if (i >= n / 2)
    {
        return true;
    }
    if (s[i] != s[n - 1 - i])
    {
        return false;
    }

    return checkPalindrome(s, i + 1, n);
}

void printF(int i, int arr[], int n, vector<int> ds)
{

    // Base case
    if (i >= n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // first add element
    ds.push_back(arr[i]);
    // Pick the element
    printF(i + 1, arr, n, ds);
    // remove the element
    ds.pop_back();

    // again call the function for donot pick the element
    printF(i + 1, arr, n, ds);
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void permutations(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, vector<int> &freq)
{
    // base condition
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    // Real problem
    for (int i = 0; i < nums.size(); i++)
    {
        // Check for the frequency array
        if (!freq[i])
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            permutations(nums, ans, ds, freq);

            // Now remove element from ds
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

void printArr(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)//ans[i] signifies that 1st row or 2nd row .in 1st row print all the elements.
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // descendingOrder(5, 5);
    // cout << sum(5);
    // int arr[5] = {1, 3, 2, 5, 4};
    // int n = 5;
    // reverseArr(arr, 0, n);
    // printArr(arr, 5);
    // string s = "MADAM";
    // cout << checkPalindrome(s, 0, s.size());

    // int arr[] = {3, 1, 2};
    // int n = 3;
    // vector<int> ds;
    // printF(0, arr, n, ds);
    vector<vector<int>> ans;
    vector<int> ds;

    vector<int> nums = {1, 2, 3};
    vector<int> freq(nums.size(), 0);

    permutations(nums, ans, ds, freq);
    printArr(ans);
}