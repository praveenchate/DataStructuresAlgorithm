#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int st = 0;
    int end = numbers.size() - 1;
    vector<int> ans;

    while (st < end)
    {
        int currSum = numbers[st] + numbers[end];

        if (currSum == target)
        {
            // return {left + 1, right + 1};
            ans.push_back(st + 1);
            ans.push_back(end + 1);
            return ans;
        }
        else if (currSum > target)
        {
            end--;
        }
        else
        {
            st++;
        }
    }
    return ans; // If no solution is found return empty vector
}

int main()
{
    // vector<int> vec1 = {2, 7, 11, 15};
    // // cout << vec1.size();
    // vector<int> ans = twoSum(vec1, 9);
    // cout << "(" << ans[0] << "," << ans[1] << ")";

    // vector<int> vec1;
    // cout << "size: " << vec1.size() << endl;
    // cout << "capacity: " << vec1.capacity() << endl;

    // vec1.push_back(5);
    // cout << "size: " << vec1.size() << endl;
    // cout << "capacity: " << vec1.capacity() << endl;

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}