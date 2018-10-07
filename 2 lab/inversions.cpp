#include <vector>
#include <fstream>
using namespace std;

long long int merge(vector<int> &buf, int temp[], int left, int middle, int right)
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

	long long int count = 0;
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			temp[k] = L[i];
			i++;
		}
		else
		{
			temp[k] = R[j];
			j++;
			count = count + n1 - i;
		}
		k++;
	}

	while (i < n1)
	{
		temp[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		temp[k] = R[j];
		j++;
		k++;
	}
	return count;
}

long long int mergeSort(vector<int> &buf, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		long long int count1 = mergeSort(buf, left, middle);
		long long int count2 = mergeSort(buf, middle + 1, right);
		int *temp = new int[right + 1];
		long long int count3 = merge(buf, temp, left, middle, right);
		for (int x = left; x <= right; x++)
		{
			buf[x] = temp[x];
		}
		delete[] temp;
		return count1 + count2 + count3;
	}
	else
	{
		return 0;
	}
}

int main()
{

	fstream fs;
	fs.open("inversions.in", fstream::in);

	vector<int> buf;
	int var, size;
	fs >> size;

	for (int i = 0; i < size; i++)
	{
		fs >> var;
		buf.push_back(var);
	}
	fs.close();

	long long int iterator = mergeSort(buf, 0, size - 1);

	fs.open("inversions.out", fstream::out);

	fs << iterator << endl;

	fs.close();

	return 0;
}
