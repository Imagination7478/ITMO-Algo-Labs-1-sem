#include <fstream>
#include <string>
using namespace std;

class Stack 
{
private:
	char* elements;
	int top;
	int size;

public:
	Stack() 
	{
		size = 10;
		top = 0;
		elements = new char[size];
	}

	void pushBack(int Value) 
	{
		if (top == size)
		{
			resize();
		}
		elements[top] = Value;
		++top;
	}

	char popAndGet() 
	{
		int temp = elements[--top];
		return temp;
	}

	char GetLast() 
	{
		return elements[top - 1];
	}

	void resize()
	{
		size = 2 * size;
		char *temp = new char[size];
		for (int i = 0; i < top; ++i)
		{
			temp[i] = elements[i];
		}
		delete[] elements;
		elements = temp;
	}

	bool isEmpty() 
	{
		if (top == 0)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	~Stack()
	{
		delete[] elements;
	}
};

int main() 
{
	ifstream is("brackets.in");
	ofstream os("brackets.out");

	string str;

	while (getline(is, str))
	{
		Stack stack;
		bool itIsTrue = true;
		for (int i = 0; i < str.size(); ++i)
		{
			if ((str[i] == ')' || str[i] == ']') && !stack.isEmpty())
			{
				if ((str[i] == ')' && stack.GetLast() == '(') || (str[i] == ']' && stack.GetLast() == '[')) 
				{
					stack.popAndGet();
					continue;
				}
				else 
				{
					itIsTrue = false;
					break;
				}
			}
			else 
			{
				stack.pushBack(str[i]);
			}
		}
		if (itIsTrue && stack.isEmpty())
		{
			os << "YES\n";
		}
		else 
		{
			os << "NO\n";
		}
	}

	is.close();
	os.close();
	return 0;
}