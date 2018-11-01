#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void countSort(string arr[], int t, int n)
{
	int i;
	int* count = new int[30];

	for (i = 0; i < 30; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		count[arr[i][t] - 'a']++;
	}

	for (i = 1; i < 30; i++)
	{
		count[i] += count[i - 1];
	}

	string* temp = new string[n];

	for (i = n - 1; i >= 0; i--)
	{
		temp[count[arr[i][t] - 'a'] - 1] = arr[i];
		count[arr[i][t] - 'a']--;
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
}

void radixSort(string a[], int k, int m, int n)
{
	for (int i = 0; i < k; i++)
	{
		countSort(a, m - 1 - i, n);
	}
}

int main()
{
	int i, n, m, k;

	fstream fs;
	fs.open("radixsort.in", fstream::in);

	fs >> n >> m >> k;

	string* arr = new string[n];

	for (i = 0; i < n; i++)
	{
		fs >> arr[i];
	}
	fs.close();

	radixSort(arr, k, m, n);

	fs.open("radixsort.out", fstream::out);
	for (i = 0; i < n; i++)
	{
		fs << arr[i] << endl;
	}
	fs.close();

	return 0;
}