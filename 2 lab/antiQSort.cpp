#include <vector>
#include <fstream>
using namespace std;

int main()
{
	fstream fs;
	fs.open("antiqs.in", fstream::in);
	int size;
	fs >> size;
	int *ptrArr = new int[size];

	if (size > 0) ptrArr[0] = 1;
	if (size > 1) ptrArr[1] = 2;
	fs.close();

	for (int i = 3; i <= size; i++)
	{
		int key = (i - 1) / 2;
		int t = ptrArr[key];
		ptrArr[key] = i;
		ptrArr[i - 1] = t;
	}

	fs.open("antiqs.out", fstream::out);
	for (int i = 0; i < size; i++)
	{
		fs << ptrArr[i] << " ";
	}

	delete[] ptrArr;
	fs.close();
	return 0;
}