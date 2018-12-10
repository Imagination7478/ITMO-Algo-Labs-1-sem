#include <fstream>
#include <string>
#include <vector>
#define _SIZE 1000000
using namespace std;

class List
{
public:
	List();
	void push_back(const long long data);
	void remove(const int data);
	int getSize() { return size; }
	bool Search(int x);

private:
	class Node
	{
	public:
		Node *pNext;
		long long data;
	};

	int size;
	Node *head;
};

List::List()
{
	head = new Node();
	head->data = LONG_MAX;
	head->pNext = nullptr;
	size = 0;
}

void List::push_back(const long long data)
{
	Node *NewNode = new Node;
	NewNode->data = data;
	NewNode->pNext = head->pNext;
	head->pNext = NewNode;
	size++;
}

void List::remove(const int data)
{
	Node *CurNode = head;
	while (CurNode->pNext != nullptr)
	{
		if (CurNode->pNext->data == data)
		{
			Node *NodeToDel = CurNode->pNext;
			CurNode->pNext = CurNode->pNext->pNext;
			delete NodeToDel;
			size--;
			return;
		}
		else
		{
			CurNode = CurNode->pNext;
		}
	}

}

bool List::Search(int x)
{
	Node *CurNode = head;
	while (CurNode->pNext != nullptr)
	{
		if (CurNode->pNext->data == x)
		{
			return true;
		}
		else
		{
			CurNode = CurNode->pNext;
		}
	}
	return false;
}


class Set
{
private:
	int key;
	vector<List> lst;

public:
	Set()
	{
		lst.resize(_SIZE);
	}

	int generateHash(const long long key)
	{
		int res = key % (int)lst.size();
		if (res < 0) res += lst.size();
		return res;
	}

	void insert(const long long var)
	{
		if (!exists(var)) 
			lst[generateHash(var)].push_back(var);
	}

	bool exists(const long long var)
	{
		return lst[generateHash(var)].Search(var);
	}

	void deleteHt(const long long var)
	{
		lst[generateHash(var)].remove(var);
	}
};



int main()
{
	ifstream is;
	ofstream os;

	string str;
	long long var;
	Set mySet;

	is.open("set.in");
	os.open("set.out");
	while (!(is.eof()))
	{
		is >> str;
		if (str == "insert")
		{
			is >> var;
			mySet.insert(var);
		}
		if (str == "exists")
		{
			is >> var;
			if (mySet.exists(var))
			{
				os << "true" << endl;
			}
			else
			{
				os << "false" << endl;
			}

		}
		if (str == "delete")
		{
			is >> var;
			mySet.deleteHt(var);
		}
		str = "";
	}

	is.close();
	os.close();

	return 0;
}
