#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fs;
	int SIZE;

	fs.open("smallsort.in", fstream::in);
	fs >> SIZE;

	int *ptrArr = new int[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		fs >> ptrArr[i];
	}
	fs.close();

	int temp;
	for (int i = 0; i < SIZE - 1; i++) 
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (ptrArr[j + 1] < ptrArr[j])
			{
				temp = ptrArr[j + 1];
				ptrArr[j + 1] = ptrArr[j];
				ptrArr[j] = temp;
			}
		}
	}

	fs.open("smallsort.out", fstream::out);
	for (int i = 0; i < SIZE; i++)
	{
		fs << ptrArr[i] << " ";
	}
	fs.close();

	delete[] ptrArr;

	return 0;
}