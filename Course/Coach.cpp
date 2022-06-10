#include "Coach.h"

using namespace std;

ostream& operator<<(ostream& os, const Coach& ad) {
	os << ad.coachname << '|' << ad.price << '|' << ad.ages << '|' << ad.rating << "\n";
	return os;
}

vector<Coach> ReadInC(vector<Coach>& personal) {
	ifstream file("Coaches.bin", ios::binary);
	Coach ex;
	personal.clear();
	while (file)
	{
		file.read((char*)(&ex.coachname), sizeof(ex.coachname));
		file.read((char*)(&ex.price), sizeof(ex.price));
		file.read((char*)(&ex.ages), sizeof(ex.ages));
		file.read((char*)(&ex.rating), sizeof(ex.rating));
		if (!file)
			break;
		personal.push_back(ex);
	}
	file.close();
	return personal;

}

void WriteInC(vector<Coach>& personal) {
	ofstream file("Coaches.bin", ios::binary);
	for (unsigned int i = 0; i < personal.size(); i++) {
		file.write((char*)(&personal[i].coachname), sizeof(personal[i].coachname));
		file.write((char*)(&personal[i].price), sizeof(personal[i].price));
		file.write((char*)(&personal[i].ages), sizeof(personal[i].ages));
		file.write((char*)(&personal[i].rating), sizeof(personal[i].rating));

	}
	file.close();
}
