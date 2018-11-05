#include <fstream>
using namespace std;

class stack
{
private:
	int top = 0;
	int *elements;

public:
	stack(const int size)
	{
		elements = new int[size];
	}
	void push(const int number)
	{
		elements[top++] = number;
	}
	int pop()
	{
		return elements[--top];
	}
	~stack()
	{
		delete[] elements;
	}
};

int main()
{
	int size;
	int var;
	char command;

	ifstream is;
	ofstream os;
	is.open("stack.in");
	os.open("stack.out");
	is >> size;

	stack myStack(size);

	for (int i = 0; i < size; i++)
	{
		is >> command;

		if (command == '+')
		{
			is >> var;
			myStack.push(var);
		}
		else if (command == '-' && i > 0)
		{
			os << myStack.pop() << endl;
		}
	}

	is.close();
	os.close();


	return 0;
}