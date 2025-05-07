#include <iostream>
using namespace std;

void largestElement(int arr[], int n)
{
   // int n = sizeof(arr) / sizeof(int);
   int max = arr[0];
   for (int i = 0; i < n; i++)
   {
      if (arr[i] > max)
      {
         max = arr[i];
         // cout << "Assigning the value=" << arr[i] << endl;
      }
   }
   cout << "Max Element =" << max << endl;
}

void printArr(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << ",";
   }
}

int main()
{
   int arr[] = {7, 9, 10, 13, 8, 4};
   int n = sizeof(arr) / sizeof(int);
   // printArr(arr, n);
   largestElement(arr, n);
   // int n = sizeof(arr) / sizeof(int);
   // int max = arr[0];

   // for (int i = 0; i < n; i++)
   // {
   //    if (arr[i] > max)
   //    {
   //       max = arr[i];
   //       cout << "Assigning the value=" << arr[i] << endl;
   //    }
   // }
   // cout << "Max Element =" << max << endl;
   // cout << arr << endl;
   // cout << *arr << endl;
   // cout << *(arr + 1) << endl;
   // cout << *(arr + 2) << endl;

   return 0;
}