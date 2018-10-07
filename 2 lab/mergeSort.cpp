#include <vector>
#include <fstream>
using namespace std;

void merge(vector<int> &buf, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	vector<int> L;
	vector<int> R;

	for (i = 0; i < n1; i++)
	{
		L.push_back(buf[left + i]);
	}
	for (i = 0; i < n2; i++)
	{
		R.push_back(buf[middle + 1 + i]);
	}

	i = 0; 
	j = 0; 
	k = left; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			buf[k] = L[i];
			i++;
		}
		else
		{
			buf[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		buf[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		buf[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int> &buf, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(buf, left, middle);
		mergeSort(buf, middle + 1, right);

		merge(buf, left, middle, right);
	}
}

int main()
{
	int SIZE, var, i;
	fstream fs;
	fs.open("sort.in", fstream::in);
	fs >> SIZE;

	vector<int> buf;

	for (i = 0; i < SIZE; i++)
	{
		fs >> var;
		buf.push_back(var);
	}

	fs.close();

	mergeSort(buf, 0, buf.size() - 1);


	fs.open("sort.out", fstream::out);

	for (i = 0; i < SIZE; i++)
	{
		fs << buf[i] << " ";
	}

	return 0;
}
