#include <iostream>
using namespace std;

int maxProfit(int *arr, int n)
{
    int bestBuy[100000];
    int profit[n];
    bestBuy[0] = INT16_MAX;
    // cout << bestBuy[0] << " ,";
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i - 1], arr[i - 1]);
        // cout << bestBuy[i] << " ,";
    }
    int maxElement = profit[0];
    for (int i = 0; i < n; i++)
    {
        profit[i] = arr[i] - bestBuy[i];
        // cout << profit[i] << endl;
        if (profit[i] > maxElement)
        {
            maxElement = profit[i];
        }
    }

    // for (int i = 1; i < n; i++)
    // {

    // }

    return maxElement;
}

int maxProfit1(int *arr, int n)
{
    int bestBuy[100000];
    int profit[n];
    bestBuy[0] = INT16_MAX;
    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i - 1], arr[i - 1]);
        // cout << bestBuy[i] << " ,";
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currProfit = arr[i] - bestBuy[i];
        maxProfit = max(maxProfit, currProfit);
    }
    return maxProfit;
}

int trappingRainWater(int *height, int n)
{
    int leftmax[20000], rightmax[20000];
    leftmax[0] = height[0];
    // cout << leftmax[0] << " ,";

    // Finding the leftMax array
    for (int i = 1; i < n; i++)
    {
        leftmax[i] = max(leftmax[i - 1], height[i - 1]);
        // cout << leftmax[i] << " ,";
    }

    // Finding the Rightmax array
    rightmax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightmax[i] = max(rightmax[i + 1], height[i + 1]);
        // cout << rightmax[i] << " ,";
    }

    // current water=minimum of leftmax and rightmax of the array - height of the bars
    // after that add all the current values except the 0 and negative values.
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int currWater = min(leftmax[i], rightmax[i]) - height[i];
        if (currWater > 0)
        {
            waterTrapped += currWater;
        }
    }

    return waterTrapped;
}

int main()
{
    int heights[] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(int);
    trappingRainWater(heights, n);
}