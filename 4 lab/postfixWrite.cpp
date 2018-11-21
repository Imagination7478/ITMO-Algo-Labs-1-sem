#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

class Stack 
{
private:
	int size;
	int* elements;
	int top;

public:

	Stack() 
	{
		size = 10;
		top = 0;
		elements = new int[size];
	}

	void push_back(int Value) 
	{
		if (top == size)
		{
			resize();
		}
		elements[top] = Value;
		++top;
	}

	void resize()
	{
		size = 2 * size;
		int *temp = new int[size];
		for (int i = 0; i < top; ++i)
		{
			temp[i] = elements[i];
		}
		delete[] elements;
		elements = temp;
	}

	int eraseAndGet() 
	{
		int temp = elements[--top];
		return temp;
	}

	int getLast() 
	{
		return elements[top - 1];
	}

	int getSize() 
	{
		return top;
	}

	~Stack()
	{
		delete[] elements;
	}
};


int main() 
{
	ifstream is("postfix.in");
	ofstream os("postfix.out");

	Stack stack;
	char symbol;

	is >> symbol;

	while (symbol != EOF) 
	{
		if (symbol == '+' || symbol == '-' || symbol == '*') 
		{
			if (stack.getSize() > 1)
			{
				switch (symbol)
				{
					case '+':
					{
						stack.push_back(stack.eraseAndGet() + stack.eraseAndGet());
						break;
					}
					case '-':
					{
						int temp = stack.eraseAndGet() - stack.eraseAndGet();
						temp = -temp;
						stack.push_back(temp);
						break;
					}
					case '*':
					{
						stack.push_back(stack.eraseAndGet() * stack.eraseAndGet());
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			stack.push_back(symbol - '0');
		}
		is >> symbol;
	}

	os << stack.getLast();

	is.close();
	os.close();

	return 0;
}