#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<class Runners> &arrRunners, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	vector<class Runners> L;
	vector<class Runners> R;
	Runners runner;

	for (i = 0; i < n1; i++)
	{
		runner.setCountry(arrRunners[left + i].getCountry());
		runner.setSurname(arrRunners[left + i].getSurname());
		runner.setPlace(arrRunners[left + i].getPlace());

		L.push_back(runner);
	}
	for (i = 0; i < n2; i++)
	{
		runner.setCountry(arrRunners[middle + 1 + i].getCountry());
		runner.setSurname(arrRunners[middle + 1 + i].getSurname());
		runner.setPlace(arrRunners[middle + 1 + i].getPlace());

		R.push_back(runner);
	}

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i].getCountry() <= R[j].getCountry())
		{
			arrRunners[k].setCountry(L[i].getCountry());
			i++;
		}
		else
		{
			arrRunners[k].setCountry(R[j].getCountry());
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arrRunners[k].setCountry(L[i].getCountry());
		i++;
		k++;
	}

	while (j < n2)
	{
		arrRunners[k].setCountry(R[j].getCountry());
		j++;
		k++;
	}
}

void mergeSort(vector<class Runners> &arrRunners, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		mergeSort(arrRunners, left, middle);
		mergeSort(arrRunners, middle + 1, right);

		merge(arrRunners, left, middle, right);
	}
}

class Runners
{
private:
	string surname;
	int place;
	string country;

public:
	//friend void merge(vector<Runners> &arrRunners, int left, int middle, int right);
	//friend void mergeSort(vector<Runners> &arrRunners, int left, int right);

	Runners operator = (Runners &runner)
	{
		this->country = runner.country;
		this->surname = runner.surname;
		this->place = runner.place;
		return runner;
	}

	void setSurname(string surname)
	{
		this->surname = surname;
	}
	void setPlace(int place)
	{
		this->place = place;
	}
	void setCountry(string country)
	{
		this->country = country;
	}
	string getSurname()
	{
		return this->surname;
	}
	string getCountry()
	{
		return this->country;
	}
	int getPlace()
	{
		return this->place;
	}
};


int main()
{
	int quantityRunners = 0;
	vector<Runners> arrRunners;
	Runners runner;

	fstream fs;
	fs.open("race.in", fstream::in);
	fs >> quantityRunners;

	string surname, country;
	for (int i = 0; i < quantityRunners; i++)
	{
		runner.setPlace(i + 1);

		fs >> country;
		runner.setCountry(country);

		fs >> surname;
		runner.setSurname(surname);

		arrRunners.push_back(runner);
	}

	fs.close();

	// Сорт. вставками
	/*for (int i = 1; i < quantityRunners; i++)
	{	
		for (int j = i; j > 0; j--)
		{
			if (arrRunners[j - 1].getCountry() > arrRunners[j].getCountry())
			{
				swap(arrRunners[j - 1], arrRunners[j]);
			}
		}
	}*/

	mergeSort(arrRunners, 0, arrRunners.size() - 1);

	

	//sort(arrRunners.begin(), arrRunners.end());

	fs.open("race.out", fstream::out);

	for (int i = 0; i < quantityRunners; i++)
	{
		if (i == 0)
		{
			fs << "=== " << arrRunners[i].getCountry() << " ===" << endl;
			fs << arrRunners[i].getSurname() << endl;
		} 
		else if (arrRunners[i].getCountry() == arrRunners[i - 1].getCountry())
		{
			fs << arrRunners[i].getSurname() << endl;
		}
		else
		{
			fs << "=== " << arrRunners[i].getCountry() << " ===" << endl;
			fs << arrRunners[i].getSurname() << endl;
		}
	}

	fs.close();
	return 0;
}