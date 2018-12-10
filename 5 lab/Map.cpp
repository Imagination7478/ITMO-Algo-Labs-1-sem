#include <fstream> 
#include <vector> 
#include <string> 
#define _SIZE 1000000
using namespace std;

struct Node
{
	string Key, Value;
	Node *Next;
};

class List
{
	Node *Start;
public:
	List();
	void InsertInList(string K, string V);
	void DeleteInList(string K);
	Node* SearchInList(string K);
};

List::List()
{
	Start = new Node();
	Start->Value = Start->Key = "";
	Start->Next = nullptr;
}

void List::InsertInList(string Key, string Value)
{
	Node *NewNode = SearchInList(Key);
	if (SearchInList(Key) == nullptr)
	{
		NewNode = new Node;
		NewNode->Key = Key;
		NewNode->Value = Value;
		NewNode->Next = Start->Next;
		Start->Next = NewNode;
	}
	else
	{
		NewNode->Value = Value;
	}
}

void List::DeleteInList(string K)
{
	Node *CurNode = Start;
	while (CurNode->Next != nullptr)
	{
		if (CurNode->Next->Key == K)
		{
			Node *NodeToDel = CurNode->Next;
			CurNode->Next = CurNode->Next->Next;
			delete NodeToDel;
			return;
		}
		else
		{
			CurNode = CurNode->Next;
		}
	}
}

Node* List::SearchInList(string Key)
{
	Node *CurNode = Start;
	while (CurNode->Next != nullptr)
	{
		if (CurNode->Next->Key == Key)
		{
			return CurNode->Next;
		}
		else
		{
			CurNode = CurNode->Next;
		}
	}
	return nullptr;
}

class Map
{
	vector<List> lst;
	int generateHash(string Key);
public:
	Map();
	void Insert(string Key, string Value);
	void Delete(string Key);
	string Search(string Key);
};

Map::Map()
{
	lst.resize(_SIZE);
}

int Map::generateHash(string Key)
{
	unsigned int res = 0, pow = 1, p = 31, s = lst.size();
	for (int i = 0; i < Key.length(); ++i)
	{
		res += (Key[i] - 'A') * pow;
		pow *= p;
	}
	return res % s;
}

void Map::Insert(string Key, string Value)
{
	lst[generateHash(Key)].InsertInList(Key, Value);
}

string Map::Search(string Key)
{
	Node *Res = lst[generateHash(Key)].SearchInList(Key);
	if (Res == nullptr)
		return "none";
	else
		return Res->Value;
}

void Map::Delete(string Key)
{
	lst[generateHash(Key)].DeleteInList(Key);
}

int main()
{
	ifstream fin("map.in");
	ofstream fout("map.out");
	Map myMap;
	string Command;
	while (fin >> Command)
	{
		string K, V;
		if (Command == "put")
		{
			fin >> K >> V;
			myMap.Insert(K, V);
		}
		else if (Command == "delete")
		{
			fin >> K;
			myMap.Delete(K);
		}
		else if (Command == "get")
		{
			fin >> K;
			fout << myMap.Search(K) << "\n";
		}
	}
	return 0;
}