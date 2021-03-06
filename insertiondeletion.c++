#include <iostream>
using namespace std;
int insertSorted(int arr[], int n, int key, int capacity)
{
 if (n >= capacity)
 return n;
 int i;
 for (i = n - 1; (i >= 0 && arr[i] > key); i--)
 arr[i + 1] = arr[i];
 arr[i + 1] = key;
 return (n + 1);
}
int binarySearch(int arr[], int low, int high, int key);
int deleteElement(int arr[], int n, int key)
{
 int pos = binarySearch(arr, 0, n - 1, key);
 if (pos == -1)
 {
 cout << "Element not found";
 return n;
 }
 int i;
 for (i = pos; i < n - 1; i++)
 arr[i] = arr[i + 1];
 return n - 1;
}
int binarySearch(int arr[], int low, int high, int key)
{
 if (high < low)
 return -1;
 int mid = (low + high) / 2;
 if (key == arr[mid])
 return mid;
 if (key > arr[mid])
 return binarySearch(arr, (mid + 1), high, key);
 return binarySearch(arr, low, (mid - 1), key);
}
int main()
{
 int arr[20] = { 12, 16, 20, 40, 50, 70 };
 int capacity = sizeof(arr) / sizeof(arr[0]);
 int n = 6;
 int i, key = 26;
 cout<< "Array Before Insertion:- "<<endl;
 for (i = 0; i < n; i++)
 cout << arr[i] << " "<<endl;
 n = insertSorted(arr, n, key, capacity);
 cout << "Array After Insertion:- "<<endl;
 for (i = 0; i < n; i++)
 cout << arr[i]<< " "<<endl;
 cout << "Array before deletion:- "<<endl;
 for (i = 0; i < n; i++)
 cout << arr[i] << " "<<endl;
 n = deleteElement(arr, n, key);
 cout << "Array after deletion:- "<<endl;
 for (i = 0; i < n; i++)
 cout << arr[i] << " "<<endl;
 return 0;
}
