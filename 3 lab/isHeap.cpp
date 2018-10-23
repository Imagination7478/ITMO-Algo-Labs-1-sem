#include <fstream>
#include <vector>

static int k = 0;

bool isParent(vector<int> arr, int parent)
{
	indexOfFirstChild = 2 * parent;
	indexOfSecondChild = 2 * parent + 1;
	
	if (indexOfFirstChild >= arr.size())
	{
		
	}
	else if (indexOfSecondChild >= arr.size())
	{
		
	}
	else if (arr[indexOfFirstChild] > arr[parent] && arr[indexOfSecondChild] > arr[parent])
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
int main()
{
	fstream fs;
	fs.open("isheap.in", fstream::in);
	
	int size = 0, temp = 0;
	vector<int> arr;
	
	for(int i = 0; i < size; i++)
	{
		fs >> temp;
		arr.push_back(temp);
	}
	
	fs.close();
	
	for(int i = 0; i < size; i++)
	{
		if (isParent(arr, i)
		else 
		{
			fs.open("isheap.out", fstream::out);
			fs << "NO";
		}
	}
	
	
	return 0;
}