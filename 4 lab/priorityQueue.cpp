#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

class PriorityQueue 
{
private:
	struct data
	{
		int value;
		int counter;
	};

	int it;
	int counter_push;
	data *pQueue;
	int size;

public:

	PriorityQueue()
	{
		counter_push = 0;
		it = 0;
		size = 10;
		pQueue = new data[size];
	}

	void set_counter_push() 
	{
		this->counter_push++;
	}

	void push(int value)
	{
		if (it == size) 
		{
			resize_data();
		}
		pQueue[it].value = value;
		pQueue[it].counter = counter_push;
		++it;
	}

	bool check_empty()
	{
		if (it == 0) 
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}

	void resize_data()
	{
		size = 2 * size;
		data *temp = new data[size];
		for (int i = 0; i < this->it; ++i)
		{
			temp[i] = pQueue[i];
		}
		data *temp_2 = pQueue;
		this->pQueue = temp;
		delete[] temp_2;
	}

	int extract_min()
	{
		int temp_min = pQueue[0].value;
		int i_temp = 0;
		for (int i = 0; i < it; ++i)
		{
			if (pQueue[i].value < temp_min)
			{
				temp_min = pQueue[i].value;
				i_temp = i;
			}
		}

		for (int j = i_temp; j < it - 1; ++j)
		{
			pQueue[j] = pQueue[j + 1];
		}
		--it;
		return temp_min;
	}

	void decrease_key(int x, int y) 
	{
		for (int i = 0; i < it; ++i) 
		{
			if (pQueue[i].counter == x) 
			{
				pQueue[i].value = y;
				break;
			}
		}
	}

	~PriorityQueue()
	{
		delete[] pQueue;
	}
};

int main() 
{
	string str;
	PriorityQueue pQueue;

	ifstream is("priorityqueue.in");
	ofstream os("priorityqueue.out");

	while (is >> str)
	{
		pQueue.set_counter_push();

		if (str == "push")
		{
			long long value;

			is >> value;
			pQueue.push(value);
		}
		if (str == "extract-min")
		{
			if (pQueue.check_empty())
			{

				os << '*' << "\n";
			}
			else
			{
				os << pQueue.extract_min() << "\n";
			}
		}
		if (str == "decrease-key")
		{
			int it;
			long value;
			is >> it >> value;
			pQueue.decrease_key(it, value);
		}
	}

	is.close();
	os.close();

	return 0;
}