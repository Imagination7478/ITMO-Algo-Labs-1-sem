#include <fstream>
#include <vector>
using namespace std;

int main()
{
	fstream fs;
	fs.open("isheap.in", fstream::in);
	
	int size = 0, temp = 0;
	vector<int> arr;
	fs >> size;
	
	for(int i = 0; i < size; i++)
	{
		fs >> temp;
		arr.push_back(temp);
	}
	
	fs.close();
	
	fs.open("isheap.out", fstream::out);

	bool result = true;

	for(int i = size - 1; i > 0; i--)
	{
		if (i % 2 == 0)
		{
			if (arr[(i + 1) / 2 - 1] < arr[i])
			{
				result *= true;
			}
			else
			{
				result *= false;
			}
		}
		else
		{
			if (arr[(i + 1) / 2 - 1] < arr[i])
			{
				result *= true;
			}
			else
			{
				result *= false;
			}
		}

	}

	if (result)
	{
		fs << "YES";
	}
	else
	{
		fs << "NO";
	}

	fs.close();


	
	return 0;
}