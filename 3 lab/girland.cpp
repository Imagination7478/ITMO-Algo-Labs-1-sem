#include <vector> 
#include <fstream> 
using namespace std;

int n;
vector<double> h;

double last()
{
	double l = 0, r = h[0];

	while (r - l >  0.0000000001) {

		h[1] = (l + r) / 2;

		bool up = true;

		for (int i = 2; i < n; i++) {

			h[i] = 2 * h[i - 1] - h[i - 2] + 2;

			if (h[i] < 0) {
				up = false;
				break;
			}
		}
		if (up) {
			r = h[1];
		}
		else {
			l = h[1];
		}
	}
	return h[n - 1];
}

int main()
{
	fstream fs;
	fs.open("garland.in", fstream::in);
	fs >> n;
	h.resize(n);
	fs >> h[0];
	double B = last();
	fs.close();


	fs.open("garland.out", fstream::out);

	fs.precision(2);

	fs << fixed << B;
	fs.close();

	return 0;
}