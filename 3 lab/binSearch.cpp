#include <fstream>
#include <vector>
using namespace std;

int rBinSearch(int arr[], int key, int size)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		int mid = (right + left) / 2 + 1;
		if (key >= arr[mid]) 		
		{
			left = mid; 	
		}
		else 		
		{
			right = mid - 1;	 
		}
	}
	if (arr[left] == key) { return left; }
	else { return -1; }
}

int lBinSearch(int arr[], int key, int size)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (key <= arr[mid]) 	
		{
			right = mid;  		
		}
		else 	
		{
			left = mid + 1;		
		}
	}
	if (arr[left] == key) { return left; }
	else { return -1; }
}

int main()
{
	fstream fopen;
	fopen.open("binsearch.in", fstream::in);

	int sizeOfArr;
	fopen >> sizeOfArr;

	int *ptrArr = new int[sizeOfArr];
	for (int i = 0; i < sizeOfArr; i++)
	{
		int var;
		fopen >> var;
		ptrArr[i] = var;
	}
	int sizeOfRequest;
	fopen >> sizeOfRequest;

	fstream fclose;
	fclose.open("binsearch.out", fstream::out);

	for (int k = 0; k < sizeOfRequest; k++)
	{
		int key;
		fopen >> key;
		int first = lBinSearch(ptrArr, key, sizeOfArr);
		int last = rBinSearch(ptrArr, key, sizeOfArr);

		if (first != -1)
		{
			first++;
			last++;
		}
		fclose << first;
		fclose << " ";
		fclose << last << endl;
	}

	delete[] ptrArr;
	fopen.close();
	fclose.close();

	return 0;
}