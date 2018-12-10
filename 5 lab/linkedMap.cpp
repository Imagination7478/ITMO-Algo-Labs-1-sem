#include <fstream> 
#include <vector> 
#include <string> 
#define _SIZE 100000
using namespace std;

struct Node
{
	string Key, Value;
	Node *NextInChain;
	Node *NextElem, *PrevElem;
};

class List
{
	Node *head;
public:
	List();
	void Insert(string K, string V, Node *Head);
	void Delete(string K, Node *Head);
	Node* Search(string K);
};

List::List()
{
	head = new Node();
	head->Value = head->Key = "";
	head->NextInChain = nullptr;
}

void List::Insert(string K, string V, Node *Head)
{
	Node *NewNode = Search(K);
	if (Search(K) == nullptr)
	{
		NewNode = new Node;
		NewNode->Key = K;
		NewNode->Value = V;
		NewNode->NextInChain = head->NextInChain;
		head->NextInChain = NewNode;

		Node *Tail = Head->PrevElem;
		Tail->NextElem = NewNode;
		Head->PrevElem = NewNode;
		NewNode->NextElem = Head;
		NewNode->PrevElem = Tail;
	}
	else
	{
		NewNode->Value = V;
	}
}

void List::Delete(string K, Node *Head)
{
	Node *CurNode = head;
	while (CurNode->NextInChain != nullptr)
	{
		if (CurNode->NextInChain->Key == K)
		{
			Node *NodeToDel = CurNode->NextInChain;
			CurNode->NextInChain = CurNode->NextInChain->NextInChain;
			Node *PrevNode = NodeToDel->PrevElem, *NextNode = NodeToDel->NextElem;
			NodeToDel->PrevElem->NextElem = NextNode;
			NodeToDel->NextElem->PrevElem = PrevNode;
			delete NodeToDel;
			return;
		}
		else
		{
			CurNode = CurNode->NextInChain;
		}
	}
}

Node* List::Search(string K)
{
	Node *CurNode = head;
	while (CurNode->NextInChain != nullptr)
	{
		if (CurNode->NextInChain->Key == K)
		{
			return CurNode->NextInChain;
		}
		else
		{
			CurNode = CurNode->NextInChain;
		}
	}
	return nullptr;
}

class LinkedMap
{
	vector<List> Src;
	Node *Head;
	int generateHash(string K);
public:
	LinkedMap();
	void Insert(string K, string V);
	void Delete(string K);
	string Search(string K);
	string Next(string K);
	string Prev(string K);
	void Print()
	{
		Node *CurNode = Head->NextElem;
		while (CurNode != Head)
		{
			CurNode = CurNode->NextElem;
		}
	}
};

LinkedMap::LinkedMap()
{
	Src.resize(_SIZE);
	Head = new Node;
	Head->NextElem = Head->PrevElem = Head;
	Head->Value = Head->Key = "HEAD";
}

int LinkedMap::generateHash(string K)
{
	unsigned int res = 0, pow = 1, p = 31, s = Src.size();
	for (int i = 0; i < K.length(); ++i)
	{
		res += (K[i] - 'A') * pow;
		pow *= p;
	}
	return res % s;
}

void LinkedMap::Insert(string K, string V)
{
	Src[generateHash(K)].Insert(K, V, Head);
}

string LinkedMap::Search(string K)
{
	Node *Res = Src[generateHash(K)].Search(K);
	if (Res == nullptr)
		return "none";
	else
		return Res->Value;
}

void LinkedMap::Delete(string K)
{
	Src[generateHash(K)].Delete(K, Head);
}

string LinkedMap::Next(string K)
{
	Node *Res = Src[generateHash(K)].Search(K);
	if (Res == nullptr || Res->NextElem == Head)
		return "none";
	else
		return Res->NextElem->Value;
}

string LinkedMap::Prev(string K)
{
	Node *Res = Src[generateHash(K)].Search(K);
	if (Res == nullptr || Res->PrevElem == Head)
		return "none";
	else
		return Res->PrevElem->Value;
}

int main()
{
	ifstream fin("linkedmap.in");
	ofstream fout("linkedmap.out");
	LinkedMap LM;
	string Command;
	while (fin >> Command)
	{
		string K, V;
		if (Command == "put")
		{
			fin >> K >> V;
			LM.Insert(K, V);
		}
		else if (Command == "delete")
		{
			fin >> K;
			LM.Delete(K);
		}
		else if (Command == "get")
		{
			fin >> K;
			fout << LM.Search(K) << "\n";
		}
		else if (Command == "next")
		{
			fin >> K;
			fout << LM.Next(K) << "\n";
		}
		else if (Command == "prev")
		{
			fin >> K;
			fout << LM.Prev(K) << "\n";
		}
	}
	return 0;
}