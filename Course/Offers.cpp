#include "Offers.h"
#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

void WriteInO(vector<Offers>& offering) {
	ofstream file("Offers.bin", ios::binary);
	for (unsigned int i = 0; i < offering.size(); i++) {
		file.write((char*)(&offering[i].Month), sizeof(offering[i].Month));
		file.write((char*)(&offering[i].var), sizeof(offering[i].var));
	}
	file.close();

}

vector<Offers> ReadInO(vector<Offers>& offering) {
	ifstream file("Offers.bin", ios::binary);
	Offers ex;
	offering.clear();
	while (file)
	{
		file.read((char*)(&ex.Month), sizeof(ex.Month));
		file.read((char*)(&ex.var), sizeof(ex.var));
		if (!file)
			break;
		offering.push_back(ex);
	}
	file.close();
	return offering;

}

vector<Offers> OfRegistration(vector<Offers>offering, size_t& numberOfElement){
	numberOfElement = offering.size();
	cout << "Adding new object \n";
	offering.push_back(Offers());
	cout << "Enter variant of contract\n";
	cin.ignore();
	cin.getline(offering[numberOfElement].var, 50);
	cout << "Enter months \n";
	cin >> offering[numberOfElement].Month;
	CLEARBUF
	while (true)
	{
		if (cin.fail())
		{
			CLEARBUF
			cout << "Error: not an integer" << endl;
			cin >> offering[numberOfElement].Month;
		}
		if (!cin.fail())
			break;
	}
	numberOfElement++;
	WriteInO(offering);
	return offering;
}
