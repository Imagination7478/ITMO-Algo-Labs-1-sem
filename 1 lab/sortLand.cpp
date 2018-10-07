#include <fstream>
using namespace std;

int main()
{
	fstream fs;
	int SIZE;
	int minId, midId, maxId;

	double temp;

	fs.open("sortland.in", fstream::in);

	fs >> SIZE;

	double *ptrArr = new double[SIZE];
	double *ptrTempArr = new double[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		fs >> ptrArr[i];
		ptrTempArr[i] = ptrArr[i];
	}
	fs.close();

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (ptrTempArr[i] < ptrTempArr[j])
			{
				temp = ptrTempArr[i];
				ptrTempArr[i] = ptrTempArr[j];
				ptrTempArr[j] = temp;
			}
		}
	}
	
	int center = SIZE / 2;

	for (int i = 0; i < SIZE; i++)
	{
		if (ptrArr[i] == ptrTempArr[0])
		{
			minId = i + 1;
		}
		else if (ptrArr[i] == ptrTempArr[SIZE - 1])
		{
			maxId = i + 1;
		}
		else if (ptrArr[i] == ptrTempArr[center])
		{
			midId = i + 1;
		}
	}


	fs.open("sortland.out", fstream::out);

	fs << minId << " " << midId << " " << maxId;

	fs.close();





	for (int i = 0; i < SIZE; i++)
	{
		fs << ptrTempArr[i] << " ";
	}


	delete[] ptrArr;
	delete[] ptrTempArr;

	return 0;
}