#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fs;
	int var1, var2, result;

	fs.open("aplusb.txt", fstream::in );

	fs >> var1 >> var2;

	fs.close();

	fs.open("aplusb.out", fstream::out);

	result = var1 + var2;
	fs << result << endl;

	fs.close();
	return 0;
}