#include <fstream>
#include <vector>
using namespace std;


int binSearch (vector<int> arr, int left, int right, int key) 
{ 	
	int mid = 0; 	
	while (1) 	
	{ 		
		mid = (left + right) / 2; 		 		
		if (key < arr[mid]) // если искомое меньше значения в ячейке 		
		{
			right = mid - 1; // смещаем правую границу поиска 		
		}
		else if (key > arr[mid]) // если искомое больше значения в ячейке 			
		{
			left = mid + 1;	 // смещаем левую границу поиска 		
		}
		else // иначе (значения равны) 			
		{
			return mid; // функция возвращает индекс ячейки 		
		}
		if (left > right) // если границы сомкнулись 			
		{
			return -1; 
		}	
	} 
} 

int main()
{
	fstream fs;
	fs.open("binsearch.in", fstream::in);
	int sizeOfArr;
	fs >> sizeOfArr;
	
	vector<int> arr(sizeOfArr);
	for(int i = 0; i < sizeOfArr; i++)
	{
		fs >> arr[i];
	}
	
	int sizeOfRequest;
	fs >> sizeOfRequest;
	
	vector<int> arrOfRequest(sizeOfRequest);
	for(int i = 0; i < sizeOfRequest; i++)
	{
		fs >> arrOfRequest[i];
	}
	fs.close();
	
	for(int i = 0; i < sizeOfRequest; i++)
	{
		// binSearch(arr, 0, arr.size() - 1, arrOfRequest[i]);
		if(i == 0)
		{
			int first = binSearch(arr, 0, arr.size() - 1, arrOfRequest[i]);
		}
		else if(arr[i] == arr[i - 1])
		{
			int last = binSearch(arr, 0, arr.size() - 1, arrOfRequest[i]);
		}
		
	}
	
	
	
	return 0;
}
    