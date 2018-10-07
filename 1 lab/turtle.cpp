#include <iostream> 
#include <fstream> 
using namespace std;

int main() {

	fstream fs;

	int h, w;
	fs.open("turtle.in", fstream::in);
	fs >> h >> w;

	int **ptrArr = new int*[h];
	int **ptrArrFlipped = new int*[h];
	int **ptrArrResult = new int*[h];

	for (int i = 0; i < h; i++)
	{
		ptrArr[i] = new int[w];
		ptrArrFlipped[i] = new int[w];
		ptrArrResult[i] = new int[w];
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)	{
			fs >> ptrArr[i][j];
		}
	}

	fs.close();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ptrArrFlipped[i][j] = ptrArr[h - 1 - i][j];
		}
	}

	int k = 0;
	for (int i = 0; i < h; i++) {
		k += ptrArrFlipped[i][0];
		ptrArrResult[i][0] = k;
	}

	k = 0;
	for (int j = 0; j < w; j++) {
		k += ptrArrFlipped[0][j];
		ptrArrResult[0][j] = k;
	}

	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (ptrArrResult[i - 1][j] > ptrArrResult[i][j - 1]) {
				ptrArrResult[i][j] = ptrArrResult[i - 1][j] + ptrArrFlipped[i][j];
			}
			else {
				ptrArrResult[i][j] = ptrArrResult[i][j - 1] + ptrArrFlipped[i][j];
			}
		}
	}

	fs.open("turtle.out", fstream::out);

	fs << ptrArrResult[h - 1][w - 1];

	fs.close();

	for (int i = 0; i < h; i++)
	{
		delete[] ptrArr[i];
		delete[] ptrArrFlipped[i];
		delete[] ptrArrResult[i];
	}
	delete[] ptrArr;
	delete[] ptrArrFlipped;
	delete[] ptrArrResult;

	return 0;
}
