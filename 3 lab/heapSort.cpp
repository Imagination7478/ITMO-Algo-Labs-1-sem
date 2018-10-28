#include <fstream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int size, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < size && arr[l] > arr[largest])
	{
		largest = l;
	}

	if (r < size && arr[r] > arr[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		heapify(arr, size, largest);
	}
}

void heapSort(vector<int> &arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

int main()
{
	fstream fs;
	fs.open("sort.in", fstream::in);

	int size;
	fs >> size;

	vector<int> arr;
	for (int i = 0; i < size; i++)
	{
		int var;
		fs >> var;
		arr.push_back(var);
	}

	fs.close();

	heapSort(arr, arr.size());

	fs.open("sort.out", fstream::out);

	for (int i = 0; i < size; i++)
	{
		fs << arr[i] << " ";
	}

	fs.close();

	return 0;
}