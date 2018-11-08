#include <fstream>
using namespace std;

class queue
{
private:
	int head = 0;
	int tail = 0;
	int *elements;

public:
	queue(const int size)
	{
		elements = new int[size];
	}

	void push(int var)
	{
		elements[tail++] = var;
	}

	int pop()
	{
		return elements[head++];
	}

	~queue()
	{
		delete[] elements;
	}
};

int main()
{
	ifstream is;
	ofstream os;
	is.open("queue.in");
	os.open("queue.out");

	int size;
	is >> size;

	int var;
	char command;
	queue myQueue(size);

	for (int i = 0; i < size; i++)
	{
		is >> command;
		if (command == '+')
		{
			is >> var;
			myQueue.push(var);
		}
		else if (command == '-' && i > 0)
		{
			os << myQueue.pop() << endl;
		}
	}

	return 0;
}