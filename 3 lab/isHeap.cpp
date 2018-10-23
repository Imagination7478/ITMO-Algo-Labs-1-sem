#include <fstream>
#include <vector>
using namespace std;

bool isParent(vector<int> arr, int parent)
{
	int indexOfFirstChild = 2 * parent + 1;
	int indexOfSecondChild = 2 * parent + 2;
	
	if (indexOfFirstChild >= arr.size())
	{}
	else if (indexOfSecondChild >= arr.size())
	{}
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
	fs >> size;
	
	for(int i = 0; i < size; i++)
	{
		fs >> temp;
		arr.push_back(temp);
	}
	
	fs.close();
	
	fs.open("isheap.out", fstream::out);
	for(int i = 0; i < size; i++)
	{
		if (isParent(arr, i))
		{}
		else 
		{
			fs << "NO";
			break;
		}
		if (i == size - 1) { fs << "YES"; }
	}
	fs.close();
	
	
	return 0;
}