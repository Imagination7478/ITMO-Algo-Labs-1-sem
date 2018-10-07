#include <fstream>
#include <vector>
using namespace std;

static int i = 0, j = 0;
void partition(vector<int> &arr, int &l, int &r)
{
	int k = (l + r) / 2;
	int key = arr[k];
	i = l;
	j = r;

	while (i <= j) 
	{
		while (arr[i] < key)
			i++;
		while (key < arr[j])
			j--;

		if (i <= j) 
		{
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			i++;
			j--;
		}
	}
}

int kElement(vector<int> &arr, int l, int r, int k) 
{

	if (r < l)
	{
		return arr[l];
	}

	partition(arr, l, r);

	if (j + 1 <= k && k <= i - 1) 
	{
		return arr[j + 1];
	}
	else if (l <= k && k <= j) 
	{
		return kElement(arr, l, j, k);
	}
	else 
	{
		return kElement(arr, i, r, k);
	}
}

int main()
{
	fstream fs;
	fs.open("kth.in", fstream::in);

	int n, k;
	fs >> n >> k; 
	--k;
	
	int A, B, C;
	fs >> A >> B >> C;

	vector<int> arr(n);
	fs >> arr[0];
	fs >> arr[1];
	fs.close();

	for (int i = 2; i < n; i++)
	{
		arr[i] = A * arr[i - 2] + B * arr[i - 1] + C;
	}

	int result = kElement(arr, 0, arr.size() - 1, k);

	fs.open("kth.out", fstream::out);
	fs << result;
	fs.close();
	return 0;
}