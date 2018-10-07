#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fs;
	long long int a, b, result;

	fs.open("aplusbb.in", ios_base::in);

	fs >> a >> b;

	fs.close();


	fs.open("aplusbb.out", ios_base::out);

	result = a + b*b;
	fs << result;

	fs.close();

	return 0;
}