#include "Validation.h"

using namespace std;

int monthsQ(int& months) {
	cout << "Enter for how many months (1 - 12) you want to sign contract: " << endl;

	while (true)
	{
		cin >> months;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error: not an integer" << endl;
		}
		if ((months > 0) && (months < 13)) {
			break;
		}
		else {
			cout << "Out of range please enter one more time (1 - 12): " << endl;
		}

	}
	return months;
}

bool isvalid_data(const string& data, const string& str_re)
{
	regex re{ str_re };
	return regex_match(data, re);
}
