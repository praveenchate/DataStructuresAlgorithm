#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void changeArr(int arr[], int n, int i)
{
    if (i == n)
    {
        printArr(arr, n);
        return;
    }
    arr[i] = i + 1;
    changeArr(arr, n, i + 1);
    arr[i] = arr[i] - 2;
}

void printSubsets(string str, string subsets)
{

    if (str.size() == 0)
    {
        cout << subsets << "\n";
        return;
    }
    char ch = str[0];
    // yes choice
    printSubsets(str.substr(1, str.size() - 1), subsets + ch);

    // no choice
    printSubsets(str.substr(1, str.size() - 1), subsets);
}

// Sum of the subsets
void sumOfSubsets(int i, vector<int> &arr, int sum, int N, vector<int> &sumSubsets)
{

    // Base Case
    if (i == arr.size())
    {
        sumSubsets.push_back(sum);

        return;
    }

    // Pick the element
    sumOfSubsets(i + 1, arr, sum + arr[i], N, sumSubsets);

    // Donot pick the element
    sumOfSubsets(i + 1, arr, sum, N, sumSubsets);
}

void permutations(string str, string ans)
{

    int n = str.size();
    if (str.size() == 0)
    {
        cout << ans << "\n";
    }

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1, n - i - 1);
        permutations(nextStr, ans + ch);
    }
}

// void pm(string str, string ans)
// {

//     // Base case
//     if(str.size()==0){
//         cout<<ans<<"\n";
//     }

//     // use for loop to iterate over the string
//     int n = str.size();
//     for (int i = 0; i < str.size(); i++)
//     {
//         char ch = str[i];
//         string nextstr = str.substr(0, i) + str.substr(i + 1, n - 1 - i);
//         pm(nextstr, ans + ch);
//     }
// }

int main()
{
    // int arr[5] = {0};
    // int n = 5;
    // changeArr(arr, n, 0);
    // cout << endl;
    // printArr(arr, n);
    string str = "abc";
    string subset = "";
    printSubsets(str, subset);
    // string str = "abc";
    // string ans = "";
    // permutations(str, ans);
    // vector<int> arr = {3, 1, 2};
    // vector<int> sumSubsets = {};
    // int N = arr.size();
    // sumOfSubsets(0, arr, 0, N, sumSubsets);
    // std::sort(sumSubsets.begin(),sumSubsets.end());
    // for (int i = 0; i < sumSubsets.size(); i++)
    // {
    //     cout << sumSubsets[i] << " ";
    // }

    return 0;
}